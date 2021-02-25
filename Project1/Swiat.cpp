#pragma once
#include <chrono>
#include <thread>
#include <fstream>
#include "Swiat.h"
#include "ErrorLog.h"

#include "Swiat_Prawdopodobienstwa.h"
#include "ListaOrganizmow.h"

#include "Stale.h"

void Swiat::ZainicjujNoweOrgnaznimy() {
	if (nowoDodaneOrganizmy.size() == 0) return;
	while (nowoDodaneOrganizmy.size() > 0) {
		kolejkaOrganizmow.push_back(nowoDodaneOrganizmy.front());
		nowoDodaneOrganizmy.pop();
	}
	this->SortujOrganizmy();
}
void Swiat::WykonajZadania() {
	while(doZabicia.size()>0){
		Zabij(doZabicia.front());
		doZabicia.pop();
	}
	while (doPrzeniesienia.size() > 0) {
		Przenies(doPrzeniesienia.front());
		doPrzeniesienia.erase(doPrzeniesienia.begin());
	}
}

Point Swiat::WrapPoint(const Point& point) {
	Point p = point;
	if (point.GetX() < 0) p.OffsetX(szerokosc);
	if (point.GetX() >= szerokosc) p.OffsetX(-szerokosc);
	if (point.GetY() < 0) p.OffsetY(wysokosc);
	if (point.GetY() >= wysokosc) p.OffsetY(-wysokosc);
	return p;
}

void Swiat::ZaludnijSwiat(const double& procentZaludnienia) {
	int liczba_organizmow = 1;
	DodajOrganizm(Point::GetRandomPoint(0, 0, this->szerokosc, this->wysokosc), new Czlowiek (*this, Point()), false);
	double docelowaPopulacja = procentZaludnienia * wysokosc * szerokosc;
	docelowaPopulacja = floor(docelowaPopulacja);
	while (liczba_organizmow < docelowaPopulacja) {
		int x = std::rand() % szerokosc, y = std::rand() % wysokosc;
		if (organizmy[y][x] == nullptr) {
			DodajOrganizm(Point(x, y), nullptr, false);
			liczba_organizmow++;
		}
	}
	ZainicjujNoweOrgnaznimy();
	SortujOrganizmy();
}

void Swiat::DodajOrganizm(const Point& polozenie, Organizm* organizm, bool sortuj) {
	Point wrappedPoint = WrapPoint(polozenie);
	if (organizmy[wrappedPoint.GetY()][wrappedPoint.GetX()] != nullptr)
		return;
	Organizm* org = organizm;
	if (org == nullptr)
		org = GenerujLosowyOrganizm(wrappedPoint);
	else
		org->SetPozycja(wrappedPoint);
	organizmy[wrappedPoint.GetY()][wrappedPoint.GetX()] = org;
	nowoDodaneOrganizmy.push(org);
}

Organizm* Swiat::GenerujLosowyOrganizm(const Point& polozenie) {
	Organizm* organizm = nullptr;
	double los = (double)std::rand() / RAND_MAX;
	PrawdopodobienstwaOrganizmow typ = pSUMA;
	double przedzial = 0;
	for (int i = 0; i < pSUMA; i++) {
		przedzial += Prawdopodobienstwo[i];
		if (los <= przedzial) {
			typ = PrawdopodobienstwaOrganizmow(i);
			break;
		}
	}
	if (przedzial > 0.9999 && typ == pSUMA)
		typ = PrawdopodobienstwaOrganizmow(pSUMA - 1);
	switch (typ)
	{
	case pTrawa:
		organizm = new Trawa(*this, polozenie);
		break;
	case pMlecz:
		organizm = new Mlecz(*this, polozenie);
		break;
	case pGuarana:
		organizm = new Guarana(*this, polozenie);
		break;
	case pWilczeJagody:
		organizm = new WilczeJagody(*this, polozenie);
		break;
	case pBarszczSosnowskiego:
		organizm = new BarszczSosnowskiego(*this, polozenie);
		break;
	case pWilk:
		organizm = new Wilk(*this, polozenie);
		break;
	case pOwca:
		organizm = new Owca(*this, polozenie);
		break;
	case pLis:
		organizm = new Lis(*this, polozenie);
		break;
	case pZolw:
		organizm = new Zolw(*this, polozenie);
		break;
	case pAntylopa:
		organizm = new Antylopa(*this, polozenie);
		break;
	case pSUMA:
	default:
		return nullptr;
	}
	return organizm;
}

