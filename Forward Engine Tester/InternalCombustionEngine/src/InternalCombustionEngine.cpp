#include "../include/InternalCombustionEngine.hpp"
#include <stdexcept>

#define M engine_condition_.torque
#define V engine_condition_.crankshaft_speed
#define Tcur engine_condition_.temp
#define a engine_condition_.acceleration

#define J engine_characteristics_.moment_of_inertia
#define Hm engine_characteristics_.heating_from_torque_coef
#define Hv engine_characteristics_.heating_from_speed_coef
#define C engine_characteristics_.cooling_from_ambient_coef
#define Tmax engine_characteristics_.overheat_temperature

#define Tamb ambient_temperature_

InternalCombustionEngine::InternalCombustionEngine(
	EngineCharacteristics engine_characteristics,
	TorqueFromSpeed torque_from_speed,
	double ambient_temperature)
	:
	engine_characteristics_(engine_characteristics),
	torque_from_speed_(torque_from_speed),
	ambient_temperature_(ambient_temperature) {}

void InternalCombustionEngine::resetEngine()
{
	Tcur = ambient_temperature_;
	V = 0.0;
	M = 0.0;
	a = 0.0;
}

void InternalCombustionEngine::run(double step)
{
	if (step <= 0)
		throw std::invalid_argument("Invalid step pushed");
	V += step * a;
	M = torque_from_speed_(V);
	a = M / J;
	Tcur += step * (- C * (Tamb - Tcur) + (M * Hm + pow(V, 2) * Hv));
}

InternalCombustionEngine::~InternalCombustionEngine() {};