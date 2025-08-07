#include <stdio.h>
#include <stdlib.h>  // Para abs()

#define TAM 10         // Tamanho do tabuleiro
#define TAM_HAB 5      // Tamanho fixo das matrizes de habilidade

// ------------------------------
// Funções de geração das habilidades
// ------------------------------

// Gera matriz Cone: forma piramidal apontando para baixo
void gerarCone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Só preenche se a posição estiver dentro dos limites do "cone"
            if (i >= TAM_HAB / 2 && j >= (TAM_HAB / 2) - (i - TAM_HAB / 2) && j <= (TAM_HAB / 2) + (i - TAM_HAB / 2))
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Gera matriz Cruz: linhas e colunas cruzadas no centro
void gerarCruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Gera matriz Octaedro (losango)
void gerarOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// ------------------------------
// Aplica a matriz de habilidade ao tabuleiro
// ------------------------------
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna, int valor) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int l = origemLinha - TAM_HAB / 2 + i;
                int c = origemColuna - TAM_HAB / 2 + j;

                // Verifica limites e se a posição ainda está livre
                if (l >= 0 && l < TAM && c >= 0 && c < TAM && tabuleiro[l][c] == 0)
                    tabuleiro[l][c] = valor;
            }
        }
    }
}

// ------------------------------
// Exibe o tabuleiro formatado
// ------------------------------
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    char colunas[10] = {'A','B','C','D','E','F','G','H','I','J'};

    printf("\nTABULEIRO BATALHA NAVAL\n    ");
    for (int i = 0; i < TAM; i++)
        printf("%c ", colunas[i]);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d  ", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// ------------------------------
// Função principal
// ------------------------------
int main() {
    int tabuleiro[TAM][TAM]; // Tabuleiro principal
    int cone[TAM_HAB][TAM_HAB], cruz[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];

    // Inicializa o tabuleiro com água (valor 0)
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;

    // Gera as três matrizes de habilidades
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Aplica as habilidades no tabuleiro sem sobrepor:
    // Valor 3 = Cone
    // Valor 5 = Cruz
    // Valor 2 = Octaedro

    aplicarHabilidade(tabuleiro, cone, 3, 2, 3);       // Cone com centro na linha 4, coluna C
    aplicarHabilidade(tabuleiro, cruz, 2, 6, 5);       // Cruz com centro na linha 2, coluna G
    aplicarHabilidade(tabuleiro, octaedro, 7, 7, 2);   // Octaedro com centro na linha 7, coluna H

    // Exibe o resultado final
    exibirTabuleiro(tabuleiro);

    return 0;
}
