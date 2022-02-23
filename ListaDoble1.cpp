#include <iostream>
using namespace std;

class cDobleLista {

public:
	int numero;
	cDobleLista();
	cDobleLista* sig, * ant;
	cDobleLista* crearLista();
	cDobleLista* eliminarNodo(cDobleLista*);
	cDobleLista* crearNodo(cDobleLista*);
	void imprimirListaDobleSiguiente(cDobleLista*);
	void imprimirListaDobleAnterior(cDobleLista*);
};

cDobleLista::cDobleLista() {
	numero = 0;
	sig = ant = NULL;
}

cDobleLista* cDobleLista::crearLista() {
	cDobleLista* lista = NULL, * aux = NULL, * aux1 = NULL;
	int listaSize;

	cout << "Ingresa el tamaño de la lista: ";
	cin >> listaSize;

	for (int i = 0; i < listaSize; i++) {
		if (lista == NULL) {
			lista = new cDobleLista();
			cout << "dame el valor del primer nodo [ " << i << " ]: ";
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

cDobleLista* cDobleLista::eliminarNodo(cDobleLista* l) {
	cDobleLista* aux = l, * aux1;
	int position;
	cout << "Que posicion deseas eliminar" << endl;
	cin >> position;
	if (position == 1) {
		aux = aux->sig;
		aux->ant = NULL;
		l->sig = NULL;
		l = aux;
	}
	else {
		for (int i = 0; i < position - 2; i++)
		{
			aux = aux->sig;
		}
		aux1 = aux->sig->sig;
		aux->sig->sig = NULL;
		aux1->ant->ant = NULL;
		aux->sig = aux1;
		aux1->ant = aux;
	}
	return l;
}
void cDobleLista::imprimirListaDobleSiguiente(cDobleLista* l) {
	cDobleLista* aux;
	cout << "Imprimiendo en de adelante a atras" << endl;
	for (aux = l; aux != NULL; aux = aux->sig) {
		cout << aux->numero << endl;
	}
}

void cDobleLista::imprimirListaDobleAnterior(cDobleLista* l) {
	cDobleLista* aux = l;
	while (aux->sig != NULL) {
		aux = aux->sig;
	}
	cout << "Imprimiendo al de atras a delante" << endl;
	while (aux != NULL) {
		cout << aux->numero << endl;
		aux = aux->ant;
	}
}

cDobleLista* cDobleLista::crearNodo(cDobleLista* lista) {
	cDobleLista* newNodo = new cDobleLista();
	cout << "Valor del nuevo nodo: ";
	cin >> newNodo->numero;
	newNodo->ant = NULL;
	newNodo->sig = NULL;

	if (lista == NULL) {
		lista = newNodo;
	}else{
		lista->ant = newNodo;
		newNodo->sig = lista;
	}
	lista = newNodo;
	return lista;
}

int main() {
	int res = 1;
	cDobleLista* lista = new cDobleLista();
	cDobleLista* recuperarLista = lista->crearLista();
	lista->imprimirListaDobleSiguiente(recuperarLista);
	lista->imprimirListaDobleAnterior(recuperarLista);
	do {
		cout << "Deseas eliminar algun Nodo" << endl;
		cout << "(0) Para Nuevo Nodo" << endl;
		cout << "(1) Para si" << endl;
		cout << "(2) Para no" << endl;
		cout << ": ";
		cin >> res;
		if (res == 1) {
			recuperarLista = lista->eliminarNodo(recuperarLista);
			lista->imprimirListaDobleSiguiente(recuperarLista);
			lista->imprimirListaDobleAnterior(recuperarLista);
		}
		if (res == 0) {
			recuperarLista = lista->crearNodo(recuperarLista);
			lista->imprimirListaDobleAnterior(recuperarLista);
			lista->imprimirListaDobleSiguiente(recuperarLista);
		}
	} while (res == 1 or res == 0);
	return 0;
}
// Tarea Agregar nodos en listas dobles
