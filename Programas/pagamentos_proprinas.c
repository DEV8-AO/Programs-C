#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>

#define MAX 1000
/* considercoes de comandos*/
/* ================= REGISTRO ================= */
typedef struct {
    int matricula;
    char nome[50];
    int classe;
    int idade;
    int curso;      // 1 a 6 cursos
    int propinas[11];  // 1 = em dia | 0 = em falta
    char bi[20];
} Aluno;

/* ================= VARIÁVEIS ================= */
Aluno alunos[MAX];
int total = 0;
int prox_matricula = 1;
int escolha1, escolha2;
float preco_propina[7]={0};

/* ================= UTILITÁRIOS VISUAIS ================= */
void reset()   { printf("\033[0m"); } //cod da cor branca 
void azul()    { printf("\033[1;34m"); }
void verde()   { printf("\033[1;32m"); }
void amarelo() { printf("\033[1;33m"); }
void vermelho(){ printf("\033[1;31m"); }
void roxo()    { printf("\033[1;35m"); }
void ciano()   { printf("\033[1;36m"); }
void branco()  { printf("\033[1;37m"); }

//responsavel por fazer a animação de inserção de letra
void digitar(const char *t) { // simular um printf e ao mesmo tempo analisar caracter por caracter a mensagem a ser iprimida  
    while(*t) { // enquanto tiver algum caracter a apresentar 
        printf("%c", *t++); // apresentar um caracter 
        Sleep(15); //dar um atraso a imprimir os caracteres na tela
    }
}

/* ================= LOGO KEA ================= */
void logo() {
    ciano();
    digitar("\t\t\t\t '***''  '***''    '*********''     '**********''\n");
    digitar("\t\t\t\t '***'' '***''     '*********''    '************''\n");
    digitar("\t\t\t\t '***'''***''      '***''         '***''     '***''\n");
    digitar("\t\t\t\t '********''       '*********''  '*****************''\n");
    digitar("\t\t\t\t '*********''      '*********''  '*****************''\n");
    digitar("\t\t\t\t '***'''****''     '***''        '***''        '***''\n");
    digitar("\t\t\t\t '***'' '****''    '*********''  '***''        '***''\n");
    digitar("\t\t\t\t '***''  '****''   '*********''  '***''        '***''\n");
    reset();
}

void logo_sem_animacao(){
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

/* ================= MENUS ================= */
void menu_principal() {
    ciano();
    printf("\n\t\t\t\t\t()------------------------------------()"); Sleep(150);
    printf("\n\t\t\t\t\t''        SISTEMA DE PAGAMENTOS       ''"); Sleep(150);
    printf("\n\t\t\t\t\t''------------------------------------''"); Sleep(150);
    verde();
    printf("\n\t\t\t\t\t'' 1 - Registos                       ''"); Sleep(150);
    printf("\n\t\t\t\t\t'' 2 - Listagem                       ''"); Sleep(150);
    printf("\n\t\t\t\t\t'' 3 - Dados Estatisticos             ''"); Sleep(150);
    vermelho();
    printf("\n\t\t\t\t\t'' 0 - Encerrar                       ''"); Sleep(150);
    ciano();
    printf("\n\t\t\t\t\t()------------------------------------()"); Sleep(150);
    branco();
    printf("\n\t\t\t\t\tEscolha: ");
    reset();
}

void menu_principal_com_logo() {
    system("cls");
    logo_sem_animacao();
    ciano();
    printf("\n\t\t\t\t\t()------------------------------------()"); Sleep(150);
    printf("\n\t\t\t\t\t''        SISTEMA DE PAGAMENTOS       ''"); Sleep(150);
    printf("\n\t\t\t\t\t''------------------------------------''"); Sleep(150);
    verde();
    printf("\n\t\t\t\t\t'' 1 - Registos                       ''"); Sleep(150);
    printf("\n\t\t\t\t\t'' 2 - Listagem                       ''"); Sleep(150);
    printf("\n\t\t\t\t\t'' 3 - Dados Estatísticos             ''"); Sleep(150);
    vermelho();
    printf("\n\t\t\t\t\t'' 0 - Encerrar                       ''"); Sleep(150);
    ciano();
    printf("\n\t\t\t\t\t()------------------------------------()"); Sleep(150);
    branco();
    printf("\n\t\t\t\t\tEscolha: ");
    reset();
}
    
void menu_registros() {
    system("cls");
    logo_sem_animacao();
    printf("\n");
    verde();
    printf("\t\t\t\t\t()----------------------------()\n");
    printf("\t\t\t\t\t''       MENU REGISTOS        ''\n");
    printf("\t\t\t\t\t''----------------------------''\n");
    printf("\t\t\t\t\t'' 1 - Cadastrar aluno        ''\n");
    printf("\t\t\t\t\t'' 2 - atualizar propina      ''\n");
    printf("\t\t\t\t\t'' 3 - preçário das propinas  ''\n");
    printf("\t\t\t\t\t'' 4 - atualizar dados        ''\n");
    printf("\t\t\t\t\t'' 0 - Voltar                 ''\n");
    printf("\t\t\t\t\t()----------------------------()\n");
    printf("\t\t\t\t\tEscolha: ");
    reset();
}

void menu_precario() {
    system("cls");
    logo_sem_animacao();
    printf("\n");
    verde();
    printf("\t\t\t\t\t()----------------------------()\n");
    printf("\t\t\t\t\t''       MENU PERÇÁRIO        ''\n");
    printf("\t\t\t\t\t''----------------------------''\n");
    printf("\t\t\t\t\t'' 1 - definir preçário       ''\n");
    printf("\t\t\t\t\t'' 2 - atualizar preçário     ''\n");
    printf("\t\t\t\t\t'' 3 - consulta do preçário   ''\n");
    printf("\t\t\t\t\t'' 0 - Voltar                 ''\n");
    printf("\t\t\t\t\t()----------------------------()\n");
    printf("\t\t\t\t\tEscolha: ");
    reset();
}

void menu_listagem() {
    system("cls");
    logo_sem_animacao();
    printf("\n");
    amarelo();
    printf("\t\t\t\t\t()-----------------------------------------------()\n");
    printf("\t\t\t\t\t''                  MENU LISTAGEM                ''\n");
    printf("\t\t\t\t\t''-----------------------------------------------''\n");
    printf("\t\t\t\t\t'' 1 - Ver meses pagos e em atraso de um aluno   ''\n");
    printf("\t\t\t\t\t'' 2 - Listar alunos que não pagaram um mês      ''\n");
    printf("\t\t\t\t\t'' 3 - Listar alunos em atraso por classe/curso  ''\n");
    printf("\t\t\t\t\t'' 4 - Listar meses pagos ou em atraso de todos  ''\n");
    printf("\t\t\t\t\t'' 0 - Voltar                                    ''\n");
    printf("\t\t\t\t\t()-----------------------------------------------()\n");
    printf("\t\t\t\t\tEscolha: ");
    reset();
}

void menu_estatistica() {
    system("cls");
    logo_sem_animacao();
    printf("\n");
    roxo();
    printf("\t\t\t\t\t()----------------------------()\n");
    printf("\t\t\t\t\t''     DADOS ESTATÍSTICOS     ''\n");
    printf("\t\t\t\t\t''----------------------------''\n");
    printf("\t\t\t\t\t'' 1 - Ver estatísticas       ''\n");
    printf("\t\t\t\t\t'' 2 - Alunos em falta        ''\n");
    printf("\t\t\t\t\t'' 3 - Estatísticas por mês   ''\n");
    printf("\t\t\t\t\t'' 0 - Voltar                 ''\n");
    printf("\t\t\t\t\t()----------------------------()\n");
    printf("\t\t\t\t\tEscolha: ");
    reset();
}

/* ================= CURSO ================= */
int escolher_curso() {
    int op;
    do {
        ciano();
        printf("\n====================================");
        printf("\n        SELECIONE O CURSO");
        printf("\n====================================");
        printf("\n 1 - Técnico de Informática");
        printf("\n 2 - Bioquímica");
        printf("\n 3 - Electricistas");
        printf("\n 4 - Mecânica");
        printf("\n 5 - Desenhador Projetista");
        printf("\n 6 - Ensino Geral (Sem curso)");
        printf("\n====================================");
        branco();
        printf("\nEscolha (1 a 6): ");

        scanf("%d", &op);

        if(op < 1 || op > 6) {
            vermelho();
            printf("\nOpção inválida! Tente novamente.\n");
            reset();
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
        printf("\n 1 - 8º");
        printf("\n 2 - 9º");
        printf("\n 3 - 10º");
        printf("\n 4 - 11º");
        printf("\n 5 - 12º");
        printf("\n 6 - 13º");
        printf("\n===================================\n");
        scanf("%d", &op);
    } while(op < 1 || op > 6);

    return op + 7;
}

/* ================= PREÇÁRIO ================= */
void definir_precario() {
    int curso;
    float valor;
    curso = escolher_curso();
    printf("\nDigite o valor da propina para este curso: ");
    scanf("%f", &valor);
    preco_propina[curso] = valor;
    verde();
    printf("\nPreçário definido com sucesso!\n");
    reset();
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
    verde();
    printf("\nPreçário atualizado com sucesso!\n");
    reset();
    system("pause");
}

void consultar_precario() {
    system("cls");
    ciano();
    printf("\n===== CONSULTA DO PREÇÁRIO =====\n");
    printf("1 - Técnico de Informática: %.2f\n", preco_propina[1]);
    printf("2 - Bioquímica: %.2f\n", preco_propina[2]);
    printf("3 - Electricistas: %.2f\n", preco_propina[3]);
    printf("4 - Mecânica: %.2f\n", preco_propina[4]);
    printf("5 - Desenhador Projetista: %.2f\n", preco_propina[5]);
    printf("6 - Ensino Geral: %.2f\n", preco_propina[6]);
    reset();
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
                vermelho();
                printf("\nOpção inválida!\n");
                reset();
                Sleep(1200);
        }
    } while(escolhap != 0);
}


