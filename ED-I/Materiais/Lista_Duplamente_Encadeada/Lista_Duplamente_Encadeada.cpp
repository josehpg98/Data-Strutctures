#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
#include "Lista_Duplamente_Encadeada.hpp"
main()
{
    setlocale(LC_ALL,"Portuguese");
    Lista *lista1 = new Lista();///executa o construtor da lista
    Pessoas p;
    p.cod = 1;
    p.nome = "Joao";
    insere(lista1, p);
    p.cod = 2;
    p.nome = "Maria";
    insere(lista1, p);
    p.cod = 3;
    p.nome = "Jose";
    insere(lista1, p);
    cout<<lista1;///mostra a lista 1
}
