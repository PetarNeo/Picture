#ifndef _pozicija_h_
#define _pozicija_h_

class Pozicija {

	int vrsta, kolona;

public:

	Pozicija(int v, int k) :vrsta(v), kolona(k){}

	int dohVr()const { return vrsta; }
	int dohKol()const { return kolona; }

	friend int operator-(const Pozicija& p1, const Pozicija& p2) {
		return (p1.kolona - p2.kolona) + (p1.vrsta - p2.vrsta);
	}

};

#endif