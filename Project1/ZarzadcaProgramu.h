#pragma once
#include "Swiat.h"

#define SYMBOL_POLECENIA ':'
#define POLOZENIE_KONSOLI Point(0,0)
#define KLAWISZ_USUWANIA '\b'
#define KLAWISZ_AKCEPTACJI '\r'

#define WYJDZ 'q'
#define LOAD 'o'
#define SAVE 'w'
#define NOWA_GRA 'n'

class ZarzadcaProgramu {
private:
	Swiat& swiat;
	bool wyjdz;
	void WypiszObecnaTure();
	void WypiszTytulOkna();
	std::string WyciagnijArgument(const std::string& polozenie, const int& numerArgumentu = 0);
	int ZnajdzPolozenieArgumentu(const std::string& polecenie, const int& numerArgumentu = 0);
public:
	ZarzadcaProgramu(Swiat& swiat);
	~ZarzadcaProgramu();
	bool Wyjdz();
	bool PrzyjmijPolecenie();
};