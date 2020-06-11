#pragma once
#include "aircraft.h"

class cargoAircraft : public aircraft {
private:
	int max_weight; //Max. terhelhetoseg
	int weight; //jelenlegi teher

public:
	cargoAircraft(const std::string, const int, const float, const float, const int, const int);
	int getMaxWeight();
	void setMaxWeight(const int);
	void setWeight(const int);
	int getWeight();
	void information();
};