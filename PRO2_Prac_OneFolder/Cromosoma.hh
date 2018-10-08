#ifndef CROMOSOMA_HH
#define CROMOSOMA_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif //NO_DIAGRAM

#include "Especie.hh"

using namespace std;

class Cromosoma {
private:
  vector<bool> gens;

  /** @brief <em>Atributs<em>
   *  @brief
   *  gens:  es un vector de gens on true representa tipus 1 i false tipus 0.
   */

public:
  //Constructores
  /** @brief
   *  \pre cert
   *  \post S'ha creat un cromosoma buit.
   */
  Cromosoma();

  /** @brief
   *  \pre L = l
   *  \post S'ha creat un cromosoma de longitud L.
   */
  Cromosoma(int l);

  //Modificadores/Consultores
  /** @brief
   *  \pre I = i, I es entre 0 i la mida del Cromosoma menys 1.
   *  \post canvia el valor del gen numero I per el valor g.
   */
  void modificar_gen(int i , int g);

  /** @brief
   *  \pre I = i, I es entre 0 i la mida del Cromosoma menys 1.
   *  \post Dona el valor del gen numero I.
   */
  int consultar_gen(int i) const;

  //Entrada i Sortida
  /** @brief
   *  \pre Llegeix la informacio del gen en froma de 1 i 0s.
   *  \post Guarda la infromacio de forma, false <== 0 i true <== 1.
   */
  void llegir();

  /** @brief
   *  \pre cert
   *  \post Escriu la informacio en 1 i 0s en funcio de false ==> 0 i true ==> 1
   */
  void escriure() const;
};

#endif //CROMOSOMA_HH
