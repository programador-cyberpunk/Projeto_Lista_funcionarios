#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

struct elemento{

CLIENTE dados;
struct elemento *prox;
};

typedef struct elemento ELEM;


Lista *criaLista() {//cria lista de acordo com os slides de lista dinamica

Lista *li;
li = (Lista*) malloc(sizeof(Lista));
if(li != NULL) {
    *li = NULL;
}
return li;
}


void exibirMenu() { // opcoes do menu
            printf("=== MENU ===\n\n");
            printf("1. Inserir funcionario\n");
            printf("2. Remover funcionario\n");
            printf("3. Editar funcionario\n");
            printf("4. Buscar funcionario por codigo\n");
            printf("5. Buscar funcionario por nome\n");
            printf("6. Exibir lista de funcionarios\n");
            printf("7. Apagar Lista Salva\n");
            printf("8. Sair\n\n");
            printf("Digite a opcao desejada: ");
        }

void abortaPrograma() { //funcao para terminar o programa em caso de método que recebe lista cheia ativado e recebendo lista vazia
printf("Erro! Lista nao foi alocada, ");
printf("Programa sera encerrado\n\n\n ");
system("pause");
exit(1);
}
void apagaLista(Lista *li) { //reseta os valores da sessão

if(li != NULL){
    ELEM *no;
    while ((*li) != NULL){
        no = *li;
        *li = (*li)->prox;
        free(no);
    }
    free(li);
}
}

int tamanhoLista(Lista *li) {//calcula o tamanho da lista de acordo com os slides de lista dinamica

if (li == NULL){

    abortaPrograma();
}
int acum = 0;
ELEM *no = *li;
while(no != NULL){
    acum++;
    no = no->prox;
}
return acum;
}
int listaCheia(Lista *li) { //verifica se a lista está cheia de acordo

if(li == NULL) {

    abortaPrograma();
}
return 0;
}
int listaVazia(Lista *li) { //verifica se a lista e está vazia - aqui tive que adicionar o check se o ponteiro *li está vazio
    // pois caso contrário o método de salvar dados insere o contato novo e mais uma instancia do último contato salvo
//if(li == NULL) {

    //abortaPrograma();
//}
//if (li == NULL) {
   // return 1;
//}
//return 0;

    if (li == NULL || *li == NULL) {
        return 1;
    }
    return 0;


}

int insereOrdenado(Lista *li, CLIENTE cli) { //inserir contato alocando memória

    if(li == NULL){

        abortaPrograma();
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }
    no->dados = cli;
    if(listaVazia(li)){
        no->prox = (*li);
        *li = no;

        return cli.codigo;

    }else {
    ELEM *ant, *atual = *li;
    while(atual != NULL && atual->dados.codigo < cli.codigo){
        ant = atual;
        atual = atual->prox;
    }
    if(atual == *li) {
        no->prox = (*li);
        *li = no;

    }else {
    no->prox = ant->prox;
    ant->prox = no;

    }
    return cli.codigo;

    }

} ;

int consultaCodigoCliente(Lista *li, int cod, CLIENTE *cli){// consulta por código
if(li == NULL){
    abortaPrograma();
}
ELEM *no = *li;
while(no != NULL && no->dados.codigo != cod){
    no = no->prox;
}
if(no == NULL){
    return 0;
}else {
*cli = no->dados;
return 1;
}
};

