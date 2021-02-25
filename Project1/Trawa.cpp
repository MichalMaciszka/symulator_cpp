#include "Trawa.h"

Trawa::Trawa(Swiat& swiat, const Point& polozenie) : Roslina(swiat, polozenie, SYMBOL_TRAWY, DOMYSLNA_SILA_ROSLINY, KOLORY_TRAWY) {}

Trawa::Trawa(Swiat& swiat, const Point& polozenie, const int& sila) : Roslina(swiat, polozenie, SYMBOL_TRAWY, sila, KOLORY_TRAWY) {}

Trawa::Trawa(Swiat& swiat, const Point& polozenie, const int& sila, const int& wiek) : Roslina(swiat, wiek, polozenie, SYMBOL_TRAWY, sila, KOLORY_TRAWY) {}

Trawa::~Trawa() {}

std::string Trawa::GetNazwa() const {
	return "Trawa";
}

Organizm* Trawa::wygenerujKopie(const Point& polozenie) {
	return new Trawa(this->swiat, polozenie);
}