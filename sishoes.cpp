#include "sishoes.h"
#include <iostream>

using namespace std;
 
void DISPLAY::SIS_MostrarDados(char *nome, char* bairro, char* rua, char* numero, char* telefone, char* cnpj){
    cout<<"\n"<<"CLIENTE: ";
    cout<<nome<<"\n";
    cout<<"ENDEREÇO: "<<bairro<<" ";
    cout<<rua<<" ";
    cout<<numero<<"\n";
    cout<<"TELEFONE: "<<telefone<<"\n";
    cout<<"CNPJ: "<<cnpj<<"\n\n\n";
}

void DISPLAY::SIS_MostrarDados(char* nome, char* insumos, char* bairro, char* rua, char* numero, char* telefone, char* cnpj){
    cout<<"FORNECEDOR: ";
    cout<<nome<<"\n";
    cout<<"CNPJ: "<<cnpj<<"\n";
    cout<<"TELEFONE: "<<telefone<<"\n";
    cout<<"ENDEREÇO"<<bairro<<" "<<rua<<" "<<numero<<"\n\n\n";
}

void DISPLAY::SIS_MostrarDados(int referencia, char *tipo, float preco, char* data_cadastro){
    cout<<"REFERENCIA: "<< referencia<<"\n";
    cout<<"TIPO: "<<tipo<<"\n";
    cout<<"PRECO: "<< preco<<"\n";
    cout<<"\n";
}

void DISPLAY::SIS_MostrarValorSapato(float preco, int referencia){
    cout<<"SAPATO:"<<referencia<< "TEM UM VALOR DE:"<<preco<<"\n";
}

void DISPLAY::SIS_MostrarTempoEntrga(int dias){
    cout<<"O tempo de entrega e: "<< dias <<" dias";
}

CLIENTE::CLIENTE(char *nome, char* bairro, char* rua, char* numero, char* telefone, char* cnpj){
    this->nome = nome;
    this->bairro = bairro;
    this->rua = rua;
    this->numero = numero;
    this->telefone = telefone;
    this->cnpj = cnpj;
}

void CLIENTE::SIS_ExibirDados(){
    this->disp->SIS_MostrarDados(this->nome, this->bairro, this->rua, this->numero, this->telefone, this->cnpj);
}

void CLIENTE::SIS_SetDisplay(DISPLAY* disp){
    this->disp = disp;
}


FORNECEDOR::FORNECEDOR(char* nome, char* insumos, char* bairro, char* rua, char* numero, char* telefone, char* CNPJ){
    this->bairro = bairro;
    this->cnpj = CNPJ;
    this->insumos = insumos;
    this->nome = nome;
    this->numero = numero;
    this->rua = rua;
    this->telefone = telefone;
}

void FORNECEDOR::SIS_SetDisplay(DISPLAY *disp){
    this->disp = disp;
}

void FORNECEDOR::SIS_ExibirDados(){
    this->disp->SIS_MostrarDados(this->nome, this->insumos, this->bairro, this->rua, this->numero, this->telefone, this->cnpj);
}


INSUMO::INSUMO(int referencia, char *tipo, float preco, FORNECEDOR* fornecedor, char* dataCadastro){
    this->data_cadastro = dataCadastro;
    this->fornecedor = fornecedor;
    this->preco = preco;
    this->referencia = referencia;
    this->tipo = tipo;
}

void INSUMO::SIS_AtualizarPreco(float novo_preco){
    this->preco = novo_preco;
}

void INSUMO::SIS_SetDisplay(DISPLAY *disp){
    this->disp = disp;
}

void INSUMO::SIS_TrocarFornecedor(FORNECEDOR *novo_fornecedor){
    this->fornecedor = novo_fornecedor;
}

void INSUMO::SIS_MostrarIsumo(){
    this->disp->SIS_MostrarDados(this->referencia, this->tipo, this->preco, this->data_cadastro);
    this->fornecedor->SIS_ExibirDados();
}

int INSUMO::SIS_GetReferencia(){
    return this->referencia;
}

float INSUMO::SIS_GetPreco(){
    return this->preco;
}

ESTOQUE::ESTOQUE(){
    INSUMO **a;
    a = new INSUMO*[200];
    this->item = a;

    int *b;
    b = new int[200];
    this->quantidade = b;

    this->local = 0;
}

void ESTOQUE::SIS_AdicionarEstoque(INSUMO *item, int quantidade){
    if(this->SIS_BuscarInsumo(item->SIS_GetReferencia()) == -1){
        this->item[this->local] = item;
        this->quantidade[this->local] = quantidade;
        this->local++;
    }else{
        this->quantidade[this->SIS_BuscarInsumo(item->SIS_GetReferencia())] = quantidade;
    }
}

int ESTOQUE::SIS_BuscarInsumo(int referencia){
    for (int i = 0; i < this->local; i++)
    {
        if (this->item[i]->SIS_GetReferencia() == referencia)
        {
            return this->local;
        }
    }
    return -1;
}

void ESTOQUE::SIS_ExibirEstoque(){
    for (int i = 0; i < this->local; i++)
    {
        cout<<"REFERENCIA: "<<this->item[i]->SIS_GetReferencia()<<" QUANTIDADE: "<<this->quantidade[i]<<"\n";
    }
}

SAPATO::SAPATO(int referencia, float preco, char *data_cadastro, CLIENTE *cliente, int produtividade){
    this->cliente = cliente;
    this->data_cadastro = data_cadastro;
    this->preco = preco;
    this->referencia =referencia;
    this->produtividade = produtividade;

    INSUMO** a;
    a = new INSUMO*[10];
    this->local = 0;

}

void SAPATO::SIS_InserirInsumo(INSUMO* item){
    this->itens[this->local] = item;
    this->local++;
}

void SAPATO::SIS_CalcularPreco(float pct_lucro){
    float sum = 0;

    for (int i = 0; i < this->local; i++)
    {
        sum += this->itens[i]->SIS_GetPreco();
    }
    
    this->preco = (sum * (pct_lucro+1));
    this->disp->SIS_MostrarValorSapato(this->preco, this->referencia);
}

void SAPATO::SIS_InserirPreco(float preco){
    this->preco = preco;
}

int SAPATO::SIS_GetProdutividade(){
    return this->produtividade;
}

PEDIDO::PEDIDO(){
    SAPATO **a;
    a = new SAPATO*[10];
    this->itens = a;

    int *b;
    b = new int[10];
    this->quantidade = b;

    this->local = 0;
}

void PEDIDO::SIS_InserirItens(SAPATO* item, int quantidade){
    this->itens[this->local] = item;
    this->quantidade[this->local] = quantidade;

    this->local++;
}

void PEDIDO::SIS_EstimarEntrega(){
    int tempo = 0;

    for (int i = 0; i < this->local; i++)
    {
        tempo += this->quantidade[i]/this->itens[i]->SIS_GetProdutividade();
    }
    
    this->disp->SIS_MostrarTempoEntrga(tempo);
}

void PEDIDO::SIS_SetDisplay(DISPLAY *disp){
    this->disp = disp;
}

