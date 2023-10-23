#include <chrono>
#include <functional>
#include <memory>
#include <string>



#include <chrono>
//#include <linux/can.h>
#include <linux/can/raw.h>
#include <boost/asio.hpp>
//#include <boost/asio/io_service.hpp>
//#include <boost/asio/signal_set.hpp>
//#include <thread>
#include "rclcpp/rclcpp.hpp"
//#include "can_msgs/msg/frame.hpp"
#include "std_msgs/msg/string.hpp"
// #include "can_msgs/srv/can_request.hpp"
#include "geometry_msgs/msg/twist.hpp"
//#include "log.h"
//pcan starts here
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <asm/types.h>
#ifndef NO_RT
#include <sys/mman.h>
#ifdef RTAI
#include <rtai_lxrt.h>
#endif
// PCAN-Basic device used to read on
// (RT version doesn't handle USB devices)
#define PCAN_DEVICE	 PCAN_USBBUS1
#else
// PCAN-Basic device used to read on
#define PCAN_DEVICE		PCAN_USBBUS1
#endif
#include "PCANBasic.h"
unsigned int pcan_device = PCAN_DEVICE;
TPCANMsg Message;
TPCANStatus Status;
