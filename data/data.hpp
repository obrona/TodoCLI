#pragma once
#include <string>

#include "task-manager.hpp"

struct Data {
    std::string save_file_location;
    TaskManager tasks;
};