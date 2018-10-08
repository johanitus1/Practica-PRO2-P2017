/** @file
  * @brief Es la implementacio de la classe especificada en Especie.hh
  */

#include "Especie.hh"
using namespace std;

Especie::Especie(){

}

int Especie::consultar_N() const {
	return N;
}

int Especie::consultar_l0() const {
	return l0;
}

int Especie::consultar_lx() const {
	return lx;
}

int Especie::consultar_ly() const {
	return ly;
}

int Especie::consultar_li(int i) const {
	return l[i];
}

void Especie::llegir() {
	cin >> N >> l0;
	l = vector<int>(N);
	for (int i = 0; i < N; ++i) {
		cin >> l[i];
	}
	cin >> lx >> ly;
}
