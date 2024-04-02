#include <array>
#include <functional>
#include "pixels.hpp"

template<typename P, size_t W, size_t H>
class Image {
public:
    Image() = default;
    Image(const P& pixel) {
        fill(pixel);
    }
    Image(const std::function<P(size_t, size_t)>& functor) {
        fill(functor);
    }

    P& operator()(size_t i, size_t j) {
        return pixels[i][j];
    }
    const P& operator()(size_t i, size_t j) const {
        return pixels[i][j];
    }

    template<typename OtherP>
    Image<CombinedPixel<P, OtherP>, W, H> operator+(const Image<OtherP, W, H>& other) const {
        Image<CombinedPixel<P, OtherP>, W, H> result;
        for (size_t i = 0; i < W; ++i) {
            for (size_t j = 0; j < H; ++j) {
                result(i, j) = pixels[i][j] + other(i, j);
            }
        }
        return result;
    }

private:
    std::array<std::array<P, W>, H> pixels;

    void fill(const P& pixel) {
        for(auto& row: pixels) {
            for(auto& col: row) {
                col = pixel;
            }
        }
    }

    void fill(const std::function<P(size_t, size_t)>& functor) {
        for (size_t i = 0; i < W; ++i) {
            for (size_t j = 0; j < H; ++j) {
                pixels[i][j] = functor(i, j);
            }
        }
    }
};