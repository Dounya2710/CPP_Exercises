#ifndef ALIAS_HPP
#define ALIAS_HPP

#include "../lib/Tracker.hpp"
#include <memory>

using PTR_ALIAS1 = std::unique_ptr<Tracker>;
using PTR_ALIAS2 = Tracker*;

#endif