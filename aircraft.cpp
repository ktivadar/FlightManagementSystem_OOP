#include "aircraft.h"
#include "uniqueNumberGenerator.h"
#include <iostream>

//repulogep konstruktora
aircraft::aircraft(const std::string company, const int condition, const float speed, const float noise) {
	this->plane_number = uniqueNumberGenerator::generate(); //repulogepnek egyedi ID generalasa
	this->condition = condition;
	this->speed = speed;
	this->noise = noise;
	this->company = company;
}

//Getter es setterek
void aircraft::setCondition(int condition) {
	this->condition = condition;
}

int aircraft::getCondition() {
	return condition;
}

std::string aircraft::getCompany() {
	return this->company;
}

void aircraft::setCompany(const std::string company) {
	this->company = company;
}

float aircraft::getNoise() {
	return this->noise;
}

void aircraft::setNoise(const float noise) {
	this->noise = noise;
}

float aircraft::getSpeed() {
	return this->speed;
}

void aircraft::setSpeed(const float speed) {
	this->speed = speed;
}

int aircraft::getAircraftNumber() {
	return plane_number;
}

//a repulogep informacioja kiirat
void aircraft::_information() {
	std::cout << "Gep ID: " << getAircraftNumber() << "\nCeg: " << getCompany() << "\nKondicio: " << getCondition() << " %" << "\nSebesseg: " << getSpeed() << " km/h" << "\nZajszint: " << getNoise() << "\n";
}