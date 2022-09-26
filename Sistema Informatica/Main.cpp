/*Um empresa de Suprimentos de Informática contratou uma equipe
de analista e desenvolvedor de sistemas para desenvolver um sistema
de controle de clientes, funcionários, fornecedores e produtos.
 Deve apresentar as operações de Cadastrar, consultar(listar todos e
  Consultar por nome),alterar e excluir para todos os controles.
*/

#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<io.h>
#include<string.h>
#include<dos.h>


using namespace std;   //para usar comandos C++ junto com o C

//declaração das estruturas de registros das base de dados

struct dadosCli
{
    char nomeCli[20]; //cliente.nome
    char CPFC[20]; //333.444.555-77
    int idadeCli;        //cliente.idade
    float sbaseCli;      //cliente.sbase
    float vcomprasCli;
    //cliente.vcompras.
}Cliente;//variável de registro com os campos

struct dadosForn
{
    char nomeForn[20];  //string nomeForn[];
    char endeForn[30];
    char emailForn[30];
    char cnpj[20]; 	//34.456.678/0001-67
}Fornecedor;


struct dadosProd
{
    int codprod;
    char nomeprod[30];
    float valorUniprod;

} Produto;

struct dadosFunc
{
    char nomeFunc[20];  //string nomeForn[];
    char endeFunc[30];
    char emailFunc[30];
    char CPFF[20]; //333.444.555-77
    float salario;
}Funcionario;

void menu();
//declaração de variáveis Global
//declarar os Arquivos(FILE) e seus auxiliares

FILE *fClientes;    // file  - Arquivo    * - Ponteiro dinÂmico
FILE *fFornecedores;
FILE *fProdutos;
FILE *fFuncionarios;
FILE *fAuxCli;
FILE *fAuxForn;
FILE *fAuxProd;
FILE *fAuxFunc;
int opc;//variável opção global para no programa principal e na rotina menu optarmos pela função a ser executada conforme seleção pelo usuário
//criar as funções de criação dos arquivos

//modularizar as funções -
void cria_arqCli() //função que vai criar o arquivo fClientes
{//inicia o escopo da rotina cria arquivo de clientes
    if ((fClientes = fopen("clientes.dat","a"))==NULL) //criando e abrindo o arquivo Clientes
    {
        printf("\n Erro de criação do arquivo Clientes");
        return;
    }
    printf("\n Arquivo Clientes Criado");
    fclose(fClientes); //Fechando o arquivo Clientes
}//finaliza o escopo da rotina cria arquivo de clientes

void cria_arqAuxCli(){
    if((fAuxCli=fopen("auxcli.dat","a"))==NULL){
        system("cls");//system clear screen  - Limpa tela
        printf("\n Erro de criação de arquivo AuxCli");  //cout<<"Erro de criacao de arquivo";
        return;
    }printf("\n Arquivo AuxCli Criado");
    fclose(fAuxCli);
}

void cria_arqProd()
{
    if ((fProdutos = fopen("produtos.dat","a"))==NULL) //criando e abrindo o arquivo Produtos
    {
        printf("\n Erro de criação do arquivo Produtos");
        return;
    }
    printf("\n Arquivo Clientes Criado");
    fclose(fProdutos);
}

void cria_arqAuxProd(){
    if((fAuxProd=fopen("auxprod.dat","a"))==NULL){
        system("cls");
        printf("\n Erro de criação de arquivo AuxProd");
        return;
    }printf("\n Arquivo AuxProd Criado");
    fclose(fAuxProd);
}

void cria_arqFunc()
{
    if ((fFuncionarios = fopen("funcionarios.dat","a"))==NULL)
    {
        printf("\n Erro de criação do arquivo Funcionarios");
        return;
    }
    printf("\n Arquivo Funcionário Criado");
    fclose(fFuncionarios);
}

void cria_arqAuxFunc(){
    if((fAuxFunc=fopen("auxfunc.dat","a"))==NULL){
        system("cls");
        printf("\n Erro de criação de arquivo AuxProd");
        return;
    }printf("\n Arquivo AuxFunc Criado");
    fclose(fAuxFunc);
}


void cria_arqForn()
{
    if ((fFornecedores = fopen("Fornecedores.dat","a"))==NULL) //criando e abrindo o arquivo Fornecedores
    {
        printf("\n Erro de criação do arquivo Fornecedores");
        return;
    }
    printf("\n Arquivo Fornecedores Criado");
    fclose(fFornecedores); //Fechando o arquivo Fornecedores
}

void cria_arqAuxForn(){
    if((fAuxForn=fopen("auxforn.dat","a"))==NULL){
        system("cls");//system clear screen  - Limpa tela
        printf("\n Erro de criação de arquivo AuxForn");  //cout<<"Erro de criacao de arquivo";
        return;
    }
    fclose(fAuxForn);
}

//Iniciar as operações com arquivo - Cadastrar, Consultar, Alterar, Excluir
//Operações do arquivo Clientes

void cadastraCli() //cadastro do arquivo clientes
{ char op; //variável opção
    system("cls");  //limpa tela
    int tamanho=0; // declaração da variáveltamanho para capturar a qtdide de registros cadastrdas
    fClientes = fopen("clientes.dat","r+");//abre o arquivo clientes para leitura e escrita
    rewind(fClientes);  //joga para o primeiro registro do arquivo - posição 0
    do{ //laço de repetição para contar a qtidade de registros do arquivo
        fread(&Cliente,sizeof(Cliente),1,fClientes);//leitura do registro no arquivo
        tamanho++;} //tamanho = tamanho + 1 - Contar qtos registros
    while(!feof(fClientes)); //faça até o final do arquivo

    fseek(fClientes,sizeof(Cliente),tamanho); //aponta para a posição do arquivo correspondente ao tamanho
    do
    {
        system("cls");//limpa tela
        //printf("\n Digite o nome do cliente:");// mostra na tela
        cout<<"\n Digite o nome do cliente:";//cout - comando output - printf
        cin>>Cliente.nomeCli; //cin  C - comando in  - input  - Comando de entrada - scanf
        printf("\n Digite o CPFC:");
        cin>>Cliente.CPFC;
        printf("\n Digite a idade:");
        cin>>Cliente.idadeCli;
        printf("\n Digite o salario base:");
        cin>>Cliente.sbaseCli;
        printf("\n Digite o valor da compra:");
        cin>>Cliente.vcomprasCli;
        tamanho=tamanho+fwrite(&Cliente,sizeof(struct dadosCli),1,fClientes); //gravando o registro no arquivo
        //tamanho recebe incremento para gravar o próximo registro.
        printf("\n Continuar cadastrando <S> ou <N>:");
        cin>>op;//ler a opção
        op = toupper(op); //comando que coloca o caracter em maíusculo
    }while(op =='S'); // enquanto op igual S
    fclose(fClientes);// fecha o arquivo clientes
}

