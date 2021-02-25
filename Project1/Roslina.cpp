#include "Roslina.h"

double Roslina::GetPrawdRozmnozenia() {
	return prawdopodobienstwo_rozmnozenia_sie;
}

bool Roslina::PodejmijProbeRozmnozenia() {
	double los = (double)std::rand() / RAND_MAX;
	if (los > this->prawdopodobienstwo_rozmnozenia_sie)
		return false;
	Point docelowePole = this->GetPozycja();
	docelowePole.Offset(Point::GetRandomUnitVector());
	Organizm* org = this->swiat.GetOrganizm(docelowePole);
	if (org != nullptr)
		return false;
	Organizm* dziecko = wygenerujKopie(docelowePole);
	this->swiat.DodajOrganizm(docelowePole, dziecko);
	this->swiat.GetKomentator().PowiadomORozsianiu(this, dziecko);
	return true;
}

Roslina::Roslina(Swiat& swiat, const Point& polozenie, const char& symbol, const int& sila, const Kolory::Kolor& kolorFrontu, const Kolory::Kolor& kolorTla, const double& prawdopodobienstwo_rozmnozenia_sie)
	:Organizm(swiat, polozenie, symbol, sila, INICJATYWA_ROSLINY, kolorFrontu, kolorTla), prawdopodobienstwo_rozmnozenia_sie(prawdopodobienstwo_rozmnozenia_sie) {}

Roslina::Roslina(Swiat& swiat, const int& wiek, const Point& polozenie, const char& symbol, const int& sila, const Kolory::Kolor& kolorFrontu, const Kolory::Kolor& kolorTla, const double& prawdopodobienstwo_rozmnazania_sie)
	: Organizm(swiat, polozenie, symbol, sila, INICJATYWA_ROSLINY, kolorFrontu, kolorTla, wiek), prawdopodobienstwo_rozmnozenia_sie(prawdopodobienstwo_rozmnozenia_sie) {}


Roslina::~Roslina() {}

void Roslina::Akcja() {
	if (this->Zywy())
		this->PodejmijProbeRozmnozenia();
}

bool Roslina::Kolizja(Organizm* organizmAtakujacy) {
	this->Umrzyj(organizmAtakujacy);
	return true;
}