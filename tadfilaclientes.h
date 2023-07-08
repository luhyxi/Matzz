#ifndef TADFILACLIENTES_H
#define TADFILACLIENTES_H

#define N 80

typedef struct {
  char nome[N];
  float valorDeposito;
} Cliente;

typedef struct No {
	Cliente cliente; 
	struct No* prox;
} No;

typedef struct {
  No* inicio;
  No* fim;
} FilaClientes;

FilaClientes* fila_cria(void);

void fila_insere(FilaClientes* f, Cliente v);

Cliente fila_retira(FilaClientes* f);

int fila_vazia(FilaClientes* f);

void fila_libera(FilaClientes* f);

#endif
