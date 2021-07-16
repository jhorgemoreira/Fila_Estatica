#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DEFINIÇÃO DO TAMANHO MÁXIMO DA FILA
#define MAX 5

int tamanho_fila = 0;

// ESTRUTURA DOS ALUNOS QUE SERÃO CADASTRADOS NO SISTEMA
typedef struct {

    char nome[10];
    int matricula;
    int idade;

}ALUNO;

// MENU DE OPÇÕES
void Menu() {

    printf("\t 1 - INSERIR NA FILA \n");
    printf("\t 2 - LISTAR FILA \n");
    printf("\t 3 - CONSULTAR FILA \n");
    printf("\t 4 - TAMANHO DA FILA \n");
    printf("\t 5 - PRIMEIRO DA FILA \n");
    printf("\t 6 - GRAVAR NO ARQUIVO \n");
    printf("\t 7 - CARREGAR DO ARQUIVO \n");
    printf("\t 8 - REMOVER DA FILA \n");
    printf("\t 9 - SAIR \n");

}

// LIMPAR A TELA DEPOIS DA ESCOLHA DE UMA OPÇAO
void Limpar_Tela() {

    system("cls");

}

// INICIALIZAR O TAMANHO DA FILA COM O VALOR ZERO
void Inicializar_Fila() {

    int tamanho_fila = 0;

}

void Inserir_Fila(ALUNO aluno[]) {

    char nome[10];

    printf("\n\n");

    // VERIFICAR SE O TAMANHO DA FILA É IGUAL AO TAMANHO MÁXIMO PERMITIDO, SE ISSO ACONTECER A FILA ESTÁ CHEIA
    if(tamanho_fila == MAX) {

        printf("\t FILA CHEIA \n");

    }

    // INFORMAÇOES QUE SERÃO INSERIDAS
    else {

        printf("Informe o nome do aluno: \n");
        scanf("%s", &nome);
        setbuf(stdin, NULL);

        strcpy(aluno[tamanho_fila].nome, nome);

        printf("Informe a matrícula do aluno: \n");
        scanf("%d", &aluno[tamanho_fila].matricula);
        setbuf(stdin, NULL);

        printf("Informe a idade do aluno: \n");
        scanf("%d", &aluno[tamanho_fila].idade);
        setbuf(stdin, NULL);

        tamanho_fila++;

    }

    printf("\n\n");

}

void Listar_Fila(ALUNO aluno[]) {

    int i;

    printf("\n\n");

    // VERIFICAR SE O TAMANHO DA FILA É IGUAL A ZERO
    if(tamanho_fila == 0) {

        printf("\t FILA VAZIA \n");

    }

    // EXIBIÇÃO DAS INFORMAÇÕES DOS ALUNOS CADASTRADOS
    else {

        for(i = 0; i < tamanho_fila; i++) {

            printf("\t ===================================== \n");
            printf("\t POSICAO: %d \n", i+1);
            printf("\t NOME: %s \n", aluno[i].nome);
            printf("\t MATRÍCULA: %d \n", aluno[i].matricula);
            printf("\t IDADE: %d \n", aluno[i].idade);
            printf("\t ===================================== \n");

        }

    }

    printf("\n\n");

}

void Consultar_Fila(ALUNO aluno[]) {

    int matricula = 0;
    int i;

    if(tamanho_fila == 0) {

        printf("\t FILA VAZIA \n");

    }

    else {

        printf("Informe a matricula que deseja buscar: \n");
        scanf("%d", &matricula);

        for(i = 0; i < tamanho_fila; i++) {

            // VERIFICAR SE A MATRÍCULA INFORMADA PELA PESSOA É IGUAL A CADASTRADA NO SISTEMA, CASO SEJA VERDADEIRO AS INFORMAÇÕES SERÃO EXIBIDAS
            if(matricula == aluno[i].matricula) {

                printf("\t NOME: %s \n", aluno[i].nome);
                printf("\t MATRICULA: %d \n", aluno[i].matricula);
                printf("\t IDADE: %d \n", aluno[i].idade);
                break;

            }

            else {

                printf("\t A MATRICULA DO ALUNO NAO EXISTE NO SISTEMA \n");

            }

        }

        printf("\n");

    }

}

// VERIFICAR O TAMANHO DA FILA
int Tamanho_Fila() {

    printf("\n\n");

    return tamanho_fila;

    printf("\n\n");

}

