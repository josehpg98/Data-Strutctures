#include<iostream>//biblioteca padrao para manipula��o de fluxo de dados
#include<cstdio>
#include<cstdlib>// blblioteca para uso geral
using namespace std;//define espa�os de nomes em estruturas,classes, fun��es e etc..
#include "filasimples.hpp"
main()
{
    setlocale(LC_ALL,"Portuguese");
    Fila f1;
    int recebe = 0,menu = -1,op,valor;
    cout<<"Informe o tamaho da fila: " << endl;
    cin>>valor;
    fflush(stdin);
    iniciaQ(&f1, valor);//inicia fila com tamanho que o usuario deseja
    do
    {
        system("cls");
        cout<<"-- Menu de Op��es Para Fila" << endl;
        cout<<" 0 - Sair " << endl;
        cout<<" 1 - Incluir " << endl;
        cout<<" 2 - Retirar " << endl;
        cout<<" 3 - Espiar " << endl;
        cout<<" 4 - Mostrar " << endl;
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
            incluir(&f1, valor);
            cout<<" O valor incluido na fila foi: " << valor << endl;
            getchar();
            break;
        case 2:
            recebe = retira(&f1);
            cout<<" O valor retirado foi: " << recebe << endl;
            getchar();
            break;
        case 3:
            recebe = peek(&f1);
            cout<<" O valor que est� no topo �: " << recebe << endl;
            getchar();
            break;
        case 4:
            mostrafila(&f1);
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
