#include <iostream>
#include <cstdio>
#include <cstdlib>
#define TAMV 20
using namespace std;
#include "ArquivoPilha.hpp"
void mostrarVetor(int vetor[TAMV], int i);
main()
{
    int menu, valor;
    int num, indice =0;
    int vetor[TAMV];
    pilha pi;
    inicializa(&pi, 20);
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
            cout<<"Programa finalizado." << endl;
            getchar();
            break;
        case 1 :
            system("cls");
            if(!cheia(&pi))
            {
                cout<<"Informe o valor a ser empilhado: " << endl;
                cin>>num;
                fflush(stdin);
                if (!buscar(&pi, num))// empilha caso o valor não esteja na pilha
                    empilhar(&pi, num);
                else
                    cout<<"Valor já empilhado" << endl;
            }
            else
                cout<<"PILHA CHEIA." << endl;
            getchar();
            break;
        case 2 :
            system("cls");
            if(!vazia(&pi))// se a pilha não estiver vazia
            {
                if (indice < TAMV)// se o indice do vetor for menor que o tamanho
                {
                    cout<<"Valor desempilhado: " << endl;
                    valor = desempilhar(&pi);
                    cout << valor;
                    cout<<"\n\n";
                    vetor[indice] = valor;
                    indice++;
                }
                else
                    cout<<"Vetor sem espaço para retirar da pilha" << endl;
            }
            else
                cout<<"PILHA VAZIA." << endl;
            getchar();
            break;
        case 3 :
            system("cls");
            if(!vazia(&pi))
                mostrar(&pi);
            else
                cout<<"PILHA VAZIA." << endl;
            getchar();
            break;
        case 4 :
            system("cls");
            mostrarVetor(vetor, indice);
            getchar();
            break;
        }
    }
    while (menu != 0);
}
void mostrarVetor(int vetor[TAMV], int i)
{
    cout << "DADOS DO VETOR" << endl;
    for(int x = 0; x < i; x++)
    {
        cout << "  ---------" << endl;
        cout << x << " |   ";
        cout << vetor[x];
        cout << "   |" << endl;
        cout << "  ---------" << endl;
    }
}


