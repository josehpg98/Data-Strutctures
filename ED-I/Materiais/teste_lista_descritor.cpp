
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
#include "lista_descritor.hpp"

main()
{
    setlocale(LC_ALL, "Portuguese");
    Lista *lista = new Lista();///executa o construtor....

    insere(lista, 11);
    insere(lista, 22);
    insere(lista, 33);
    insere(lista, 44);
/// 44 33 22 11

    cout << "\n Lista: \n";
    cout << lista;

    remover(lista, 33);

    cout << "\n Lista depois remover: " << endl;

    cout << "\n Tamanho: " << lista->tamanho << endl;

    cout << lista;


    delete(lista); ///executa desconstrutor
    return true;
}

