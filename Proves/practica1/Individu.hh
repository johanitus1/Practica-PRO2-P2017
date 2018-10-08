/** @file Individu.hh
 *  @brief Es l'arxiu que guarda la implementacio de la classe Individu.
 *  @class Individu
 *  @brief Es la classe que guarda la informacio genetica d'un individu.
 */
#ifndef INDIVIDU_HH
#define INDIVIDU_HH

#ifndef PARELL_CROMOSOMES_HH
#include "Parell_Cromosomes.hh"
#endif

#ifndef ESPECIE_HH
#include "Especie.hh"
#endif

#ifndef CROMOSOMA_HH
#include "Cromosoma.hh"
#endif

using namespace std;

class Individu{
private:

  /**  @brief
   *  sexe:   és X si és femella, i Y si és Mascle.
   */
  char sexe;

  /**  @brief
   *  cromosomes_sexuals: Son els cromosomes que donen informació de caràcter sexual.
   */
  Parell_Cromosomes cromosomes_sexuals;

  /**  @brief
   *  cromosomes_normals: Son els cromosomes que guarden la informació genètica, no sexual.
   */
  vector<Parell_Cromosomes> cromosomes_normals;


public:
  //Constructores
  /** @brief
   *  \pre cert
   *  \post S'ha creat un objecte de tipus Individu buit.
   */
  Individu();

  /** @brief
   *  \pre sexe és o bé Y o bé X
   *  \post S'ha creat un objecte de tipus Individu, amb les atributs definits per els paràmetres.
   */
  Individu(char sexe,const Parell_Cromosomes& cromosomes_sexuals,const vector<Parell_Cromosomes>& cromosomes_normals);

  //Consultores
  /** @brief
   *  \pre cert
   *  \post Dona el caràcter que correspon al sexe de l'Individu.
   */
  char consultarSexe() const;

  //i = num cromosoma, k = número del parell
  Cromosoma consultarCromosomaNormal(int i, int k) const;

  //k = 1 pre primer cromosoma (sempre tipus X), k = 2 per a l segon cromosoma (sent tipus X o Y)
  Cromosoma consultarCromosomaSexual(int k) const;

  //Entrada i Sortida
  /** @brief
   *  \pre L'individu és buit.
   *  \post L'entrada per el canal d'entrada estàndard determina les caracteristiques de l'individu.
   */
  void llegir(const Especie& especie);

  /** @brief
   *  \pre L'individu no esta buit.
   *  \post Imprimeix ordenadament les Característiques genètiques de l'individu.
   */
  void escriure() const;
};

#endif //INDIVIDU_HH
