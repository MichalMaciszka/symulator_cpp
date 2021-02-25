#pragma once
#include "RoslinaTrujaca.h"

#define SYMBOL_BARSZCZU 'b'
#define KOLORY_BARSZCZU Kolory::red, Kolory::black
#define SILA_BARSZCZU 10
#define BARSZCZ_SIE_ROZPRZESTRZENIA true

class BarszczSosnowskiego : public RoslinaTrujaca {
public:
	BarszczSosnowskiego(Swiat& swiat, const Point& polozenie);
	BarszczSosnowskiego(Swiat& swiat, const Point& polozenie, const int& sila);
	BarszczSosnowskiego(Swiat& swiat, const Point& polozenie, const int& sila, const int& wiek);
	~BarszczSosnowskiego();
	void Akcja() override;
	std::string GetNazwa() const override;
	Organizm* wygenerujKopie(const Point& polozenie) override;
};