/** @file Poblacio.hh
 *  @brief Arxiu de la classe poblacio.
 * @class Poblacio
 * @brief Classe poblacio que conte els individus i les funcions nessesaries per les accions principals del programa.
 */

#ifndef POBLACIO_HH
#define POBLACIO_HH

#ifndef INDIVIDU_HH
#include "Individu.hh"
#endif

#ifndef ESPECIE_HH
#include "Especie.hh"
#endif

#ifndef PARELL_CROMOSOMES_HH
#include "Parell_Cromosomes.hh"
#endif

#ifndef CROMOSOMA_HH
#include "Cromosoma.hh"
#endif

#ifndef NO_DIAGRAM
#include <queue>
#include <map>
#endif //NO_DIAGRAM

using namespace std;
class Poblacio{
private:
  /** @struct info_individu
   *  @brief Es la estroctura de dades que quarda la informacio de cada individu.
   */
  struct info_individu {
    /** @brief
     *  Es la classe que guarda la informacio genetica de l'individu.
     */
    Individu individu;

    /** @brief
     *  Es els iterador que apunta al pare dins la poblacio.
     */
    map<string, info_individu>::iterator pare;

    /** @brief
     *  Es els iterador que apunta a la mare dins la poblacio.
     */
    map<string, info_individu>::iterator mare;

  };
  /** @brief definicio de tipus per fer mes facil d'entendre el codi. */
  typedef map<string, info_individu>::iterator map_iterator;

  /** @brief definicio de tipus per fer mes facil d'entendre el codi. */
  typedef map<string, info_individu>::const_iterator const_map_iterator;

  /**  @brief
   *  població: és un conjunt (tipus map) ordenat d'Individus localitzats per ID(un string).
   */
  map<string, info_individu> poblacio;


public:
  //Constructores
  /** @brief
   *  \pre cert
   *  \post S'ha creat un objecte població buit.
   */
  Poblacio();

  //Entrada i Sortida
  /** @brief
   *  \pre cert
   *  \post Ha llegit i afegit un individu a la població, amb nom ID si no existia.
   */
  void llegirIndividu(string ID, const Especie& especie);

	/** @brief
	   *  \pre cert
   *  \post Si troba l'Individu amb nom ID, en mostra l'arbre genealògic per nivells.
   */
  void escriureArbre(string ID);

  /** @brief
   *  \pre cert
   *  \post Escriu per el canal estàndard de sortida tota la població, per ordre alfabètic sobre l'ID (de cada individu imprimeix: ID, sexe, ID pare, ID mare).
   */
  void escriure() const;

  /** @brief
	 *  \pre	cert
   *  \post Si troba l'Individu amb nom ID, en mostra el genotip.
   */
  void escriureGenotip(string ID);

  //Accions
	/** @brief
	 *  \pre	cert
	 *  \post	Si és possible i el format correcte s'ha afegit un nou individu a la població per reproducció sexual dels individus amb ID mare i pare.
	 */
	void reproduir(string mare, string pare, string ID, int l0, int N);

  /** @brief
   *  \pre	arbre és un arbre de noms en pre-ordre.
   *  \post Si l'arbre coincideix amb l'estructura de l'arbre genealògic d'algun individu de la població, es completa l'arbre. Arbre és ara el complet.
   */
  void completaArbre(queue<string>& arbre);

private:
	//Modificadores
	/** @brief
     *  \pre cert
	 *  \post Si no existia cap individu amb nom ID s'ha afegit l'individu sinó mostra un error.
	 */
  void afegirIndividu(string ID, const Individu& ind, map_iterator p, map_iterator m) {
    if (poblacio.find(ID) == poblacio.end()) {  // Si el map no troba l'individu l'afegeix a la poblacio.
        info_individu nou;
        nou.individu = ind;
        nou.pare = p;
        nou.mare = m;
        poblacio[ID] = nou;
    }
    else cout << "  error" << endl;             // Altrement escriu error per el canal estandard de sortida.

  }

	// Consultora
  /** @brief
   *	\pre tar != poblacio.end()
   *	\post Si ant_p és antecessor de tar resulta cert, altrament fals.
   */
  bool esAntecessor(const map_iterator& tar, const map_iterator& ant_p) { // tar = target i ant_p = antecessor en potència
    if (ant_p == poblacio.end()) return false;
    else if (ant_p == tar) return true;
    else return esAntecessor(tar, ant_p -> second.mare) or esAntecessor(tar, ant_p -> second.pare);
  }


