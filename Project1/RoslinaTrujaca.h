#pragma once
#include "Roslina.h"

class RoslinaTrujaca : public Roslina {
public:
	RoslinaTrujaca(Swiat& swiat, const Point& polozenie, const char& symbol, const int& sila, const Kolory::Kolor& kolorFrontu, const Kolory::Kolor& kolorTla, const double& prawdopodobienstwo_rozmnozenia_sie = DOMYSLNE_PRAWDOPODOBIENSTWO_ROZMNOZENIA_SIE_ROSLINY);
	RoslinaTrujaca(Swiat& swiat, const int& wiek, const Point& polozenie, const char& symbol, const int& sila, const Kolory::Kolor& kolorFrontu, const Kolory::Kolor& kolorTla, const double& prawdopodobienstwo_rozmnozenia_sie = DOMYSLNE_PRAWDOPODOBIENSTWO_ROZMNOZENIA_SIE_ROSLINY);
	virtual ~RoslinaTrujaca();

	virtual bool Kolizja(Organizm* organizmAtakujacy) override;
};