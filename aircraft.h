#pragma once
#include <string>
class aircraft {
private:
	int condition; //repulogep kondicioja
	std::string company; //repulogep ceg
	int plane_number; //egyedi gep azonosito (generalt)
	float speed; //repulogephez tartozo sebesseg
	float noise; //zajszint
public:
	aircraft(const std::string, const int, const float, const float); //konstruktor
	int getAircraftNumber(); //repulogep ID
	virtual void information() = 0; //tisztan virtualis fuggveny a repulogepek szerinti informacio tarolasahoz
	void _information(); //jelenlegi repulogep informacioja
	//Getter es setterek prototipusa
	void setCondition(const int);
	std::string getCompany();
	void setCompany(const std::string);
	float getNoise();
	void setNoise(const float);
	float getSpeed();
	void setSpeed(const float);
	int getCondition();
};