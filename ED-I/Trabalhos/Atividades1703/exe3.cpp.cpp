#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#include "fila_circular.hpp"
#include "pilha_dinamica.hpp"
void mostrarFilas(Fila *fpar, Fila *fimpar, Fila *fprimo);
void enfileirar(Fila *f, int valor);
bool ePrimo( int nro );
main()
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
        cout << "1 - peek;\n 2 - pop;\n3 - push;\n" <<
             "4 - show;\n5 - Mostrar Filas;\n0 - sair\n$ ";
        fflush(stdin);
        cin >> opcao;
        switch(opcao)
        {
        case 1://peek
            if (peek(&Pilha,&reg))
                cout << "Elemento encontrado : " << reg.dado <<  endl;
            else
                cout << "Nao foi poss�vel encontrar nenhum elemento." << endl;
            break;
        case 2://pop
            if (pop(&Pilha, &temp))
            {
                valor = temp.dado;
                cout  << "Elemento exclu�do:" << valor << endl;
                if (ePrimo(valor))
                    enfileirar(&fprimo, valor);
                else if (temp.dado % 2 == 0)
                    enfileirar(&fpar, valor);
                else
                    enfileirar(&fimpar, valor);
            }
            else
                cout << "Nao foi poss�vel excluir elemento." << endl;
            break;
        case 3://push
            cout << "Digite valor as ser emPilhado: ";
            cin >> reg.dado;
            fflush(stdin);
            if (push(&Pilha,reg))
                cout << "Elemento inserido: " << reg.dado << endl;
            else
                cout << "Nao foi poss�vel inserir elemento. " << endl;
            break;
        case 4://mostra
            show(&Pilha);
            break;
        case 5:
            mostrarFilas(&fpar, &fimpar, &fprimo);
            break;
        case 0:
            cout << "Saindo... fui!" << endl;;
            break;
        default:
            cout << "Op��o inv�lida" << endl;
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
    cout << "Fila PRIMOS:" << endl;
    showQ(fprimo);
    cout << "Fila PARES:" << endl;
    showQ(fpar);
    cout << "Fila �MPARES:" << endl;
    showQ(fimpar);
}
void enfileirar(Fila *f, int valor)
{
    if (enqueue(f,valor))
        cout << " Valor inclu�do " << endl;
    else
       cout << " N�o foi poss�vel inserir" << endl;
}
bool ePrimo( int nro )
{
    if( nro == 0 )
        return false;
    if(nro == 1 || nro == 2)
        return true;
    int i;
    for( i=2; i<nro; i++ )
    {
        if( nro % i ==0 )
            return false;
    }
    return true;
}
