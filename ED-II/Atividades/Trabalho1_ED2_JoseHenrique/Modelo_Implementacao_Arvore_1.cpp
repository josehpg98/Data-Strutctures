#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
#include "Arvore.hpp"
int main()
{
    arvore *t = cria_arvore(); /* cria uma árvore */
    arvore *no_pai;//cria um no
    int menu = -1,valor = 0,resultado,alsd,alse,alv,num;
    do
    {
        system("cls");
        cout << "*-----------------------*" << endl;
        cout << "|    MENU DE OPCOES!!   |" << endl;
        cout << "*-----------------------*" << endl;
        cout << "| 0 - Sair              |" << endl;
        cout << "| 1 - Incluir           |" << endl;
        cout << "| 2 - Mostrar           |" << endl;
        cout << "| 3 - Remover           |" << endl;
        cout<< " | 4 - Consulta Valor Existente na arvore   |" <<endl;
        cout<< " | 5 - Altura Sub-Arvore Esquerda " << endl;
        cout<< " | 6 - Altura Sub-Arvore Direita " << endl;
        cout<< " | 7 - Altura da Arvore " << endl;
        cout<< " | 8 - Mostrar a Quantidade de Nós a Partir de um Determinado Valor: " << endl;
        cout<< " | 9 - Mostrar Nós Pares: " << endl;
        cout<< " | 10 - Mostrar Nós Impares: " << endl;
        cout << "*-----------------------*" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        switch (menu)
        {
        case 0:
            system("cls");
            delete(t);
            cout << "PROGRAMA FINALIZADO!";
            getchar();
            break;
        case 1:
            system("cls");
            cout << "Informe o valor a ser incluido: ";
            cin >> num;
            fflush(stdin);
            inserir(&t, num);
            cout << "VALOR INCLUIDO COM SUCESSO!";
            getchar();
            break;
        case 2:
            system("cls");
            if(testa_vazia(t)) /* Verifica se a árvore está vazia */
                cout << "\n\nArvore vazia!!\n";
            else
            {
                cout << "ELEMENTOS NA ARVORE EM PRE-ORDEM: " << endl;
                mostra(t);
                cout << "\nELEMENTOS NA ARVORE EM ORDEM: " << endl;
                mostra_2(t);
                cout << "\nELEMENTOS NA ARVORE EM POS-ORDEM: " << endl;
                mostra_3(t);
            }
            getchar();
            break;
        case 3:
            system("cls");
            if(testa_vazia(t)) /* Verifica se a árvore está vazia */
                cout << "\n\n Arvore vazia!!\n";
            else
            {
                cout << "Informe o valor a ser removido: ";
                cin >> num;
                fflush(stdin);
                if(t->sae == NULL && t->sad == NULL)
                {
                    delete (t);
                    t = NULL;
                }
                else
                {
                    //consulta se o valor pertence a arvore

                    remover(&t, num);
                    cout << "VALOR REMOVIDO COM SUCESSO.";
                }
            }
            getchar();
            break;
        case 4:
            cout<<"informe o Valor a Ser Buscado: " << endl;
            cin>>valor;
            fflush(stdin);
            resultado = consulta(t,valor);
            if(resultado == 1)
            {

                cout<<"Valor Está na arvore " << endl;
            }
            else
            {
                cout<<" O valor Não Está na arvore! " << endl;
            }
            getchar();
            break;
        case 5:
            alse = conta_alt_esq(t);
            cout<<"A altura da arvore a esquerda é:" << alse << endl;
            getchar();
            break;
        case 6:
            alsd = conta_alt_dir(t);
            cout<<"A altura da arvore a direita é:" << alsd << endl;
            getchar();
            break;
        case 7:
            alv = conta_alt(t);
            cout<<"A altura da arvore é:" << alv << endl;
            getchar();
            break;
        case 8:
            cout<<"Informe um valor: " << endl;
            cin>>num;
            fflush(stdin);
            resultado = verifica_nos_informado(t, num);
            cout<<" O total de nós maiores que o valor informdo é: " << resultado << endl;
            getchar();
            break;
        case 9:
            mostra_par(t);
            getchar();
            break;
        case 10:
            mostra_impar(t);
            getchar();
            break;
        };
    }while (menu != 0);
}
