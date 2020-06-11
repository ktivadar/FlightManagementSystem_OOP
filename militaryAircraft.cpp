#include "militaryAircraft.h"
#include <iostream>

//konstruktor
militaryAircraft::militaryAircraft(const std::string company, const int condition, const float speed, const float noise, militaryAircraftTypes aircraft_type) :aircraft(company, condition, speed, noise) {
	this->aircraft_type = aircraft_type;
}

//getter es setterek
militaryAircraftTypes militaryAircraft::getAircraftType() {
	return this->aircraft_type;
}

void militaryAircraft::setAircraftType(militaryAircraftTypes aircraft_type) {
	this->aircraft_type = aircraft_type;
}

//alap virtualis fuggveny felulirasa
void militaryAircraft::information() {
	_information();
	std::cout << "Tipus: Military\nPlane Tipus: ";
	if (getAircraftType() == militaryAircraftTypes::Bomber) {
		std::cout << "Bomber";
	}
	else if ((getAircraftType() == militaryAircraftTypes::Fighter)) {
		std::cout << "Fighter";
	}
	else if ((getAircraftType() == militaryAircraftTypes::Surveillance)) {
		std::cout << "Surveillance";
	}
	else {
		std::cout << "Transport";
	}
	std::cout << std::endl;
}