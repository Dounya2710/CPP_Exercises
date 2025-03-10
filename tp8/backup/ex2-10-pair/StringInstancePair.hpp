#pragma once

#include "../lib/Tracker.hpp"
#include <vector>
#include <memory>

class StringInstancePair{
    public:
        StringInstancePair(const std::string& str)
            : _str {str}
            , _trackers {std::make_unique<Tracker>()}
        {}

        StringInstancePair(const StringInstancePair& other)
            : _str {other._str}
            , _trackers {std::make_unique<Tracker>(*other._trackers)}
        {}

        StringInstancePair(StringInstancePair&& other) 
            : _str {std::move(other._str)}
            , _trackers {std::move(other._trackers)}
        {}

        const std::string& get_str() const {
            return _str;
        }

        const Tracker& get_tracker() const{
            return *_trackers;
        }

        ~StringInstancePair() {}

    private:
        std::string _str;
        std::unique_ptr<Tracker> _trackers;
};