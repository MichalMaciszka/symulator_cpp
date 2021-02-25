#pragma once
#include "Zwierze.h"

#define SILA_LISA 3
#define INICJATYWA_LISA 7
#define SYMBOL_LISA 'L'
#define KOLORY_LISA Kolory::white, Kolory::darkRed
#define SILNIEJSZY_OSTROSC_ZNAKU >

class Lis : public Zwierze {
public:
	Lis(Swiat& swiat, const Point& polozenie);
	Lis(Swiat& swiat, const Point& polozenie, const int& sila);
	Lis(Swiat& swiat, const Point& polozenie, const int& sila, const int& wiek);
	Organizm* wygenerujKopie(const Point& polozenie) override;
	bool CzyTenSamGatunek(Organizm* organizm) override;
	Point GetPoleDocelowe() override;
	std::string GetNazwa() const override;
	~Lis();
};