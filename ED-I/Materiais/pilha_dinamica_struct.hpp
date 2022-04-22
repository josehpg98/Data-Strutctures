typedef struct registro
{
    int codigo;
    string titulo;
    int tipo;  /// 1 - Gibi 2-Mangá
    int ano;

} Registro;

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
    string tipos[3] = {"", "Gibi", "Mangá"};

    No *no = p->topo;
    cout << "\n Revistas:  " << endl;
    while (no != NULL)
    {
        cout << no->reg.codigo << " " << no->reg.titulo <<
        "  " << tipos[no->reg.tipo] << "  " << no->reg.ano << endl;

        no = no->prox;
    }
}

void contar(Pilha *p)
{
    int gibi = 0;
    int manga = 0;
    int cont =0 ;
    No *no = p->topo;
    cout << "\n Revistas:  " << endl;
    while (no != NULL)
    {
        cont++;
        if (no->reg.tipo == 1)
            gibi++;
        else
            manga++;
        no = no->prox;
    }
    cout << "\n TOTAL: " << cont << endl;
    cout << "\n GIBI: " << gibi<< endl;
    cout << "\n MANGA: " << manga << endl;

}







