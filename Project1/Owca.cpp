#include "Owca.h"

Owca::Owca(Swiat& swiat, const Point& polozenie) : Zwierze(swiat, polozenie, SYMBOL_OWCY, SILA_OWCY, INICJATYWA_OWCY, KOLORY_OWCY) {}

Owca::Owca(Swiat& swiat, const Point& polozenie, const int& sila) : Zwierze(swiat, polozenie, SYMBOL_OWCY, sila, INICJATYWA_OWCY, KOLORY_OWCY) {}

Owca::Owca(Swiat& swiat, const Point& polozenie, const int& sila, const int& wiek) : Zwierze(swiat, wiek, polozenie, SYMBOL_OWCY, sila, INICJATYWA_OWCY, KOLORY_OWCY) {}

Organizm* Owca::wygenerujKopie(const Point& polozenie) {
	Organizm* dziecko = new Owca(this->swiat, polozenie);
	return dziecko;
}

bool Owca::CzyTenSamGatunek(Organizm* organizm) {
	return dynamic_cast<Owca*>(organizm) != nullptr;
}

std::string Owca::GetNazwa() const {
	return "Owca";
}

Owca::~Owca() {}