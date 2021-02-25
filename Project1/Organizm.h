#pragma once
#include "Swiat.h"
#include "Konsola.h"
#include "Point.h"

#define DELIMITER ';'
#define NEWLINEDELIMITER '\n'

class Swiat;

class Organizm {
private:
	char SymbolOrganizmu;
	Kolory::Kolor kolorSymbolu, kolorTla;
	int wiek;
	Point polozenie;
	int inicjatywa;
	bool zywy;
protected:
	int sila;
	Swiat& swiat;
public:
	Organizm(Swiat& swiat, const Point& polozenie, const char& symbol, const int& sila, const int& inicjatywa, const Kolory::Kolor& kolorFrontu, const Kolory::Kolor& kolorTla);
	Organizm(Swiat& swiat, const Point& polozenie, const char& symbol, const int& sila, const int& inicjatywa, const Kolory::Kolor& kolorFrontu, const Kolory::Kolor& kolorTla, const int& wiek);
	virtual void Akcja()=0;
	virtual bool Kolizja(Organizm* organizmAtakujacy) = 0;
	void Rysowanie();
	int GetWiek() const;
	void inkrementujWiek();
	Point GetPozycja() const;
	void SetPozycja(const int& x, const int& y);
	void SetPozycja(const Point& nowePolozenie);
	int GetInicjatywa() const;
	int GetSila() const;
	void OffsetSile(const int& przesuniecie);
	virtual ~Organizm();

	bool Zywy();
	virtual bool Umrzyj(Organizm* zabijajacy);
	virtual bool CzyOdbilAtak(Organizm* atakujacy);
	virtual Organizm* wygenerujKopie(const Point& polozenie) = 0;
	virtual std::string GetNazwa() const;
	virtual std::string ToString() const;
	void SetInicjatywa(const int& inicjatywa);
	virtual std::string SaveToString() const;
	char GetSymbol() const;
};