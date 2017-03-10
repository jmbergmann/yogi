#ifndef CHIRP_CORE_MASTER_SLAVE_LEAFLOGIC_HPP
#define CHIRP_CORE_MASTER_SLAVE_LEAFLOGIC_HPP

#include "../../config.h"
#include "../publish_subscribe/LeafLogic.hpp"
#include "Terminal.hpp"
#include "logic_types.hpp"


namespace chirp {
namespace core {
namespace master_slave {

/***************************************************************************//**
 * Implements the logic for master-slave terminals on leafs
 ******************************************************************************/
template <typename TTypes=logic_types<>>
class LeafLogic : public publish_subscribe::LeafLogic<TTypes>
{
public:
    typedef publish_subscribe::LeafLogic<TTypes> super;

protected:
    LeafLogic(interfaces::IScheduler& scheduler)
        : super{scheduler}
    {
    }

    virtual void on_data_received(const typename super::terminal_info& tm,
        base::Buffer&& data) override
    {
        using namespace messaging;

        if (!tm.terminal->identifier().hidden() && tm.subscribed) {
            typename TTypes::Data msg;
            msg[fields::subscriptionId] = tm.fsm.mapped_id();
            msg[fields::data]           = data;

            super::connection().send(msg);
        }

        super::on_data_received(tm, std::move(data));
    }
};

} // namespace master_slave
} // namespace core
} // namespace chirp

#endif // CHIRP_CORE_MASTER_SLAVE_LEAFLOGIC_HPP
