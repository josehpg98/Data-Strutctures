#include <iostream>
#include <cstdio>
#include <cstdlib>
#define TAMV 3

using namespace std;

#include "pilha.hpp"

void mostrarVetor(int vetor[TAMV], int i);

main()
{
    int menu, valor;
    int num, iv=0;
    int vetor[TAMV];
    pilha p1;
    inicializa(&p1, 10);

    do
    {
        system("cls");
        cout << "0 - SAIR" << endl;
        cout << "1 - INCLUIR" << endl;
        cout << "2 - DESEMPLILHAR" << endl;
        cout << "3 - MOSTRAR PILHA" << endl;
        cout << "4 - MOSTRAR VETOR" << endl;
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
                cin >> num;
                fflush(stdin);
                if (!buscar(&p1, num))
                    empilhar(&p1, num);
                else
                    cout << "Valor já empilhado";
            }
            else
                cout << "PILHA CHEIA.";
            getchar();
            break;
        case 2 : // desempilhar
            system("cls");
            if(!vazia(&p1))
            {
                if (iv < TAMV)
                {
                    cout << "Valor desempilhado: ";
                    valor = desempilhar(&p1);
                    cout << valor;
                    vetor[iv] = valor;
                    iv++;
                }else
                    cout << "\n Vetor sem espaço para retirar da pilha";
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
        case 4 : // mostrar vetor
            system("cls");
            mostrarVetor(vetor, iv);
            getchar();
            break;
    }
    }
    while (menu != 0);
}//final do main

void mostrarVetor(int vetor[TAMV], int i)
{
    int x;
    cout << "DADOS DO VETOR" << endl;
    for(x = 0; x < i; x++)
    {
        cout << "  ---------" << endl;
        cout << x << " |   ";
        cout << vetor[x];
        cout << "   |" << endl;
        cout << "  ---------" << endl;
    }
}