void Swiat::SortujOrganizmy() {
	std::stable_sort(kolejkaOrganizmow.begin(), kolejkaOrganizmow.end(), PorownanieInicjatywy());
}

void Swiat::Przenies(const PrzeniesDo& przeniesDo) {
	int x1 = przeniesDo.oryginalny.GetX();
	int y1 = przeniesDo.oryginalny.GetY();
	int x2 = przeniesDo.docelowy.GetX();
	int y2 = przeniesDo.docelowy.GetY();
	if (organizmy[y1][x1] != nullptr && organizmy[y2][x2] != nullptr) {
		ERR << "NIEPRAWIDLOWA OPERACJA. PROBA PRZENIESIENIA " << x1 << ", " << y1 << ", " << &organizmy[y1][x1];
		return;
	}
	else if (organizmy[y1][x1] == nullptr && organizmy[y2][x2] == nullptr) 
		return;
	std::swap(organizmy[y2][x2], organizmy[y1][x1]);
	if (organizmy[y1][x1] != nullptr)
		organizmy[y1][x1]->SetPozycja(x1, y1);
	if (organizmy[y2][x2] != nullptr)
		organizmy[y2][x2]->SetPozycja(x2, y2);
}
void Swiat::Zabij(const Point& zabij) {
	Organizm* organizm = organizmy[zabij.GetY()][zabij.GetX()];
	if (organizm == nullptr)
		return;
	int len = doPrzeniesienia.size();
	for (int i = 0; i < len; i++) {
		if (doPrzeniesienia[i].oryginalny == zabij) {
			doPrzeniesienia.erase(doPrzeniesienia.begin() + i);
			i--;
		}
	}
	organizmy[zabij.GetY()][zabij.GetX()] = nullptr;
}

void Swiat::RysujOdswiezonePola() {
	for (auto pole : polaDoOdswiezenia) {
		Organizm* org = this->GetOrganizm(pole);
		if (org == nullptr) {
			Konsola::Wypisz(SYMBOL_PUSTEGO_POLA, pole.GetX(), pole.GetY(), KOLORY_PUSTEGO_POLA);
		}
		else
			org->Rysowanie();
	}
	polaDoOdswiezenia.clear();
}

int Swiat::GetObecnaTura() {
	return tura;
}

Komentator& Swiat::GetKomentator() {
	return this->komentator;
}

void Swiat::RozpocznijNowaGre(const int& szerokosc, const int& wysokosc, bool zaludniaj) {
	system("cls");
	this->WyzerujWszystkieTablice();
	this->InicjujSwiat(szerokosc, wysokosc, DOMYSLNE_ZALUDNIENIE, zaludniaj);
}

bool Swiat::ZapiszSwiat(const std::string& sciezkaDoZapisu) {
	std::ofstream file(KATALOG_ZAPISOW + sciezkaDoZapisu);
	if (!file.good()) {
		return false;
	}
	file << NAGLOWEK << NEWLINEDELIMITER;
	file << szerokosc << ' ' << wysokosc << NEWLINEDELIMITER;
	for (auto organizm : kolejkaOrganizmow) {
		if(organizm->Zywy())
			file << organizm->ToString();
	}
	file << KONIEC_PLIKU;
	file.close();
	return true;
}

bool Swiat::ZaladujSwiat(const std::string& sciezkaDoPlikuZapisu) {
	std::ifstream file(KATALOG_ZAPISOW + sciezkaDoPlikuZapisu);
	if (!file.good())
		return false;

	Organizm* organizm = nullptr;
	if (!this->SprawdzPoprawnoscNaglowka(file))
		return false;

	int szerokosc, wysokosc;
	file >> szerokosc >> wysokosc;

	this->RozpocznijNowaGre(szerokosc, wysokosc, false);

	char c;
	while (!file.eof())
	{
		c = file.peek();
		if (c == '\n'){
			file.get(c);
			continue;
		}
		else if (c == '#'){
			file.close();
			break;
		}
		organizm = this->ZaladujOrganizm(file);
		if (organizm != nullptr)
			this->DodajOrganizm(organizm->GetPozycja(), organizm);

	}

	this->ZainicjujNoweOrgnaznimy();
	return true;
}

