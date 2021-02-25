#include "Zwierze.h"

bool Zwierze::WykonajRuch() {
	Point poleDocelowe = this->GetPoleDocelowe();
	if (poleDocelowe == this->GetPozycja())
		return false;
	Organizm* org = this->swiat.GetOrganizm(poleDocelowe);
	if (org == nullptr) {
		this->swiat.Przenies(this, poleDocelowe);
		return true;
	}
	else if (CzyTenSamGatunek(org)) {
		RozmnozSie(org);
		return false;
	}
	else if (org->Kolizja(this)) {
		swiat.Przenies(this, poleDocelowe);
		return false;
	}
	return false;
}

bool Zwierze::RozmnozSie(Organizm* partner) {
	std::vector<Point> pola = GetPolaDlaDzieci(partner);
	while (pola.size() > 0) {
		int index = std::rand() % pola.size();
		if (this->swiat.GetOrganizm(pola[index]) == nullptr) {
			Organizm* dziecko = this->wygenerujKopie(pola[index]);
			this->swiat.DodajOrganizm(pola[index], dziecko);
			this->swiat.GetKomentator().PowiadomORozmnozeniu(this, partner, dziecko);
			return true;
		}
		pola.erase(pola.begin() + index);
	}
	return false;
}

Point Zwierze::GetPoleDocelowe() {
	Point poleDocelowe = this->GetPozycja();
	Point kierunek = Point::GetRandomUnitVector();
	poleDocelowe.Offset(kierunek);
	return poleDocelowe;
}

std::vector<Point> Zwierze::GetPolaDlaDzieci(Organizm* partner) {
	std::vector<Point> wersory = Point::GetAllUnitVectors();
	std::vector<Point> pierwszy, drugi;
	for (int i = 0; i < wersory.size(); i++) {
		pierwszy.push_back(this->GetPozycja());
		drugi.push_back(this->GetPozycja());
		pierwszy[i].Offset(wersory[i]);
		drugi[i].Offset(wersory[i]);
	}
	pierwszy.insert(pierwszy.end(), drugi.begin(), drugi.end());
	return pierwszy;
}

bool Zwierze::CzyWykonalRuch() {
	double los = (double)std::rand() / RAND_MAX;
	if (los <= szansaWykonaniaRuchu)
		return true;
	return false;
}

bool Zwierze::WykonajUnik(Organizm* atakujacy) {
	return false;
}

Zwierze::Zwierze(Swiat& swiat, const Point& polozenie, const char& symbol, const int& sila, const int& inicjatywa, const Kolory::Kolor& kolorFrontu, const Kolory::Kolor& kolorTla, const int& zasiegRuchu, const double& szansaWykonaniaRuchu)
	:Organizm(swiat, polozenie, symbol, sila, inicjatywa, kolorFrontu, kolorTla), zasiegRuchu(zasiegRuchu), szansaWykonaniaRuchu(szansaWykonaniaRuchu) {}

Zwierze::Zwierze(Swiat& swiat, const int& wiek, const Point& polozenie, const char& symbol, const int& sila, const int& inicjatywa, const Kolory::Kolor& kolorFrontu, const Kolory::Kolor& kolorTla, const int& zasiegRuchu, const double& SzansaWykonaniaRuchu)
	: Organizm(swiat, polozenie, symbol, sila, inicjatywa, kolorFrontu, kolorTla, wiek), zasiegRuchu(zasiegRuchu), szansaWykonaniaRuchu(SzansaWykonaniaRuchu) {}

Zwierze::~Zwierze() {}

void Zwierze::Akcja() {
	if (this->Zywy() && this->CzyWykonalRuch()) {
		for (int i = 0; i < zasiegRuchu; i++) {
			if (!WykonajRuch())
				break;
		}
	}
}
	
bool Zwierze::Kolizja(Organizm* organizmAtakujacy) {
	if (this->sila > organizmAtakujacy->GetSila()) {
		if (!organizmAtakujacy->CzyOdbilAtak(this)) 
			organizmAtakujacy->Umrzyj(this);
		return false;
	}
	else if(this->sila < organizmAtakujacy->GetSila()) {
		if (this->WykonajUnik(organizmAtakujacy))
			return true;
		else if (this->CzyOdbilAtak(organizmAtakujacy))
			return false;
		else {
			this->Umrzyj(organizmAtakujacy);
			return true;
		}
	}
	else {
		if (this->GetWiek() > organizmAtakujacy->GetWiek()) {
			if (!organizmAtakujacy->CzyOdbilAtak(this))
				organizmAtakujacy->Umrzyj(this);
			return false;
		}
		else {
			if (this->WykonajUnik(organizmAtakujacy))
				return true;
			else if (this->CzyOdbilAtak(organizmAtakujacy))
				return false;
			else {
				this->Umrzyj(organizmAtakujacy);
				return true;
			}
		}
	}
}