/** @file Individu.cc
 *  @brief Implementacio de les funcions de Individu.hh
 */
#include "Individu.hh"

Individu::Individu() {

}

Individu::Individu(char sexe, const Parell_Cromosomes& cromosomes_sexuals, const vector<Parell_Cromosomes>& cromosomes_normals) {
	this -> sexe = sexe;
	this -> cromosomes_sexuals = cromosomes_sexuals;
	this -> cromosomes_normals = cromosomes_normals;
}

char Individu::consultar_sexe() const {
	return sexe;
}


Cromosoma Individu::consultar_cromosoma_normal(int i, int k) const {
	if (k == 0) return cromosomes_normals[i].consultar_c1();
	return cromosomes_normals[i].consultar_c2();
}

Cromosoma Individu::consultar_cromosoma_sexual(int k) const {
	if (k == 0) return cromosomes_sexuals.consultar_c1();
	return cromosomes_sexuals.consultar_c2();
}

void Individu::llegir_individu(const Especie& especie) {
	cin >> this -> sexe;
 	cromosomes_sexuals = Parell_Cromosomes(sexe, especie);
	cromosomes_sexuals.llegir();
	cromosomes_normals = vector<Parell_Cromosomes>(especie.consultar_N());
	for (int i = 0; i < cromosomes_normals.size(); ++i) {
		cromosomes_normals[i] = Parell_Cromosomes(i, especie);
		cromosomes_normals[i].llegir();
	}
}

void Individu::escriure_genotip() const {
	cout << "  X:";
	cromosomes_sexuals.consultar_c1().escriure();
	cout << "  " << sexe << ":";
	cromosomes_sexuals.consultar_c2().escriure();
	for (int i = 0; i < cromosomes_normals.size(); ++i) {
		cout << "  " << i+1 << ".1:";
		cromosomes_normals[i].consultar_c1().escriure();
		cout << "  " << i+1 << ".2:";
		cromosomes_normals[i].consultar_c2().escriure();
	}
}
