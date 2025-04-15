#include <set>
#include <iostream>

struct Point3d {
    int x, y, z;

    bool operator<(const Point3d& other) const {
        return x < other.x && y < other.y && z < other.z;
    }
};

class Point3dCompare {
    public:
        Point3dCompare() = default;

        bool operator()(const Point3d& first, const Point3d& second) const {
            return std::tie(first.x, first.y, first.z) < std::tie(second.x, second.y, second.z);
        }

    private:
        Point3d _points;
};

int main() {
    auto coords = std::set<Point3d/*, Point3dCompare*/>{};
    coords.insert({1, 2, 3});
    coords.insert({0, 5, 1});
    coords.insert({1, 2, 2});

    for (const auto& p : coords) {
        std::cout << "(" << p.x << ", " << p.y << ", " << p.z << ")" << std::endl;
    }

    return 0;
}