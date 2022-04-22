typedef struct registro//registra os dados/inform��es
{
    string nome;
    int idade;
    string data_vacinacao;
    char marca_vacina;
    char tipo_pessoa;
} Registro;
typedef struct no//nodo/elemento
{
    Registro reg;//contem dados
    no *prox;//proximo endere�o
} No;
typedef struct fila
{
    No *frente;
    No *re;
} Fila;
/// fun��es: initQ, enqueue, dequeue, showQ,  resetQ, peekQ
void initQ(Fila *f)
{
    f->frente = NULL;
    f->re = NULL;
};
bool enqueue(Fila *f, Registro reg)//incluir na fila
{
    No *novo = new No();
    if (novo == NULL) /// n�o conseguiu alocar na mem�ria
        return false;
    novo->reg = reg;//atualiaza a informa��o de registro e proximo no
    novo->prox = NULL;
    //controle de iiga��o
    if (f->frente == NULL)/// fila estava vazia
        f->frente = novo;
    else
        f->re->prox = novo;//re recebe o endreco do proximo  no
    f->re = novo;// r� recebe o novo n�, atualizando a r�
    return true;
};
bool verificavazia(Fila *f)
{
    if(f->frente == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
};
bool dequeue(Fila *f, Registro *reg = NULL)//retirar
{
    if (f->frente == NULL)//fila est� vazia
        return false;
    if (reg != NULL)//passou o ponteiro do registro
        *reg = f->frente->reg;//registro recebe o rgistro atras dele
    No *apagar = f->frente;//vai para ser apagado
    f->frente = f->frente->prox; /// atualiza a frente da fila
    delete(apagar); /// apagar elemento
    if (f->frente == NULL)//se a fila ficou vazia
        f->re = NULL;//r� recebe nulo
    return true;
};
void showQ(Fila *f)/// mostrar a fila
{
    No *nodo = f->frente;//come�a pela frente
    cout << "\nFila: " << endl;
    while(nodo != NULL)//ennquenato n�o for nulo
    {
        cout << nodo->reg.nome << " | \t ";
        cout << nodo->reg.idade << " | \t ";
        cout << nodo->reg.data_vacinacao << " | \t ";
        cout << nodo->reg.marca_vacina<< " | \t ";
        cout << nodo->reg.tipo_pessoa << " | \t ";
        nodo = nodo->prox;//recebe o proximo da fila
    }
    cout << "\n";
};
No *peekQ(Fila *f)
{
    No *nodo = f->frente;//recebe o nodo da frente e mostra
    return nodo;
};
void resetQ(Fila *f) ///excluir todos os nodos da fila - liberar mem�ria
{
    No *nodo = f->frente;
    while (nodo != NULL)
    {
        No *apagar = nodo;//recebe apagar
        nodo = nodo->prox;//faz a liaga��o
        delete(apagar);//deleta
    }
    f->frente = NULL;//ap�s zera a frente e r�
    f->re = NULL;
};
int contQ(Fila *f)
{
    No *nodo = f->frente;
    int cont = 0;
    while (nodo != NULL)
    {
        cont++;
        nodo = nodo->prox;
    }
    return cont;
};
void ListServidores(Fila *f)///Lista servidores com seu numero total
{
    No *nodo = f->frente;//come�a pela frente
    int cont = 0;
    if(verificavazia(f) == true)
    {
        cout<<"Fila de Servidores Est� Vazia! " << endl;
    }
    else
    {
        cout<<"Fila de Servidores com N�mero Total: " << endl;
        while(nodo != NULL)//ennquenato n�o for nulo
        {
            if(nodo->reg.tipo_pessoa == 'S')
            {
                cout << nodo->reg.nome << " | \t ";
                cout << nodo->reg.idade << " | \t ";
                cout << nodo->reg.data_vacinacao << " | \t ";
                cout << nodo->reg.marca_vacina<< " | \t ";
                cout << nodo->reg.tipo_pessoa << " | \t ";
                cont++;
            }
            nodo = nodo->prox;//recebe o proximo da fila
        }
    }
    cout<<endl;
    cout<<" N�mero Total de Servidores: " << cont << endl;
    cout<<endl;
    getchar();
};
void ListEstudantes(Fila *f)///Lista servidores com seu numero total
{
    No *nodo = f->frente;//come�a pela frente
    int cont = 0;
    if(verificavazia(f) == true)
    {
          cout<<"Fila de Estudantes Est� Vazia! " << endl;
    }
    else
    {
        cout<<"Fila de Estudantes com N�mero Total: " << endl;
        while(nodo != NULL)//ennquenato n�o for nulo
        {
            if(nodo->reg.tipo_pessoa == 'E')
            {
                cout << nodo->reg.nome << " | \t ";
                cout << nodo->reg.idade << " | \t ";
                cout << nodo->reg.data_vacinacao << " | \t ";
                cout << nodo->reg.marca_vacina<< " | \t ";
                cout << nodo->reg.tipo_pessoa << " | \t ";
                cont++;
            }
            nodo = nodo->prox;//recebe o proximo da fila
        }
    }
    cout<<endl;
    cout<<" N�mero Total de Estudantes: " << cont << endl;
    cout<<endl;
    getchar();
};
