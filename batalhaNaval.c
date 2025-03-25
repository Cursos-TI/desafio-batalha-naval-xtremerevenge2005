#include <stdio.h>

// Constantes em tempo de compilação
enum {
    TAMANHO_TABULEIRO = 10,
    TAMANHO_NAVIO = 3
};

int main(void) {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int linha, coluna;

    // Inicializa todas as posições do tabuleiro com 0 (água)
    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }
    
    // Vetores que representam os navios (cada posição com valor 3)
    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navioVertical[TAMANHO_NAVIO]   = {3, 3, 3};
    int navioDiagonal1[TAMANHO_NAVIO]  = {3, 3, 3};
    int navioDiagonal2[TAMANHO_NAVIO]  = {3, 3, 3};

    // Coordenadas para os navios posicionados horizontalmente e verticalmente
    int linhaNavioHorizontal = 2;    // Linha para o navio horizontal
    int colunaNavioHorizontal = 3;     // Coluna inicial do navio horizontal

    int linhaNavioVertical = 5;        // Linha inicial do navio vertical
    int colunaNavioVertical = 6;       // Coluna para o navio vertical

    // Coordenadas para os navios posicionados na diagonal
    // Navio diagonal 1: orientação de cima-esquerda para baixo-direita
    int linhaNavioDiagonal1 = 0;       
    int colunaNavioDiagonal1 = 0;
    
    // Navio diagonal 2: orientação de cima-direita para baixo-esquerda
    int linhaNavioDiagonal2 = 0;
    int colunaNavioDiagonal2 = TAMANHO_TABULEIRO - 1;  // Coluna 9

    // --- Validações de limites e sobreposição ---

    // Navio horizontal
    if (colunaNavioHorizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal não cabe no tabuleiro.\n");
        return 1;
    }
    for (coluna = colunaNavioHorizontal; coluna < colunaNavioHorizontal + TAMANHO_NAVIO; coluna++) {
        if (tabuleiro[linhaNavioHorizontal][coluna] != 0) {
            printf("Erro: Navios se sobrepõem (horizontal).\n");
            return 1;
        }
    }
    for (coluna = colunaNavioHorizontal; coluna < colunaNavioHorizontal + TAMANHO_NAVIO; coluna++) {
        tabuleiro[linhaNavioHorizontal][coluna] = navioHorizontal[coluna - colunaNavioHorizontal];
    }
    
    // Navio vertical
    if (linhaNavioVertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical não cabe no tabuleiro.\n");
        return 1;
    }
    for (linha = linhaNavioVertical; linha < linhaNavioVertical + TAMANHO_NAVIO; linha++) {
        if (tabuleiro[linha][colunaNavioVertical] != 0) {
            printf("Erro: Navios se sobrepõem (vertical).\n");
            return 1;
        }
    }
    for (linha = linhaNavioVertical; linha < linhaNavioVertical + TAMANHO_NAVIO; linha++) {
        tabuleiro[linha][colunaNavioVertical] = navioVertical[linha - linhaNavioVertical];
    }
    
    // Navio diagonal 1 (cima-esquerda para baixo-direita)
    if ((linhaNavioDiagonal1 + TAMANHO_NAVIO > TAMANHO_TABULEIRO) || 
        (colunaNavioDiagonal1 + TAMANHO_NAVIO > TAMANHO_TABULEIRO)) {
        printf("Erro: Navio diagonal 1 não cabe no tabuleiro.\n");
        return 1;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhaNavioDiagonal1 + i][colunaNavioDiagonal1 + i] != 0) {
            printf("Erro: Navios se sobrepõem (diagonal 1).\n");
            return 1;
        }
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaNavioDiagonal1 + i][colunaNavioDiagonal1 + i] = navioDiagonal1[i];
    }
    
    // Navio diagonal 2 (cima-direita para baixo-esquerda)
    if ((linhaNavioDiagonal2 + TAMANHO_NAVIO > TAMANHO_TABULEIRO) || 
        (colunaNavioDiagonal2 - (TAMANHO_NAVIO - 1) < 0)) {
        printf("Erro: Navio diagonal 2 não cabe no tabuleiro.\n");
        return 1;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhaNavioDiagonal2 + i][colunaNavioDiagonal2 - i] != 0) {
            printf("Erro: Navios se sobrepõem (diagonal 2).\n");
            return 1;
        }
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaNavioDiagonal2 + i][colunaNavioDiagonal2 - i] = navioDiagonal2[i];
    }
    
    // --- Exibição do Tabuleiro ---
    printf("Tabuleiro:\n");
    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
