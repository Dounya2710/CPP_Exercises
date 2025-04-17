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

RGBA operator+(const RGBA& lhs, const RGBA& rhs)
{
    const auto data = image_lib::mix_color(lhs.r, lhs.g, lhs.b, lhs.a, rhs.r, rhs.g, rhs.b, rhs.a);
    return {data[0], data[1], data[2], data[3]};
}

RGB operator+(const RGB& lhs, const RGBA& rhs)
{
    const auto new_lhs = convert<RGBA, RGB>(lhs);
    return convert<RGB, RGBA>(new_lhs + rhs);
}

RGB operator+(const Luma& lhs, const RGBA& rhs)
{
    const auto new_lhs = convert<RGBA, Luma>(lhs);
    return convert<RGB, RGBA>(new_lhs + rhs);
}

RGBA operator+(const RGBA& lhs, const RGB& rhs)
{
    const auto new_rhs = convert<RGBA, RGB>(rhs);
    return lhs + new_rhs;
}

RGB operator+(const RGB& lhs, const RGB& rhs)
{
    const auto new_lhs = convert<RGBA, RGB>(lhs);
    const auto new_rhs = convert<RGBA, RGB>(rhs);
    return convert<RGB, RGBA>(new_lhs + new_rhs);
}

RGB operator+(const Luma& lhs, const RGB& rhs)
{
    const auto new_lhs = convert<RGBA, Luma>(lhs);
    const auto new_rhs = convert<RGBA, RGB>(rhs);
    return convert<RGB, RGBA>(new_lhs + new_rhs);
}

RGBA operator+(const RGBA& lhs, const Luma& rhs)
{
    auto v = lhs;
    v.a = v.a * rhs.l / 255;
    return v;
}

RGBA operator+(const RGB& lhs, const Luma& rhs)
{
    return convert<RGBA, RGB>(lhs) + rhs;
}