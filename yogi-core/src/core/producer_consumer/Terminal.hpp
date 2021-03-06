#ifndef YOGI_CORE_PRODUCER_CONSUMER_TERMINAL_HPP
#define YOGI_CORE_PRODUCER_CONSUMER_TERMINAL_HPP

#include "../../config.h"
#include "../publish_subscribe/Terminal.hpp"
#include "logic_types.hpp"


namespace yogi {
namespace core {

class Leaf;

namespace producer_consumer {

/***************************************************************************//**
 * Implements a producer-consumer terminal
 ******************************************************************************/
template <typename TTypes=logic_types<>>
class Terminal : public publish_subscribe::Terminal<TTypes>
{
    typedef publish_subscribe::Terminal<TTypes> super;

public:
    Terminal(Leaf& leaf, base::Identifier identifier)
        : super(leaf, identifier)
    {
    }
};

} // namespace producer_consumer
} // namespace core
} // namespace yogi

#endif // YOGI_CORE_PRODUCER_CONSUMER_TERMINAL_HPP
