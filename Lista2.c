#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trocar(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(char *arr[], int baixo, int alto, int *trocas) {
    char *pivot = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (strcmp(arr[j], pivot) <= 0) {
            i++;
            trocar(&arr[i], &arr[j]);
            (*trocas)++;
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    (*trocas)++;
    return (i + 1);
}

void quicksort(char *arr[], int baixo, int alto, int *trocas) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto, trocas);

        quicksort(arr, baixo, pi - 1, trocas);
        quicksort(arr, pi + 1, alto, trocas);
    }
}

int main() {
    char *arr[20] = {"maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi", "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"};
    int n = sizeof(arr) / sizeof(arr[0]);
    int trocas = 0;

    printf("Vetor original:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }

    quicksort(arr, 0, n - 1, &trocas);

    printf("\n\nVetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }

    printf("\n\nNumero de trocas: %d\n", trocas);

    FILE *arquivo_saida = fopen("saida.txt", "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao criar o arquivo de saida.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(arquivo_saida, "%s\n", arr[i]);
    }

    fclose(arquivo_saida);

    return 0;
}
