#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {

				int i, p, j;
				for (i = x->r - 1; i >= 0; i--) {

								j=i;
								p=b->data[i][0];
								while(j < x->r -1)
                                {
                                    p-=x->data[j][0] * mat->data[i][j];
                                    j++;
                                }
							x->data[i][0]= p / mat->data[i][i];
				}

				return 0;
}


