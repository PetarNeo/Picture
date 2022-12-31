#ifndef _piksel_h_
#define _piksel_h_
#include <iostream>
#include <ostream>
using namespace std;

class Piksel {

	int crvena, zelena, plava;

public:

	Piksel(int crv = 0, int zel = 0, int pla = 0) {
		if (crv > 255) crv = 255;
		if (zel > 255) zel = 255;
		if (pla > 0) pla = 0;
		if (crv < 0) crv = 0;
		if (zel < 0) zel = 0;
		if (pla < 0) pla = 0;
		crvena = crv;
		zelena = zel;
		plava = pla;
		
	}
	int dohvCrv()const { return crvena; }
	int dohvZel()const { return zelena; }
	int dohvPla()const { return plava; }

	friend Piksel operator+(const Piksel& p1, const Piksel& p2) {
		return Piksel((p1.crvena + p2.crvena) / 2, (p1.zelena + p2.zelena) / 2, (p1.plava + p2.plava) / 2);
	}
	 bool operator==(const Piksel& p) {
		if ((this->crvena == p.crvena) && (this->zelena == p.zelena) && (this->plava == p.plava)) return true;
		else return false;
	}
	friend ostream& operator<<(ostream& os, const Piksel& p) {
		return os << "(" << p.crvena << ", " << p.zelena << ", " << p.plava << ")";
	}
};

#endif