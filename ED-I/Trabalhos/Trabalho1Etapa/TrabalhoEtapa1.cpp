#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>
using namespace std;
#include "fila_dinamica_trabalho.hpp"
#include "pilha_dinamica_trabalho.hpp"
main()
{
    setlocale(LC_ALL,"Portuguese");
    Fila Estudantes;
    Fila Servidores;
    Pilha Vacinados;
    Registro reg;
    initQ(&Servidores);
    initQ(&Estudantes);
    init(&Vacinados);
    int op,menu = -1;
    bool teste;
    do
    {
        system("cls");
        cout<<" --- Menu de Ações Para vacinação Covid-19 do IFSUL - PF --- " << endl;
        cout<<" 0 - Sair. " << endl;
        cout<<" 1 - Incluir Pessoa. " << endl;
        cout<<" 2 - Vacinar. " << endl;
        cout<<" 3 - Listar Servidores Com Seu Número Total. " << endl;
        cout<<" 4 - Listar Estudantes Com Seu Número Total. " << endl;
        cout<<" 5 - Listar Todas as Pessoas vacinadas Com Seu Número Total. " << endl;
        cout<<" 6 - Listar Todos os Servidores vacinados Com Seu Número Total. " << endl;
        cout<<" 7 - Listar Todos os Estudantes vacinados Com Seu Número Total. " << endl;
        cout<<" 8 - Mostrar a Média de Idade das Pessoas Vacinadas. " << endl;
        cout<<" 9 - Mostrar Pessoas Vacinadas Com o Tipo de Vacina. " << endl;
        cout<<" 10 - Mostrar os Dados do Arquivo Texto. " << endl;
        cout<<" Escolha Uma Opção Listada Acima: " <<endl;
        cin>>op;
        fflush(stdin);
        switch(op)
        {
        case 0:
            cout<<"Programa Encerrado! " << endl;
            getchar();
            break;
        case 1:
            cout<<"Informe o nome da pessoa: " << endl;
            getline(cin,reg.nome);
            fflush(stdin);
            do
            {
                cout<<" Informe a idade da pessoa: " << endl;
                cin>>reg.idade;
                fflush(stdin);
            }
            while(reg.idade <= 0);
            cout<<"Informe a data de vacinação: " << endl;
            getline(cin,reg.data_vacinacao);
            fflush(stdin);
            do
            {
                cout<<"Informe a marca da vacina ( A - Astrazenecca | B - Butanvac | C - Coronavac ): " << endl;
                cin>>reg.marca_vacina;
                reg.marca_vacina = toupper(reg.marca_vacina);
                fflush(stdin);
                if(reg.marca_vacina == 'A' || reg.marca_vacina == 'B' || reg.marca_vacina == 'C')
                {
                    teste = true;
                }
                else
                {
                    teste = false;
                }
            }
            while(teste == false);
            do
            {
                cout<<"Informe o tipo da pessoa ( E - Estudante | S - Servidor): " << endl;
                cin>>reg.tipo_pessoa;
                reg.tipo_pessoa = toupper(reg.tipo_pessoa);
                fflush(stdin);
                if(reg.tipo_pessoa == 'E' || reg.tipo_pessoa == 'S')
                {
                    teste = true;
                }
                else
                {
                    teste = false;
                }
            }
            while(teste == false);
            if(reg.tipo_pessoa == 'E')
            {
                if (enqueue(&Estudantes, reg))
                {
                    cout<<"Pessoa do Tipo Estudante Incluída Com Sucesso!" << endl;
                    getchar();
                }
                else
                    cout<<"Fila de Estudantes está cheia, Não Foi Possível Incluir!" << endl;
                getchar();
            }
            if(reg.tipo_pessoa == 'S')
            {
                if (enqueue(&Servidores, reg))
                {
                    cout<<"Pessoa do Tipo Servidor Incluída Com Sucesso!" << endl;
                    getchar();
                }
                else
                    cout<<"Fila de Servidores está cheia, Não Foi Possível Incluir!" << endl;
                getchar();
            }
            getchar();
            break;
        case 2:
            if(verificavazia(&Servidores) == true)
            {
                dequeue(&Estudantes, &reg);
                cout<<"Estudante vacinado: " << endl;
                cout<<reg.nome << " | \t ";
                cout<<reg.idade << " | \t ";
                cout<<reg.data_vacinacao << " | \t ";
                cout<<reg.marca_vacina<< " | \t ";
                cout<<reg.tipo_pessoa << " | \t ";
                push(&Vacinados,reg);
            }
            else
            {
                dequeue(&Servidores, &reg);
                cout<<"Servidor vacinado: " << endl;
                cout<<reg.nome << " | \t ";
                cout<<reg.idade << " | \t ";
                cout<<reg.data_vacinacao << " | \t ";
                cout<<reg.marca_vacina<< " | \t ";
                cout<<reg.tipo_pessoa << " | \t ";
                push(&Vacinados,reg);
            }
        case 3:
            ListServidores(&Servidores);
            getchar();
            break;
        case 4:
            ListEstudantes(&Estudantes);
            getchar();
            break;
        case 5:
            ListVacinados(&Vacinados);
            getchar();
            break;
        case 6:
            ListServidoresVacinados(&Vacinados);
            getchar();
            break;
        case 7:
            ListEstudantesVacinados(&Vacinados);
            getchar();
            break;
        case 8:
            MediaIdade(&Vacinados);
            getchar();
            break;
        case 9:
            ListTipoVacina(&Vacinados);
            getchar();
            break;
        default:
            cout<<"Opção Inválida! " << endl;
            getchar();
            break;
        }
    }
    while(op != 0);
}
