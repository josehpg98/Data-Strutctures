
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
#include "lista_dupla.hpp"

main()
{
    setlocale(LC_ALL, "Portuguese");
    Lista *lista = new Lista();///executa o construtor....

    Pessoas p;
    p.cod = 1;
    p.nome = "Maria";
    inserir(lista, p);

    p.cod = 2;
    p.nome = "Ana";
    inserir(lista, p);

    p.cod = 3;
    p.nome = "Beti";
    inserir(lista, p);

    cout << lista;

    //remover(lista, 2);
   // cout << lista;


    No *n = busca(lista, 1);
    if (n)
        cout << "\n  Pessoa encontrada: " << n->pessoa.nome << endl;
    else
        cout << "\n Pessoa não encontrada \n";

    mostrarInverso(lista);

}
