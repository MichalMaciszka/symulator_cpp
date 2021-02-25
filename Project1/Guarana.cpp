#include "Guarana.h"

Guarana::Guarana(Swiat& swiat, const Point& polozenie) : Roslina(swiat, polozenie, SYMBOL_GUARANA, DOMYSLNA_SILA_ROSLINY, KOLORY_GUARANY) {}

Guarana::Guarana(Swiat& swiat, const Point& polozenie, const int& sila)	: Roslina(swiat, polozenie, SYMBOL_GUARANA, sila, KOLORY_GUARANY){}

Guarana::Guarana(Swiat& swiat, const Point& polozenie, const int& sila, const int& wiek) : Roslina(swiat, wiek, polozenie, SYMBOL_GUARANA, sila, KOLORY_GUARANY) {}

Guarana::~Guarana(){}

std::string Guarana::GetNazwa() const {
	return "Guarana";
}

bool Guarana::Kolizja(Organizm* atakujacy) {
	atakujacy->OffsetSile(GUARANA_BONUS_DO_SILY);
	this->Umrzyj(atakujacy);
	return true;
}

Organizm* Guarana::wygenerujKopie(const Point& polozenie) {
	return new Guarana(swiat, polozenie);
}