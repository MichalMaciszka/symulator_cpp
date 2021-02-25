#pragma once
#include "Zwierze.h"

#define SILA_WILKA 9
#define INICJATYWA_WILKA 5
#define SYMBOL_WILKA 'W'
#define KOLORY_WILKA Kolory::white, Kolory::grey

class Wilk : public Zwierze {
public:
	Wilk(Swiat& swiat, const Point& polozenie);
	Wilk(Swiat& swiat, const Point& polozenie, const int& sila);
	Wilk(Swiat& swiat, const Point& polozenie, const int& sila, const int& wiek);
	Organizm* wygenerujKopie(const Point& polozenie) override;
	bool CzyTenSamGatunek(Organizm* organizm) override;
	std::string GetNazwa() const override;
	~Wilk();
};