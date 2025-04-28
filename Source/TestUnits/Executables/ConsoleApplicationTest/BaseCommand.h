// Copyright Grant Abernathy, 2025.
#pragma once

#include <string>
#include <vector>
#include <memory>
#include <map>

class BaseCommand {
public:
	// Deconstructor.
	virtual ~BaseCommand() = default;

	// Function to execute the command's action
	// Takes vector of string arugments (tokenized input).
	virtual void Execute(const std::vector<std::string>& args) = 0;

	// Function to get the command's name (keyword to type)
	virtual std::string GetName() const = 0;

	// Function to get brief description for the help command.
	virtual std::string GetDescription() const = 0;
};

// Define type alias for storing commands for easier use.
using CommandMap = std::map<std::string, std::unique_ptr<BaseCommand>>;
