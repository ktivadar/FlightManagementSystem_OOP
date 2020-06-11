#pragma once
#include <vector>
#include <string>
#include "flight.h"

class flights {
private:
	std::vector<flight> _flights; //a jaratok tarolasahoz
public:
	flights(); //konstruktor
	~flights(); //destruktor
	void addFlight(const std::string, const std::string, const std::string, const std::string, aircraft*); //jarathoz hozzaadas
	std::vector<flight>* getFlight(const std::string, const char); //mutato alapjan adott jarathoz eleres,kereseshez paramterek szerint
	bool updateFlight(const std::string, const std::string, const bool, aircraft*, const std::string, const std::string, const int); //adott jarat frissitese
	bool deleteFlight(const int); //jarat torlese
	bool departureFlight(const int); //jarat landolt statusz beallitas
	void display(); //az osszes jarat kilistazasa
	void display(const std::vector<flight>); //listazasa a vektorbol
};