/* ================= FUNCIONALIDADES ================= */

int encontrar() {
    int mat;
    char bi[20];
    int escolha;

    printf("\nBuscar aluno por:\n");
    printf("1 - Matrícula\n");
    printf("2 - BI\n");
    printf("Escolha: ");
    scanf("%d", &escolha);

    if(escolha == 1) {
        printf("\nDigite a matrícula: ");
        scanf("%d", &mat);
        for(int i = 0; i < total; i++) {
            if(alunos[i].matricula == mat) return i;
        }
    }
    else if(escolha == 2) {
        printf("\nDigite o número do BI: ");
        scanf("%19s", bi);
        for(int i = 0; i < total; i++) {
            if(strcmp(alunos[i].bi, bi) == 0) return i;
        }
    }

    return -1;
}

/* ===================== LISTAGENS ====================*/

void atualizar_aluno() {
    system("cls");
    logo_sem_animacao();
    printf("\n");

    if(total == 0) {
        vermelho();
        printf("\nNenhum aluno cadastrado.\n");
        reset();
        system("pause");
        return;
    }

    int idx = encontrar(); // busca por matrícula ou BI
    if(idx == -1) {
        vermelho();
        printf("\nAluno não encontrado!\n");
        reset();
        system("pause");
        return;
    }

    Aluno *a = &alunos[idx];

    verde();
    printf("\nAtualizando dados do aluno:\n");
    printf("Matrícula: %d\n", a->matricula);
    printf("Nome atual: %s\n", a->nome);
    reset();

    while(getchar() != '\n'); // limpar buffer
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
	
	while(getchar() != '\n'); // limpar buffer
	char novoBI[20];
	
	fgets(novoBI, sizeof(novoBI), stdin);
    if(novoBI[0] != '\n') {
        novoBI[strcspn(novoBI, "\n")] = 0;
        strcpy(a->bi, novoBI);
    }

    verde();
    printf("\nDados atualizados com sucesso!\n");
    reset();
    system("pause");
}

void listar_meses_aluno() {
    int idx = encontrar();
    if(idx == -1) {
        vermelho(); printf("\nAluno não encontrado!\n"); reset();
        system("pause"); return;
    }
    char *meses[11] = {"Setembro","Outubro","Novembro","Dezembro","Janeiro",
                       "Fevereiro","Março","Abril","Maio","Junho","Julho"};

    verde(); printf("\nMeses pagos:\n");
    for(int i=0;i<11;i++) if(alunos[idx].propinas[i]==1) printf(" - %s\n", meses[i]);
    vermelho(); printf("\nMeses em atraso:\n");
    for(int i=0;i<11;i++) if(alunos[idx].propinas[i]==0) printf(" - %s\n", meses[i]);
    reset();
    system("pause");
}

void listar_por_mes() {
    char *meses[11] = {"Setembro","Outubro","Novembro","Dezembro","Janeiro",
                       "Fevereiro","Março","Abril","Maio","Junho","Julho"};
    int mes;
    printf("\nDigite o número do mês (1-11): ");
    scanf("%d",&mes);
    
    if(mes < 1 || mes > 11) {
	    vermelho();
	    printf("\nMês inválido!\n");
	    reset();
	    system("pause");
	    return;
	}

    vermelho(); printf("\nAlunos em atraso no mês %s:\n", meses[mes-1]);
    for(int i=0;i<total;i++) {
        if(alunos[i].propinas[mes-1]==0) {
            printf(" - %s (Matrícula %d)\n", alunos[i].nome, alunos[i].matricula);
        }
    }
    reset();
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

        
        vermelho(); printf("\nAlunos da classe %d com mensalidades em atraso:\n", classe);
        for(int i=0;i<total;i++) {
            if(alunos[i].classe==classe) {
                for(int j=0;j<11;j++) if(alunos[i].propinas[j]==0) {
                    printf(" - %s (Matrícula %d)\n", alunos[i].nome, alunos[i].matricula);
                    break;
                }
            }
        }
    } else if(tipo==2) {
        int curso=escolher_curso();
        vermelho(); printf("\nAlunos do curso %d com mensalidades em atraso:\n", curso);
        for(int i=0;i<total;i++) {
            if(alunos[i].curso==curso) {
                for(int j=0;j<11;j++) if(alunos[i].propinas[j]==0) {
                    printf(" - %s (Matrícula %d)\n", alunos[i].nome, alunos[i].matricula);
                    break;
                }
            }
        }
    }
    reset();
    system("pause");
}

