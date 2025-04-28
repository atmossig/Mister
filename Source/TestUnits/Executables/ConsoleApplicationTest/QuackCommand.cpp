// Copyright Grant Abernathy, 2025.
#include "QuackCommand.h"
#include <iostream>

void QuackCommand::Execute(const std::vector<std::string>& args) {
    std::cout << "\n   _.._\n";
    std::cout << " / >__)\n";
    std::cout << " \\ (_>)\n";
    std::cout << "  `----' Quack! Quack!\n\n";
}

std::string QuackCommand::GetName() const {
    return "quack";
}

std::string QuackCommand::GetDescription() const {
    return "ASCII Duck.";
}
