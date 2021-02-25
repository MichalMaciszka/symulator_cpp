#pragma once
#include <string>
#include "Point.h"
#include "kolory.h"

#define MAX_WYSOKOSC 20
#define MAX_DLUGOSC_KOMUNIKATU
#define KOLORY_KOMENTATORA Kolory::black, Kolory::white
#define KOLOR_GUMKI_KOMENTATORA Kolory::black, Kolory::black

class Organizm;


class Komentator {
private:
	Point punktZaczepienia;
	unsigned int obecnyWiersz;
	void WymazWiersz(const int& wiersz);
	void WypiszWierzsz(const std::string& komunikat);
public:
	Komentator(const Point& punktZaczepienia);
	void Zaczep(const Point& punktZaczepienia);
	void PowiadomONowejTurze(const int& licznikTur);
	void PowiadomOSmierciOrganizmu(Organizm* umierajacy, Organizm* zabijajcy);
	void PowiadomOUniku(Organizm* uniknal, Organizm* atakujacy);
	void PowiadomOOdbiciu(Organizm* zolw, Organizm* atakujacy);
	void PowiadomORozmnozeniu(Organizm* rodzic1, Organizm* rodzic2, Organizm* nowy);
	void PowiadomORozsianiu(Organizm* rodzic, Organizm* nowy);

	~Komentator();
};