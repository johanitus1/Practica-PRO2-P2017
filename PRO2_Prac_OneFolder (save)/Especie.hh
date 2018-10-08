#ifndef ESPECIE_HH
#define ESPECIE_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif //NO_DIAGRAM

using namespace std;

class Especie {
private:
  int N;
  int l0;
  int lx;
  int ly;
  vector<int> l;

  /** @brief <em>Atributs<em>
   *  @brief
   *  N:  Es el nombre de parells de cromosomes normals(autosomicos) que te l'especie.
   *  @brief
   *  l0: Es el nombre de gens comuns que tenen els cromosomes sexuals.
   *  @brief
   *  lx: Es el nombre de gens que te el cromosoma X.
   *  @brief
   *  ly: Es el nombre de gens que te el cromosoma Y.
   *  @brief
   *  l:  Es un vector que a la possicio i te la informacio del cromosoma normal numero i+1.
   */

public:
  /** @brief
   *  \pre cert
   *  \post S'ha creat un objecte de tipus Especie buit.
   */
  Especie();

  //Consultores
  /** @brief
   *  \pre p.i. no es buit.
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
   *  \pre p.i. no es buit. I = i.
   *  \post Dona la longitud del cromosoma nomal (no sexual) numero I, sent I = 1 el primer, i sent I = N l'ultim. De l'Especie.
   */
  int consultar_li(int i) const;

  //Entrada
  /** @brief
   *  \pre cert
   *  \post L'entrada es el que defineix l'Especie.
   */
  void llegir();
};

#endif //ESPECIE_HH
