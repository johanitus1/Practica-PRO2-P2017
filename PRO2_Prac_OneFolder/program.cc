#include "Poblacio.hh"
#include "ArbreIO.hh"

using namespace std;

int main() {
  Poblacio poblacio;

  Especie especie;
  especie.llegir();

  int numero_inicial_individus;
  cin >> numero_inicial_individus;

  poblacio = Poblacio(especie);
  for (int i = 0; i < numero_inicial_individus; ++i) {
    string ID;
    cin >> ID;
    poblacio.llegir_individu(ID);
  }

  string accio;
  cin >> accio;
  while (accio != "acabar") {
    if (accio == "anadir_individuo") {
      cout << accio;
      string ID;
      cin >> ID;
      cout << ' ' << ID;
      poblacio.llegir_individu(ID);
      cout << endl;
    }
    else  if (accio == "reproduccion_sexual")
    {
      cout << accio;
      string m, p, n; // m de mare, p de pare, i n de nou.
      cin >> m >> p >> n;
      poblacio.reproduir(m, p, n);
      cout << endl;
    }
    else  if (accio == "escribir_arbol_genealogico")
    {
      cout << accio;
      poblacio.escriure_arbre();
    }
    else  if (accio == "completar_arbol_genealogico")
    {
      queue<string> arbre;
			ArbreIn(arbre);
			cout << "completar_arbol_genealogico " << arbre.front() << endl;
			poblacio.completar_arbre(arbre);
    }
    else  if (accio == "escribir_poblacion")
    {
      cout << accio << endl;
      poblacio.escriure_poblacio();
    }
    else  if (accio == "escribir_genotipo")
    {
      cout << accio;
      string ID;
      cin >> ID;
      poblacio.escriure_individu(ID);
    }
    cin >> accio;	//Entra la proxima accio.
  }
  cout << accio << endl;

}
