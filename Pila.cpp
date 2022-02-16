#include <iostream>
using namespace std;

class cDobleLista {

public:
	int numero;
	cDobleLista();
	cDobleLista* sig, * ant;
	cDobleLista* crearLista();
	void imprimirListaDobleSiguiente(cDobleLista*);
	void imprimirListaDobleAnterior(cDobleLista*);
};

cDobleLista::cDobleLista() {
	numero = 0;
	sig = ant = NULL;
}

cDobleLista* cDobleLista::crearLista() {
	cDobleLista* lista = NULL, *aux = NULL, *aux1 = NULL;
	int listaSize;

	cout << "Ingresa el tamaño de la lista: ";
	cin >> listaSize;

	for (int i = 0; i < listaSize; i++) {
		if (lista == NULL) {
			lista = new cDobleLista();
			cout << "dame el valor del primer nodo [ "<<i<<" ]: ";
			cin >> lista->numero;
			aux = lista;
			aux1 = lista;
		}
		else
		{
			aux->sig = new cDobleLista();
			aux = aux->sig;
			aux->ant = aux1;
			aux1 = aux1->sig;
			cout << "dame le valor del nodo: ";
			cin >> aux->numero;
		}
	}

	return lista;
}

void cDobleLista::imprimirListaDobleSiguiente(cDobleLista *l) {
	cDobleLista* aux;
	for (aux = l; aux != NULL; aux = aux->sig) {
		cout << aux->numero << endl;
	}
}

void cDobleLista::imprimirListaDobleAnterior(cDobleLista *l) {
	cDobleLista* aux = l;
	while (aux->sig != NULL) {
		aux = aux->sig;
	}
	while (aux != NULL) {
		cout << aux->numero;
		aux = aux->ant;
	}
}

int main() {

	cDobleLista* lista = new cDobleLista();
	cDobleLista* recuperarLista = lista->crearLista();
	lista->imprimirListaDobleSiguiente(recuperarLista);
	lista->imprimirListaDobleAnterior(recuperarLista);
	return 0;
}
// Tarea Agregar nodos en listas dobles