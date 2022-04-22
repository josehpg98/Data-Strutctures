/// pilha_dinamica.hpp
typedef struct pilha
{
    No *topo;
} Pilha;
void init(Pilha *p)
{
    p->topo = NULL; ///pilha vazia
};
bool isEmpty(Pilha *p) /// verifica se a pilha est� vazia
{
    if (p->topo == NULL)
        return true;
    else
        return false;
};
bool push(Pilha *p, Registro registro) /// empilhar
{
    No *novo =  new No();
    if (!novo) /// sistema n�o conseguiu alocar a mem�ria
        return false;
    novo->reg = registro;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
};
bool pop(Pilha *p, Registro *reg) /// desempilhar
{
    if (isEmpty(p))
        return false;
    *reg = p->topo->reg; ///(*p).(*topo).reg
    No *apagar = p->topo;
    p->topo = p->topo->prox;
    delete apagar;
    return true;
};
void show(Pilha *p)
{
    No *no = p->topo;
    cout << "\n Pilha:  [ ";
    while (no != NULL)
    {
        //cout << no->reg.dado << "\t ";
        cout << no->reg.nome << " \t ";
        cout << no->reg.idade << " \t ";
        cout << no->reg.data_vacinacao << " \t ";
        cout << no->reg.marca_vacina<< " \t ";
        cout << no->reg.tipo_pessoa << " \t ";
        no = no->prox;
    }
    cout << " ] \n";
};
bool peek(Pilha* p, Registro *reg)
{
    if (p->topo != NULL)
    {
        *reg= p->topo->reg;
        return true;
    }
    else
        return false;
};
/* Exclui (e libera a mem�ria) de todos os elementos da PILHA */
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
};
void ListVacinados(Pilha *p)
{
    No *no = p->topo;
    int cont = 0;
    if(isEmpty(p) == true)
    {
        cout<<"A Pilha de Vacinadoos Est� Vazia! " << endl;
    }
    else
    {
        cout<<"Pilha de Pessoas Vacinadas e Seu Total:  [ ";
        while (no != NULL)
        {
            //cout << no->reg.dado << "\t ";
            cout<<no->reg.nome << " \t ";
            cout<<no->reg.idade << " \t ";
            cout<<no->reg.data_vacinacao << " \t ";
            cout<<no->reg.marca_vacina<< " \t ";
            cout<<no->reg.tipo_pessoa << " \t ";
            cont++;
            no = no->prox;
        }
        cout << " ] \n";
    }
    cout<<endl;
    cout<<"O N�mero de Vacinados �: " << cont << endl;
    cout<<endl;
};
void ListServidoresVacinados(Pilha *p)
{
    No *no = p->topo;
    int cont = 0;
    if(isEmpty(p) == true)
    {
        cout<<"A Pilha de Servidores Vacinadoos Est� Vazia! " << endl;
    }
    else
    {
        cout<<"Pilha de Servidores Vacinados e Seu Total:  [ ";
        while (no != NULL)
        {
            //cout << no->reg.dado << "\t ";
            if(no->reg.tipo_pessoa == 'S')
            {
                cout<<no->reg.nome << " \t ";
                cout<<no->reg.idade << " \t ";
                cout<<no->reg.data_vacinacao << " \t ";
                cout<<no->reg.marca_vacina<< " \t ";
                cout<<no->reg.tipo_pessoa << " \t ";
                cont++;
            }
            no = no->prox;
        }
        cout << " ] \n";
    }
    cout<<endl;
    cout<<"O N�mero de Servidores Vacinados �: " << cont << endl;
    cout<<endl;
};
void ListEstudantesVacinados(Pilha *p)
{
    No *no = p->topo;
    int cont = 0;
    if(isEmpty(p) == true)
    {
        cout<<"A Pilha de Estudantes Vacinadoos Est� Vazia! " << endl;
    }
    else
    {
        cout<<"Pilha de Estudantes Vacinados e Seu Total:  [ ";
        while (no != NULL)
        {
            //cout << no->reg.dado << "\t ";
            if(no->reg.tipo_pessoa == 'E')
            {
                cout<<no->reg.nome << " \t ";
                cout<<no->reg.idade << " \t ";
                cout<<no->reg.data_vacinacao << " \t ";
                cout<<no->reg.marca_vacina<< " \t ";
                cout<<no->reg.tipo_pessoa << " \t ";
                cont++;
            }
            no = no->prox;
        }
        cout << " ] \n";
    }
    cout<<endl;
    cout<<"O N�mero de Estudantes Vacinados �: " << cont << endl;
    cout<<endl;
};
void MediaIdade(Pilha *p)
{
    No *no = p->topo;
    int cont = 0, id = 0;
    float media;
    if(isEmpty(p) == true)
    {
        cout<<"A Pilha de Vacinadoos Est� Vazia, Portanto Sem M�dia de Idade dos Vacinados! " << endl;
    }
    else
    {
        while (no != NULL)
        {
            id += no->reg.idade;
            cont++;
            no = no->prox;
        }
    }
    media = (id / cont);
    cout<<endl;
    cout<<"A M�dia de Idade das Pessoas Vacinadas �: " << media << endl;
    cout<<endl;
};
void ListTipoVacina(Pilha *p)
{
    No *no = p->topo;
    int contA = 0,contB = 0,contC = 0;
    if(isEmpty(p) == true)
    {
        cout<<"A Pilha de Vacinadoos Est� Vazia! " << endl;
    }
    else
    {
        cout<<"Pilha de Pessoas Vacinadas Pela Marca e Seu Total:  [ ";
        cout<<endl;
        cout<<"Pessoas Vacinadas com Astrazenecca (A): " << endl;
        while (no != NULL)
        {
            //cout << no->reg.dado << "\t ";
            if(no->reg.marca_vacina == 'A')
            {

                cout<<no->reg.nome << " \t ";
                cout<<no->reg.idade << " \t ";
                cout<<no->reg.data_vacinacao << " \t ";
                cout<<no->reg.marca_vacina<< " \t ";
                cout<<no->reg.tipo_pessoa << " \t ";
                contA++;
            }
            no = no->prox;
        }
        cout<<endl;
        cout<<"Pessoas Vacinadas com Butanvac (B): " << endl;
        while (no != NULL)
        {
            //cout << no->reg.dado << "\t ";
            if(no->reg.marca_vacina == 'B')
            {

                cout<<no->reg.nome << " \t ";
                cout<<no->reg.idade << " \t ";
                cout<<no->reg.data_vacinacao << " \t ";
                cout<<no->reg.marca_vacina<< " \t ";
                cout<<no->reg.tipo_pessoa << " \t ";
                contB++;
            }
            no = no->prox;
        }
        cout<<endl;
        cout<<"Pessoas Vacinadas com Coronavac (C): " << endl;
        while (no != NULL)
        {
            //cout << no->reg.dado << "\t ";
            if(no->reg.marca_vacina == 'C')
            {

                cout<<no->reg.nome << " \t ";
                cout<<no->reg.idade << " \t ";
                cout<<no->reg.data_vacinacao << " \t ";
                cout<<no->reg.marca_vacina<< " \t ";
                cout<<no->reg.tipo_pessoa << " \t ";
                contC++;
            }
            no = no->prox;
        }
        cout << " ] \n";
    }
    cout<<endl;
    cout<<"O N�mero de Vacinados Com a Astranecca (A) �: " << contA << endl;
    cout<<"O N�mero deVacinados Com a Butanvac (B) �: " << contB << endl;
    cout<<"O N�mero de Vacinados Com a Coronavac (C) �: " << contC << endl;
    cout<<endl;
};
