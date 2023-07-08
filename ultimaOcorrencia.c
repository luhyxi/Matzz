#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int ultima_ocorrencia(char* s, char c){
  int p = 0;
  int ult_oco = -1;

  while (s[p] != '\0') {
    if (s[p] == c) { 
      ult_oco = p;
      } p++;
  } return ult_oco;
}

char* inverte(char* s){
  int tam = strlen(s);
  int meio = tam / 2;
  char temp;
  char *s_inv = (char*)malloc((tam + 1) * sizeof(char));


  strcpy(s_inv, s);

  for (int i = 0; i < meio; i++) {
      temp = s_inv[i];
      s_inv[i] = s_inv[tam - i - 1];
      s_inv[tam - i - 1] = temp;
  } return s_inv;
}

void codifica (char* s){
  for (int i = 0; s[i] != '\0'; i++) {
    if ((s[i] >= 'A' && s[i] < 'Z') || (s[i] >= 'a' && s[i] < 'z')) {
      s[i]++;
    } else if (s[i] == 'Z') {
      s[i] = 'A';
    } else if (s[i] == 'z') {
      s[i] = 'z';
    }
  }
}

int main() {
  char codificado[80];
  printf("Coloque a String a codificar: \n");
  scanf("%80[^\n]", codificado);
  codifica(codificado);
  printf("Codificado: %s\n", codificado);
}

/*
int main() {
  char teste[] = "Rio de Janeiro";
  char teste2[] = "puc-rio";
  char teste3[] = "PUC-rioZz";

  int index = ultima_ocorrencia(teste, 'i');

  printf("Ultima Ocorrencia: %d\n", index);

  char* teste_inv = inverte(teste2);

  printf("Invertido: %s\n", teste_inv);

  free(teste_inv);

  codifica(teste3);

  printf("Codificado: %s\n", teste3);

  return 0;
}

*/

