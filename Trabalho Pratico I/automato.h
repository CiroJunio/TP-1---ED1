#include <stdio.h>
#include <stdlib.h>
typedef struct matriz {
  int **matriz;
} Matriz;

void lerOrdem(FILE *, int *ordem);

int **alocarReticulado(int ordem);

void desalocarReticulado(int **M, int ordem);

void leituraReticulado(FILE *, int **M, int ordem);

void imprimeReticulado(int **M, int ordem);

int evoluirReticulado(int **a, int r, int c, int ordem);

void lerOrdem(FILE *fp, int *ordem) { fscanf(fp, "%d", ordem); }

int **alocarReticulado(int ordem) {
  int **M; 
  M = (int **)malloc(ordem * sizeof(int *));  
  for (int i = 0; i < ordem; i++) {
     M[i] = (int*) malloc(ordem * sizeof(int));
  }
  return M;
}

// manter como especificado
void desalocarReticulado(int **M, int ordem) {
  for (int i = 0; i < ordem; i++)
    free(M[i]);
  free(M);
}

void leituraReticulado(FILE *fp, int **M, int ordem) {
  for (int i = 0; i < ordem; i++) {
    for (int j = 0; j < ordem; j++) {
      fscanf(fp, "%d", &M[i][j]);
    }
  }
}

int evoluirReticulado(int **a, int r, int c, int ordem) {
  int count = 0;
  for (int i = r - 1; i <= r + 1; i++) {
    for (int j = c - 1; j <= c + 1; j++) {
      if ((i == r && j == c) || (i < 0 || j < 0) ||
          (i >= ordem || j >= ordem)) {
        continue;
      }
      if (a[i][j] == 1) {
        count++;
      }
    }
  }
  return count;
}

void imprimeReticulado(int **M, int ordem) {
  for (int i = 0; i < ordem; i++) {
    for (int j = 0; j < ordem; j++) {
      if (j == ordem - 1) {
        if (M[i][j] == 1)
          printf("o");
        else
          printf("-");
      } else {
        if (M[i][j] == 1)
          printf("o ");
        else
          printf("- ");
      }
    }
    printf("\n");
  }
}