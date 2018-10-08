/** @file Individu.cc
 *  @brief Implementacio de les funcions de Individu.hh
 */
 
#include "Individu.hh"

Individu::Individu()
{
}

Individu::Individu(char sexe, const Parell_Cromosomes& cromosomes_sexuals, const vector<Parell_Cromosomes>& cromosomes_normals)
{
	this -> sexe = sexe;
	this -> cromosomes_sexuals = cromosomes_sexuals;
	this -> cromosomes_normals = cromosomes_normals;
}

char Individu::consultarSexe() const
{
	return sexe;
}


Cromosoma Individu::consultarCromosomaNormal(int i, int k) const
{
	if (k == 0) return cromosomes_normals[i-1].consultar_c1();
	return cromosomes_normals[i-1].consultar_c2();
}

Cromosoma Individu::consultarCromosomaSexual(int k) const
{
	if (k == 0) return cromosomes_sexuals.consultar_c1();
	return cromosomes_sexuals.consultar_c2();
}

void Individu::llegir(const Especie& especie)
{
	cin >> this -> sexe;
	int lx = especie.consultar_lx();
 	cromosomes_sexuals = Parell_Cromosomes(lx, this -> sexe == 'Y' ? especie.consultar_ly(): lx);
	cromosomes_sexuals.llegir();
	cromosomes_normals = vector<Parell_Cromosomes>(especie.consultar_N());
	for (int i = 0; i < cromosomes_normals.size(); ++i) {
		int li = especie.consultar_li(i+1);
		cromosomes_normals[i] = Parell_Cromosomes(li, li);
		cromosomes_normals[i].llegir();
	}
}

void Individu::escriure() const
{
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
