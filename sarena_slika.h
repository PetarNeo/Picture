#ifndef _sarenaslika_h_
#define _sarenaslika_h_
#include "slika.h"
#include <random>

class SarenaSlika{

	Slika* slika;
	Slika* slika2;

public:
	
	SarenaSlika(Slika* s):slika(s) {
		for (int i = 0; i < slika->dohvVis(); i++) {
			for (int j = 0; j < slika->dohvSir(); j++) {
				Pozicija p(i, j);
				int num1 = rand() % 255 + 1;
				int num2 = rand() % 255 + 1;
				int num3 = rand() % 255 + 1;
				(*slika)[p] = (num1, num2, num3);
			}
		}
	}
	SarenaSlika(Slika* s1, Slika* s2):slika(s1),slika2(s2) {
		
		if ((slika->dohvSir() == slika2->dohvSir()) && (slika->dohvVis() == slika2->dohvVis())) {
			for (int i = 0; i < slika->dohvVis(); i++) {
				for (int j = 0; i < slika->dohvSir(); j++) {
					Pozicija p(i, j);
					(*slika)[p] = (*s1)[p] + (*slika2)[p];
					
				}
			}
			if (slika->vreme > slika2->vreme) {
				slika->vreme = slika->vreme;
			}
			else {
				slika->vreme = slika2->vreme;
			}
		}
		else {
			exit(4);
		}
	}
	friend ostream& operator<<(ostream& os, const SarenaSlika& s) {
		os << s.slika->dohvVR() << "  " << s.slika->velicina() << endl;
		for (int i = 0; i < s.slika->dohvVis(); i++) {
			for (int j = 0; j < s.slika->dohvSir(); j++) {
				Pozicija p(i, j);
				os << (*s.slika)[p] << " ";
			}
			os << endl;
		}
		return os;
	}
	/*Piksel& operator[](const Pozicija& p) {

	}*/
};


#endif 