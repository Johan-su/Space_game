#include "platform.hpp"


#ifdef _WIN32
#include "win_layer.hpp"
#endif

#ifdef __linux__
#include "linux_layer.hpp"
#endif