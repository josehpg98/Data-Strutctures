#include <iostream>
#include <cstdio>
#include <cstdlib>

#define TAM 10

using namespace std;

struct pilha
{
    int tam;
    int topo1;
    int base1;
    int topo2;
    int base2;
    int dados[TAM];

};

void inicializa (pilha *p);
bool cheia(pilha *p);
bool vazia1(pilha *p);
bool vazia2(pilha *p);
void empilhar1(pilha *p, int num);
void empilhar2(pilha *p, int num);
void mostra(pilha *p);
int desempilhar1(pilha *p);
int desempilhar2(pilha *p);

main()
{
    int menu, valor, pos;
    int num;
    pilha minha_pilha;
    inicializa(&minha_pilha);

    do
    {
       system("cls");
       cout << "0 - SAIR" << endl;
       cout << "1 - INCLUIR PILHA 1" << endl;
       cout << "2 - INCLUIR PILHA 2" << endl;
       cout << "3 - MOSTRAR" << endl;
       cout << "4 - DESEMPLILHAR PILHA 1" << endl;
       cout << "5 - DESEMPLILHAR PILHA 2" << endl;
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
             if(!cheia(&minha_pilha))
             {
                 cout << "Informe o valor a ser empilhado: ";
                 cin >> num;
                 fflush(stdin);
                 empilhar1(&minha_pilha, num);
             }
             else
             {
                 cout << "PILHA CHEIA.";
                 getchar();
             }
             break;
          case 2 :
             system("cls");
             if(!cheia(&minha_pilha))
             {
                 cout << "Informe o valor a ser empilhado: ";
                 cin >> num;
                 fflush(stdin);
                 empilhar2(&minha_pilha, num);
             }
             else
             {
                 cout << "PILHA CHEIA.";
                 getchar();
             }
             break;
          case 3 :
             system("cls");
             mostra(&minha_pilha);
             getchar();
             break;
          case 4 :
             system("cls");
             if(!vazia1(&minha_pilha))
             {
                 cout << "Valor desempilhado: ";
                 cout << desempilhar1(&minha_pilha);
            }
             else
                 cout << "PILHA VAZIA.";
             getchar();
             break;
          case 5 :
             system("cls");
             if(!vazia2(&minha_pilha))
             {
                 cout << "Valor desempilhado: ";
                 cout << desempilhar2(&minha_pilha);
            }
             else
                 cout << "PILHA VAZIA.";
             getchar();
             break;
       }
    }while (menu != 0);
}//final do main


void inicializa (pilha *p)
{
    p->tam  = TAM;
    p->base1 = -1;
    p->topo1 = p->base1;
    p->base2 = TAM;
    p->topo2 = p->base2;
}

bool cheia(pilha *p)
{
    if(p->topo1 + 1 == p->topo2)
       return true;
    else
       return false;
}

bool vazia1(pilha *p)
{
    if(p->topo1 == p->base1)
       return true;
    else
       return false;
}


bool vazia2(pilha *p)
{
    if(p->topo2 == p->base2)
       return true;
    else
       return false;
}



void empilhar1(pilha *p, int num)
{
    if (!cheia(p))
    {
        p->topo1++;
        p->dados[p->topo1] = num;
    }else
        cout << "\n Pilha 1 cheia!" << endl;
}

void empilhar2(pilha *p, int num)
{
    if (!cheia(p))
    {
        p->topo2--;
        p->dados[p->topo2] = num;
    }else
        cout << "\n Pilha 2 cheia!" << endl;
}

void mostra(pilha *p)
{
    int x;
    cout << "DADOS NA PILHA " << endl;
    cout << "TAM: " << p->tam << endl;
    cout << "TOPO1: " << p->topo1 << endl;
    cout << "BASE1: " << p->base1 << endl;
    cout << "TOPO2: " << p->topo2 << endl;
    cout << "BASE2: " << p->base2 << endl;
    cout << "\n\n";
    cout << "\nPILHA 1 \n";

    for(x = p->topo1; x > p->base1; x--)
    {
        cout << "  ---------" << endl;
        cout << x << " |   ";
        cout << p->dados[x];
        cout << "   |" << endl;
        cout << "  ---------" << endl;
    }
    cout << "\nPILHA 2 \n";
    for(x = p->topo2; x < p->base2; x++)
    {
        cout << "  ---------" << endl;
        cout << x << " |   ";
        cout << p->dados[x];
        cout << "   |" << endl;
        cout << "  ---------" << endl;
    }

}

int desempilhar1(pilha *p)
{
    if (!vazia1(p))
    {
        int valor = p->dados[p->topo1];
        p->topo1--;
        return valor;
    }else
    {
        cout << "\n Pilha 1 vazia ";
        return NULL;
    }
}

int desempilhar2(pilha *p)
{
    if (!vazia2(p))
    {
        int valor = p->dados[p->topo2];
        p->topo2++;
        return valor;
    }else
    {
        cout << "\n Pilha 2 vazia ";
        return NULL;
    }
}
