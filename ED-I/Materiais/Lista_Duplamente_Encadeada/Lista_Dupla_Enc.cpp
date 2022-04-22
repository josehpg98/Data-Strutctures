#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#include "Listadupla.hpp"
main()
{
    setlocale(LC_ALL,"Portuguese");
    Lista *lista1 = new Lista();
    Pessoas ps;
    ps.cod = 1;
    ps.nome = "José";
    inserir(lista1,ps);
    ps.cod = 2;
    ps.nome = "João";
    inserir(lista1,ps);
    ps.cod = 3;
    ps.nome = "Maria";
    inserir(lista1,ps);
    cout<<lista1;

}
