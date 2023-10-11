//
// Created by stelc on 12.10.2023.
//
#pragma once
#ifndef BLOCKCHAINCPLUSPLUS_COMMON_H
#define BLOCKCHAINCPLUSPLUS_COMMON_H

#include <chrono>
#include <ctime>
#include <string>

// Time functions
time_t getCurrentTime();
std::string getTimeZoneBased(const time_t& timestamp);

#endif //BLOCKCHAINCPLUSPLUS_COMMON_H
