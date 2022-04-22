#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#include "Lista.hpp"
main()
{
    setlocale(LC_ALL,"Portuguese");
    int recebe = 0, valor = 0,op;
    bool resultado;
    No *lista1, *lista2;///cria uma lista com ponteiro para o primenironó
    No *teste;
    inicializa(&lista1);
    inicializa(&lista2);
    do
    {
        system("cls");
        cout<<"-- Menu de Opções Para Lista" << endl;
        cout<<" 0 - Sair " << endl;
        cout<<" 1 - Incluir " << endl;
        cout<<" 2 - Retirar " << endl;
        cout<<" 3 - Mostrar " << endl;
        cout<<" 4 - Contar Elementos da Lista " << endl;
        cout<<" 5 - verificar se a Lista está vazia " << endl;
        cout<<" 6 - verificar se as Listas são iguais " << endl;
        cout<<" 7 - Busca um valor na lIsta " << endl;
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
            insere(&lista1, valor);
            cout<<" O valor incluido na Lista foi: " << valor << endl;
            getchar();
            break;
        case 2:
            cout<<"Informe Um Valor Para Ser Removida da Lista: " << endl;
            cin>>valor;
            fflush(stdin);
            remover(&lista1, valor);
            if(remover(&lista1, valor) == true)
            {
                cout<<" O valor foi retirado com sucesso! " << endl;
            }
            getchar();
            break;
        case 3:
            mostrar(lista1);
            getchar();
            break;
        case 4:
            recebe = contlista(lista1);
            cout<<" O total de elementos da lista é: " << recebe << endl;
            getchar();
            break;
        case 5:
            vazia(lista1);
            getchar();
            break;
        case 6:
            resultado = igual(lista1, lista2);
            if(resultado == false)
            {
                cout<<"As Listas não São Iguais!" << endl;
                getchar();
                break;
            }
            getchar();
            break;
        case 7:
            cout<<" Informe Um Valor Para Busca na Lista: " << endl;
            cin>>valor;
            fflush(stdin);
            teste = busca(lista1,valor);
            cout<<" Mostra Busca: " << endl;
            cout<<teste->dados << endl;
            cout<<teste->proximo << endl;
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
