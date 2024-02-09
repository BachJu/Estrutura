#include <stdio.h>
#include <stdlib.h>

typedef struct TAtleta {
    int codigo;
    char nome[50];
    int qntdVoltas;
    float *tempos;
    float tempoTotal;
    float tempoMedio;
} TAtleta;

int main(int argc, char const *argv[]) {
    TAtleta *lista;
    int qntAtletas, i, k;

    int maiorVolta = 0;
    float maisRapido = 999999; // Inicialize com um valor grande

    int vencedor = 0;
    int contVoltasAbaixo = 0;

    printf("Digite quantos atletas participaram da corrida: ");
    scanf("%d", &qntAtletas);

    lista = (TAtleta *)malloc(sizeof(TAtleta) * qntAtletas);

    for (i = 0; i < qntAtletas; i++) {
        lista[i].tempoTotal = 0;

        printf("Digite o codigo do atleta: ");
        scanf("%d", &lista[i].codigo);

        printf("Digite o nome do atleta: ");
        scanf("%s", lista[i].nome);

        printf("Digite a quantidade de voltas: ");
        scanf("%d", &lista[i].qntdVoltas);

        if (lista[i].qntdVoltas > maiorVolta) {
            maiorVolta = lista[i].qntdVoltas;
        }

        lista[i].tempos = (float *)malloc(sizeof(float) * lista[i].qntdVoltas);

        for (k = 0; k < lista[i].qntdVoltas; k++) {
            printf("Digite o tempo da %d volta: ", k + 1);
            scanf("%f", &lista[i].tempos[k]);
            lista[i].tempoTotal += lista[i].tempos[k];

            if (lista[i].tempos[k] < maisRapido) {
                maisRapido = lista[i].tempos[k];
            }
        }

        lista[i].tempoMedio = lista[i].tempoTotal / lista[i].qntdVoltas;
    }

    // Encontrando o vencedor
    for (i = 0; i < qntAtletas; i++) {
        if (lista[i].qntdVoltas == maiorVolta) {
            if (lista[i].tempoMedio < lista[vencedor].tempoMedio) {
                vencedor = i;
            }
        }
    }

    // Contagem de voltas abaixo da média do vencedor
    for (i = 0; i < qntAtletas; i++) {
        for (k = 0; k < lista[i].qntdVoltas; k++) {
            if (lista[i].tempos[k] < lista[vencedor].tempoMedio) {
                contVoltasAbaixo++;
            }
        }
    }

    printf("\nO vencedor é %s\n", lista[vencedor].nome);
    printf("A volta mais rapida foi %.2f\n", maisRapido);
    printf("O tempo medio dos corredores foi \n");
    for (i = 0; i < qntAtletas; i++) {
        printf("%.2f\n", lista[i].tempoMedio);
    }
    printf("%d voltas ficaram abaixo do tempo médio do vencedor\n", contVoltasAbaixo);

    // Liberando a memória alocada
    for (i = 0; i < qntAtletas; i++) {
        free(lista[i].tempos);
    }
    free(lista);

    return 0;
}