#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#include "Lista.hpp"
main()
{
    setlocale(LC_ALL,"Portuguese");
    int recebe = 0, valor = 0,op;
    No *lista;///cria uma lista com ponteiro para o primeniron�
    inicializa(&lista);
    do
    {
        system("cls");
        cout<<"-- Menu de Op��es Para Lista" << endl;
        cout<<" 0 - Sair " << endl;
        cout<<" 1 - Incluir " << endl;
        cout<<" 2 - Retirar " << endl;
        cout<<" 3 - Mostrar " << endl;
        cout<<" Escolha uma op��o listada acima: " << endl;
        cin>>op;
        fflush(stdin);
        switch(op)
        {
        case 0:
            cout<<"Programa Encerrado! " << endl;
            getchar();
            break;
        case 1:
            cout<<" Informe um valor para icluir: " << endl;
            cin>>valor;
            fflush(stdin);
            insere(&lista, valor);
            cout<<" O valor incluido na Lista foi: " << valor << endl;
            getchar();
            break;
        case 2:
            cout<<"Informe Um Valor Para Ser Removida da Lista: " << endl;
            cin>>valor;
            fflush(stdin);
            remover(&lista, valor);
            if(remover(&lista, valor) == true)
            {
                cout<<" O valor foi retirado com sucesso! " << endl;
            }
            getchar();
            break;
        case 3:
            mostrar(lista);
            getchar();
            break;
        default:
            cout<<" Op��o Inv�lida!" << endl;
            getchar();
            break;
        }
    }
    while(op != 0);
}
