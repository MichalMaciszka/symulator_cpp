#include "Komentator.h"
#include "Konsola.h"
#include "Organizm.h"

void Komentator::WymazWiersz(const int& wiersz) {
	std::string wymazywanie = "                                                                                                           ";
	Konsola::Wypisz(wymazywanie, punktZaczepienia.GetX(), punktZaczepienia.GetY() + wiersz, KOLOR_GUMKI_KOMENTATORA);
}

void Komentator::WypiszWierzsz(const std::string& komunikat) {
	Konsola::Wypisz(komunikat, punktZaczepienia.GetX(), punktZaczepienia.GetY() + obecnyWiersz, KOLORY_KOMENTATORA);
	obecnyWiersz++;
	if (obecnyWiersz > MAX_WYSOKOSC)
		obecnyWiersz = 0;
	WymazWiersz(obecnyWiersz);
}

Komentator::Komentator(const Point& punktZaczepienia) : punktZaczepienia(punktZaczepienia), obecnyWiersz(0){}

void Komentator::Zaczep(const Point& punktZaczepienia) {
	this->punktZaczepienia = punktZaczepienia;
}

void Komentator::PowiadomOSmierciOrganizmu(Organizm* umierajacy, Organizm* zabijajacy) {
	std::string komunikat;
	if (zabijajacy == nullptr)
		komunikat = umierajacy->ToString() + " umiera ";
	else
		komunikat = umierajacy->ToString() + " zostal zabity przez " + zabijajacy->ToString();
	this->WypiszWierzsz(komunikat);
}

void Komentator::PowiadomONowejTurze(const int& licznikTury) {
	std::string komunikat = "Rozpoczela sie tura nr. " + std::to_string(licznikTury);
	this->WypiszWierzsz(komunikat);
}

void Komentator::PowiadomOUniku(Organizm* uniknal, Organizm* tenCoAtakowal) {
	this->WypiszWierzsz(uniknal->ToString() + " wykonal unik przed " + tenCoAtakowal->ToString());
}

Komentator::~Komentator(){}

void Komentator::PowiadomOOdbiciu(Organizm* zolw, Organizm* atakujacy){
	this->WypiszWierzsz(zolw->ToString() + " odbill atak " + atakujacy->ToString());
}

void Komentator::PowiadomORozmnozeniu(Organizm* rodzic1, Organizm* rodzic2, Organizm* nowy){
	this->WypiszWierzsz(rodzic1->ToString() + " oraz " + rodzic2->ToString() + " maja dziecko! Ich potomek to: " + nowy->ToString());
}

void Komentator::PowiadomORozsianiu(Organizm* rodzic, Organizm* nowy){
	this->WypiszWierzsz(rodzic->ToString() + " zasial " + nowy->ToString());
}