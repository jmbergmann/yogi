#ifndef YOGI_CORE_CACHED_MASTER_SLAVE_LOGIC_TYPES_HPP
#define YOGI_CORE_CACHED_MASTER_SLAVE_LOGIC_TYPES_HPP

#include "../../config.h"
#include "../cached_publish_subscribe/logic_types.hpp"
#include "../../messaging/messages/CachedMasterSlave.hpp"


namespace yogi {
namespace core {
namespace cached_master_slave {

template <typename TTypes>
class LeafLogic;

template <typename TTypes>
class NodeLogic;

template <typename TTypes>
class Terminal;

template <typename TMessages=messaging::messages::CachedMasterSlave>
struct logic_types
    : public cached_publish_subscribe::logic_types<TMessages>
{
    typedef LeafLogic<logic_types> leaf_logic_type;
    typedef NodeLogic<logic_types> node_logic_type;
    typedef Terminal<logic_types> terminal_type;
};

} // namespace cached_master_slave
} // namespace core
} // namespace yogi

#endif // YOGI_CORE_CACHED_MASTER_SLAVE_LOGIC_TYPES_HPP