void consultaCli() //lista todos os registros do arquivo cliente
{
    system("cls");//limpa a tela
    fClientes=fopen("clientes.dat","r+"); //Abrir o arquivo clientes para leitura - Consulta
    fseek(fClientes,sizeof(struct dadosCli),0);//aponta para o registro 0 do arquivo de Clientes

    while(fread(&Cliente,sizeof(Cliente),1,fClientes)==1)
    {
        system("cls");//limpa a tela
        printf("Nome Cliente  :        %s\n",Cliente.nomeCli);// mostra na tela o campo nome do registro do cliente
        printf("CPFC Cliente :       %s\n",Cliente.CPFC);
        printf("Idade Cliente :       %d\n",Cliente.idadeCli);
        printf("Salario Ciente:     %.2f\n",Cliente.sbaseCli);
        printf("Valor Compr Cliente: %.2f\n",Cliente.vcomprasCli);
        printf("\n Digite enter para continuar\n");
        getch();//pedi para teclar algo  - enter
    }
    printf("\n fim do arquivo");
    fclose(fClientes); //fecha arquivo clientes
    getch(); //espera ser teclado algo para continuar
}

void consulta_nomeCli(){  //lista o registro selecionado pelo usuário do arquivo cliente
    //variáveis locais - somente enxergadas aqui
    char nom_pro[20]; //variável para o usuário digitar o nome do usuário a ser pesquisado no arquivo
    int achou=1;  //variável com sinlizador(flag) para indicar que achou o cliente e pode listar os dados e parar a pesquisa no arquivo
    int localizou=1;//variável que localizou o cliente desejado
    char op; //variável opção

    system("cls"); //limpa a tela
    fClientes=fopen("clientes.dat","r+"); // abre o arquivo para leitura e escrita
    fseek(fClientes,sizeof(struct dadosCli),0);//aponta pora o Registro 0(inicial) do arquivo
    printf("\n Digite o Nome p/ Procura : "); //Pergunta ao usuário qual cliente deseja buscar na consulta
    cin>>nom_pro;//Usário Digita o nome do cliente a ser procurado
    while(fread(&Cliente,sizeof(Cliente),1,fClientes)==1){//laço de repetição para percorrer registro a registro no arquivo até localizar o cliente desejado
        achou=strcmp(Cliente.nomeCli,nom_pro);//comando que compara as nome digitado pelo usuário com o nome do cliente do registro do arquivo
        //comando strcmp pega o valor hexadecimal dos caracteres da string nome do cliente do registro (Cliente.nomeCli)
        //e subtrai do valor hexadecimal dos caracteres da string nome do cliente para ser procurado (nome_pro)
        //se forem iguais o resultado é zero e é alocado para a variável achou, caso contrário vai 1 para a varíavel
        if(achou==0)
        { //nomes são iguais então achou o cliente desejado
            printf("\n O Nome ‚.................:%s",Cliente.nomeCli);//lista o nome do cliente na tela
            printf("\n A Idade ‚................:%d",Cliente.idadeCli);//lista a idade do cliente na tela
            printf("\n O CPFC ‚................:%d",Cliente.CPFC);
            printf("\n O Salário Bruto ‚........:%0.2f",Cliente.sbaseCli);
            printf("\n O Valor da Compra ‚......:%0.2f",Cliente.vcomprasCli);
            printf("\n_____________________________________________\n");
            getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
            localizou=0;
        }}

    if(localizou == 1){ //varreu todo o arquivo e não encontrou o nome do cliente para ser consultado
        printf("\n Cliente não Cadastrado\n"); //lista na tela
        printf("\n Cadastrar Cliente <S> ou <N>:");//lista na tela para pedir se o usuário deseja cadastrar este cliente não encontrado
        cin>>op;//lê a opção do usuário em cadastrar ou não
        op = toupper(op);//pega o a caracter S ou N digitado pelo usuário e coloca em letra maíuscula
        if (op=='S'){ //compara o valor da variável op para cadastrar ou não o novo cliente
            cadastraCli();} //chama a função para cadstrar o novo cliente
        else {fclose(fClientes);} //fecha arquivo clientes
        getch();}}//espera algo a ser teclado e saia da função de consulta cliente pelo nome

