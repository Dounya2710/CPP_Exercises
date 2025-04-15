#include <iostream>
#include <ostream>
#include <unordered_map>
#include <cstddef>
#include <functional>

struct Point2d {
    int x, y;

    bool operator==(const Point2d& other) const {
        return x == other.x && y == other.y;
    }

    
};

namespace std {
    template <>
    struct hash<Point2d> {
        std::size_t operator()(const Point2d& point) const {
            std::size_t hx = static_cast<std::size_t>(point.x);
            std::size_t hy = static_cast<std::size_t>(point.y);
            return hx * 31 + hy;
        }
    };
}

enum Content {
    Empty, Red, Yellow
};

class Point2dHash {
    public:
        Point2dHash() = default;

        std::size_t operator()(const Point2d& point) const {
            std::size_t hx = static_cast<std::size_t>(point.x);
            std::size_t hy = static_cast<std::size_t>(point.y);
            return hx * 31 + hy;
        }
        

    private:
        Point2d _point;
};

class Point2dEqual {
    public:
        Point2dEqual() = default;

        bool operator()(const Point2d& point1, const Point2d& point2) const {
            return point1.x == point2.x && point1.y == point2.y;
        }

    private:
        Point2d _points;
};


int main() {
    auto grid = std::unordered_map<Point2d, Content/*, Point2dHash, Point2dEqual*/>{};
    grid[{0, 0}] = Red;
    grid[{1, 1}] = Yellow;
    std::cout << grid[{0, 0}] << std::endl;
    std::cout << grid[{1, 1}] << std::endl;
    return 0;
}