#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[50];
    int classe;
    int idade;
    int curso; 
    int propinas[11];
    char bi[20];
} Aluno;

Aluno alunos[50];
int total = 0;
int prox_matricula = 1;
int escolha1, escolha2;
float preco_propina[7];

void menu_principal() {

    system ("cls");
    printf("\n1 - Registos");
    printf("\n2 - Listagem");
    printf("\n0 - Encerrar");
    printf("\nEscolha: ");
}

void menu_principal_com_logo() {
    system("cls");
    printf("\n1 - Registos");
    printf("\n2 - Listagem");
    printf("\n0 - Encerrar");
    printf("\nEscolha: ");
}

void menu_registros() {
    system("cls");
    printf("\n");
    printf("1 - Cadastrar aluno      \n");
    printf("2 - atualizar propina    \n");
    printf("3 - precario das propinas\n");
    printf("4 - atualizar dados      \n");
    printf("0 - Voltar               \n");
    printf("Escolha: ");
}

void menu_precario() {
    system("cls");
    printf("\n");
    printf("1 - definir precario    \n");
    printf("2 - atualizar precario  \n");
    printf("3 - consulta do precario\n");
    printf("0 - Voltar              \n");
    printf("Escolha: ");
}

void menu_listagem() {
    system("cls");
    printf("\n");
    printf("1 - Ver meses pagos e em atraso de um aluno \n");
    printf("2 - Listar alunos que nao pagaram um mes    \n");
    printf("3 - Listar alunos em atraso por classe/curso\n");
    printf("4 - Listar meses pagos ou em atraso de todos\n");
    printf("0 - Voltar                                  \n");
    printf("Escolha: ");
}

int escolher_curso() {
    int op;
    do {
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
        printf("\nEscolha (1 a 6): ");
        scanf("%d", &op);
        if(op < 1 || op > 6) {
            printf("\nOpcao invalida! Tente novamente.\n");
            Sleep(1200);
        }
    } while(op < 1 || op > 6);
    return op;
}

int escolher_classe() {
    int op;
    do {
        printf("\n====================================");
        printf("\n        SELECIONE A CLASSE");
        printf("\n====================================");
        printf("\n 1 - 8o");
        printf("\n 2 - 9o");
        printf("\n 3 - 10o");
        printf("\n 4 - 11o");
        printf("\n 5 - 12o");
        printf("\n 6 - 13o");
        printf("\n===================================\n");
        scanf("%d", &op);
    } while(op < 1 || op > 6);
    return op + 7;
}

void definir_precario() {
    int curso;
    float valor;
    curso = escolher_curso();
    printf("\nDigite o valor da propina para este curso: ");
    scanf("%f", &valor);
    preco_propina[curso] = valor;
    printf("\nPrecario definido com sucesso!\n");
    system("pause");
}

