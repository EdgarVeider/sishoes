#include <iostream>
#include "sishoes.h"

using namespace std;

int main(){
    DISPLAY disp;
    CLIENTE c1("radames", "Guanabara", "Av Prof Nicolau DelMonte", "1456", "(44)9999-9999", "5456654654651");
    c1.SIS_SetDisplay(&disp);
    c1.SIS_ExibirDados();

    FORNECEDOR f1("Inter Viras", "Viras", "Integraçao", "AV Major Nicacio", "478", "(16)9999-4444", "46541614354-01");
    f1.SIS_SetDisplay(&disp);
    f1.SIS_ExibirDados();

    INSUMO in1(142,"vira", 2.92, &f1, "30/06/2022");
    in1.SIS_MostrarIsumo();

    ESTOQUE e1;
    e1.SIS_AdicionarEstoque(&in1, 50);
    e1.SIS_ExibirEstoque();

    SAPATO s1(125, 39.56, "30/05/2022", &c1, 120);
    s1.SIS_InserirInsumo(&in1);
    s1.SIS_CalcularPreco(10.0);

    PEDIDO p1;
    p1.SIS_InserirItens(&s1, 600);
    p1.SIS_EstimarEntrega();

    return 0;
}