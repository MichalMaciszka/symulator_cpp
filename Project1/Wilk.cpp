#include "Wilk.h"

Wilk::Wilk(Swiat& swiat, const Point& polozenie) : Zwierze(swiat, polozenie, SYMBOL_WILKA, SILA_WILKA, INICJATYWA_WILKA, KOLORY_WILKA){}

Wilk::Wilk(Swiat& swiat, const Point& polozenie, const int& sila) : Zwierze(swiat, polozenie, SYMBOL_WILKA, sila, INICJATYWA_WILKA, KOLORY_WILKA){}

Wilk::Wilk(Swiat& swiat, const Point& polozenie, const int& sila, const int& wiek) : Zwierze(swiat, wiek, polozenie, SYMBOL_WILKA, sila, INICJATYWA_WILKA, KOLORY_WILKA) {}

Organizm* Wilk::wygenerujKopie(const Point& polozenie) {
	return new Wilk(this->swiat, polozenie);
}

bool Wilk::CzyTenSamGatunek(Organizm* organizm) {
	return dynamic_cast<Wilk*>(organizm) != nullptr;
}

std::string Wilk::GetNazwa() const {
	return "Wilk";
}

Wilk::~Wilk(){}
