#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

//! variaveis menu_cliente

int i, novos_cadastr, posicao, N_cadastro_realizados, opc, opc2, valor, total, num_matricula[100], saldo_alun[100];
char nome[100][20], info_adicionais[100][20];

//! vairaveis menu_venda
int N_cadastro_produtos, novos_cadastr_produ, prod, compra, resto = 0, preco_produ[100], qtd_estoque[100], valor_total = 0;
char nome_produto[100][20];

main()
{
    SetConsoleOutputCP(CP_UTF8);

    system("cls");

    do
    {
        for (i = 0; i < 28; i++)
        {
            printf(".");
        };

        printf("\nSistema de gestao de cantina\n");

        for (i = 0; i < 28; i++)
        {
            printf(".");
        };

        printf("\n\nServicos disponiveis\n");

        printf("\n1. Menu cliente\n2. Menu de venda\n3. Encerrar o dia\n");

        for (i = 0; i < 28; i++)
        {
            printf(".");
        };

        printf("\n: ");

        scanf("%i", &opc);

        system("cls");

        switch (opc)
        {
        case 1:
            int menu_cliente();
            return menu_cliente();
            break;

        case 2:
            int menu_venda();
            return menu_venda();
            break;

        case 3:
            printf("Mais um dia encerrado. ;)");
            break;
        }

    } while (opc != 3);
}

int back()
{
    printf("\nPreciose enter for continuar...");

    getch();

    system("cls");

    int menu_cliente();

    return menu_cliente();
}

int back2()
{
    printf("\nPreciose enter for continuar...");

    getch();

    system("cls");

    int menu_venda();

    return menu_venda();
}

//! Configurações do menu cliente.

int menu_cliente()
{
    do
    {

        for (i = 0; i < 22; i++)
        {
            printf(".");
        };

        printf("\n     MENU CLIENTE\n");

        for (i = 0; i < 22; i++)
        {
            printf(".");
        };

        printf("\n1. Cadastro de alunos\n2. Consulta de Saldo\n");

        printf("3. Registo de Compra\n4. Recarga de saldo\n5. Relatorio de Saldo\n6. Menu Principal\n");

        for (i = 0; i < 22; i++)
        {
            printf(".");
        };

        printf("\n\n:");

        scanf("%i", &opc2);

        system("cls");

        switch (opc2)
        {
        case 1:
            int cadas_Aluns();
            return cadas_Aluns();
            break;

        case 2:
            int saldo_aluno();
            return saldo_aluno();
            break;

        case 3:

        case 4:
            int recarga();
            return recarga();
            break;

        case 5:
            int relatorio();
            return relatorio();
            break;

        case 6:
            return main();
            break;
        }

    } while (opc2 != 6);

    return 0;
}

int cadas_Aluns()
{

    printf("Número de cadastros ja realizados? : ");

    scanf("%i", &N_cadastro_realizados);

    system("cls");

    printf("Numero de novos cadastro? : ");

    scanf("%i", &novos_cadastr);

    system("cls");

    for (i = 0; i < novos_cadastr; i++)
    {
        printf("Degite o primeiro e ultimo nome: ");

        scanf(" %[^\n]", nome[(i + 1) + N_cadastro_realizados]);

        system("cls");

        printf("Degite o 'genero' - 'Curso' :");

        scanf(" %[^\n]", info_adicionais[(i + 1) + N_cadastro_realizados]);

        system("cls");

        printf("A sua matriluca: ");

        scanf("%i", &num_matricula[(i + 1) + N_cadastro_realizados]);

        system("cls");

        printf("Seu saldo inicial: ");

        scanf("%i", &saldo_alun[(i + 1) + N_cadastro_realizados]);

        system("cls");

        for (i = 0; i < 22; i++)
        {
            printf(".");
        };
    };

    system("cls");

    int back();
    return back();
}

int saldo_aluno()
{

    printf("Se não souber a posição do aluno degite '0'\nverifica em 'Relatorio de saldo'.\n\nDegite a posição do aluno: ");

    scanf("%i", &posicao);

    system("cls");

    for (int i = 0; i < 24; i++)
    {
        printf(".");
    }

    printf("\nNome: %s", nome[posicao]);

    printf("\nSaldo: %i", saldo_alun[posicao]);

    printf("\n");

    for (int i = 0; i < 24; i++)
    {
        printf(".");
    }
    printf("\n");

    int back();
    return back();
}

