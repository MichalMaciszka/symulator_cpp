#include "Czlowiek.h"
#include <conio.h>

bool Czlowiek::AktywujZdolnoscSpecjalna() {
	if (cooldownZdolnosci > 0 || pozostalyCzasZdolnosci > 0)
		return false;
	cooldownZdolnosci = COOLDOWN;
	pozostalyCzasZdolnosci = CZAS_TRWANIA_ZDOLNOSCI_SPECJALNEJ;
	ZdolnoscSpecjalna();
	return true;
}

void Czlowiek::ZdolnoscSpecjalna() {
	if (pozostalyCzasZdolnosci == 0) {
		this->zasiegRuchu = 1;
		return;
	}
	if (pozostalyCzasZdolnosci > 2)
		this->zasiegRuchu = 2;
	else {
		int szansa = std::rand() % 2;
		if (szansa == 0) this->zasiegRuchu = 1;
		else this->zasiegRuchu = 2;
	}
	//this->zasiegRuchu = 1;
}

void Czlowiek::TuraZdolnosci() {
	if (pozostalyCzasZdolnosci > 0)
		pozostalyCzasZdolnosci--;
	else if (cooldownZdolnosci > 0)
		cooldownZdolnosci--;
}

Czlowiek::Czlowiek(Swiat& swiat, const Point& polozenie, const int& sila, const int& zdolnosc, const int& cooldown)
	:Zwierze(swiat, polozenie, SYMBOL_CZLOWIEKA, sila, INICJATYWA_CZLOWIEKA, KOLORY_CZLOWIEKA),	pozostalyCzasZdolnosci(zdolnosc), cooldownZdolnosci(cooldown){}

Czlowiek::Czlowiek(Swiat& swiat, const Point& polozenie, const int& sila, const int& zdolnosc, const int& cooldown, const int& wiek)
	: Zwierze(swiat, wiek, polozenie, SYMBOL_CZLOWIEKA, sila, INICJATYWA_CZLOWIEKA, KOLORY_CZLOWIEKA), pozostalyCzasZdolnosci(zdolnosc), cooldownZdolnosci(cooldown) {}

Czlowiek::Czlowiek(Swiat& swiat, const Point& polozenie)
	: Zwierze(swiat, polozenie, SYMBOL_CZLOWIEKA, SILA_CZLOWIEKA, INICJATYWA_CZLOWIEKA, KOLORY_CZLOWIEKA), pozostalyCzasZdolnosci(0), cooldownZdolnosci(0) {}

Organizm* Czlowiek::wygenerujKopie(const Point& polozenie) {
	return new Czlowiek(this->swiat, polozenie);
}

bool Czlowiek::CzyTenSamGatunek(Organizm* organizm) {
	return dynamic_cast<Czlowiek*>(organizm) != nullptr;
}

Point Czlowiek::GetPoleDocelowe() {
	Point poleDocelowe = this->GetPozycja();
	char c;
	while (true) {
		c = _getch();
		c = tolower(c);
		switch (c)
		{
		case CZLOWIEK_KIERUNEK_N:
			poleDocelowe.Offset(Point::North);
			return poleDocelowe;
		case CZLOWIEK_KIERUNEK_S:
			poleDocelowe.Offset(Point::South);
			return poleDocelowe;
		case CZLOWIEK_KIERUNEK_E:
			poleDocelowe.Offset(Point::East);
			return poleDocelowe;
		case CZLOWIEK_KIERUNEK_W:
			poleDocelowe.Offset(Point::West);
			return poleDocelowe;
		case CZLOWIEK_ZDOLNOSC:
			this->AktywujZdolnoscSpecjalna();
			break;
		case CZLOWIEK_PASS:
			return poleDocelowe;		
		}
	}
}

void Czlowiek::Akcja() {
	//ZdolnoscSpecjalna();
	if (CzyWykonalRuch()) {
		for (int i = 0; i < zasiegRuchu; i++) {
			if (!WykonajRuch())
				break;
		}
	}
	ZdolnoscSpecjalna();
	TuraZdolnosci();
}

std::string Czlowiek::GetNazwa() const {
	return "Czlowiek";
}

std::string Czlowiek::ToString() const {
	std::string str="";
	str += this->GetSymbol();
	str += DELIMITER;
	str += std::to_string(this->GetPozycja().GetX());
	str += DELIMITER;
	str += std::to_string(this->GetPozycja().GetY());
	str += DELIMITER;
	str += std::to_string(this->GetSila());
	str += DELIMITER;
	str += std::to_string(this->GetWiek());
	str += DELIMITER;
	str += std::to_string(this->pozostalyCzasZdolnosci);
	str += DELIMITER;
	str += std::to_string(this->cooldownZdolnosci);
	str += NEWLINEDELIMITER;
	return str;
}

Czlowiek::~Czlowiek(){}