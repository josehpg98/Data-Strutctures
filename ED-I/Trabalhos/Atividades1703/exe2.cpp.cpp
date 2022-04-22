#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#include "fila_circular_avioes.hpp"
int main()
{
    struct Fila fila1;
    bool teste;
    int opcao;
    avioes aviao;
    initQ(&fila1, 5);
    setlocale(LC_ALL, "Portuguese");
    do
    {
        cout << "Fila! Escolha uma op��o:\n\n";
        cout << "1 - N� de avi�es � espera de decolar\n" <<
             "2 - Descolagem de um avi�o \n" <<
             "3 - Entrada de um novo avi�o para decolar\n" <<
             "4 - Listar todos os avi�es � espera para decolagem\n" <<
             "5 - Listar as caracter�sticas do pr�ximo avi�o a decolar\n" <<
             "0 - sair\n$ ";
        fflush(stdin);
        cin >> opcao;
        switch(opcao)
        {
        case 1:
            contQ(&fila1);
            break;
        case 2: /// decolagem - retirar da fila
            if (!isEmptyQ(&fila1)){
                aviao = dequeue(&fila1);
                cout << "\n Avi�o que decolou: " << aviao.cod << " - " <<
                aviao.passageiros  << " - " << aviao.empresa;
            }else
                cout<< "\n N�o h� avi�es na fila para decolar";
            break;
        case 3:/// incluir avi�o na fila
            cout << "\n Informe o c�digo do avi�o: ";
            cin >> aviao.cod;
            fflush(stdin);
            cout << "\n Informe o n�mero de passageiros: ";
            cin >> aviao.passageiros;
            fflush(stdin);
            cout << "\n Informe o nome da empresa: ";
            getline(cin, aviao.empresa);
            fflush(stdin);
            if (enqueue(&fila1, aviao)){
                cout << "\n Avi�o inclu�do com sucesso";
            }else
                cout << "\n Fila est� cheia! N�o foi poss�vel incluir";
            break;
        case 4://mostra
            showQ(&fila1);
            getchar();
            break;
        case 5:/// mostrar pr�ximo avi�o a decolar
            if (!isEmptyQ(&fila1)){
                aviao = peekQ(&fila1);
                cout << "\n Pr�ximo avi�o a decolar: "<< aviao.cod  << " - " <<
                aviao.passageiros << " - " << aviao.empresa;
            }else
                cout << "\n Fila vazia! N�o h� avi�es para decolar";

            break;
        case 0:
            cout << "Saindo... fui.";
            break;
        default:
            cout << "Op��o inv�lida";
            getchar();
            break;
        }
        system("PAUSE");
        system("CLS");
    }
    while(opcao != 0);
    return 0;
}


