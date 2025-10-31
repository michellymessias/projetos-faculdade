#include <stdio.h>

// Definição de constantes para melhor legibilidade
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Percorre todas as linhas do tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        // Percorre todas as colunas do tabuleiro
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA; // Inicializa com água
        }
    }
}

// Função para validar se as coordenadas estão dentro dos limites do tabuleiro
int validarCoordenadas(int linha, int coluna, int tamanho, char orientacao) {
    // Verifica se a posição inicial está dentro do tabuleiro
    if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO) {
        return 0; // Coordenadas inválidas
    }
    
    // Verifica se o navio cabe no tabuleiro de acordo com a orientação
    if (orientacao == 'H' || orientacao == 'h') {
        // Navio horizontal: verifica se cabe na horizontal
        if (coluna + tamanho > TAMANHO_TABULEIRO) {
            return 0; // Navio ultrapassa o limite horizontal
        }
    } else if (orientacao == 'V' || orientacao == 'v') {
        // Navio vertical: verifica se cabe na vertical
        if (linha + tamanho > TAMANHO_TABULEIRO) {
            return 0; // Navio ultrapassa o limite vertical
        }
    } else {
        return 0; // Orientação inválida
    }
    
    return 1; // Coordenadas válidas
}

// Função para verificar se há sobreposição com outro navio
int verificarSobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                          int linha, int coluna, int tamanho, char orientacao) {
    // Verifica cada posição que o navio irá ocupar
    for (int i = 0; i < tamanho; i++) {
        if (orientacao == 'H' || orientacao == 'h') {
            // Verifica posições horizontais
            if (tabuleiro[linha][coluna + i] != AGUA) {
                return 1; // Há sobreposição
            }
        } else {
            // Verifica posições verticais
            if (tabuleiro[linha + i][coluna] != AGUA) {
                return 1; // Há sobreposição
            }
        }
    }
    
    return 0; // Não há sobreposição
}

// Função para posicionar um navio no tabuleiro
int posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                    int navio[TAMANHO_NAVIO], int linha, int coluna, char orientacao) {
    // Valida as coordenadas
    if (!validarCoordenadas(linha, coluna, TAMANHO_NAVIO, orientacao)) {
        printf("Erro: Coordenadas inválidas ou navio fora dos limites do tabuleiro!\n");
        return 0;
    }
    
    // Verifica sobreposição
    if (verificarSobreposicao(tabuleiro, linha, coluna, TAMANHO_NAVIO, orientacao)) {
        printf("Erro: O navio sobrepõe outro navio já posicionado!\n");
        return 0;
    }
    
    // Posiciona o navio no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (orientacao == 'H' || orientacao == 'h') {
            // Posiciona horizontalmente
            tabuleiro[linha][coluna + i] = navio[i];
        } else {
            // Posiciona verticalmente
            tabuleiro[linha + i][coluna] = navio[i];
        }
    }
    
    return 1; // Navio posicionado com sucesso
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    
    // Exibe o cabeçalho com números das colunas
    printf("   ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf(" %d ", i);
    }
    printf("\n");
    
    // Exibe linha separadora
    printf("  ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("---");
    }
    printf("\n");
    
    // Exibe cada linha do tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d |", i); // Número da linha
        
        // Exibe cada coluna da linha atual
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    printf("\nLegenda: 0 = Água | 3 = Navio\n\n");
}

int main() {
    // Declaração da matriz que representa o tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Declaração dos vetores que representam os navios
    // Cada posição do navio tem valor 3
    int navio1[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navio2[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    
    // Coordenadas e orientação dos navios
    // Navio 1: Horizontal, começa na posição (2, 3)
    int navio1_linha = 2;
    int navio1_coluna = 3;
    char navio1_orientacao = 'H'; // H = Horizontal
    
    // Navio 2: Vertical, começa na posição (5, 7)
    int navio2_linha = 5;
    int navio2_coluna = 7;
    char navio2_orientacao = 'V'; // V = Vertical
    
    printf("=== JOGO DE BATALHA NAVAL ===\n");
    printf("Inicializando o tabuleiro...\n\n");
    
    // Passo 1: Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);
    
    // Passo 2: Posiciona o primeiro navio (horizontal)
    printf("Posicionando Navio 1 (Horizontal)...\n");
    printf("Posição: Linha %d, Coluna %d\n", navio1_linha, navio1_coluna);
    
    if (posicionarNavio(tabuleiro, navio1, navio1_linha, navio1_coluna, navio1_orientacao)) {
        printf("Navio 1 posicionado com sucesso!\n\n");
    } else {
        printf("Falha ao posicionar Navio 1!\n\n");
        return 1;
    }
    
    // Passo 3: Posiciona o segundo navio (vertical)
    printf("Posicionando Navio 2 (Vertical)...\n");
    printf("Posição: Linha %d, Coluna %d\n", navio2_linha, navio2_coluna);
    
    if (posicionarNavio(tabuleiro, navio2, navio2_linha, navio2_coluna, navio2_orientacao)) {
        printf("Navio 2 posicionado com sucesso!\n\n");
    } else {
        printf("Falha ao posicionar Navio 2!\n\n");
        return 1;
    }
    
    // Passo 4: Exibe o tabuleiro final com os navios posicionados
    exibirTabuleiro(tabuleiro);
    
    printf("Programa finalizado com sucesso!\n");
    
    return 0;
}