void listar_meses_todos() {
    char *meses[11] = {"Setembro","Outubro","Novembro","Dezembro","Janeiro",
                       "Fevereiro","Março","Abril","Maio","Junho","Julho"};
    for(int i=0;i<total;i++) {
        printf("\nAluno: %s (Matrícula %d)\n", alunos[i].nome, alunos[i].matricula);
        verde(); printf("Meses pagos: ");
        for(int j=0;j<11;j++) if(alunos[i].propinas[j]==1) printf("%s ", meses[j]);
        vermelho(); printf("\nMeses em atraso: ");
        for(int j=0;j<11;j++) if(alunos[i].propinas[j]==0) printf("%s ", meses[j]);
        reset(); printf("\n-------------------------------------\n");
    }
    system("pause");
}

int nome_valido(char nome[]) {
    
    for(int i = 0; nome[i] != '\0'; i++) {
        if(nome[i] != ' ' && nome[i] != '\n') {
            return 1; 
        }
    }
    return 0; 
}

int idade_valida(int idade) {
    return (idade >= 5 && idade <= 100);
}

int bi_existe(char bi[]) {
    for(int i = 0; i < total; i++) {
        if(strcmp(alunos[i].bi, bi) == 0) {
            return 1; 
        }
    }
    return 0;
}

void cadastrar() {
    Aluno a;
    system("cls");
	logo_sem_animacao();
	printf("\n");
    if(total >= MAX) {
        vermelho();
        printf("\nLimite atingido!\n");
        reset();
        return;
    }

    a.matricula = prox_matricula++;

    ciano();
    for(int i = 0; i < 50; i++) printf("*");
    
char nomeTemp[50];

	do {
	    printf("\nNome do aluno: ");
	    scanf(" %49[^\n]", nomeTemp);
	
	    if(!nome_valido(nomeTemp)) {
	        vermelho();
	        printf("\nNome não pode estar vazio!\n");
	        reset();
	    }
	
	} while(!nome_valido(nomeTemp));
	
	strcpy(a.nome, nomeTemp);

    a.classe = escolher_classe();

    for(int i = 0; i < 50; i++) printf("*");
    do {
	    printf("\nIdade: ");
	    scanf("%d", &a.idade);
	
	    if(!idade_valida(a.idade)) {
	        vermelho();
	        printf("\nIdade inválida! (5 - 100)\n");
	        reset();
	    }

	} while(!idade_valida(a.idade));

    for(int i = 0; i < 50; i++) printf("*");
    a.curso = escolher_curso();

    for(int i = 0; i < 50; i++) printf("*");
    
    for(int i = 0; i < 11; i++) a.propinas[i]=0;
    
    char biTemp[20];

	do {
	    printf("\nInsira o BI: ");
	    scanf("%19s", biTemp);
	
	    if(bi_existe(biTemp)) {
	        vermelho();
	        printf("\nEste BI já está cadastrado!\n");
	        reset();
	    }
	
	} while(bi_existe(biTemp));

	strcpy(a.bi, biTemp);

    alunos[total++] = a;
	printf("\n");
    verde();
    for(int i = 0; i < 50; i++) printf("*");
    printf("\nAluno cadastrado com sucesso!");
    printf("\nMatricula: %d\n", a.matricula);
    reset();
    system("pause");
    system("cls");
    
}

/* ================= ATUALIZAR PROPINAS ================= */

void atualizar_propinas() {
    system("cls");
    logo_sem_animacao();
    printf("\n");
    char *meses[11] = {"Setembro","Outubro","Novembro","Dezembro","Janeiro",
                       "Fevereiro","Março","Abril","Maio","Junho","Julho"};

    int matx = encontrar();

    if(matx == -1) {
        vermelho();
        printf("\nAluno não encontrado!\n");
        reset();
        system("pause");
        return;
    }

    int op;
    do {
        system("cls");
        logo_sem_animacao();

        ciano();
        printf("\nPropinas de %s\n\n", alunos[matx].nome);

        for(int i = 0; i < 11; i++) {
            printf("%d - %s [%s]\n",
                i + 1,
                meses[i],
                alunos[matx].propinas[i] ? "PAGO" : "NÃO PAGO"
            );
        }

        printf("\n12 - Anular pagamento de um mês");
        printf("\n0  - Voltar");
        printf("\nEscolha: ");
        reset();

        scanf("%d", &op);

        if(op >= 1 && op <= 11) {
            // Verifica se meses anteriores estão pagos
            int permitido = 1;
            for(int k = 0; k < op-1; k++) {
                if(alunos[matx].propinas[k] == 0) {
                    permitido = 0;
                    break;
                }
            }

            if(permitido) {
                alunos[matx].propinas[op - 1] = 1;
                verde();
                printf("\nPagamento do mês %s registrado!\n", meses[op-1]);
                reset();
            } else {
                vermelho();
                printf("\nNão é possível pagar %s antes de quitar os meses anteriores!\n", meses[op-1]);
                reset();
            }
            Sleep(800);
        }
        else if(op == 12) {
            int mes;
            printf("\nDigite o número do mês para anular (1 a 11): ");
            scanf("%d", &mes);

            if(mes >= 1 && mes <= 11) {
                // Ao anular, todos os meses seguintes também ficam em atraso
                for(int j = mes-1; j < 11; j++) {
                    alunos[matx].propinas[j] = 0;
                }
                verde();
                printf("\nPagamento de %s e meses seguintes foram anulados!\n", meses[mes-1]);
                reset();
                Sleep(800);
            } else {
                vermelho();
                printf("\nMês inválido!\n");
                reset();
                Sleep(800);
            }
        }
        else if(op != 0) {
            vermelho();
            printf("\nOpção inválida!\n");
            reset();
            Sleep(800);
        }

    } while(op != 0);
    system("cls");
}


/* ================= BARRA DE CARREGAMENTO ================= */
void barra_carregamento_basica() {
    int largura = 40;
    int i;

    printf("\n\n");

    for(i = 0; i <= largura; i++) {
        Sleep(100);
        int espacos = (80 - largura) / 2;
        for(int j = 0; j < espacos; j++) printf(" ");
        
        printf("[");
        for(int j = 0; j < i; j++) printf("#");
        for(int j = i; j < largura; j++) printf(" ");
        printf("] %d%%\r", (i * 100) / largura);
        fflush(stdout);
    }
    printf("\n\n");
    system("pause");
}

/* ================= LISTAGEM ================= */
void mostrar_listagem() {
    system("cls");
    logo_sem_animacao();
    printf("\n");
    if(total == 0) {
        vermelho();
        printf("\nNenhum aluno cadastrado.\n");
        reset();
        Sleep(1500);
    } else {
        char *meses[11] = {"Setembro","Outubro","Novembro","Dezembro","Janeiro",
                           "Fevereiro","Março","Abril","Maio","Junho","Julho"};
        for(int i = 0; i < total; i++) {
            char *cursoNome;
            switch(alunos[i].curso) {
                case 1: cursoNome = "Técnico de Informática"; break;
                case 2: cursoNome = "Bioquímica"; break;
                case 3: cursoNome = "Electricistas"; break;
                case 4: cursoNome = "Mecânica"; break;
                case 5: cursoNome = "Desenhador Projetista"; break;
                case 6: cursoNome = "Ensino Geral"; break;
                default: cursoNome = "Indefinido";
            }

            ciano();
            printf("\n-------------------------------------");
            printf("\nMatrícula : %d", alunos[i].matricula);
            printf("\nNome      : %s", alunos[i].nome);
            printf("\nClasse    : %d", alunos[i].classe);
            printf("\nIdade     : %d", alunos[i].idade);
            printf("\nCurso     : %s", cursoNome);

            verde(); printf("\nMeses pagos: ");
            for(int j=0;j<11;j++) if(alunos[i].propinas[j]==1) printf("%s ", meses[j]);

            vermelho(); printf("\nMeses em atraso: ");
            for(int j=0;j<11;j++) if(alunos[i].propinas[j]==0) printf("%s ", meses[j]);

            reset();
            printf("\n-------------------------------------\n");
        }
    }
    system("pause");
}


