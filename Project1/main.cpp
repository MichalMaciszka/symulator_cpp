#include <cstdlib>
#include<ctime>
#include<iostream>
#include "Konsola.h"
#include "Point.h"
#include"ZarzadcaProgramu.h"
#include <conio.h>
#define ROZMIAR 20

int main() {
	std::string str = "Projekt - Michal Maciszka 180522";
	TCHAR* param = new TCHAR[str.size() + 1];
	param[str.size()] = 0;
	std::copy(str.begin(), str.end(), param);
	SetConsoleTitle(param);
	std::srand(std::time(nullptr));
	int wysokosc, szerokosc;
	std::cout << "Podaj wymiary (WYSOKOSCxSZEROKOSC)" << std::endl;
	std::cin >> wysokosc >> szerokosc;
	system("cls");
	Swiat swiat (szerokosc, wysokosc);
	ZarzadcaProgramu zarzadca(swiat);
	std::string polecenie;
	while (!zarzadca.Wyjdz()) {
		swiat.Rysuj();
		if (!zarzadca.PrzyjmijPolecenie())
			continue;
		swiat.WykonajTure();
	}
	return 0;
}