/*Um empresa de Suprimentos de Inform�tica contratou uma equipe
de analista e desenvolvedor de sistemas para desenvolver um sistema
de controle de clientes, funcion�rios, fornecedores e produtos.
 Deve apresentar as opera��es de Cadastrar, consultar(listar todos e
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

//declara��o das estruturas de registros das base de dados

struct dadosCli
{
    char nomeCli[20]; //cliente.nome
    char CPFC[20]; //333.444.555-77
    int idadeCli;        //cliente.idade
    float sbaseCli;      //cliente.sbase
    float vcomprasCli;
    //cliente.vcompras.
}Cliente;//vari�vel de registro com os campos

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
//declara��o de vari�veis Global
//declarar os Arquivos(FILE) e seus auxiliares

FILE *fClientes;    // file  - Arquivo    * - Ponteiro din�mico
FILE *fFornecedores;
FILE *fProdutos;
FILE *fFuncionarios;
FILE *fAuxCli;
FILE *fAuxForn;
FILE *fAuxProd;
FILE *fAuxFunc;
int opc;//vari�vel op��o global para no programa principal e na rotina menu optarmos pela fun��o a ser executada conforme sele��o pelo usu�rio
//criar as fun��es de cria��o dos arquivos

//modularizar as fun��es -
void cria_arqCli() //fun��o que vai criar o arquivo fClientes
{//inicia o escopo da rotina cria arquivo de clientes
    if ((fClientes = fopen("clientes.dat","a"))==NULL) //criando e abrindo o arquivo Clientes
    {
        printf("\n Erro de cria��o do arquivo Clientes");
        return;
    }
    fclose(fClientes); //Fechando o arquivo Clientes
}//finaliza o escopo da rotina cria arquivo de clientes

void cria_arqAuxCli(){
    if((fAuxCli=fopen("auxcli.dat","a"))==NULL){
        system("cls");//system clear screen  - Limpa tela
        printf("\n Erro de cria��o de arquivo AuxCli");  //cout<<"Erro de criacao de arquivo";
        return;
    }
    fclose(fAuxCli);
}

void cria_arqProd()
{
    if ((fProdutos = fopen("produtos.dat","a"))==NULL) //criando e abrindo o arquivo Produtos
    {
        printf("\n Erro de cria��o do arquivo Produtos");
        return;
    }
    fclose(fProdutos);
}

void cria_arqAuxProd(){
    if((fAuxProd=fopen("auxprod.dat","a"))==NULL){
        system("cls");
        printf("\n Erro de cria��o de arquivo AuxProd");
        return;
    }
    fclose(fAuxProd);
}

void cria_arqFunc()
{
    if ((fFuncionarios = fopen("funcionarios.dat","a"))==NULL)
    {
        printf("\n Erro de cria��o do arquivo Funcionarios");
        return;
    }
    fclose(fFuncionarios);
}

void cria_arqAuxFunc(){
    if((fAuxFunc=fopen("auxfunc.dat","a"))==NULL){
        system("cls");
        printf("\n Erro de cria��o de arquivo AuxProd");
        return;
    }
    fclose(fAuxFunc);
}


void cria_arqForn()
{
    if ((fFornecedores = fopen("Fornecedores.dat","a"))==NULL) //criando e abrindo o arquivo Fornecedores
    {
        printf("\n Erro de cria��o do arquivo Fornecedores");
        return;
    }
    fclose(fFornecedores); //Fechando o arquivo Fornecedores
}

void cria_arqAuxForn(){
    if((fAuxForn=fopen("auxforn.dat","a"))==NULL){
        system("cls");//system clear screen  - Limpa tela
        printf("\n Erro de cria��o de arquivo AuxForn");  //cout<<"Erro de criacao de arquivo";
        return;
    }
    fclose(fAuxForn);
}

//Iniciar as opera��es com arquivo - Cadastrar, Consultar, Alterar, Excluir
//Opera��es do arquivo Clientes
void flushstdin(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void cadastraCli() //cadastro do arquivo clientes
{ char op; //vari�vel op��o
    system("cls");  //limpa tela
    int tamanho=0; // declara��o da vari�veltamanho para capturar a qtdide de registros cadastrdas
    fClientes = fopen("clientes.dat","r+");//abre o arquivo clientes para leitura e escrita
    rewind(fClientes);  //joga para o primeiro registro do arquivo - posi��o 0
    do{ //la�o de repeti��o para contar a qtidade de registros do arquivo
        fread(&Cliente,sizeof(Cliente),1,fClientes);//leitura do registro no arquivo
        tamanho++;} //tamanho = tamanho + 1 - Contar qtos registros
    while(!feof(fClientes)); //fa�a at� o final do arquivo

    fseek(fClientes,sizeof(Cliente),tamanho); //aponta para a posi��o do arquivo correspondente ao tamanho
    do
    {	flushstdin();	
        system("cls");//limpa tela
		printf("\n Digite o Nome: ");
 		scanf("%[^\n]", Cliente.nomeCli);
		flushstdin();
        printf("\n Digite o CPFC:");
        cin>>Cliente.CPFC;
        printf("\n Digite a idade:");
        cin>>Cliente.idadeCli;
        printf("\n Digite o salario base:");
        cin>>Cliente.sbaseCli;
        printf("\n Digite o valor da compra:");
        cin>>Cliente.vcomprasCli;
        tamanho=tamanho+fwrite(&Cliente,sizeof(struct dadosCli),1,fClientes); //gravando o registro no arquivo
        //tamanho recebe incremento para gravar o pr�ximo registro.
        printf("\n Continuar cadastrando <S> ou <N>:");
        cin>>op;//ler a op��o
        op = toupper(op); //comando que coloca o caracter em ma�usculo
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

void consulta_nomeCli(){  //lista o registro selecionado pelo usu�rio do arquivo cliente
    //vari�veis locais - somente enxergadas aqui
    char nom_pro[20]; //vari�vel para o usu�rio digitar o nome do usu�rio a ser pesquisado no arquivo
    int achou=1;  //vari�vel com sinlizador(flag) para indicar que achou o cliente e pode listar os dados e parar a pesquisa no arquivo
    int localizou=1;//vari�vel que localizou o cliente desejado
    char op; //vari�vel op��o

    system("cls"); //limpa a tela
    fClientes=fopen("clientes.dat","r+"); // abre o arquivo para leitura e escrita
    fseek(fClientes,sizeof(struct dadosCli),0);//aponta pora o Registro 0(inicial) do arquivo
    printf("\n Digite o Nome p/ Procura : "); //Pergunta ao usu�rio qual cliente deseja buscar na consulta
    scanf("%[^\n]", nom_pro);//Us�rio Digita o nome do cliente a ser procurado
    while(fread(&Cliente,sizeof(Cliente),1,fClientes)==1){//la�o de repeti��o para percorrer registro a registro no arquivo at� localizar o cliente desejado
        achou=strcmp(Cliente.nomeCli,nom_pro);//comando que compara as nome digitado pelo usu�rio com o nome do cliente do registro do arquivo
        //comando strcmp pega o valor hexadecimal dos caracteres da string nome do cliente do registro (Cliente.nomeCli)
        //e subtrai do valor hexadecimal dos caracteres da string nome do cliente para ser procurado (nome_pro)
        //se forem iguais o resultado � zero e � alocado para a vari�vel achou, caso contr�rio vai 1 para a var�avel
        if(achou==0)
        { //nomes s�o iguais ent�o achou o cliente desejado
            printf("\n O Nome �.................:%s",Cliente.nomeCli);//lista o nome do cliente na tela
            printf("\n A Idade �................:%d",Cliente.idadeCli);//lista a idade do cliente na tela
            printf("\n O CPFC �................:%d",Cliente.CPFC);
            printf("\n O Sal�rio Bruto �........:%0.2f",Cliente.sbaseCli);
            printf("\n O Valor da Compra �......:%0.2f",Cliente.vcomprasCli);
            printf("\n_____________________________________________\n");
            getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
            localizou=0;
        }}

    if(localizou == 1){ //varreu todo o arquivo e n�o encontrou o nome do cliente para ser consultado
        printf("\n Cliente n�o Cadastrado\n"); //lista na tela
        printf("\n Cadastrar Cliente <S> ou <N>:");//lista na tela para pedir se o usu�rio deseja cadastrar este cliente n�o encontrado
        cin>>op;//l� a op��o do usu�rio em cadastrar ou n�o
        op = toupper(op);//pega o a caracter S ou N digitado pelo usu�rio e coloca em letra ma�uscula
        if (op=='S'){ //compara o valor da vari�vel op para cadastrar ou n�o o novo cliente
            cadastraCli();} //chama a fun��o para cadstrar o novo cliente
        else {fclose(fClientes);} //fecha arquivo clientes
        getch();}}//espera algo a ser teclado e saia da fun��o de consulta cliente pelo nome

void alteraCli(){ //Procura o registro selecionado pelo usu�rio do arquivo cliente para altera��o
    char nom_pro[20]; //vari�vel para o usu�rio digitar o nome do usu�rio a ser pesquisado no arquivo
    int achou;//vari�vel com sinalizador(flag) para indicar que achou o cliente e pode listar os dados para fazer a altera��o e parar a pesquisa no arquivo
    int pos=0;//vari�vel para incrementar a posi��o do registro dentro do arquivo cliente
    system("cls");//limpa a tela
    fClientes=fopen("clientes.dat","r+");// abre o arquivo para leitura e escrita
    fseek(fClientes,sizeof(struct dadosCli),0);//aponta pora o Registro 0(inicial) do arquivo
    printf("\n Digite o Nome p/ Procura : ");//Pergunta ao usu�rio qual cliente deseja buscar na consulta
    scanf("%[^\n]", nom_pro);//Us�rio Digita o nome do cliente a ser procurado
    while(fread(&Cliente,sizeof(Cliente),1,fClientes)==1){//la�o de repeti��o para percorrer registro a registro no arquivo at� localizar o cliente desejado
        achou=strcmp(Cliente.nomeCli,nom_pro);//comando que compara as nome digitado pelo usu�rio com o nome do cliente do registro do arquivo
        //comando strcmp pega o valor hexadecimal dos caracteres da string nome do cliente do registro (Cliente.nomeCli)
        //e subtrai do valor hexadecimal dos caracteres da string nome do cliente para ser procurado (nome_pro)
        //se forem iguais o resultado � zero e � alocado para a vari�vel achou, caso contr�rio vai 1 para a var�avel
        pos++;//incrementa a vari�vel pos 1 a 1 para posicionar o pr�ximo registro dentro do arquivo cliente
        if(achou==0){ //nomes s�o iguais ent�o achou o cliente desejado
            printf("\n O Nome �.................:%s",Cliente.nomeCli); //lista o nome do cliente encontrado na tela
            printf("\n A Idade �................:%d",Cliente.idadeCli);
            printf("\n O CPFFC �................:%d",Cliente.CPFC);
            printf("\n O Sal�rio Bruto �........:%0.2f",Cliente.sbaseCli);
            printf("\n O Valor da Compra �......:%0.2f",Cliente.vcomprasCli);
            printf("_____________________________________________\n");
            printf("Digite <enter> para continuar e alterar____________\n");
            getch(); //espera algoa ser teclado para continuar, permite que vejamos os dados na tela
            //Come�a a pedir para o usu�rio os novos dados a ser alterados
            printf("\n Digite a alter��o do nome do cliente: %s",Cliente.nomeCli);//Apresenta na tela o que o usu�rio deve alterar
            cin>>Cliente.nomeCli;//L� o novo valor de altera��o do nome do cliente
            printf("\n Digite a idade:");//Apresenta na tela o que o usu�rio deve alterar
            cin>>Cliente.idadeCli;//L� o novo valor de altera��o da idade do cliente
            printf("\n Digite o salario base:");
            cin>>Cliente.sbaseCli;
            printf("\n Digite o CPFC");
            cin>>Cliente.CPFC;
            printf("\n Digite o valor da compra:");
            cin>>Cliente.vcomprasCli;
            fseek(fClientes,pos*sizeof(struct dadosCli),SEEK_SET);//posiciona o ponteiro de registro do arquivo na posi��o pos registrada para alterar o registro certo dentro do arquivo
            fwrite(&Cliente,sizeof(struct dadosCli),1,fClientes);//Grava os dados alterados no registro certo dentro do arquivo
            fseek(fClientes,sizeof(struct dadosCli),SEEK_END);}
        printf("Digite <enter> para continuar___________________\n");
        getch();}//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
    fclose(fClientes);}//fecha o arquivo Clientes e sai da fun��o altera


void excluiCli() //Procura o registro selecionado pelo usu�rio do arquivo cliente para exclus�o
{
    char nom_pro[20];//vari�vel para o usu�rio digitar o nome do usu�rio a ser pesquisado no arquivo
    int achou=1;//vari�vel com sinalizador(flag) para indicar que achou o cliente e pode listar os dados para fazer a exclus�o e parar a pesquisa no arquivo
    int tamanhoaux=0;//var�aveis para ter o controle de registro a registro do tamanho do arquivo auxiliar de clientes
    int tamanhocli=0;//var�aveis para ter o controle de registro a registro do tamanho do arquivo de clientes

    system("cls");//linpa tela
    fClientes=fopen("clientes.dat","r+");// abre o arquivo para leitura e escrita
    fseek(fClientes,sizeof(struct dadosCli),0);//aponta pora o Registro 0(inicial) do arquivo
    cria_arqAuxCli();//chama a fun��o para criar o arquivo auxiliar de clientes
    fAuxCli=fopen("auxcli.dat","r+");//abre o arquivo auxiliar de clientes para leitura e escrita
    fseek(fAuxCli,sizeof(struct dadosCli),0);//aponta por segura��o ao registro 0(inicial) do arquivo auxiliar de clientes
    //come�a a procura do registro a ser exclu�do no arquivo clientes
    printf("\n Digite o Nome do cliente p/ Procura : ");//Pergunta ao usu�rio qual cliente deseja buscar na consulta para ser exclu�do
    scanf("%[^\n]", nom_pro);//Us�rio Digita o nome do cliente a ser procurado para exclus�o
    while(fread(&Cliente,sizeof(Cliente),1,fClientes)==1){//la�o de repeti��o para ler registro a registro do arquivo clientes at� encontrar o desejado
        achou=strcmp(Cliente.nomeCli,nom_pro);//comando que compara as nome digitado pelo usu�rio com o nome do cliente do registro do arquivo
        //comando strcmp pega o valor hexadecimal dos caracteres da string nome do cliente do registro (Cliente.nomeCli)
        //e subtrai do valor hexadecimal dos caracteres da string nome do cliente para ser procurado (nome_pro)
        //se forem iguais o resultado � zero e � alocado para a vari�vel achou, caso contr�rio vai 1 para a var�avel
        if(achou==0){ //nomes s�o iguais ent�o achou o cliente desejado
            printf("\n O Nome �.................:%s",Cliente.nomeCli);//lista o nome do cliente encontrado na tela
            printf("\n A Idade �................:   %d",Cliente.idadeCli);
            printf("\n O CPFC �................:   %d",Cliente.CPFC);
            printf("\n O Sal�rio Bruto �........:%0.2f",Cliente.sbaseCli);
            printf("\n O Valor da Compra �......:%0.2f",Cliente.vcomprasCli);
            printf("_____________________________________________\n");
            getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
        }
        else{ //caso n�o entre no achou==0 ent�o vai para esta parte do sen�o para transferir uma c�pia do registro que n�o � o desejado a excluir
            //do arquivo clientes para o arquivo auxiliar do cliente
            tamanhoaux=tamanhoaux+fwrite(&Cliente,sizeof(struct dadosCli),1,fAuxCli);}}//grava o registro do arquivo cliente no arquivo aux cliente um a um
    //cada registro gravado no aux a fun��o fwrite gera 1 que � incerementado na vari�vel tamanhoaux para gravar
    //no pr�ximo registro livre no arquivo e n�o sobrepor resgistros.
    fclose(fAuxCli);//fecha arquivo AuxCli
    fclose(fClientes);//fecha arquivo Clientes
    remove("clientes.dat");//remove o arquivo inicial de Clientes totalmente pois j� trasnferimos aqueles registros com excess�o do a ser exclu�do
    cria_arqCli();//chama a fun��o para criar novamente o arquivo Clientes zerado
    fClientes=fopen("clientes.dat","r+");//Abre o novo arquivo Clientes para ler e gravar dados
    fseek(fClientes,sizeof(struct dadosCli),0);//Aponta por seguran�a para o registro 0(inicial) do arquivo clientes

    fAuxCli=fopen("auxcli.dat","r+");//abre o arquivi AuxCli para transferir de volta os registros dos clientes que n�o eram para ser exclu�dos
    fseek(fAuxCli,sizeof(struct dadosCli),0);//Aponta por seguran�a para o registro 0(inicial) do arquivo AuxCli
    while(fread(&Cliente,sizeof(Cliente),1,fAuxCli)==1) {//la�o de repeti��o para trasnferir registros 1 a 1 do arquivo AuxCli para o arquivo Clientes
        tamanhocli=tamanhocli+fwrite(&Cliente,sizeof(struct dadosCli),1,fClientes);}//grava o registro do arquivo AucCLi no arquivo Clientes um a um
    //cada registro gravado no Clinetes a fun��o fwrite gera 1 que � incerementado na vari�vel tamanhocli para gravar
    //no pr�ximo registro livre no arquivo e n�o sobrepor resgistros.
    fclose(fAuxCli);//fecha arquivo auxcli
    remove("auxcli.dat");//remove completamente o arquivo auxcli pois j� trensferimos os registros para o novo arquivo Clientes agora sem o registro que foi exclu�do
    fclose(fClientes);//fecha aqruivo Clientes
    printf("\n Cliente Exclu�do - Digite <enter> para continuar___________________\n");
    getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
}//fecha a fun��o de exclus�o de registro de clientes


void excl_arqCli(){//fun��o para excluir completamente todo o arquivo de clientes de uma vez s�
    char op;//vari�vel de seguran�a para optar em excluir mesmo ou n�o o arquivo de clientes
    printf("\n Deleta Arquivo <S> ou <N>? ");//informa��o na tela para o usu�rio
    cin>>op;//leitura da op��o de deletar S ou n�o N o arquivo Clientes inteiro
    op = toupper(op);//pega o a caracter S ou N digitado pelo usu�rio e coloca em letra ma�uscula
    if (op=='S')//compara o valor da vari�vel op para cadastrar ou n�o o novo cliente
    {
        remove("clientes.dat");//remove completamente o arquivo inteiro de Clientes
        printf("arquivo deletado");}//informa na tela para o usu�rio que deletou o arquivo

    else{//sen�o optou por N�o - N
        printf("\n Arquivo n�o foi deletado por sua op��o");//informa na tela para o usu�rio que na� deletou o arquivo
        getch();}//espera algoa ser teclado para continuar, permite que vejamos os dados na tela e fecha a fun��o de exclus�o total do arquivo Clientes
    cria_arqCli();}//cria arquivo para uso futuro


void menuCli()//cria��o da fun��o Menu de op��es
{ //inicia o escopo da rotina Menu
	char opc;
    system("cls");//limpa a tela
    printf("Menu de opcoes");//mostra na tela para o usu�rios as op��es de Menu
    printf("\n");//pula linha
    printf("1 - Cadastrar Clientes\n");
    printf("2 - Consultar Listar todos Clintes  \n");
    printf("3 - Consultar Por Nome de Cliente \n");
    printf("4 - Alterar Registro de Cliente \n");
    printf("5 - Excluir Registro de Clientes \n");
    printf("6 - Exclui Arquivo total de Clientes\n");
    printf("7 - Voltar ao Menu principal \n");
    printf("8 - Fechar o programa \n");
    printf("Digite uma opcao \n");//pede a op��o via teclado do usu�rio
    cin>>opc;//l� a vari�vel global op��o do menu para chamar a fun�ao
    flushstdin();
    switch(opc)//estrutura de composi��o de v�rios if
    {
        case '1':cadastraCli();break; //caso a opc igual 1 chamada rotina cadastra executando-a retornando para o menu
        case '2':consultaCli();break;//caso a opc igual 2 chamada rotina consulta Cliente Listar executando-a retornando para o menu
        case '3':consulta_nomeCli();break;
        case '4':alteraCli();break;
        case '5':excluiCli();break;
        case '6':excl_arqCli();break;
        case '7':menu();break;
        case '8':exit(0);//fun��o para sair totalmente do programa
        default:
    	printf("Valor inv�lido\n");
    	printf("Aperte enter para voltar\n");
    	system("cls");
    	menuCli();
    }
}//finaliza o escopo da rotina Menu





//Opera��es do arquivo Funcionario

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
    {	flushstdin();
        system("cls");

	printf("\n Digite o nome do funcionario: ");
 	scanf("%[^\n]", Funcionario.nomeFunc);
	flushstdin();
    printf("\n Digite o Email:");
        cin>>Funcionario.emailFunc;
	printf("\n Digite o endere�o do funcionario: ");
 	scanf("%[^\n]", Funcionario.endeFunc);
	flushstdin();
	 	flushstdin();
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
        printf("Endere�o funcion�rio :       %s\n",Funcionario.endeFunc);
        printf("Salario Funcion�rio:     %.2f\n",Funcionario.salario);
        printf("CPFF Funcion�rio: %s\n",Funcionario.CPFF);
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
    scanf("%[^\n]", nom_pro);
    while(fread(&Funcionario,sizeof(Funcionario),1,fFuncionarios)==1){
        achou=strcmp(Funcionario.nomeFunc,nom_pro);
        if(achou==0)
        {
            printf("\n O Nome �.................:%s",Funcionario.nomeFunc);
            printf("\n O Email �.................:%s",Funcionario.emailFunc);
            printf("\n O Endere�o �................:%s",Funcionario.endeFunc);
            printf("\n O Sal�rio  �........:%.2f",Funcionario.salario);
            printf("\n O CPFF �......:%s",Funcionario.CPFF);
            printf("\n_____________________________________________\n");
            getch();
            localizou=0;
        }}

    if(localizou == 1){
        printf("\n Funcion�rio n�o Cadastrado\n");
        printf("\n Cadastrar Funcion�rio <S> ou <N>:");
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
    scanf("%[^\n]", nom_pro);
    while(fread(&Funcionario,sizeof(Funcionario),1,fFuncionarios)==1){
        achou=strcmp(Funcionario.nomeFunc,nom_pro);
        pos++;
        if(achou==0){
            printf("\n O Nome �.................:%s",Funcionario.nomeFunc);
            printf("\n O Email �.................:%s",Funcionario.emailFunc);
            printf("\n O Endere�o �................:%s",Funcionario.endeFunc);
            printf("\n O Sal�rio �........:%0.2f",Funcionario.salario);
            printf("\n O CPFF �......:%s",Funcionario.CPFF);
            printf("_____________________________________________\n");
            printf("Digite <enter> para continuar e alterar____________\n");
            getch();

            printf("\n Digite a alter��o do nome do funcion�rio: %s",Funcionario.nomeFunc);
            cin>>Funcionario.nomeFunc;
            printf("\n Digite o email:");
            cin>>Funcionario.emailFunc;
            printf("\n Digite o endere�o:");
            cin>>Funcionario.endeFunc;
            printf("\n Digite o salario:");
            cin>>Funcionario.salario;
            printf("\n Digite o CPFF do funcion�rio");
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
    printf("\n Digite o Nome do funcion�rio p/ Procura : ");
    scanf("%[^\n]", nom_pro);
    while(fread(&Funcionario,sizeof(Funcionario),1,fFuncionarios)==1){
        achou=strcmp(Funcionario.nomeFunc,nom_pro);
        if(achou==0){
            printf("\n O Nome �.................:%s",Funcionario.nomeFunc);
            printf("\n O Email �.................:%s",Funcionario.emailFunc);
            printf("\n O Endere�o �................:%s",Funcionario.endeFunc);
            printf("\n O Sal�rio �........:%0.2f",Funcionario.salario);
            printf("\n O CPFF �......:%s",Funcionario.CPFF);
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
    printf("\n Funcion�rio Exclu�do - Digite <enter> para continuar___________________\n");
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
        printf("\n Arquivo n�o foi deletado por sua op��o");
        getch();}
    cria_arqFunc();}


void menuFunc()
{	char opc;
    system("cls");
    printf("Menu de op��es");
    printf("\n");
    printf("1 - Cadastrar Funcion�rios\n");
    printf("2 - Consultar Listar todos Funcion�rios  \n");
    printf("3 - Consultar Por Nome de Funcion�rio \n");
    printf("4 - Alterar Registro de Funcion�rio \n");
    printf("5 - Excluir Registro de Funcion�rios \n");
    printf("6 - Exclui Arquivo total de Funcion�rios\n");
    printf("7 - Voltar ao Menu principal \n");
    printf("8 - Sair do programa \n");
    printf("Digite uma opcao \n");
    cin>>opc;
    flushstdin();
    switch(opc)
    {
        case '1':cadastraFunc();break;
        case '2':consultaFunc();break;
        case '3':consulta_nomeFunc();break;
        case '4':alteraFunc();break;
        case '5':excluiFunc();break;
        case '6':excl_arqFunc();break;
        case '7':menu();break;
        case '8':exit(0);
        default:
    	printf("Valor inv�lido\n");
    	printf("Aperte enter para voltar\n");
    	system("cls");
    	menuFunc();
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
    {	flushstdin();
        system("cls");

		printf("\n Digite o nome: ");
 		scanf("%[^\n]", Fornecedor.nomeForn);
	    flushstdin();
		printf("\n Digite o endere�o do fornecedor: ");
 		scanf("%[^\n]", Fornecedor.endeForn);
		flushstdin();
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
        printf("Endere�o Fornecedor :       %s\n",Fornecedor.endeForn);
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
    scanf("%[^\n]", nom_pro);
    while(fread(&Fornecedor,sizeof(Fornecedor),1,fFornecedores)==1){
        achou=strcmp(Fornecedor.nomeForn,nom_pro);
        if(achou==0)
        {
            printf("\n O Nome �.................:%s",Fornecedor.nomeForn   );
            printf("\n O Endere�o �................:%s",Fornecedor.endeForn);
            printf("\n O Email  �........:%s",Fornecedor.emailForn);
            printf("\n O CNPJ �......:%s",Fornecedor.cnpj);
            printf("\n_____________________________________________\n");
            getch();
            localizou=0;
        }}

    if(localizou == 1){
        printf("\n Fornecedor n�o Cadastrado\n");
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
    scanf("%[^\n]", nom_pro);
    while(fread(&Fornecedor,sizeof(Fornecedor),1,fFornecedores)==1){
        achou=strcmp(Fornecedor.nomeForn,nom_pro);
        pos++;
        if(achou==0){
            printf("\n O Nome �.................:%s",Fornecedor.nomeForn);
            printf("\n O Endere�o �................:%s",Fornecedor.endeForn);
            printf("\n O Email �........:%s",Fornecedor.emailForn);
            printf("\n O CNPJ �......:%s",Fornecedor.cnpj);
            printf("_____________________________________________\n");
            printf("Digite <enter> para continuar e alterar____________\n");
            getch();

            printf("\n Digite a alter��o do nome do fornecedor: %s",Fornecedor.nomeForn);
            cin>>Fornecedor.nomeForn;
            printf("\n Digite o endere�o:");
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
    scanf("%[^\n]", nom_pro);
    while(fread(&Fornecedor,sizeof(Fornecedor),1,fFornecedores)==1){
        achou=strcmp(Fornecedor.nomeForn,nom_pro);
        if(achou==0){
            printf("\n O Nome �.................:%s",Fornecedor.nomeForn);
            printf("\n O Endere�o �................:%s",Fornecedor.endeForn);
            printf("\n O Email �........:%s",Fornecedor.emailForn);
            printf("\n O CNPJ �......:%s",Fornecedor.cnpj);
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
    printf("\n Fornecedor Exclu�do - Digite <enter> para continuar___________________\n");
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
        printf("\n Arquivo n�o foi deletado por sua op��o");
        getch();}
    cria_arqForn();}


void menuForn()
{	char opc;
    system("cls");
    printf("Menu de op��es");
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
    flushstdin();
    switch(opc)
    {
        case '1':cadastraForn();break;
        case '2':consultaForn();break;
        case '3':consulta_nomeForn();break;
        case '4':alteraForn();break;
        case '5':excluiForn();break;
        case '6':excl_arqForn();break;
        case '7':menu();break;
        case '8':exit(0);
        default:
    	printf("Valor inv�lido\n");
    	printf("Aperte enter para voltar\n");
    	system("cls");
    	menuForn();
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
    {	flushstdin();
        system("cls");

	printf("\n Digite o nome do produto: ");
 	scanf("%[^\n]", Produto.nomeprod);
	flushstdin();
	    cout<<"\n Digite o c�digo do produto:";
        cin>>Produto.codprod;
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
    scanf("%[^\n]", nom_pro);
    while(fread(&Produto,sizeof(Produto),1,fProdutos)==1){
        achou=strcmp(Produto.nomeprod,nom_pro);
        if(achou==0)
        {
            printf("\n O Nome �.................:%s",Produto.nomeprod);
            printf("\n O Codigo �................:%d",Produto.codprod);
            printf("\n O Valor �nico  �........:%0.2f",Produto.valorUniprod);
            printf("\n_____________________________________________\n");
            getch();
            localizou=0;
        }}

    if(localizou == 1){
        printf("\n Produto n�o Cadastrado\n");
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
    scanf("%[^\n]", nom_pro);
    while(fread(&Produto,sizeof(Produto),1,fProdutos)==1){
        achou=strcmp(Produto.nomeprod,nom_pro);
        pos++;
        if(achou==0){
            printf("\n O Nome �.................:%s",Produto.nomeprod);
            printf("\n O C�digo �................:%d",Produto.codprod);
            printf("\n O Valor �........:%0.2f",Produto.valorUniprod);
            printf("_____________________________________________\n");
            printf("Digite <enter> para continuar e alterar____________\n");
            getch();

            printf("\n Digite a alter��o do nome do fornecedor: %s",Produto.nomeprod);
            cin>>Produto.nomeprod;
            printf("\n Digite o c�digo:");
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
    scanf("%[^\n]", nom_pro);
    while(fread(&Produto,sizeof(Produto),1,fProdutos)==1){
        achou=strcmp(Produto.nomeprod,nom_pro);
        if(achou==0){
            printf("\n O Nome �.................:%s",Produto.nomeprod);
            printf("\n O C�digo �................:%d",Produto.codprod);
            printf("\n O Valor �........:%s",Produto.valorUniprod);
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
    printf("\n Produto Exclu�do - Digite <enter> para continuar___________________\n");
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
        printf("\n Arquivo n�o foi deletado por sua op��o");
        getch();}
    cria_arqProd();}


void menuProd()
{	char opc;
    system("cls");
    printf("Menu de op��es");
    printf("\n");
    printf("1 - Cadastrar Produtos\n");
    printf("2 - Consultar Listar todos Produtos  \n");
    printf("3 - Consultar Por Nome de Produtos \n");
    printf("4 - Alterar Registro de Produtos \n");
    printf("5 - Excluir Registro de Produtos \n");
    printf("6 - Exclui Arquivo total de Produto\n");
    printf("7 - Voltar ao Menu principal \n");
    printf("8 - Sair do Programa\n");
    printf("Digite uma op��o\n");
    cin>>opc;
    flushstdin();
    switch(opc)
    {
        case '1':cadastraProd();break;
        case '2':consultaProd();break;
        case '3':consulta_nomeProd();break;
        case '4':alteraProd();break;
        case '5':excluiProd();break;
        case '6':excl_arqProd();break;
        case '7':menu(); break;
        case '8':exit(0);
    default:
    	printf("Valor inv�lido\n");
    	printf("Aperte enter para voltar\n");
    	system("cls");
    	menuProd();}
}

void menu()
{
	char opc;    
    system("cls");
    printf("Menu de op��es");
    printf("\n");
    printf("1 - Acessar Sistema Cliente\n");
    printf("2 - Acessar Sistema Funcion�rio \n");
    printf("3 - Acessar Sistema Fornecedor \n");
    printf("4 - Acessar Sistema Produto \n");
    printf("8 - Sair do Programa\n ");
    printf("Digite uma op��o: \n");
    cin>>opc;
    switch(opc)
    {
        case '1':menuCli();break;
        case '2':menuFunc();break;
        case '3':menuForn();break;
        case '4':menuProd();break;
        case '8':exit(0);
    default:
    	printf("Valor inv�lido\n");
    	printf("Aperte enter para voltar\n");
    	system("cls");
    	menu();
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
    do //la�o de repeti��o da rotina Menu enquanto n�o desejo sair do programa
    {
       menu();
    }
    while (opc!=8);//Enquanto do la�o de repeti��o at� optar por opc igual 7 para sair do programa
}//finaliza o escopo do programa

