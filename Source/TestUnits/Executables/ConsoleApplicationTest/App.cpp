// Copyright Grant Abernathy, 2025.
#include "App.h"
#include "HelpCommand.h"
#include "QuackCommand.h"
#include "DanceCommand.h"
#include "JokeCommand.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>

// Constructor: Initializes the application state and registers commands.
App::App() : isRunning(true) {
    RegisterCommands();
}

// Registers all available commands.
void App::RegisterCommands() {
    // Create and store instances of each command using unique_ptr
    commands["quack"] = std::make_unique<QuackCommand>();
    commands["dance"] = std::make_unique<DanceCommand>();
    commands["joke"] = std::make_unique<JokeCommand>();

    // Help command needs the map itself to function.
    commands["help"] = std::make_unique<HelpCommand>(commands);

    std::cout << "Registered " << commands.size() << " commands." << std::endl;
}

// Tokenizes the input string into command and arguments.
std::vector<std::string> App::TokenizeInput(const std::string& inputLine) {
    std::stringstream ss(inputLine);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> tokens(begin, end);
    return tokens;
}

// Processes a line of user input/
void App::ProcessInput(const std::string& inputLine) {
    if (inputLine.empty()) {
        return;
    }

    // Tokenize the input line.
    std::vector<std::string> tokens = TokenizeInput(inputLine);
    std::string commandName = tokens[0];

    // Convert command name to lowercase for case-insensitive matching.
    std::transform(commandName.begin(), commandName.end(), commandName.begin(), ::tolower);

    // Handle the exit command explicitly.
    if (commandName == "exit") {
        isRunning = false;
        std::cout << "Exiting application." << std::endl;
        return;
    }

    // Find the command in the map.
    auto it = commands.find(commandName);
    if (it != commands.end()) {
        // Command found, execute it.
        // it->first is the key (string)
        // it->second is the value (unique_ptr<BaseCommand>)
        it->second->Execute(tokens);
    }
    else {
        // Command not found.
        std::cout << "Unknown command: '" << tokens[0] << "'. Type 'help' for a list of commands." << std::endl;
    }
}

// Main application loop.
void App::Run() {
    std::string inputLine;
    std::cout << "\nWelcome to the Silly Console App!" << std::endl;
    std::cout << "Type 'help' for commands or 'exit' to quit." << std::endl;

    while (isRunning) {
        std::cout << "> "; // Prompt.
        if (!std::getline(std::cin, inputLine)) {
            if (std::cin.eof()) {
                std::cout << "\nEOF detected. Exiting." << std::endl;
            }
            else {
                std::cout << "\nInput error. Exiting." << std::endl;
            }
            isRunning = false;
            break;
        }
        ProcessInput(inputLine);
    }
}

int main() {
    App consoleApp;
    consoleApp.Run();
    return 0;
}
