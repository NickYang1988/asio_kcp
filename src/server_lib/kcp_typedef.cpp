#include "kcp_typedef.hpp"

namespace asio_kcp {

const char* eventTypeStr(eEventType eventType)
{
    switch (eventType)
    {
        case eConnect:
            return "Connect";
        case eDisconnect:
            return "Disconnect";
        case eRcvMsg:
            return "Recv";
        case eLagNotify:
            return "LagNotify";
        default:
            return "Unknown";
    }
}

} // namespace asio_kcp