void Primeiro_Fila(ALUNO aluno[]) {

    printf("\n\n");

    if(tamanho_fila == 0) {

        printf("\t FILA VAZIA \n");

    }

    else {

        for(int i = 0; i < tamanho_fila; i++) {

            // VERIFICAR SE É O PRIMEIRO ALUNO DA FILA
            if(i == 0) {

                printf("\t ===================================== \n");
                printf("\t NOME: %s \n", aluno[i].nome);
                printf("\t MATRÍCULA: %d \n", aluno[i].matricula);
                printf("\t IDADE: %d \n", aluno[i].idade);
                printf("\t ===================================== \n");
                break;

            }

        }

    }

    printf("\n\n");

}

void Gravar(ALUNO aluno[]) {

    FILE *arquivo;

    int i;

    // ABERTURA DO ARQUIVO
    arquivo = fopen("fila_estatica.txt", "w");

    printf("\n\n");

    if(arquivo == NULL) {

        printf("\t NÃO FOI POSSÍVEL ABRIR O ARQUIVO \n");
        exit(0);

    }

    // INFORMAÇÕES QUE SERÃO GRAVADAS NO ARQUIVO
    else {

        for(i = 0; i < tamanho_fila; i++) {

            //fprintf(arquivo, "%d \n ", i+1);
            fprintf(arquivo, "%s \n ", aluno[i].nome);
            fprintf(arquivo, "%d \n ", aluno[i].matricula);
            fprintf(arquivo, "%d \n ", aluno[i].idade);

        }

    }

    //FECHAMENTO DO ARQUIVO
    fclose(arquivo);

    printf("\n\n");

}

void Carregar(ALUNO aluno[]) {

    FILE *arquivo;

    int i = 0;
    int resultado = 0;

    arquivo = fopen("fila_estatica.txt", "r");

    printf("\n\n");

    if(arquivo == NULL) {

        printf("\t NÃO FOI POSSIVEL ABRIR NO ARQUIVO \n");
        exit(0);

    }

    else {

        while((resultado = fscanf(arquivo, "%s %d %d ",
        aluno[i].nome, &aluno[i].matricula, &aluno[i].idade) != EOF)) {

            printf("\t ===================================== \n");
            //printf("\t CÓDIGO: %d \n", i);
            printf("\t NOME: %s \n", aluno[i].nome);
            printf("\t MATRÍCULA: %d \n", aluno[i].matricula);
            printf("\t IDADE: %d \n", aluno[i].idade);
            printf("\t ===================================== \n");

            // VAI PASSAR PARA O PRÓXIMO ALUNO NO ARQUIVO
            i++;

            // TERÁ O TAMANHO AUMENTADO
            tamanho_fila++;

        }

    }

    fclose(arquivo);

    printf("\n\n");

}

void Remover_Fila(ALUNO aluno[]) {

    if(tamanho_fila == 0) {

        printf("\t FILA VAZIA \n");

    }

    // IRÁ SEMPRE PEGAR O PRIMEIRO ALUNO DA FILA PARA REMOÇÃO
    else if(aluno[0].matricula) {

        for(int i = 0; i < tamanho_fila; i++) {

            aluno[i] = aluno[i + 1];

        }

        tamanho_fila--;

    }

}

// CHAMADA DAS FUNÇOES NO MÉTODO PRINCIPAL
int main(void) {

    ALUNO aluno[MAX];

    int opcao = 0;

    Inicializar_Fila();

    do {

        Menu();

        printf("Informe uma opção: \n");
        scanf("%d", &opcao);

        Limpar_Tela();

        switch(opcao) {

            case 1:

                Inserir_Fila(aluno);
                break;

            case 2:

                Listar_Fila(aluno);
                break;

            case 3:

                Consultar_Fila(aluno);
                break;

            case 4:

                printf("\t TAMANHO DA FILA: %d \n", Tamanho_Fila());
                break;

            case 5:

                Primeiro_Fila(aluno);
                break;

            case 6:

                Gravar(aluno);
                break;

            case 7:

                Carregar(aluno);
                break;

            case 8:

                Remover_Fila(aluno);
                break;

            case 9:

                exit(0);
                break;

            default:

                printf("\t OPÇÃO INVÁLIDA \n");
                break;

        }

    }while(opcao != 0);

}

// CRIADO POR -> JORGE LUIS MOREIRA GOMES FILHO
// DATA -> 16/07/2021
