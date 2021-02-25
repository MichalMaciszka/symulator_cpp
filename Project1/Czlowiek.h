#pragma once
#include "Zwierze.h"

#define SILA_CZLOWIEKA 99
#define INICJATYWA_CZLOWIEKA 4
#define SYMBOL_CZLOWIEKA '@'
#define KOLORY_CZLOWIEKA Kolory::white, Kolory::red
#define CZLOWIEK_KIERUNEK_N 'w'
#define CZLOWIEK_KIERUNEK_E 'd'
#define CZLOWIEK_KIERUNEK_S 's'
#define CZLOWIEK_KIERUNEK_W 'a'
#define CZLOWIEK_ZDOLNOSC 'f'
#define CZLOWIEK_PASS ' '

#define CZAS_TRWANIA_ZDOLNOSCI_SPECJALNEJ 5
#define COOLDOWN 5

class Czlowiek : public Zwierze {
private:
	int pozostalyCzasZdolnosci, cooldownZdolnosci;
	bool AktywujZdolnoscSpecjalna();
	void ZdolnoscSpecjalna();
	void TuraZdolnosci();
public:
	Czlowiek(Swiat& swiat, const Point& polozenie);
	Czlowiek(Swiat& swiat, const Point& polozenie, const int& sila, const int& zdolnosc, const int& cooldown);
	Czlowiek(Swiat& swiat, const Point& polozenie, const int& sila, const int& zdolnosc, const int& cooldown, const int& wiek);
	Organizm* wygenerujKopie(const Point& polozenie) override;
	bool CzyTenSamGatunek(Organizm* organizm) override;
	Point GetPoleDocelowe() override;
	void Akcja() override;
	std::string GetNazwa() const override;
	std::string ToString() const override;
	~Czlowiek();
};