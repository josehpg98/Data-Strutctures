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

/* Função que mostra a informação da árvore em preordem raiz, sae, sad*/
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

/* Exibe arvore Em Ordem sae, raiz, sad*/
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
/* Exibe arvore Em posOrdem mesma descrição dos mostra anteriores sae, sad, raiz*/
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

/* Função que verifica se um elemento pertence ou não à árvore */
int verifica(arvore *t, int v) {

  if(testa_vazia(t)) { /* Se a árvore estiver vazia, então retorna 0 */
    return 0;
  }

  /* O operador lógico || interrompe a busca quando o elemento for encontrado */
  return t->info == v || verifica(t->sae, v) || verifica(t->sad, v);
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
        {   //possui filhos a direita e a esquerda
            aux = (*t)->sae;
            while(aux->sad != NULL)
            {
                aux = aux->sad;
            }
            (*t)->info = aux->info;/*faz a troca de lugar dos elementos*/
            aux->info = v;
            (*t)->sae = remover(&(*t)->sae, v);//chama a função novamente.
        }
    }
    return *t;
}

void mostra_paragrafacao(arvore *t, int nivel = -1)
{
  /* Essa função imprime os elementos de forma recursiva */
  if(!testa_vazia(t)) /* se a árvore não for vazia... */
  {
    /* Rotina para exibir a paragrafação, utiliza um contador
    para a cada nível que desce incrementa o contador */
    nivel++;
    cout << "\n"; //a cada nova chamada quebra a linha
    if (nivel > 0) //no nível 0 não precisa inserir ponto
      cout << ".";

    for (int i = 0; i < nivel; i++)
      cout << ".";//laço para escrever a quantidade de pontos conforme o nível

    cout << t->info; /* mostra a raiz */
    mostra_paragrafacao(t->sae, nivel); /* mostra a sae (subárvore à esquerda) */
    mostra_paragrafacao(t->sad, nivel); /* mostra a sad (subárvore à direita) */
  }
}

int conta_nivel (arvore *t)
{
    //função que encontra o maior nível existente na árvore
    if(t == NULL)
        return 0;
    int alt_esq = conta_nivel(t->sae);//percorre a árvore esquerda
    int alt_dir = conta_nivel(t->sad);//percorre a árvore direita
    if(alt_esq > alt_dir)
        return (alt_esq + 1); //contador da altura esquerda
    else
        return (alt_dir + 1); //contador da altura direita
}

void elemento_nivel(arvore *t, int cont, int nivel)
{
    //mostra os elementos de um determinado nível
    if(!testa_vazia(t))
    {
        cont++; //a cada chamada incrementa um contador
        if (cont == nivel) //verifica se o contador é igual ao nível desejado
            cout << t->info << ", "; //se for igual mostra o elemento
        elemento_nivel(t->sae, cont, nivel); //chamada recursiva percorrendo a árvore a esquerda
        elemento_nivel(t->sad, cont, nivel); //chamada recursiva percorrendo a árvore direita
    }
}

int qtd_folhas(arvore *t)
{
    //função que mostra os elementos folhas, conforme a árvore esquerda ou direita
    //é só ao chamar a função passar o endereço da sae ou da sad
    if(t == NULL)
        return 0;
    else if((t->sae == NULL) && (t->sad == NULL))//se não possui sae e sad é folha, retorna 1
      return 1;
    return(qtd_folhas(t->sae) + qtd_folhas(t->sad)); //executa a soma de 1 em 1 conforme é retornado
}

int main()
{
  arvore *t = cria_arvore(); /* cria uma árvore vazia */
  int menu = -1, num, nivel, flag = 0;
  do
  {
      system("cls");
      cout << "*-----------------------*" << endl;
      cout << "|    MENU DE OPCOES!!   |" << endl;
      cout << "*-----------------------*" << endl;
      cout << "| 0 - Sair              |" << endl;
      cout << "| 1 - Incluir           |" << endl;
      cout << "| 2 - Mostrar           |" << endl;
      cout << "| 3 - Consultar         |" << endl;
      cout << "| 4 - Remover           |" << endl;
      cout << "| 5 - Paragrafacao      |" << endl;
      cout << "| 6 - Elemento no nivel |" << endl;
      cout << "| 7 - qtd folhas        |" << endl;
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
                cout << "Informe o valor a ser consultado: ";
                cin >> num;
                fflush(stdin);
                if(verifica(t, num))
                    cout << "\nO numero " << num << " pertence a arvore!\n";
                else
                    cout << "\nO numero " << num << " NAO pertence a arvore!\n";

            }
            getchar();
            break;
        case 4:
            system("cls");
            if(testa_vazia(t)) /* Verifica se a árvore está vazia */
                cout << "\n\nArvore vazia!!\n";
            else
            {
                cout << "Informe o valor a ser removido: ";
                cin >> num;
                fflush(stdin);
                if(verifica(t, num))
                {
                    if(t->sae == NULL && t->sad == NULL)
                    {
                       delete (t);
                       t = NULL;
                    }
                    else
                       remover(&t, num);
                    cout << "VALOR REMOVIDO COM SUCESSO.";
                }
                else
                    cout << "\nO numero " << num << " NAO pertence a arvore!\n";
            }
            getchar();
            break;
        case 5:
            system("cls");
            if(testa_vazia(t)) /* Verifica se a árvore está vazia */
                cout << "\n\nArvore vazia!!\n";
            else
            {
                cout << "ELEMENTOS EM PARAGRAFACAO: " << endl;
                mostra_paragrafacao(t);
            }
            getchar();
            break;
        case 6:
            system("cls");
            if(testa_vazia(t)) /* Verifica se a árvore está vazia */
                cout << "\n\nArvore vazia!!\n";
            else
            {
                cout << "Indique o nivel desejado: " << endl;
                cin >> nivel;
                flag = conta_nivel(t);
                if(nivel >= flag)
                   cout << "Nao existe este nivel na arvore. \n";
                else
                {
                    cout << "Elementos no nivel " << nivel << ": ";
                    elemento_nivel(t, -1, nivel);
                }
                getchar();
            }
            getchar();
            break;
         case 7:
            system("cls");
            if(testa_vazia(t)) /* Verifica se a árvore está vazia */
                cout << "\n\nArvore vazia!!\n";
            else
            {
                cout << "ELEMENTOS NA ARVORE EM PRE-ORDEM: " << endl;
                mostra(t);
                cout << "\nQtd Folhas na SAE = " << qtd_folhas(t->sae) << endl;
                cout << "\nQtd Folhas na SAD = " << qtd_folhas(t->sad) << endl;
            }
            getchar();
            break;
      };
  }while (menu != 0);
}
