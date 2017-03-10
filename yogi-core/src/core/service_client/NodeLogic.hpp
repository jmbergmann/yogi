#ifndef CHIRP_CORE_SERVICE_CLIENT_NODELOGIC_HPP
#define CHIRP_CORE_SERVICE_CLIENT_NODELOGIC_HPP

#include "../../config.h"
#include "../scatter_gather/NodeLogic.hpp"
#include "logic_types.hpp"


namespace chirp {
namespace core {
namespace service_client {

/***************************************************************************//**
 * Implements the logic for service-client terminals on leafs
 ******************************************************************************/
template <typename TTypes=logic_types<>>
class NodeLogic : public scatter_gather::NodeLogic<TTypes>
{
    typedef scatter_gather::NodeLogic<TTypes> super;

protected:
    NodeLogic(interfaces::IScheduler& scheduler,
        typename super::known_terminals_changed_fn knownTerminalsChangedFn)
        : super{scheduler, knownTerminalsChangedFn}
    {
    }
};

} // namespace service_client
} // namespace core
} // namespace chirp

#endif // CHIRP_CORE_SERVICE_CLIENT_NODELOGIC_HPP
