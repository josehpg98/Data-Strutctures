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
/* Fun��o que mostra a informa��o da �rvore em preordem */
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
/* Exibe arvore Em Ordem*/
void mostra_2(arvore *t)
{
    cout << "<"; /* nota��o para organizar na hora de mostrar os elementos */
    if(!testa_vazia(t)) /* se a �rvore n�o for vazia... */
    {
        mostra_2(t->sae);/* mostra a sae (sub�rvore � esquerda) */
        cout << t->info; /* mostra a raiz */
        mostra_2(t->sad);/* mostra a sad (sub�rvore � direita) */
    }
    cout << ">";/* nota��o para organizar na hora de mostrar os elementos */
}
/* Exibe arvore Em posOrdem mesma descri��o dos mostra anteriores*/
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
    //fun��o que encontra o maior n�vel existente na �rvore
    if(t == NULL)
        return 0;
    int altesq = conta_alt_esq(t->sae);//percorre a �rvore esquerda
    int altdir = conta_alt_esq(t->sad);//percorre a �rvore direita
    if(altesq > altdir)
        return (altesq + 1); //contador da altura esquerda
    else
        return (altdir + 1); //contador da altura direita
}
int conta_alt_dir(arvore *t)
{
    //fun��o que encontra o maior n�vel existente na �rvore
    if(t == NULL)
        return 0;
    int altesq = conta_alt_dir(t->sae);//percorre a �rvore esquerda
    int altdir = conta_alt_dir(t->sad);//percorre a �rvore direita
    if(altdir < altesq)
        return (altdir + 1); //contador da altura esquerda
    else
        return (altesq + 1); //contador da altura direita
}
int conta_alt(arvore *t)
{
    //fun��o que encontra o maior n�vel existente na �rvore
    if(t == NULL)
        return 0;
    int altesq = conta_alt_esq(t);
    int altdir = conta_alt_dir(t);
    if(altesq >= altdir)
    {
        return altesq;
    }
    else
    {
        return altdir;
    }
}
int verifica_nos_informado(arvore *t, int v)
{
    if(!t)
        return 0;
    if(t->info > v)
        return 1 + (verifica_nos_informado(t->sae, v) + verifica_nos_informado(t->sad, v));
    else
        return (verifica_nos_informado(t->sae, v) + verifica_nos_informado(t->sad, v));
}
void mostra_par(arvore *t)
{
    cout << "<"; /* nota��o para organizar na hora de mostrar os elementos */
    if(!testa_vazia(t)) /* se a �rvore n�o for vazia... */
    {
        if(t->info % 2 == 0){
        //mostra_par(t->sae);/* mostra a sae (sub�rvore � esquerda) */
        cout<<t->info; /* mostra a raiz */
        mostra_par(t->sae);/* mostra a sae (sub�rvore � esquerda) */
        mostra_par(t->sad);/* mostra a sad (sub�rvore � direita) */
        }
    }
    cout << ">";/* nota��o para organizar na hora de mostrar os elementos */
}
void mostra_impar(arvore *t)
{
    cout << "<"; /* nota��o para organizar na hora de mostrar os elementos */
    if(!testa_vazia(t)) /* se a �rvore n�o for vazia... */
    {
        if(t->info % 2 != 0){
        //mostra_par(t->sae);/* mostra a sae (sub�rvore � esquerda) */
        cout<<t->info; /* mostra a raiz */
        mostra_impar(t->sae);/* mostra a sae (sub�rvore � esquerda) */
        mostra_impar(t->sad);/* mostra a sad (sub�rvore � direita) */
        }
    }
    cout << ">";/* nota��o para organizar na hora de mostrar os elementos */
}
