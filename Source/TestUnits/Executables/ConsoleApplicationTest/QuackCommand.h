// Copyright Grant Abernathy, 2025.
#pragma once

#include "BaseCommand.h"

class QuackCommand : public BaseCommand {
public:
	void Execute(const std::vector<std::string>& args) override;
	std::string GetName() const override;
	std::string GetDescription() const override;
};
