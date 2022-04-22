#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
/* Cada n� armazena tr�s informa��es:
   nesse caso um n�mero (num),
   ponteiro para sub�rvore � direita (sad)
   e ponteiro para sub�rvore � esquerda (sae).*/
typedef struct arv
{
  int info;
  arv *sad;
  arv *sae;
} arvore;

/* A estrutura da �rvore � representada por um ponteiro
   para o n� raiz. Com esse ponteiro, temos acesso aos
   demais n�s. */

/* Fun��o que cria uma �rvore e retorna um ponteiro do tipo �rvore */
arvore* cria_arvore()
{
  /* Uma �rvore � representada pelo endere�o do n� raiz,
     essa fun��o cria uma �rvore com nenhum elemento,
     ou seja, cria uma �rvore vazia, por isso retorna NULL. */
   return NULL;
}

/* Fun��o que verifica se uma �rvore � vazia */
int testa_vazia(arvore *t)
{
  /* Retorna 1 se a �rvore for vazia e 0 caso contr�rio */
  if(t == NULL)
     return 1;
  if(t->info == NULL)
     return 1;
  return 0;
}

/* Fun��o que mostra a informa��o da �rvore em preordem raiz, sae, sad*/
void mostra(arvore *t)
{
  /* Essa fun��o imprime os elementos de forma recursiva */
  cout << "<"; /* nota��o para organizar na hora de mostrar os elementos */
  if(!testa_vazia(t)) /* se a �rvore n�o for vazia... */
  {
    /* Mostra os elementos em pr�-ordem */
    cout << t->info; /* mostra a raiz */
    mostra(t->sae); /* mostra a sae (sub�rvore � esquerda) */
    mostra(t->sad); /* mostra a sad (sub�rvore � direita) */
  }
  cout << ">"; /* nota��o para organizar na hora de mostrar os elementos */
}

/* Exibe arvore Em Ordem sae, raiz, sad*/
void mostra_2(arvore *t){
  cout << "<"; /* nota��o para organizar na hora de mostrar os elementos */
  if(!testa_vazia(t)) /* se a �rvore n�o for vazia... */
  {
     mostra_2(t->sae);/* mostra a sae (sub�rvore � esquerda) */
     cout << t->info; /* mostra a raiz */
     mostra_2(t->sad);/* mostra a sad (sub�rvore � direita) */
  }
  cout << ">";/* nota��o para organizar na hora de mostrar os elementos */
}
/* Exibe arvore Em posOrdem mesma descri��o dos mostra anteriores sae, sad, raiz*/
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


/* Fun��o que insere um dado na �rvore */
void inserir(arvore **t, int v)
{
  /* Essa fun��o insere os elementos de forma recursiva */
  if(*t == NULL)
  {
    *t = new arvore; /* Aloca mem�ria para a estrutura */
    (*t)->sae = NULL; /* Sub�rvore � esquerda � NULL */
    (*t)->sad = NULL; /* Sub�rvore � direita � NULL */
    (*t)->info = v; /* Armazena a informa��o */
  }
  else
  {
    if(v < (*t)->info) /* Se o n�mero for menor ent�o vai pra esquerda */
    {
      /* Percorre pela sub�rvore � esquerda */
      inserir(&(*t)->sae, v);
    }
    if(v >= (*t)->info) /* Se o n�mero for maior ent�o vai pra direita */
    {
      /* Percorre pela sub�rvore � direita */
      inserir(&(*t)->sad, v);
    }
  }
}

/* Fun��o que verifica se um elemento pertence ou n�o � �rvore */
int verifica(arvore *t, int v) {

  if(testa_vazia(t)) { /* Se a �rvore estiver vazia, ent�o retorna 0 */
    return 0;
  }

  /* O operador l�gico || interrompe a busca quando o elemento for encontrado */
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
            //� um n� folha
            delete(aux);
            (*t) = NULL;
        }
        else if((*t)->sae == NULL)
        {
            //s� tem filho a direita
            (*t) = (*t)->sad;
            aux->sad = NULL;
            delete(aux);
            aux = NULL;
        }
        else if ((*t)->sad == NULL)
        {
            //s� tem filho a esquerda
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
            (*t)->sae = remover(&(*t)->sae, v);//chama a fun��o novamente.
        }
    }
    return *t;
}

void mostra_paragrafacao(arvore *t, int nivel = -1)
{
  /* Essa fun��o imprime os elementos de forma recursiva */
  if(!testa_vazia(t)) /* se a �rvore n�o for vazia... */
  {
    /* Rotina para exibir a paragrafa��o, utiliza um contador
    para a cada n�vel que desce incrementa o contador */
    nivel++;
    cout << "\n"; //a cada nova chamada quebra a linha
    if (nivel > 0) //no n�vel 0 n�o precisa inserir ponto
      cout << ".";

    for (int i = 0; i < nivel; i++)
      cout << ".";//la�o para escrever a quantidade de pontos conforme o n�vel

    cout << t->info; /* mostra a raiz */
    mostra_paragrafacao(t->sae, nivel); /* mostra a sae (sub�rvore � esquerda) */
    mostra_paragrafacao(t->sad, nivel); /* mostra a sad (sub�rvore � direita) */
  }
}

int conta_nivel (arvore *t)
{
    //fun��o que encontra o maior n�vel existente na �rvore
    if(t == NULL)
        return 0;
    int alt_esq = conta_nivel(t->sae);//percorre a �rvore esquerda
    int alt_dir = conta_nivel(t->sad);//percorre a �rvore direita
    if(alt_esq > alt_dir)
        return (alt_esq + 1); //contador da altura esquerda
    else
        return (alt_dir + 1); //contador da altura direita
}

void elemento_nivel(arvore *t, int cont, int nivel)
{
    //mostra os elementos de um determinado n�vel
    if(!testa_vazia(t))
    {
        cont++; //a cada chamada incrementa um contador
        if (cont == nivel) //verifica se o contador � igual ao n�vel desejado
            cout << t->info << ", "; //se for igual mostra o elemento
        elemento_nivel(t->sae, cont, nivel); //chamada recursiva percorrendo a �rvore a esquerda
        elemento_nivel(t->sad, cont, nivel); //chamada recursiva percorrendo a �rvore direita
    }
}

int qtd_folhas(arvore *t)
{
    //fun��o que mostra os elementos folhas, conforme a �rvore esquerda ou direita
    //� s� ao chamar a fun��o passar o endere�o da sae ou da sad
    if(t == NULL)
        return 0;
    else if((t->sae == NULL) && (t->sad == NULL))//se n�o possui sae e sad � folha, retorna 1
      return 1;
    return(qtd_folhas(t->sae) + qtd_folhas(t->sad)); //executa a soma de 1 em 1 conforme � retornado
}

int main()
{
  arvore *t = cria_arvore(); /* cria uma �rvore vazia */
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
            if(testa_vazia(t)) /* Verifica se a �rvore est� vazia */
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
            if(testa_vazia(t)) /* Verifica se a �rvore est� vazia */
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
            if(testa_vazia(t)) /* Verifica se a �rvore est� vazia */
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
            if(testa_vazia(t)) /* Verifica se a �rvore est� vazia */
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
            if(testa_vazia(t)) /* Verifica se a �rvore est� vazia */
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
            if(testa_vazia(t)) /* Verifica se a �rvore est� vazia */
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