void alteraCli(){ //Procura o registro selecionado pelo usuário do arquivo cliente para alteração
    char nom_pro[20]; //variável para o usuário digitar o nome do usuário a ser pesquisado no arquivo
    int achou;//variável com sinalizador(flag) para indicar que achou o cliente e pode listar os dados para fazer a alteração e parar a pesquisa no arquivo
    int pos=0;//variável para incrementar a posição do registro dentro do arquivo cliente
    system("cls");//limpa a tela
    fClientes=fopen("clientes.dat","r+");// abre o arquivo para leitura e escrita
    fseek(fClientes,sizeof(struct dadosCli),0);//aponta pora o Registro 0(inicial) do arquivo
    printf("\n Digite o Nome p/ Procura : ");//Pergunta ao usuário qual cliente deseja buscar na consulta
    cin>> nom_pro;//Usário Digita o nome do cliente a ser procurado
    while(fread(&Cliente,sizeof(Cliente),1,fClientes)==1){//laço de repetição para percorrer registro a registro no arquivo até localizar o cliente desejado
        achou=strcmp(Cliente.nomeCli,nom_pro);//comando que compara as nome digitado pelo usuário com o nome do cliente do registro do arquivo
        //comando strcmp pega o valor hexadecimal dos caracteres da string nome do cliente do registro (Cliente.nomeCli)
        //e subtrai do valor hexadecimal dos caracteres da string nome do cliente para ser procurado (nome_pro)
        //se forem iguais o resultado é zero e é alocado para a variável achou, caso contrário vai 1 para a varíavel
        pos++;//incrementa a variável pos 1 a 1 para posicionar o próximo registro dentro do arquivo cliente
        if(achou==0){ //nomes são iguais então achou o cliente desejado
            printf("\n O Nome ‚.................:%s",Cliente.nomeCli); //lista o nome do cliente encontrado na tela
            printf("\n A Idade ‚................:%d",Cliente.idadeCli);
            printf("\n O CPFFC ‚................:%d",Cliente.CPFC);
            printf("\n O Salário Bruto ‚........:%0.2f",Cliente.sbaseCli);
            printf("\n O Valor da Compra ‚......:%0.2f",Cliente.vcomprasCli);
            printf("_____________________________________________\n");
            printf("Digite <enter> para continuar e alterar____________\n");
            getch(); //espera algoa ser teclado para continuar, permite que vejamos os dados na tela
            //Começa a pedir para o usuário os novos dados a ser alterados
            printf("\n Digite a alterção do nome do cliente: %s",Cliente.nomeCli);//Apresenta na tela o que o usuário deve alterar
            cin>>Cliente.nomeCli;//Lê o novo valor de alteração do nome do cliente
            printf("\n Digite a idade:");//Apresenta na tela o que o usuário deve alterar
            cin>>Cliente.idadeCli;//Lê o novo valor de alteração da idade do cliente
            printf("\n Digite o salario base:");
            cin>>Cliente.sbaseCli;
            printf("\n Digite o CPFC");
            cin>>Cliente.CPFC;
            printf("\n Digite o valor da compra:");
            cin>>Cliente.vcomprasCli;
            fseek(fClientes,pos*sizeof(struct dadosCli),SEEK_SET);//posiciona o ponteiro de registro do arquivo na posição pos registrada para alterar o registro certo dentro do arquivo
            fwrite(&Cliente,sizeof(struct dadosCli),1,fClientes);//Grava os dados alterados no registro certo dentro do arquivo
            fseek(fClientes,sizeof(struct dadosCli),SEEK_END);}
        printf("Digite <enter> para continuar___________________\n");
        getch();}//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
    fclose(fClientes);}//fecha o arquivo Clientes e sai da função altera


void excluiCli() //Procura o registro selecionado pelo usuário do arquivo cliente para exclusão
{
    char nom_pro[20];//variável para o usuário digitar o nome do usuário a ser pesquisado no arquivo
    int achou=1;//variável com sinalizador(flag) para indicar que achou o cliente e pode listar os dados para fazer a exclusão e parar a pesquisa no arquivo
    int tamanhoaux=0;//varíaveis para ter o controle de registro a registro do tamanho do arquivo auxiliar de clientes
    int tamanhocli=0;//varíaveis para ter o controle de registro a registro do tamanho do arquivo de clientes

    system("cls");//linpa tela
    fClientes=fopen("clientes.dat","r+");// abre o arquivo para leitura e escrita
    fseek(fClientes,sizeof(struct dadosCli),0);//aponta pora o Registro 0(inicial) do arquivo
    cria_arqAuxCli();//chama a função para criar o arquivo auxiliar de clientes
    fAuxCli=fopen("auxcli.dat","r+");//abre o arquivo auxiliar de clientes para leitura e escrita
    fseek(fAuxCli,sizeof(struct dadosCli),0);//aponta por seguração ao registro 0(inicial) do arquivo auxiliar de clientes
    //começa a procura do registro a ser excluído no arquivo clientes
    printf("\n Digite o Nome do cliente p/ Procura : ");//Pergunta ao usuário qual cliente deseja buscar na consulta para ser excluído
    cin>> nom_pro;//Usário Digita o nome do cliente a ser procurado para exclusão
    while(fread(&Cliente,sizeof(Cliente),1,fClientes)==1){//laço de repetição para ler registro a registro do arquivo clientes até encontrar o desejado
        achou=strcmp(Cliente.nomeCli,nom_pro);//comando que compara as nome digitado pelo usuário com o nome do cliente do registro do arquivo
        //comando strcmp pega o valor hexadecimal dos caracteres da string nome do cliente do registro (Cliente.nomeCli)
        //e subtrai do valor hexadecimal dos caracteres da string nome do cliente para ser procurado (nome_pro)
        //se forem iguais o resultado é zero e é alocado para a variável achou, caso contrário vai 1 para a varíavel
        if(achou==0){ //nomes são iguais então achou o cliente desejado
            printf("\n O Nome ‚.................:%s",Cliente.nomeCli);//lista o nome do cliente encontrado na tela
            printf("\n A Idade ‚................:   %d",Cliente.idadeCli);
            printf("\n O CPFC ‚................:   %d",Cliente.CPFC);
            printf("\n O Salário Bruto ‚........:%0.2f",Cliente.sbaseCli);
            printf("\n O Valor da Compra ‚......:%0.2f",Cliente.vcomprasCli);
            printf("_____________________________________________\n");
            getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
        }
        else{ //caso não entre no achou==0 então vai para esta parte do senão para transferir uma cópia do registro que não é o desejado a excluir
            //do arquivo clientes para o arquivo auxiliar do cliente
            tamanhoaux=tamanhoaux+fwrite(&Cliente,sizeof(struct dadosCli),1,fAuxCli);}}//grava o registro do arquivo cliente no arquivo aux cliente um a um
    //cada registro gravado no aux a função fwrite gera 1 que é incerementado na variável tamanhoaux para gravar
    //no próximo registro livre no arquivo e não sobrepor resgistros.
    fclose(fAuxCli);//fecha arquivo AuxCli
    fclose(fClientes);//fecha arquivo Clientes
    remove("clientes.dat");//remove o arquivo inicial de Clientes totalmente pois já trasnferimos aqueles registros com excessão do a ser excluído
    cria_arqCli();//chama a função para criar novamente o arquivo Clientes zerado
    fClientes=fopen("clientes.dat","r+");//Abre o novo arquivo Clientes para ler e gravar dados
    fseek(fClientes,sizeof(struct dadosCli),0);//Aponta por segurança para o registro 0(inicial) do arquivo clientes

    fAuxCli=fopen("auxcli.dat","r+");//abre o arquivi AuxCli para transferir de volta os registros dos clientes que não eram para ser excluídos
    fseek(fAuxCli,sizeof(struct dadosCli),0);//Aponta por segurança para o registro 0(inicial) do arquivo AuxCli
    while(fread(&Cliente,sizeof(Cliente),1,fAuxCli)==1) {//laço de repetição para trasnferir registros 1 a 1 do arquivo AuxCli para o arquivo Clientes
        tamanhocli=tamanhocli+fwrite(&Cliente,sizeof(struct dadosCli),1,fClientes);}//grava o registro do arquivo AucCLi no arquivo Clientes um a um
    //cada registro gravado no Clinetes a função fwrite gera 1 que é incerementado na variável tamanhocli para gravar
    //no próximo registro livre no arquivo e não sobrepor resgistros.
    fclose(fAuxCli);//fecha arquivo auxcli
    remove("auxcli.dat");//remove completamente o arquivo auxcli pois já trensferimos os registros para o novo arquivo Clientes agora sem o registro que foi excluído
    fclose(fClientes);//fecha aqruivo Clientes
    printf("\n Cliente Excluído - Digite <enter> para continuar___________________\n");
    getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
}//fecha a função de exclusão de registro de clientes


