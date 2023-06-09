#include <iostream>
#include <map>

#include "InternalCombustionEngine/include/InternalCombustionEngine.hpp"
#include "ConcreteEngineTests/include/MaxPowerTest.hpp"
#include "ConcreteEngineTests/include/OverheatTest.hpp"

int main()
{
#pragma region initial_values
	TorqueFromSpeed tfs({ {0, 20}, {75, 75}, {150, 100}, {200, 105}, {250, 75}, {300, 0} });
	EngineCharacteristics ec;

	ec.moment_of_inertia = 10;
	ec.heating_from_speed_coef = 0.0001;
	ec.heating_from_torque_coef = 0.01;
	ec.cooling_from_ambient_coef = 0.1;
	ec.overheat_temperature = 110;
#pragma endregion
	double ambient_temperature;
	try {

		std::cout << "Enter ambient temperature: ";
		std::cin >> ambient_temperature;

		if (ambient_temperature > ec.overheat_temperature)
			throw std::invalid_argument("Ambient temperature is higher than engine overheat");

		IEngine* engine = new InternalCombustionEngine(ec, tfs, ambient_temperature);
		engine->resetEngine();

		// Overheat test, stops at 110 C
		IEngineTest<double>* ot = new OverheatTest<double>(engine);
		std::cout << "Overheat time: " << ot->run(1) << " s" << std::endl << std::endl;

		engine->resetEngine();

		// Mex power test, stops at maximum power reached
		IEngineTest<std::pair<double, double>>* mpt = new MaxPowerTest<std::pair<double, double>>(engine);
		std::pair<double, double> res = mpt->run(1);
		std::cout << "Max power: " << res.first << " kW ";
		std::cout << "at crankshaft speed : " << res.second << " rad/s" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
}