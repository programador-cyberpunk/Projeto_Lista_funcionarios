#include<stdio.h>
#include<stdlib.h>
#include "lista.h"


int main() {
int x = 0;
//Lista *li = NULL;
Lista *li = carregaListaSalva("dados.bin"); // carregar a lista salva
//(aqui tive que mudar li para *li e em todas as demais funcoes que chamam *li da lista salva

if(li == NULL){
    li = criaLista(); // se a lista estiver vazia, ou seja, se não há dados salvos de sessões anteriores, cria-se uma nova

}

CLIENTE cli_consulta;

int opcao = 0;
while (opcao != 7) {
                exibirMenu();
                scanf("%d", &opcao);
                getchar();

 switch (opcao) {
    case 1: { //inserir contato
printf("\n");
printf("Digite o codigo do cliente: ");

int cod_duplicado;

  scanf(" %d", &cod_duplicado);
  getchar();

  if(consultaCodigoCliente(li, cod_duplicado, &cli_consulta)){
    printf("\nErro de duplicidade, codigo ja cadastrado!\n\n");
    break;
  }

  cli_consulta.codigo = cod_duplicado;


printf("Digite o nome do cliente: ");

  fgets(cli_consulta.nome, 50, stdin);


 printf("Digite o nome da empresa: ");


  gets(cli_consulta.empresa);


printf("Digite o departamento: ");

  fgets(cli_consulta.departamento, 50, stdin);


 printf("Digite o telefone: ");

  fgets(cli_consulta.telefone, 50, stdin);


printf("Digite o numero de celular: ");

  fgets(cli_consulta.celular, 50, stdin);

printf("Digite o email: ");

  fgets(cli_consulta.email, 50, stdin);


x = insereOrdenado(li, cli_consulta);
if(x){
     printf("\nCliente cadastrado! ");
     salvaDados(li, "dados.bin"); //chamando o método para salvar os dados no fim da rotina de insercao
     system("pause");
}else {
printf("\nCadastro nao realizado!");
 system("pause");
}

system("cls");
break;
    }

    case 3: { // editar contato - para implementar essa funcionalidade usei uma mistura da inserir e da consulta por código
printf("\n");
printf("Digite o codigo do contato: ");
        int cod;
        scanf("%d", &cod);
        fgetc(stdin);
        printf("Digite o nome do contato: ");
  fgets(cli_consulta.nome, 50, stdin);

 printf("Digite o nome da empresa: ");

  gets(cli_consulta.empresa);

printf("Digite o departamento: ");

  fgets(cli_consulta.departamento, 50, stdin);

 printf("Digite o telefone: ");

  fgets(cli_consulta.telefone, 50, stdin);


printf("Digite o numero de celular: ");

  fgets(cli_consulta.celular, 50, stdin);

printf("Digite o email: ");

  fgets(cli_consulta.email, 50, stdin);
    x =  editaPorCodigoCliente(li,  cod,   &cli_consulta);
if(x){

     printf("\nCliente atualizado!");
     salvaDados(li, "dados.bin"); //chamando o método para salvar os dados no fim da rotina de insercao
system("pause");
}else {
printf("\nCadastro nao atualizado!");

system("pause");
}
system("cls");
break;
    }

    case 4:{ //consulta por código
    printf("\n");
    printf("Digite o codigo do funcionario: ");
                        int codigo;
                        scanf("%d", &codigo);
fgetc(stdin);



x = consultaCodigoCliente(li,  codigo, &cli_consulta);
if(x){
    printf("\n=== Consulta de cadastro do cliente ===");
    printf("\n");
    printf("\nCodigo do cliente : %d\n", cli_consulta.codigo);
    printf("\nNome do cliente: %s", cli_consulta.nome);
    printf("\nEmpresa: %s\n", cli_consulta.empresa);
    printf("\nDepartamento: %s", cli_consulta.departamento);
    printf("\nTelefone: %s", cli_consulta.telefone);
    printf("\nCelular: %s", cli_consulta.celular);
    printf("\nE-mail: %s", cli_consulta.email);
    printf("\n\n");
    system("pause");

}else {
printf("Cliente nao encontrado!");
}
system("cls");
break;
    }

case 5:{ //Busca nome
    printf("\nDigite o nome do cliente: ");
    char buscaNome[50];
    fgets(buscaNome,50,stdin);
    buscaNome[strcspn(buscaNome,"\n")]='\0';

    buscaNomeCli(li,buscaNome);
break;
}


    case 6:{ //lista de contatos completa e com dados salvos de outras sessões

   relatorioTotal(li);
   printf("Lista Completa!\n\n");
   break;
}

 case 7:{ //limpar os dados salvos da lista - adicionei essa funcionalidade porque precisei usá-la para testes de salvar os dados




    limpaListaSalva("dados.bin");
    apagaLista(li);
    li = criaLista();
    break;

}

case 8:{ // sair do programa


    apagaLista(li);
    printf("Fim do programa\n");
    return 0;



}




}}}