void excl_arqCli(){//função para excluir completamente todo o arquivo de clientes de uma vez só
    char op;//variável de segurança para optar em excluir mesmo ou não o arquivo de clientes
    printf("\n Deleta Arquivo <S> ou <N>? ");//informação na tela para o usuário
    cin>>op;//leitura da opção de deletar S ou não N o arquivo Clientes inteiro
    op = toupper(op);//pega o a caracter S ou N digitado pelo usuário e coloca em letra maíuscula
    if (op=='S')//compara o valor da variável op para cadastrar ou não o novo cliente
    {
        remove("clientes.dat");//remove completamente o arquivo inteiro de Clientes
        printf("arquivo deletado");}//informa na tela para o usuário que deletou o arquivo

    else{//senão optou por Não - N
        printf("\n Arquivo não foi deletado por sua opção");//informa na tela para o usuário que naõ deletou o arquivo
        getch();}//espera algoa ser teclado para continuar, permite que vejamos os dados na tela e fecha a função de exclusão total do arquivo Clientes
    cria_arqCli();}//cria arquivo para uso futuro


void menuCli()//criação da função Menu de opções
{ //inicia o escopo da rotina Menu
    system("cls");//limpa a tela
    printf("Menu de opcoes");//mostra na tela para o usuários as opções de Menu
    printf("\n");//pula linha
    printf("1 - Cadastrar Clientes\n");
    printf("2 - Consultar Listar todos Clintes  \n");
    printf("3 - Consultar Por Nome de Cliente \n");
    printf("4 - Alterar Registro de Cliente \n");
    printf("5 - Excluir Registro de Clientes \n");
    printf("6 - Exclui Arquivo total de Clientes\n");
    printf("7 - Voltar ao Menu principal \n");
    printf("8 - Fechar o programa \n");
    printf("Digite uma opcao \n");//pede a opção via teclado do usuário
    cin>>opc;//lê a variável global opção do menu para chamar a funçao
    switch(opc)//estrutura de composição de vários if
    {
        case 1:cadastraCli();break; //caso a opc igual 1 chamada rotina cadastra executando-a retornando para o menu
        case 2:consultaCli();break;//caso a opc igual 2 chamada rotina consulta Cliente Listar executando-a retornando para o menu
        case 3:consulta_nomeCli();break;
        case 4:alteraCli();break;
        case 5:excluiCli();break;
        case 6:excl_arqCli();break;
        case 7:menu();break;
        case 8:exit(0);//função para sair totalmente do programa
    }
}//finaliza o escopo da rotina Menu





//Operações do arquivo Funcionario

void cadastraFunc()
{ char op;
    system("cls");
    int tamanho=0;
    fFuncionarios = fopen("funcionarios.dat","r+");
    rewind(fFuncionarios);
    do{
        fread(&Funcionario,sizeof(Funcionario),1,fFuncionarios);
        tamanho++;}
    while(!feof(fFuncionarios));

    fseek(fFuncionarios,sizeof(Funcionario),tamanho);
    do
    {
        system("cls");

        cout<<"\n Digite o nome do funcionário:";
        cin>>Funcionario.nomeFunc;
         printf("\n Digite o Email:");
        cin>>Funcionario.emailFunc;
        printf("\n Digite o Endereço:");
        cin>>Funcionario.endeFunc;
        printf("\n Digite o salario:");
        cin>>Funcionario.salario;
        printf("\n Digite o Cpff:");
        cin>>Funcionario.CPFF;
        tamanho=tamanho+fwrite(&Funcionario,sizeof(struct dadosFunc),1,fFuncionarios);
        printf("\n Continuar cadastrando <S> ou <N>:");
        cin>>op;
        op = toupper(op);
    }while(op =='S');
    fclose(fFuncionarios);
}

