#pragma once
#include "../../AbstractEngineTest/include/IEngineTest.hpp"
#include <utility>

template<typename T>
class MaxPowerTest : public IEngineTest<std::pair<double, double>>
{
public:
	MaxPowerTest(IEngine* engine)
		:engine_(engine) {}
	T run(double step) override;
private:
	IEngine* engine_;
};