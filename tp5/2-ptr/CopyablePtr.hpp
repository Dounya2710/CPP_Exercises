#include "Object.hpp"
#include <cstddef>

class CopyablePtr {
    public:
    CopyablePtr() : ptr(nullptr) {}

    explicit CopyablePtr(Object* p) : ptr(p) {}

    explicit CopyablePtr(int value) : ptr(new Object(value)) {}

    CopyablePtr(const CopyablePtr& other) : ptr(other.ptr ? new Object(*other.ptr) : nullptr) {}

    ~CopyablePtr() {
        delete ptr;
    }

    bool operator==(std::nullptr_t) const {
        return ptr == nullptr;
    }

    const Object& operator*() const {
        return *ptr;
    }

    CopyablePtr& operator=(std::nullptr_t) {
        delete ptr;
        ptr = nullptr;
        return *this;
    }

    CopyablePtr& operator=(const CopyablePtr& other) {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr ? new Object(*other.ptr) : nullptr;
        }
        return *this;
    }

    CopyablePtr(CopyablePtr&& other) : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    CopyablePtr& operator=(CopyablePtr&& other) {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    private:
        Object *ptr;
};