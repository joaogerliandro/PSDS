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

enum OrderStatus
{
    CREATED = 0,
    PROCESSING = 1,
    CONFIRMED = 2,
    CANCELING = 3,
    CANCELED = 4,
    PROCESSED = 5
};