void consultaFunc()
{
    system("cls");
    fFuncionarios=fopen("funcionarios.dat","r");
    fseek(fFuncionarios,sizeof(struct dadosFunc),0);

    while(fread(&Funcionario,sizeof(Funcionario),1,fFuncionarios)==1)
    {
        system("cls");
        printf("Nome Funcionario  :        %s\n",Funcionario.nomeFunc);
        printf("Email Funcionario  :        %s\n",Funcionario.emailFunc);
        printf("Endereço funcionário :       %s\n",Funcionario.endeFunc);
        printf("Salario Funcionário:     %.2f\n",Funcionario.salario);
        printf("CPFF Funcionário: %s\n",Funcionario.CPFF);
        printf("\n Digite enter para continuar\n");
        getch();
    }
    printf("\n fim do arquivo");
    fclose(fFuncionarios);
    getch();
}

void consulta_nomeFunc(){

    char nom_pro[20];
    int achou=1;
    int localizou=1;
    char op;

    system("cls");
    fFuncionarios=fopen("funcionarios.dat","r+");
    fseek(fFuncionarios,sizeof(struct dadosFunc),0);
    printf("\n Digite o Nome p/ Procura : ");
    cin>>nom_pro;
    while(fread(&Funcionario,sizeof(Funcionario),1,fFuncionarios)==1){
        achou=strcmp(Funcionario.nomeFunc,nom_pro);
        if(achou==0)
        {
            printf("\n O Nome ‚.................:%s",Funcionario.nomeFunc);
            printf("\n O Email ‚.................:%s",Funcionario.emailFunc);
            printf("\n O Endereço ‚................:%s",Funcionario.endeFunc);
            printf("\n O Salário  ‚........:%.2f",Funcionario.salario);
            printf("\n O CPFF ‚......:%s",Funcionario.CPFF);
            printf("\n_____________________________________________\n");
            getch();
            localizou=0;
        }}

    if(localizou == 1){
        printf("\n Funcionário não Cadastrado\n");
        printf("\n Cadastrar Funcionário <S> ou <N>:");
        cin>>op;
        op = toupper(op);
        if (op=='S'){
            cadastraFunc();}
        else {fclose(fFuncionarios);}
        getch();}}

void alteraFunc(){
    char nom_pro[20];
    int achou;
    int pos=0;
    system("cls");
    fFuncionarios=fopen("funcionarios.dat","r+");
    fseek(fFuncionarios,sizeof(struct dadosFunc),0);
    printf("\n Digite o Nome p/ Procura : ");
    cin>> nom_pro;
    while(fread(&Funcionario,sizeof(Funcionario),1,fFuncionarios)==1){
        achou=strcmp(Funcionario.nomeFunc,nom_pro);
        pos++;
        if(achou==0){
            printf("\n O Nome ‚.................:%s",Funcionario.nomeFunc);
            printf("\n O Email ‚.................:%s",Funcionario.emailFunc);
            printf("\n O Endereço ‚................:%s",Funcionario.endeFunc);
            printf("\n O Salário ‚........:%0.2f",Funcionario.salario);
            printf("\n O CPFF ‚......:%s",Funcionario.CPFF);
            printf("_____________________________________________\n");
            printf("Digite <enter> para continuar e alterar____________\n");
            getch();

            printf("\n Digite a alterção do nome do funcionário: %s",Funcionario.nomeFunc);
            cin>>Funcionario.nomeFunc;
            printf("\n Digite o email:");
            cin>>Funcionario.emailFunc;
            printf("\n Digite o endereço:");
            cin>>Funcionario.endeFunc;
            printf("\n Digite o salario:");
            cin>>Funcionario.salario;
            printf("\n Digite o CPFF do funcionário");
            cin>>Funcionario.CPFF;
            fseek(fFuncionarios,pos*sizeof(struct dadosFunc),SEEK_SET);
            fwrite(&Funcionario,sizeof(struct dadosFunc),1,fFuncionarios);
            fseek(fFuncionarios,sizeof(struct dadosFunc),SEEK_END);}
        printf("Digite <enter> para continuar___________________\n");
        getch();}
    fclose(fFuncionarios);}


void excluiFunc()
{
    char nom_pro[20];
    int achou=1;
    int tamanhoaux=0;
    int tamanhofunc=0;

    system("cls");
    fFuncionarios=fopen("funcionarios.dat","r+");
    fseek(fFuncionarios,sizeof(struct dadosFunc),0);
    cria_arqAuxFunc();
    fAuxFunc=fopen("auxfunc.dat","r+");
    fseek(fAuxFunc,sizeof(struct dadosFunc),0);
    printf("\n Digite o Nome do funcionário p/ Procura : ");
    cin>> nom_pro;
    while(fread(&Funcionario,sizeof(Funcionario),1,fFuncionarios)==1){
        achou=strcmp(Funcionario.nomeFunc,nom_pro);
        if(achou==0){
            printf("\n O Nome ‚.................:%s",Funcionario.nomeFunc);
            printf("\n O Email ‚.................:%s",Funcionario.emailFunc);
            printf("\n O Endereço ‚................:%s",Funcionario.endeFunc);
            printf("\n O Salário ‚........:%0.2f",Funcionario.salario);
            printf("\n O CPFF ‚......:%s",Funcionario.CPFF);
            printf("_____________________________________________\n");
            getch();
        }
        else{
            tamanhoaux=tamanhoaux+fwrite(&Funcionario,sizeof(struct dadosFunc),1,fAuxFunc);}}
    fclose(fAuxFunc);
    fclose(fFuncionarios);
    remove("funcionarios.dat");
    cria_arqFunc();
    fFuncionarios=fopen("funcionarios.dat","r+");
    fseek(fFuncionarios,sizeof(struct dadosFunc),0);
    fAuxFunc=fopen("auxfunc.dat","r+");
    fseek(fAuxFunc,sizeof(struct dadosFunc),0);
    while(fread(&Funcionario,sizeof(Funcionario),1,fAuxFunc)==1) {
        tamanhofunc=tamanhofunc+fwrite(&Funcionario,sizeof(struct dadosFunc),1,fFuncionarios);}
    fclose(fAuxFunc);
    remove("auxfunc.dat");
    fclose(fFuncionarios);
    printf("\n Funcionário Excluído - Digite <enter> para continuar___________________\n");
    getch();
}

