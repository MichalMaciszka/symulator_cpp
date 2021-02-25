#include "Antylopa.h"

Antylopa::Antylopa(Swiat& swiat, const Point& polozenie) : Zwierze(swiat, polozenie, SYMBOL_ANTYLOPY, SILA_ANTYLOPY, INICJATYWA_ANTYLOPY, KOLORY_ANTYLOPY, ZASIEG_RUCHU_ANTYLOPY) {}

Antylopa::Antylopa(Swiat& swiat, const Point& polozenie, const int& sila) : Zwierze(swiat, polozenie, SYMBOL_ANTYLOPY, sila, INICJATYWA_ANTYLOPY, KOLORY_ANTYLOPY) {}

Antylopa::Antylopa(Swiat& swiat, const Point& polozenie, const int& sila, const int& wiek) : Zwierze(swiat, wiek, polozenie, SYMBOL_ANTYLOPY, sila, INICJATYWA_ANTYLOPY, KOLORY_ANTYLOPY) {}

Organizm* Antylopa::wygenerujKopie(const Point& polozenie) {
	return new Antylopa(this->swiat, polozenie);
}

bool Antylopa::CzyTenSamGatunek(Organizm* organizm) {
	return dynamic_cast<Antylopa*>(organizm) != nullptr;
}

bool Antylopa::WykonajUnik(Organizm* atakujacy) {
	if (dynamic_cast<Zwierze*>(atakujacy) == nullptr)
		return false;
	double los = (double)std::rand() / RAND_MAX;
	std::vector<Point> mozliwePoleDoUcieczki = Point::GetOffsetByAllUnitVectors(this->GetPozycja());
	while (mozliwePoleDoUcieczki.size()) {
		int i = std::rand() % mozliwePoleDoUcieczki.size();
		if (this->swiat.GetOrganizm(mozliwePoleDoUcieczki[i]) != nullptr) {
			mozliwePoleDoUcieczki.erase(mozliwePoleDoUcieczki.begin() + i);
			continue;
		}
		this->swiat.Przenies(this, mozliwePoleDoUcieczki[i]);
		this->swiat.GetKomentator().PowiadomOUniku(this, atakujacy);
		return true;
	}
	return false;
}

std::string Antylopa::GetNazwa() const {
	return "Antylopa";
}

Antylopa::~Antylopa() {}