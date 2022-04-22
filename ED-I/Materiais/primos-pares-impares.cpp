#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#include "fila_circular.hpp"
#include "pilha_dinamica.hpp"

/*
3. Fa�a um programa que cadastre v�rios n�meros em uma estrutura do tipo Pilha.
 Ao remover um n�mero da Pilha, este deve ser enfileirado em uma Fila, conforme o crit�rio:
- se o n�mero for primo, na Fila dos primos
- se o n�mero for par, na Fila dos pares
- se o n�mero for �mpar, na Fila dos �mpares

O menu deve conter as seguintes op��es:
- Incluir na Pilha
- Remover da Pilha
- Mostrar Pilha
- Mostrar as Filas (Primos/Pares/�mpares)
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
        cout << "Fila! Escolha uma op��o:\n\n";
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
                cout << "Nao foi poss�vel encontrar nenhum elemento (Pilha vazia).\n";

            break;
        case 2://pop
            if (pop(&Pilha, &temp))
            {
                valor = temp.dado;
                cout  << "Elemento exclu�do:" << valor << endl;
                if (ehPrimo(valor))
                    enfileirar(&fprimo, valor);
                else if (temp.dado % 2 == 0)
                    enfileirar(&fpar, valor);
                else
                    enfileirar(&fimpar, valor);
            }
            else
                cout << "Nao foi poss�vel excluir elemento (Pilha vazia).\n";

            break;
        case 3://push
            cout << "Digite valor as ser emPilhado: ";
            cin >> reg.dado;
            fflush(stdin);
            if (push(&Pilha,reg))
                cout << "Elemento inserido: " << reg.dado << endl;
            else
                cout << "Nao foi poss�vel inserir elemento. \n";
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
            cout << "Op��o inv�lida";
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
    cout << "\n\nFila �MPARES:";
    showQ(fimpar);

}

void enfileirar(Fila *f, int valor)
{
    if (enqueue(f,valor))
        cout << "\n Valor inclu�do \n";
    else
       cout << "\n N�o foi poss�vel inserir\n";

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
            return false;//se � divis�vel por pelo menos um i, n�o � primo
    }
    //se ap�s todas as divis�es entre 2 e nro-1 n�o teve nenhuma divis�o exata, � primo
    return true;
}
