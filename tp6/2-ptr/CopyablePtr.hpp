#pragma once

#include "Object.hpp"

class CopyablePtr {
    public:
        CopyablePtr(Object* object = nullptr)
            : _object {object}
        {}

        CopyablePtr(int value)
            : _object { new Object(value)}
        {}

        CopyablePtr(const CopyablePtr& other)
            : _object {other._object}
        {}

        CopyablePtr(CopyablePtr&& other)
            : _object {std::move(other._object)}
        {}

        bool operator==(std::nullptr_t) const {
            return _object == nullptr;
        }

        CopyablePtr& operator=(const CopyablePtr& other) {
            if(this != &other) {
                _object = other._object;
            }
            return *this;
        }

        Object& operator*() const {
            return *_object;
        }

        CopyablePtr& operator=(std::nullptr_t) {
            if(_object == nullptr) {
                delete _object;
                _object = nullptr;
            }
            return *this;
        }

        /*~CopyablePtr()
        {
            delete _object;
            _object = nullptr;
        }*/

    private:
        Object* _object;
};