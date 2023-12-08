#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <sstream>

#include <libpq-fe.h>

#include <zmq.hpp>
#include <nlohmann/json.hpp>

enum ServiceType
{
    CreateOrder = 0,
    GetOrderList = 1,
    ConfirmOrder = 2,
    CancelOrder = 3,
    ProcessOrder = 4,
    SaveLog = 5
};
