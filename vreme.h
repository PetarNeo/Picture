#ifndef _vreme_h_
#define _vreme_h_
#include <iostream>
#include "slika.h"

class Vreme {

	int sati, minuti, sekunde;

public:

	Vreme(int s, int m, int se):sati(s),minuti(m),sekunde(se){}

	friend bool operator>(const Vreme& v1, const Vreme& v2) {
		int brs1 = v1.sati * 60 * 60 + v1.minuti * 60 + v1.sekunde;
		int brs2 = v2.sati * 60 * 60 + v2.minuti * 60 + v2.sekunde;
		return brs1 > brs2;
	}
	friend ostream& operator<<(ostream& os, const Vreme& v) {
		return os << v.sati << ":" << v.minuti << ":" << v.sekunde;
	}

};

#endif