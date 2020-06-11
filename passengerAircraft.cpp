#include "passengerAircraft.h"
#include <iostream>

//utasszalito gep konstruktora
passengerAircraft::passengerAircraft(const std::string company, const int condition, const float speed, const float noise, const int capacity, const int current_passenger) : aircraft(company, condition, speed, noise) {
	if (current_passenger > capacity) //if the current passangers is greater then capacity
		throw std::invalid_argument("Az utasok szama nem lehet nagyobb mint a kapacitas!"); //ezert itt eldobunk egy exception-t
	this->capacity = capacity;
	this->current_passenger = current_passenger;
}

//getter es setterek
int passengerAircraft::getCapacity() {
	return this->capacity;
}
void passengerAircraft::setCapacity(const int capacity) {
	if (this->current_passenger > capacity)
		throw std::invalid_argument("Az utasok szama nem lehet nagyobb az utasszam kapacitasanal, utasok mar meg lettek adva!"); //ha kesobb max utasszamot modositanank pl. kevesebre mint az akt.kapacitas
	this->capacity = capacity;
}
int passengerAircraft::getCurrentPassenger() {
	return this->current_passenger;
}
void passengerAircraft::setCurrentPassanger(const int current_passenger) {
	if (current_passenger > this->capacity)
		throw std::invalid_argument("Az utasok szama nem lehet nagyobb az utasszam kapacitasanal!");
	this->current_passenger = current_passenger;
}

//az alap virtualis fuggveny felulirasa
void passengerAircraft::information() {
	_information();
	std::cout << "Tipus: Utasszallito\nMax. utas kapacitas: " << getCapacity() << " fo" << "\nUtasszam: " << getCurrentPassenger() << " fo" << "\n";
}