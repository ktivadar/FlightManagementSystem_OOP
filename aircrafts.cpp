#include "aircrafts.h"
#include "cargoAircraft.h"
#include "militaryAircraft.h"
#include "passengerAircraft.h"
#include <iostream>

aircrafts::aircrafts() {
	//this->_aircrafts.clear(); //repulogepek tisztitasa (inicializalas 0-ra)
}
aircrafts::~aircrafts() {
	//osszes repulogepen vegigiteralas es a ramutatva eltavolitas
	std::vector<aircraft*>::iterator it;

	for (it = this->_aircrafts.begin(); it != this->_aircrafts.end(); it++) {
		delete (*it); //igy minden egyes gep eltavolitasa
	}

	//this->_aircrafts.clear(); //repulogepeket tarolo vektor uritese
}

//Parameterek segitsegevel uj repulogepek hozzaadasa
void aircrafts::add(const std::string &company, const int condition, const float speed, const float noise, const int max_weight, const int weight = 0) { //Cargo gep
	this->_aircrafts.push_back(new cargoAircraft(company, condition, speed, noise, max_weight, weight));
}
void aircrafts::add(const std::string &company, const int condition, const float speed, const float noise, militaryAircraftTypes aircraft_type) { //Military
	this->_aircrafts.push_back(new militaryAircraft(company, condition, speed, noise, aircraft_type));
}
void aircrafts::add(const std::string &company, const int condition, const float speed, const float noise, const int capacity, const int passangers = 0, const int overrider = 0) { //Utasszallito
	this->_aircrafts.push_back(new passengerAircraft(company, condition, speed, noise, capacity, passangers));
}


//Parameterek segitsegevel frissiteni a meglevo gepeket
bool aircrafts::update(const std::string &company, const int condition, const float speed, const float noise, const int max_weight, const int weight, const int aircraft_id) { //Cargo
	std::vector<aircraft*>::iterator it;
	//Az osszes gep vegig iteralasa
	for (it = this->_aircrafts.begin(); it != this->_aircrafts.end(); it++) {
		if ((*it)->getAircraftNumber() == aircraft_id) { //ha megvan a gep akkor frissitsuk
			cargoAircraft *cargo = dynamic_cast<cargoAircraft*>(*it);
			cargo->setCompany(company);
			cargo->setCondition(condition);
			cargo->setNoise(noise);
			cargo->setMaxWeight(max_weight);
			cargo->setWeight(weight);
			cargo->setSpeed(speed);
			return true; //igazzal terunk vissza ha sikerult
		}
	}
	return false; //hamis-al ha kulonben nem talaltunk gepet
}
bool aircrafts::update(const std::string &company, const int condition, const float speed, const float noise, const militaryAircraftTypes aircraft_type, const int aircraft_id) { //Military gep
	std::vector<aircraft*>::iterator it;

	for (it = this->_aircrafts.begin(); it != this->_aircrafts.end(); it++) {
		if ((*it)->getAircraftNumber() == aircraft_id) {
			militaryAircraft* military = dynamic_cast<militaryAircraft*>(*it);
			military->setCompany(company);
			military->setCondition(condition);
			military->setNoise(noise);
			military->setAircraftType(aircraft_type);
			military->setSpeed(speed);
			return true;
		}
	}
	return false;
}

bool aircrafts::update(const std::string &company, const int condition, const float speed, const float noise, const int capacity, const int passangers, const int aircraft_id, const int overrider) { //Utasszallito
	std::vector<aircraft*>::iterator it;
	for (it = this->_aircrafts.begin(); it != this->_aircrafts.end(); it++) {
		if ((*it)->getAircraftNumber() == aircraft_id) {
			passengerAircraft* cargo = dynamic_cast<passengerAircraft*>(*it);
			cargo->setCompany(company);
			cargo->setCondition(condition);
			cargo->setNoise(noise);
			cargo->setCapacity(capacity);
			cargo->setCurrentPassanger(passangers);
			cargo->setSpeed(speed);
			return true;
		}
	}
	return false;
}


//ID alapjan repulogep eltavolitasa
bool aircrafts::remove(const int aircraft_id) {
	std::vector<aircraft*>::iterator it;

	aircraft* rmv;
	for (it = this->_aircrafts.begin(); it != this->_aircrafts.end(); it++) {
		if ((*it)->getAircraftNumber() == aircraft_id) {
			rmv = *it;
			this->_aircrafts.erase(it);
			delete rmv;
			return true;
		}
	}
	return false;
}
bool aircrafts::remove(const aircraft* _aircraft) {
	std::vector<aircraft*>::iterator it;

	for (it = this->_aircrafts.begin(); it != this->_aircrafts.end(); it++) {
		if ((*it) == _aircraft) {
			this->_aircrafts.erase(it);
			return true;
		}
	}
	return false;
}

//repulogep karbantartasa ID alapjan
bool aircrafts::maintainAircraft(int aircraft_id) {
	std::vector<aircraft*>::iterator it;

	for (it = this->_aircrafts.begin(); it != this->_aircrafts.end(); it++) {
		if ((*it)->getAircraftNumber() == aircraft_id) { //ha megtalaltuk a keresett gepet
			(*it)->setCondition(100); //akkor kondiciojat beallitjuk maximumra
			return true;
		}
	}
	return false;
}

//ID alapjan repulogep keresese
aircraft* aircrafts::search(const int aircraft_id) {
	std::vector<aircraft*>::iterator it;

	for (it = this->_aircrafts.begin(); it != this->_aircrafts.end(); it++) {
		if ((*it)->getAircraftNumber() == aircraft_id) { //ha megyezik a keresett ID megtalaltuk es
			return *it; //visszaadjuk a gepet
		}
	}
	return NULL; //NULLT adunk vissza ha nem talalhato
}

//Az osszes repulogep kiiratasa
void aircrafts::display() {
	if (_aircrafts.size() <= 0) { //Ha nem adtunk gepet hozza akkor a meret 0 
		std::cout << "Nem talalhato rogzitett repulogep a rendszerben!" << std::endl;
		return;
	}
	//Az osszes repulogep kilistazasa
	std::cout << "***Repulogepek***\n";
	std::vector<aircraft*>::iterator it;
	for (it = _aircrafts.begin(); it != _aircrafts.end(); it++) {//eredetileg ramutattam this->_aricraft.... -ra de ez nem kotelezo hiszen mar ezen classon belul vagyunk (::)
		(*it)->information(); //virtualis feluliras fuggveny meghivasa minden egyes gepre
		std::cout << "\n\n";
	}
}