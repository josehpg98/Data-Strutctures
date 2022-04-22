#include <iostream>
#include <cstdio>
#include <cstdlib>

#define TAM 6
using namespace std;
#include "pilha.hpp"

int busca(pilha *p, int v);

main()
{
    int menu, valor, pos;
    int num;
    pilha p, pp, pi;
    inicializa(&p, TAM);
    inicializa(&pp, TAM);
    inicializa(&pi, TAM);

    do
    {
        system("cls");
        cout << "0 - SAIR" << endl;
        cout << "1 - INCLUIR" << endl;
        cout << "2 - DESEMPLILHAR" << endl;
        cout << "3 - MOSTRAR PILHA INICIAL" << endl;
        cout << "4 - MOSTRAR PILHA PARES" << endl;
        cout << "5 - MOSTRAR PILHA ÍMPARES" << endl;
        cout << "6 - ZERAR AS PILHAS" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        switch (menu)
        {
        case 0 :
            system("cls");
            cout << "Programa finalizado.";
            getchar();
            break;
        case 1 :
            system("cls");
            if(!cheia(&p))
            {
                cout << "Informe o valor a ser empilhado: ";
                cin >> num;
                fflush(stdin);
                empilhar(&p, num);
            }
            else
                cout << "PILHA CHEIA.";
            getchar();
            break;
        case 2 :
            system("cls");
            if(!vazia(&p))
            {
                cout << "Valor desempilhado: ";
                valor = desempilhar(&p);
                cout << valor;
                if (valor%2 == 0) //par
                {
                    if (empilhar(&pp, valor))
                        cout << "\n Empilhando na pilha dos pares";
                    else
                        cout << "\n Pilha dos pares está cheia";
                }
                else
                {
                    if (empilhar(&pi, valor))
                        cout << "\n Empilhando na pilha dos ímpares";
                    else
                        cout << "\n Pilha dos ímpares está cheia";
                }
            }
            else
                cout << "PILHA VAZIA.";
            getchar();
            break;
        case 3 : // mostrar pilha inicial
            system("cls");
            if(!cheia(&p))
                mostrar(&p);
            else
                cout << "PILHA VAZIA.";
            getchar();
            break;
        case 4 : // mostrar pilha pares
            system("cls");
            if(!vazia(&pp))
                mostrar(&pp);
            else
                cout << "PILHA VAZIA.";
            getchar();
            break;
        case 5 : // mostrar pilha ímpares
            system("cls");
            if(!vazia(&pi))
                mostrar(&pi);
            else
                cout << "PILHA VAZIA.";
            getchar();
            break;
        case 6 :
            system("cls");
            inicializa(&p, TAM);
            inicializa(&pp, TAM);
            inicializa(&pi, TAM);
            cout << "Pilhas zeradas";
            getchar();
            break;
        }

    }
    while (menu != 0);
}//final do main