void atualizar_precario() {
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

void consultar_precario() {
    system("cls");
    printf("\n===== CONSULTA DO PRECARIO =====\n");
    printf("1 - Tecnico de Informatica: %.2f\n", preco_propina[1]);
    printf("2 - Bioquimica: %.2f\n", preco_propina[2]);
    printf("3 - Electricistas: %.2f\n", preco_propina[3]);
    printf("4 - Mecanica: %.2f\n", preco_propina[4]);
    printf("5 - Desenhador Projetista: %.2f\n", preco_propina[5]);
    printf("6 - Ensino Geral: %.2f\n", preco_propina[6]);
    system("pause");
}

void precario() {
    int escolhap;
    do {
        menu_precario();
        scanf("%d", &escolhap);
        switch(escolhap) {
            case 1: definir_precario(); break;
            case 2: atualizar_precario(); break;
            case 3: consultar_precario(); break;
            case 0: return;
            default:
                printf("\nOpcao invalida!\n");
                Sleep(1200);
        }
    } while(escolhap != 0);
}

int encontrar() {
    int mat;
    char bi[20];
    int escolha;
    printf("\nBuscar aluno por:\n");
    printf("1 - Matricula\n");
    printf("2 - BI\n");
    printf("Escolha: ");
    scanf("%d", &escolha);
    if(escolha == 1) {
        printf("\nDigite a matricula: ");
        scanf("%d", &mat);
        for(int i = 0; i < total; i++) {
            if(alunos[i].matricula == mat) return i;
        }
    }
    else if(escolha == 2) {
        printf("\nDigite o numero do BI: ");
        scanf("%s", bi);
        for(int i = 0; i < total; i++) {
            if(strcmp(alunos[i].bi, bi) == 0) return i;
        }
    }
    return -1;
}

void atualizar_aluno() {
    system("cls");
    printf("\n");
    if(total == 0) {
        printf("\nNenhum aluno cadastrado.\n");
        system("pause");
        return;
    }
    int idx = encontrar();
    if(idx == -1) {
        printf("\nAluno nao encontrado!\n");
        system("pause");
        return;
    }
    Aluno *a = &alunos[idx];
    printf("\nAtualizando dados do aluno:\n");
    printf("Matricula: %d\n", a->matricula);
    printf("Nome atual: %s\n", a->nome);
    getchar();
    printf("\nNovo nome (ENTER para manter): ");
    char novoNome[50];
    fgets(novoNome, sizeof(novoNome), stdin);
    if(novoNome[0] != '\n') {
        novoNome[strcspn(novoNome, "\n")] = 0;
        strcpy(a->nome, novoNome);
    }
    printf("\nIdade atual: %d\n", a->idade);
    printf("Nova idade (0 para manter): ");
    int novaIdade;
    scanf("%d", &novaIdade);
    if(novaIdade > 0) a->idade = novaIdade;
    printf("\nClasse atual: %d\n", a->classe);
    printf("Deseja atualizar classe? (1=Sim / 0=Não): ");
    int op;
    scanf("%d", &op);
    if(op == 1) a->classe = escolher_classe();
    printf("\nCurso atual: %d\n", a->curso);
    printf("Deseja atualizar curso? (1=Sim / 0=Não): ");
    scanf("%d", &op);
    if(op == 1) a->curso = escolher_curso();
    printf("\nBI atual: %s\n", a->bi);
    printf("Novo BI (ENTER para manter): ");
    getchar();
    char novoBI[20];
    fgets(novoBI, sizeof(novoBI), stdin);
    if(novoBI[0] != '\n') {
        novoBI[strcspn(novoBI, "\n")] = 0;
        strcpy(a->bi, novoBI);
    }
    printf("\nDados atualizados com sucesso!\n");
    system("pause");
}

void listar_meses_aluno() {
    int idx = encontrar();
    if(idx == -1) {
         printf("\nAluno nao encontrado!\n"); 
        system("pause"); return;
    }
    char *meses[11] = {"Setembro","Outubro","Novembro","Dezembro","Janeiro",
                       "Fevereiro","Marco","Abril","Maio","Junho","Julho"};
     printf("\nMeses pagos:\n");
    for(int i=0;i<11;i++) if(alunos[idx].propinas[i]==1) printf(" - %s\n", meses[i]);
     printf("\nMeses em atraso:\n");
    for(int i=0;i<11;i++) if(alunos[idx].propinas[i]==0) printf(" - %s\n", meses[i]);
    system("pause");
}

void listar_por_mes() {
    char *meses[11] = {"Setembro","Outubro","Novembro","Dezembro","Janeiro",
                       "Fevereiro","Marco","Abril","Maio","Junho","Julho"};
    int mes;
    printf("\nDigite o numero do mes (1-11): ");
    scanf("%d",&mes);
    if(mes < 1 || mes > 11) {
	    printf("\nMes invalido!\n");
	    system("pause");
	    return;
	}
     printf("\nAlunos em atraso no mes %s:\n", meses[mes-1]);
    for(int i=0;i<total;i++) {
        if(alunos[i].propinas[mes-1]==0) {
            printf(" - %s (Matricula %d)\n", alunos[i].nome, alunos[i].matricula);
        }
    }
    system("pause");
}

void listar_por_classe_curso() {
    int tipo,classe;
    printf("\nListar por:\n1 - Classe\n2 - Curso\nEscolha: ");
    scanf("%d",&tipo);
    if(tipo==1) {
        do {
		    printf("\nDigite a classe (8-13): ");
		    scanf("%d",&classe);
		} while(classe < 8 || classe > 13);
         printf("\nAlunos da classe %d com mensalidades em atraso:\n", classe);
        for(int i=0;i<total;i++) {
            if(alunos[i].classe==classe) {
                for(int j=0;j<11;j++) if(alunos[i].propinas[j]==0) {
                    printf(" - %s (Matricula %d)\n", alunos[i].nome, alunos[i].matricula);
                    break;
                }
            }
        }
    } else if(tipo==2) {
        int curso=escolher_curso();
         printf("\nAlunos do curso %d com mensalidades em atraso:\n", curso);
        for(int i=0;i<total;i++) {
            if(alunos[i].curso==curso) {
                for(int j=0;j<11;j++) if(alunos[i].propinas[j]==0) {
                    printf(" - %s (Matricula %d)\n", alunos[i].nome, alunos[i].matricula);
                    break;
                }
            }
        }
    }
    system("pause");
}

void listar_meses_todos() {
    char *meses[11] = {"Setembro","Outubro","Novembro","Dezembro","Janeiro",
                       "Fevereiro","Marco","Abril","Maio","Junho","Julho"};
    for(int i=0;i<total;i++) {
        printf("\nAluno: %s (Matricula %d)\n", alunos[i].nome, alunos[i].matricula);
         printf("Meses pagos: ");
        for(int j=0;j<11;j++) if(alunos[i].propinas[j]==1) printf("%s ", meses[j]);
         printf("\nMeses em atraso: ");
        for(int j=0;j<11;j++) if(alunos[i].propinas[j]==0) printf("%s ", meses[j]);
         printf("\n-------------------------------------\n");
    }
    system("pause");
}

void cadastrar() {
    Aluno a;
    system("cls");
    printf("\n");
    if(total >= 50) {
        printf("\nLimite atingido!\n");
        return;
    }
    a.matricula = prox_matricula++;
    for(int i = 0; i < 50; i++) printf("*");
    getchar();
    printf("\nNome do aluno: ");
    scanf("%49[^\n]", a.nome);
    a.classe = escolher_classe();
    for(int i = 0; i < 50; i++) printf("*");
    printf("\nIdade: ");
    scanf("%d", &a.idade);
    for(int i = 0; i < 50; i++) printf("*");
    a.curso = escolher_curso();
    for(int i = 0; i < 50; i++) printf("*");
    for(int i = 0; i < 11; i++) a.propinas[i]=0;
    printf("\ninsira o numero do BI: ");
    scanf("%d", &a.bi);
    alunos[total++] = a;
	printf("\n");
    for(int i = 0; i < 50; i++) printf("*");
    printf("\nAluno cadastrado com sucesso!");
    printf("\nMatricula: %d\n", a.matricula);
    system("pause");
    system("cls");
}
void atualizar_propinas() {
    system("cls");
    printf("\n");
    char *meses[11] = {"Setembro","Outubro","Novembro","Dezembro","Janeiro",
                       "Fevereiro","Marco","Abril","Maio","Junho","Julho"};
    int matx = encontrar();
    if(matx == -1) {
        printf("\nAluno nao encontrado!\n");
        system("pause");
        return;
    }
    int op;
    do {
        system("cls");
        printf("\nPropinas de %s\n\n", alunos[matx].nome);
        for(int i = 0; i < 11; i++) {
            printf("%d - %s [%s]\n",
                i + 1,
                meses[i],
                alunos[matx].propinas[i] ? "PAGO" : "NAO PAGO"
            );
        }
        printf("\n12 - Anular pagamento de um mes");
        printf("\n0  - Voltar");
        printf("\nEscolha: ");
        scanf("%d", &op);
        if(op >= 1 && op <= 11) {
            int permitido = 1;
            for(int k = 0; k < op-1; k++) {
                if(alunos[matx].propinas[k] == 0) {
                    permitido = 0;
                    break;
                }
            }
            if(permitido) {
                alunos[matx].propinas[op - 1] = 1;
                printf("\nPagamento do mes %s registrado!\n", meses[op-1]);
            } else {
                printf("\nNao e possivel pagar %s antes de quitar os meses anteriores!\n", meses[op-1]);
            }
            Sleep(800);
        }
        else if(op == 12) {
            int mes;
            printf("\nDigite o numero do mes para anular (1 a 11): ");
            scanf("%d", &mes);
            if(mes >= 1 && mes <= 11) {
                // Ao anular, todos os meses seguintes tambem ficam em atraso
                for(int j = mes-1; j < 11; j++) {
                    alunos[matx].propinas[j] = 0;
                }
                printf("\nPagamento de %s e meses seguintes foram anulados!\n", meses[mes-1]);
                Sleep(800);
            } else {
                printf("\nMes invalido!\n");
                Sleep(800);
            }
        }
        else if(op != 0) {
            printf("\nOpcao invalida!\n");
            Sleep(800);
        }
    } while(op != 0);
    system("cls");
}
void mostrar_listagem() {
    system("cls");
    printf("\n");
    if(total == 0) {
        printf("\nNenhum aluno cadastrado.\n");
        Sleep(1500);
    } else {
        char *meses[11] = {"Setembro","Outubro","Novembro","Dezembro","Janeiro",
                           "Fevereiro","Marco","Abril","Maio","Junho","Julho"};
        for(int i = 0; i < total; i++) {
            char *cursoNome;
            switch(alunos[i].curso) {
                case 1: cursoNome = "Tecnico de Informatica"; break;
                case 2: cursoNome = "Bioquimica"; break;
                case 3: cursoNome = "Electricistas"; break;
                case 4: cursoNome = "Mecanica"; break;
                case 5: cursoNome = "Desenhador Projetista"; break;
                case 6: cursoNome = "Ensino Geral"; break;
                default: cursoNome = "Indefinido";
            }
            printf("\n-------------------------------------");
            printf("\nMatricula : %d", alunos[i].matricula);
            printf("\nNome      : %s", alunos[i].nome);
            printf("\nClasse    : %d", alunos[i].classe);
            printf("\nIdade     : %d", alunos[i].idade);
            printf("\nCurso     : %s", cursoNome);
             printf("\nMeses pagos: ");
            for(int j=0;j<11;j++) if(alunos[i].propinas[j]==1) printf("%s ", meses[j]);
             printf("\nMeses em atraso: ");
            for(int j=0;j<11;j++) if(alunos[i].propinas[j]==0) printf("%s ", meses[j]);
            printf("\n-------------------------------------\n");
        }
    }
    system("pause");
}

void programa_com_logo() {
    menu_principal_com_logo();
    scanf("%d", &escolha1);
    system("cls");
    
    if(escolha1 == 1) {
        menu_registros();
        scanf("%d", &escolha2);
        if(escolha2 == 1) cadastrar();
        else if(escolha2 == 2) atualizar_propinas();
        else if(escolha2 == 3) precario();
        else if(escolha2 == 4) atualizar_aluno();
        else if(escolha2 == 0) programa_com_logo();
        
        if(escolha2 != 0) programa_com_logo();
    }
    else if(escolha1 == 2) {
        menu_listagem();
        scanf("%d", &escolha2);
        if(escolha2 == 1) listar_meses_aluno();
        else if(escolha2 == 2) listar_por_mes();
        else if(escolha2 == 3) listar_por_classe_curso();
        else if(escolha2 == 4) listar_meses_todos();
        else if(escolha2 == 0) programa_com_logo();
        
        if(escolha2 != 0) programa_com_logo();
    }
    else if(escolha1 == 0) {
        system("cls");
        printf("Encerrando o sistema...\n");
        Sleep(800);
        exit(0);
    }
    else {
        printf("\nOpcao invalida!\n");
        Sleep(1200);
        programa_com_logo();
    }
}
void programa() {
    menu_principal();
    scanf("%d", &escolha1);
    system("cls");
    
    if(escolha1 == 1){
        menu_registros();
        scanf("%d", &escolha2);
        if(escolha2 == 1) cadastrar();
        else if(escolha2 == 2) atualizar_propinas();
        else if(escolha2 == 3) precario();
        else if(escolha2 == 4) atualizar_aluno();
        
        programa_com_logo();
    }
    else if(escolha1 == 2) {
        menu_listagem();
        scanf("%d", &escolha2);
        if(escolha2 == 1) listar_meses_aluno();
        else if(escolha2 == 2) listar_por_mes();
        else if(escolha2 == 3) listar_por_classe_curso();
        else if(escolha2 == 4) listar_meses_todos();
        
        programa_com_logo();
    }
    else if(escolha1 == 0) {
        system("cls");
        printf("Encerrando o sistema...\n");
        Sleep(800);
        exit(0);
    }
    else {
        printf("\nOpcao invalida!\n");
        Sleep(1200);
        programa_com_logo();
    }
}


int main() {
    setlocale(LC_ALL, "portuguese");
    system("cls");
    programa();
    return 0;
}
