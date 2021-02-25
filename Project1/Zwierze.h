#pragma once
#include "Organizm.h"

#define DOMYSLNY_ZASIEG_RUCHU 1
#define DOMYSLNA_SZANSA_WYKONANIA_RUCHU 1

class Zwierze : public Organizm {
protected:
	virtual bool WykonajRuch();
	virtual bool CzyTenSamGatunek(Organizm* organizm) = 0;
	virtual bool RozmnozSie(Organizm* partner);
	int zasiegRuchu;
	virtual Point GetPoleDocelowe();
	std::vector<Point> GetPolaDlaDzieci(Organizm* partner);
	double szansaWykonaniaRuchu;
	bool CzyWykonalRuch();
	virtual bool WykonajUnik(Organizm* atakujacy);
public:
	Zwierze(Swiat& swiat, const Point& polozenie, const char& symbol, const int& sila, const int& inicjatywa, const Kolory::Kolor& kolorFrontu, const Kolory::Kolor& kolorTla, const int& zasiegRuchu = DOMYSLNY_ZASIEG_RUCHU, const double& SzansaWykonaniaRuchu = DOMYSLNA_SZANSA_WYKONANIA_RUCHU);
	Zwierze(Swiat& swiat, const int& wiek, const Point& polozenie, const char& symbol, const int& sila, const int& inicjatywa, const Kolory::Kolor& kolorFrontu, const Kolory::Kolor& kolorTla, const int& zasiegRuchu = DOMYSLNY_ZASIEG_RUCHU, const double& SzansaWykonaniaRuchu = DOMYSLNA_SZANSA_WYKONANIA_RUCHU);
	virtual ~Zwierze();
	virtual void Akcja() override;
	virtual bool Kolizja(Organizm* organizmAtakujacy) override;
};