#pragma once
#include "aircraft.h"
//enum osztaly a military gepek felsorolt tipusaira
enum class militaryAircraftTypes
{
	Fighter,
	Transport,
	Bomber,
	Surveillance
};
class militaryAircraft : public aircraft {
private:
	militaryAircraftTypes aircraft_type; //Military tipusu gep..

public:
	militaryAircraft(const std::string, const int, const float, const float, militaryAircraftTypes);//konstruktor
	//getter es setterek
	militaryAircraftTypes getAircraftType();
	void setAircraftType(militaryAircraftTypes);
	//alap virtualis fuggveny felulirasa
	void information();
};