#include "automato.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
  Matriz M, b;
  int ordem;

  FILE *fp;

  fp = fopen("automato.txt", "w");

  // ordem = 30;
  ordem = 20;
  srand(time(NULL));

  int **d = alocarReticulado(ordem);
  int rascunho;
  for (int i = 0; i < ordem; i++) {
    for (int j = 0; j < ordem; j++) {
      // d[i][j] = rand() % 2;
      rascunho = rand() % 6;
      if (rascunho == 0) {
        d[i][j] = 1;
      } else
        d[i][j] = 0;
    }
  }
  fprintf(fp, "%d\n", ordem);
  for (int i = 0; i < ordem; i++) {
    for (int j = 0; j < ordem; j++) {

      if (j == ordem - 1) {
        fprintf(fp, "%d", d[i][j]);
      } else
        fprintf(fp, "%d ", d[i][j]);
    }
    fprintf(fp, "\n");
  }
  desalocarReticulado(d, ordem);
  fclose(fp);
  fp = fopen("automato.txt", "r");

  if (fp == NULL) {
    printf("Erro\n");
    return 1;
  }

  lerOrdem(fp, &ordem);

  M.matriz = alocarReticulado(ordem);
  b.matriz = alocarReticulado(ordem);

  leituraReticulado(fp, M.matriz, ordem);

  int contador_celulas;
  int loop = 1;
  do {
    printf("\e[1;1H\e[2J");
    for (int i = 0; i < ordem; i++) {
      for (int j = 0; j < ordem; j++) {
        contador_celulas = evoluirReticulado(M.matriz, i, j, ordem);
        if (M.matriz[i][j] == 1 &&
            (contador_celulas == 2 || contador_celulas == 3)) {
          b.matriz[i][j] = 1;
        }

        else if (M.matriz[i][j] == 0 && contador_celulas == 3) {
          b.matriz[i][j] = 1;
        }

        else {
          b.matriz[i][j] = 0;
        }
      }
    }
    printf("\n\n\n");
    imprimeReticulado(b.matriz, ordem);
    for (int i = 0; i < ordem; i++) {
      for (int j = 0; j < ordem; j++) {
        M.matriz[i][j] = b.matriz[i][j];
      }
    }
    loop++;
    sleep(1);
  } while (loop != 100);
  desalocarReticulado(M.matriz, ordem);
  fclose(fp);

  return 0;
}
