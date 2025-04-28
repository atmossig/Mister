// Copyright Grant Abernathy, 2025.
#include "HelpCommand.h"
#include <iostream>
#include <iomanip>

// Implementation of the HelpCommand
void HelpCommand::Execute(const std::vector<std::string>& args) {
	std::cout << "Available commands:\n";
	std::cout << "-------------------\n";

	// Determine the maximum command name length for alignment.
	size_t maxLen = 0;
	for (const auto& pair : commands) {
		if (pair.first.length() > maxLen) {
			maxLen = pair.first.length();
		}
	}
	// Add buffer for spacing.
	maxLen += 2;
	// Print each command and it's description.
	for (const auto& pair : commands) {
		// pair.first		Command Name.
		// pair.second		unique_ptr<BaseCommand>
		std::cout << " " << std::left << std::setw(maxLen) << pair.first
			<< ": " << pair.second->GetDescription() << std::endl;
	}
	std::cout << " " << std::left << std::setw(maxLen) << "exit"
		<< ": Quits the app." << std::endl; // Manually add exit cmd.
	std::cout << "-------------------\n";
}

std::string HelpCommand::GetName() const {
	return "help";
}

std::string HelpCommand::GetDescription() const {
	return "Displays this help message.";
}
