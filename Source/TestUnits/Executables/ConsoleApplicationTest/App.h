// Copyright Grant Abernathy, 2025.
#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "BaseCommand.h"

// Main application class
class App {
private:
	CommandMap commands;
	bool isRunning;

	void RegisterCommands();
	void ProcessInput(const std::string& inputLine);
	std::vector<std::string> TokenizeInput(const std::string& inputLine);

public:
	App();
	~App() = default;

	void Run();
};
