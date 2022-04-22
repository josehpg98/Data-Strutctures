#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
//#include "aquivopilha.hpp";
///arquivos da pilha
struct pilha
{
    int tam;
    int base;
    int topo;
    int *dados;
};
void inicializa(pilha *p, int tam)
{
    //inicializando os dados da pilha
    p->base = -1;//(*p).base = -1
    p->topo = -1;
    p->tam = tam;
    p->dados = new int(tam);// aloca dinamicamente
}
bool cheia(pilha *p)
{
    if(p->topo == p->tam-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool vazia(pilha *p)
{
    if(p->topo == p->base)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool empilhar(pilha *p, int valor)
{
    if(cheia(p)) //caso a pilha está cheia
    {
        return false;//retorna false, pois não consegue incluir
    }
    else
    {
        p->topo++;
        p->dados[p->topo] = valor;
        return true;
    }
}
void mostrar(pilha *p)
{
    int x;
    cout<<" Mostrar Pilha: " << endl;
    cout<<" Tamanho: " << p->tam << endl;
    cout<<" Topo: " << p->topo << endl;
    for(x = p->topo; x > p->base; x--)
    {
        cout<<"  -------" << endl;
        cout<< x <<" |  " << p->dados[x] << "  | " << endl;
        cout<<"  ------ " << endl;
    }
}
int desempilhar2(pilha *p)
{
    int valor = p->dados[p->topo];
    p->dados[p->topo] = NULL;
    p->topo--;
    return valor;
}
int desempilhar(pilha *p)
{
    int valor = NULL;
    if(!vazia(p))
    {
        valor = p->dados[p->topo];
        p->dados[p->topo] = NULL;
        p->topo--;
    }
    return valor;
}
bool buscar(pilha *p, int valor)
{
    int x;
    for(x = p->topo; x > p->base; x--)
    {
        if(valor == p->dados[x])
        {
            return true;
            cout<<" O valor existe!" << endl;
        }
    }
    return false;
    cout<<" O valor  não existe!" << endl;
}
main()
{
    setlocale(LC_ALL,"Portuguese");
    int menu = -1,op;
    int v = 10;
    pilha pi;
    inicializa(&pi, v);
    do
    {
        cout<<" -- Mebu de Ações -- " << endl;
        cout<<" 0 - Sair " << endl;
        cout<<" 1 - Empilhar " << endl;
        cout<<" 2 - Desempilhar " << endl;
        cout<<" 3 - Buscar " << endl;
        cout<<" Escolha sua opção: " << endl;
        cin>>op;
        fflush(stdin);
        switch(op)
        {
        case 0:
            cout<<" O programa foi encerrado! " << endl;
            break;
        case 1:
            cout<<" Informe o valor para acrescentar a pilha: " << endl;
            cin>>v;
            empilhar(&pi, v);
            break;
        case 2:
            cout<<"Para retirar da pilha: " << endl;
            desempilhar(&pi);
            int valor2 = 0;
            valor2 = desempilhar(&pi);
            cout<<"\n O valor retirado foi: " << valor2 << endl;
            getchar();
            break;
        //case 3:
            //cout<<" Informe o valor para buscar da pilha: " << endl;
            //cin>>v;
           // buscar(&pi, v);
           //break;
       // default:
            //cout<<" Opção inválida! " << endl;
            //break;
        }
    }
    while(op != 0);
    mostrar(&pi);
}
