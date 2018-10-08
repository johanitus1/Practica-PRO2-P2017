/** @file Poblacio.cc
 *  @brief Aquesta es la especieifcacio de la classe Poblacio.
 */

#include "Poblacio.hh"

Poblacio::Poblacio()
{
}

//Entrada i Sortida
void Poblacio::llegirIndividu(string ID, const Especie& especie)
{
	Individu nou;
	nou.llegir(especie);
	afegirIndividu(ID, nou, poblacio.end(), poblacio.end());
}

void Poblacio::escriureArbre(string ID)
{
	queue<map_iterator> nivell;
	nivell.push(poblacio.find(ID));

	if (nivell.front() != poblacio.end())
	{
		nivell.push(poblacio.end());
		int nivell_act = 0;
		cout << "  Nivel 0:";
		while(not nivell.empty())
		{
			if (nivell.front() != poblacio.end())
			{
				map_iterator act = nivell.front();
				cout << ' ' << act -> first;
				if (act -> second.pare != poblacio.end()) {
					nivell.push(act -> second.pare);
          nivell.push(act -> second.mare);
				}
				nivell.pop();
			}
			else
			{
				nivell.pop();
				if (not nivell.empty()){
          cout << endl;
          cout << "  Nivel " << ++nivell_act << ":";
          nivell.push(poblacio.end());
        }
			}
		}
		cout << endl;
	}
	else cout << "  error" << endl;
}

void Poblacio::escriure() const
{
	const_map_iterator act = poblacio.begin();
  while(act != poblacio.end()) {
    cout << "  " << act -> first << " ";
    cout << 'X' << act -> second.individu.consultarSexe() << ' ';
    if (act -> second.pare == poblacio.end()) cout << "($,$)" << endl;
    else {
      cout << '('<< act -> second.pare -> first << ',';
      cout << act -> second.mare -> first << ')' << endl;
    }
    act++;
  }
}

void Poblacio::escriureGenotip(string ID)
{
	if (poblacio.find(ID) == poblacio.end())
		cout << "  error" << endl;
	else
		poblacio[ID].individu.escriure();
}

//Accions
void Poblacio::reproduir(string mare, string pare, string ID, int l0, int N)
{
	map_iterator mare_it = poblacio.find(mare);
	map_iterator pare_it = poblacio.find(pare);

	struct {
		string bin;
		void consumeix(int trash_stack) {
			while (trash_stack > 0){
				cin >> bin;
				--trash_stack;
			}
		}
	}trash_bin;

	if
		(
			poblacio.find(ID) != poblacio.end() or
			mare_it == poblacio.end() or
			pare_it == poblacio.end()
		)
		{
			cout << "  error" << endl;
			trash_bin.consumeix((N+1)*3);
		}
	else
		{
			if (posible_reproduccio(mare_it, pare_it))
			{
				int nm, np, t; // nm = numero mare, np = numero pare, t = tall (numero del parell)
				Individu mare = mare_it -> second.individu;
				Individu pare = pare_it -> second.individu;
				Cromosoma cm, cp;
				char sexe;
				Parell_Cromosomes c_s;
				vector<Parell_Cromosomes> c_n(N);

				cin >> nm >> np >> t;
				sexe = (np == 1) ? 'Y' : 'X';
				cm = mare.consultarCromosomaSexual(nm);
      	cp = pare.consultarCromosomaSexual(np);
				c_s = creuaCromosomesSexuals(cm, cp, t, l0);

				for (int i = 1; i <= N; ++i)
      	{
        	cin >> nm >> np >> t;
        	cm = mare.consultarCromosomaNormal(i, nm);
        	cp = pare.consultarCromosomaNormal(i, np);
        	c_n[i-1] = creuaCromosomesNormals(cm, cp, t);
      	}

				Individu nou(sexe, c_s, c_n);
				afegirIndividu(ID, nou, pare_it, mare_it);
			}
			else
			{
				cout << "  no es posible reproduccion" << endl;
				trash_bin.consumeix((N+1)*3);
			}
		}
}

void Poblacio::completaArbre(queue<string>& arbre)
{
	queue<string> otp;

	otp.push(arbre.front());
	map_iterator arrel = poblacio.find(arbre.front());
	arbre.pop();
	if (arrel != poblacio.end() and input_and_completa_arbre(arrel, otp, arbre)) {
		cout << ' ';
		while (not otp.empty()) {
			cout << ' ' << otp.front();
			otp.pop();
		}
		cout << endl;
	}else cout << "  no es arbol parcial" << endl;
}
