#include<iostream>//flixo de dados
#include<cstdio>//entrada/saida
#include<cstdlib>//biblioteca padrão da linguagem c
using namespace std;
#include "fila_circular.hpp"
main()
{
    setlocale(LC_ALL,"Portuguese");
    Fila f1;
    int recebe = 0,menu = -1,op,valor;
    cout<<"Informe o tamaho da fila: " << endl;
    cin>>valor;
    fflush(stdin);
    initQ(&f1, valor);//inicia fila com tamanho que o usuario deseja
    do
    {
        system("cls");
        cout<<"-- Menu de Opções Para Fila" << endl;
        cout<<" 0 - Sair " << endl;
        cout<<" 1 - Incluir " << endl;
        cout<<" 2 - Retirar " << endl;
        cout<<" 3 - Espiar " << endl;
        cout<<" 4 - Mostrar " << endl;
        cout<<" Escolha uma opção listada acima: " << endl;
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
            enqueue(&f1, valor);
            cout<<" O valor incluido na fila foi: " << valor << endl;
            getchar();
            break;
        case 2:
            recebe = dequeue(&f1);
            cout<<" O valor retirado foi: " << recebe << endl;
            getchar();
            break;
        case 3:
            recebe = peekQ(&f1);
            cout<<" O valor que está no topo é: " << recebe << endl;
            getchar();
            break;
        case 4:
            showQ(&f1);
            getchar();
            break;
        default:
            cout<<" Opção Inválida!" << endl;
            getchar();
            break;
        }
    }
    while(op != 0);
}

