#pragma once
#include "Zwierze.h"

#define SILA_ANTYLOPY 4
#define INICJATYWA_ANTYLOPY 4
#define SYMBOL_ANTYLOPY 'A'
#define KOLORY_ANTYLOPY Kolory::yellow, Kolory::blue
#define ZASIEG_RUCHU_ANTYLOPY 2
#define SZANSA_NA_UNIK_ANTYLOPY 0.5

class Antylopa : public Zwierze {
public:
	Antylopa(Swiat& swiat, const Point& polozenie);
	Antylopa(Swiat& swiat, const Point& polozenie, const int& sila);
	Antylopa(Swiat& swiat, const Point& polozenie, const int& sila, const int& wiek);
	Organizm* wygenerujKopie(const Point& polozenie) override;
	bool CzyTenSamGatunek(Organizm* organizm) override;
	bool WykonajUnik(Organizm* organizm) override;
	std::string GetNazwa() const override;
	~Antylopa();
};