#include <iostream>
using namespace std;

class ListaDoble
{
private:
    class Nodo
    {
    public:
        int numero;
        Nodo *siguiente, *anterior;
    };
    Nodo *lista;

public:
    ListaDoble();
    void crearLista();
    void printList();
    void addNewNodo();
};

ListaDoble::ListaDoble()
{
    lista = NULL;
}

void ListaDoble::addNewNodo()
{
    // Nodo *newNodo;
    // newNodo->numero = 10;
    // lista
    Nodo *aux, *aux1;

    aux->siguiente = new Nodo();
    aux = aux->siguiente;
    aux->anterior = aux1;
    aux1 = aux1->siguiente;
    cout << "Dame el valor del siguiente Nodo: ";
    cin >> aux->numero;
}

void ListaDoble::crearLista()
{
    Nodo *aux, *aux1;
    int sizeList;
    cout << "Dame el tama;o de la lista: ";
    cin >> sizeList;

    for (int i = 0; i < sizeList; i++)
    {
        if (lista == NULL)
        {
            lista = new Nodo();
            cout << "Dame el valor de el primer Nodo: ";
            cin >> lista->numero;
            aux = lista;
            aux1 = lista;
        }
        else
        {
            aux->siguiente = new Nodo();
            aux = aux->siguiente;
            aux->anterior = aux1;
            aux1 = aux1->siguiente;
            cout << "Dame el valor del siguiente Nodo: ";
            cin >> aux->numero;
        }
    }
}

void ListaDoble::printList()
{
    Nodo *aux;
    for (aux = lista; aux != NULL; aux = aux->siguiente)
    {
        cout << aux->numero << endl;
    }
}

int main()
{

    ListaDoble *object = new ListaDoble();
    object->crearLista();
    object->printList();
    object->addNewNodo();
    object->printList();

    return 0;
}