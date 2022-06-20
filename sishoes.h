#include <string>
#pragma GCC diagnostic ignored "-Wwrite-strings"
class DISPLAY{
    public:
        void SIS_MostrarDados(char*, char*, char*, char*, char*, char*);
        void SIS_MostrarDados(char*, char*, char*, char*, char*, char*, char*);
        void SIS_MostrarDados(int, char*, float, char*);
        void SIS_MostrarValorSapato(float, int);
        void SIS_MostrarTempoEntrga(int);
};

class CLIENTE{
    char *nome;
    char *bairro;
    char *rua;
    char *numero;
    char *telefone;
    char *cnpj;

    DISPLAY* disp;

    public:
        CLIENTE(char*, char*, char*, char*, char*, char*);
        void SIS_ExibirDados();
        void SIS_SetDisplay(DISPLAY*);
};

class FORNECEDOR{
    char *nome;
    char *insumos;
    char *bairro;
    char *rua;
    char *numero;
    char *telefone;
    char *cnpj;

    DISPLAY *disp;

    public:
        FORNECEDOR(char*, char*, char*, char*, char*, char*, char*);
        void SIS_SetDisplay(DISPLAY*);
        void SIS_ExibirDados();
};


class INSUMO{
    int referencia;
    char *tipo;
    float preco;
    FORNECEDOR *fornecedor;
    char * data_cadastro;

    DISPLAY *disp;

    public:
        INSUMO(int, char*, float, FORNECEDOR*, char*);
        void SIS_AtualizarPreco(float);
        void SIS_TrocarFornecedor(FORNECEDOR*);
        void SIS_SetDisplay(DISPLAY*);
        void SIS_MostrarIsumo();
        int SIS_GetReferencia();
        float SIS_GetPreco();
};

class ESTOQUE{
    INSUMO **item;
    int *quantidade;
    int local;

    public:
        ESTOQUE();
        void SIS_AdicionarEstoque(INSUMO*, int );
        int SIS_BuscarInsumo(int);
        void SIS_ExibirEstoque();
};

class SAPATO{
    int referencia;
    float preco;
    INSUMO **itens;
    char *data_cadastro;
    CLIENTE *cliente;
    DISPLAY *disp;
    int local;
    int produtividade;

    public:
        SAPATO(int, float, char*, CLIENTE*, int);
        void SIS_InserirInsumo(INSUMO*);
        void SIS_CalcularPreco(float);
        void SIS_InserirPreco(float);
        int SIS_GetProdutividade();
};

class PEDIDO{
    SAPATO **itens;
    int *quantidade;
    float preco;
    int local;

    DISPLAY *disp;

    public:
        PEDIDO();
        void SIS_InserirItens(SAPATO*, int);
        void SIS_SetDisplay(DISPLAY*);
        void SIS_EstimarEntrega();
};