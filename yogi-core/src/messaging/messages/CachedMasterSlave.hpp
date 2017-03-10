#ifndef CHIRP_MESSAGING_MESSAGES_CACHEDMASTERSLAVE_HPP
#define CHIRP_MESSAGING_MESSAGES_CACHEDMASTERSLAVE_HPP

#include "../../config.h"
#include "CachedPublishSubscribe.hpp"


namespace chirp {
namespace messaging {
namespace messages {

struct CachedMasterSlave {
    struct TerminalDescription : public InheritedMessage<TerminalDescription,
        CachedPublishSubscribe::TerminalDescription
    > { CHIRP_MESSAGE_NAME("CachedMasterSlave::TerminalDescription"); };

    struct TerminalMapping : public InheritedMessage<TerminalMapping,
        CachedPublishSubscribe::TerminalMapping
    > { CHIRP_MESSAGE_NAME("CachedMasterSlave::TerminalMapping"); };

    struct TerminalNoticed : public InheritedMessage<TerminalNoticed,
        CachedPublishSubscribe::TerminalNoticed
    > { CHIRP_MESSAGE_NAME("CachedMasterSlave::TerminalNoticed"); };

    struct TerminalRemoved : public InheritedMessage<TerminalRemoved,
        CachedPublishSubscribe::TerminalRemoved
    > { CHIRP_MESSAGE_NAME("CachedMasterSlave::TerminalRemoved"); };

    struct TerminalRemovedAck : public InheritedMessage<TerminalRemovedAck,
        CachedPublishSubscribe::TerminalRemovedAck
    > { CHIRP_MESSAGE_NAME("CachedMasterSlave::TerminalRemovedAck"); };

    struct BindingDescription : public InheritedMessage<BindingDescription,
        CachedPublishSubscribe::BindingDescription
    > { CHIRP_MESSAGE_NAME("CachedMasterSlave::BindingDescription"); };

    struct BindingMapping : public InheritedMessage<BindingMapping,
        CachedPublishSubscribe::BindingMapping
    > { CHIRP_MESSAGE_NAME("CachedMasterSlave::BindingMapping"); };

    struct BindingNoticed : public InheritedMessage<BindingNoticed,
        CachedPublishSubscribe::BindingNoticed
    > { CHIRP_MESSAGE_NAME("CachedMasterSlave::BindingNoticed"); };

    struct BindingRemoved : public InheritedMessage<BindingRemoved,
        CachedPublishSubscribe::BindingRemoved
    > { CHIRP_MESSAGE_NAME("CachedMasterSlave::BindingRemoved"); };

    struct BindingRemovedAck : public InheritedMessage<BindingRemovedAck,
        CachedPublishSubscribe::BindingRemovedAck
    > { CHIRP_MESSAGE_NAME("CachedMasterSlave::BindingRemovedAck"); };

    struct BindingEstablished : public InheritedMessage<BindingEstablished,
        CachedPublishSubscribe::BindingEstablished
    > { CHIRP_MESSAGE_NAME("CachedMasterSlave::BindingEstablished"); };

    struct BindingReleased : public InheritedMessage<BindingReleased,
        CachedPublishSubscribe::BindingReleased
    > { CHIRP_MESSAGE_NAME("CachedMasterSlave::BindingReleased"); };

    struct Subscribe : public InheritedMessage<Subscribe,
        CachedPublishSubscribe::Subscribe
    > { CHIRP_MESSAGE_NAME("CachedMasterSlave::Subscribe"); };

    struct Unsubscribe : public InheritedMessage<Unsubscribe,
        CachedPublishSubscribe::Unsubscribe
    > { CHIRP_MESSAGE_NAME("CachedMasterSlave::Unsubscribe"); };

    struct Data : public InheritedMessage<Data,
        CachedPublishSubscribe::Data
    > { CHIRP_MESSAGE_NAME("CachedMasterSlave::Data"); };

    struct CachedData : public InheritedMessage<CachedData,
        CachedPublishSubscribe::CachedData
    > { CHIRP_MESSAGE_NAME("CachedMasterSlave::CachedData"); };
}; // struct CachedMasterSlave

} // namespace messages
} // namespace messaging
} // namespace chirp

#endif // CHIRP_MESSAGING_MESSAGES_CACHEDMASTERSLAVE_HPP
