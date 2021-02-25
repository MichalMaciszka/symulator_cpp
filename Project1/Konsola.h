#pragma once
#include <string>
#include <Windows.h>
#include "kolory.h"

class Konsola {
	static HANDLE uchwytKonsoli;
public:
	HANDLE& GetUchwytKonsoli();
	static unsigned short Kolory2UShort(const Kolory::Kolor& kolorTekstu, const Kolory::Kolor& kolorTla);
	static unsigned short GetKolor(const short& x, const short& y);
	static void SetKolor(const short& x, const short& y, unsigned short kolory);
	static void SetKolor(const short& x, const short& y, const Kolory::Kolor& kolorTekstu, const Kolory::Kolor& kolorTla);
	static void Wypisz(const std::string& string, const short& x, const short& y, const Kolory::Kolor &kolorTekstu=Kolory::white, const Kolory::Kolor& kolorTla=Kolory::black);
	static void Wypisz(const char& znak, const short& x, const short& y, const Kolory::Kolor& kolorTekstu = Kolory::white, const Kolory::Kolor& kolorTla = Kolory::black);
	virtual ~Konsola() = 0;
};