void excl_arqFunc(){
    char op;
    printf("\n Deleta Arquivo <S> ou <N>? ");
    cin>>op;
    op = toupper(op);
    if (op=='S')
    {
        remove("funcionarios.dat");
        printf("arquivo deletado");}

    else{
        printf("\n Arquivo não foi deletado por sua opção");
        getch();}
    cria_arqFunc();}


void menuFunc()
{
    system("cls");
    printf("Menu de opções");
    printf("\n");
    printf("1 - Cadastrar Funcionários\n");
    printf("2 - Consultar Listar todos Funcionários  \n");
    printf("3 - Consultar Por Nome de Funcionário \n");
    printf("4 - Alterar Registro de Funcionário \n");
    printf("5 - Excluir Registro de Funcionários \n");
    printf("6 - Exclui Arquivo total de Funcionários\n");
    printf("7 - Voltar ao Menu principal \n");
    printf("8 - Sair do programa \n");
    printf("Digite uma opcao \n");
    cin>>opc;
    switch(opc)
    {
        case 1:cadastraFunc();break;
        case 2:consultaFunc();break;
        case 3:consulta_nomeFunc();break;
        case 4:alteraFunc();break;
        case 5:excluiFunc();break;
        case 6:excl_arqFunc();break;
        case 7:menu();break;
        case 8:exit(0);
    }
}

void cadastraForn()
{ char op;
    system("cls");
    int tamanho=0;
    fFornecedores = fopen("fornecedores.dat","r+");
    rewind(fFornecedores);
    do{
        fread(&Fornecedor,sizeof(Fornecedor),1,fFornecedores);
        tamanho++;}
    while(!feof(fFornecedores));

    fseek(fFornecedores,sizeof(Fornecedor),tamanho);
    do
    {
        system("cls");

        cout<<"\n Digite o nome do fornecedor:";
        cin>>Fornecedor.nomeForn;
        printf("\n Digite o Endereço:");
        cin>>Fornecedor.endeForn;
        printf("\n Digite o Email:");
        cin>>Fornecedor.emailForn;
        printf("\n Digite o CNPJ:");
        cin>>Fornecedor.cnpj;
        tamanho=tamanho+fwrite(&Fornecedor,sizeof(struct dadosForn),1,fFornecedores);
        printf("\n Continuar cadastrando <S> ou <N>:");
        cin>>op;
        op = toupper(op);
    }while(op =='S');
    fclose(fFornecedores);
}

void consultaForn()
{
    system("cls");
    fFuncionarios=fopen("fornecedores.dat","r");
    fseek(fFornecedores,sizeof(struct dadosForn),0);

    while(fread(&Fornecedor,sizeof(Fornecedor),1,fFornecedores)==1)
    {
        system("cls");
        printf("Nome Fornecedor  :        %s\n",Fornecedor.nomeForn);
        printf("Endereço Fornecedor :       %s\n",Fornecedor.endeForn);
        printf("Email Fornecedor:     %s\n", Fornecedor.emailForn);
        printf("CNPJ Fornecedor: %s\n",Fornecedor.cnpj);
        printf("\n Digite enter para continuar\n");
        getch();
    }
    printf("\n fim do arquivo");
    fclose(fFornecedores);
    getch();
}

void consulta_nomeForn(){

    char nom_pro[20];
    int achou=1;
    int localizou=1;
    char op;

    system("cls");
    fFornecedores=fopen("fornecedores.dat","r+");
    fseek(fFornecedores,sizeof(struct dadosForn),0);
    printf("\n Digite o Nome p/ Procura : ");
    cin>>nom_pro;
    while(fread(&Fornecedor,sizeof(Fornecedor),1,fFornecedores)==1){
        achou=strcmp(Fornecedor.nomeForn,nom_pro);
        if(achou==0)
        {
            printf("\n O Nome ‚.................:%s",Fornecedor.nomeForn   );
            printf("\n O Endereço ‚................:%s",Fornecedor.endeForn);
            printf("\n O Email  ‚........:%s",Fornecedor.emailForn);
            printf("\n O CNPJ ‚......:%s",Fornecedor.cnpj);
            printf("\n_____________________________________________\n");
            getch();
            localizou=0;
        }}

    if(localizou == 1){
        printf("\n Fornecedor não Cadastrado\n");
        printf("\n Cadastrar Fornecedor <S> ou <N>:");
        cin>>op;
        op = toupper(op);
        if (op=='S'){
            cadastraForn();}
        else {fclose(fFornecedores);}
        getch();}}

void alteraForn(){
    char nom_pro[20];
    int achou;
    int pos=0;
    system("cls");
    fFuncionarios=fopen("fornecedores.dat","r+");
    fseek(fFornecedores,sizeof(struct dadosForn),0);
    printf("\n Digite o Nome p/ Procura : ");
    cin>> nom_pro;
    while(fread(&Fornecedor,sizeof(Fornecedor),1,fFornecedores)==1){
        achou=strcmp(Fornecedor.nomeForn,nom_pro);
        pos++;
        if(achou==0){
            printf("\n O Nome ‚.................:%s",Fornecedor.nomeForn);
            printf("\n O Endereço ‚................:%s",Fornecedor.endeForn);
            printf("\n O Email ‚........:%s",Fornecedor.emailForn);
            printf("\n O CNPJ ‚......:%s",Fornecedor.cnpj);
            printf("_____________________________________________\n");
            printf("Digite <enter> para continuar e alterar____________\n");
            getch();

            printf("\n Digite a alterção do nome do fornecedor: %s",Fornecedor.nomeForn);
            cin>>Fornecedor.nomeForn;
            printf("\n Digite o endereço:");
            cin>>Fornecedor.endeForn;
            printf("\n Digite o email:");
            cin>>Fornecedor.emailForn;
            printf("\n Digite o CNPJ do fornecedor");
            cin>>Fornecedor.cnpj;
            fseek(fFornecedores,pos*sizeof(struct dadosForn),SEEK_SET);
            fwrite(&Fornecedor,sizeof(struct dadosForn),1,fFornecedores);
            fseek(fFornecedores,sizeof(struct dadosForn),SEEK_END);}
        printf("Digite <enter> para continuar___________________\n");
        getch();}
    fclose(fFornecedores);}


