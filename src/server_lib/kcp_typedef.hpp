#pragma once

#define ASIO_KCP_CONNECTION_TIMEOUT_TIME 10 * 1000 // default is 10 seconds.

#include <stdint.h>
#include <memory>

struct IKCPCB;
typedef struct IKCPCB ikcpcb;

// indicate a converse between a client and connection_obj between server.
typedef uint32_t kcp_conv_t;

namespace asio_kcp {

enum eEventType
{
    eConnect,
    eDisconnect,
    eRcvMsg,
    eLagNotify,

    eCountOfEventType
};

const char* eventTypeStr(eEventType eventType);

typedef void(event_callback_t)(kcp_conv_t /*conv*/, eEventType /*event_type*/, std::shared_ptr<std::string> /*msg*/);

} // namespace asio_kcp
