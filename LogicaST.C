#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Carta {
    char nome[20];
    int forca;
    int velocidade;
    int inteligencia;
};

int main() {
    srand(time(NULL));

    struct Carta cartas[3] = {
        {"Dragao", 90, 60, 40},
        {"Robo", 70, 80, 90},
        {"Mago", 50, 40, 100}
    };

    int indiceJogador1 = rand() % 3;
    int indiceJogador2 = rand() % 3;

    struct Carta jogador1 = cartas[indiceJogador1];
    struct Carta jogador2 = cartas[indiceJogador2];

    printf("Sua carta:\n");
    printf("Nome: %s\n", jogador1.nome);
    printf("1. Forca: %d\n", jogador1.forca);
    printf("2. Velocidade: %d\n", jogador1.velocidade);
    printf("3. Inteligencia: %d\n", jogador1.inteligencia);

    int escolha;
    printf("Escolha um atributo para competir (1-Forca, 2-Velocidade, 3-Inteligencia): ");
    scanf("%d", &escolha);

    int valor1, valor2;
    if (escolha == 1) {
        valor1 = jogador1.forca;
        valor2 = jogador2.forca;
    } else if (escolha == 2) {
        valor1 = jogador1.velocidade;
        valor2 = jogador2.velocidade;
    } else if (escolha == 3) {
        valor1 = jogador1.inteligencia;
        valor2 = jogador2.inteligencia;
    } else {
        printf("Escolha invalida!\n");
        return 1;
    }

    printf("\nCarta do adversario:\n");
    printf("Nome: %s\n", jogador2.nome);
    printf("Forca: %d\n", jogador2.forca);
    printf("Velocidade: %d\n", jogador2.velocidade);
    printf("Inteligencia: %d\n", jogador2.inteligencia);

    if (valor1 > valor2) {
        printf("\nVoce venceu!\n");
    } else if (valor1 < valor2) {
        printf("\nVoce perdeu!\n");
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}