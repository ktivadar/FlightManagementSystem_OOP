#include "uniqueNumberGenerator.h"

int uniqueNumberGenerator::unique = 0;

uniqueNumberGenerator::uniqueNumberGenerator() { //ures konstruktor
}

int uniqueNumberGenerator::generate() {
	return uniqueNumberGenerator::unique++; //generalt szam novelese 1el
}

int uniqueNumberGenerator::getCurrentNumber() {
	return uniqueNumberGenerator::unique; //jelenlegi szam
}

void uniqueNumberGenerator::reset() {
	uniqueNumberGenerator::unique = 0; //szam reset
}