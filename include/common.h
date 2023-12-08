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
    GetOrderListByTaxNumber = 2,
    ConfirmOrder = 3,
    CancelOrder = 4,
    ProcessOrder = 5
};
