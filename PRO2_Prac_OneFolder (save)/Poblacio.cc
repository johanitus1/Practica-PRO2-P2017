/** @file Poblacio.cc
    @brief Código de la clase Poblacio
*/

#include "Poblacio.hh"

Poblacio::Poblacio() {

}

Poblacio::Poblacio(const Especie& especie){
    this -> especie = especie;
}

Poblacio::map_iterator Poblacio::buscar(string ID) {
  map_iterator individu;
  individu = poblacio.find(ID);
  return individu;
}

void Poblacio::reproduir(string mare, string pare, string ID){
  cout << ' ' << mare << ' ' << pare << ' ' << ID;
  map_iterator mare_it = poblacio.find(mare);
  map_iterator pare_it = poblacio.find(pare);
  if ((mare_it != poblacio.end() and pare_it != poblacio.end()) and poblacio.find(ID) == poblacio.end()) {
    if (posible_reproduccio(mare_it, pare_it)) {
      int m, p, t;
      char sexe;
      Individu mare = mare_it -> second.esser;
      Individu pare = pare_it -> second.esser;
      Parell_Cromosomes c_s;
      vector<Parell_Cromosomes> c_n(especie.consultar_N());

      Cromosoma cm;
      Cromosoma cp;
      Cromosoma c1;
      Cromosoma c2;

      cin >> m >> p >> t;
      if (p == 1) sexe = 'Y';
      else sexe = 'X';
      cm = mare.consultar_cromosoma_sexual(m);
      cp = pare.consultar_cromosoma_sexual(p);
      c_s = creua_cromosomes_sexuals(cm, cp, t, sexe);

      //cout << endl;
      for (int i = 0; i < especie.consultar_N(); ++i)
      {
        cin >> m >> p >> t;
        cm = mare.consultar_cromosoma_normal(i, m);
        cp = pare.consultar_cromosoma_normal(i, p);
        c_n[i] = creua_cromosomes_normals(cm, cp, t, i);
      }

      Individu nou(sexe, c_s, c_n);
      afegir_individu(ID, nou, pare_it, mare_it);
    } else cout << endl << "  no es posible reproduccion";
  }else cout << endl << "  error"; // Consumir dades.
}


void Poblacio::llegir_individu(string ID) {
  Individu nou;
  nou.llegir_individu(especie);
  afegir_individu(ID, nou, poblacio.end(), poblacio.end());
}

void Poblacio::escriure_poblacio() const{
  const_map_iterator act = poblacio.begin();
  while(act != poblacio.end()) {
    cout << "  " << act -> first << " ";
    cout << 'X' << act -> second.esser.consultar_sexe() << ' ';
    if (act -> second.pare == poblacio.end()) cout << "($,$)" << endl;
    else {
      cout << '('<< act -> second.pare -> first << ',';
      cout << act -> second.mare -> first << ')' << endl;
    }
    act++;
  }
}

void Poblacio::escriure_individu(string ID) {
  cout << " " << ID << endl;
  if (poblacio.find(ID) != poblacio.end())poblacio[ID].esser.escriure_genotip();
  else cout << "  error" << endl;
}

void Poblacio::escriure_arbre() {
  string ID;
  cin >> ID;
  cout << ' ' << ID << endl;
  queue<map_iterator> pares;
  pares.push(poblacio.find(ID));
  if (pares.front() != poblacio.end()) {
    pares.push(poblacio.end());
    int n = 0;
    cout << "  Nivel 0:";
    while(not pares.empty()) {
      if (pares.front() != poblacio.end()){
        map_iterator act = pares.front();
        cout << ' ' << act -> first;
        if (act -> second.pare != poblacio.end()) {
          pares.push(act -> second.pare);
          pares.push(act -> second.mare);
        }
        pares.pop();
      }
      else {
        pares.pop();
        if (not pares.empty()){
          cout << endl;
          cout << "  Nivel " << ++n << ":";
          pares.push(poblacio.end());
        }

      }
    }
    cout << endl;
  }
  else cout << "  error" << endl;
}

void Poblacio::completar_arbre() {
  queue<string> otp;
  string ID;
  cin >> ID;
  otp.push(ID);
  map_iterator arrel = poblacio.find(ID);
  cout << ' ' << otp.front() << endl << ' ';
  if (arrel != poblacio.end() and input_and_completar_arbre(arrel, otp)) {
    while (not otp.empty()) {
          cout << ' ' << otp.front();
          otp.pop();
    }   
    cout << endl;
  }else cout << " no es arbol parcial" << endl;
}
