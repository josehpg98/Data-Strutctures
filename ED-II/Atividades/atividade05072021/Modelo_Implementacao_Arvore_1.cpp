#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
/* Cada n? armazena tr?s informa??es:
   nesse caso um n?mero (num),
   ponteiro para sub?rvore ? direita (sad)
   e ponteiro para sub?rvore ? esquerda (sae).*/
typedef struct arv
{
    int info;
    arv *sad;
    arv *sae;
} arvore;
/* A estrutura da ?rvore ? representada por um ponteiro
   para o n? raiz. Com esse ponteiro, temos acesso aos
   demais n?s. */
/* Fun??o que cria uma ?rvore e retorna um ponteiro do tipo ?rvore */
arvore* cria_arvore()
{
    /* Uma ?rvore ? representada pelo endere?o do n? raiz,
       essa fun??o cria uma ?rvore com nenhum elemento,
       ou seja, cria uma ?rvore vazia, por isso retorna NULL. */
    return NULL;
}
/* Fun??o que verifica se uma ?rvore ? vazia */
int testa_vazia(arvore *t)
{
    /* Retorna 1 se a ?rvore for vazia e 0 caso contr?rio */
    if(t == NULL)
        return 1;
    if(t->info == NULL)
        return 1;
    return 0;
}
/* Fun??o que mostra a informa??o da ?rvore em preordem */
void mostra(arvore *t)
{
    /* Essa fun??o imprime os elementos de forma recursiva */
    cout << "<"; /* nota??o para organizar na hora de mostrar os elementos */
    if(!testa_vazia(t)) /* se a ?rvore n?o for vazia... */
    {
        /* Mostra os elementos em pr?-ordem */
        cout << t->info; /* mostra a raiz */
        mostra(t->sae); /* mostra a sae (sub?rvore ? esquerda) */
        mostra(t->sad); /* mostra a sad (sub?rvore ? direita) */
    }
    cout << ">"; /* nota??o para organizar na hora de mostrar os elementos */
}
/* Exibe arvore Em Ordem*/
void mostra_2(arvore *t)
{
    cout << "<"; /* nota??o para organizar na hora de mostrar os elementos */
    if(!testa_vazia(t)) /* se a ?rvore n?o for vazia... */
    {
        mostra_2(t->sae);/* mostra a sae (sub?rvore ? esquerda) */
        cout << t->info; /* mostra a raiz */
        mostra_2(t->sad);/* mostra a sad (sub?rvore ? direita) */
    }
    cout << ">";/* nota??o para organizar na hora de mostrar os elementos */
}
/* Exibe arvore Em posOrdem mesma descri??o dos mostra anteriores*/
void mostra_3(arvore *t)
{
    cout << "<";
    if(!testa_vazia(t))
    {
        mostra_3(t->sae);
        mostra_3(t->sad);
        cout << t->info;
    }
    cout << ">";
}
/* Fun??o que insere um dado na ?rvore */
void inserir(arvore **t, int v)
{
    /* Essa fun??o insere os elementos de forma recursiva */
    if(*t == NULL)
    {
        *t = new arvore; /* Aloca mem?ria para a estrutura */
        (*t)->sae = NULL; /* Sub?rvore ? esquerda ? NULL */
        (*t)->sad = NULL; /* Sub?rvore ? direita ? NULL */
        (*t)->info = v; /* Armazena a informa??o */
    }
    else
    {
        if(v < (*t)->info) /* Se o n?mero for menor ent?o vai pra esquerda */
        {
            /* Percorre pela sub?rvore ? esquerda */
            inserir(&(*t)->sae, v);
        }
        if(v >= (*t)->info) /* Se o n?mero for maior ent?o vai pra direita */
        {
            /* Percorre pela sub?rvore ? direita */
            inserir(&(*t)->sad, v);
        }
    }
}
arvore* remover(arvore **t, int v)
{
    if(v < (*t)->info)
        remover(&(*t)->sae, v);
    else if(v > (*t)->info)
        remover(&(*t)->sad, v);
    else
    {
        //achou o elemento a ser removido
        arvore *aux = *t;
        if(((*t)->sae == NULL) && ((*t)->sad == NULL))
        {
            //? um n? folha
            delete(aux);
            (*t) = NULL;
        }
        else if((*t)->sae == NULL)
        {
            //s? tem filho a direita
            (*t) = (*t)->sad;
            aux->sad = NULL;
            delete(aux);
            aux = NULL;
        }
        else if ((*t)->sad == NULL)
        {
            //s? tem filho a esquerda
            (*t) = (*t)->sae;
            aux->sae = NULL;
            delete(aux);
            aux = NULL;
        }
        else
        {
            aux = (*t)->sae;
            while(aux->sad != NULL)
            {
                aux = aux->sad;
            }
            (*t)->info = aux->info;
            aux->info = v;
            (*t)->sae = remover(&(*t)->sae, v);
        }
    }
    return *t;
}
int consulta(arvore *t,int vl)
{
    setlocale(LC_ALL,"Portuguese");
    int nivel,res;
    if(!testa_vazia(t))
    {
        if(t->info == vl)
        {
            res = 1;
            return res;
        }
        else if(consulta(t->sae,vl))
        {
            res = 1;
            return res;
        }
        else if(consulta(t->sad,vl))
        {
            res = 1;
            return res;
        }
        else
        {
            res = 0;
            return res;
        }
    }
}
int conta_alt_esq(arvore *t)
{
    //fun??o que encontra o maior n?vel existente na ?rvore
    if(t == NULL)
        return 0;
    int altesq = conta_alt_esq(t->sae);//percorre a ?rvore esquerda
    int altdir = conta_alt_esq(t->sad);//percorre a ?rvore direita
    if(altesq > altdir)
        return (altesq + 1); //contador da altura esquerda
    else
        return (altdir + 1); //contador da altura direita
}
int conta_alt_dir(arvore *t)
{
    //fun??o que encontra o maior n?vel existente na ?rvore
    if(t == NULL)
        return 0;
    int altesq = conta_alt_dir(t->sae);//percorre a ?rvore esquerda
    int altdir = conta_alt_dir(t->sad);//percorre a ?rvore direita
    if(altdir < altesq)
        return (altdir + 1); //contador da altura esquerda
      else
        return (altesq + 1); //contador da altura direita
}
int conta_alt(arvore *t)
{
    //fun??o que encontra o maior n?vel existente na ?rvore
    if(t == NULL)
        return 0;
    int altesq = conta_alt_esq(t);
    int altdir = conta_alt_dir(t);
    if(altesq >= altdir){
        return altesq;
    }else{
        return altdir;
    }
}
int main()
{
    arvore *t = cria_arvore(); /* cria uma ?rvore */
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
            if(testa_vazia(t)) /* Verifica se a ?rvore est? vazia */
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
            if(testa_vazia(t)) /* Verifica se a ?rvore est? vazia */
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

                cout<<"Valor Est? na arvore " << endl;
            }
            else
            {
                cout<<" O valor N?o Est? na arvore! " << endl;
            }
            getchar();
            break;
        case 5:
            alse = conta_alt_esq(t);
            cout<<"A altura da arvore a esquerda ?:" << alse << endl;
            getchar();
            break;
        case 6:
            alsd = conta_alt_dir(t);
            cout<<"A altura da arvore a direita ?:" << alsd << endl;
            getchar();
            break;
         case 7:
            alv = conta_alt(t);
            cout<<"A altura da arvore ?:" << alv << endl;
            getchar();
            break;
        };
    }
    while (menu != 0);
}
