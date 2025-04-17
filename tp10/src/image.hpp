#pragma once

#include <array>
#include <cassert>
#include <functional>

template <typename P1, typename P2>
using CombinedPixel = decltype(std::declval<P1>() + std::declval<P2>());

template <typename P, size_t W, size_t H>
class Image {
    public:
        Image() = default;
        Image(const P& pixel){
            for(auto& row: _pixels) {
                row.fill(pixel);
            }
        }

        Image(const std::function<P(size_t, size_t)>& function) {
            for(auto x = 0; x < W; ++x) {
                for(auto y = 0; y < H; ++y) {
                    _pixels[y][x] = function(x, y);
                }
            }
        }

        const P& operator()(size_t x, size_t y) const {
            assert(x < W && y < H);
            return _pixels[y][x];
        }

        P& operator()(size_t x, size_t y){
            assert(x < W && y < H);
            return _pixels[y][x];
        }

        //Image operator+(const Image& other) const 
        template<typename OtherP>
        Image<CombinedPixel<P, OtherP>, W, H> operator+(const Image<OtherP, W, H>& other) const {
            //auto result = new Image();
            auto result = Image<CombinedPixel<P, OtherP>, W, H> {};
            for (auto y = 0; y < H; ++y) {
                for (auto x = 0; x < W; ++x) {
                    //result._pixels[y][x] = _pixels[y][x] + other._pixels[y][x];
                    result(x, y) = (*this)(x, y) + other(x, y);
                }
            }
            return result;
        }


        const size_t width() const { return W; }
        
        const size_t height() const { return H; }

    private:
        std::array<std::array<P, W>, H> _pixels;
};