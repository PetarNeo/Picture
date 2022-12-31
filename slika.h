#ifndef _slika_h_
#define _slika_h_
#include <iostream>
#include <ostream>
#include "piksel.h"
#include "pozicija.h"
#include "vreme.h"

class Slika {

	int visina, sirina;
	Piksel** m = new Piksel*[visina];
	Vreme* vreme;

	void kopiraj(const Slika& s);
	void premesti(Slika& s);
	void brisi();
	friend class CBSlika;
	friend class SarenaSlika;

public:
	Slika(int v, int s, Vreme* a):visina(v), sirina(s),vreme(a){
		for (int i = 0; i < visina; i++) {
			m[i] = new Piksel[sirina];
		}
	}
	Slika(const Slika& s) { kopiraj(s); }
	Slika(Slika&& s) { premesti(s); }
	~Slika() { brisi(); }
	Slika& operator=(const Slika& s) { if (this != &s) { brisi(); kopiraj(s); }return *this; }
	Slika& operator=(Slika&& s) { if (this != &s) { brisi(); premesti(s); }return *this; }
	

	int dohvVis()const { return visina; }
	int dohvSir()const { return sirina; }
	Vreme dohvVR() const { return *vreme; }
	
	Piksel& operator[](const Pozicija& p) {
		if (p.dohKol() > sirina + 1 || p.dohVr() > visina + 1) exit(2);
		return m[p.dohVr()][p.dohKol()];
	}
	const Piksel& operator[](const Pozicija& p)const {
		if (p.dohKol() > sirina + 1  || p.dohVr() > visina + 1) exit(2);
		return m[p.dohVr()][p.dohKol()];
	}
	double velicina()const {
		return visina * sirina * 24;
	}
	friend ostream& operator<<(ostream& os, const Slika& s) {
		os<< *s.vreme << "  " << s.velicina() << endl;
		for (int i = 0; i < s.visina; i++) {
			for (int j = 0; j < s.sirina; j++) {
				os << s.m[i][j] << " ";
			}
			os << endl;
		}
		return os;
	}
	
};

#endif