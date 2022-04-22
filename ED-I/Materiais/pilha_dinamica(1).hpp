
/// pilha_dinamica.hpp

typedef struct registro
{
    int dado;
} Registro;
/**
struct registro
{
    int dado;
}
*/
typedef struct no
{
    Registro reg;
    no *prox;
} No;

typedef struct pilha
{
    No *topo;
} Pilha;

void init(Pilha *p)
{
    p->topo = NULL; ///pilha vazia
}

bool isEmpty(Pilha *p) /// verifica se a pilha está vazia
{
    if (p->topo == NULL)
        return true;
    else
        return false;
}

bool push(Pilha *p, Registro registro) /// empilhar
{
    No *novo =  new No();
    if (!novo) /// sistema não conseguiu alocar a memória
        return false;
    novo->reg = registro;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

bool pop (Pilha *p, Registro *reg) /// desempilhar
{
    if (isEmpty(p))
        return false;
    *reg = p->topo->reg; ///(*p).(*topo).reg
    No *apagar = p->topo;
    p->topo = p->topo->prox;
    delete apagar;
    return true;
}

void show(Pilha *p)
{
    No *no = p->topo;
    cout << "\n Pilha:  [ ";
    while (no != NULL)
    {
        cout << no->reg.dado << "\t ";
        no = no->prox;
    }
    cout << " ] \n";
}

bool peek(Pilha* p, Registro *reg)
{
    if (p->topo != NULL)
    {
        *reg= p->topo->reg;
        return true;
    }
    else
        return false;
}


/* Exclui (e libera a memória) de todos os elementos da PILHA */
void reset(Pilha* p)
{
    No *apagar;
    No *posicao = p->topo;
    while (posicao != NULL)
    {
        apagar = posicao;
        posicao = posicao->prox;
        delete apagar;
    }
    p->topo = NULL;
}



/* Retornar o tamanho da pilha (numero de elementos) */
int sizePilha(Pilha* p)
{
    No *no = p->topo;
    int tam = 0;
    while (no!= NULL)
    {
        tam++;
        no = no->prox;
    }
    return tam;
}


/*Retornar o tamanho em bytes da pilha. Neste caso, isto depende do número
   de elementos que estao sendo usados.   */
int sizeBytes(Pilha* p)
{
    cout << ">> Tamanho de cada elemento " << sizeof(Registro) << endl;
    cout << ">> tamanho do topo  " << sizeof(Pilha) << endl;

    return(sizePilha(p)*sizeof(Registro))+sizeof(Pilha);
    // sizeof(PILHA) = sizeof(PONT) pois a "PILHA" eh um ponteiro para o 1o elemento
}



