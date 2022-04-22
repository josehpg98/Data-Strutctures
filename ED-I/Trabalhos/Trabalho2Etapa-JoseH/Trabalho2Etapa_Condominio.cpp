#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<locale.h>
#include<string>
#include<sstream>
using namespace std;
#include "ListaCondominio.hpp"
main()
{
    setlocale(LC_ALL,"Portuguese");
    Lista_Moradores *LM = new Lista_Moradores();
    Lista_Casa *LC = new Lista_Casa();
    Moradores mo;
    Casa ca;
    string linha, dado;
    string tipo = "";
    ifstream leitura;
    int menu = 0,cont = 0,quant_moradores = 0,contNM = 1,op;
    leitura.open("Listatrabalho.txt");
    if(leitura.is_open())
    {
        cout<<"Arquivo Texto Aberto Com Sucesso! " << endl;
        getchar();
        leitura.clear( );///limpa o objeto leitura
    }
    else
    {
        cout<<"Não Foi Possivel Abrir o Arquivo Texto! " << endl;
        getchar();
    }
    while(!leitura.fail())//SE A LEITURA NÃO FALHAR,Faz leittura linha a linha
    {
        if(!getline(leitura, linha, '\n'))//leitura da linha do arquivo até a quebra de linha
            break;
        if(linha == "MORADORES")
        {
            tipo = "MORADORES";
            continue;
        }
        if(linha == "CASAS")
        {
            tipo = "CASAS";
            continue;
        }
        istringstream ss(linha);
        cont = 0;
        while(ss)
        {
            if(!getline(ss,dado,';'))
                break;
            if(tipo == "MORADORES")
            {
                if(cont == 0)
                    mo.codigo = stoi(dado);
                if(cont == 1)
                    mo.nome = dado;
                if(cont == 2)
                    mo.documento = dado;
                if(cont == 3)
                    mo.idade = stoi(dado);
                if(cont == 4)
                {
                    mo.sexo = dado;
                    insere_moradores(LM,mo);
                }
                cont++;
            }
            if(tipo == "CASAS")
            {
                if(cont == 0)
                    ca.numero_casa = stoi(dado);
                if(cont == 1)
                {
                    ca.rua = dado;
                }
                if(cont == 2)
                {
                    quant_moradores = stoi(dado);
                    ca.numero_total_moradores = stoi(dado);
                    insere_casa(LC,ca);
                }
                if(cont > 2)
                {
                        mo.codigo = stoi(dado);
                        insereMC(LC,ca.numero_casa,mo.codigo);
                }
                cont++;
            }
        };
    };
    leitura.close();///fecha o objeto leitura
    do
    {
        system("cls");
        cout<<" --- Menu Sistema de Controle - Condomínio --- " << endl;
        cout<<" 0 - Encerra o Programa. " << endl;
        cout<<" 1 - Mostrar Lista de Moradores. " << endl;
        cout<<" 2 - Mostrar Lista de Casas. " << endl;
        cout<<" 3 - Mostrar Lista de Casas e Seus Moradores (Com Nome). " << endl;
        cout<<" 4 - Mostrar Número de Moradores por Sexo. " << endl;
        cout<<" 5 - Mostrar Média de Idade dos Moradores. " << endl;
        cout<<" 6 - Mostrar Média de Idade dos Moradores, Por Casa. " << endl;
        cout<<" 7 - Mostrar Número de Moradores ( Crianças [Até 12 anos] | Adultos [Maiores de 12 anos]. " << endl;
        cout<<" 8 - Filtrar Dados. " << endl;
        cout<<" Escolha Uma Opção Listada Acima: " << endl;
        cin>>op;
        fflush(stdin);
        switch(op)
        {
        case 0:
            cout<<"Programa Encerrado Com Sucesso!" << endl;
            break;
            getchar();
        case 1:
            mostrar_morador(LM);
            getchar();
            break;
        case 2:
            mostrar_casa(LC);
            getchar();
            break;
        case 3:
            cout<<LC;///mostra sublista de moradores casa
            getchar();
            break;
        case 4:
            mostra_numero_moradores(LM);
            getchar();
            break;
        case 5:
            media_idade_moradores(LM);
            getchar();
            break;
        case 7:
            mostrar_numero_moradores_idade(LM);
            getchar();
            break;
        default:
            cout<<"\n\n Opção Inválida, Tente Novamente! " << endl;
            getchar();
            break;
        }
    }
    while(op != 0);
}
///insereSub(lista, 1, "1111");///incluir fone 1111 para pessoa  1
