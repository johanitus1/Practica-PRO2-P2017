/** @file Parell_Cromosomes.hh
 *  @brief Es lárxiu que guarda la implementacio de la classe Parell_Cromosomes
 *  @class Parell_Cromosomes
 *  @brief Es la classe que guarda la informacio a de dos cromosomes.
 */

#ifndef PARELL_CROMOSOMES_HH
#define PARELL_CROMOSOMES_HH

#ifndef CROMOSOMA_HH
#include "Cromosoma.hh"
#endif

class Parell_Cromosomes{
private:

  /**  @brief
   *  cromosoma1: Primer cromosoma del parell.
   */
  Cromosoma cromosoma1;

  /**  @brief
   *  cromosoma2: Segon cromosoma del parell.
   */
  Cromosoma cromosoma2;


public:
  //Constructores
    /** @brief
   *  \pre cert
   *  \post crea un parell de cromosomes buit.
   */
  Parell_Cromosomes();

  /** @brief
   *  \pre l1 i l2 > 0
   *  \post crea un parell de cromosomes de longitud l1 i l2 respectivament.
   */
  Parell_Cromosomes(int l1, int l2);

  /** @brief
   *  \pre cert
   *  \post crea un parell de cromosomes amb els dos atributs.
   */
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
   *  \post Llegeix la informació dels Cromosomes
   */
  void llegir();

};

#endif //PARELL_CROMOSOMES_HH
