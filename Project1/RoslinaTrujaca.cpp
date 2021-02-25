#include "RoslinaTrujaca.h"

RoslinaTrujaca::RoslinaTrujaca(Swiat& swiat, const Point& polozenie, const char& symbol, const int& sila, const Kolory::Kolor& kolorFrontu, const Kolory::Kolor& kolorTla, const double& prawdopodobienstwo_rozmnozenia_sie)
	:Roslina(swiat, polozenie, symbol, sila, kolorFrontu, kolorTla, prawdopodobienstwo_rozmnozenia_sie) {}

RoslinaTrujaca::RoslinaTrujaca(Swiat& swiat, const int& wiek, const Point& polozenie, const char& symbol, const int& sila, const Kolory::Kolor& kolorFrontu, const Kolory::Kolor& kolorTla, const double& prawdopodobienstwo_rozmnozenia_sie)
	: Roslina(swiat, wiek, polozenie, symbol, sila, kolorFrontu, kolorTla, prawdopodobienstwo_rozmnozenia_sie) {}

RoslinaTrujaca::~RoslinaTrujaca() {}

bool RoslinaTrujaca::Kolizja(Organizm* atakujacy) {
	if (!this->Zywy())
		return true;
	if (this->sila > atakujacy->GetSila()) {
		atakujacy->Umrzyj(this);
		return false;
	}
	else {
		this->Umrzyj(atakujacy);
		atakujacy->Umrzyj(this);
		return true;
	}
}