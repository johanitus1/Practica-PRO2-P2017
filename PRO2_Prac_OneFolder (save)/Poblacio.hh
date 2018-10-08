#ifndef POBLACIO_HH
#define POBLACIO_HH

#include "Individu.hh"

#ifndef NO_DIAGRAM
#include <queue>
#endif //NO_DIAGRAM

using namespace std;

class Poblacio{
private:


  struct info_individu {
        Individu esser;
        map<string, info_individu>::iterator pare, mare;
  };


  typedef map<string, info_individu>::iterator map_iterator;
  typedef map<string, info_individu>::const_iterator const_map_iterator;

  Especie especie;
  map<string, info_individu> poblacio;

    /** @brief <em>Atributs<em>
     *  @brief
     *  especie:  es la descripcio de la biologia de l'individu
     *  @brief
     *  poblacio: es un conjunt (tipus map) ordenat de Individus localitzats per ID(un string).
     */

public:
  //Constructores
  /** @brief
   *  \pre cert
   *  \post S'ha creat un objecte poblacio buit.
   */
  Poblacio();


  /** @brief
   *  \pre E = especie
   *  \post S'ha creat un objecte poblacio, que te coma a especie E. La poblacio inicial es llegeix, i te poblacio_inicial individus.
   */
  Poblacio(const Especie& especie);

  //Consultores
  /** @brief
   *  \pre id = ID(parametre)
   *  \post Es retorna el iterador que resulta de la busqueda de id en el map poblacio.
   */
  map_iterator buscar(string ID) ;

  /**
   *  \pre
   *  \post
   */
  void reproduir(string mare, string pare, string ID);


  //Entrada i Sortida
  /** @brief
   *  \pre i > 0
   *  \post Ha llegit i afegit un individu a la poblacio.
   */
  void llegir_individu(string ID);

  /** @brief
   *  \pre cert
   *  \post Escriu per pantalla tota la poblacio, per ordre alfabetic sobre l'ID, de cada individu imprimeix: ID, sexe, ID pare, ID mare.
   */
  void escriure_poblacio() const;

  /** @brief
   *  \pre id = ID(parametre)
   *  \post Si troba l'Individu amb ID id, en mostra el genotip.
   */
  void escriure_individu(string ID);

  /** @brief
   *  \pre id = ID(parametre)
   *  \post Si troba l'Individu amb ID id, en mostra el l'arbre genealogic.
   */
  void escriure_arbre();

  //--------------------------------------
  /** @brief
   *  \pre cert
   *  \post Es llegeix un arbre i si es pot s'imprimeix el complert.
   */
  void completar_arbre() ;

private:
  //Modificadores
  void afegir_individu(string ID, const Individu& individu, map_iterator pare, map_iterator mare) {
    /** @brief
     *  \pre id = ID(parametre), pare = mare = "" per indicar que no te pares.
     *  \post Si no existia cap individu amb ID id s'ha afegit l'individu sino mostra un error.
     */
    if (poblacio.find(ID) == poblacio.end()) {
        info_individu nou;
        nou.esser = individu;
        nou.pare = pare;
        nou.mare = mare;
        poblacio[ID] = nou;
    }
    else {
        cout << endl << "  error";
    }
  }


  // Consultora
  bool es_antesesor(const map_iterator& tar, const map_iterator& ant_p) {
        if (ant_p == poblacio.end()) return false;
        else if (ant_p == tar) return true;
        else return es_antesesor(tar, ant_p -> second.mare) or es_antesesor(tar, ant_p -> second.pare);
  }
  
  
  bool posible_reproduccio(map_iterator mare, map_iterator pare) {
    /** @brief
     *  \pre cert
     *  \post si el segon element que conte cada parell d'iteradors es pot reproduir amb l'altre cert, altrement fals.
     */
    if (mare -> second.esser.consultar_sexe() != 'X') {return false;}
    if (pare -> second.esser.consultar_sexe() != 'Y') {return false;}
    if ((mare -> second.pare)==(pare -> second.pare) and
        (mare -> second.pare) != poblacio.end()) {return false;}

    if ((mare -> second.mare)==(pare -> second.mare) and
        (mare -> second.mare) != poblacio.end()) {return false;}
    if (es_antesesor(mare, pare)) return false;
    if (es_antesesor(pare, mare)) return false;
    return true;
  }

  Parell_Cromosomes creua_cromosomes_normals(const Cromosoma& cm, const Cromosoma& cp, int t, int i) {
    Cromosoma c1 = Cromosoma(especie.consultar_li(i));
    Cromosoma c2 = Cromosoma(especie.consultar_li(i));
    for (int j = 0; j < t and j < especie.consultar_li(i); ++j) {
      c1.modificar_gen(j, cm.consultar_gen(j));
      c2.modificar_gen(j, cp.consultar_gen(j));
    }
    for (int j = t; j < especie.consultar_li(i); ++j) {
      c2.modificar_gen(j, cm.consultar_gen(j));
      c1.modificar_gen(j, cp.consultar_gen(j));
    }
    return Parell_Cromosomes(c1, c2);
  }

  Parell_Cromosomes creua_cromosomes_sexuals(const Cromosoma& cm, const Cromosoma& cp, int t, char sexe) {
    Cromosoma c1 = Cromosoma(especie.consultar_lx());
    Cromosoma c2;

    int l0, lx, ly;
    l0 = especie.consultar_l0();
    lx = especie.consultar_lx();
    ly = especie.consultar_ly();
    --t;
    if (sexe == 'Y') {
      c2 = Cromosoma(especie.consultar_ly());
      for (int i = 0; i < lx; ++i) {
        if (i > t and i < l0 and i < ly)
          c1.modificar_gen(i, cp.consultar_gen(i));
        else
          c1.modificar_gen(i, cm.consultar_gen(i));
      }

      for (int i = 0; i < ly; ++i) {
        if (i > t and i < l0 and i < lx)
          c2.modificar_gen(i, cm.consultar_gen(i));
        else
          c2.modificar_gen(i, cp.consultar_gen(i));
      }

    }
    else {
      c2 = Cromosoma(especie.consultar_lx());
      for (int i = 0; i < lx; ++i) {
        if (i > t and i < l0-1) {
          c2.modificar_gen(i, cm.consultar_gen(i));
          c1.modificar_gen(i, cp.consultar_gen(i));
        }
        else
        {
          c1.modificar_gen(i, cm.consultar_gen(i));
          c2.modificar_gen(i, cp.consultar_gen(i));
        }
      }
    }

    return Parell_Cromosomes(c1, c2);
  }
  
  void completar_arbre(map_iterator arrel, queue<string>& otp) {
      if (arrel == poblacio.end()) otp.push("$");
      else {
        otp.push("*" + (arrel -> first) + "*");
        completar_arbre(arrel -> second.pare, otp);
        completar_arbre(arrel -> second.mare, otp);
      }
      
  }

  bool input_and_completar_arbre(map_iterator arrel, queue<string>& otp) {
      string pares;
      map_iterator p;
      bool valid = true;
      
      cin >> pares;
      p = arrel -> second.pare;
      if (pares == "$") {
          completar_arbre(p, otp);
      }else {
          if (pares != p -> first) valid = false;
          else {
              otp.push(pares);
              valid = input_and_completar_arbre(p , otp);
          }
      }
      
      cin >> pares;
      p = arrel -> second.mare;
      if (pares == "$") {
          completar_arbre(p, otp);
      }else {
          if (pares != p -> first) valid = false;
          else {
              otp.push(pares);
              valid = input_and_completar_arbre(p, otp);
          }
      }
      return valid;    
  }

};

#endif //POBLACIO_HH
