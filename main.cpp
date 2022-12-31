#include "crno_belo_slika.h"
#include "vreme.h"
#include "sarena_slika.h"

int main() {

	Piksel p1(2,3),p2(2,3,4);
	//cout << p1;
	//cout << (p1 == p2);
	Pozicija poz0(0,0),poz1(0,1),poz2(0,2),poz3(1,0),poz4(1,1),poz5(1,2),poz6(2,0),poz7(2,1),poz8(2,2);
	Vreme v(11, 40, 35),e(12,12,12);
	Slika  s(3,3,&v);
	Slika d(3, 3, &e);

	//cout << s[poz]<<endl;
	//cout << p2 << endl;
	//s[poz] = p2;
	//cout << s[poz];
	//cout << s;
	//Piksel a = p1 + p2;
	//cout << a;
	s[poz0] = p1;
	s[poz1] = p2;
	s[poz2] = p2;
	s[poz3] = p1;
	s[poz4] = Piksel(200,220,150);
	s[poz5] = p1;
	s[poz6] = p2;
	s[poz7] = p1;
	s[poz8] = p2;
	cout << s;
	//CBSlika cb = &s;
	//cout << cb[poz0];
	SarenaSlika s1(&s);
	cout << s1 << endl;

	SarenaSlika s2(&s, &d);
	cout << s2;
	


	

}