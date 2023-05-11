#pragma once
struct EngineCharacteristics
{
	double moment_of_inertia,
		heating_from_torque_coef,
		heating_from_speed_coef,
		cooling_from_ambient_coef,
		overheat_temperature;
};