void Swiat::WyzerujWszystkieTablice() {
	this->organizmy.clear();
	this->doPrzeniesienia.clear();
	this->kolejkaOrganizmow.clear();
}

void Swiat::InicjujSwiat(const int& szerokosc, const int& wysokosc, const double& procentZaludnienia, bool zaludniaj) {
	this->szerokosc = szerokosc;
	this->wysokosc = wysokosc;
	this->tura = 1;
	this->komentator.Zaczep(Point(szerokosc + 1, wysokosc));
	for (int y = 0; y < wysokosc; y++) {
		organizmy.push_back(std::vector<Organizm*>());
		for (int x = 0; x < szerokosc; x++) {
			organizmy[y].push_back(nullptr);
		}
	}
	if (zaludniaj)
		ZaludnijSwiat(procentZaludnienia);
}

bool Swiat::SprawdzPoprawnoscNaglowka(std::ifstream& file) {
	std::string header = NAGLOWEK;
	char c;
	int len = header.length();
	for (int i = 0; i < len; i++) {
		file.get(c);
		if (c != header[i])
			return false;
	}
	return true;
}

Organizm* Swiat::ZaladujOrganizm(std::ifstream& file) {
	char symbol = ' ';
	int x = -1, y = -1, sila = -1, zdolnosc = 0, cooldown = 0, wiek=0;
	char c;
	std::vector<std::string> buf;
	while (true) {
		if (file.peek() == NEWLINEDELIMITER)
			break;
		buf.push_back(this->GetPolePlikuZapisu(file));
	}
	if (buf.size() < pzMINIMUMDLAORGANIZMU)
		return nullptr;
	else if (!buf[0].size())
		return nullptr;
	symbol = buf[pzSymbol][0];
	x = std::stoi(buf[pzX]);
	y = std::stoi(buf[pzY]);
	sila = std::stoi(buf[pzSila]);
	wiek = std::stoi(buf[pzWiek]);
	if (buf.size() > pzMINIMUMCZLOWIEKA) {
		zdolnosc = std::stoi(buf[pzCzlowiekZdolnoscAktywna]);
		cooldown = std::stoi(buf[pzCzlowiekZdolnoscCooldown]);
	}
	switch(symbol)
	{
	case SYMBOL_CZLOWIEKA:
		return new Czlowiek(*this, Point(x, y), sila, zdolnosc, cooldown, wiek);
	case SYMBOL_ANTYLOPY:
		return new Antylopa(*this, Point(x, y), sila, wiek);
	case SYMBOL_LISA:
		return new Lis(*this, Point(x, y), sila, wiek);
	case SYMBOL_OWCY:
		return new Owca(*this, Point(x, y), sila, wiek);
	case SYMBOL_WILKA:
		return new Wilk(*this, Point(x, y), sila, wiek);
	case SYMBOL_ZOLWIA:
		return new Zolw(*this, Point(x, y), sila, wiek);
	case SYMBOL_BARSZCZU:
		return new BarszczSosnowskiego(*this, Point(x, y), sila, wiek);
	case SYMBOL_GUARANA:
		return new Guarana(*this, Point(x, y), sila, wiek);
	case SYMBOL_MLECZA:
		return new Mlecz(*this, Point(x, y), sila, wiek);
	case SYMBOL_TRAWY:
		return new Trawa(*this, Point(x, y), sila, wiek);
	case SYMBOL_WILCZEJ_JAGODY:
		return new WilczeJagody(*this, Point(x, y), sila, wiek);
	default:
		return nullptr;
	}
}

std::string Swiat::GetPolePlikuZapisu(std::ifstream& file) {
	char c;
	std::string pole;
	while (true) {
		if (file.eof()) return pole;
		c = file.peek();
		if (c == DELIMITER) {
			file.get(c);
			return pole;
		}
		else if (c == NEWLINEDELIMITER)
			return pole;
		else {
			file.get(c);
			pole += c;
		}
	}
	return pole;
}

Swiat::Swiat(const int& szerokosc, const int& wysokosc, const double& procentZaludnienia) : szerokosc(szerokosc), wysokosc(wysokosc), tura(1), komentator(Point(szerokosc + 1, wysokosc + 1)) {
	if (szerokosc <= 0 || wysokosc <= 0) 
		return;
	this->InicjujSwiat(szerokosc, wysokosc, procentZaludnienia);
}

