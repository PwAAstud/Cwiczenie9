#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	for(int ir=0; ir < mat->r-1; ir++){
		if( ir == mat->c){
			break;
		}

		double podzielPrzez = mat->data[ir][ir];
		for(int ic=0; ic<mat->r; ic++){
			mat->data[ir][ic] /= podzielPrzez;
		}
		for(int ic=0; ic<b->r; ic++){
			b->data[ir][ic] /= podzielPrzez;
		}

		for(int iMinC = ir+1; iMinC < mat->r; iMinC++){
			double mnoznik = mat->data[iMinC][ir];
			for(int ic=0; ic<mat->r; ic++){
				mat->data[iMinC][ic] -= mat->data[ir][ic] * mnoznik;
			}
			for(int ic=0; ic<b->r; ic++){
				b->data[iMinC][ic] -= b->data[ir][ic] * mnoznik;
			}
		}

	}

	return 0;
}

