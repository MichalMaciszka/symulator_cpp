#include "Zolw.h"

Zolw::Zolw(Swiat& swiat, const Point& polozenie) : Zwierze(swiat, polozenie, SYMBOL_ZOLWIA, SILA_ZOLWIA, INICJATYWA_ZOLWIA, KOLORY_ZOLWIA, DOMYSLNY_ZASIEG_RUCHU, PRAWDOPODOBIENSTWO_WYKONANIA_RUCHU_ZOLWIA) {}

Zolw::Zolw(Swiat& swiat, const Point& polozenie, const int& sila) : Zwierze(swiat, polozenie, SYMBOL_ZOLWIA, sila, INICJATYWA_ZOLWIA, KOLORY_ZOLWIA, DOMYSLNY_ZASIEG_RUCHU, PRAWDOPODOBIENSTWO_WYKONANIA_RUCHU_ZOLWIA) {}

Zolw::Zolw(Swiat& swiat, const Point& polozenie, const int& sila, const int& wiek) : Zwierze(swiat, wiek, polozenie, SYMBOL_ZOLWIA, sila, INICJATYWA_ZOLWIA, KOLORY_ZOLWIA, DOMYSLNY_ZASIEG_RUCHU, PRAWDOPODOBIENSTWO_WYKONANIA_RUCHU_ZOLWIA) {}

Organizm* Zolw::wygenerujKopie(const Point& polozenie) {
	return new Zolw(this->swiat, polozenie);
}

bool Zolw::CzyTenSamGatunek(Organizm* organizm) {
	return dynamic_cast<Zolw*>(organizm) != nullptr;
}

bool Zolw::CzyOdbilAtak(Organizm* atakujacy) {
	if (atakujacy->GetSila() < ZOLW_ODBIJA_ATAKI) {
		this->swiat.GetKomentator().PowiadomOOdbiciu(this, atakujacy);
		return true;
	}
	return false;
}

std::string Zolw::GetNazwa() const {
	return "Zolw";
}

Zolw::~Zolw() {}