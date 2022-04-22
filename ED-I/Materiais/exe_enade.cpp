#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
#include "pilha_char.hpp"

void inverte(string texto);

main()
{
    string texto;
    cout << "Informe texto:";
    getline(cin, texto);
    fflush(stdin);
    inverte(texto);

}//final do main


void inverte(string texto)
{
    int i;
    pilha p;
    int tam;
    tam = texto.size();
    inicializa(&p, tam);
    for( i = 0; i < tam ; i++ )
    {
        empilhar(&p, texto[i]);
    }
    //show(&p);
    cout << "\n Saída: ";
    for( i = 0; i < tam ; i++ )
    {
        cout << desempilhar(&p);
    }

}
