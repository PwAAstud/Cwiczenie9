#include "gauss.h"
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b) {
    for(int ir = 0; ir < mat->r - 1; ir++) {
        if(ir == mat->c) {
            break;
        }

        // Wybór elementu g³ównego
        int maxRow = ir;
        for(int i = ir + 1; i < mat->r; i++) {
            if(fabs(mat->data[i][ir]) > fabs(mat->data[maxRow][ir])) {
                maxRow = i;
            }
        }

        // Zamiana wierszy, aby element g³ówny by³ w wierszu ir
        if(maxRow != ir) {
            for(int ic = 0; ic < mat->c; ic++) {
                double temp = mat->data[ir][ic];
                mat->data[ir][ic] = mat->data[maxRow][ic];
                mat->data[maxRow][ic] = temp;
            }
            for(int ic = 0; ic < b->r; ic++) {
                double temp = b->data[ir][ic];
                b->data[ir][ic] = b->data[maxRow][ic];
                b->data[maxRow][ic] = temp;
            }
        }

        // Normalizacja wiersza (dzielenie przez element g³ówny)
        double podzielPrzez = mat->data[ir][ir];
        for(int ic = 0; ic < mat->c; ic++) {
            mat->data[ir][ic] /= podzielPrzez;
        }
        for(int ic = 0; ic < b->r; ic++) {
            b->data[ir][ic] /= podzielPrzez;
        }

        // Eliminacja zmiennych poni¿ej wiersza
        for(int iMinC = ir + 1; iMinC < mat->r; iMinC++) {
            double mnoznik = mat->data[iMinC][ir];
            for(int ic = 0; ic < mat->c; ic++) {
                mat->data[iMinC][ic] -= mat->data[ir][ic] * mnoznik;
            }
            for(int ic = 0; ic < b->r; ic++) {
                b->data[iMinC][ic] -= b->data[ir][ic] * mnoznik;
            }
        }
    }

    return 0;
}


