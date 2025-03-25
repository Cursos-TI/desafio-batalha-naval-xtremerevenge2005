#include <stdio.h>

// Constantes em tempo de compilação
enum {
    TAMANHO_TABULEIRO = 10,
    TAMANHO_NAVIO = 3,
    ALTURA_HABILIDADE = 3,   // Número de linhas da matriz de habilidade
    LARGURA_HABILIDADE = 5   // Número de colunas da matriz de habilidade
};

int main(void) {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int linha, coluna;
    
    // Inicializa o tabuleiro com água (0)
    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }
    
    // ---------------------------
    // Posicionamento dos Navios
    // ---------------------------
    // Vetores que representam os navios (cada posição com valor 3)
    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navioVertical[TAMANHO_NAVIO]   = {3, 3, 3};
    int navioDiagonal1[TAMANHO_NAVIO]  = {3, 3, 3};
    int navioDiagonal2[TAMANHO_NAVIO]  = {3, 3, 3};

    // Coordenadas para os navios:
    // Navio horizontal: posicionado na linha 2, iniciando na coluna 3.
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 3;
    // Navio vertical: posicionado na coluna 6, iniciando na linha 5.
    int linhaNavioVertical = 5;
    int colunaNavioVertical = 6;
    // Navio diagonal 1 (cima-esquerda para baixo-direita): inicia em (0,0).
    int linhaNavioDiagonal1 = 0;
    int colunaNavioDiagonal1 = 0;
    // Navio diagonal 2 (cima-direita para baixo-esquerda): inicia em (0,9).
    int linhaNavioDiagonal2 = 0;
    int colunaNavioDiagonal2 = TAMANHO_TABULEIRO - 1;  // 9

    // Validação e posicionamento do navio horizontal
    if (colunaNavioHorizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal não cabe no tabuleiro.\n");
        return 1;
    }
    for (coluna = colunaNavioHorizontal; coluna < colunaNavioHorizontal + TAMANHO_NAVIO; coluna++) {
        if (tabuleiro[linhaNavioHorizontal][coluna] != 0) {
            printf("Erro: Sobreposição no navio horizontal.\n");
            return 1;
        }
    }
    for (coluna = colunaNavioHorizontal; coluna < colunaNavioHorizontal + TAMANHO_NAVIO; coluna++) {
        tabuleiro[linhaNavioHorizontal][coluna] = navioHorizontal[coluna - colunaNavioHorizontal];
    }
    
    // Validação e posicionamento do navio vertical
    if (linhaNavioVertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical não cabe no tabuleiro.\n");
        return 1;
    }
    for (linha = linhaNavioVertical; linha < linhaNavioVertical + TAMANHO_NAVIO; linha++) {
        if (tabuleiro[linha][colunaNavioVertical] != 0) {
            printf("Erro: Sobreposição no navio vertical.\n");
            return 1;
        }
    }
    for (linha = linhaNavioVertical; linha < linhaNavioVertical + TAMANHO_NAVIO; linha++) {
        tabuleiro[linha][colunaNavioVertical] = navioVertical[linha - linhaNavioVertical];
    }
    
    // Validação e posicionamento do navio diagonal 1 (cima-esquerda para baixo-direita)
    if ((linhaNavioDiagonal1 + TAMANHO_NAVIO > TAMANHO_TABULEIRO) ||
        (colunaNavioDiagonal1 + TAMANHO_NAVIO > TAMANHO_TABULEIRO)) {
        printf("Erro: Navio diagonal 1 não cabe no tabuleiro.\n");
        return 1;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhaNavioDiagonal1 + i][colunaNavioDiagonal1 + i] != 0) {
            printf("Erro: Sobreposição no navio diagonal 1.\n");
            return 1;
        }
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaNavioDiagonal1 + i][colunaNavioDiagonal1 + i] = navioDiagonal1[i];
    }
    
    // Validação e posicionamento do navio diagonal 2 (cima-direita para baixo-esquerda)
    if ((linhaNavioDiagonal2 + TAMANHO_NAVIO > TAMANHO_TABULEIRO) ||
        (colunaNavioDiagonal2 - (TAMANHO_NAVIO - 1) < 0)) {
        printf("Erro: Navio diagonal 2 não cabe no tabuleiro.\n");
        return 1;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhaNavioDiagonal2 + i][colunaNavioDiagonal2 - i] != 0) {
            printf("Erro: Sobreposição no navio diagonal 2.\n");
            return 1;
        }
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaNavioDiagonal2 + i][colunaNavioDiagonal2 - i] = navioDiagonal2[i];
    }
    
    // ---------------------------
    // Criação das Matrizes de Habilidade
    // ---------------------------
    // Utilizaremos matrizes de habilidade de tamanho 3x5, onde cada célula
    // terá valor 1 se estiver afetada pela habilidade ou 0 caso contrário.
    int habilidadeCone[ALTURA_HABILIDADE][LARGURA_HABILIDADE];
    int habilidadeCruz[ALTURA_HABILIDADE][LARGURA_HABILIDADE];
    int habilidadeOctaedro[ALTURA_HABILIDADE][LARGURA_HABILIDADE];
    
    // Preenche a matriz da habilidade Cone (cone apontando para baixo)
    // Regra:
    // Linha 0: somente coluna 2 afetada.
    // Linha 1: colunas 1, 2 e 3 afetadas.
    // Linha 2: todas as colunas afetadas.
    for (int i = 0; i < ALTURA_HABILIDADE; i++) {
        for (int j = 0; j < LARGURA_HABILIDADE; j++) {
            if (i == 0 && j == 2)
                habilidadeCone[i][j] = 1;
            else if (i == 1 && (j >= 1 && j <= 3))
                habilidadeCone[i][j] = 1;
            else if (i == 2)
                habilidadeCone[i][j] = 1;
            else
                habilidadeCone[i][j] = 0;
        }
    }
    
    // Preenche a matriz da habilidade Cruz (em forma de cruz)
    // Regra: a célula é afetada se estiver na linha central (i == 1) ou na coluna central (j == 2).
    for (int i = 0; i < ALTURA_HABILIDADE; i++) {
        for (int j = 0; j < LARGURA_HABILIDADE; j++) {
            if (i == 1 || j == 2)
                habilidadeCruz[i][j] = 1;
            else
                habilidadeCruz[i][j] = 0;
        }
    }
    
    // Preenche a matriz da habilidade Octaedro (vista frontal, formando um losango)
    // Regra:
    // Linhas 0 e 2: somente coluna 2 afetada.
    // Linha 1: colunas 1, 2 e 3 afetadas.
    for (int i = 0; i < ALTURA_HABILIDADE; i++) {
        for (int j = 0; j < LARGURA_HABILIDADE; j++) {
            if ((i == 0 || i == 2) && j == 2)
                habilidadeOctaedro[i][j] = 1;
            else if (i == 1 && (j >= 1 && j <= 3))
                habilidadeOctaedro[i][j] = 1;
            else
                habilidadeOctaedro[i][j] = 0;
        }
    }
    
    // ---------------------------
    // Sobreposição das Habilidades no Tabuleiro
    // ---------------------------
    // Cada matriz de habilidade será sobreposta ao tabuleiro a partir de um ponto de origem,
    // de forma que o centro da matriz (índices 1,2 para uma matriz 3x5) fique nesse ponto.
    int centroHabilidadeLinha = ALTURA_HABILIDADE / 2;   // 3/2 = 1
    int centroHabilidadeColuna = LARGURA_HABILIDADE / 2;   // 5/2 = 2
    
    // Define os pontos de origem para cada habilidade no tabuleiro
    int origemConeLinha = 4,    origemConeColuna = 4;
    int origemCruzLinha = 7,    origemCruzColuna = 2;
    int origemOctaedroLinha = 2, origemOctaedroColuna = 8;
    
    // Função de sobreposição:
    // Se a célula da matriz de habilidade for 1 e a posição correspondente no tabuleiro contiver água (0),
    // marca essa posição com 5 (área afetada pela habilidade).
    
    // Sobrepõe a habilidade Cone
    for (int i = 0; i < ALTURA_HABILIDADE; i++) {
        for (int j = 0; j < LARGURA_HABILIDADE; j++) {
            if (habilidadeCone[i][j] == 1) {
                int posLinha = origemConeLinha - centroHabilidadeLinha + i;
                int posColuna = origemConeColuna - centroHabilidadeColuna + j;
                if (posLinha >= 0 && posLinha < TAMANHO_TABULEIRO &&
                    posColuna >= 0 && posColuna < TAMANHO_TABULEIRO) {
                    if (tabuleiro[posLinha][posColuna] == 0)
                        tabuleiro[posLinha][posColuna] = 5;
                }
            }
        }
    }
    
    // Sobrepõe a habilidade Cruz
    for (int i = 0; i < ALTURA_HABILIDADE; i++) {
        for (int j = 0; j < LARGURA_HABILIDADE; j++) {
            if (habilidadeCruz[i][j] == 1) {
                int posLinha = origemCruzLinha - centroHabilidadeLinha + i;
                int posColuna = origemCruzColuna - centroHabilidadeColuna + j;
                if (posLinha >= 0 && posLinha < TAMANHO_TABULEIRO &&
                    posColuna >= 0 && posColuna < TAMANHO_TABULEIRO) {
                    if (tabuleiro[posLinha][posColuna] == 0)
                        tabuleiro[posLinha][posColuna] = 5;
                }
            }
        }
    }
    
    // Sobrepõe a habilidade Octaedro
    for (int i = 0; i < ALTURA_HABILIDADE; i++) {
        for (int j = 0; j < LARGURA_HABILIDADE; j++) {
            if (habilidadeOctaedro[i][j] == 1) {
                int posLinha = origemOctaedroLinha - centroHabilidadeLinha + i;
                int posColuna = origemOctaedroColuna - centroHabilidadeColuna + j;
                if (posLinha >= 0 && posLinha < TAMANHO_TABULEIRO &&
                    posColuna >= 0 && posColuna < TAMANHO_TABULEIRO) {
                    if (tabuleiro[posLinha][posColuna] == 0)
                        tabuleiro[posLinha][posColuna] = 5;
                }
            }
        }
    }
    
    // ---------------------------
    // Exibição Final do Tabuleiro
    // ---------------------------
    // Legenda:
    //   0 -> Água
    //   3 -> Navio
    //   5 -> Área afetada pela habilidade
    printf("Tabuleiro com Navios e Habilidades:\n");
    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
    
    return 0;
}
