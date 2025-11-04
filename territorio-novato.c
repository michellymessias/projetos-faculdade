#include <stdio.h>
#include <string.h>

// Definição da estrutura Territorio
// Armazena informações essenciais de cada território do jogo
typedef struct {
    char nome[30];    // Nome do território (até 29 caracteres)
    char cor[10];     // Cor do exército (até 9 caracteres)
    int tropas;       // Quantidade de tropas no território
} Territorio;

// Constante para número de territórios
#define NUM_TERRITORIOS 5

// Função para limpar o buffer de entrada
// Evita problemas com caracteres residuais no buffer
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para cadastrar um território
// Recebe os dados do usuário e preenche a estrutura
void cadastrarTerritorio(Territorio *t, int numero) {
    printf("\n=== CADASTRO DO TERRITORIO %d ===\n", numero);
    
    // Entrada do nome do território
    printf("Nome do territorio: ");
    fgets(t->nome, sizeof(t->nome), stdin);
    // Remove o caractere de nova linha do final da string
    t->nome[strcspn(t->nome, "\n")] = '\0';
    
    // Entrada da cor do exército
    printf("Cor do exercito: ");
    fgets(t->cor, sizeof(t->cor), stdin);
    t->cor[strcspn(t->cor, "\n")] = '\0';
    
    // Entrada da quantidade de tropas
    printf("Quantidade de tropas: ");
    while (scanf("%d", &t->tropas) != 1 || t->tropas < 0) {
        printf("Valor invalido! Digite um numero inteiro positivo: ");
        limparBuffer();
    }
    limparBuffer(); // Limpa o buffer após scanf
}

// Função para exibir os dados de um território
// Mostra as informações de forma formatada
void exibirTerritorio(Territorio t, int numero) {
    printf("\n--- Territorio %d ---\n", numero);
    printf("Nome: %s\n", t.nome);
    printf("Cor do Exercito: %s\n", t.cor);
    printf("Tropas: %d\n", t.tropas);
}

// Função principal
int main() {
    // Declaração do vetor de estruturas
    // Armazena os dados de todos os territórios
    Territorio territorios[NUM_TERRITORIOS];
    
    printf("====================================\n");
    printf("  SISTEMA DE CADASTRO DE TERRITORIOS\n");
    printf("====================================\n");
    printf("\nVoce ira cadastrar %d territorios.\n", NUM_TERRITORIOS);
    
    // Laço para cadastrar todos os territórios
    // Percorre o vetor preenchendo cada posição
    for (int i = 0; i < NUM_TERRITORIOS; i++) {
        cadastrarTerritorio(&territorios[i], i + 1);
    }
    
    // Exibição dos dados cadastrados
    printf("\n\n====================================\n");
    printf("  TERRITORIOS CADASTRADOS\n");
    printf("====================================\n");
    
    // Laço para exibir todos os territórios
    // Percorre o vetor mostrando os dados de cada território
    for (int i = 0; i < NUM_TERRITORIOS; i++) {
        exibirTerritorio(territorios[i], i + 1);
    }
    
    printf("\n====================================\n");
    printf("Cadastro concluido com sucesso!\n");
    printf("====================================\n");
    
    return 0;
}