Swiat::~Swiat() {
	for (int y = 0; y < wysokosc; y++) {
		for (int x = 0; x < szerokosc; x++) {
			if (organizmy[y][x] != nullptr)
				delete organizmy[y][x];
		}
	}
}

bool Swiat::Good() const {
	return organizmy.size() != 0;
}

bool Swiat::Przenies(Organizm* organizmDoPrzeniesienia, const Point& docelowy) {
	if (organizmDoPrzeniesienia == nullptr)
		return false;
	Point p = WrapPoint(docelowy);
	doPrzeniesienia.emplace_back(organizmDoPrzeniesienia->GetPozycja(), p);
	Przenies(doPrzeniesienia.front());
	doPrzeniesienia.pop_back();
	return true;
}

bool Swiat::Zabij(Organizm* organizmDoZabicia) {
	if (organizmDoZabicia == nullptr)
		return false;
	doZabicia.push(organizmDoZabicia->GetPozycja());
	Zabij(doZabicia.front());
	doZabicia.pop();
	return true;
}

Organizm* Swiat::GetOrganizm(const Point& point) {
	Point p = WrapPoint(point);
	return organizmy[p.GetY()][p.GetX()];
}

std::vector<Organizm*> Swiat::GetSasiednieOrganizmy(const Point& polozenie) {
	std::vector<Point> sasiedniePola = Point::GetOffsetByAllUnitVectors(polozenie);
	std::vector<Organizm*> sasiednieOrganizmy;
	int len = sasiedniePola.size();
	for (int i = 0; i < len; i++)
		sasiednieOrganizmy.push_back(this->GetOrganizm(sasiedniePola[i]));
	return sasiednieOrganizmy;
}

void Swiat::Rysuj() {
	for (int y = 0; y < wysokosc; y++) {
		for (int x = 0; x < szerokosc; x++) {
			if (organizmy[y][x] == nullptr)
				Konsola::Wypisz(SYMBOL_PUSTEGO_POLA, x, y, KOLORY_PUSTEGO_POLA);
			else
				organizmy[y][x]->Rysowanie();
		}
	}
}

void Swiat::Test() {
	WykonajZadania();
}

void Swiat::WykonajTure() {
	this->komentator.PowiadomONowejTurze(this->tura);
	for (auto organizm : kolejkaOrganizmow) {
		organizm->inkrementujWiek();
#if !WYLACZ_ANIMACJE_RUCHU
#if IGNORUJ_ANIMACJE_ROSLIN
		if (dynamic_cast<Roslina*>(organizm))
		{
			organizm->Akcja();
			continue;
		}
#endif // IGNORUJ_ANIMACJE_ROSLIN
#if WYLAP_ZWIERZE 
		if (dynamic_cast<TYP_ZWIERZA>(organizm))
		{
			int x = 1;
		}
#endif // WYLAP_ZWIERZE
		int x = organizm->GetPozycja().GetX(), y = organizm->GetPozycja().GetY();
		DWORD kolor = Konsola::GetKolor(x, y);
		Konsola::SetKolor(x, y, KOLORY_AKTYWNEGO_ORGANIZMU);
		std::this_thread::sleep_for(std::chrono::milliseconds(CZAS_TRWANIA_RUCHU / 2));

		organizm->Akcja();
		x = organizm->GetPozycja().GetX(), y = organizm->GetPozycja().GetY();
		Rysuj();
		Konsola::SetKolor(x, y, KOLORY_AKTYWNEGO_ORGANIZMU);
		std::this_thread::sleep_for(std::chrono::milliseconds(CZAS_TRWANIA_RUCHU / 2));
		Konsola::SetKolor(x, y, kolor);
#else
		organizm->Akcja();
#endif // WYLACZ_ANIMACJE_RUCHU
	}
	//WalidujOrganizmy();
	this->ZainicjujNoweOrgnaznimy();
	std::this_thread::sleep_for(std::chrono::milliseconds(CZAS_TRWANIA_RUCHU * 5));
	tura++;
}
void Swiat::OdswiezPole(const Point& pole) {
	polaDoOdswiezenia.emplace_back(pole);
}

void Swiat::OdswiezPole(const std::vector<Point>& pola) {
	for (auto pole : pola) {
		this->OdswiezPole(pole);
	}
}

bool Swiat::PorownanieInicjatywy::operator() (const Organizm* lewy, const Organizm* prawy) const{
	return lewy->GetInicjatywa() > prawy->GetInicjatywa();
}