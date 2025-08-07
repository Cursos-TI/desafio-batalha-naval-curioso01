#include <stdio.h>

// Função para verificar se um navio pode ser colocado sem sair do tabuleiro e sem sobreposição
int podeColocar(int tabuleiro[10][10], int linha, int coluna, int tamanho, char direcao) {
    for (int i = 0; i < tamanho; i++) {
        int l = linha, c = coluna;

        if (direcao == 'H') c += i;
        else if (direcao == 'V') l += i;
        else if (direcao == 'D') { l += i; c += i; }
        else if (direcao == 'E') { l += i; c -= i; }

        // Verifica se está dentro dos limites
        if (l < 0 || l >= 10 || c < 0 || c >= 10) return 0;

        // Verifica se a posição já está ocupada
        if (tabuleiro[l][c] == 3) return 0;
    }

    return 1;
}

// Função para posicionar o navio na matriz
void colocarNavio(int tabuleiro[10][10], int linha, int coluna, int tamanho, char direcao) {
    for (int i = 0; i < tamanho; i++) {
        if (direcao == 'H') {
            tabuleiro[linha][coluna + i] = 3;  // Horizontal
        } else if (direcao == 'V') {
            tabuleiro[linha + i][coluna] = 3;  // Vertical
        } else if (direcao == 'D') {
            tabuleiro[linha + i][coluna + i] = 3;  // Diagonal descendente
        } else if (direcao == 'E') {
            tabuleiro[linha + i][coluna - i] = 3;  // Diagonal ascendente (espelhada)
        }
    }
}

int main() {
    int tabuleiro[10][10];
    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tamanhoNavio = 3;

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            tabuleiro[i][j] = 0;

    // Posicionamento dos navios
    // Navio 1 - Horizontal em (2, 1)
    if (podeColocar(tabuleiro, 2, 1, tamanhoNavio, 'H'))
        colocarNavio(tabuleiro, 2, 1, tamanhoNavio, 'H');

    // Navio 2 - Vertical em (5, 5)
    if (podeColocar(tabuleiro, 5, 5, tamanhoNavio, 'V'))
        colocarNavio(tabuleiro, 5, 5, tamanhoNavio, 'V');

    // Navio 3 - Diagonal descendente em (7, 7)
    if (podeColocar(tabuleiro, 7, 7, tamanhoNavio, 'D'))
        colocarNavio(tabuleiro, 7, 7, tamanhoNavio, 'D');

    // Navio 4 - Diagonal ascendente em (0, 9)
    if (podeColocar(tabuleiro, 0, 9, tamanhoNavio, 'E'))
        colocarNavio(tabuleiro, 0, 9, tamanhoNavio, 'E');

    // Exibição do tabuleiro com cabeçalhos
    printf("TABULEIRO BATALHA NAVAL\n");
    printf("   ");  // Espaço para alinhar os números
    for (int i = 0; i < 10; i++) {
        printf(" %c", colunas[i]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1);  // Número da linha
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
