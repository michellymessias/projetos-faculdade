#include <stdio.h>

// ========== PROTÓTIPOS DAS FUNÇÕES RECURSIVAS ==========
void mover_torre_recursivo(int casas_restantes);
void mover_bispo_recursivo(int casas_restantes);
void mover_rainha_recursivo(int casas_restantes);

// ========== FUNÇÃO RECURSIVA: TORRE ==========
// Move a Torre para a direita usando recursão
// Parâmetro: casas_restantes - número de casas que ainda faltam mover
void mover_torre_recursivo(int casas_restantes) {
    // Caso base: se não há mais casas para mover, encerra a recursão
    if (casas_restantes == 0) {
        return;
    }
    
    // Imprime o movimento para a direita
    printf("Direita\n");
    
    // Chamada recursiva: move mais uma casa (reduz em 1 o contador)
    mover_torre_recursivo(casas_restantes - 1);
}

// ========== FUNÇÃO RECURSIVA: BISPO ==========
// Move o Bispo na diagonal (cima e direita) usando recursão
// Parâmetro: casas_restantes - número de casas que ainda faltam mover
void mover_bispo_recursivo(int casas_restantes) {
    // Caso base: se não há mais casas para mover, encerra a recursão
    if (casas_restantes == 0) {
        return;
    }
    
    // Imprime o movimento diagonal (cima e direita simultaneamente)
    printf("Cima\n");
    printf("Direita\n");
    
    // Chamada recursiva: move mais uma casa diagonal
    mover_bispo_recursivo(casas_restantes - 1);
}

// ========== FUNÇÃO RECURSIVA: RAINHA ==========
// Move a Rainha para a esquerda usando recursão
// Parâmetro: casas_restantes - número de casas que ainda faltam mover
void mover_rainha_recursivo(int casas_restantes) {
    // Caso base: se não há mais casas para mover, encerra a recursão
    if (casas_restantes == 0) {
        return;
    }
    
    // Imprime o movimento para a esquerda
    printf("Esquerda\n");
    
    // Chamada recursiva: move mais uma casa
    mover_rainha_recursivo(casas_restantes - 1);
}

// ========== FUNÇÃO PRINCIPAL ==========
int main() {
    // Declaração de constantes para número de movimentos
    int casas_torre = 5;      // Torre move 5 casas
    int casas_bispo = 5;      // Bispo move 5 casas na diagonal
    int casas_rainha = 8;     // Rainha move 8 casas
    
    // Variáveis para loops aninhados
    int i, j;                 // Contadores para loops aninhados
    
    
    // ========== MOVIMENTO DA TORRE (RECURSIVO) ==========
    printf("=== Movimento da Torre (Recursivo) ===\n");
    printf("Movendo 5 casas para a direita:\n");
    
    // Chama a função recursiva que move a Torre
    mover_torre_recursivo(casas_torre);
    
    printf("\n"); // Separação visual
    
    
    // ========== MOVIMENTO DO BISPO (RECURSIVO) ==========
    printf("=== Movimento do Bispo (Recursivo) ===\n");
    printf("Movendo 5 casas na diagonal (cima e direita):\n");
    
    // Chama a função recursiva que move o Bispo
    mover_bispo_recursivo(casas_bispo);
    
    printf("\n"); // Separação visual
    
    
    // ========== MOVIMENTO DO BISPO (LOOPS ANINHADOS) ==========
    printf("=== Movimento do Bispo (Loops Aninhados) ===\n");
    printf("Movendo 5 casas na diagonal usando loops aninhados:\n");
    
    // Loop externo: controla o movimento VERTICAL (cima)
    for (i = 0; i < casas_bispo; i++) {
        printf("Cima\n");
        
        // Loop interno: controla o movimento HORIZONTAL (direita)
        // Para cada movimento vertical, há um movimento horizontal
        for (j = 0; j < 1; j++) {
            printf("Direita\n");
        }
    }
    
    printf("\n"); // Separação visual
    
    
    // ========== MOVIMENTO DA RAINHA (RECURSIVO) ==========
    printf("=== Movimento da Rainha (Recursivo) ===\n");
    printf("Movendo 8 casas para a esquerda:\n");
    
    // Chama a função recursiva que move a Rainha
    mover_rainha_recursivo(casas_rainha);
    
    printf("\n"); // Separação visual
    
    
    // ========== MOVIMENTO DO CAVALO (LOOPS COMPLEXOS) ==========
    printf("=== Movimento do Cavalo (Loops Complexos) ===\n");
    printf("Movimento em 'L': 2 casas para cima e 1 para direita\n");
    
    // Variáveis de controle para o movimento do Cavalo
    int movimentos_completos = 0;  // Contador de movimentos em L completos
    int max_movimentos = 3;        // Número de movimentos em L que o Cavalo fará
    
    // Loop externo: controla quantos movimentos em "L" serão feitos
    for (i = 0; i < max_movimentos; i++) {
        
        // Loop interno: simula as 2 casas para CIMA
        for (j = 0; j < 2; j++) {
            printf("Cima\n");
            
            // Verifica se já completou a parte vertical do movimento
            if (j == 1) {
                // Após mover 2 casas para cima, move 1 para a direita
                printf("Direita\n");
                movimentos_completos++;
            }
        }
        
        // Adiciona separação visual entre os movimentos em L
        if (i < max_movimentos - 1) {
            printf("\n");
        }
        
        // Condição de controle: se já fez 3 movimentos completos, interrompe
        if (movimentos_completos >= max_movimentos) {
            break; // Uso de break para controle preciso do fluxo
        }
    }
    
    printf("\n"); // Separação visual final
    
    
    // ========== FINALIZAÇÃO ==========
    printf("=== Simulacao de movimentos complexos concluida! ===\n");
    
    return 0; // Retorna 0 indicando execução bem-sucedida
}