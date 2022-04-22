typedef int TIPOINFO;

typedef struct registro
{
    TIPOINFO dado;

} Registro;

typedef struct no
{
    Registro reg;
    no *prox;
}No;

typedef struct fila
{
    No *frente;
    No *re;
} Fila;

/// funções: initQ, enqueue, dequeue, showQ,  resetQ, peekQ

void initQ(Fila *f)
{
    f->frente = NULL;
    f->re = NULL;
}

bool enqueue(Fila *f, Registro reg)
{
    No *novo = new No();
    if (novo == NULL) /// não conseguiu alocar memória
        return false;
    novo->reg = reg;
    novo->prox = NULL;
    if (f->frente == NULL)/// fila estava vazia
        f->frente = novo;
    else
        f->re->prox = novo;
    f->re = novo;
    return true;
}


bool dequeue(Fila *f, Registro *reg = NULL)
{
    if (f->frente == NULL)
        return false;
    if (reg != NULL)
        *reg = f->frente->reg;
    No *apagar = f->frente;
    f->frente = f->frente->prox; /// atualiza a frente da fila
    delete(apagar); /// apagar elemento
    if (f->frente == NULL)
        f->re = NULL;
    return true;
}

void showQ(Fila *f)/// mostrar a fila
{
    No *nodo = f->frente;
    cout << "\nFila: " << endl;
    while(nodo != NULL)
    {
        cout << nodo->reg.dado << " \t ";
        nodo = nodo->prox;
    }
    cout << "\n";
}


No *peekQ(Fila *f)
{
    No *nodo = f->frente;
    return nodo;
}

void resetQ(Fila *f) ///excluir todos os nodos da fila - liberar memória
{
    No *nodo = f->frente;
    while (nodo != NULL)
    {
        No *apagar = nodo;
        nodo = nodo->prox;
        delete(apagar);
    }
    f->frente = NULL;
    f->re = NULL;
}









