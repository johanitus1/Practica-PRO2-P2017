

#ifndef NO_DIAGRAM
#include <iostream>
#include <queue>
#endif //NO_DIAGRAM

using namespace std;

/** @brief
 *	\pre	arbre es una cua buida.
 *	\post	S'ha guardat l'arbre en pre-ordre que es disposava en el canal d'entrada estandard, en forma de qua.
 */
void ArbreIn(queue<string>& arbre){
	string arrel;
	cin >> arrel;
	arbre.push(arrel);
	if (arrel != "$") {
		ArbreIn(arbre);
		ArbreIn(arbre);
	}
}

/** @brief
 *	\pre	arbre es un arbre disposat en forma de qua en pre-ordre.
 *	\post S'ha impres l'arbre en pre-ordre per el canal de sortida estandar. arbre es buit.
 */
void ArbreOut(queue<string>& arbre){
	while (not arbre.empty()) {
		cout << " " << arbre.front();
		arbre.pop();
	}
	cout << endl;
}
