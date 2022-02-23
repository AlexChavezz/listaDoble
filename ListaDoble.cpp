#include <iostream>
using namespace std;

class DobleLista {
    protected:
    class Nodo {
        public:
        int numero;
        Nodo* siguiente;
        Nodo* anterior;
    };
    Nodo* lista;
    public:
    DobleLista();
    void crearLista();
    void print();
    void delete();
};

DobleLista::DobleLista(){
    lista = NULL;
}

void DobleLista::crearLista(){
    Nodo* aux1,* aux2;
    int size;
    cout << "ingresa el tama;o de la lista: ";
    cin >> size;
    for ( int i = 0; i < size; i++){
        if ( lista == NULL){
            lista = new Nodo();
            cout << "Dame valor del primer elemento: "<<endl;
            cin >> lista->numero;
            aux1 = lista;
            aux2 = lista;
        }else{
            cout<<"estamos en el else"<<endl;
            aux1->siguiente = new Nodo();
			aux1 = aux1->siguiente;
			aux1->anterior = aux2;
			aux2 = aux2->siguiente;
			cout << "Dame le valor del nodo: ";
			cin >> aux1->numero;
        }
    }
}

void DobleLista::print(){
    Nodo *aux;
    for( aux = lista ; aux != NULL; aux = aux->siguiente){
        cout<<aux->numero<<endl;
    }
}


int main(){
    
    DobleLista* object = new DobleLista();
    object->crearLista();
    object->print();
    
    return 0;
}
