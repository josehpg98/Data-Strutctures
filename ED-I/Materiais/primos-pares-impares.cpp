#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#include "fila_circular.hpp"
#include "pilha_dinamica.hpp"

/*
3. Faça um programa que cadastre vários números em uma estrutura do tipo Pilha.
 Ao remover um número da Pilha, este deve ser enfileirado em uma Fila, conforme o critério:
- se o número for primo, na Fila dos primos
- se o número for par, na Fila dos pares
- se o número for ímpar, na Fila dos ímpares

O menu deve conter as seguintes opções:
- Incluir na Pilha
- Remover da Pilha
- Mostrar Pilha
- Mostrar as Filas (Primos/Pares/Ímpares)
*/

void mostrarFilas(Fila *fpar, Fila *fimpar, Fila *fprimo);
void enfileirar(Fila *f, int valor);
bool ehPrimo( int nro );


int main()
{
    Pilha Pilha;
    init(&Pilha);

    Fila fpar, fimpar, fprimo;
    int opcao;
    Registro reg;
    Registro temp;
    int valor;

    setlocale(LC_ALL, "Portuguese");

    initQ(&fpar, 10);
    initQ(&fimpar, 10);
    initQ(&fprimo, 10 );

    do
    {
        cout << "Fila! Escolha uma opção:\n\n";
        cout << "1 - peek;\n2 - pop;\n3 - push;\n" <<
             "4 - show;\n5 - Mostrar Filas;\n0 - sair\n$ ";
        fflush(stdin);
        cin >> opcao;
        switch(opcao)
        {
        case 1://peek
            if (peek(&Pilha,&reg))
                cout << "Elemento encontrado : " << reg.dado <<  endl;
            else
                cout << "Nao foi possível encontrar nenhum elemento (Pilha vazia).\n";

            break;
        case 2://pop
            if (pop(&Pilha, &temp))
            {
                valor = temp.dado;
                cout  << "Elemento excluído:" << valor << endl;
                if (ehPrimo(valor))
                    enfileirar(&fprimo, valor);
                else if (temp.dado % 2 == 0)
                    enfileirar(&fpar, valor);
                else
                    enfileirar(&fimpar, valor);
            }
            else
                cout << "Nao foi possível excluir elemento (Pilha vazia).\n";

            break;
        case 3://push
            cout << "Digite valor as ser emPilhado: ";
            cin >> reg.dado;
            fflush(stdin);
            if (push(&Pilha,reg))
                cout << "Elemento inserido: " << reg.dado << endl;
            else
                cout << "Nao foi possível inserir elemento. \n";
            break;
        case 4://mostra
            show(&Pilha);
            break;
        case 5:
            mostrarFilas(&fpar, &fimpar, &fprimo);
            break;
        case 0:
            cout << "Saindo...";
            break;
        default:
            cout << "Opção inválida";
            break;
        }
        system("PAUSE");
        system("CLS");
    }
    while(opcao != 0);
    return 0;
}

void mostrarFilas(Fila *fpar, Fila *fimpar, Fila *fprimo)
{
    cout << "\n\nFila PRIMOS:";
    showQ(fprimo);
    cout << "\n\nFila PARES:";
    showQ(fpar);
    cout << "\n\nFila ÍMPARES:";
    showQ(fimpar);

}

void enfileirar(Fila *f, int valor)
{
    if (enqueue(f,valor))
        cout << "\n Valor incluído \n";
    else
       cout << "\n Não foi possível inserir\n";

}


bool ehPrimo( int nro )
{
    if( nro == 0 )
        return false;
    if(nro == 1 || nro == 2)
        return true;
    int i;
    for( i=2; i<nro; i++ )
    {
        if( nro % i ==0 )
            return false;//se é divisível por pelo menos um i, não é primo
    }
    //se após todas as divisões entre 2 e nro-1 não teve nenhuma divisão exata, é primo
    return true;
}
