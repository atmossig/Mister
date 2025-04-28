#include "JokeCommand.h"
#include <iostream>
#include <vector>
#include <random>
#include <stdexcept>

void JokeCommand::Execute(const std::vector<std::string>& args) {
    std::vector<std::string> jokes = {
        "Why don't programmers like nature? It has too many bugs.",
        "Why did the C++ programmers song note sound wrong? Because he didn't hit the C#.",
        "Why did Ben Shaprio use Objective-C? Because it was Objective."
    };

    if (jokes.empty()) {
        std::cout << "\nI'm all out of jokes!\n\n";
        return;
    }

    // Random Number Generator. Seed it.
    std::random_device rd;
    std::mt19937 gen(rd());

    int max_index = 0;
    if (jokes.size() > 1) {
        if (jokes.size() - 1 > static_cast<size_t>(std::numeric_limits<int>::max())) {
            throw std::runtime_error("Joke vector size exceeds integer limits for distribution.");
        }
        max_index = static_cast<int>(jokes.size() - 1);
    }

    std::uniform_int_distribution<> distrib(0, max_index);

    // Select and print a random joke.
    std::cout << "\nJoke time: " << jokes[distrib(gen)] << "\n\n";
}

std::string JokeCommand::GetName() const {
    return "joke";
}

std::string JokeCommand::GetDescription() const {
    return "Tells a programmer joke (results may vary).";
}
