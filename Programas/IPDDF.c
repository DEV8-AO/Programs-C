#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000
#define TAM_NOME 50
#define TAM_BI 20

typedef struct
{
    int matricula;
    char nome[TAM_NOME];
    int classe;
    int idade;
    int curso;
    int propinas[11];
    char bi[TAM_BI];
} Aluno;

/* ================= VARIAVEIS GLOBAIS ================= */
Aluno alunos[MAX];
int total = 0;
int prox_matricula = 1;
float preco_propina[7] = {0};

/* ================= UTILITARIOS VISUAIS ================= */
void reset() { printf("\033[0m"); }
void ciano() { printf("\033[1;36m"); }

/* ================= FUNCOES DE VALIDACAO ================= */
void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int eh_numero(const char *str)
{
    if (str == NULL || *str == '\0')
        return 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit((unsigned char)str[i]))
            return 0;
    }
    return 1;
}

int eh_nome_valido(const char *str)
{
    if (str == NULL || *str == '\0')
        return 0;
    int tem_letra = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)str[i]))
        {
            tem_letra = 1;
        }
        else if (!isspace((unsigned char)str[i]))
        {
            return 0;
        }
    }
    return tem_letra;
}

int eh_bi_valido(const char *str)
{
    if (str == NULL || *str == '\0' || strlen(str) < 5 || strlen(str) > 19)
        return 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit((unsigned char)str[i]))
            return 0;
    }
    return 1;
}

int ler_inteiro()
{
    char buffer[100];
    while (1)
    {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            printf("Erro de leitura. Tente novamente: ");
            continue;
        }
        buffer[strcspn(buffer, "\n")] = '\0';
        if (eh_numero(buffer))
        {
            return atoi(buffer);
        }
        else
        {
            printf("Entrada invalida. Digite apenas numeros: ");
        }
    }
}

void ler_string(char *destino, int max_len)
{
    char buffer[256];
    while (1)
    {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            printf("Erro de leitura. Tente novamente: ");
            continue;
        }
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strlen(buffer) == 0)
        {
            printf("Campo nao pode estar vazio. Tente novamente: ");
            continue;
        }
        if (strlen(buffer) >= (size_t)max_len)
        {
            printf("Texto muito longo. Maximo %d caracteres: ", max_len - 1);
            continue;
        }
        strcpy(destino, buffer);
        break;
    }
}

int bi_existe(const char *bi)
{
    for (int i = 0; i < total; i++)
    {
        if (strcmp(alunos[i].bi, bi) == 0)
        {
            return 1;
        }
    }
    return 0;
}

/* ================= LOGO KEA ================= */
void logo()
{
    ciano();
    printf("\t\t\t\t '***''  '***''    '*********''     '**********''\n");
    printf("\t\t\t\t '***'' '***''     '*********''    '************''\n");
    printf("\t\t\t\t '***'''***''      '***''         '***''     '***''\n");
    printf("\t\t\t\t '********''       '*********''  '*****************''\n");
    printf("\t\t\t\t '*********''      '*********''  '*****************''\n");
    printf("\t\t\t\t '***'''****''     '***''        '***''        '***''\n");
    printf("\t\t\t\t '***'' '****''    '*********''  '***''        '***''\n");
    printf("\t\t\t\t '***''  '****''   '*********''  '***''        '***''\n");
    reset();
}

/* ================= MENUS ======= ========== */
void menu_principal()
{
    ciano();
    printf("\n\t\t\t\t\t()------------------------------------()");
    printf("\n\t\t\t\t\t''        SISTEMA DE PAGAMENTOS       ''");
    printf("\n\t\t\t\t\t''------------------------------------''");
    printf("\n\t\t\t\t\t'' 1 - Registos                       ''");
    printf("\n\t\t\t\t\t'' 2 - Listagem                       ''");
    printf("\n\t\t\t\t\t'' 3 - Dados Estatisticos             ''");
    printf("\n\t\t\t\t\t'' 0 - Encerrar                       ''");
    ciano();
    printf("\n\t\t\t\t\t()------------------------------------()");
    printf("\n\t\t\t\t\tEscolha: ");
    reset();
}

