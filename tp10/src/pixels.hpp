#pragma once

#include "../lib/image_lib.hpp"

struct RGBA{
    uint8_t r, g, b, a;
};

struct RGB{
    uint8_t r, g, b;
};

struct Luma{
    uint8_t l;
};

template <typename To, typename From>
To convert(const From& stuff);

template <typename From>
From convert(const From& x)
{
    return x;
}

template <>
RGBA convert<RGBA, RGB>(const RGB& rgb) {
    return { rgb.r, rgb.g, rgb.b, 255 };
}

template <>
RGB convert<RGB, RGBA>(const RGBA& rgba) {
    return { rgba.r, rgba.g, rgba.b };
}

template <>
Luma convert<Luma, RGB>(const RGB& rgb) {
    return { image_lib::rgb_to_grayscale(rgb.r, rgb.g, rgb.b) };
}

template <>
RGB convert<RGB, Luma>(const Luma& luma) {
    auto rgb = image_lib::grayscale_to_rgb(luma.l);
    return { rgb[0], rgb[1], rgb[2] };
}

template <>
Luma convert<Luma, RGBA>(const RGBA& rgba) {
    return convert<Luma>(convert<RGB>(rgba));
}

template <>
RGBA convert<RGBA, Luma>(const Luma& luma) {
    return convert<RGBA>(convert<RGB>(luma));
}

RGBA operator+(const RGBA& lhs, const RGBA& rhs) {
    auto blended = image_lib::mix_color(lhs.r, lhs.g, lhs.b, lhs.a, rhs.r, rhs.g, rhs.b, rhs.a);
    return { blended[0], blended[1], blended[2], blended[3] };
}

RGB operator+(const RGB& lhs, const RGBA& rhs) {
    return convert<RGB>(convert<RGBA>(lhs) + rhs);
}

RGB operator+(const Luma& lhs, const RGBA& rhs) {
    return convert<RGB>(convert<RGBA>(lhs) + rhs);
}

RGBA operator+(const RGBA& lhs, const RGB& rhs) {
    return lhs + convert<RGBA>(rhs);
}

RGB operator+(const RGB& lhs, const RGB& rhs) {
    return convert<RGB>(convert<RGBA>(lhs) + convert<RGBA>(rhs));
}

RGB operator+(const Luma& lhs, const RGB& rhs) {
    return convert<RGB>(convert<RGBA>(lhs) + convert<RGBA>(rhs));
}

RGBA operator+(const RGBA& lhs, const Luma& rhs) {
    return { lhs.r, lhs.g, lhs.b, rhs.l };
}

RGBA operator+(const RGB& lhs, const Luma& rhs) {
    return { lhs.r, lhs.g, lhs.b, rhs.l };
}

RGBA operator+(const Luma& lhs, const Luma& rhs) {
    return { lhs.l, lhs.l, lhs.l, rhs.l };
}

template <typename P>
RGBA operator+(const P& lhs, const Luma& mask){
    auto res = convert<RGBA, Luma>(lhs);
    res.a = (res.a * mask.l) / 255;
    return res;
}

template <typename P1, typename P2>
using CombinedPixel = decltype(std::declval<P1>() + std::declval<P2>());