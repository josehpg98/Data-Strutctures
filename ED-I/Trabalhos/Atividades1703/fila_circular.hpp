
struct Fila
{
    int tam;
    int f;
    int r;
    int *dados;/// ponteiro para vetor que será alocado
};

void initQ(Fila *f, int tam) /// inicialização da fila
{
    f->tam = tam;
    f->f = -1;
    f->r = -1;
    f->dados = new int[tam];/// aloca memória para vetor
    for(int i =0 ;i < f->tam ; i++)
        f->dados[i] = NULL;
}

bool isEmptyQ(Fila *f)
{
    if (f->r == f->f) /// fila vazia
        return true;
    else
        return false;
}

bool isFullQ(Fila *f)
{
    if (((f->r == f->tam - 1) && (f->f <= 0)) ||
       ((f->r != f->tam - 1) && (f->r + 1 == f->f)))
        return true;
    else
        return false;
}

bool enqueue(Fila *f, int valor) /// incluir valor na fila
{
    if (isFullQ(f))
        return false;
    if (f->r != f->tam -1)
        f->r++; /// avança a ré
    else
        f->r = 0;
    f->dados[f->r] = valor; /// atribui valor
    return true;

}

int dequeue(Fila *f)  ///retirar da fila
{
    int valor = f->dados[f->f + 1];

    f->f++;
    if (f->f == f->r)
    {
        f->f = -1;
        f->r = -1;
    }
    if (f->f == f->tam - 1)
        f->f = -1;
    f->dados[f->f] = NULL;
    return valor;
}

int peekQ(Fila *f) /// onde for chamada verificar antes se não está vazia
{
    int valor = f->dados[f->f + 1];
    return valor;
}

void showQ(Fila *f)
{
    cout << "Fila: " << endl;
    cout << "Frente: " << f->f << endl;
    cout << "Ré: " << f->r << endl;
    int i;
    if (!isEmptyQ(f))
    {
        for(i = 0; i < f->tam; i++)
        {
            if (f->dados[i] != NULL)
                cout << "[" << i << "]" << f->dados[i];
            else
                cout << "[" << i << "]";
            if (f->r == i)
                cout << " <-- RÉ";
            cout << endl;
        }
    }else
        cout << "\n Fila vazia!";
}


