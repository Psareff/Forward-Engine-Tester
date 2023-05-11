#pragma once
#include "../../AbstractEngine/include/IEngine.hpp"
template<typename T>
class IEngineTest
{
public:
	virtual T run(double step) = 0;
};