/* ================= ESTATÍSTICAS ================= */

void dados_estatisticos_avancados() {
    system("cls");
    logo_sem_animacao();
    printf("\n");

    if(total == 0) {
        vermelho();
        printf("\nNenhum aluno cadastrado.\n");
        reset();
        system("pause");
        return;
    }

    char *meses[11] = {"Setembro","Outubro","Novembro","Dezembro","Janeiro",
                       "Fevereiro","Março","Abril","Maio","Junho","Julho"};

    int mes;
    printf("\nDigite o número do mês (1 a 11): ");
    scanf("%d", &mes);
    if(mes < 1 || mes > 11) {
        vermelho();
        printf("\nMês inválido!\n");
        reset();
        system("pause");
        return;
    }

    mes -= 1; // ajustar índice

    int totalPagantes = 0;
    int totalNaoPagantes = 0;
    float saldoTotal = 0;
    int porClasse[14] = {0}; // classes de 8 a 13

    for(int i = 0; i < total; i++) {
        if(alunos[i].propinas[mes] == 1) {
            totalPagantes++;
            saldoTotal += preco_propina[alunos[i].curso];
            porClasse[alunos[i].classe]++;
        } else {
            totalNaoPagantes++;
        }
    }

    float percentagem = (totalPagantes * 100.0) / total;

    roxo();
    printf("\n===== ESTATÍSTICAS DO MÊS DE %s =====\n", meses[mes]);
    printf("Total de estudantes: %d\n", total);
    printf("Pagaram: %d\n", totalPagantes);
    printf("Não pagaram: %d\n", totalNaoPagantes);
    printf("Percentagem de pagamento: %.2f%%\n", percentagem);
    printf("Saldo arrecadado: %.2f\n", saldoTotal);
    printf("\nValor arrecadado por classe:\n");
    for(int i = 8; i <= 13; i++) {
        printf("Classe %d: %d alunos pagaram\n", i, porClasse[i]);
    }
    reset();

    system("pause");
}

void estatisticas() {
    system("cls");
    logo_sem_animacao();
	printf("\n");
    if(total == 0) {
        vermelho();
        printf("\nNenhum aluno cadastrado.\n");
        reset();
        system("pause");
        return;
    }

    int soma_idades = 0;
    int cursos[7] = {0};
    int em_dia = 0;

    for(int i = 0; i < total; i++) {
        soma_idades += alunos[i].idade;
        cursos[alunos[i].curso]++;
        
        int todasPagas = 1;
        for(int j = 0; j < 11; j++) {
            if(alunos[i].propinas[j] == 0) {
                todasPagas = 0;
                break;
            }
        }
        if(todasPagas) em_dia++;
    }

    float media_idade = (float)soma_idades / total;

    roxo();
    printf("\n===== ESTATÍSTICAS =====\n");
    printf("Total de alunos: %d\n", total);
    printf("Média de idade: %.2f\n", media_idade);
    printf("Alunos com todas as propinas em dia: %d\n", em_dia);
    printf("\nDistribuição por curso:\n");
    printf("1 - Técnico de Informática: %d\n", cursos[1]);
    printf("2 - Bioquímica: %d\n", cursos[2]);
    printf("3 - Electricistas: %d\n", cursos[3]);
    printf("4 - Mecânica: %d\n", cursos[4]);
    printf("5 - Desenhador Projetista: %d\n", cursos[5]);
    printf("6 - Ensino Geral: %d\n", cursos[6]);
    reset();

    system("pause");
}

/* ================= LISTAR EM FALTA ================= */

void listar_em_falta() {
    system("cls");
    logo_sem_animacao();

    int encontrados = 0;

    for(int i = 0; i < total; i++) {
        int falta = 0;
        for(int j = 0; j < 11; j++) {
            if(alunos[i].propinas[j] == 0) {
                falta = 1;
                break;
            }
        }

        if(falta) {
            encontrados++;
            vermelho();
            printf("\n-------------------------------------");
            printf("\nMatrícula : %d", alunos[i].matricula);
            printf("\nNome      : %s", alunos[i].nome);
            printf("\nClasse    : %d", alunos[i].classe);
            printf("\nIdade     : %d", alunos[i].idade);
            char *cursoNome;
			switch(alunos[i].curso) {
	    		case 1: cursoNome = "Técnico de Informática"; break;
	    		case 2: cursoNome = "Bioquímica"; break;
	    		case 3: cursoNome = "Electricistas"; break;
	    		case 4: cursoNome = "Mecânica"; break;
	    		case 5: cursoNome = "Desenhador Projetista"; break;
	    		case 6: cursoNome = "Ensino Geral"; break;
    			default: cursoNome = "Indefinido";
			}
			printf("\nCurso     : %s", cursoNome);
            printf("\nSituação  : EM FALTA");
            printf("\n-------------------------------------\n");
            reset();
        }
    }

    if(encontrados == 0) {
        verde();
        printf("\nTodos os alunos estão com propinas em dia!\n");
        reset();
    }

    system("pause");
}

void programa_com_logo() {
    while(1) {
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
        }

        else if(escolha1 == 2) {
            menu_listagem();
            scanf("%d", &escolha2);

            if(escolha2 == 1) listar_meses_aluno();
            else if(escolha2 == 2) listar_por_mes();
            else if(escolha2 == 3) listar_por_classe_curso();
            else if(escolha2 == 4) listar_meses_todos();
        }

        else if(escolha1 == 3) {
            menu_estatistica();
            scanf("%d", &escolha2);

            if(escolha2 == 1) estatisticas();
            else if(escolha2 == 2) listar_em_falta();
            else if(escolha2 == 3) dados_estatisticos_avancados();
        }

        else if(escolha1 == 0) {
            system("cls");
            digitar("Encerrando o sistema...");
            Sleep(800);
            exit(0);
        }

        else {
            vermelho();
            printf("\nOpção inválida!\n");
            reset();
            Sleep(1200);
        }
    }
}