void buscaNomeCli(Lista *li, char *nome){
    if(li == NULL){
        abortaPrograma();
    }
    ELEM *no = *li;
    int semNome = 0;

while (no != NULL) {
    if (strstr(no->dados.nome, nome) != NULL) {
         printf("\n=======================\//======================\n");
         printf("\nCodigo: %d\n", no->dados.codigo);
         printf("\nNome: %s", no->dados.nome);
         printf("\nEmpresa: %s\n", no->dados.empresa);
         printf("\nDepartamento: %s", no->dados.departamento);
         printf("\nTelefone: %s", no->dados.telefone);
         printf("\nCelular: %s", no->dados.celular);
         printf("\nEmail: %s\n", no->dados.email);

    semNome = 1;
 }
 no = no->prox;
 }

 if (!semNome) {
 printf("\nNome de cliente não encontrado!\n");
 }

};




    void relatorioTotal(Lista *li){// lista total(salva)
if (li == NULL || *li == NULL){
    printf("a lista nao foi alocada...\n\n\n");
    return;
} else {

ELEM *no = *li;

printf("\n ========== \\ RELATORIO TOTAL DE CLIENTES ======// \n\n");

while (no !=NULL){
    printf("Codigo: %d\n\n", no->dados.codigo);
    printf("Nome: %s\n", no->dados.nome);
    printf("Empresa: %s\n\n", no->dados.empresa);
    printf("Departamento: %s\n", no->dados.departamento);
    printf("Telefone: %s\n", no->dados.telefone);
    printf("Celular: %s\n", no->dados.celular);
    printf("Email: %s\n", no->dados.email);
    printf("=======================\\//======================\n\n");
    no = no->prox;
}
printf("\n ========== \\ FIM DO RELATORIO ======// \n\n");}
};

int editaPorCodigoCliente(Lista *li,  int cod, CLIENTE *cli){//edicao por código


CLIENTE cli_consulta;
if(li == NULL){
    abortaPrograma();
}
ELEM *no = *li;
while(no != NULL && no->dados.codigo != cod){//o método usa a parte de busca da busca por código
      no = no->prox;
}
if(no == NULL){
    return 0;
}else {//e se encontra um resultado para a busca, atribui o código salvo na busca e o atribui ao dado codigo da scruct do item
cli->codigo = no->dados.codigo;
    no->dados = *cli;

return 1;


    }





};

void salvaDados(Lista *li, const char *contatosSalvos){ //recolhe os contatos e os grava no bin

FILE *arquivo = fopen(contatosSalvos, "wb");//abre e salva no arquivo binário
if (arquivo == NULL) {

    printf("Nenhuma lista salva!");
    return;
}

ELEM *no = *li;//o vetor do nó equivale ao vetor dos itens da lista

while (no != NULL) {//enquanto o elemento dado pelo nó recebido pelo *li não for vazio

    fwrite(&(no->dados), sizeof(CLIENTE), 1, arquivo);//grava os dados que foram recebidos em no atual alocando-os o tamanho de memória da struct em 1 registro
    no = no->prox;//repete para o próximo nó se houver
}
fclose(arquivo);
printf("Dados salvos! ");
};


Lista carregaListaSalva (const char *contatosSalvos){ //mostra lista salva

FILE *arquivo = fopen(contatosSalvos, "rb");//abre e le o arquivo binário
if (arquivo == NULL){
    printf("Nenhuma lista salva! Insira um contato!");
    return NULL;
}
Lista *li = criaLista();//cria a lista de acordo com o ponteiro *li
//Lista li = NULL;
CLIENTE cli;
while(fread(&cli, sizeof(CLIENTE), 1, arquivo)== 1) {// faz leitura de cada item de estruct cli(CLIENTE)

    //ELEM *novo = (ELEM*) malloc(sizeof(ELEM));//essa foi uma tentativa que deu errado
    //if (novo == NULL){//dessa forma o programa só terminava inesperadamente quando o método era ativado

        //printf("Erro de memória!\n");
        //fclose(arquivo);
        //return li;
    //}

    CLIENTE existente;//nova instancia da mesma struct para armazenar valores a serem lidos caso necessario
        if (consultaCodigoCliente(li, cli.codigo, &existente)) //verifica se o cliente já existe
            //vita um problema duplicidade que estava tendo
        {
            //se existir nada acontece
        } else
            {
            insereOrdenado(li, cli);// se o cliente não existir, ele é adicionado ordenadamente
        }
}
fclose(arquivo);
printf("Dados carregados com sucesso!\n\n");
return li;
};

void limpaListaSalva(const char *contatosSalvos) {//limpa a lista salva
    if (remove(contatosSalvos) == 0) {//usa a funcao remove como arquivo salvo na salvaDados como parametro
        printf("Lista de contatos salva foi limpa !\n");
    } else {
        printf("Erro ao limpar a lista salva ou arquivo não encontrado.\n");
    }
}
