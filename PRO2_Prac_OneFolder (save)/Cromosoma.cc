/** @file Cromosoma.cc
 *  @brif Implementacio de la classe especificada a Cromosoma.hh (Cromosoma)
 */

#include "Cromosoma.hh"

Cromosoma::Cromosoma() {

}

Cromosoma::Cromosoma(int l) {
  this -> gens = vector<bool>(l);
}

void Cromosoma::modificar_gen(int i, int g) {
  this -> gens[i] = (g == 1);
}

int Cromosoma::consultar_gen(int i) const {
  if (this -> gens[i]) return 1;
  return 0;
}

void Cromosoma::llegir() {
  int mida = this -> gens.size();
  for (int i = 0; i < mida; ++i) {
    int gen;
    cin >> gen;
    this -> gens[i] = (gen == 1);
  }
}

void Cromosoma::escriure() const {
  int mida = this -> gens.size();
  for (int i = 0; i < mida; ++i) {
    cout << ' ' << (this -> gens[i] ? 1 : 0);
  }
}
