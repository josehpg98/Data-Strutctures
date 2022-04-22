#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define TAMANHO 3
using namespace std;
#include "ArquivoPilha.hpp"
main()
{
    setlocale(LC_ALL,"Portuguese");
    pilha p1;
    pilha p2;
    inicializa(&p1, TAMANHO);
    inicializa(&p2, TAMANHO);
    int v1 = 0, v2 = 0, v3 = 0;
    int result;
    cout<<"Informe os valores da pilha 1: " << endl;
    cin>>v1;
    fflush(stdin);
    empilhar(&p1,v1);
    cin>>v2;
    fflush(stdin);
    empilhar(&p1,v2);
    cin>>v3;
    fflush(stdin);
    empilhar(&p1,v3);
    cout<<"Informe os valores da pilha 2: " << endl;
    cin>>v1;
    fflush(stdin);
    empilhar(&p2,v1);
    cin>>v2;
    fflush(stdin);
    empilhar(&p2,v2);
    cin>>v3;
    fflush(stdin);
    empilhar(&p2,v3);
    result = verifica_pilhas(&p1,&p2);
    if(result == 3)
    {
        cout<<"AS PILHAS SÃO IGUAIS, CONTENDO OS MESMOS VALORES!" << endl;
    }
    else
    {
        cout<<"AS PILHAS NÃO SÃO IGUAIS, POIS NÃO CONTÉM OS MESMOS VALORES!" << endl;
    }
}
