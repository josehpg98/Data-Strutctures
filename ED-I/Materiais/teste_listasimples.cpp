
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
#include "lista.hpp"

main()
{
    setlocale(LC_ALL, "Portuguese");

    /// cria��o da lista - ponteiro para primeiro n�
    No *lista;

    inicializa(&lista);///lista == NULL

    insere(&lista, 10);
    insere(&lista, 5);
    insere(&lista, 2);
    insere(&lista, 8);

    mostrar(lista);

    remover(&lista, 2);


    mostrar(lista);
    return true;
}

