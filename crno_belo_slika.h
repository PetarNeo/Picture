#ifndef _cbslika_h_
#define _cbslika_h_
#include "slika.h"

class CBSlika {

	Slika* slika;

public:
	
	CBSlika(Slika* s) :slika(s) {}

	Piksel& operator[](const Pozicija& p) {
		if (p.dohKol() > slika->sirina + 1 || p.dohVr() > slika->visina + 1) exit(3);
		Piksel crn, beo(255, 255, 255);
		if (((    (*slika)[p].dohvCrv() + (*slika)[p].dohvZel() + (*slika)[p].dohvPla()) / 3) > 127) {
			return (*slika)[p] = beo;
		}
		else {
			return (*slika)[p] = crn;
		}
	}
	const Piksel& operator[](const Pozicija& p)const {
		if (p.dohKol() > slika->sirina + 1 || p.dohVr() > slika->visina + 1) exit(3);
		Piksel crn, beo(255, 255, 255);
		if ((((*slika)[p].dohvCrv() + (*slika)[p].dohvZel() + (*slika)[p].dohvPla()) / 3) > 127) {
			beo = (*slika)[p];
			return beo;
		}
		else {
			crn = (*slika)[p];
			return crn;
		}
	}
};

#endif