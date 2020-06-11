#include "cargoAircraft.h"
#include <iostream>

//Konstruktor
cargoAircraft::cargoAircraft(const std::string company, const int condition, const float speed, const float noise, const int max_weight, const int weight) : aircraft(company, condition, speed, noise) {
	if (weight > max_weight)
		throw std::invalid_argument("A szallitmany sulya nem lehet nagyobb a maximalis terhelhetosegnel!");
	this->max_weight = max_weight;
	this->weight = weight;
}

//Getter es setterek
int cargoAircraft::getMaxWeight() {
	return max_weight;
}

void cargoAircraft::setMaxWeight(const int max_weight) {
	if (this->weight > max_weight)
		throw std::invalid_argument("A teher nem lehet nagyobb a maximalis terhelhetosegnel!, suly mar be lett allitva!"); //ha kesobb max sulyt modositanank pl. kissebbre mint az akt. teher
	this->max_weight = max_weight;
}

void cargoAircraft::setWeight(const int weight) {
	if (weight > this->max_weight)
		throw std::invalid_argument("A teher nem lehet nagyobb a maximalis terhelhetosegnel!");
	this->weight = weight;
}

int cargoAircraft::getWeight() {
	return weight;
}

//feluldefinialjuk a bazis osztalyunk virtualis fuggvenyet
void cargoAircraft::information() {
	_information();
	std::cout << "Tipus: Cargo\nMax terhelhetoseg: " << getMaxWeight() << " t" << "\nJelenlegi teher: " << getWeight() << " t" << "\n";
}