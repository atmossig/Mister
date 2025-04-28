// Copyright Grant Abernathy, 2025.
#pragma once

#include "BaseCommand.h"

// A silly command that performs a text-based dance
class DanceCommand : public BaseCommand {
public:
	void Execute(const std::vector<std::string>& args) override;
	std::string GetName() const override;
	std::string GetDescription() const override;
};
