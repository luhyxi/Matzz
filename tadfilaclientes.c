#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadfilaclientes.h"

void cria_fila(FilaClientes* fila) {
  fila->inicio = NULL;
  fila->fim = NULL;
}

int filaVazia(FilaClientes* fila) {
  return (fila->inicio == NULL);
}

void insereCliente(FilaClientes* fila, Cliente cliente) {
  No* novoNo = (No*)malloc(sizeof(No));
  novoNo->cliente = cliente;
  novoNo->prox = NULL;

  if (filaVazia(fila)) {
    fila->inicio = novoNo;
    fila->fim = novoNo;
  } else {
    fila->fim->prox = novoNo;
    fila->fim = novoNo;
  }
}

Cliente removeCliente(FilaClientes* fila) {
  if (filaVazia(fila)) {
    Cliente clienteVazio;
    strcpy(clienteVazio.nome, "");
    clienteVazio.valorDeposito = 0.0;
    return clienteVazio;
  }

  No* noRemovido = fila->inicio;
  Cliente clienteRemovido = noRemovido->cliente;

  fila->inicio = fila->inicio->prox;
  free(noRemovido);

  if (fila->inicio == NULL) {
    fila->fim = NULL;
  }

  return clienteRemovido;
}

float atendimentoCaixaBanco(FilaClientes* fila, int* totalAtendidos) {
  float totalDepositos = 0.0;
  *totalAtendidos = 0;

  while (!filaVazia(fila)) {
    Cliente clienteAtual = removeCliente(fila);
    (*totalAtendidos)++;
    totalDepositos += clienteAtual.valorDeposito;

    printf("Cliente %d - ", *totalAtendidos);
    printf("%s atendido", clienteAtual.nome);
    printf(", deposito de %.2f reais\n", clienteAtual.valorDeposito);
    printf("\n");
  }

  return totalDepositos;
}

int main() {
  FilaClientes fila;
  cria_fila(&fila);

  char fim_scan[] = "FIM";
  char nome[N];
  float valorDeposito;


	printf("Insira o nome do cliente e seu valor depositado (digite 'FIM' para finalizar): \n");
	
  while (scanf("%s", nome) == 1 && strcmp(nome, fim_scan) != 0) {
    scanf("%f", &valorDeposito);

    Cliente cliente;
    strcpy(cliente.nome, nome);
    cliente.valorDeposito = valorDeposito;

    insereCliente(&fila, cliente);
  }

	int totalAtendidos;
  float totalDepositos = atendimentoCaixaBanco(&fila, &totalAtendidos);


  printf("Total de clientes: %d\n", totalAtendidos);
  printf("Deposito total: %.2f reais\n", totalDepositos); 
}