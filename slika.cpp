#include "slika.h"

void Slika::kopiraj(const Slika& s){
	visina = s.visina;
	sirina = s.sirina;
	vreme = s.vreme;
	for (int i = 0; i < visina; i++) {
		for (int j = 0; j < sirina; j++) {
			m[i][j] = s.m[i][j];
		}
	}
}

void Slika::premesti(Slika& s){
	visina = s.visina;
	sirina = s.sirina;
	vreme = s.vreme;
	m = s.m;
	s.m = nullptr;
}

void Slika::brisi(){
	for (int i = 0; i < visina; i++) {
		delete[] m[i];
	}
	delete [] m;
}
