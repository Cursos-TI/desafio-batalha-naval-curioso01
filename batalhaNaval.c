#include <stdio.h>

int main() {
    // Letras das colunas de A até J
    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // Tamanho fixo do tabuleiro e dos navios
    int tabuleiro[10][10];
    int tamanhoNavio = 3;

    // Inicializa o tabuleiro com 0 (representando água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas iniciais para o navio horizontal
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    // Coordenadas iniciais para o navio vertical
    int linhaVertical = 6;
    int colunaVertical = 1;

    // Posicionamento do navio horizontal (se não ultrapassar os limites e sem sobreposição)
    if (colunaHorizontal + tamanhoNavio <= 10) {
        int sobreposicao = 0;
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaHorizontal][colunaHorizontal + i] == 3) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
            }
        }
    }

    // Posicionamento do navio vertical (se não ultrapassar os limites e sem sobreposição)
    if (linhaVertical + tamanhoNavio <= 10) {
        int sobreposicao = 0;
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaVertical + i][colunaVertical] == 3) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaVertical + i][colunaVertical] = 3;
            }
        }
    }

    // Exibição do cabeçalho (título + letras das colunas)
    printf("TABULEIRO BATALHA NAVAL\n");
    printf("  "); // Espaço para alinhar os números das linhas
    for (int j = 0; j < 10; j++) {
        printf(" %c", colunas[j]);
    }
    printf("\n");

    // Exibição do tabuleiro com os números das linhas (1 a 10)
    for (int i = 0; i < 10; i++) {
        printf("%2d", i + 1); // Números das linhas com alinhamento
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
