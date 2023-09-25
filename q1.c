#include <stdio.h>
#include <stdlib.h>

void removeHtmlTags(char *input, char *output) {
    int insideTag = 0;
    while (*input) {
        if (*input == '<') {
            insideTag = 1;
        } else if (*input == '>') {
            insideTag = 0;
        } else if (!insideTag) {
            *output = *input;
            output++;
        }
        input++;
    }
    *output = '\0';
}

int main() {
    char inputFile[] = "index.html"; 
    char outputFile[] = "output.txt"; 

    FILE *input = fopen(inputFile, "r");
    if (input == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    FILE *output = fopen(outputFile, "w");
    if (output == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        fclose(input);
        return 1;
    }

    char buffer[1024]; 

    while (fgets(buffer, sizeof(buffer), input) != NULL) {
        char cleanedLine[1024];
        removeHtmlTags(buffer, cleanedLine);
        fprintf(output, "%s", cleanedLine);
    }

    fclose(input);
    fclose(output);

    printf("Tags HTML removidas com sucesso. O texto limpo foi salvo em %s\n", outputFile);

    return 0;
}