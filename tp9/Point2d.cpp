#include <iostream>
#include <unordered_map>
#include <utility>

struct Point2d {
    int x;
    int y;

    bool operator==(const Point2d& other) const {
        return x == other.x && y == other.y;
    }
};

namespace std {
    template<>
    struct hash<Point2d> {
        std::size_t operator()(const Point2d& p) const {
            return std::hash<int>{}(p.x) ^ (std::hash<int>{}(p.y) << 1);
        }
    };
}

enum class Content {
    Empty,
    Red,
    Yellow
};

/*class Point2dHash {
public:
    std::size_t operator()(const Point2d& p) const {
        return hash_pair(std::make_pair(p.x, p.y));
    }
private:
    std::size_t hash_pair(const std::pair<int, int>& pair) const {
        auto hash1 = std::hash<int>{}(pair.first);
        auto hash2 = std::hash<int>{}(pair.second);
        return hash1 ^ (hash2 << 1);
    }
};

class Point2dEqual {
public:
    bool operator()(const Point2d& p1, const Point2d& p2) const {
        return p1.x == p2.x && p1.y == p2.y;
    }
};*/

int main() {
    //std::unordered_map<Point2d, Content, Point2dHash, Point2dEqual> grid;
    std::unordered_map<Point2d, Content> grid;
    grid[{0, 0}] = Content::Red;
    grid[{1, 1}] = Content::Yellow;

    grid.erase({0, 0});

    Point2d key{1, 1};
    auto it = grid.find(key);
    if (it != grid.end()) {
        std::cout << "Found content: " << static_cast<int>(it->second) << std::endl;
    } else {
        std::cout << "Content not found." << std::endl;
    }
    return 0;
}