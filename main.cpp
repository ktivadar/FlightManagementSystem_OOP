#include  <iostream>
#include "cargoAircraft.h"
#include "flights.h"
#include "aircrafts.h"
#include "passengerAircraft.h"
#include <time.h>

/*
////////////////////
Nev: Kamondy Tivadar
Neptun kód: ZXCJX6
////////////////////
-----------------------------------------------
***** Repter menedzseleset segito program *****
-----------------------------------------------

	Repulogepek kezelesehez kapcsolodo fuggvenyek:

	_aircrafts.add(); metodussal uj gepeket tudunk felvenni a rendszerbe: lehet ez Cargo,military,passenger gep.
		- Cargo gepeknel lehetosegunk van beallitani az aktualis rakomany tomeget illetva az adott gep maximalis terhelhetoseget, aminek nagyobbnak kell lennie mint az akt.tomeg.
		- Utasszallitonal beallithato az aktualis utasok szama illetve hogy az adott gepnek mekkora az utas letszam kapacitasa, utasok szamanak kisebbnek kell lenni mint a max kapacitas.
		- Ezen belul militaryban megkulonboztetunk tobb tipust mint pl. Surveillance,Transport,Fighter,Bomber..
	_aircrafts.update(); egy adott gep valamelyik parameteren modositunk - az egyes gepeket a mar gep hozzaadasanal legeneralt ID segitsegevel tudjuk elerni,azonositani.
	_aircrafts.remove(); segitsegevel eltavolithatunk egyes gepeket ID alapjan
	_aircrafts.maintainAircraft(); segitsegevel tudunk karbantartani egy adott repulogepet, mivel minden repulest kovetoen a gep allapota valamennyi erteket romlik ezert
		ha bizonyos erteket meghaladja a kondicio, szukseges lehet a repulogep karbantartasa. Ha a kondicio rosszabb mint 95% akkor nem adhato hozza a repulogep egy adott jarathoz!
	_aircrafts.search(); segitsegevel ID alapjan tudunk megkeresni egy adott gepet.
	_aircrafts.display(); metodussal listazni tudjuk a repuloket.

	Jaratok kezelesehez kapcsolodo fuggvenyek:

	_flights.addFlight(); metodussal hozza fuzni egy gepet egy jarathoz.
	_flights.departureFlight(); fuggveny segitsegevel egy jarat allapotat "landolt"ra tudjuk beallitani.
		A repulogep kondicioja egy ut utan csokken ezert ekkor csokkentunk 1-8 % kozott a gep kondiciojanak szazalekos ertekebol.
		landolas utan az utasok leszallnak ezert a gepen levo szamukat nullazuk.
		Cargo gepek eseten kirakodjak landolas utan a szallitmanyt, igy a sulyt szinten 0-ra allitjuk
	_flights.display(); metodussal listazni tudjuk a meglevo jaratokat.
	_flights.deleteFlight(); metodussal egy jaratot el tudunk torolni.
	_flights.updateFlight(); metodussal frissiteni tudunk egy adott jarat kulonbozo ertekein: pl. keses hozzaadas az erkezeshez.
	_flights.getFlight(); metodussal egy jaratra kulonbozo parameterekkel mas-mas szempontok alapjan tudunk rakeresni. Mint peldaul (s)ource,(d)estination,(a)rrival time.

*/


