#pragma once
#include "../../AbstractEngine/include/IEngine.hpp"
#include "../../AbstractEngine/include/EngineCharacteristics.hpp"
#include "TorqueFromSpeed.hpp"
class InternalCombustionEngine : public IEngine
{
public:
	InternalCombustionEngine(
		EngineCharacteristics engine_characteristics,
		TorqueFromSpeed torque_from_speed,
		double ambient_temperature);
	~InternalCombustionEngine();
	
	void run(double step) override;
	void resetEngine() override;
	EngineCondition getEngineCondition() const override;
private:
	EngineCharacteristics engine_characteristics_;
	TorqueFromSpeed torque_from_speed_;

	EngineCondition engine_condition_;
	double ambient_temperature_;
};

inline EngineCondition InternalCombustionEngine::getEngineCondition() const
{
	return engine_condition_;
}