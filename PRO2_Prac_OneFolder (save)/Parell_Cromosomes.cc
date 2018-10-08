/** @file Parell_Cromosomes.cc
 *  @brief Es la implementacio de les funcions de Parell_Cromosomes.hh
 */
#include "Parell_Cromosomes.hh"


Parell_Cromosomes::Parell_Cromosomes() {

}

Parell_Cromosomes::Parell_Cromosomes(int i, const Especie& especie) {
	this -> cromosoma1 = Cromosoma(especie.consultar_li(i));
	this -> cromosoma2 = Cromosoma(especie.consultar_li(i));
}

Parell_Cromosomes::Parell_Cromosomes(char sexe, const Especie& especie) {
	this -> cromosoma1 = Cromosoma(especie.consultar_lx());
  if (sexe == 'Y') this -> cromosoma2 = Cromosoma(especie.consultar_ly());
  else             this -> cromosoma2 = Cromosoma(especie.consultar_lx());
}

Parell_Cromosomes::Parell_Cromosomes(const Cromosoma& c1, const Cromosoma& c2) {
	this -> cromosoma1 = c1;
	this -> cromosoma2 = c2;
}

Cromosoma Parell_Cromosomes::consultar_c1() const {
	return cromosoma1;
}

Cromosoma Parell_Cromosomes::consultar_c2() const {
	return cromosoma2;
}

void Parell_Cromosomes::llegir() {
	cromosoma1.llegir();
	cromosoma2.llegir();
}
