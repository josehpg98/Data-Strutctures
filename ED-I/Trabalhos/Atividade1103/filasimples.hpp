struct Fila//queue
{
    int tam;
    int frente;
    int re;
    int *dados;//ponteiro do vetor que será alocado
};
void iniciaQ(Fila *f, int tam) //inicializa a fila
{
    f->tam = tam;
    f->frente = -1;
    f->re = -1;
    f->dados = new int[tam];//aloca a memória para o vetor
};
bool vazia(Fila *f)//isempty
{
    if(f->re == f->frente)
    {
        cout<<"A fila está vazia! " << endl;
        getchar();
        return true;
    }
    else
    {
        return false;
    }
};
bool cheia(Fila *f)//isfull
{
    if(f->re == f->tam -1)
    {
        cout<<"A fila está cheia! " << endl;
        getchar();
        return true;
    }
    else
    {
        return false;
    }
};
bool incluir(Fila *f,int valor) //inqueue
{
    if(cheia(f))
    {
        return false;
    }
    else
    {
        f->re++;//avança na ré
        f->dados[f->re] = valor;//atribui valor na posição da fila
        //f->dados[f->frente] = NULL;
        return true;
    }
};
int retira(Fila *f) //dequeue
{
    int valor = f->dados[f->frente + 1];
    f->frente++;
    return valor;
};
int peek(Fila *f)
{
    int valor = f->dados[f->frente + 1];
    return valor;
};
void mostrafila(Fila *f)
{
    cout<<endl;
    cout<<" Mostra Fila!" << endl;
    cout<<" Frente: " << f->frente << endl;
    cout<<" Ré: " << f->re << endl;
    cout<<" Tamanho: " << f->tam << endl;
    cout<<endl;
    cout<<endl;
    if(!vazia(f))
    {
        cout<<"Frente" << endl;
        for(int i = f->frente + 1; i <= f->re; i++)
        {
            cout<<" [ " << i << " ] " << f->dados[i];
            cout<<endl;
            if(f->re == i)
            {
                cout<<" --> Ré";

            }
        }
    }
    else
    {
        cout<<"Fila Vazia!" << endl;
    }
};
