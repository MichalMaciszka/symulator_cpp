#pragma once

enum PrawdopodobienstwaOrganizmow
{
	pTrawa,
	pMlecz,
	pGuarana,
	pWilczeJagody,
	pBarszczSosnowskiego,
	pWilk,
	pOwca,
	pLis,
	pZolw,
	pAntylopa,
	pSUMA
};

double Prawdopodobienstwo[pSUMA] = {
	0.05,	//trawa
	0.10,	//mlecz
	0.10,	//guarana
	0.10,	//wilcze jagody
	0.10,	//barszcz sosnowskiego
	0.10,	//wilk
	0.10,	//owca
	0.15,	//lis
	0.10,	//zolw
	0.10	//antylopa
};