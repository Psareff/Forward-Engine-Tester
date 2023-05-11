#pragma once
#include "EngineCondition.hpp"
class IEngine
{
public:
	virtual void run(double step) = 0;
	virtual void resetEngine() = 0;
	virtual EngineCondition getEngineCondition() const = 0;
};	