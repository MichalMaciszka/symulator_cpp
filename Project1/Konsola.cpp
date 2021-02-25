#include "Konsola.h"
#define GetHandle GetStdHandle(STD_OUTPUT_HANDLE)

HANDLE Konsola::uchwytKonsoli = GetHandle;

HANDLE& Konsola::GetUchwytKonsoli() {
	return uchwytKonsoli;
}

unsigned short Konsola::Kolory2UShort(const Kolory::Kolor& kolorTekstu, const Kolory::Kolor& kolorTla) {
	return ((unsigned)kolorTla << 4) | (unsigned)kolorTekstu;
}

unsigned short Konsola::GetKolor(const short& x, const short& y) {
	COORD pos = { x,y };
	HANDLE uchwyt = GetHandle;
	WORD lpAttribute;
	DWORD numberOfAttrsRead;
	ReadConsoleOutputAttribute(uchwyt, &lpAttribute, 1, pos, &numberOfAttrsRead);
	return lpAttribute;
}

void Konsola::SetKolor(const short& x, const short& y, unsigned short kolory) {
	COORD poz = { x,y };
	DWORD bytesWritten;
	WriteConsoleOutputAttribute(uchwytKonsoli, &kolory, 1, poz, &bytesWritten);
}

void Konsola::SetKolor(const short& x, const short& y, const Kolory::Kolor& kolorTekstu, const Kolory::Kolor& kolorTla) {
	SetKolor(x, y, Kolory2UShort(kolorTekstu, kolorTla));
}

void Konsola::Wypisz(const std::string& string, const short& x, const short& y,	const Kolory::Kolor& kolorTekstu, const Kolory::Kolor& kolorTla) {
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD len = string.size();
	DWORD bytesWritten = 0;

	unsigned short* attrArray = new unsigned short[len];
	for (int i = 0; i < len; i++)
		attrArray[i] = ((unsigned)kolorTla << 4) | (unsigned)kolorTekstu;
	std::wstring stemp = std::wstring(string.begin(), string.end());
	LPCWSTR sw = stemp.c_str();
	WriteConsoleOutputAttribute(output, attrArray, len, pos, &bytesWritten);
	WriteConsoleOutputCharacter(output, sw, len, pos, &bytesWritten);

	delete[] attrArray;
}

void Konsola::Wypisz(const char& znak, const short& x, const short& y,const Kolory::Kolor& kolorTekstu, const Kolory::Kolor& kolorTla) {
	std::string s;
	s += znak;
	Wypisz(s, x, y, kolorTekstu, kolorTla);
}

Konsola::~Konsola() {}