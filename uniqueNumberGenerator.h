#pragma once
class uniqueNumberGenerator {
private:
	int static unique; //static egyedi szam minden objektum meghivaskor init.var.
public:
	uniqueNumberGenerator(); //konstruktor
	static int generate(); //uj ID letrehozasa
	int getCurrentNumber(); //jelenlegi szam
	void reset();//szam generalas resetelese
};
