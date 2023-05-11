#pragma once
#include "../include/TorqueFromSpeed.hpp"
#include <stdexcept>
TorqueFromSpeed::TorqueFromSpeed(std::map<double, double> initial_dependency)
	: initial_dependency_(initial_dependency) {}

double TorqueFromSpeed::operator()(double crankshaft_speed)
{
	if (crankshaft_speed > (--initial_dependency_.end())->first ||
		crankshaft_speed < (initial_dependency_.begin())->first)
		throw std::invalid_argument("Crankshaft speed is out of bounds");

	// Piecewise linear interpolation of dependency of torque on crankshaft speed
	else if (initial_dependency_.find(crankshaft_speed) == initial_dependency_.end())
	{
		auto it = initial_dependency_.lower_bound(crankshaft_speed);
		std::pair<double, double> next = *it--, previous = *it;
		return previous.second + (next.second - previous.second) * (crankshaft_speed - previous.first) / (next.first - previous.first);
	}

	else return initial_dependency_[crankshaft_speed];
}