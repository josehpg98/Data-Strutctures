struct avioes
{

    int cod;
    int passageiros;
    string empresa;
};
struct Fila
{
    int tam;
    int f;
    int r;
    avioes  *dados;/// ponteiro para vetor que será alocado
};
void initQ(Fila *f, int tam) /// inicialização da fila
{
    f->tam = tam;
    f->f = -1;
    f->r = -1;
    f->dados = new avioes[tam];/// aloca memória para vetor
    for(int i =0 ;i < f->tam ; i++)
        f->dados[i].cod = NULL;
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
bool enqueue(Fila *f, avioes av) /// incluir valor na fila
{
    if (isFullQ(f))
        return false;
    if (f->r != f->tam -1)
        f->r++;
    else
        f->r = 0;
    f->dados[f->r] = av;
    return true;

}
avioes dequeue(Fila *f)  ///retira
{
    avioes valor = f->dados[f->f + 1];

    f->f++;
    if (f->f == f->r)
    {
        f->f = -1;
        f->r = -1;
    }
    if (f->f == f->tam - 1)
        f->f = -1;
    f->dados[f->f].cod = NULL;
    return valor;
}
avioes peekQ(Fila *f) /// onde for chamada verificar antes se não está vazia
{
    avioes valor = f->dados[f->f + 1];
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
            if (f->dados[i].cod != NULL)
                cout << "[" << i << "]" << f->dados[i].cod <<
                " " << f->dados[i].passageiros << " " <<
                  f->dados[i].empresa;
            else
                cout << "[" << i << "]";
            if (f->r == i)
                cout << " <-- RÉ";
            cout << endl;
        }
    }else
        cout << "\n Fila vazia!";
}
void contQ(struct Fila *fila)
{
    int i, cont=0;
    if( isEmptyQ(fila))
        cout << "Fila vazia";
    else
    {
        for(i = 0; i <= fila->tam; i++)
        {
            if (fila->dados[i].cod != NULL)
                cont++;
        }
        cout << "Voos esperando: " << cont << endl;
    }
}
