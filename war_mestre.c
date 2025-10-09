#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct de território
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Vetor de missões
const char* missoes[] = {
    "Conquistar 3 territorios seguidos",
    "Eliminar todas as tropas da cor vermelha",
    "Controlar 5 territorios ao final do turno",
    "Ter mais de 20 tropas em um unico territorio",
    "Conquistar todos os territorios da cor azul"
};
int totalMissoes = sizeof(missoes) / sizeof(missoes[0]);

// Função para atribuir missão ao jogador
void atribuirMissao(char* destino, const char* missoes[], int totalMissoes) {
    int sorteio = rand() % totalMissoes;
    strcpy(destino, missoes[sorteio]);
}

// Função para verificar se a missão foi cumprida
int verificarMissao(char* missao, Territorio* mapa, int tamanho) {
    if (strcmp(missao, "Ter mais de 20 tropas em um unico territorio") == 0) {
        for (int i = 0; i < tamanho; i++) {
            if (mapa[i].tropas > 20) return 1;
        }
    }

    if (strcmp(missao, "Eliminar todas as tropas da cor vermelha") == 0) {
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, "vermelha") == 0 && mapa[i].tropas > 0) return 0;
        }
        return 1;
    }

    if (strcmp(missao, "Controlar 5 territorios ao final do turno") == 0) {
        int contador = 0;
        for (int i = 0; i < tamanho; i++) {
            if (mapa[i].tropas > 0) contador++;
        }
        if (contador >= 5) return 1;
    }

    return 0;
}

// Função de ataque
void atacar(Territorio* atacante, Territorio* defensor) {
    if (strcmp(atacante->cor, defensor->cor) == 0) {
        printf("\nErro: não pode atacar território da mesma cor!\n");
        return;
    }

    int dado_atacante = (rand() % 6) + 1;
    int dado_defensor = (rand() % 6) + 1;

    printf("\n%s (%s) atacou %s (%s)\n", atacante->nome, atacante->cor, defensor->nome, defensor->cor);
    printf("Dado atacante: %d | Dado defensor: %d\n", dado_atacante, dado_defensor);

    if (dado_atacante > dado_defensor) {
        int metade = atacante->tropas / 2;
        defensor->tropas = metade;
        atacante->tropas = metade;
        strcpy(defensor->cor, atacante->cor);
        printf("Vitória! %s agora pertence à cor %s com %d tropas.\n", defensor->nome, defensor->cor, defensor->tropas);
    } else {
        atacante->tropas -= 1;
        printf("Derrota! %s perdeu 1 tropa e agora tem %d.\n", atacante->nome, atacante->tropas);
    }
}

// Exibir territórios
void exibirTerritorios(Territorio* mapa, int num) {
    printf("\n--- Territórios ---\n");
    for (int i = 0; i < num; i++) {
        printf("[%d] %s | Cor: %s | Tropas: %d\n", i, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

// Liberar memória
void liberarMemoria(Territorio* mapa, char* missao) {
    free(mapa);
    free(missao);
}

int main() {
    srand(time(NULL));
    int num;

    printf("Quantos territórios deseja cadastrar? ");
    scanf("%d", &num);

    Territorio* mapa = (Territorio*) calloc(num, sizeof(Territorio));
    if (!mapa) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Cadastro dos territórios
    for (int i = 0; i < num; i++) {
        printf("\nCadastro do território %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", mapa[i].nome);
        printf("Cor: ");
        scanf("%s", mapa[i].cor);
        printf("Tropas: ");
        scanf("%d", &mapa[i].tropas);
    }

    // Sorteio da missão
    char* missaoJogador = (char*) malloc(100 * sizeof(char));
    atribuirMissao(missaoJogador, missoes, totalMissoes);
    printf("\nSua missão: %s\n", missaoJogador);

    // Loop de turnos
    char continuar = 's';
    while (continuar == 's') {
        exibirTerritorios(mapa, num);

        int i_atacante, i_defensor;
        printf("\nEscolha o índice do território atacante: ");
        scanf("%d", &i_atacante);
        printf("Escolha o índice do território defensor: ");
        scanf("%d", &i_defensor);

        if (i_atacante >= 0 && i_atacante < num && i_defensor >= 0 && i_defensor < num) {
            atacar(&mapa[i_atacante], &mapa[i_defensor]);
        } else {
            printf("Índices inválidos!\n");
        }

        // Verificação de missão
        if (verificarMissao(missaoJogador, mapa, num)) {
            printf("\n🎉 Missão cumprida: %s\n", missaoJogador);
            printf("🏆 Você venceu o jogo!\n");
            break;
        }

        printf("\nDeseja continuar o jogo? (s/n): ");
        scanf(" %c", &continuar);
    }

    liberarMemoria(mapa, missaoJogador);
    return 0;
}