/* ================= CONTROLE ================= */
void programa() {
    menu_principal();
    scanf("%d", &escolha1);
    system("cls");
    if(escolha1 == 1){
        menu_registros();
        scanf("%d", &escolha2);
        if(escolha2 == 1) cadastrar();
        if(escolha2 == 2) atualizar_propinas();
        if(escolha2 == 3) precario();
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
    else if(escolha1 == 3) {
        menu_estatistica();
        scanf("%d", &escolha2);
        if(escolha2 == 1) estatisticas();
        else if(escolha2 == 2) listar_em_falta();
        else if(escolha2 == 3) dados_estatisticos_avancados();
        programa_com_logo();
    }
    else if(escolha1 == 0) {
        system("cls");
        digitar("Encerrando o sistema...");
        Sleep(800);
        exit(0);
	    }
	else {
        vermelho();
        printf("\nOpção inválida!\n");
        reset();
        Sleep(1200);
        programa_com_logo();
    }
}

/* ================= MAIN ================= */
int main() {
    setlocale(LC_ALL, "Portuguese");

    system("cls");
    verde();
    barra_carregamento_basica();
    Sleep(1000);
    system("cls");
    logo();
    programa();
    return 0;
}#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>

#define MAX 1000
/* considercoes de comandos*/
/* ================= REGISTRO ================= */
typedef struct {
    int matricula;
    char nome[50];
    int classe;
    int idade;
    int curso;      // 1 a 6 cursos
    int propinas[11];  // 1 = em dia | 0 = em falta
    char bi[20];
} Aluno;

/* ================= VARIÁVEIS ================= */
Aluno alunos[MAX];
int total = 0;
int prox_matricula = 1;
int escolha1, escolha2;
float preco_propina[7]={0};

/* ================= UTILITÁRIOS VISUAIS ================= */
void reset()   { printf("\033[0m"); } //cod da cor branca 
void azul()    { printf("\033[1;34m"); }
void verde()   { printf("\033[1;32m"); }
void amarelo() { printf("\033[1;33m"); }
void vermelho(){ printf("\033[1;31m"); }
void roxo()    { printf("\033[1;35m"); }
void ciano()   { printf("\033[1;36m"); }
void branco()  { printf("\033[1;37m"); }

//responsavel por fazer a animação de inserção de letra
void digitar(const char *t) { // simular um printf e ao mesmo tempo analisar caracter por caracter a mensagem a ser iprimida  
    while(*t) { // enquanto tiver algum caracter a apresentar 
        printf("%c", *t++); // apresentar um caracter 
        Sleep(15); //dar um atraso a imprimir os caracteres na tela
    }
}

/* ================= LOGO KEA ================= */
void logo() {
    ciano();
    digitar("\t\t\t\t '***''  '***''    '*********''     '**********''\n");
    digitar("\t\t\t\t '***'' '***''     '*********''    '************''\n");
    digitar("\t\t\t\t '***'''***''      '***''         '***''     '***''\n");
    digitar("\t\t\t\t '********''       '*********''  '*****************''\n");
    digitar("\t\t\t\t '*********''      '*********''  '*****************''\n");
    digitar("\t\t\t\t '***'''****''     '***''        '***''        '***''\n");
    digitar("\t\t\t\t '***'' '****''    '*********''  '***''        '***''\n");
    digitar("\t\t\t\t '***''  '****''   '*********''  '***''        '***''\n");
    reset();
}

void logo_sem_animacao(){
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

/* ================= MENUS ================= */
void menu_principal() {
    ciano();
    printf("\n\t\t\t\t\t()------------------------------------()"); Sleep(150);
    printf("\n\t\t\t\t\t''        SISTEMA DE PAGAMENTOS       ''"); Sleep(150);
    printf("\n\t\t\t\t\t''------------------------------------''"); Sleep(150);
    verde();
    printf("\n\t\t\t\t\t'' 1 - Registos                       ''"); Sleep(150);
    printf("\n\t\t\t\t\t'' 2 - Listagem                       ''"); Sleep(150);
    printf("\n\t\t\t\t\t'' 3 - Dados Estatisticos             ''"); Sleep(150);
    vermelho();
    printf("\n\t\t\t\t\t'' 0 - Encerrar                       ''"); Sleep(150);
    ciano();
    printf("\n\t\t\t\t\t()------------------------------------()"); Sleep(150);
    branco();
    printf("\n\t\t\t\t\tEscolha: ");
    reset();
}

void menu_principal_com_logo() {
    system("cls");
    logo_sem_animacao();
    ciano();
    printf("\n\t\t\t\t\t()------------------------------------()"); Sleep(150);
    printf("\n\t\t\t\t\t''        SISTEMA DE PAGAMENTOS       ''"); Sleep(150);
    printf("\n\t\t\t\t\t''------------------------------------''"); Sleep(150);
    verde();
    printf("\n\t\t\t\t\t'' 1 - Registos                       ''"); Sleep(150);
    printf("\n\t\t\t\t\t'' 2 - Listagem                       ''"); Sleep(150);
    printf("\n\t\t\t\t\t'' 3 - Dados Estatísticos             ''"); Sleep(150);
    vermelho();
    printf("\n\t\t\t\t\t'' 0 - Encerrar                       ''"); Sleep(150);
    ciano();
    printf("\n\t\t\t\t\t()------------------------------------()"); Sleep(150);
    branco();
    printf("\n\t\t\t\t\tEscolha: ");
    reset();
}
    
void menu_registros() {
    system("cls");
    logo_sem_animacao();
    printf("\n");
    verde();
    printf("\t\t\t\t\t()----------------------------()\n");
    printf("\t\t\t\t\t''       MENU REGISTOS        ''\n");
    printf("\t\t\t\t\t''----------------------------''\n");
    printf("\t\t\t\t\t'' 1 - Cadastrar aluno        ''\n");
    printf("\t\t\t\t\t'' 2 - atualizar propina      ''\n");
    printf("\t\t\t\t\t'' 3 - preçário das propinas  ''\n");
    printf("\t\t\t\t\t'' 4 - atualizar dados        ''\n");
    printf("\t\t\t\t\t'' 0 - Voltar                 ''\n");
    printf("\t\t\t\t\t()----------------------------()\n");
    printf("\t\t\t\t\tEscolha: ");
    reset();
}

void menu_precario() {
    system("cls");
    logo_sem_animacao();
    printf("\n");
    verde();
    printf("\t\t\t\t\t()----------------------------()\n");
    printf("\t\t\t\t\t''       MENU PERÇÁRIO        ''\n");
    printf("\t\t\t\t\t''----------------------------''\n");
    printf("\t\t\t\t\t'' 1 - definir preçário       ''\n");
    printf("\t\t\t\t\t'' 2 - atualizar preçário     ''\n");
    printf("\t\t\t\t\t'' 3 - consulta do preçário   ''\n");
    printf("\t\t\t\t\t'' 0 - Voltar                 ''\n");
    printf("\t\t\t\t\t()----------------------------()\n");
    printf("\t\t\t\t\tEscolha: ");
    reset();
}

void menu_listagem() {
    system("cls");
    logo_sem_animacao();
    printf("\n");
    amarelo();
    printf("\t\t\t\t\t()-----------------------------------------------()\n");
    printf("\t\t\t\t\t''                  MENU LISTAGEM                ''\n");
    printf("\t\t\t\t\t''-----------------------------------------------''\n");
    printf("\t\t\t\t\t'' 1 - Ver meses pagos e em atraso de um aluno   ''\n");
    printf("\t\t\t\t\t'' 2 - Listar alunos que não pagaram um mês      ''\n");
    printf("\t\t\t\t\t'' 3 - Listar alunos em atraso por classe/curso  ''\n");
    printf("\t\t\t\t\t'' 4 - Listar meses pagos ou em atraso de todos  ''\n");
    printf("\t\t\t\t\t'' 0 - Voltar                                    ''\n");
    printf("\t\t\t\t\t()-----------------------------------------------()\n");
    printf("\t\t\t\t\tEscolha: ");
    reset();
}

void menu_estatistica() {
    system("cls");
    logo_sem_animacao();
    printf("\n");
    roxo();
    printf("\t\t\t\t\t()----------------------------()\n");
    printf("\t\t\t\t\t''     DADOS ESTATÍSTICOS     ''\n");
    printf("\t\t\t\t\t''----------------------------''\n");
    printf("\t\t\t\t\t'' 1 - Ver estatísticas       ''\n");
    printf("\t\t\t\t\t'' 2 - Alunos em falta        ''\n");
    printf("\t\t\t\t\t'' 3 - Estatísticas por mês   ''\n");
    printf("\t\t\t\t\t'' 0 - Voltar                 ''\n");
    printf("\t\t\t\t\t()----------------------------()\n");
    printf("\t\t\t\t\tEscolha: ");
    reset();
}

/* ================= CURSO ================= */
int escolher_curso() {
    int op;
    do {
        ciano();
        printf("\n====================================");
        printf("\n        SELECIONE O CURSO");
        printf("\n====================================");
        printf("\n 1 - Técnico de Informática");
        printf("\n 2 - Bioquímica");
        printf("\n 3 - Electricistas");
        printf("\n 4 - Mecânica");
        printf("\n 5 - Desenhador Projetista");
        printf("\n 6 - Ensino Geral (Sem curso)");
        printf("\n====================================");
        branco();
        printf("\nEscolha (1 a 6): ");

        scanf("%d", &op);

        if(op < 1 || op > 6) {
            vermelho();
            printf("\nOpção inválida! Tente novamente.\n");
            reset();
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
        printf("\n 1 - 8º");
        printf("\n 2 - 9º");
        printf("\n 3 - 10º");
        printf("\n 4 - 11º");
        printf("\n 5 - 12º");
        printf("\n 6 - 13º");
        printf("\n===================================\n");
        scanf("%d", &op);
    } while(op < 1 || op > 6);

    return op + 7;
}

/* ================= PREÇÁRIO ================= */
void definir_precario() {
    int curso;
    float valor;
    curso = escolher_curso();
    printf("\nDigite o valor da propina para este curso: ");
    scanf("%f", &valor);
    preco_propina[curso] = valor;
    verde();
    printf("\nPreçário definido com sucesso!\n");
    reset();
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
    verde();
    printf("\nPreçário atualizado com sucesso!\n");
    reset();
    system("pause");
}

void consultar_precario() {
    system("cls");
    ciano();
    printf("\n===== CONSULTA DO PREÇÁRIO =====\n");
    printf("1 - Técnico de Informática: %.2f\n", preco_propina[1]);
    printf("2 - Bioquímica: %.2f\n", preco_propina[2]);
    printf("3 - Electricistas: %.2f\n", preco_propina[3]);
    printf("4 - Mecânica: %.2f\n", preco_propina[4]);
    printf("5 - Desenhador Projetista: %.2f\n", preco_propina[5]);
    printf("6 - Ensino Geral: %.2f\n", preco_propina[6]);
    reset();
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
                vermelho();
                printf("\nOpção inválida!\n");
                reset();
                Sleep(1200);
        }
    } while(escolhap != 0);
}


/* ================= FUNCIONALIDADES ================= */

int encontrar() {
    int mat;
    char bi[20];
    int escolha;

    printf("\nBuscar aluno por:\n");
    printf("1 - Matrícula\n");
    printf("2 - BI\n");
    printf("Escolha: ");
    scanf("%d", &escolha);

    if(escolha == 1) {
        printf("\nDigite a matrícula: ");
        scanf("%d", &mat);
        for(int i = 0; i < total; i++) {
            if(alunos[i].matricula == mat) return i;
        }
    }
    else if(escolha == 2) {
        printf("\nDigite o número do BI: ");
        scanf("%19s", bi);
        for(int i = 0; i < total; i++) {
            if(strcmp(alunos[i].bi, bi) == 0) return i;
        }
    }

    return -1;
}

/* ===================== LISTAGENS ====================*/

void atualizar_aluno() {
    system("cls");
    logo_sem_animacao();
    printf("\n");

    if(total == 0) {
        vermelho();
        printf("\nNenhum aluno cadastrado.\n");
        reset();
        system("pause");
        return;
    }

    int idx = encontrar(); // busca por matrícula ou BI
    if(idx == -1) {
        vermelho();
        printf("\nAluno não encontrado!\n");
        reset();
        system("pause");
        return;
    }

    Aluno *a = &alunos[idx];

    verde();
    printf("\nAtualizando dados do aluno:\n");
    printf("Matrícula: %d\n", a->matricula);
    printf("Nome atual: %s\n", a->nome);
    reset();

    while(getchar() != '\n'); // limpar buffer
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
	
	while(getchar() != '\n'); // limpar buffer
	char novoBI[20];
	
	fgets(novoBI, sizeof(novoBI), stdin);
    if(novoBI[0] != '\n') {
        novoBI[strcspn(novoBI, "\n")] = 0;
        strcpy(a->bi, novoBI);
    }

    verde();
    printf("\nDados atualizados com sucesso!\n");
    reset();
    system("pause");
}

void listar_meses_aluno() {
    int idx = encontrar();
    if(idx == -1) {
        vermelho(); printf("\nAluno não encontrado!\n"); reset();
        system("pause"); return;
    }
    char *meses[11] = {"Setembro","Outubro","Novembro","Dezembro","Janeiro",
                       "Fevereiro","Março","Abril","Maio","Junho","Julho"};

    verde(); printf("\nMeses pagos:\n");
    for(int i=0;i<11;i++) if(alunos[idx].propinas[i]==1) printf(" - %s\n", meses[i]);
    vermelho(); printf("\nMeses em atraso:\n");
    for(int i=0;i<11;i++) if(alunos[idx].propinas[i]==0) printf(" - %s\n", meses[i]);
    reset();
    system("pause");
}

void listar_por_mes() {
    char *meses[11] = {"Setembro","Outubro","Novembro","Dezembro","Janeiro",
                       "Fevereiro","Março","Abril","Maio","Junho","Julho"};
    int mes;
    printf("\nDigite o número do mês (1-11): ");
    scanf("%d",&mes);
    
    if(mes < 1 || mes > 11) {
	    vermelho();
	    printf("\nMês inválido!\n");
	    reset();
	    system("pause");
	    return;
	}

    vermelho(); printf("\nAlunos em atraso no mês %s:\n", meses[mes-1]);
    for(int i=0;i<total;i++) {
        if(alunos[i].propinas[mes-1]==0) {
            printf(" - %s (Matrícula %d)\n", alunos[i].nome, alunos[i].matricula);
        }
    }
    reset();
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

        
        vermelho(); printf("\nAlunos da classe %d com mensalidades em atraso:\n", classe);
        for(int i=0;i<total;i++) {
            if(alunos[i].classe==classe) {
                for(int j=0;j<11;j++) if(alunos[i].propinas[j]==0) {
                    printf(" - %s (Matrícula %d)\n", alunos[i].nome, alunos[i].matricula);
                    break;
                }
            }
        }
    } else if(tipo==2) {
        int curso=escolher_curso();
        vermelho(); printf("\nAlunos do curso %d com mensalidades em atraso:\n", curso);
        for(int i=0;i<total;i++) {
            if(alunos[i].curso==curso) {
                for(int j=0;j<11;j++) if(alunos[i].propinas[j]==0) {
                    printf(" - %s (Matrícula %d)\n", alunos[i].nome, alunos[i].matricula);
                    break;
                }
            }
        }
    }
    reset();
    system("pause");
}

