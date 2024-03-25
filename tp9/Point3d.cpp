#include <iostream>
#include <set>
#include <tuple>

struct Point3d {
    int x; 
    int y;
    int z;

    bool operator<(const Point3d& other) const {
        return std::tie(x, y, z) < std::tie(other.x, other.y, other.z);
    }
};

/*class Point3dCompare {
    public:
        bool operator()(const Point3d& p1, const Point3d& p2) const {
            return std::tie(p1.x, p1.y, p1.z) < std::tie(p2.x, p2.y, p2.z);
        }

};*/

namespace std {
    template<>
    struct less<Point3d> {
        bool operator()(const Point3d& p1, const Point3d& p2) const {
            return std::tie(p1.x, p1.y, p1.z) < std::tie(p2.x, p2.y, p2.z);
        }
    };
}

int main() {
    //std::set<Point3d, Point3dCompare> coords;
    std::set<Point3d> coords;
    coords.insert({1, 2, 3});
    coords.insert({4, 5, 6});
    coords.insert({7, 8, 9});

    coords.erase({4, 5, 6});

    Point3d key{1, 2, 3};
    auto it = coords.find(key);
    if (it != coords.end()) {
        std::cout << "Found point: (" << it->x << ", " << it->y << ", " << it->z << ")" << std::endl;
    } else {
        std::cout << "Point not found." << std::endl;
    }
    return 0;
}