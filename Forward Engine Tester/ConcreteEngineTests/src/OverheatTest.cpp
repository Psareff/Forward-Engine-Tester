#include "../include/OverheatTest.hpp"
#include <stdexcept>
double OverheatTest <double>::run(double step)
{
	if (step <= 0)
		throw std::invalid_argument("Invalid step pushed");
	double overall_time = 0.0;
	while (true)
	{
		if (engine_->getEngineCondition().temp > 110.0)
			return overall_time;
		overall_time += step;
		engine_->run(step);
	}
}