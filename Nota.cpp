#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_NOTAS 100

struct nota {
    char titulo[50];
    char conteudo[500];
};

struct nota notas[MAX_NOTAS];
int num_notas = 0;

void adicionar_nota() {
    if (num_notas < MAX_NOTAS) {
        printf("Digite o título da nota: ");
        scanf(" %[^\n]", notas[num_notas].titulo);

        printf("Digite o conteúdo da nota: ");
        scanf(" %[^\n]", notas[num_notas].conteudo);

        num_notas++;
        printf("Nota adicionada com sucesso!\n");
    } else {
        printf("Não é possível adicionar mais notas.\n");
    }
}

void exibir_notas() {
    if (num_notas == 0) {
        printf("Não há notas para exibir.\n");
    } else {
        printf("Notas:\n");
        for (int i = 0; i < num_notas; i++) {
            printf("%d) %s:\n", i+1, notas[i].titulo);
            printf("%s\n", notas[i].conteudo);
            printf("--------\n");
        }
    }
}

void remover_nota() {
    if (num_notas == 0) {
        printf("Não há notas para remover.\n");
    } else {
        int num;
        printf("Digite o número da nota que deseja remover: ");
        scanf("%d", &num);

        if (num >= 1 && num <= num_notas) {
            for (int i = num-1; i < num_notas-1; i++) {
                strcpy(notas[i].titulo, notas[i+1].titulo);
                strcpy(notas[i].conteudo, notas[i+1].conteudo);
            }
            num_notas--;
            printf("Nota removida com sucesso!\n");
        } else {
            printf("Nota inválida.\n");
        }
    }
}

int main() {
	setlocale(LC_ALL, "Portuguese_Brazil");
	
    int opcao;

    while (1) {
        printf("Selecione uma opção:\n");
        printf("1) Adicionar nota\n");
        printf("2) Exibir notas\n");
        printf("3) Remover nota\n");
        printf("4) Sair\n");
        scanf("%d", &opcao);
        
        system("cls");


        switch (opcao) {
            case 1:
                adicionar_nota();
                break;
            case 2:
                exibir_notas();
                break;
            case 3:
                remover_nota();
                break;
            case 4:
                exit(0);
            default:
                printf("Opção inválida.\n");
                break;
        }
    }

    return 0;
}

