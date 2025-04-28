// Copyright Grant Abernathy, 2025.
#pragma once

#include "BaseCommand.h"

// Command to display help info about other commands.
class HelpCommand : public BaseCommand {
private:
	// Store a reference to the main command map to list commands.
	const CommandMap& commands;
public:
	// Constructor that takes a reference to the command map.
	explicit HelpCommand(const CommandMap& cmdMap) : commands(cmdMap) {}

	// Executes the help display logic.
	void Execute(const std::vector<std::string>& args) override;

	// Returns command name.
	std::string GetName() const override;

	// Returns command description.
	std::string GetDescription() const override;
};
