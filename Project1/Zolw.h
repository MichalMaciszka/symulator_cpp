#pragma once
#include "Zwierze.h"

#define SILA_ZOLWIA 2
#define INICJATYWA_ZOLWIA 1
#define SYMBOL_ZOLWIA 'z'
#define KOLORY_ZOLWIA Kolory::green, Kolory::darkGreen
#define PRAWDOPODOBIENSTWO_WYKONANIA_RUCHU_ZOLWIA 0.25
#define ZOLW_ODBIJA_ATAKI 5

class Zolw : public Zwierze {
public:
	Zolw(Swiat& swiat, const Point& polozenie);
	Zolw(Swiat& swiat, const Point& polozenie, const int& sila);
	Zolw(Swiat& swiat, const Point& polozenie, const int& sila, const int& wiek);
	Organizm* wygenerujKopie(const Point& polozenie) override;
	bool CzyTenSamGatunek(Organizm* organizm) override;
	bool CzyOdbilAtak(Organizm* atakujacy) override;
	std::string GetNazwa() const override;
	~Zolw();
};