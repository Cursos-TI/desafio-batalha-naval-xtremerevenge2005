#include <stdio.h>

// Definição de constantes
enum {
    TAMANHO_TABULEIRO = 10,
    TAMANHO_NAVIO = 3
};

int main(void) {
    // Declaração da matriz que representa o tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int linha, coluna;

    // Inicializa todas as posições do tabuleiro com 0 (água)
    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }
    
    // Declaração e inicialização dos vetores que representam os navios
    // Cada posição do vetor possui o valor 3 (parte do navio)
    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navioVertical[TAMANHO_NAVIO]   = {3, 3, 3};

    // Definição das coordenadas iniciais para cada navio (definidas diretamente no código)
    int linhaNavioHorizontal = 2;    // Linha onde o navio horizontal será posicionado 
    int colunaNavioHorizontal = 3;   // Coluna inicial do navio horizontal

    int linhaNavioVertical = 5;      // Linha inicial do navio vertical
    int colunaNavioVertical = 6;     // Coluna onde o navio vertical será posicionado 

    // Validação: Verifica se o navio horizontal cabe no tabuleiro
    if (colunaNavioHorizontal - 1 + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal não cabe no tabuleiro.\n");
        return 1;
    }

    // Validação: Verifica se o navio vertical cabe no tabuleiro
    if (linhaNavioVertical - 1 + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical não cabe no tabuleiro.\n");
        return 1;
    }

    // Validação: Verifica se há sobreposição para o navio horizontal
    for (coluna = colunaNavioHorizontal; coluna < colunaNavioHorizontal + TAMANHO_NAVIO; coluna++) {
        if (tabuleiro[linhaNavioHorizontal][coluna] != 0) {
            printf("Erro: Navios se sobrepõem (sobreposição no navio horizontal).\n");
            return 1;
        }
    }
    // Posiciona o navio horizontal
    for (coluna = colunaNavioHorizontal; coluna < colunaNavioHorizontal + TAMANHO_NAVIO; coluna++) {
        tabuleiro[linhaNavioHorizontal][coluna] = navioHorizontal[coluna - colunaNavioHorizontal];
    }

    // Validação: Verifica se há sobreposição para o navio vertical
    for (linha = linhaNavioVertical; linha < linhaNavioVertical + TAMANHO_NAVIO; linha++) {
        if (tabuleiro[linha][colunaNavioVertical] != 0) {
            printf("Erro: Navios se sobrepõem (sobreposição no navio vertical).\n");
            return 1;
        }
    }
    // Posiciona o navio vertical
    for (linha = linhaNavioVertical; linha < linhaNavioVertical + TAMANHO_NAVIO; linha++) {
        tabuleiro[linha][colunaNavioVertical] = navioVertical[linha - linhaNavioVertical];
    }

    // Exibe o tabuleiro no console
    printf("Tabuleiro:\n");
    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
