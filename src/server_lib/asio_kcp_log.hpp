#ifndef _ASIO_KCP_LOG_HPP__
#define _ASIO_KCP_LOG_HPP__

#include <ostream>
#include <fstream>
#include <utility>

// TODO: will use spdlog as the default log
#define AK_LOG std::cout
#define AK_DEBUG_LOG AK_LOG << "[DEBUG] "
#define AK_INFO_LOG AK_LOG << "[INFO] "
#define AK_WARNING_LOG AK_LOG << "[WARN] "
#define AK_FATAL_LOG AK_LOG << "[FATAL] "

#define AK_UDP_PACKET_LOG AK_INFO_LOG
#define AK_ASK_PACKET_LOG AK_INFO_LOG

#define AK_ENABLE_UDP_PACKET_LOG 0

#endif // _ASIO_KCP_LOG_HPP__
