
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
#include "lista_dupla_sublista.hpp"

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

   insereSub(lista, 1, "1111");///incluir fone 1111 para pessoa  1
   insereSub(lista, 1, "9999");///incluir fone 9999 para pessoa 1
   insereSub(lista, 2, "2222");///incluir fone 2222 para pessoa 2
   insereSub(lista, 3, "7777");///incluir fone 7777 para pessoa 3

    cout << lista;

}