int main()
{
	std::cout << "\n\n===== Repter menedzsment rendszer =====\n\n";
	srand(time(NULL)); //kondicio csokkenesenek randomliazasa repules kozben

	aircrafts _aircrafts; //_aircrafts objektum keszites a repulogepek tarolasara
	flights _flights; //jaratok tarolasahoz

	//Military repulogepek felvetele
	_aircrafts.add("MIL-1", 100, 820, 4.6f, militaryAircraftTypes::Bomber); //ceg,kondicio,sebesseg atl.,zajszint,fajta tipusa
	_aircrafts.add("MIL-2", 96, 2500, 7.0f, militaryAircraftTypes::Fighter);
	_aircrafts.add("MIL-3", 100, 2400, 4.6f, militaryAircraftTypes::Surveillance);
	_aircrafts.add("MIL-4", 100, 840, 4.6f, militaryAircraftTypes::Bomber);
	_aircrafts.add("MIL-5", 100, 800, 4.6f, militaryAircraftTypes::Transport);

	//Utasszallito gepek felvetele
	try {
		_aircrafts.add("Wizzair", 100, 1200, 4.6f, 250, 240, 0); //ceg,kondicio,sebesseg atl.,zajszint, kapacitas, utasok szama,overriderer parameter
		_aircrafts.add("Ryanair", 100, 1100, 7.6f, 240, 200, 0);
		_aircrafts.add("Lufthansa", 100, 1400, 9.6f, 400, 365, 0);
	}
	catch (std::exception ex) { //ha nem felel meg valamelyik feltetelnek dobunk egy hibat es elkapjuk
		std::cout << ex.what() << std::endl;
	}
	//Cargo gepek felvetele
	try {
		_aircrafts.add("FedEx", 100, 1300, 4.6f, 300, 250); //ceg,kondicio,seb.atl.,zajszint,max teher,akt.teher
		_aircrafts.add("Amazon", 100, 1200, 7.6f, 400, 125);
		_aircrafts.add("Emirates", 100, 1200, 9.6f, 700, 500);
	}
	catch (std::exception ex) { //ha nem felel meg valamelyik feltetelnek dobunk egy hibat es elkapjuk
		std::cout << ex.what() << std::endl;
	}

	std::cout << "***Repulogepek kiiratasa***\n\n";
	_aircrafts.display();

	//Frissitunk a gep adatain az egyedi ID alapjan megkeresve
	_aircrafts.update("MIL-2", 50, 2000, 7.1f, militaryAircraftTypes::Fighter, 1);

	//Eltavolitunk egy gepet az ID alapjan
	_aircrafts.remove(6);

	//Frissitunk egy gep adatain (ami nem military ezert kell hibakezeles,mivel vannak feltetelek)
	try {
		_aircrafts.update("Lufthansa", 100, 1400, 9.6f, 400, 350, 7, 0);
	}
	catch (std::exception ex) {
		std::cout << ex.what() << std::endl;
	}

	std::cout << "***Repulogepek kiiratasa***\n\n";
	_aircrafts.display();

	//Egy cargo repulogep hozzaadasa egy jarathoz
	try {
		cargoAircraft* cargo_plane = dynamic_cast<cargoAircraft*>(_aircrafts.search(10));
		cargo_plane->setWeight(500);
		_flights.addFlight("2020/05/17 13:30", "2020/05/17 15:50", "BUD", "HAJ", cargo_plane);
	}
	catch (std::exception ex) {
		std::cout << ex.what() << std::endl;
	}
	//Utasszallito hozzadasa egy jarathoz
	try {
		passengerAircraft* passanger_plane = dynamic_cast<passengerAircraft*>(_aircrafts.search(5));
		passanger_plane->setCurrentPassanger(200);
		_flights.addFlight("2020/05/17 10:00", "2020/05/17 12:20", "BUD", "BRU", passanger_plane);
	}
	catch (std::exception ex) {
		std::cout << ex.what() << std::endl;
	}
	//Utasszallito hozzadasa egy jarathoz
	try {
		passengerAircraft* passanger_plane = dynamic_cast<passengerAircraft*>(_aircrafts.search(7));
		passanger_plane->setCurrentPassanger(200);
		_flights.addFlight("2020/05/17 13:30", "2020/05/17 15:30", "BUD", "LTN", passanger_plane);
	}
	catch (std::exception ex) {
		std::cout << ex.what() << std::endl;
	}
	//Military gep hozzadasa egy jarathoz
	try {
		militaryAircraft* military_plane = dynamic_cast<militaryAircraft*>(_aircrafts.search(3));
		_flights.addFlight("2020/05/17 13:35", "2020/05/17 15:30", "CGN", "LTN", military_plane);
	}
	catch (std::exception ex) {
		std::cout << ex.what() << std::endl;
	}
	_flights.display(); //kiiratjuk a jaratokat


	//Egy jarat adatainak frissitese jarat ID segitsegevel
	try {
		_flights.updateFlight("2020/05/17 13:35", "2020/05/17 15:40", false, _aircrafts.search(7), "CGN", "LGW", 14); //14.jaratot modositottak ezert uj uticelt kapott illetve kesest emiatt
	}
	catch (std::exception ex) {
		std::cout << ex.what() << std::endl;
	}

	//uticel alapjan jarat keresese
	std::cout << "Kereses uticel alapjan: " << std::endl;
	std::vector<flight>* f_flights = _flights.getFlight("LTN", 'd'); //kereses (d)estination,(a)rrival t.,(s)ource alapjan
	_flights.display(*f_flights);

	delete f_flights;

	//Jaratok allapotanak beallitas landoltra
	_flights.departureFlight(13);
	_flights.departureFlight(14);

	//Jarat kiiratasa
	std::cout << "***Jaratok kiiratasa leszallas utan***\n\n";
	_flights.display();



	//std::cin.get();
	return 0;
}