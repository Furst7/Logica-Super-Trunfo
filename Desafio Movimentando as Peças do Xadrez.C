#include <stdio.h>

// Função para imprimir o tabuleiro com marcação dos movimentos
void imprimirTabuleiro(int tabuleiro[8][8]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (tabuleiro[i][j] == 1)
                printf(" x ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}

// Torre - movimentos em linha reta (for)
void movimentoTorre(int linha, int coluna, int tabuleiro[8][8]) {
    for (int i = 0; i < 8; i++) {
        if (i != linha) tabuleiro[i][coluna] = 1;
        if (i != coluna) tabuleiro[linha][i] = 1;
    }
}

// Bispo - movimentos diagonais (while)
void movimentoBispo(int linha, int coluna, int tabuleiro[8][8]) {
    int i, j;

    // Diagonal superior esquerda
    i = linha - 1; j = coluna - 1;
    while (i >= 0 && j >= 0) tabuleiro[i--][j--] = 1;

    // Diagonal superior direita
    i = linha - 1; j = coluna + 1;
    while (i >= 0 && j < 8) tabuleiro[i--][j++] = 1;

    // Diagonal inferior esquerda
    i = linha + 1; j = coluna - 1;
    while (i < 8 && j >= 0) tabuleiro[i++][j--] = 1;

    // Diagonal inferior direita
    i = linha + 1; j = coluna + 1;
    while (i < 8 && j < 8) tabuleiro[i++][j++] = 1;
}

// Rainha - combinação de torre e bispo
void movimentoRainha(int linha, int coluna, int tabuleiro[8][8]) {
    movimentoTorre(linha, coluna, tabuleiro);
    movimentoBispo(linha, coluna, tabuleiro);
}

// Cavalo - movimento em "L" com loops aninhados
void movimentoCavalo(int linha, int coluna, int tabuleiro[8][8]) {
    int movimentos[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < 8; i++) {
        int novaLinha = linha + movimentos[i][0];
        int novaColuna = coluna + movimentos[i][1];

        if (novaLinha >= 0 && novaLinha < 8 && novaColuna >= 0 && novaColuna < 8)
            tabuleiro[novaLinha][novaColuna] = 1;
    }
}

// Bispo com recursividade
void movimentoBispoRecursivo(int linha, int coluna, int dirLinha, int dirColuna, int tabuleiro[8][8]) {
    int novaLinha = linha + dirLinha;
    int novaColuna = coluna + dirColuna;

    if (novaLinha >= 0 && novaLinha < 8 && novaColuna >= 0 && novaColuna < 8) {
        tabuleiro[novaLinha][novaColuna] = 1;
        movimentoBispoRecursivo(novaLinha, novaColuna, dirLinha, dirColuna, tabuleiro);
    }
}

void movimentoBispoAvancado(int linha, int coluna, int tabuleiro[8][8]) {
    movimentoBispoRecursivo(linha, coluna, 1, 1, tabuleiro);
    movimentoBispoRecursivo(linha, coluna, -1, -1, tabuleiro);
    movimentoBispoRecursivo(linha, coluna, -1, 1, tabuleiro);
    movimentoBispoRecursivo(linha, coluna, 1, -1, tabuleiro);
}

// Menu principal
int main() {
    int tabuleiro[8][8] = {0};
    int linha, coluna, escolha;

    printf("Digite a posição da peça (linha e coluna de 0 a 7):\n");
    scanf("%d %d", &linha, &coluna);

    printf("\nEscolha a peça:\n");
    printf("1 - Torre\n");
    printf("2 - Bispo\n");
    printf("3 - Rainha\n");
    printf("4 - Cavalo\n");
    printf("5 - Bispo (Recursivo)\n");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1: movimentoTorre(linha, coluna, tabuleiro); break;
        case 2: movimentoBispo(linha, coluna, tabuleiro); break;
        case 3: movimentoRainha(linha, coluna, tabuleiro); break;
        case 4: movimentoCavalo(linha, coluna, tabuleiro); break;
        case 5: movimentoBispoAvancado(linha, coluna, tabuleiro); break;
        default: printf("Opção inválida.\n"); return 1;
    }

    tabuleiro[linha][coluna] = 9; // Marca a posição da peça
    imprimirTabuleiro(tabuleiro);

    return 0;
}
``