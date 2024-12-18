typedef struct cliente{
    int codigo;
    char  nome[50];
    char  empresa[50];
    char  departamento[50];
    char  telefone[50];
    char  celular[50];
    char  email[50];}CLIENTE;

    typedef struct elemento* Lista;

    Lista *criaLista();

    void abortaPrograma();
    void apagaLista();
    //void exibirClientes(Cliente* lista);
    void relatorioTotal(Lista *li);
    //void limpaListaSalva(const char *contatosSalvos) //programa quebra se declarar esse método aqui | deixar comentado
    void salvaDados(Lista *li, const char *contatosSalvos);

    void buscaNomeCli(Lista *li, char *nomeCli);

    Lista carregaListaSalva (const char *contatosSalvos);
    int tamanhoLista(Lista *li);
    int listaCheia(Lista *li);
    int listaVazia(Lista *li);
    int insereInicio(Lista *li, CLIENTE cli);
    int insereFinal(Lista *li, CLIENTE cli);
    int insereOrdenado(Lista *li, CLIENTE cli);
    int consultaCodigoCliente(Lista *li, int cod, CLIENTE *cli);
    int editaPorCodigoCliente(Lista *li, int cod, CLIENTE *cli);





