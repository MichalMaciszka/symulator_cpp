#include "Mlecz.h"

Mlecz::Mlecz(Swiat& swiat, const Point& polozenie) : Roslina(swiat, polozenie, SYMBOL_MLECZA, DOMYSLNA_SILA_ROSLINY, KOLORY_MLECZA) {}

Mlecz::Mlecz(Swiat& swiat, const Point& polozenie, const int& sila) : Roslina(swiat, polozenie, SYMBOL_MLECZA, sila, KOLORY_MLECZA) {}

Mlecz::Mlecz(Swiat& swiat, const Point& polozenie, const int& sila, const int& wiek) : Roslina(swiat, wiek, polozenie, SYMBOL_MLECZA, sila, KOLORY_MLECZA) {}

Mlecz::~Mlecz() {}

std::string Mlecz::GetNazwa() const {
	return "Mlecz";
}

void Mlecz::Akcja() {
	for (int i = 0; i < ILOSC_PROB_ROZMNOZENIA_SIE; i++)
		PodejmijProbeRozmnozenia();
}

Organizm* Mlecz::wygenerujKopie(const Point& polozenie) {
	return new Mlecz(swiat, polozenie);
}