void excluiForn()
{
    char nom_pro[20];
    int achou=1;
    int tamanhoaux=0;
    int tamanhoforn=0;

    system("cls");
    fFornecedores=fopen("fornecedores.dat","r+");
    fseek(fFornecedores,sizeof(struct dadosForn),0);
    cria_arqAuxForn();
    fAuxForn=fopen("auxforn.dat","r+");
    fseek(fAuxForn,sizeof(struct dadosForn),0);
    printf("\n Digite o Nome do fornecedor p/ Procura : ");
    cin>> nom_pro;
    while(fread(&Fornecedor,sizeof(Fornecedor),1,fFornecedores)==1){
        achou=strcmp(Fornecedor.nomeForn,nom_pro);
        if(achou==0){
            printf("\n O Nome ‚.................:%s",Fornecedor.nomeForn);
            printf("\n O Endereço ‚................:%s",Fornecedor.endeForn);
            printf("\n O Email ‚........:%s",Fornecedor.emailForn);
            printf("\n O CNPJ ‚......:%s",Fornecedor.cnpj);
            printf("_____________________________________________\n");
            getch();
        }
        else{
            tamanhoaux=tamanhoaux+fwrite(&Fornecedor,sizeof(struct dadosForn),1,fAuxForn);}}
    fclose(fAuxForn);
    fclose(fFornecedores);
    remove("fornecedores.dat");
    cria_arqForn();
    fFornecedores=fopen("fornecedores.dat","r+");
    fseek(fFornecedores,sizeof(struct dadosForn),0);
    fAuxForn=fopen("auxforn.dat","r+");
    fseek(fAuxForn,sizeof(struct dadosForn),0);
    while(fread(&Fornecedor,sizeof(Fornecedor),1,fAuxForn)==1) {
        tamanhoforn=tamanhoforn+fwrite(&Fornecedor,sizeof(struct dadosForn),1,fFornecedores);}
    fclose(fAuxForn);
    remove("auxforn.dat");
    fclose(fFornecedores);
    printf("\n Fornecedor Excluído - Digite <enter> para continuar___________________\n");
    getch();
}

void excl_arqForn(){
    char op;
    printf("\n Deleta Arquivo <S> ou <N>? ");
    cin>>op;
    op = toupper(op);
    if (op=='S')
    {
        remove("fornecedores.dat");
        printf("arquivo deletado");}

    else{
        printf("\n Arquivo não foi deletado por sua opção");
        getch();}
    cria_arqForn();}


void menuForn()
{
    system("cls");
    printf("Menu de opções");
    printf("\n");
    printf("1 - Cadastrar Fornecedores\n");
    printf("2 - Consultar Listar todos Fornecedores  \n");
    printf("3 - Consultar Por Nome de Fornecedor \n");
    printf("4 - Alterar Registro de Fornecedor \n");
    printf("5 - Excluir Registro de Fornecedores \n");
    printf("6 - Exclui Arquivo total de Fornecedores\n");
    printf("7 - Voltar ao Menu principal \n");
    printf("8 - Sair do Programa \n");
    printf("Digite uma opcao \n");
    cin>>opc;
    switch(opc)
    {
        case 1:cadastraForn();break;
        case 2:consultaForn();break;
        case 3:consulta_nomeForn();break;
        case 4:alteraForn();break;
        case 5:excluiForn();break;
        case 6:excl_arqForn();break;
        case 7:menu();break;
        case 8:exit(0);
    }
}

void cadastraProd()
{ char op;
    system("cls");
    int tamanho=0;
    fProdutos = fopen("produtos.dat","r+");
    rewind(fProdutos);
    do{
        fread(&Produto,sizeof(Produto),1,fProdutos);
        tamanho++;}
    while(!feof(fProdutos));

    fseek(fProdutos,sizeof(Produto),tamanho);
    do
    {
        system("cls");

        cout<<"\n Digite o código do produto:";
        cin>>Produto.codprod;
        printf("\n Digite o Nome:");
        cin>>Produto.nomeprod;
        printf("\n Digite o valor:");
        cin>>Produto.valorUniprod;
        tamanho=tamanho+fwrite(&Produto,sizeof(struct dadosProd),1,fProdutos);
        printf("\n Continuar cadastrando <S> ou <N>:");
        cin>>op;
        op = toupper(op);
    }while(op =='S');
    fclose(fProdutos);
}

void consultaProd()
{
    system("cls");
    fProdutos=fopen("produtos.dat","r");
    fseek(fProdutos,sizeof(struct dadosProd),0);

    while(fread(&Produto,sizeof(Produto),1,fProdutos)==1)
    {
        system("cls");
        printf("Codigo do Produto  :        %d\n",Produto.codprod);
        printf("Nome do Produto :       %s\n",Produto.nomeprod);
        printf("Valor do Produto:     %0.2f\n", Produto.valorUniprod);
        printf("\n Digite enter para continuar\n");
        getch();
    }
    printf("\n fim do arquivo");
    fclose(fProdutos);
    getch();
}

void consulta_nomeProd(){

    char nom_pro[20];
    int achou=1;
    int localizou=1;
    char op;

    system("cls");
    fProdutos=fopen("produtos.dat","r+");
    fseek(fProdutos,sizeof(struct dadosProd),0);
    printf("\n Digite o Nome p/ Procura : ");
    cin>>nom_pro;
    while(fread(&Produto,sizeof(Produto),1,fProdutos)==1){
        achou=strcmp(Produto.nomeprod,nom_pro);
        if(achou==0)
        {
            printf("\n O Nome ‚.................:%s",Produto.nomeprod);
            printf("\n O Codigo ‚................:%d",Produto.codprod);
            printf("\n O Valor Único  ‚........:%0.2f",Produto.valorUniprod);
            printf("\n_____________________________________________\n");
            getch();
            localizou=0;
        }}

    if(localizou == 1){
        printf("\n Produto não Cadastrado\n");
        printf("\n Cadastrar Produto <S> ou <N>:");
        cin>>op;
        op = toupper(op);
        if (op=='S'){
            cadastraProd();}
        else {fclose(fProdutos);}
        getch();}}

