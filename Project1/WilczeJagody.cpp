#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(Swiat& swiat, const Point& polozenie) : RoslinaTrujaca(swiat, polozenie, SYMBOL_WILCZEJ_JAGODY, SILA_WILCZEJ_JAGODY, KOLORY_WILCZEJ_JAGODY) {}

WilczeJagody::WilczeJagody(Swiat& swiat, const Point& polozenie, const int& sila) : RoslinaTrujaca(swiat, polozenie, SYMBOL_WILCZEJ_JAGODY, sila, KOLORY_WILCZEJ_JAGODY){}

WilczeJagody::WilczeJagody(Swiat& swiat, const Point& polozenie, const int& sila, const int& wiek) : RoslinaTrujaca(swiat, wiek, polozenie, SYMBOL_WILCZEJ_JAGODY, sila, KOLORY_WILCZEJ_JAGODY) {}

WilczeJagody::~WilczeJagody(){}

std::string WilczeJagody::GetNazwa() const {
	return "WilczeJagody";
}

Organizm* WilczeJagody::wygenerujKopie(const Point& polozenie) {
	return new WilczeJagody(this->swiat, polozenie);
}
