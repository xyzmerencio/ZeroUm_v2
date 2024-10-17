#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bins() {
    char user_input[100];
    char url[256];
    char output[110];
    char command[400];
    FILE *file;

    // Solicita ao usuário o nome do binário
    printf("Digite o binário a ser exploitado: ");
    scanf("%s", user_input);

    // Monta a URL e o nome do arquivo de saída
    snprintf(url, sizeof(url), "https://raw.githubusercontent.com/GTFOBins/GTFOBins.github.io/master/_gtfobins/%s.md", user_input);
    snprintf(output, sizeof(output), "%s.txt", user_input);

    // Monta o comando curl para fazer o download
    snprintf(command, sizeof(command), "curl -o %s %s", output, url);

    // Executa o comando curl
    int result = system(command);

    // Verifica se o download foi bem-sucedido
    if (result == 0) {
        printf("Conteúdo salvo em %s\n", output);

        // Abrindo o arquivo baixado
        file = fopen(output, "r");
        if (file == NULL) {
            printf("Erro ao abrir o arquivo %s\n", output);
            return;
        }

        // Lendo e imprimindo o conteúdo do arquivo
        char ch;
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
        }
        
        // Fechando o arquivo
        fclose(file);
    } else {
        printf("Arquivo não encontrado ou erro na requisição\n");
    }
}

int main() {
    bins();
    return 0;
}