void alteraProd(){
    char nom_pro[20];
    int achou;
    int pos=0;
    system("cls");
    fProdutos=fopen("produtos.dat","r+");
    fseek(fProdutos,sizeof(struct dadosProd),0);
    printf("\n Digite o Nome p/ Procura : ");
    cin>> nom_pro;
    while(fread(&Produto,sizeof(Produto),1,fProdutos)==1){
        achou=strcmp(Produto.nomeprod,nom_pro);
        pos++;
        if(achou==0){
            printf("\n O Nome ‚.................:%s",Produto.nomeprod);
            printf("\n O Código ‚................:%d",Produto.codprod);
            printf("\n O Valor ‚........:%0.2f",Produto.valorUniprod);
            printf("_____________________________________________\n");
            printf("Digite <enter> para continuar e alterar____________\n");
            getch();

            printf("\n Digite a alterção do nome do fornecedor: %s",Produto.nomeprod);
            cin>>Produto.nomeprod;
            printf("\n Digite o código:");
            cin>>Produto.codprod;
            printf("\n Digite o valor:");
            cin>>Produto.valorUniprod;
            fseek(fProdutos,pos*sizeof(struct dadosProd),SEEK_SET);
            fwrite(&Produto,sizeof(struct dadosProd),1,fProdutos);
            fseek(fProdutos,sizeof(struct dadosProd),SEEK_END);}
        printf("Digite <enter> para continuar___________________\n");
        getch();}
    fclose(fProdutos);}


void excluiProd()
{
    char nom_pro[20];
    int achou=1;
    int tamanhoaux=0;
    int tamanhoprod=0;

    system("cls");
    fProdutos=fopen("produtos.dat","r+");
    fseek(fProdutos,sizeof(struct dadosProd),0);
    cria_arqAuxProd();
    fAuxProd=fopen("auxprod.dat","r+");
    fseek(fAuxProd,sizeof(struct dadosProd),0);
    printf("\n Digite o Nome do produto p/ Procura : ");
    cin>> nom_pro;
    while(fread(&Produto,sizeof(Produto),1,fProdutos)==1){
        achou=strcmp(Produto.nomeprod,nom_pro);
        if(achou==0){
            printf("\n O Nome ‚.................:%s",Produto.nomeprod);
            printf("\n O Código ‚................:%d",Produto.codprod);
            printf("\n O Valor ‚........:%s",Produto.valorUniprod);
            printf("_____________________________________________\n");
            getch();
        }
        else{
            tamanhoaux=tamanhoaux+fwrite(&Produto,sizeof(struct dadosProd),1,fAuxProd);}}
    fclose(fAuxProd);
    fclose(fProdutos);
    remove("produtos.dat");
    cria_arqProd();
    fProdutos=fopen("produtos.dat","r+");
    fseek(fProdutos,sizeof(struct dadosProd),0);
    fAuxProd=fopen("auxprod.dat","r+");
    fseek(fAuxProd,sizeof(struct dadosProd),0);
    while(fread(&Produto,sizeof(Produto),1,fAuxProd)==1) {
        tamanhoprod=tamanhoprod+fwrite(&Produto,sizeof(struct dadosProd),1,fProdutos);}
    fclose(fAuxProd);
    remove("auxprod.dat");
    fclose(fProdutos);
    printf("\n Produto Excluído - Digite <enter> para continuar___________________\n");
    getch();
}

void excl_arqProd(){
    char op;
    printf("\n Deleta Arquivo <S> ou <N>? ");
    cin>>op;
    op = toupper(op);
    if (op=='S')
    {
        remove("produtos.dat");
        printf("arquivo deletado");}

    else{
        printf("\n Arquivo não foi deletado por sua opção");
        getch();}
    cria_arqProd();}


void menuProd()
{
    system("cls");
    printf("Menu de opções");
    printf("\n");
    printf("1 - Cadastrar Produtos\n");
    printf("2 - Consultar Listar todos Produtos  \n");
    printf("3 - Consultar Por Nome de Produtos \n");
    printf("4 - Alterar Registro de Produtos \n");
    printf("5 - Excluir Registro de Produtos \n");
    printf("6 - Exclui Arquivo total de Produto\n");
    printf("7 - Voltar ao Menu principal \n");
    printf("8 - Sair do Programa");
    printf("Digite uma opção \n");
    cin>>opc;
    switch(opc)
    {
        case 1:cadastraProd();break;
        case 2:consultaProd();break;
        case 3:consulta_nomeProd();break;
        case 4:alteraProd();break;
        case 5:excluiProd();break;
        case 6:excl_arqProd();break;
        case 7:menu(); break;
        case 8:exit(0);
    }
}

void menu()
{
    system("cls");
    printf("Menu de opções");
    printf("\n");
    printf("1 - Acessar Sistema Cliente\n");
    printf("2 - Acessar Sistema Funcionário \n");
    printf("3 - Acessar Sistema Fornecedor \n");
    printf("4 - Acessar Sistema Produto \n");
    printf("8 - Sair do Programa");
    printf("Digite uma opção: \n");
    cin>>opc;
    switch(opc)
    {
        case 1:menuCli();break;
        case 2:menuFunc();break;
        case 3:menuForn();break;
        case 4:menuProd();break;
        case 8:exit(0);
    }
}

int main()//programa prinipal para a chamada de inicial da rotina menu que chama todas as demais
{//inicia o escopo do programa
    setlocale(LC_ALL,"portuguese");
    system("cls");//limpa tela
    cria_arqCli();
    cria_arqFunc();
    cria_arqForn();
    cria_arqProd();
    do //laço de repetição da rotina Menu enquanto não desejo sair do programa
    {
       menu();
    }
    while (opc!=8);//Enquanto do laço de repetição até optar por opc igual 7 para sair do programa
}//finaliza o escopo do programa

