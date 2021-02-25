#pragma once
#include "Roslina.h"

#define SYMBOL_MLECZA 'm'
#define KOLORY_MLECZA Kolory::yellow, Kolory::black
#define ILOSC_PROB_ROZMNOZENIA_SIE 3

class Mlecz : public Roslina {
public:
	Mlecz(Swiat& swiat, const Point& polozenie);
	Mlecz(Swiat& swiat, const Point& polozenie, const int& sila);
	Mlecz(Swiat& swiat, const Point& polozenie, const int& sila, const int& wiek);
	virtual ~Mlecz();
	std::string GetNazwa() const override;
	virtual void Akcja() override;
	Organizm* wygenerujKopie(const Point& polozenie) override;
};