void listar_meses_todos() {
    char *meses[11] = {"Setembro","Outubro","Novembro","Dezembro","Janeiro",
                       "Fevereiro","Março","Abril","Maio","Junho","Julho"};
    for(int i=0;i<total;i++) {
        printf("\nAluno: %s (Matrícula %d)\n", alunos[i].nome, alunos[i].matricula);
        verde(); printf("Meses pagos: ");
        for(int j=0;j<11;j++) if(alunos[i].propinas[j]==1) printf("%s ", meses[j]);
        vermelho(); printf("\nMeses em atraso: ");
        for(int j=0;j<11;j++) if(alunos[i].propinas[j]==0) printf("%s ", meses[j]);
        reset(); printf("\n-------------------------------------\n");
    }
    system("pause");
}

int nome_valido(char nome[]) {
    
    for(int i = 0; nome[i] != '\0'; i++) {
        if(nome[i] != ' ' && nome[i] != '\n') {
            return 1; 
        }
    }
    return 0; 
}

int idade_valida(int idade) {
    return (idade >= 5 && idade <= 100);
}

int bi_existe(char bi[]) {
    for(int i = 0; i < total; i++) {
        if(strcmp(alunos[i].bi, bi) == 0) {
            return 1; 
        }
    }
    return 0;
}

