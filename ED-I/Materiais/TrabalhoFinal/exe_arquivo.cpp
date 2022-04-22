#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    ifstream leitura;
    leitura.open("entradaFINAL.txt");

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
        if (linha == "HEROIS")
        {
            tipo = "HEROIS";
            continue;
        }
        if (linha == "EQUIPES")
        {
            tipo = "EQUIPES";
            continue;
        }
//        cout << "\n >>" << linha;
        cout << "\n TIPO: >>" << tipo;
        istringstream ss(linha);
        /** é um manipulador de fluxos de dados de cadeias de
        caracteres especializado para o tipo de dado nativo char
        */
        int cont = 0;
        /// Pessoas p;
        while (ss)
        {
            if (!getline( ss, dado, ';' ))  ///chegou ao fim
                break;

            if (tipo == "TIPOS")
            {
                cout<<"\nEntrou tipo\n";
//                cout << "\t >" << dado;
                /**
                if (cont == 0)
                    p.cod = dado;
                  //  cout << "\n cód = " << dado;
                if (cont == 1)
                  //  cout << "\n descricao = " << dado;
                    p.nome = dado;
                cont++;
                **/
            }
            if (tipo == "HEROIS")
            {
                cout<<"\nEntrou herois\n";
//                cout << "\t >" << dado;
                /**
                if (cont == 0)
                    p.cod = dado;
                  //  cout << "\n cód = " << dado;
                if (cont == 1)
                  //  cout << "\n descricao = " << dado;
                    p.nome = dado;
                cont++;
                **/
            }
            if (tipo == "EQUIPE")
            {
                cout<<"\nEntrou equipe\n";
//                cout << "\t >" << dado;
                /**
                if (cont == 0)
                    p.cod = dado;
                  //  cout << "\n cód = " << dado;
                if (cont == 1)
                  //  cout << "\n descricao = " << dado;
                    p.nome = dado;
                cont++;
                **/
            }
        };
        ///inserir(listaTipo, p);
    }

}
