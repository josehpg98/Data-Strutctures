#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#include "ArquivoPilha.hpp";
main()
{
    setlocale(LC_ALL,"Portuguese");
    int menu = -1,op;
    int v = 0;
    bool resultado;
    cout<<"Informe o valor do tamanho da pilha: " << endl;
    cin>>v;
    fflush(stdin);
    pilha pi;
    inicializa(&pi, v);
    do
    {
        system("cls");
        cout<<" -- Menu de Ações -- " << endl;
        cout<<" 0 - Sair " << endl;
        cout<<" 1 - Empilhar " << endl;
        cout<<" 2 - Desempilhar " << endl;
        cout<<" 3 - Buscar " << endl;
        cout<<" 4 - Mostrar Pilha " << endl;
        cout<<" 5 - Verifica Elementos Pares " << endl;
        cout<<" 6 - Verifica Elemento Impares " << endl;
        cout<<" Escolha sua opção: " << endl;
        cin>>op;
        fflush(stdin);
        switch(op)
        {
        case 0 :
            system("cls");
            cout<<" O programa foi encerrado! " << endl;
            getchar();
            break;
        case 1 :
            system("cls");
            cout<<" Informe o valor para acrescentar a pilha: " << endl;
            cin>>v;
            fflush(stdin);
            empilhar(&pi, v);
            menu += 1;
            break;
        case 2 :
            system("cls");
            if(menu < 0)
            {
                cout<<"Primeiro acrescente um valor na piha!" << endl;
                getchar();
            }
            else
            {
                cout<<"Para retirar da pilha: " << endl;
                desempilhar(&pi);
                int valor2 = 0;
                valor2 = desempilhar(&pi);
                cout<<"\n O valor retirado da pilha foi: " << valor2 << endl;
            }
            break;
            getchar();
        case 3 :
            system("cls");
            if(menu < 0)
            {
                cout<<"Primeiro acrescente um valor na piha!" << endl;
                getchar();
            }
            else
            {
                cout<<"Informe o valor para buscar da pilha: " << endl;
                cin>>v;
                fflush(stdin);
                buscar(&pi, v);
            }
            break;
        case 4 :
            system("cls");
            if(menu < 0)
            {
                cout<<"Primeiro acrescente um valor na piha!" << endl;
                getchar();
            }
            else
            {
                mostrar(&pi);
                getchar();
            }
            break;
        case 5 :
            system("cls");
            if(menu < 0)
            {
                cout<<"Primeiro acrescente um valor na piha!" << endl;
                getchar();
            }
            else
            {
                verifica_par(&pi);
            }
            break;
        case 6 :
            system("cls");
            if(menu < 0)
            {
                cout<<"Primeiro acrescente um valor na piha!" << endl;
                getchar();
            }
            else
            {
                verifica_impar(&pi);
            }
            break;
        }
    }
    while(op != 0);
}
