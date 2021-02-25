#pragma once
#define WYLACZ_ANIMACJE_RUCHU true
#define IGNORUJ_ANIMACJE_ROSLIN true
#define WYLAP_ZWIERZE true
#define TYP_ZWIERZA Antylopa*
//STALE
#define SYMBOL_PUSTEGO_POLA '.'
#define KOLORY_PUSTEGO_POLA Kolory::white, Kolory::black
#define KOLORY_AKTYWNEGO_ORGANIZMU Kolory::black, Kolory::white
#define CZAS_TRWANIA_RUCHU 1		//w milisekundach
#define POLOZENIE_KOMENTATORA 22,0
//ZAPISYWANIE I WCZYTANIE
#define KATALOG_ZAPISOW "saves/"
#define NAGLOWEK "savefile/"
#define KONIEC_PLIKU "#savefile/end"
enum POLA_ZAPISU
{
	pzSymbol = 0,
	pzX,
	pzY,
	pzSila,
	pzWiek,
	pzMINIMUMDLAORGANIZMU,
	pzCzlowiekZdolnoscAktywna = pzMINIMUMDLAORGANIZMU,
	pzCzlowiekZdolnoscCooldown,
	pzMINIMUMCZLOWIEKA
};