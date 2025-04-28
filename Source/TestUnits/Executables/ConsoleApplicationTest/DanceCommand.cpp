// Copyright Grant Abernathy, 2025.
#include "DanceCommand.h"
#include <iostream>

void DanceCommand::Execute(const std::vector<std::string>& args) {
    std::cout << "\nLet's Dance!\n";
    std::cout << "  \\o/  \n";
    std::cout << "   |   \n";
    std::cout << "  / \\  \n";
    std::cout << "Doing the robot...\n\n";
}

std::string DanceCommand::GetName() const {
    return "dance";
}

std::string DanceCommand::GetDescription() const {
    return "ASCII Dance!";
}
