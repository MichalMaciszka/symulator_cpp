#pragma once
#include "Zwierze.h"

#define SILA_OWCY 4
#define INICJATYWA_OWCY 4
#define SYMBOL_OWCY 'O'
#define KOLORY_OWCY Kolory::gray, Kolory::white

class Owca : public Zwierze {
public:
	Owca(Swiat& swiat, const Point& polozenie);
	Owca(Swiat& swiat, const Point& polozenie, const int& sila);
	Owca(Swiat& swiat, const Point& polozenie, const int& sila, const int& wiek);
	Organizm* wygenerujKopie(const Point& polozenie) override;
	bool CzyTenSamGatunek(Organizm* organizm) override;
	std::string GetNazwa() const override;

	~Owca();
};