  bool posible_reproduccio(map_iterator mare, map_iterator pare) {
    /** @brief
     *  \pre cert
     */
     if (
         (mare -> second.individu.consultarSexe() != 'X') or   // Comprobem que la mare sigui del sexe femeni
         (pare -> second.individu.consultarSexe() != 'Y') or   // Comprobem que el pare sigui de sexe masculi
         (
          (
           (mare -> second.pare)==(pare -> second.pare)   or   // Comprobem que no siguin germans de part de pare.
           (mare -> second.mare)==(pare -> second.mare)        // Comprobem que no siguin germans de part de mare.
          ) and
          (mare -> second.pare) != poblacio.end()              // Si tenen pares.
         )                                                or
         (esAntecessor(pare, mare))                       or   // Comprobar que mare no es antessesor de pare.
         (esAntecessor(mare, pare))                            // Comprobar que pare no es antessesor de mare
        )return false;                                         // Si una de les condicions anteriors es certa vol dir que no es poden reproduir.
     return true;                                              // Altrement si que poden.
		/** @brief
		 *  \post si el segon element que compta cada parell d'iteradors és pot reproduir amb l'altre serà cert, altrament fals.
		 */
  }

	//Accions
  /** @brief
   *  \pre  cm es un cromosoma de la mare, i cp es un cromosoma del pare. t >= 0
   *  \post Resulta un Parell_Cromosomes creuant els cromosomes de la mare amb els del pare.
   */
	Parell_Cromosomes creuaCromosomesNormals(const Cromosoma& cm, const Cromosoma& cp, int t) {
    int li = cm.mida();
    Cromosoma c1 = cm;
    Cromosoma c2 = cp;

    //Girem tots els gens despres del tall fins a li
    for (int i = t+1; i <= li; ++i) {
      c2.modificar_gen(i, cm.consultar_gen(i));
      c1.modificar_gen(i, cp.consultar_gen(i));
    }
    return Parell_Cromosomes(c1, c2);
  }


  /** @brief
   *  \pre  cm es un cromosoma de la mare, i cp es un cromosoma del pare. t >= 0
   *  \post Resulta un Parell_Cromosomes creuant els cromosomes (els gens no comuns) de la mare amb els del pare,
   */
  Parell_Cromosomes creuaCromosomesSexuals(const Cromosoma& cm, const Cromosoma& cp, int t, int l0) {
    int l1 = cm.mida();
    int l2 = cp.mida();
    int lmin = l1 < l0 ? l1 : l0;
    Cromosoma c1 = cm;
    Cromosoma c2 = cp;

    if (l1 != l2) {
      //Girem tots els gens despres del tall fins a min(l1, l2, l0)
      if (l2 < lmin) lmin = l2;
      for (int i = t+1; i <= lmin and i <= l0; ++i) {
        c1.modificar_gen(i, cp.consultar_gen(i));
        c2.modificar_gen(i, cm.consultar_gen(i));
      }
    }
    else {
      //Girem tots els gens despres del tall fins a min(l1, l0)
      for (int i = t+1; i <= lmin; ++i) {
        c2.modificar_gen(i, cm.consultar_gen(i));
        c1.modificar_gen(i, cp.consultar_gen(i));
      }
    }
    return Parell_Cromosomes(c1, c2);
  }

  /** @brief
   *  \pre  arrel es l'iterador de l'arrel de l'arbre. otp es la cua de sortida.
   *  \post afegeix l'arbre genealogic de l'arrel a la cua de sortida. (marca els nodes entre *)
   */
  void completa_arbre(map_iterator arrel, queue<string>& otp) {
    // Cas no recorsiu. Quan accedim al fill d'una fulla.
    // Carreguem a la cua de sortida el caracter $ per definició.
    if (arrel == poblacio.end()) otp.push("$");
    else {
      // PRE-ORDRE
      otp.push("*" + (arrel -> first) + "*");    // Carreguem la arrel a la cua de sortida marcant els noms que no eren a l'arbre inicialment entre *.
      completa_arbre(arrel -> second.pare, otp); // I completem l'arbre del pare.
      completa_arbre(arrel -> second.mare, otp); // I despres el de la mare.
    }
  }

  /** @brief
   *  \pre  arrel es l'iterador de l'arrel de l'arbre. otp es la cua de sortida. arbre es la cua d'entrada.
   *  \post retorna true si s'ha pogut completar l'arbre (i false altrement). Si resulta true a otp hi ha la sortida de l'arbre genealogic de arrel complet.
   */
  bool input_and_completa_arbre(map_iterator arrel, queue<string>& otp, queue<string>& arbre) {
    string pares;
    map_iterator p;
    bool valid = true;

    // Comprobem l'arbre del pare en funcio de la cua d'entrada.
    pares = arbre.front();
    arbre.pop();
    p = arrel -> second.pare;
    if (pares == "$") {
      completa_arbre(p, otp);
    }else {
      if (poblacio.find(pares) != p) {
        valid = false;
      }
      else {
          otp.push(pares);
          valid = input_and_completa_arbre(p , otp, arbre);
        }
      }

      // Comprobem l'arbre de la mare en funcio de l'entrada.
      pares = arbre.front();
      arbre.pop();
      p = arrel -> second.mare;
      if (pares == "$") {
        completa_arbre(p, otp);
      }else {
        if (poblacio.find(pares) != p) valid = false;
        else {
          otp.push(pares);
          valid = input_and_completa_arbre(p, otp, arbre);
        }
      }
      return valid;
  }
};

#endif //POBLACIO_HH
