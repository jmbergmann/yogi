#ifndef YOGI_SERIALIZATION_DESERIALIZE_HPP
#define YOGI_SERIALIZATION_DESERIALIZE_HPP

#include "../config.h"
#include "deserialize_one.hpp"


namespace yogi {
namespace serialization {

template <typename... TValues>
std::vector<char>::const_iterator deserialize(const std::vector<char>& buffer,
    std::vector<char>::const_iterator start, TValues&... values)
{
    // nasty trick to call deserialize_one() for every field
    auto _ = { (deserialize_one(buffer, start, values), 0)... };
    return start;
}

} // namespace serialization
} // namespace yogi

#endif // YOGI_SERIALIZATION_DESERIALIZE_HPP
