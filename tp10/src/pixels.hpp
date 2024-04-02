#include <cstdint>
#include "../lib/image_lib.hpp"

struct RGBA{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
};

struct RGB{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

struct Luma{
    uint8_t gray;
};

template <typename From>
From convert(const From& x)
{
    return x;
}

template <>
RGBA convert<RGBA, RGB>(const RGB& x)
{
    return { x.red, x.green, x.blue, 255 };
}

template <>
RGB convert<RGB, RGBA>(const RGBA& x)
{
    return { x.red, x.green, x.blue };
}

template <>
Luma convert<Luma, RGB>(const RGB& x)
{
    auto gray = image_lib::rgb_to_grayscale(x.red, x.green, x.blue);
    return { gray };
}

template <>
RGB convert<RGB, Luma>(const Luma& x)
{
    auto rgb = image_lib::grayscale_to_rgb(x.gray);
    return { rgb[0], rgb[1], rgb[2] };
}

template <>
RGBA convert<RGBA, Luma>(const Luma& x)
{
    auto rgb = convert<RGB>(x);
    return convert<RGBA>(rgb);
}

template <>
Luma convert<Luma, RGBA>(const RGBA& x)
{
    auto rgb = convert<RGB>(x);
    return convert<Luma>(rgb);
}

RGBA operator+(const RGBA& lhs, const RGBA& rhs) {
    return {
        image_lib::mix_color(lhs.red, lhs.green, lhs.blue, lhs.alpha,
                             rhs.red, rhs.green, rhs.blue, rhs.alpha)
    };
}

RGB operator+(const RGB& lhs, const RGB& rhs) {
    return {
        static_cast<uint8_t>((lhs.red + rhs.red) / 2),
        static_cast<uint8_t>((lhs.green + rhs.green) / 2),
        static_cast<uint8_t>((lhs.blue + rhs.blue) / 2)
    };
}

RGB operator+(const Luma& lhs, const RGB& rhs) {
    RGB converted_lhs = convert<RGB>(lhs);
    return converted_lhs + rhs;
}

RGBA operator+(const Luma& lhs, const RGBA& rhs) {
    RGBA converted_lhs = convert<RGBA>(lhs);
    return converted_lhs + rhs;
}

template <typename P1, typename P2>
using CombinedPixel = decltype(std::declval<P1>() + std::declval<P2>());
