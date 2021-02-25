#include "BarszczSosnowskiego.h"
#include "Zwierze.h"

BarszczSosnowskiego::BarszczSosnowskiego(Swiat& swiat, const Point& polozenie) : RoslinaTrujaca(swiat, polozenie, SYMBOL_BARSZCZU, SILA_BARSZCZU, KOLORY_BARSZCZU) {}

BarszczSosnowskiego::BarszczSosnowskiego(Swiat& swiat, const Point& polozenie, const int& sila) : RoslinaTrujaca(swiat, polozenie, SYMBOL_BARSZCZU, sila, KOLORY_BARSZCZU) {}

BarszczSosnowskiego::BarszczSosnowskiego(Swiat& swiat, const Point& polozenie, const int& sila, const int& wiek) : RoslinaTrujaca(swiat, wiek, polozenie, SYMBOL_BARSZCZU, sila, KOLORY_BARSZCZU) {}

BarszczSosnowskiego::~BarszczSosnowskiego() {}

void BarszczSosnowskiego::Akcja() {
	if (!this->Zywy())
		return;
	std::vector<Point> otoczenie = Point::GetOffsetByAllUnitVectors(this->GetPozycja());
	for (auto pole : otoczenie) {
		Organizm* org = this->swiat.GetOrganizm(pole);
		if (org == nullptr)
			continue;
		else if (dynamic_cast<Zwierze*>(org) != nullptr)
			org->Umrzyj(this);
	}
#if BARSZCZ_SIE_ROZPRZESTRZENIA
	this->PodejmijProbeRozmnozenia();
#endif

}

std::string BarszczSosnowskiego::GetNazwa() const {
	return "Barszcz";
}

Organizm* BarszczSosnowskiego::wygenerujKopie(const Point& polozenie) {
	return new BarszczSosnowskiego(this->swiat, polozenie);
}