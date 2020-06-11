#pragma once
#include "aircraft.h"
#include <vector>
#include <string>

class flight {
private:
	int flight_id; //jarat egyedi ID
	std::string departure_time;
	std::string arrival_time;
	bool completed;
	aircraft *_aircraft;
	std::string destination;
	std::string source;

public:
	//konstruktor
	flight(const std::string, const std::string, aircraft *, const std::string, const std::string);
	//Getter es setterek
	bool getStatus();
	int getFlightNumber();
	void setStatus(const bool);
	std::string getDepartureTime();
	std::string getArrivalTime();
	void setDepartureTime(const std::string);
	void setArrivalTime(const std::string);
	aircraft* getAircraft();
	void setAircraft(const aircraft *);
	void setSource(const std::string);
	std::string getSource();
	void setDestination(const std::string);
	std::string getDestination();
	//jarat informacio kiiratas
	void information();
};