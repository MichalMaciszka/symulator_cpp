#include "Organizm.h"


std::string Organizm::SaveToString() const {
	return "Organizm";
}

void Organizm::SetInicjatywa(const int& inicjatywa) {
	this->inicjatywa = inicjatywa;
}

char Organizm::GetSymbol() const {
	return SymbolOrganizmu;
}

Organizm::Organizm(Swiat& swiat, const Point& polozenie, const char& symbol, const int& sila, const int& inicjatywa, const Kolory::Kolor& kolorFrontu, const Kolory::Kolor& kolorTla)
	: swiat(swiat), polozenie(polozenie), SymbolOrganizmu(symbol), sila(sila), inicjatywa(inicjatywa), kolorSymbolu(kolorFrontu), kolorTla(kolorTla), zywy(true), wiek(0) {}

Organizm::Organizm(Swiat& swiat, const Point& polozenie, const char& symbol, const int& sila, const int& inicjatywa, const Kolory::Kolor& kolorFrontu, const Kolory::Kolor& kolorTla, const int& wiek) 
	: swiat(swiat), polozenie(polozenie), SymbolOrganizmu(symbol), sila(sila), inicjatywa(inicjatywa), kolorSymbolu(kolorFrontu), kolorTla(kolorTla), zywy(true), wiek(wiek) {}

void Organizm::Rysowanie() {
	Konsola::Wypisz(SymbolOrganizmu, polozenie.GetX(), polozenie.GetY(), kolorSymbolu, kolorTla);
}

Point Organizm::GetPozycja() const {
	return polozenie;
}

void Organizm::SetPozycja(const int& x, const int& y) {
	SetPozycja(Point(x, y));
}

void Organizm::SetPozycja(const Point& nowePolozenie) {
	polozenie = nowePolozenie;
}

int Organizm::GetInicjatywa() const {
	return inicjatywa;
}

int Organizm::GetSila() const {
	return sila;
}

void Organizm::OffsetSile(const int& przesuniecie) {
	sila += przesuniecie;
}

Organizm::~Organizm(){}

bool Organizm::Zywy() {
	return zywy;
}

bool Organizm::Umrzyj(Organizm* atakujacy) {
	this->swiat.GetKomentator().PowiadomOSmierciOrganizmu(this, atakujacy);
	zywy = false;
	swiat.Zabij(this);
	return true;
}

bool Organizm::CzyOdbilAtak(Organizm* atakujacy) {
	return false;
}

std::string Organizm::GetNazwa() const {
#define _CRT_SECURE_NO_WARNINGS 1
	char buf[256];
	sprintf(buf, "%p", this);
	return std::string(buf);
}

std::string Organizm::ToString() const {
	std::string str;
	str+= this->GetSymbol();
	str+=DELIMITER;
	str += std::to_string(this->GetPozycja().GetX());
	str += DELIMITER;
	str+= std::to_string(this->GetPozycja().GetY());
	str += DELIMITER;
	str+= std::to_string(this->GetSila());
	str += DELIMITER;
	str += std::to_string(this->wiek);

	str+= NEWLINEDELIMITER;

	return str;
}

int Organizm::GetWiek() const{
	return wiek;
}

void Organizm::inkrementujWiek() {
	this->wiek++;
}