void cadastrar() {
    Aluno a;
    system("cls");
	logo_sem_animacao();
	printf("\n");
    if(total >= MAX) {
        vermelho();
        printf("\nLimite atingido!\n");
        reset();
        return;
    }

    a.matricula = prox_matricula++;

    ciano();
    for(int i = 0; i < 50; i++) printf("*");
    
char nomeTemp[50];

	do {
	    printf("\nNome do aluno: ");
	    scanf(" %49[^\n]", nomeTemp);
	
	    if(!nome_valido(nomeTemp)) {
	        vermelho();
	        printf("\nNome não pode estar vazio!\n");
	        reset();
	    }
	
	} while(!nome_valido(nomeTemp));
	
	strcpy(a.nome, nomeTemp);

    a.classe = escolher_classe();

    for(int i = 0; i < 50; i++) printf("*");
    do {
	    printf("\nIdade: ");
	    scanf("%d", &a.idade);
	
	    if(!idade_valida(a.idade)) {
	        vermelho();
	        printf("\nIdade inválida! (5 - 100)\n");
	        reset();
	    }

	} while(!idade_valida(a.idade));

    for(int i = 0; i < 50; i++) printf("*");
    a.curso = escolher_curso();

    for(int i = 0; i < 50; i++) printf("*");
    
    for(int i = 0; i < 11; i++) a.propinas[i]=0;
    
    char biTemp[20];

	do {
	    printf("\nInsira o BI: ");
	    scanf("%19s", biTemp);
	
	    if(bi_existe(biTemp)) {
	        vermelho();
	        printf("\nEste BI já está cadastrado!\n");
	        reset();
	    }
	
	} while(bi_existe(biTemp));

	strcpy(a.bi, biTemp);

    alunos[total++] = a;
	printf("\n");
    verde();
    for(int i = 0; i < 50; i++) printf("*");
    printf("\nAluno cadastrado com sucesso!");
    printf("\nMatricula: %d\n", a.matricula);
    reset();
    system("pause");
    system("cls");
    
}

/* ================= ATUALIZAR PROPINAS ================= */

void atualizar_propinas() {
    system("cls");
    logo_sem_animacao();
    printf("\n");
    char *meses[11] = {"Setembro","Outubro","Novembro","Dezembro","Janeiro",
                       "Fevereiro","Março","Abril","Maio","Junho","Julho"};

    int matx = encontrar();

    if(matx == -1) {
        vermelho();
        printf("\nAluno não encontrado!\n");
        reset();
        system("pause");
        return;
    }

    int op;
    do {
        system("cls");
        logo_sem_animacao();

        ciano();
        printf("\nPropinas de %s\n\n", alunos[matx].nome);

        for(int i = 0; i < 11; i++) {
            printf("%d - %s [%s]\n",
                i + 1,
                meses[i],
                alunos[matx].propinas[i] ? "PAGO" : "NÃO PAGO"
            );
        }

        printf("\n12 - Anular pagamento de um mês");
        printf("\n0  - Voltar");
        printf("\nEscolha: ");
        reset();

        scanf("%d", &op);

        if(op >= 1 && op <= 11) {
            // Verifica se meses anteriores estão pagos
            int permitido = 1;
            for(int k = 0; k < op-1; k++) {
                if(alunos[matx].propinas[k] == 0) {
                    permitido = 0;
                    break;
                }
            }

            if(permitido) {
                alunos[matx].propinas[op - 1] = 1;
                verde();
                printf("\nPagamento do mês %s registrado!\n", meses[op-1]);
                reset();
            } else {
                vermelho();
                printf("\nNão é possível pagar %s antes de quitar os meses anteriores!\n", meses[op-1]);
                reset();
            }
            Sleep(800);
        }
        else if(op == 12) {
            int mes;
            printf("\nDigite o número do mês para anular (1 a 11): ");
            scanf("%d", &mes);

            if(mes >= 1 && mes <= 11) {
                // Ao anular, todos os meses seguintes também ficam em atraso
                for(int j = mes-1; j < 11; j++) {
                    alunos[matx].propinas[j] = 0;
                }
                verde();
                printf("\nPagamento de %s e meses seguintes foram anulados!\n", meses[mes-1]);
                reset();
                Sleep(800);
            } else {
                vermelho();
                printf("\nMês inválido!\n");
                reset();
                Sleep(800);
            }
        }
        else if(op != 0) {
            vermelho();
            printf("\nOpção inválida!\n");
            reset();
            Sleep(800);
        }

    } while(op != 0);
    system("cls");
}


/* ================= BARRA DE CARREGAMENTO ================= */
void barra_carregamento_basica() {
    int largura = 40;
    int i;

    printf("\n\n");

    for(i = 0; i <= largura; i++) {
        Sleep(100);
        int espacos = (80 - largura) / 2;
        for(int j = 0; j < espacos; j++) printf(" ");
        
        printf("[");
        for(int j = 0; j < i; j++) printf("#");
        for(int j = i; j < largura; j++) printf(" ");
        printf("] %d%%\r", (i * 100) / largura);
        fflush(stdout);
    }
    printf("\n\n");
    system("pause");
}

/* ================= LISTAGEM ================= */
void mostrar_listagem() {
    system("cls");
    logo_sem_animacao();
    printf("\n");
    if(total == 0) {
        vermelho();
        printf("\nNenhum aluno cadastrado.\n");
        reset();
        Sleep(1500);
    } else {
        char *meses[11] = {"Setembro","Outubro","Novembro","Dezembro","Janeiro",
                           "Fevereiro","Março","Abril","Maio","Junho","Julho"};
        for(int i = 0; i < total; i++) {
            char *cursoNome;
            switch(alunos[i].curso) {
                case 1: cursoNome = "Técnico de Informática"; break;
                case 2: cursoNome = "Bioquímica"; break;
                case 3: cursoNome = "Electricistas"; break;
                case 4: cursoNome = "Mecânica"; break;
                case 5: cursoNome = "Desenhador Projetista"; break;
                case 6: cursoNome = "Ensino Geral"; break;
                default: cursoNome = "Indefinido";
            }

            ciano();
            printf("\n-------------------------------------");
            printf("\nMatrícula : %d", alunos[i].matricula);
            printf("\nNome      : %s", alunos[i].nome);
            printf("\nClasse    : %d", alunos[i].classe);
            printf("\nIdade     : %d", alunos[i].idade);
            printf("\nCurso     : %s", cursoNome);

            verde(); printf("\nMeses pagos: ");
            for(int j=0;j<11;j++) if(alunos[i].propinas[j]==1) printf("%s ", meses[j]);

            vermelho(); printf("\nMeses em atraso: ");
            for(int j=0;j<11;j++) if(alunos[i].propinas[j]==0) printf("%s ", meses[j]);

            reset();
            printf("\n-------------------------------------\n");
        }
    }
    system("pause");
}


