#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#include "pilha.hpp"

void procurar(pilha *pcidades, int cidade)
{
    pilha aux;
    inicializa(&aux, pcidades->tam);
    for (int x = pcidades->topo; x > pcidades->base; x--)
    {
        if (pcidades->dados[x] == cidade)
        {
            cout << "\n A cidade " << cidade << " existe no caminho" << endl;
            break;
        }else{ // não é a cidade
            empilhar(&aux, desempilhar(pcidades));
        }
    }// fim do laço
    if(vazia(pcidades))
        cout << "\n Cidade não existe no caminho";
    for(int i= aux.topo; i > aux.base; i--)
            empilhar(pcidades, desempilhar(&aux));

}

main()
{
    pilha pcidades;
    int num;

    do
    {
        system("cls");
        cout<<"Informe o número de cidades do caminho:"<<endl;
        cin >> num;
        fflush(stdin);
        if (num > 10)
        {
            cout << "\n Número máximo de cidades deve ser 10 \n";
            getchar();
        }


    }
    while(num <=0 || num > 10);

    inicializa(&pcidades, num);
    int op=0;
    int cidade;
    do
    {
        system("cls");

        cout<<"1: Adicionar cidade"<<endl;
        cout<<"2: Retirar cidade"  <<endl;
        cout<<"3: Mostrar caminho "<<endl;
        cout<<"4: Procurar cidade "<<endl;
        cout<<"0: Sair            "<<endl;
        cout<<"Opcao:";
        cin>>op;
        fflush(stdin);

        switch (op)
        {
        case 0:
            system("cls");
            cout<<"Programa Finalizado!"<<endl;

            getchar();
            break;
        case 1:
            system("cls");
            fflush(stdin);
            if(!cheia(&pcidades))
            {
                cout<<"Informe a cidade que fez parte do caminho:"<<endl;
                cin >> cidade;
                fflush(stdin);
                empilhar(&pcidades, cidade);
            }
            else
                cout<<"Pilha cheia!";
            getchar();
            break;
        case 2:
            system("cls");
            if(!vazia(&pcidades))
                cout<<"Cidade removida: "<<desempilhar(&pcidades);
            else
                cout<<"Sem cidades para retirar!";
            getchar();
            break;
        case 3:
            system("cls");
            mostrar(&pcidades);
            getchar();
            break;
        case 4:
            system("cls");
            cout<<"Informe a cidade para procurar:"<<endl;
            cin >> cidade;
            fflush(stdin);
            procurar(&pcidades, cidade);
           // mostrar(&pcidades);
            getchar();
            break;
        default:
            system("cls");
            cout<<"Opcao invalida!"<<endl;
            getchar();
            break;
        }
    }
    while(op!=0);
}
