// |Friends
/*
* Daniel Monteiro Ribeiro
* RA: 176231
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Estrutura do nó (amigo da lista)
typedef struct cel{
  char amigo_nome[20];
  struct cel *prox;
} amigo;

// Verifica se a alocação foi bem-sucedida
int verificar_erro_alocacao(amigo *p) {
  if (p == NULL) {
    printf("Erro ao alocar memória\n");
    return 1;
  } else return 0;
}

// Remover o '\n' do final de input, caso exista
void remover_nova_linha(char input[]) {
  if (input[strlen(input) - 1] == '\n') {
    input[strlen(input) - 1] = '\0';
  }
}

void liberar_lista(amigo *head) {
  amigo *p = head;
  amigo *aux;

  while (p != NULL) {
    aux = p->prox; // Armazena o próximo nó
    free(p);       // Libera o nó atual
    p = aux;       // Avança para o próximo nó
  }
}

void insere_amigo(char nome[], amigo *p) {
  amigo *novo;
  novo = (amigo *)malloc(sizeof(amigo));
  if (verificar_erro_alocacao(novo)) exit(1);
  strcpy(novo->amigo_nome, nome);   // Copia a string 'nome' para o conteúdo do novo amigo
  novo->prox = p->prox;             
  p->prox = novo;                   // Insere novo amigo na lista após o amigo 'p'
}

amigo *busca_amigo_indicado(char nome[], amigo *head) {
  amigo *p;
  p = head;
  // Busca o amigo anterior ao amigo indicado
  while (p!=NULL && p->prox!=NULL && strcmp(p->prox->amigo_nome, nome)) {
    p = p->prox;
  }
  // Retorna o amigo anterior ao indicado para inserir indicação de amigos
  return (p != NULL && p->prox != NULL) ? p : NULL;
}

amigo *busca_fim_lista(amigo *head) {
  amigo *p;
  p = head;
  while (p->prox!=NULL) {
    p = p->prox;
  }
  return p; 
}

void print_lista(amigo *head) {
  amigo *p;
  // Imprime todos os nomes da lista
  for (p = head->prox; p != NULL; p = p->prox) {
    if (p->prox!=NULL) {
      printf("%s ", p->amigo_nome);
    } else {
      printf("%s", p->amigo_nome);
    }
  }
  printf("\n");  // Adiciona uma nova linha ao final
}

int main() {
  char input[1000], *nome, amigo_indicado[20];
  amigo *pp_amigo_indicado, *fim_lista;

  // Inicializa a cabeça da lista
  amigo *head;
  head = (amigo *)malloc(sizeof(amigo));
  if (verificar_erro_alocacao(head)) exit(1); 
  head->prox = NULL; 

  // Lê a primeira linha de nomes separada por espaços
  fgets(input, sizeof(input), stdin);
  remover_nova_linha(input); // Remove \n para comparação

  // Atribui o primeiro nome separado por espaço a 'nome'
  nome = strtok(input, " ");

  // Insere na lista cada nome de input[]
  amigo *p = head;
  while (nome != NULL) {
    insere_amigo(nome, p);
    p = p->prox;
    nome = strtok(NULL, " ");
  }

  // Lê a segunda linha de nomes separda por espaço
  fgets(input, sizeof(input), stdin);
  remover_nova_linha(input); // Remove \n para comparação
  
  // Atribui o primeiro nome separado por espaço a 'nome'
  nome = strtok(input, " ");

  // Lê o amigo ao qual a lista será indicada
  fgets(amigo_indicado, sizeof(amigo_indicado), stdin);
  remover_nova_linha(amigo_indicado); // Remove \n para comparação

  if (!strcmp("nao", amigo_indicado)) {
    fim_lista = busca_fim_lista(head);
    while (nome != NULL) {
      insere_amigo(nome, fim_lista);
      fim_lista = fim_lista->prox;
      nome = strtok(NULL, " ");
    }
  } else {
    // Encontra e guarda o endereço na lista do amigo anterior ao indicado
    pp_amigo_indicado = busca_amigo_indicado(amigo_indicado, head);
    if (pp_amigo_indicado!=NULL){
      while (nome != NULL) {
        insere_amigo(nome, pp_amigo_indicado);
        pp_amigo_indicado = pp_amigo_indicado->prox;
        nome = strtok(NULL, " ");
      }
    }
  }

  print_lista(head);
  liberar_lista(head);
}