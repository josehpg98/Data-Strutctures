#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#include "pilha.hpp"

main()
{
    int menu, valor;
    pilha p1;
    cout << "Informe o tamanho da pilha: ";
    cin >> valor;
    inicializa(&p1, valor);
    do
    {
        system("cls");
        cout << "0 - SAIR" << endl;
        cout << "1 - INCLUIR" << endl;
        cout << "2 - DESEMPLILHAR" << endl;
        cout << "3 - MOSTRAR PILHA" << endl;
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
            if(!cheia(&p1))
            {
                cout << "Informe o valor a ser empilhado: ";
                cin >> valor;
                fflush(stdin);
                empilhar(&p1, valor);
                cout << "Valor empilhado";
            }
            else
                cout << "PILHA CHEIA.";
            getchar();
            break;
        case 2 : // desempilhar
            system("cls");
            if(!vazia(&p1))
            {
                cout << "Valor desempilhado: ";
                valor = desempilhar(&p1);
                cout << valor;
            }
            else
                cout << "PILHA VAZIA.";
            getchar();
            break;
        case 3 : // mostrar pilha
            system("cls");
            if(!vazia(&p1))
                mostrar(&p1);
            else
                cout << "PILHA VAZIA.";
            getchar();
            break;
        }
    }
    while (menu != 0);
}//final do main
