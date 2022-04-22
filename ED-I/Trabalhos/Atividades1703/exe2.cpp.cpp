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
        cout << "Fila! Escolha uma opção:\n\n";
        cout << "1 - Nº de aviões à espera de decolar\n" <<
             "2 - Descolagem de um avião \n" <<
             "3 - Entrada de um novo avião para decolar\n" <<
             "4 - Listar todos os aviões à espera para decolagem\n" <<
             "5 - Listar as características do próximo avião a decolar\n" <<
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
                cout << "\n Avião que decolou: " << aviao.cod << " - " <<
                aviao.passageiros  << " - " << aviao.empresa;
            }else
                cout<< "\n Não há aviões na fila para decolar";
            break;
        case 3:/// incluir avião na fila
            cout << "\n Informe o código do avião: ";
            cin >> aviao.cod;
            fflush(stdin);
            cout << "\n Informe o número de passageiros: ";
            cin >> aviao.passageiros;
            fflush(stdin);
            cout << "\n Informe o nome da empresa: ";
            getline(cin, aviao.empresa);
            fflush(stdin);
            if (enqueue(&fila1, aviao)){
                cout << "\n Avião incluído com sucesso";
            }else
                cout << "\n Fila está cheia! Não foi possível incluir";
            break;
        case 4://mostra
            showQ(&fila1);
            getchar();
            break;
        case 5:/// mostrar próximo avião a decolar
            if (!isEmptyQ(&fila1)){
                aviao = peekQ(&fila1);
                cout << "\n Próximo avião a decolar: "<< aviao.cod  << " - " <<
                aviao.passageiros << " - " << aviao.empresa;
            }else
                cout << "\n Fila vazia! Não há aviões para decolar";

            break;
        case 0:
            cout << "Saindo... fui.";
            break;
        default:
            cout << "Opção inválida";
            getchar();
            break;
        }
        system("PAUSE");
        system("CLS");
    }
    while(opcao != 0);
    return 0;
}


