/** @file Cromosoma.hh
 *  @brief Es l'arxiu de la especificacio de la classe Cromosoma.
 *  @class Cromosoma
 *  @brief Es la classe que guarda la informacio genetica d'un cromosoma.
 */

#ifndef CROMOSOMA_HH
#define CROMOSOMA_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif //NO_DIAGRAM

using namespace std;

class Cromosoma {
private:
  /** @brief
   *  gens:  és un vector de gens on true representa tipus 1 i false tipus 0.
   */
  vector<bool> gens;

public:
  //Constructores
  /** @brief
   *  \pre cert
   *  \post S'ha creat un cromosoma buit.
   */
  Cromosoma();

  /** @brief
   *  \pre l > 0
   *  \post S'ha creat un cromosoma de longitud l.
   */
  Cromosoma(int l);

  //Modificadores/Consultores
  /** @brief
   *  \pre i és entre 1 i la mida del Cromosoma.
   *  \post canvia el valor del gen número i per el valor g.
   */
  void modificar_gen(int i , int g);

  /** @brief
   *  \pre i és entre 1 i la mida del Cromosoma.
   *  \post Dona el valor del gen número i.
   */
  int consultar_gen(int i) const;

  /** @brief
   *  \pre  cert
   *  \post resulta la mida del cromosoma.
   */
  int mida() const;
  /** @brief
   *  \pre cert
   *  \post Guarda la informació del canal estàndard d'entrada de forma: false <== 0 i true <== 1.
   */
  void llegir();

  /** @brief
   *  \pre cert
   *  \post Escriu la informació en 1 i 0s en funció de false ==> 0 i true ==> 1
   */
  void escriure() const;
};

#endif //CROMOSOMA_HH
