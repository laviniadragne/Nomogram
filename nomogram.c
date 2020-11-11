// Copyright 2019 Dragne Lavinia-Stefana 314CA
#include <stdio.h>

void citirea(int b[101][101], int n, int m) {
  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      scanf("%d", & b[i][j]);
    }
  }
}
// functie pentru citirea unei matrici
void citirelinii(int v[101], int b[101][101], int n) {
  int i, j;
  for (i = 1; i <= n; i++) {
    scanf("%d", & v[i]);
    for (j = 1; j <= v[i]; j++) {
      scanf("%d", & b[i][j]);
    }
  }
}
// construieste o matrice cu valorile date pe linii
void citirecoloane(int v[101], int b[101][101], int n) {
  int i, j;
  for (i = 1; i <= n; i++) {
    scanf("%d", & v[i]);
    for (j = 1; j <= v[i]; j++) {
      scanf("%d", & b[j][i]);
    }
  }
}
// construieste o matrice cu valorile date pe coloane
void umplere(int v[101], int b[101][101], int n, int m) {
  int i, j;
  for (i = 1; i <= n; i++) {
    v[i] = 0;
    for (j = 1; j <= m; j++) {
      b[i][j] = 0;
    }
  }
}
// umple o matrice cu 0
void afisare(int v[101], int t) {
  int i;
  for (i = 1; i <= t; i++) {
    if (v[i] == 0) printf("Eroare\n");
    else
      printf("Corect\n");
  }
}
// afiseaza matricea
int main() {
  int t, n, m, nr_bloc_linie[101], nr_bloc_col[101], a[101][101], i, j, k;
  int matr_linie[101][101], matr_col[101][101], ok, lung_secv;
  int matr_linie_constr[101][101], matr_col_constr[101][101];
  int nr_bloc_linie_constr[101], nr_bloc_col_constr[101], inceput, v_afis[101];
  scanf("%d", & t);
  if (t == 0) {printf("Eroare\n");
  } else {
    k = 1;
    while (k <= t) {
      ok = 1;
      scanf("%d%d", & n, & m);
      citirelinii(nr_bloc_linie, matr_linie, n);
      citirecoloane(nr_bloc_col, matr_col, m);
      citirea(a, n, m);
      // citirea datelor de la tastatura
      umplere(nr_bloc_linie_constr, matr_linie_constr, n, m);
      umplere(nr_bloc_col_constr, matr_col_constr, m, n);
      // umplerea matricilor ce trebuie suprapuse peste sabloane cu 0
      for (i = 1; i <= n; i++) {
        lung_secv = 0;
        inceput = 0;
        for (j = 1; j <= m; j++) {
          if (a[i][j] == 1) {lung_secv++;
          // contorizez lungimea de secvente de 1 maxima de pe o linie
         } else {
            if (a[i][j - 1] == 1 && j > 1) {
              nr_bloc_linie_constr[i]++;
              inceput++;
              matr_linie_constr[i][inceput] = lung_secv;
            }
            lung_secv = 0;
          }
          if (j == m && lung_secv != 0) {
            nr_bloc_linie_constr[i]++;
            inceput++;
            matr_linie_constr[i][inceput] = lung_secv;
          }
        }
      }
      // construire matricilor bloc-linie de 1 dupa valorile de la tastatura
      for (j = 1; j <= m; j++) {
        lung_secv = 0;
        inceput = 0;
        for (i = 1; i <= n; i++) {
          if (a[i][j] == 1) {lung_secv++;
          } else {
            if (a[i - 1][j] == 1 && i > 1) {
              nr_bloc_col_constr[j]++;
              inceput++;
              matr_col_constr[inceput][j] = lung_secv;
            }
            lung_secv = 0;
          }
          if (i == n && lung_secv != 0) {
            nr_bloc_col_constr[j]++;
            inceput++;
            matr_col_constr[inceput][j] = lung_secv;
          }
        }
      }
      // construire matricilor bloc-col. de 1 dupa valorile de la tastatura
      for (i = 1; i <= n; i++) {
        if (nr_bloc_linie[i] == nr_bloc_linie_constr[i]) {
          for (j = 1; j <= nr_bloc_linie[i]; j++) {
            if (matr_linie[i][j] != matr_linie_constr[i][j]) ok = 0;
          }
        } else {
          ok = 0;
        }
      }
      for (i = 1; i <= m; i++) {
        if (nr_bloc_col[i] == nr_bloc_col_constr[i]) {
          for (j = 1; j <= nr_bloc_col[i]; j++) {
            if (matr_col[j][i] != matr_col_constr[j][i]) ok = 0;
          }
        } else {
          ok = 0;
        }
      }
      // compararea matricilor construite cu cea data spre verificare
      v_afis[k] = ok;
      k++;
    }
    afisare(v_afis, t);
    // concluzia
  }
  return 0;
}
