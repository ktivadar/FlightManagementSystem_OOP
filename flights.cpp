#include "flights.h"
#include <iostream>
#include "cargoAircraft.h"
#include "passengerAircraft.h"


flights::flights() {
	//this->_flights.clear(); //jaratok tisztitasa (inicializalas 0-ra)
}

flights::~flights() {
	this->_flights.clear(); //jaratok tisztitasa
}

//hozzaadasa a jarathoz
void flights::addFlight(const std::string departure_time, const std::string arrival_time, const std::string source, const std::string destination, aircraft* _aircraft) {
	if (_aircraft->getCondition() < 95)
		throw std::invalid_argument("A repulogep kondicioja nem lehet 95-nel kevesebb. Szervizeles szukseges!");
	this->_flights.push_back(flight(departure_time, arrival_time, _aircraft, source, destination));
}

//jarat paramterekek szerinti atadasa
std::vector<flight> * flights::getFlight(const std::string data, const char _type) {
	std::vector<flight>* _filter = new std::vector<flight>();
	std::vector<flight>::iterator it;
	if (_type == 'a') { //jarat keresese erkezesi ido alapjan: (a)rrival time
		for (it = this->_flights.begin(); it != this->_flights.end(); it++) {
			if (it->getArrivalTime() == data) {
				_filter->push_back(*it);
			}
		}
	}
	else if (_type == 's') { //jarat atadasa indulo hely alapjan: (s)ourcv
		for (it = this->_flights.begin(); it != this->_flights.end(); it++) {
			if (it->getSource() == data) {
				_filter->push_back(*it);
			}
		}
	}
	else if (_type == 'd') { //jarat atadasa uticel alapjan: (d)estination
		for (it = this->_flights.begin(); it != this->_flights.end(); it++) {
			if (it->getDestination() == data) {
				_filter->push_back(*it);
			}
		}
	}
	else { //landolt-teljesites allapota szerint a jaratok atadasa
		for (it = this->_flights.begin(); it != this->_flights.end(); it++) {
			if (it->getArrivalTime() == data) {
				_filter->push_back(*it);
			}
		}
	}

	return _filter; //visszaadjuk a kiszurt listank ami egy vektor
}

//egy bizonyos jarat frissitese
bool flights::updateFlight(const std::string departure_time, const std::string arrival_time, const bool completed, aircraft * _aircraft, const std::string source, const std::string destination, const int flight_id) {
	if (_aircraft->getCondition() < 95)
		throw std::invalid_argument("A repulogep kondicioja nem lehet 95-nel kevesebb. Szervizeles szukseges!");
	std::vector<flight>::iterator it;
	for (it = this->_flights.begin(); it != this->_flights.end(); it++) {
		if ((*it).getFlightNumber() == flight_id) {
			(*it).setDepartureTime(departure_time);
			(*it).setArrivalTime(arrival_time);
			(*it).setStatus(completed);
			(*it).setAircraft(_aircraft);
			(*it).setDestination(destination);
			(*it).setSource(source);
			return true;
		}
	}
	return false;
}

//adott jarat eltavolitasa
bool flights::deleteFlight(const int flight_id) {
	std::vector<flight>::iterator it;
	for (it = this->_flights.begin(); it != this->_flights.end(); it++) {
		if ((*it).getFlightNumber() == flight_id) {
			this->_flights.erase(it);
			return true;
		}
	}
	return false;
}

//a jaratok kilistazasa
void flights::display() {
	std::vector<flight>::iterator it;
	std::cout << "***Jarat adatai***\n";
	for (it = this->_flights.begin(); it != this->_flights.end(); it++) {
		(*it).information();
		std::cout << "\n\n";
	}
}

//jarat allapotanak allitasa landoltra jarat ID alapjan
bool flights::departureFlight(const int flight_id) {
	std::vector<flight>::iterator it;
	for (it = _flights.begin(); it !=_flights.end(); it++) {
		if ((*it).getFlightNumber() == flight_id) {
			it->setStatus(true); //statusz igaz-ra allitasa
			(*it).getAircraft()->setCondition((*it).getAircraft()->getCondition() - ((rand() % 8) + 1)); //a repulogep kondicioja egy ut utan csokken->csokkentunk valamennyit 1-8% kozott az allapot ertekebol
			if (dynamic_cast<passengerAircraft*>((*it).getAircraft())) { //ha utasszallito az adott gep dynamikus kasztolas alapjan-tehat atalakithato e es ha igen akkor nem NULLal ter vissza hanem az objektummal
				passengerAircraft* _aircraft = dynamic_cast<passengerAircraft*>((*it).getAircraft()); //akkor utasszallitova konvertaljuk
				_aircraft->setCurrentPassanger(0); //landolas utan az utasok leszallnak ezert a gepen levo szamukat nullazuk.
			}
			else if (dynamic_cast<cargoAircraft*>((*it).getAircraft())) { //maskulonben cargo a gepunk
				cargoAircraft* _aircraft = dynamic_cast<cargoAircraft*>((*it).getAircraft());
				_aircraft->setWeight(0);//kirakodjak landolas utan a szallitmanyt, igy a sulyt 0 ra allitjuk
			}
			return true; //ha talaltunk ilyet akkor igazzal visszaterunk
		}
	}
	return false; //kulonben nem
}

//vectorral jaratok listazasa - szureshez kell ez mert ekkor mar egy szurt vectort fog megkapni.
void flights::display(std::vector<flight> _myflights) {
	std::vector<flight>::iterator it;
	std::cout << "***Jarat adatai***\n";
	for (it = _myflights.begin(); it != _myflights.end(); it++) {
		(*it).information();
		std::cout << "\n\n";
	}
}