void menu_registros()
{
    system("cls");
    printf("\n");
    printf("\t\t\t\t\t()----------------------------()\n");
    printf("\t\t\t\t\t''       MENU REGISTOS        ''\n");
    printf("\t\t\t\t\t''----------------------------''\n");
    printf("\t\t\t\t\t'' 1 - Cadastrar aluno        ''\n");
    printf("\t\t\t\t\t'' 2 - atualizar propina      ''\n");
    printf("\t\t\t\t\t'' 3 - precario das propinas  ''\n");
    printf("\t\t\t\t\t'' 4 - atualizar dados        ''\n");
    printf("\t\t\t\t\t'' 0 - Voltar                 ''\n");
    printf("\t\t\t\t\t()----------------------------()\n");
    printf("\t\t\t\t\tEscolha: ");
}

void menu_precario()
{
    system("cls");
    printf("\n");
    printf("\t\t\t\t\t()----------------------------()\n");
    printf("\t\t\t\t\t''       MENU PRECARIO        ''\n");
    printf("\t\t\t\t\t''----------------------------''\n");
    printf("\t\t\t\t\t'' 1 - definir precario       ''\n");
    printf("\t\t\t\t\t'' 2 - atualizar precario     ''\n");
    printf("\t\t\t\t\t'' 3 - consulta do precario   ''\n");
    printf("\t\t\t\t\t'' 0 - Voltar                 ''\n");
    printf("\t\t\t\t\t()----------------------------()\n");
    printf("\t\t\t\t\tEscolha: ");
}

void menu_listagem()
{
    system("cls");
    printf("\n");
    printf("\t\t\t\t\t()-----------------------------------------------()\n");
    printf("\t\t\t\t\t''                  MENU LISTAGEM                ''\n");
    printf("\t\t\t\t\t''-----------------------------------------------''\n");
    printf("\t\t\t\t\t'' 1 - Ver meses pagos e em atraso de um aluno   ''\n");
    printf("\t\t\t\t\t'' 2 - Listar alunos que nao pagaram um mes      ''\n");
    printf("\t\t\t\t\t'' 3 - Listar alunos em atraso por classe/curso  ''\n");
    printf("\t\t\t\t\t'' 4 - Listar meses pagos ou em atraso de todos  ''\n");
    printf("\t\t\t\t\t'' 0 - Voltar                                    ''\n");
    printf("\t\t\t\t\t()-----------------------------------------------()\n");
    printf("\t\t\t\t\tEscolha: ");
}

void menu_estatistica()
{
    system("cls");
    printf("\n");
    printf("\t\t\t\t\t()----------------------------()\n");
    printf("\t\t\t\t\t''     DADOS ESTATISTICOS     ''\n");
    printf("\t\t\t\t\t''----------------------------''\n");
    printf("\t\t\t\t\t'' 1 - Ver estatisticas       ''\n");
    printf("\t\t\t\t\t'' 2 - Alunos em falta        ''\n");
    printf("\t\t\t\t\t'' 3 - Estatisticas por mes   ''\n");
    printf("\t\t\t\t\t'' 0 - Voltar                 ''\n");
    printf("\t\t\t\t\t()----------------------------()\n");
    printf("\t\t\t\t\tEscolha: ");
}

