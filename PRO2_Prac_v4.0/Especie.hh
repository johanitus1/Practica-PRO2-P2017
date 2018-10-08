/** @file Especie.hh
 *  @brief Es l'arxiu de la classe Especie.
 *  @class Especie
 *  @brief Es la classe que guarda el tipus de informacio genetica d'una especie.
 */

#ifndef ESPECIE_HH
#define ESPECIE_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif //NO_DIAGRAM

using namespace std;

class Especie {
private:

  /**  @brief
   *  N:  És el nombre de parells de cromosomes normals (autosòmics) que te l'espècie.
   */
  int N;

  /**  @brief
   *  l0: És el nombre de gens comuns que tenen els cromosomes sexuals.
   */
  int l0;

  /**  @brief
   *  lx: És el nombre de gens que té el cromosoma X.
   */
  int lx;

  /**  @brief
   *  ly: És el nombre de gens que té el cromosoma Y.
   */
  int ly;

  /**  @brief
   *  l:  És un vector que a la posició i té la informació del cromosoma normal número i+1.
   */
  vector<int> l;


public:
  /** @brief
   *  \pre cert
   *  \post S'ha creat un objecte de tipus Especie buit.
   */
  Especie();

  //Consultores
  /** @brief
   *  \pre p.i. no és buit.
   *  \post dona el nombre de cromosomes normals (no sexuals) de l'Especie
   */
  int consultar_N() const;

  /** @brief
   *  \pre p.i. no es buit.
   *  \post dona el nombre de gens comuns dels cromosomes de l'Especie.
   */
  int consultar_l0() const;

  /** @brief
   *  \pre p.i. no es buit.
   *  \post Dona la longitud del cromosoma sexual x. De l'Especie.
   */
  int consultar_lx() const;

  /** @brief
   *  \pre p.i. no es buit.
   *  \post Dona la longitud del cromosoma sexual y. De l'Especie.
   */
  int consultar_ly() const;

  /** @brief
   *  \pre p.i. no es buit.
   *  \post Dona la longitud del cromosoma nomal (no sexual) numero i, sent I = 1 el primer, i sent I = N l'ultim. De l'Especie.
   */
  int consultar_li(int i) const;

  //Entrada
  /** @brief
   *  \pre cert
   *  \post L'entrada per el canal d'entrade estandard es el que defineix l'Especie.
   */
  void llegir();
};

#endif //ESPECIE_HH
