c++
 Lista_Moradores *LM = new Lista_Moradores();
    Lista_Casa *LC = new Lista_Casa();
    Moradores mo;
    Casa ca;
    string linha, dado;
    string tipo = "";
    ifstream leitura;
    int menu = 0,cont = 0,op;
    leitura.open("Listatrabalho.txt");
    if(leitura.is_open( ))
    {
        cout<<"Arquivo Texto Aberto Com Sucesso! " << endl;
        leitura.clear( );///limpa o objeto leitura
    }
    else
    {
        cout<<"Não Foi Possivel Abrir o Arquivo Texto! " << endl;
        abort();
    }
    while(!leitura.fail() || !leitura.eof())//SE A LEITURA NÃO FALHAR
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
         cont  = 0;
         //cout<<"\n" << linha;
        istringstream ss(linha);
           while(ss)
               {

                    if(!getline( ss, dado, ';'))///chegou ao fim
                        break;
                   if(tipo == "MORADORES")
                    {
                        if(cont == 0)///codigo morador
                            mo.codigo = stoi(dado);
                        if(cont == 1)///nome
                            mo.nome = dado;
                        if(cont == 2)///doc
                            mo.documento = dado;
                        if(cont == 3)///idade
                            mo.idade = stoi(dado);
                        if(cont == 4)///sexo
                            mo.sexo = dado;
                        cont++;
                        if(cont > 0)
                       {
                           insere_moradores(LM,mo);
                        }
                    }///if - tipo
                    if(tipo == "CASAS")
                    {
                        if(cont == 0)///codigo morador
                            ca.numero_casa = stoi(dado);
                        if(cont == 1)///nome
                            ca.rua = dado;
                        //if(cont == 2)///idade
                            //ca.numero_moradores = stoi(dado);
                        cont++;
                        if(cont > 0)
                       {
                           insere_casa(LC,ca);
                        }
                    }///if - tipo
                }

        ///getchar();
    }