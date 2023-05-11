#include "../include/MaxPowerTest.hpp"
#include <stdexcept>
#define M engine_->getEngineCondition().torque
#define V engine_->getEngineCondition().crankshaft_speed

std::pair<double, double> MaxPowerTest <std::pair<double, double>>::run(double step)
{
	if (step <= 0)
		throw std::invalid_argument("Invalid step pushed");
	double overall_time = 0.0,
		current_power = 0.0,
		previous_power = 0.0;
	while (previous_power <= current_power)
	{
		engine_->run(step);
		previous_power = current_power;
		current_power = M * V / 1000;
	}
	return { current_power, M };
}