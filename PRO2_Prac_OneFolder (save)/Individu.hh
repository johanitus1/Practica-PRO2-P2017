#ifndef INDIVIDU_HH
#define INDIVIDU_HH

#include "Parell_Cromosomes.hh"

#ifndef NO_DIAGRAM
#include <map>
#include "PRO2Excepcio.hh"
#endif //NO_DIAGRAM

using namespace std;

class Individu{
private:
  char sexe;
  Parell_Cromosomes cromosomes_sexuals;
  vector<Parell_Cromosomes> cromosomes_normals;

  /** @brief <em>Atributs<em>
   *  @brief
   *  sexe:   es X si es femella, i Y si es Mascle.
   *  @brief
   *  @brief
   *  cromosomes_sexuals: Son els cromosomes que donen informacio de caracter sexual.
   *  @brief
   *  cromosomes_normals: Son els cromosomes que guarden la informacio genetica, no sexual.
   */

public:
  //Constructores
  /** @brief
   *  \pre cert
   *  \post S'ha creat un objecte de tipus Individu buit.
   */
  Individu();

  /** @brief
   *  \pre mare i pare es poden reproduir.
   *  \post S'ha creat un objecte de tipus Individu, amb les atributs definits per els parametres.
   */
  Individu(char sexe,const Parell_Cromosomes& cromosomes_sexuals,const vector<Parell_Cromosomes>& cromosomes_normals);

  //Consultores
  /** @brief
   *  \pre cert
   *  \post dona el caracter que correspon al sexe de l'Individu.
   */
  char consultar_sexe() const;

  //i = num cromosoma, k = numero del parell
  Cromosoma consultar_cromosoma_normal(int i, int k) const;

  //k = 1 pre primer cromosoma (sempre tipus X), k = 2 per a l segon cromosoma (siguent tipus X o Y)
  Cromosoma consultar_cromosoma_sexual(int k) const;

  //Entrada i Sortida
  /** @brief
   *  \pre L'individu esta buit.
   *  \post La entrada per teclat determina les caracteristiques de lindividu.
   */
  void llegir_individu(const Especie& especie);

  /** @brief
   *  \pre L'individu no esta buit.
   *  \post Imprimeix ordenadament les caracteristique genetiques de l'individu.
   */
  void escriure_genotip() const;
};

#endif //INDIVIDU_HH
