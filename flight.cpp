#include "flight.h"
#include <iostream>
#include "uniqueNumberGenerator.h"

//konstruktor
flight::flight(const std::string departure_time = "", const std::string arrival_time = "", aircraft * _aircraft = NULL, const std::string source = "", const std::string destination = "") {
	this->flight_id = uniqueNumberGenerator::generate();
	this->departure_time = departure_time;
	this->arrival_time = arrival_time;
	this->_aircraft = _aircraft;
	this->source = source;
	this->destination = destination;
	this->completed = false;
}

//Getter es setterek
bool flight::getStatus() {
	return completed;
}


int flight::getFlightNumber() {
	return this->flight_id;
}

void flight::setStatus(const bool completed) {
	this->completed = completed;
}

std::string flight::getDepartureTime() {
	return this->departure_time;
}

std::string flight::getArrivalTime() {
	return this->arrival_time;
}

void flight::setDepartureTime(const std::string departure_time) {
	this->departure_time = departure_time;
}

void flight::setArrivalTime(const std::string arrival_time) {
	this->arrival_time = arrival_time;
}

aircraft* flight::getAircraft() {
	return this->_aircraft;
}

void flight::setAircraft(const aircraft*) {
	this->_aircraft = _aircraft;
}

void flight::setSource(const std::string source) {
	this->source = source;
}

std::string flight::getSource() {
	return this->source;
}

void flight::setDestination(const std::string destination) {
	this->destination = destination;
}

std::string flight::getDestination() {
	return this->destination = destination;
}

//Jarat kiiratasa
void flight::information() {
	std::cout << "Jarat ID: " << getFlightNumber() << "\nFelszallas ideje: " << getDepartureTime() << "\nLandolas ido: " << getArrivalTime() << "\nFelszallas helye: " << getSource() << "\nUticel: " << getDestination() << "\nStatusz: " << (this->getStatus() ? "Landolt." : "Folyamatban.") << "\nRepulogep:\n";
	this->_aircraft->information();
}
