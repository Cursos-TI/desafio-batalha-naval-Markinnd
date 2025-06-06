

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
 
/*Comentando o Desafio Novato    
#include <stdio.h>
// usando #define para facilitar
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    

// 1. Representar o Tabuleiro:
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializar o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2. Posicionar os Navios:

    // Navio Horizontal
    // Coordenadas iniciais: linha 2, coluna 3
    // Ocupará as posições (2,3), (2,4), (2,5)
    int linha_navio_h = 2;
    int coluna_navio_h = 3;

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_navio_h][coluna_navio_h + i] = NAVIO;
    }

    // Navio Vertical
    // Coordenadas iniciais: linha 5, coluna 1
    // Ocupará as posições (5,1), (6,1), (7,1)
    int linha_navio_v = 5;
    int coluna_navio_v = 1;

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_navio_v + i][coluna_navio_v] = NAVIO;
    }

    // 3. Exibir o Tabuleiro:
    printf("Tabuleiro de Batalha Naval:\n");
    printf("---------------------------\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); // Nova linha após cada linha do tabuleiro
    }
    printf("---------------------------\n");
return 0;
*/
 
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

#include <stdio.h>
#include <stdbool.h> // Para usar o tipo bool

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3 // Tamanho fixo para todos os navios neste exemplo
#define AGUA 0
#define NAVIO 3

// Função para verificar se uma posição está dentro dos limites do tabuleiro
bool ehPosicaoValida(int linha, int coluna) {
    return (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO);
}

// Função para tentar posicionar um navio e verificar sobreposição
bool posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha_inicial, int coluna_inicial, int orientacao) {
    // orientacao: 0 = horizontal, 1 = vertical, 2 = diagonal crescente, 3 = diagonal decrescente

    // Array para armazenar as posições que o navio irá ocupar
    int posicoes[TAMANHO_NAVIO][2]; // [0]=linha, [1]=coluna

    // Calcular as posições que o navio ocuparia
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        switch (orientacao) {
            case 0: // Horizontal
                posicoes[i][0] = linha_inicial;
                posicoes[i][1] = coluna_inicial + i;
                break;
            case 1: // Vertical
                posicoes[i][0] = linha_inicial + i;
                posicoes[i][1] = coluna_inicial;
                break;
            case 2: // Diagonal crescente (linha e coluna aumentam)
                posicoes[i][0] = linha_inicial + i;
                posicoes[i][1] = coluna_inicial + i;
                break;
            case 3: // Diagonal decrescente (linha aumenta, coluna diminui)
                posicoes[i][0] = linha_inicial + i;
                posicoes[i][1] = coluna_inicial - i;
                break;
            default:
                return false; // Orientação inválida
        }

        // Verificar se a posição está dentro dos limites do tabuleiro
        if (!ehPosicaoValida(posicoes[i][0], posicoes[i][1])) {
            return false; // Navio fora do tabuleiro
        }

        // Verificar sobreposição (se a posição já está ocupada por outro navio)
        if (tabuleiro[posicoes[i][0]][posicoes[i][1]] == NAVIO) {
            return false; // Sobreposição detectada
        }
    }

    // Se todas as posições são válidas e não há sobreposição, posicionar o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[posicoes[i][0]][posicoes[i][1]] = NAVIO;
    }
    return true; // Navio posicionado com sucesso
}


int main() {
    // 1. Criar um Tabuleiro 10x10:
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializar o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2. Posicionar Quatro Navios:
    // Tentar posicionar os navios. Se uma posição falhar, tente outras coordenadas.
    // Para simplificar, neste exemplo, as coordenadas são fixas e esperamos que sejam válidas.
    // Em um jogo real, você teria loops ou lógica para tentar novas posições até encontrar uma válida.

    // Navio 1: Horizontal
    if (!posicionarNavio(tabuleiro, 1, 1, 0)) {
        printf("Erro ao posicionar Navio 1 (Horizontal) ou sobreposicao.\n");
    }

    // Navio 2: Vertical
    if (!posicionarNavio(tabuleiro, 6, 8, 1)) {
        printf("Erro ao posicionar Navio 2 (Vertical) ou sobreposicao.\n");
    }

    // Navio 3: Diagonal Crescente (linha e coluna aumentam)
    // Ex: (0,0), (1,1), (2,2)
    if (!posicionarNavio(tabuleiro, 5, 0, 2)) {
        printf("Erro ao posicionar Navio 3 (Diagonal Crescente) ou sobreposicao.\n");
    }

    // Navio 4: Diagonal Decrescente (linha aumenta, coluna diminui)
    // Ex: (0,9), (1,8), (2,7)
    // Coordenada inicial (linha, coluna) onde o navio "começa"
    // Para um navio diagonal decrescente, a coluna inicial deve ser maior ou igual ao tamanho do navio-1
    if (!posicionarNavio(tabuleiro, 4, 8, 3)) { // Começa em (4,8), ocupará (4,8), (5,7), (6,6)
        printf("Erro ao posicionar Navio 4 (Diagonal Decrescente) ou sobreposicao.\n");
    }


    // 3. Exibir o Tabuleiro:
    printf("\nTabuleiro de Batalha Naval com 4 Navios (H, V, D+ e D-):\n");
    printf("------------------------------------------------------\n");

    // Imprimir cabeçalho das colunas
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i); // Imprimir número da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n"); // Nova linha após cada linha do tabuleiro
    }
    printf("------------------------------------------------------\n");

    return 0;
}

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    

