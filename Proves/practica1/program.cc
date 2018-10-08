/** @file program.cc
 *  @brief Es lárxiu on hi ha la funcio main del programa.
 */

#include "Poblacio.hh"
#include "ArbreIO.hh"

using namespace std;

int main()
{
	Especie especie;
	especie.llegir();

	int poblacio_inicial;
	cin >> poblacio_inicial;

	Poblacio poblacio;
	for (int i = 0; i < poblacio_inicial; ++i) {
		string nou;
		cin >> nou;
		poblacio.llegirIndividu(nou, especie);
	}

	string accio;
	do {
		cin >> accio;
		if (accio == "anadir_individuo")
		{
			string nou;
			cin >> nou;
			cout << "anadir_individuo " << nou << endl;
			poblacio.llegirIndividu(nou, especie);
		}
		else  if (accio == "reproduccion_sexual")
		{
			string mare, pare, nou;
			cin >> mare >> pare >> nou;
			cout << ("reproduccion_sexual " + mare + " " + pare + " " + nou) << endl;
			poblacio.reproduir(mare, pare, nou, especie.consultar_l0(), especie.consultar_N());
		}
		else  if (accio == "escribir_arbol_genealogico")
		{
			string ID;
			cin >> ID;
			cout << "escribir_arbol_genealogico " << ID << endl;
			poblacio.escriureArbre(ID);
		}
		else  if (accio == "completar_arbol_genealogico")
		{
			queue<string> arbre;
			ArbreIn(arbre);
			cout << "completar_arbol_genealogico " << arbre.front() << endl;
			poblacio.completaArbre(arbre);
		}
		else  if (accio == "escribir_poblacion")
		{
			cout << "escribir_poblacion" << endl;
			poblacio.escriure();
		}
		else  if (accio == "escribir_genotipo")
		{
			string ID;
			cin >> ID;
			cout << "escribir_genotipo " << ID << endl;
			poblacio.escriureGenotip(ID);
		}

	}while (accio != "acabar");
	cout << "acabar" << endl;
}
