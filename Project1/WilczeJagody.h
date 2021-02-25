#pragma once
#include "RoslinaTrujaca.h"

#define SYMBOL_WILCZEJ_JAGODY 'w'
#define KOLORY_WILCZEJ_JAGODY Kolory::darkPurple, Kolory::black
#define SILA_WILCZEJ_JAGODY 99

class WilczeJagody : public RoslinaTrujaca {
public:
	WilczeJagody(Swiat& swiat, const Point& polozenie);
	WilczeJagody(Swiat& swiat, const Point& polozenie, const int& sila);
	WilczeJagody(Swiat& swiat, const Point& polozenie, const int& sila, const int& wiek);
	~WilczeJagody();
	std::string GetNazwa() const override;
	Organizm* wygenerujKopie(const Point& polozenie) override;
};