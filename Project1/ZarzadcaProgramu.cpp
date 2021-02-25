#include "ZarzadcaProgramu.h"
#include <conio.h>
#include "Konsola.h"

void ZarzadcaProgramu::WypiszObecnaTure() {
	TCHAR msStr[255];
	std::string str = "Obecna tura: " + std::to_string(swiat.GetObecnaTura());
	int i;
	for (i = 0; i <= str.size(); ++i){
		msStr[i] = str[i];
	}
	msStr[i] = '\0';
	SetConsoleTitle(msStr);
}

void ZarzadcaProgramu::WypiszTytulOkna() {
	std::string str = "Projekt - Michal Maciszka 180522";
	TCHAR* param = new TCHAR[str.size() + 1];
	param[str.size()] = 0;
	std::copy(str.begin(), str.end(), param);
	SetConsoleTitle(param);
}

std::string ZarzadcaProgramu::WyciagnijArgument(const std::string& polecenie, const int& numerArgumentu) {
	int polozenie = this->ZnajdzPolozenieArgumentu(polecenie, numerArgumentu);
	if (polozenie == -1)
		return std::string();
	std::string arg;
	while (polozenie < polecenie.size() && polecenie[polozenie] != ' ') {
		arg += polecenie[polozenie++];
	}
	return arg;
}

int ZarzadcaProgramu::ZnajdzPolozenieArgumentu(const std::string& polecenie, const int& numerArgumentu) {
	int obecnyArgument = -1;
	int polozenieKursora = 0;
	while (polozenieKursora < polecenie.size())
	{
		if (obecnyArgument == numerArgumentu)
		{
			polecenie[polozenieKursora] != ' ';
			return polozenieKursora;
		}

		if (polecenie[polozenieKursora] == ' ')
			obecnyArgument++;

		polozenieKursora++;
	}
	return -1;
}

ZarzadcaProgramu::ZarzadcaProgramu(Swiat& swiat) : swiat(swiat), wyjdz(false) {}

ZarzadcaProgramu::~ZarzadcaProgramu() {}

bool ZarzadcaProgramu::Wyjdz() {
	return wyjdz;
}

bool ZarzadcaProgramu::PrzyjmijPolecenie() {
	//this->WypiszObecnaTure();
	this->WypiszTytulOkna();
	char c = _getch();
	if (c != SYMBOL_POLECENIA)
		return true;

	TCHAR polecenie[255];
	int rozmiar = 0;

	//std::string polecenie;
	polecenie[rozmiar] = c;
	rozmiar++;
	while (true)
	{

		SetConsoleTitle(polecenie);

		c = _getch();
		if (c == '\r')
			break;
		else if (c == KLAWISZ_USUWANIA)
		{
			if (rozmiar > 0)
			{
				polecenie[rozmiar - 1] = '\0';
				rozmiar--;
			}
			continue;
		}
		polecenie[rozmiar] = c;
		rozmiar++;
		polecenie[rozmiar] = '\0';
	}
	this->WypiszTytulOkna();

	if (rozmiar < 2)
		return false;

	std::string arg1;
	std::string arg2;

	std::string polecenie_string = "                  ";
	int i = 0;
	while (polecenie[i] != '\0') {
		polecenie_string[i] = polecenie[i++];
	}

	switch (polecenie[1])
	{
	case WYJDZ:
		this->wyjdz = true;
		return false;
	case LOAD:
		arg1 = this->WyciagnijArgument(polecenie_string);
		if (arg1.size() > 0)
		{
			this->swiat.ZaladujSwiat(arg1);
			return false;
		}
		return true;
	case SAVE:
		arg1 = this->WyciagnijArgument(polecenie_string);
		if (arg1.size() > 0)
		{
			this->swiat.ZapiszSwiat(arg1);
			return false;
		}
		return true;
	case NOWA_GRA:
		arg1 = this->WyciagnijArgument(polecenie_string);
		arg2 = this->WyciagnijArgument(polecenie_string, 1);
		if (arg1 == "" || arg2 == "")
			return true;
		int width = std::stoi(arg1);
		int heigth = std::stoi(arg2);
		this->swiat.RozpocznijNowaGre(width, heigth);
		return false;
	}
	return false;
}