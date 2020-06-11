#pragma once
#include "aircraft.h"
#include "militaryAircraft.h"
#include <vector>

class aircrafts {
private:
	std::vector<aircraft *> _aircrafts; //osszes gep tarolasa
public:
	aircrafts(); //repulogepek konstruktora
	~aircrafts(); //destruktor
	void add(const std::string&, const int, const float, const float, const int, const int); //Cargo
	void add(const std::string&, const int, const float, const float, const militaryAircraftTypes); //Military
	void add(const std::string&, const int, const float, const float, const int, const int, const int); //Utasszallito

	bool update(const std::string&, const int, const float, const float, const int, const int, const int); //Cargo
	bool update(const std::string&, const int, const float, const float, const militaryAircraftTypes, const int); //Military
	bool update(const std::string&, const int, const float, const float, const int, const int, const int, const int); //Utasszallito

	bool remove(const int); //ID azonosito szerinti torles
	bool remove(const aircraft*);//objektum szerinti torles

	aircraft* search(const int); //repulogep keresese

	bool maintainAircraft(int); //repulogepek karbantartasa

	void display(); //az osszes gep kilistazasa
};