/* ================= ESTATÍSTICAS ================= */

void dados_estatisticos_avancados() {
    system("cls");
    logo_sem_animacao();
    printf("\n");

    if(total == 0) {
        vermelho();
        printf("\nNenhum aluno cadastrado.\n");
        reset();
        system("pause");
        return;
    }

    char *meses[11] = {"Setembro","Outubro","Novembro","Dezembro","Janeiro",
                       "Fevereiro","Março","Abril","Maio","Junho","Julho"};

    int mes;
    printf("\nDigite o número do mês (1 a 11): ");
    scanf("%d", &mes);
    if(mes < 1 || mes > 11) {
        vermelho();
        printf("\nMês inválido!\n");
        reset();
        system("pause");
        return;
    }

    mes -= 1; // ajustar índice

    int totalPagantes = 0;
    int totalNaoPagantes = 0;
    float saldoTotal = 0;
    int porClasse[14] = {0}; // classes de 8 a 13

    for(int i = 0; i < total; i++) {
        if(alunos[i].propinas[mes] == 1) {
            totalPagantes++;
            saldoTotal += preco_propina[alunos[i].curso];
            porClasse[alunos[i].classe]++;
        } else {
            totalNaoPagantes++;
        }
    }

    float percentagem = (totalPagantes * 100.0) / total;

    roxo();
    printf("\n===== ESTATÍSTICAS DO MÊS DE %s =====\n", meses[mes]);
    printf("Total de estudantes: %d\n", total);
    printf("Pagaram: %d\n", totalPagantes);
    printf("Não pagaram: %d\n", totalNaoPagantes);
    printf("Percentagem de pagamento: %.2f%%\n", percentagem);
    printf("Saldo arrecadado: %.2f\n", saldoTotal);
    printf("\nValor arrecadado por classe:\n");
    for(int i = 8; i <= 13; i++) {
        printf("Classe %d: %d alunos pagaram\n", i, porClasse[i]);
    }
    reset();

    system("pause");
}

void estatisticas() {
    system("cls");
    logo_sem_animacao();
	printf("\n");
    if(total == 0) {
        vermelho();
        printf("\nNenhum aluno cadastrado.\n");
        reset();
        system("pause");
        return;
    }

    int soma_idades = 0;
    int cursos[7] = {0};
    int em_dia = 0;

    for(int i = 0; i < total; i++) {
        soma_idades += alunos[i].idade;
        cursos[alunos[i].curso]++;
        
        int todasPagas = 1;
        for(int j = 0; j < 11; j++) {
            if(alunos[i].propinas[j] == 0) {
                todasPagas = 0;
                break;
            }
        }
        if(todasPagas) em_dia++;
    }

    float media_idade = (float)soma_idades / total;

    roxo();
    printf("\n===== ESTATÍSTICAS =====\n");
    printf("Total de alunos: %d\n", total);
    printf("Média de idade: %.2f\n", media_idade);
    printf("Alunos com todas as propinas em dia: %d\n", em_dia);
    printf("\nDistribuição por curso:\n");
    printf("1 - Técnico de Informática: %d\n", cursos[1]);
    printf("2 - Bioquímica: %d\n", cursos[2]);
    printf("3 - Electricistas: %d\n", cursos[3]);
    printf("4 - Mecânica: %d\n", cursos[4]);
    printf("5 - Desenhador Projetista: %d\n", cursos[5]);
    printf("6 - Ensino Geral: %d\n", cursos[6]);
    reset();

    system("pause");
}

/* ================= LISTAR EM FALTA ================= */

void listar_em_falta() {
    system("cls");
    logo_sem_animacao();

    int encontrados = 0;

    for(int i = 0; i < total; i++) {
        int falta = 0;
        for(int j = 0; j < 11; j++) {
            if(alunos[i].propinas[j] == 0) {
                falta = 1;
                break;
            }
        }

        if(falta) {
            encontrados++;
            vermelho();
            printf("\n-------------------------------------");
            printf("\nMatrícula : %d", alunos[i].matricula);
            printf("\nNome      : %s", alunos[i].nome);
            printf("\nClasse    : %d", alunos[i].classe);
            printf("\nIdade     : %d", alunos[i].idade);
            char *cursoNome;
			switch(alunos[i].curso) {
	    		case 1: cursoNome = "Técnico de Informática"; break;
	    		case 2: cursoNome = "Bioquímica"; break;
	    		case 3: cursoNome = "Electricistas"; break;
	    		case 4: cursoNome = "Mecânica"; break;
	    		case 5: cursoNome = "Desenhador Projetista"; break;
	    		case 6: cursoNome = "Ensino Geral"; break;
    			default: cursoNome = "Indefinido";
			}
			printf("\nCurso     : %s", cursoNome);
            printf("\nSituação  : EM FALTA");
            printf("\n-------------------------------------\n");
            reset();
        }
    }

    if(encontrados == 0) {
        verde();
        printf("\nTodos os alunos estão com propinas em dia!\n");
        reset();
    }

    system("pause");
}

void programa_com_logo() {
    while(1) {
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
        }

        else if(escolha1 == 2) {
            menu_listagem();
            scanf("%d", &escolha2);

            if(escolha2 == 1) listar_meses_aluno();
            else if(escolha2 == 2) listar_por_mes();
            else if(escolha2 == 3) listar_por_classe_curso();
            else if(escolha2 == 4) listar_meses_todos();
        }

        else if(escolha1 == 3) {
            menu_estatistica();
            scanf("%d", &escolha2);

            if(escolha2 == 1) estatisticas();
            else if(escolha2 == 2) listar_em_falta();
            else if(escolha2 == 3) dados_estatisticos_avancados();
        }

        else if(escolha1 == 0) {
            system("cls");
            digitar("Encerrando o sistema...");
            Sleep(800);
            exit(0);
        }

        else {
            vermelho();
            printf("\nOpção inválida!\n");
            reset();
            Sleep(1200);
        }
    }
}

/* ================= CONTROLE ================= */
void programa() {
    menu_principal();
    scanf("%d", &escolha1);
    system("cls");
    if(escolha1 == 1){
        menu_registros();
        scanf("%d", &escolha2);
        if(escolha2 == 1) cadastrar();
        if(escolha2 == 2) atualizar_propinas();
        if(escolha2 == 3) precario();
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
    else if(escolha1 == 3) {
        menu_estatistica();
        scanf("%d", &escolha2);
        if(escolha2 == 1) estatisticas();
        else if(escolha2 == 2) listar_em_falta();
        else if(escolha2 == 3) dados_estatisticos_avancados();
        programa_com_logo();
    }
    else if(escolha1 == 0) {
        system("cls");
        digitar("Encerrando o sistema...");
        Sleep(800);
        exit(0);
	    }
	else {
        vermelho();
        printf("\nOpção inválida!\n");
        reset();
        Sleep(1200);
        programa_com_logo();
    }
}

/* ================= MAIN ================= */
int main() {
    setlocale(LC_ALL, "Portuguese");

    system("cls");
    verde();
    barra_carregamento_basica();
    Sleep(1000);
    system("cls");
    logo();
    programa();
    return 0;
}