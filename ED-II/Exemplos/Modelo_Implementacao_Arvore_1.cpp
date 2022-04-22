#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
/* Cada nó armazena três informações:
   nesse caso um número (num),
   ponteiro para subárvore à direita (sad)
   e ponteiro para subárvore à esquerda (sae).*/
typedef struct arv
{
  int info;
  arv *sad;
  arv *sae;
} arvore;

/* A estrutura da árvore é representada por um ponteiro
   para o nó raiz. Com esse ponteiro, temos acesso aos
   demais nós. */

/* Função que cria uma árvore e retorna um ponteiro do tipo árvore */
arvore* cria_arvore()
{
  /* Uma árvore é representada pelo endereço do nó raiz,
     essa função cria uma árvore com nenhum elemento,
     ou seja, cria uma árvore vazia, por isso retorna NULL. */
   return NULL;
}

/* Função que verifica se uma árvore é vazia */
int testa_vazia(arvore *t)
{
  /* Retorna 1 se a árvore for vazia e 0 caso contrário */
  if(t == NULL)
     return 1;
  if(t->info == NULL)
     return 1;
  return 0;
}

/* Função que mostra a informação da árvore em preordem */
void mostra(arvore *t)
{
  /* Essa função imprime os elementos de forma recursiva */
  cout << "<"; /* notação para organizar na hora de mostrar os elementos */
  if(!testa_vazia(t)) /* se a árvore não for vazia... */
  {
    /* Mostra os elementos em pré-ordem */
    cout << t->info; /* mostra a raiz */
    mostra(t->sae); /* mostra a sae (subárvore à esquerda) */
    mostra(t->sad); /* mostra a sad (subárvore à direita) */
  }
  cout << ">"; /* notação para organizar na hora de mostrar os elementos */
}

/* Exibe arvore Em Ordem*/
void mostra_2(arvore *t){
  cout << "<"; /* notação para organizar na hora de mostrar os elementos */
  if(!testa_vazia(t)) /* se a árvore não for vazia... */
  {
     mostra_2(t->sae);/* mostra a sae (subárvore à esquerda) */
     cout << t->info; /* mostra a raiz */
     mostra_2(t->sad);/* mostra a sad (subárvore à direita) */
  }
  cout << ">";/* notação para organizar na hora de mostrar os elementos */
}
/* Exibe arvore Em posOrdem mesma descrição dos mostra anteriores*/
void mostra_3(arvore *t){
  cout << "<";
  if(!testa_vazia(t))
  {
     mostra_3(t->sae);
     mostra_3(t->sad);
     cout << t->info;
  }
  cout << ">";
}


/* Função que insere um dado na árvore */
void inserir(arvore **t, int v)
{
  /* Essa função insere os elementos de forma recursiva */
  if(*t == NULL)
  {
    *t = new arvore; /* Aloca memória para a estrutura */
    (*t)->sae = NULL; /* Subárvore à esquerda é NULL */
    (*t)->sad = NULL; /* Subárvore à direita é NULL */
    (*t)->info = v; /* Armazena a informação */
  }
  else
  {
    if(v < (*t)->info) /* Se o número for menor então vai pra esquerda */
    {
      /* Percorre pela subárvore à esquerda */
      inserir(&(*t)->sae, v);
    }
    if(v >= (*t)->info) /* Se o número for maior então vai pra direita */
    {
      /* Percorre pela subárvore à direita */
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
            //é um nó folha
            delete(aux);
            (*t) = NULL;
        }
        else if((*t)->sae == NULL)
        {
            //só tem filho a direita
            (*t) = (*t)->sad;
            aux->sad = NULL;
            delete(aux);
            aux = NULL;
        }
        else if ((*t)->sad == NULL)
        {
            //só tem filho a esquerda
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


int main()
{
  arvore *t = cria_arvore(); /* cria uma árvore */
  arvore *no_pai;
  int menu = -1, num;
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
                cout << "\n\nArvore vazia!!\n";
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
      };
  }while (menu != 0);
}
