#ifndef PARELL_CROMOSOMES_HH
#define PARELL_CROMOSOMES_HH

#include "Cromosoma.hh"

class Parell_Cromosomes{
private:
  Cromosoma cromosoma1;
  Cromosoma cromosoma2;

  /** @brief <em>Atributs<em>
   *  @brief
   *  cromosoma1: Primer cromosoma del parell.
   *  @brief
   *  cromosoma2: Segon cromosoma del parell.
   */

public:
  //Constructores
    /** @brief
   *  \pre cert
   *  \post crea un parell de cromosomes buit.
   */
  Parell_Cromosomes();

  /** @brief
   *  \pre 0 < i < = N, N es el nombre de cromosomes normals.
   *  \post crea un parell de cromosomes de longitud li.
   */
  Parell_Cromosomes(int i, const Especie& especie);

  /** @brief
   *  \pre sexe = 'X' o 'Y'
   *  \post crea un parell de cromosomes sexuals el primer de mida lx i el segon de mida lx o ly en funcio de sexe;
   */
  Parell_Cromosomes(char sexe, const Especie& especie);

  Parell_Cromosomes(const Cromosoma& c1, const Cromosoma& c2);

  //Consultores
  /** @brief
   *  \pre cert
   *  \post Dona el primer Cromosoma del parell.
   */
  Cromosoma consultar_c1() const;

  /** @brief
   *  \pre
   *  \post Dona el segon Cromosoma del parell.
   */
  Cromosoma consultar_c2() const;

  //Entrada i Sortida
  /** @brief
   *  \pre cert
   *  \post Llegeix la informacio del Cromosoma
   */
  void llegir();

};

#endif //PARELL_CROMOSOMES_HH
