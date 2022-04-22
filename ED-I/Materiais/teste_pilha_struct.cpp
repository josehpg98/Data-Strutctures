#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#include "pilha_dinamica_struct.hpp";

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Pilha p;
    int menu;
    Registro reg; /// codigo titulo tipo ano
    init(&p); ///inicializar a pilha

    do
    {
        system("cls");
        cout << "0 - SAIR" << endl;
        cout << "1 - INCLUIR" << endl;
        cout << "2 - DESEMPLILHAR" << endl;
        cout << "3 - MOSTRAR PILHA" << endl;
        cout << "4 - QUANTIDADES" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        switch (menu)
        {
        case 0 :
            system("cls");
            cout << "Programa finalizado.";
            getchar();
            break;
        case 1 :
            system("cls");
            if (isEmpty(&p))
                reg.codigo = 0;
            else
                reg.codigo = p.topo->reg.codigo;
            reg.codigo++;
          //  cout << "Informe o código: ";
          //  cin >> reg.codigo;
          //  fflush(stdin);
            cout << "Informe o título: ";
            getline(cin, reg.titulo);
            fflush(stdin);

            cout << "Informe o tipo [1-Gibi 2-Mangá]: ";
            cin  >> reg.tipo;
            fflush(stdin);
            cout << "Informe o ano: ";
            cin  >> reg.ano;
            fflush(stdin);
            push(&p, reg);
            getchar();
            break;
        case 2 : // desempilhar
            system("cls");
            if (pop(&p, &reg))
                cout << "Valor desempilhado: " << reg.titulo << endl;
            else
                cout << "PILHA VAZIA.";
            getchar();
            break;
        case 3 : // mostrar pilha
            system("cls");
            show(&p);
            getchar();
            break;
        case 4 : // mostrar quantidades da pilha
            system("cls");
            contar(&p);
            getchar();
            break;
        }
    }
    while (menu != 0);
    return 0;

}