/* ================= CURSO E CLASSE ================= */
int escolher_curso()
{
    int op;
    do
    {
        ciano();
        printf("\n====================================");
        printf("\n        SELECIONE O CURSO");
        printf("\n====================================");
        printf("\n 1 - Tecnico de Informatica");
        printf("\n 2 - Bioquimica");
        printf("\n 3 - Electricistas");
        printf("\n 4 - Mecanica");
        printf("\n 5 - Desenhador Projetista");
        printf("\n 6 - Ensino Geral (Sem curso)");
        printf("\n====================================");
        reset();
        printf("\nEscolha (1 a 6): ");
        op = ler_inteiro();
        if (op < 1 || op > 6)
        {
            printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (op < 1 || op > 6);
    return op;
}

int escolher_classe()
{
    int op;
    do
    {
        printf("\n====================================");
        printf("\n        SELECIONE A CLASSE");
        printf("\n====================================");
        printf("\n 1 - 8º");
        printf("\n 2 - 9º");
        printf("\n 3 - 10º");
        printf("\n 4 - 11º");
        printf("\n 5 - 12º");
        printf("\n 6 - 13º");
        printf("\n===================================\n");
        printf("Escolha (1 a 6): ");
        op = ler_inteiro();
    } while (op < 1 || op > 6);
    return op + 7;
}

/* ================= PRECARIO ================= */
void definir_precario()
{
    int curso;
    float valor;
    curso = escolher_curso();
    printf("\nDigite o valor da propina para este curso: ");
    scanf("%f", &valor);
    preco_propina[curso] = valor;
    printf("\nPrecario definido com sucesso!\n");
    system("pause");
}

void atualizar_precario()
{
    int curso;
    float valor;
    curso = escolher_curso();
    printf("\nValor atual da propina: %.2f\n", preco_propina[curso]);
    printf("Digite o novo valor da propina: ");
    scanf("%f", &valor);
    preco_propina[curso] = valor;
    printf("\nPrecario atualizado com sucesso!\n");
    system("pause");
}

void consultar_precario()
{
    system("cls");
    ciano();
    printf("\n===== CONSULTA DO PRECARIO =====\n");
    printf("1 - Tecnico de Informatica: %.2f\n", preco_propina[1]);
    printf("2 - Bioquimica: %.2f\n", preco_propina[2]);
    printf("3 - Electricistas: %.2f\n", preco_propina[3]);
    printf("4 - Mecanica: %.2f\n", preco_propina[4]);
    printf("5 - Desenhador Projetista: %.2f\n", preco_propina[5]);
    printf("6 - Ensino Geral: %.2f\n", preco_propina[6]);
    reset();
    system("pause");
}

void precario()
{
    int escolhap;
    do
    {
        menu_precario();
        escolhap = ler_inteiro();
        switch (escolhap)
        {
        case 1:
            definir_precario();
            break;
        case 2:
            atualizar_precario();
            break;
        case 3:
            consultar_precario();
            break;
        case 0:
            return;
        default:
            printf("\nOpcao invalida!\n");
        }
    } while (escolhap != 0);
}

/* ================= FUNCIONALIDADES ================= */
int encontrar()
{
    int mat;
    char bi[TAM_BI];
    int escolha;

    printf("\nBuscar aluno por:\n");
    printf("1 - Matricula\n");
    printf("2 - BI\n");
    printf("Escolha: ");
    escolha = ler_inteiro();

    if (escolha == 1)
    {
        printf("\nDigite a matricula: ");
        mat = ler_inteiro();
        for (int i = 0; i < total; i++)
        {
            if (alunos[i].matricula == mat)
                return i;
        }
    }
    else if (escolha == 2)
    {
        printf("\nDigite o numero do BI: ");
        ler_string(bi, TAM_BI);
        for (int i = 0; i < total; i++)
        {
            if (strcmp(alunos[i].bi, bi) == 0)
                return i;
        }
    }

    return -1;
}

/* ================= CADASTRO COM VALIDACAO ================= */
void cadastrar()
{
    if (total >= MAX)
    {
        printf("\nLimite atingido!\n");
        system("pause");
        return;
    }

    Aluno a;
    a.matricula = prox_matricula++;

    // Nome
    char temp_nome[TAM_NOME];
    do
    {
        printf("\nNome do aluno: ");
        ler_string(temp_nome, TAM_NOME);
        if (!eh_nome_valido(temp_nome))
        {
            printf("Nome invalido! Use apenas letras e espacos.\n");
        }
    } while (!eh_nome_valido(temp_nome));
    strcpy(a.nome, temp_nome);

    a.classe = escolher_classe();

    // Idade
    int idade;
    do
    {
        printf("\nIdade (5 a 100): ");
        idade = ler_inteiro();
        if (idade < 5 || idade > 100)
        {
            printf("Idade fora do intervalo permitido!\n");
        }
    } while (idade < 5 || idade > 100);
    a.idade = idade;

    a.curso = escolher_curso();

    // BI
    char temp_bi[TAM_BI];
    do
    {
        printf("\nInsira o BI (apenas numeros): ");
        ler_string(temp_bi, TAM_BI);
        if (!eh_bi_valido(temp_bi))
        {
            printf("BI invalido! Use apenas numeros (5 a 19 digitos).\n");
        }
        else if (bi_existe(temp_bi))
        {
            printf("Este BI ja esta cadastrado!\n");
        }
    } while (!eh_bi_valido(temp_bi) || bi_existe(temp_bi));
    strcpy(a.bi, temp_bi);

    // Inicializa propinas como nao pagas
    for (int i = 0; i < 11; i++)
        a.propinas[i] = 0;

    alunos[total++] = a;

    printf("\n");
    for (int i = 0; i < 50; i++)
        printf("*");
    printf("\nAluno cadastrado com sucesso!");
    printf("\nMatricula: %d\n", a.matricula);
    system("pause");
    system("cls");
}

/* ================= ATUALIZAR PROPINAS ================= */
void atualizar_propinas()
{
    system("cls");
    printf("\n");

    int idx = -1;
    int busca_tipo;
    do
    {
        printf("\nBuscar aluno por:\n1 - Matricula\n2 - BI\n0 - Voltar\nEscolha: ");
        busca_tipo = ler_inteiro();
        if (busca_tipo == 0)
            return;

        if (busca_tipo == 1)
        {
            printf("\nDigite a matricula: ");
            int mat = ler_inteiro();
            for (int i = 0; i < total; i++)
            {
                if (alunos[i].matricula == mat)
                {
                    idx = i;
                    break;
                }
            }
        }
        else if (busca_tipo == 2)
        {
            char bi_busca[TAM_BI];
            printf("\nDigite o BI: ");
            ler_string(bi_busca, TAM_BI);
            for (int i = 0; i < total; i++)
            {
                if (strcmp(alunos[i].bi, bi_busca) == 0)
                {
                    idx = i;
                    break;
                }
            }
        }
        else
        {
            printf("Opcao invalida!\n");
        }
    } while (idx == -1);

    if (idx == -1)
    {
        printf("\nAluno nao encontrado!\n");
        system("pause");
        return;
    }

    char *meses[11] = {"Setembro", "Outubro", "Novembro", "Dezembro", "Janeiro",
                       "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho"};

    int op;
    do
    {
        system("cls");
        ciano();
        printf("\nPropinas de %s\n\n", alunos[idx].nome);
        reset();
        for (int i = 0; i < 11; i++)
        {
            printf("%d - %s [%s]\n", i + 1, meses[i],
                   alunos[idx].propinas[i] ? "PAGO" : "NAO PAGO");
        }
        printf("\n12 - Anular pagamento de um mes");
        printf("\n0  - Voltar");
        printf("\nEscolha: ");
        op = ler_inteiro();

        if (op >= 1 && op <= 11)
        {
            int permitido = 1;
            for (int k = 0; k < op - 1; k++)
            {
                if (alunos[idx].propinas[k] == 0)
                {
                    permitido = 0;
                    break;
                }
            }
            if (permitido)
            {
                alunos[idx].propinas[op - 1] = 1;
                printf("\nPagamento do mes %s registrado!\n", meses[op - 1]);
            }
            else
            {
                printf("\nNao e possivel pagar %s antes de quitar os meses anteriores!\n", meses[op - 1]);
            }
            system("pause");
        }
        else if (op == 12)
        {
            printf("\nDigite o numero do mes para anular (1 a 11): ");
            int mes = ler_inteiro();
            if (mes >= 1 && mes <= 11)
            {
                for (int j = mes - 1; j < 11; j++)
                {
                    alunos[idx].propinas[j] = 0;
                }
                printf("\nPagamento de %s e meses seguintes foram anulados!\n", meses[mes - 1]);
            }
            else
            {
                printf("\nMes invalido!\n");
            }
            system("pause");
        }
        else if (op != 0)
        {
            printf("\nOpcao invalida!\n");
            system("pause");
        }
    } while (op != 0);
    system("cls");
}

/* ================= LISTAGENS ================= */
void listar_meses_aluno()
{
    int idx = encontrar();
    if (idx == -1)
    {
        printf("\nAluno nao encontrado!\n");
        system("pause");
        return;
    }
    char *meses[11] = {"Setembro", "Outubro", "Novembro", "Dezembro", "Janeiro",
                       "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho"};
    printf("\nMeses pagos:\n");
    for (int i = 0; i < 11; i++)
        if (alunos[idx].propinas[i] == 1)
            printf(" - %s\n", meses[i]);
    printf("\nMeses em atraso:\n");
    for (int i = 0; i < 11; i++)
        if (alunos[idx].propinas[i] == 0)
            printf(" - %s\n", meses[i]);
    system("pause");
}

void listar_por_mes()
{
    char *meses[11] = {"Setembro", "Outubro", "Novembro", "Dezembro", "Janeiro",
                       "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho"};
    printf("\nDigite o numero do mes (1-11): ");
    int mes = ler_inteiro();
    if (mes < 1 || mes > 11)
    {
        printf("\nMes invalido!\n");
        system("pause");
        return;
    }
    printf("\nAlunos em atraso no mes %s:\n", meses[mes - 1]);
    for (int i = 0; i < total; i++)
    {
        if (alunos[i].propinas[mes - 1] == 0)
        {
            printf(" - %s (Matricula %d)\n", alunos[i].nome, alunos[i].matricula);
        }
    }
    system("pause");
}

void listar_por_classe_curso()
{
    printf("\nListar por:\n1 - Classe\n2 - Curso\nEscolha: ");
    int tipo = ler_inteiro();
    if (tipo == 1)
    {
        int classe;
        do
        {
            printf("\nDigite a classe (8-13): ");
            classe = ler_inteiro();
        } while (classe < 8 || classe > 13);
        printf("\nAlunos da classe %d com mensalidades em atraso:\n", classe);
        for (int i = 0; i < total; i++)
        {
            if (alunos[i].classe == classe)
            {
                for (int j = 0; j < 11; j++)
                    if (alunos[i].propinas[j] == 0)
                    {
                        printf(" - %s (Matricula %d)\n", alunos[i].nome, alunos[i].matricula);
                        break;
                    }
            }
        }
    }
    else if (tipo == 2)
    {
        int curso = escolher_curso();
        printf("\nAlunos do curso %d com mensalidades em atraso:\n", curso);
        for (int i = 0; i < total; i++)
        {
            if (alunos[i].curso == curso)
            {
                for (int j = 0; j < 11; j++)
                    if (alunos[i].propinas[j] == 0)
                    {
                        printf(" - %s (Matricula %d)\n", alunos[i].nome, alunos[i].matricula);
                        break;
                    }
            }
        }
    }
    system("pause");
}

void listar_meses_todos()
{
    char *meses[11] = {"Setembro", "Outubro", "Novembro", "Dezembro", "Janeiro",
                       "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho"};
    for (int i = 0; i < total; i++)
    {
        printf("\nAluno: %s (Matricula %d)\n", alunos[i].nome, alunos[i].matricula);
        printf("Meses pagos: ");
        for (int j = 0; j < 11; j++)
            if (alunos[i].propinas[j] == 1)
                printf("%s ", meses[j]);
        printf("\nMeses em atraso: ");
        for (int j = 0; j < 11; j++)
            if (alunos[i].propinas[j] == 0)
                printf("%s ", meses[j]);
        printf("\n-------------------------------------\n");
    }
    system("pause");
}

/* ================= ATUALIZAR ALUNO ================= */
void atualizar_aluno()
{
    system("cls");
    printf("\n");

    if (total == 0)
    {
        printf("\nNenhum aluno cadastrado.\n");
        system("pause");
        return;
    }

    int idx = encontrar();
    if (idx == -1)
    {
        printf("\nAluno nao encontrado!\n");
        system("pause");
        return;
    }

    Aluno *a = &alunos[idx];
    printf("\nAtualizando dados do aluno:\n");
    printf("Matricula: %d\n", a->matricula);
    printf("Nome atual: %s\n", a->nome);

    char novoNome[TAM_NOME];
    printf("\nNovo nome (ENTER para manter): ");
    fgets(novoNome, sizeof(novoNome), stdin);
    novoNome[strcspn(novoNome, "\n")] = 0;
    if (strlen(novoNome) > 0)
    {
        if (eh_nome_valido(novoNome))
        {
            strcpy(a->nome, novoNome);
        }
        else
        {
            printf("Nome invalido! Mantendo nome atual.\n");
        }
    }

    printf("\nIdade atual: %d\n", a->idade);
    printf("Nova idade (0 para manter): ");
    int novaIdade = ler_inteiro();
    if (novaIdade > 0 && novaIdade >= 5 && novaIdade <= 100)
    {
        a->idade = novaIdade;
    }

    printf("\nClasse atual: %d\n", a->classe);
    printf("Deseja atualizar classe? (1=Sim / 0=Nao): ");
    int op = ler_inteiro();
    if (op == 1)
        a->classe = escolher_classe();

    printf("\nCurso atual: %d\n", a->curso);
    printf("Deseja atualizar curso? (1=Sim / 0=Nao): ");
    op = ler_inteiro();
    if (op == 1)
        a->curso = escolher_curso();

    printf("\nBI atual: %s\n", a->bi);
    printf("Novo BI (ENTER para manter): ");
    char novoBI[TAM_BI];
    fgets(novoBI, sizeof(novoBI), stdin);
    novoBI[strcspn(novoBI, "\n")] = 0;
    if (strlen(novoBI) > 0)
    {
        if (eh_bi_valido(novoBI) && !bi_existe(novoBI))
        {
            strcpy(a->bi, novoBI);
        }
        else
        {
            printf("BI invalido ou ja existente! Mantendo BI atual.\n");
        }
    }

    printf("\nDados atualizados com sucesso!\n");
    system("pause");
}

/* ================= ESTATISTICAS ================= */
void estatisticas()
{
    system("cls");
    printf("\n");
    if (total == 0)
    {
        printf("\nNenhum aluno cadastrado.\n");
        system("pause");
        return;
    }

    int soma_idades = 0;
    int cursos[7] = {0};
    int em_dia = 0;

    for (int i = 0; i < total; i++)
    {
        soma_idades += alunos[i].idade;
        cursos[alunos[i].curso]++;

        int todasPagas = 1;
        for (int j = 0; j < 11; j++)
        {
            if (alunos[i].propinas[j] == 0)
            {
                todasPagas = 0;
                break;
            }
        }
        if (todasPagas)
            em_dia++;
    }

    float media_idade = (float)soma_idades / total;

    printf("\n===== ESTATISTICAS =====\n");
    printf("Total de alunos: %d\n", total);
    printf("Media de idade: %.2f\n", media_idade);
    printf("Alunos com todas as propinas em dia: %d\n", em_dia);
    printf("\nDistribuicao por curso:\n");
    printf("1 - Tecnico de Informatica: %d\n", cursos[1]);
    printf("2 - Bioquimica: %d\n", cursos[2]);
    printf("3 - Electricistas: %d\n", cursos[3]);
    printf("4 - Mecanica: %d\n", cursos[4]);
    printf("5 - Desenhador Projetista: %d\n", cursos[5]);
    printf("6 - Ensino Geral: %d\n", cursos[6]);

    system("pause");
}

void listar_em_falta()
{
    system("cls");
    int encontrados = 0;

    for (int i = 0; i < total; i++)
    {
        int falta = 0;
        for (int j = 0; j < 11; j++)
        {
            if (alunos[i].propinas[j] == 0)
            {
                falta = 1;
                break;
            }
        }

        if (falta)
        {
            encontrados++;
            printf("\n-------------------------------------");
            printf("\nMatricula : %d", alunos[i].matricula);
            printf("\nNome      : %s", alunos[i].nome);
            printf("\nClasse    : %d", alunos[i].classe);
            printf("\nIdade     : %d", alunos[i].idade);
            char *cursoNome;
            switch (alunos[i].curso)
            {
            case 1:
                cursoNome = "Tecnico de Informatica";
                break;
            case 2:
                cursoNome = "Bioquimica";
                break;
            case 3:
                cursoNome = "Electricistas";
                break;
            case 4:
                cursoNome = "Mecanica";
                break;
            case 5:
                cursoNome = "Desenhador Projetista";
                break;
            case 6:
                cursoNome = "Ensino Geral";
                break;
            default:
                cursoNome = "Indefinido";
            }
            printf("\nCurso     : %s", cursoNome);
            printf("\nSituacao  : EM FALTA");
            printf("\n-------------------------------------\n");
        }
    }

    if (encontrados == 0)
    {
        printf("\nTodos os alunos estao com propinas em dia!\n");
    }

    system("pause");
}

/* ================= CONTROLE ================= */
void programa_com_logo()
{
    while (1)
    {
        menu_principal();
        int escolha1 = ler_inteiro();
        system("cls");

        if (escolha1 == 1)
        {
            menu_registros();
            int escolha2 = ler_inteiro();
            if (escolha2 == 1)
                cadastrar();
            else if (escolha2 == 2)
                atualizar_propinas();
            else if (escolha2 == 3)
                precario();
            else if (escolha2 == 4)
                atualizar_aluno();
        }
        else if (escolha1 == 2)
        {
            menu_listagem();
            int escolha2 = ler_inteiro();
            if (escolha2 == 1)
                listar_meses_aluno();
            else if (escolha2 == 2)
                listar_por_mes();
            else if (escolha2 == 3)
                listar_por_classe_curso();
            else if (escolha2 == 4)
                listar_meses_todos();
        }
        else if (escolha1 == 3)
        {
            menu_estatistica();
            int escolha2 = ler_inteiro();
            if (escolha2 == 1)
                estatisticas();
            else if (escolha2 == 2)
                listar_em_falta();
        }
        else if (escolha1 == 0)
        {
            system("cls");
            printf("Encerrando o sistema...");
            exit(0);
        }
        else
        {
            printf("\nOpcao invalida!\n");
            system("pause");
        }
    }
}

void programa()
{
    menu_principal();
    int escolha1 = ler_inteiro();
    system("cls");
    if (escolha1 == 1)
    {
        menu_registros();
        int escolha2 = ler_inteiro();
        if (escolha2 == 1)
            cadastrar();
        else if (escolha2 == 2)
            atualizar_propinas();
        else if (escolha2 == 3)
            precario();
        programa_com_logo();
    }
    else if (escolha1 == 2)
    {
        menu_listagem();
        int escolha2 = ler_inteiro();
        if (escolha2 == 1)
            listar_meses_aluno();
        else if (escolha2 == 2)
            listar_por_mes();
        else if (escolha2 == 3)
            listar_por_classe_curso();
        else if (escolha2 == 4)
            listar_meses_todos();
        programa_com_logo();
    }
    else if (escolha1 == 3)
    {
        menu_estatistica();
        int escolha2 = ler_inteiro();
        if (escolha2 == 1)
            estatisticas();
        else if (escolha2 == 2)
            listar_em_falta();
        programa_com_logo();
    }
    else if (escolha1 == 0)
    {
        system("cls");
        printf("Encerrando o sistema...");
        exit(0);
    }
    else
    {
        printf("\nOpcao invalida!\n");
        system("pause");
        programa_com_logo();
    }
}

/* ================= MAIN ================= */
int main()
{
    system("cls");
    printf("\nCarregando sistema...\n");
    system("pause");
    system("cls");
    logo();
    programa();
    return 0;
}