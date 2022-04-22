#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#include "lista_descritor.hpp"
main()
{
    setlocale(LC_ALL, "Portuguese");
    Lista *lista = new Lista();
    insere(lista, 10);
    insere(lista, 20);
    insere(lista, 30);
    insere(lista, 40);
    insere(lista, 50);
     insere(lista, 60);
     insere(lista, 70);
    cout << "\n Lista: \n";
    cout << lista;
     soma_lista(lista);
    contar_no_par(lista);
    remover(lista, 40);
    cout << "\n Lista depois remover: " << endl;
    cout << "\n Tamanho: " << lista->tamanho << endl;
    cout << lista;
    contar_no_par(lista);
    soma_lista(lista);
    soma_indice_par(lista);
    delete(lista); //executa desconstrutor
    return true;
}

