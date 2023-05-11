#pragma once
#include <map>
class TorqueFromSpeed
{
private:
	std::map<double, double> initial_dependency_;
public:
	TorqueFromSpeed(){};
	TorqueFromSpeed(std::map<double, double> initial_dependency);
	double operator()(double crankshaft_speed);
};