#pragma once
#include "../../AbstractEngineTest/include/IEngineTest.hpp"

template<typename T>
class OverheatTest : public IEngineTest<double>
{
public:
	OverheatTest(IEngine* engine)
		:engine_(engine) {}
	T run(double step) override;
private:
	IEngine* engine_;
};