int recarga()
{
    printf("Se não souber a posição do aluno, degite '0'\n");

    printf("verifica em 'Relatorio de saldo' a sua posição.\n\nEm que posição encontrasse o aluno? : ");

    scanf("%i", &posicao);

    system("cls");

    for (int i = 0; i < 24; i++)
    {
        printf(".");
    }

    printf("\nNome: %s", nome[posicao]);

    printf("\nSaldo: %i", saldo_alun[posicao]);

    printf("\n");

    for (int i = 0; i < 24; i++)
    {
        printf(".");
    }

    printf("\nQuanto valor quer adicionar ou remover? : ");

    scanf("%i", &valor);

    system("cls");

    total = saldo_alun[posicao] + valor;

    for (int i = 0; i < 24; i++)
    {
        printf(".");
    }

    printf("\nNome: %s", nome[posicao]);

    printf("\nNovo saldo: %i", total);

    printf("\n");

    for (int i = 0; i < 24; i++)
    {
        printf(".");
    }

    saldo_alun[posicao] = total;

    int back();
    return back();
}

int relatorio()
{

    for (int i = 0; i < (novos_cadastr + 1) + N_cadastro_realizados; i++)
    {

        printf("\nPosição de cadastro número: %i", i);

        printf("\n\n%s", nome[i]);

        printf("\n%s", info_adicionais[i]);

        printf("\nMatricula: %i", num_matricula[i]);

        printf("\nSaldo: %i", saldo_alun[i]);

        printf(" Kz\n");

        for (int i = 0; i < 25; i++)
        {
            printf(".");
        }
    }

    int back();
    return back();
}

//! Configurações do menu cliente.

//! Configurações do menu Venda.

int menu_venda()
{
    do
    {

        for (int i = 0; i < 27; i++)
        {
            printf(".");
        }

        printf("\n      MENU DE VENDA\n");

        for (int i = 0; i < 27; i++)
        {
            printf(".");
        }

        printf("\n1. Cadastro de produtos\n2. Controle de estoque\n");

        printf("3. Processamento de Venda\n4. Relátorio de Vendas\n5. Menu Principal\n");

        for (int i = 0; i < 27; i++)
        {
            printf(".");
        }

        printf("\n\n:");

        scanf("%i", &opc2);

        system("cls");

        switch (opc2)
        {

        case 1:
            int cadas_produto();
            return cadas_produto();
            break;
        
        case 3:
            int vendas();
            return vendas();
            break;

        case 5:
            int main();
            return main();
            break;
        }

    } while (opc2 != 5);

    return 0;
}

int cadas_produto()
{

    printf("Número de cadastros de produtos já realizados? : ");

    scanf("%i", &N_cadastro_produtos);

    system("cls");

    printf("Número de novos cadastros de produtos? : ");

    scanf("%i", &novos_cadastr_produ);

    system("cls");

    for (int i = 0; i < novos_cadastr_produ; i++)
    {
        printf("Degite o nome do produto: ");

        scanf("%s", nome_produto[(i + 1) + N_cadastro_produtos]);

        system("cls");

        printf("Degite o preço do produto: ");

        scanf("%i", &preco_produ[(i + 1) + N_cadastro_produtos]);

        system("cls");

        printf("Degite a quantidade de estoque: ");

        scanf("%i", &qtd_estoque[(i + 1) + N_cadastro_produtos]);

        system("cls");
    }

    int back2();
    return back2();
}

int vedas()
{
    printf("Produtos cadastrados:");

    for (int i = 0; i < (novos_cadastr_produ + 1) + N_cadastro_produtos; i++)
    {
        printf("\n\nProduto: %i",i);

        printf("\n\nNome: %s",nome_produto[i]);

        printf("\nPreço: %i", preco_produ[i]);
    }

    printf("\n\nProduto de compra: ");

    scanf("%i", &prod);

    system("cls");

    printf("\nNome: %s",nome_produto[i]);

    printf("\nPreço: %i", preco_produ[i]);

    printf("\n\nQuantidade desejada: ");

    scanf("%i", &compra);

    system("cls");

    resto = qtd_estoque[prod] - compra;

    qtd_estoque[prod] = resto;

    printf("Compra feita com sucesso, no valor de %i", preco_produ[prod] * compra); 

    printf (" kz\n");

    if (qtd_estoque[prod] < 3)
    {

        printf("\nAlerta! quantidade de estoque baixo. do produto\n%s", nome_produto[prod]);

        printf(" Restão apenas %i", resto);

        printf (" unidade.\n");
    }

    int back2 ();
    return back2();
}