#pragma once
#include <queue>
#include <vector>
#include "Organizm.h"
#include "Point.h"
#include "Komentator.h"

#define DOMYSLNE_ZALUDNIENIE 0.2

class Swiat {
private:
	int szerokosc, wysokosc;
	int tura;
	struct PrzeniesDo {
		Point oryginalny, docelowy;
		PrzeniesDo(const Point& oryginalny, const Point& docelowy) : oryginalny(oryginalny), docelowy(docelowy) {};
	};
	struct PorownanieInicjatywy {
		bool operator() (const Organizm* lewy, const Organizm* prawy) const;
	};
	std::vector<std::vector<Organizm* >> organizmy;
	std::queue<Point> doZabicia;
	std::vector<PrzeniesDo> doPrzeniesienia;
	std::vector<Organizm*> kolejkaOrganizmow;
	std::queue<Organizm*> nowoDodaneOrganizmy;
	void ZainicjujNoweOrgnaznimy();
	void WykonajZadania();
	Point WrapPoint(const Point& point);
	void ZaludnijSwiat(const double& procentZaludnienia);
	Organizm* GenerujLosowyOrganizm(const Point& polozenie);
	void SortujOrganizmy();
	void Przenies(const PrzeniesDo& przeniesDo);
	void Zabij(const Point& zabij);
	//void WalidujOrganizmy();
	std::vector<Point> polaDoOdswiezenia;
	Komentator komentator;
	void WyzerujWszystkieTablice();
	void InicjujSwiat(const int& szerokosc, const int& wysokosc, const double& procentZaludnienia, bool zaludniaj=true);
	bool SprawdzPoprawnoscNaglowka(std::ifstream& file);
	Organizm* ZaladujOrganizm(std::ifstream& file);
	std::string GetPolePlikuZapisu(std::ifstream& file);
public:
	Swiat(const int& szerokosc, const int& wysokosc, const double& procentZaludnienia = DOMYSLNE_ZALUDNIENIE);
	~Swiat();
	bool Good() const;
	bool Przenies(Organizm* organizmDoPrzeniesienia, const Point& docelowy);
	bool Zabij(Organizm* organizmDoZabicia);
	Organizm* GetOrganizm(const Point& point);
	//Organizm* GetOrganizm(Organizm* organizm);
	std::vector<Organizm*> GetSasiednieOrganizmy(const Point& polozenie);
	void DodajOrganizm(const Point& polozenie, Organizm* organizm = nullptr, bool sortuj = true);
	void Rysuj();
	void Test();
	void WykonajTure();
	void OdswiezPole(const Point& point);
	void OdswiezPole(const std::vector<Point>& pola);
	void RysujOdswiezonePola();
	int GetObecnaTura();
	Komentator& GetKomentator();
	void RozpocznijNowaGre(const int& szerokosc, const int& wysokosc, bool zaludniaj = true);
	bool ZapiszSwiat(const std::string& sciezkaDoZapisu);
	bool ZaladujSwiat(const std::string& sciezkaDoZapisu);
};