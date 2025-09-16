#pragma once
#include "Commands.h"
#include <string>
#include <vector>
#include <memory>

class CommandFactory {
public:
    static std::vector<std::unique_ptr<ICommand>> parseFile(const std::string& filename);
};