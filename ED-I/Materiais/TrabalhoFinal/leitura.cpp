/// Ramon Antonio Maito Velasco

//Os protetores da cidade se organizaram e montaram uma lista dos protetores, com código, nome e
//telefone. E para cada protetor, há uma lista de animais que estão sob sua responsabilidade e disponíveis
//para adoção. Para cada animal tem-se as seguintes informações: código, tipo, nome, idade, raça, e porte
//(P,M,G).

#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;
#include "tipo.hpp"
#include "animal.hpp"
#include "protetor.hpp"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    ListaTipo *listaTipo = new ListaTipo();
    ListaAnimal *listaAnimal = new ListaAnimal();
    //ListaProtetor *listaProtetor= new ListaProtetor();

    ifstream leitura;
    leitura.open("entradaLINUX.txt");

    //Lista *listaTipo = new Lista();


    if(!leitura.is_open( ))
    {
        cout<<"Não foi possível abrir arquivo! Programa será terminado!\n";
        leitura.clear( ); //reseta o objeto leitura, para limpar memória do sistema}
    }
    string linha;
    string dado;
    string tipo = "";

    while(!leitura.fail())
    {
        getline(leitura, linha, '\n');
        if (linha == "TIPOS")
        {
            tipo = "TIPOS";
            continue;
        }

        if (linha == "ANIMAIS")
        {
            tipo = "ANIMAIS";
            continue;
        }

        if (linha == "PROTETORES")
        {
            tipo = "PROTETORES";
            continue;
        }

        //cout << "\n LINHA--------->>" << linha;
        istringstream ss(linha);
        /** é um manipulador de fluxos de dados de cadeias de
        caracteres especializado para o tipo de dado nativo char
        */
        int cont = 0;

        Tipos t;
        Animais a;
        //Protetores p;

//       cout<<"\nTIPO: "<<tipo<<endl;
        while (ss)
        {
            if (!getline( ss, dado, ';' ))  ///chegou ao fim
                break;

            if (tipo == "TIPOS")
            {
                cout<<"\nCONTADOR: "<<cont<<endl;
//                cout << "\n ENTROU"<<endl;
//                cout << "\t ||" << dado;

                if (cont == 0)
                {
                    t.cod = stoi(dado);
                    cout<<"DADO: "<<dado;

                }
                if (cont == 1)
                {
                    t.descricao = dado;
                    cout<<"DESCRICAO: "<<dado;
                    inserir(listaTipo, t);
                }
                cout<<"\n";
                cont++;
            }

            if (tipo == "ANIMAIS")
            {
                //cout << "\n ENTROU"<<endl;
////                cout << "\t ||" << dado;
//
                if (cont == 0)
                    a.cod = stoi(dado);
                if (cont == 1)
                    a.tipo=stoi(dado);
                if (cont == 2)
                    a.nome=dado;
                if (cont == 3)
                    a.idade=stoi(dado);
                if (cont == 4)
                    a.raca=dado;
                if (cont == 5)
                {
                    a.porte=atoi(dado);
                    inserir(listaAnimal, a);
                }
                cont++;
            }
            if (tipo == "PROTETORES")
            {
                //cout << "\n ENTROU"<<endl;
//                cout << "\t ||" << dado;

//                if (cont == 0)
////                    t.cod = dado;
//                    cout << "\n cód = " << dado;
//                if (cont == 1)
//                    cout << "\n descricao = " << dado;
////                    t.descricao = dado;
//                cont++;
            }

//            inserir(listaAnimal, a);
//            inserir(listaProtetor, p);
        };
    }

    cout<<"\n---------------\n";
//    cout<<"\nTIPO: "<<tipo<<endl;
    cout<<listaTipo;
    cout<<listaAnimal;

}
