#include "Lis.h"

Lis::Lis(Swiat& swiat, const Point& polozenie) : Zwierze(swiat, polozenie, SYMBOL_LISA, SILA_LISA, INICJATYWA_LISA, KOLORY_LISA) {}

Lis::Lis(Swiat& swiat, const Point& polozenie, const int& sila) : Zwierze(swiat, polozenie, SYMBOL_LISA, sila, INICJATYWA_LISA, KOLORY_LISA){}

Lis::Lis(Swiat& swiat, const Point& polozenie, const int& sila, const int& wiek) : Zwierze(swiat, wiek, polozenie, SYMBOL_LISA, sila, INICJATYWA_LISA, KOLORY_LISA) {}

Organizm* Lis::wygenerujKopie(const Point& polozenie) {
	return new Lis(this->swiat, polozenie);
}

bool Lis::CzyTenSamGatunek(Organizm* organizm) {
	return dynamic_cast<Lis*>(organizm) != nullptr;
}

Point Lis::GetPoleDocelowe() {
	std::vector<Point> sasiedniePola = Point::GetOffsetByAllUnitVectors(this->GetPozycja());
	while (sasiedniePola.size() > 0) {
		int i = std::rand() % sasiedniePola.size();
		std::vector<Organizm*> sasiadujaceOrganizmy = this->swiat.GetSasiednieOrganizmy(sasiedniePola[i]);
		bool bezpiecznePole = true;
		for (auto organizm : sasiadujaceOrganizmy) {
			if (organizm != nullptr && organizm->GetSila() SILNIEJSZY_OSTROSC_ZNAKU this->GetSila()) {
				bezpiecznePole = false;
				break;
			}
		}
		if (bezpiecznePole)
			return sasiedniePola[i];
		else
			sasiedniePola.erase(sasiedniePola.begin() + i);
	}
	return this->GetPozycja();
}

std::string Lis::GetNazwa() const {
	return "Lis";
}

Lis::~Lis() {}