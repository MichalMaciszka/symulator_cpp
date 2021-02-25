#pragma once
#include "Roslina.h"

#define SYMBOL_TRAWY 't'
#define KOLORY_TRAWY Kolory::green, Kolory::black

class Trawa : public Roslina {
public:
	Trawa(Swiat& swiat, const Point& polozenie);
	Trawa(Swiat& swiat, const Point& polozenie, const int& sila);
	Trawa(Swiat& swiat, const Point& polozenie, const int& sila, const int& wiek);
	~Trawa();
	std::string GetNazwa() const override;
	Organizm* wygenerujKopie(const Point& polozenie) override;
};