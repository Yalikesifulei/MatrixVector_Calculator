#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void StringToArray(char *str, double *arr, int n){
	char *t = strtok(str, " "); int i=0;
    while ((t != NULL)&&(i<n)){
    	arr[i]=atof(t);
    	t = strtok(NULL, " ");
    	i++;
	}
	if (i<n){
		for (int j=i; j<n; j++){
			arr[j] = 0.0;
		}
	}
}

double Vector_ScalarProduct(double *x, double *y, int n){
	double res = 0.0;
	for (int i=0; i<n; i++){
    	res += x[i]*y[i];
    }
    return res;
}

int Matrix_Rank(double **Matrix, int m, int n){
	int i=0,j=0,k,l; double r; double eps = 0.000001;

	while (i<m && j<n){
		r = 0.0;
		for (k=i; k<m; k++) {
			if (fabs(Matrix[k][j])>r){
				l = k;
				r = fabs(Matrix[k][j]);
			}
		}
		if (r<=eps) {
			for (k=i; k<m; k++){
				Matrix[k][j] = 0.0;
			}
			j++; continue;
		}
		if (l!=i) {
			for (k=j; k<n; k++){
				r = Matrix[i][k];
				Matrix[i][k] = Matrix[l][k];
				Matrix[l][k] = (-r);
			}
		}
		for (k=i+1; k<m; k++){
			r = (-Matrix[k][j]/Matrix[i][j]);
            Matrix[k][j] = 0.0;
            for (l=j+1; l<n; l++) {
                Matrix[k][l] += r*Matrix[i][l];
            }
		}

		i++; j++;
	}

	return i;
}

void Adjugate(double **Matrix, int n){
	double **Minor = new double*[n-1];
	for (int i=0; i<n-1; i++) Minor[i] = new double[n-1];
	double **Adj = new double*[n];
	for (int i=0; i<n; i++) Adj[i] = new double[n];
	double det = 1.0; int i, j, k1, k2, a; int rank;
	for (k1=0; k1<n; k1++){
		for (k2=0; k2<n; k2++){
			det = 1.0;
			for (i=0; i<k1; i++){
				for (j=0; j<k2; j++)
					Minor[i][j] = Matrix[i][j];
				for (j=k2+1; j<n; j++)
					Minor[i][j-1] = Matrix[i][j];			
			}
			for (i=k1+1; i<n; i++){
				for (j=0; j<k2; j++)
					Minor[i-1][j] = Matrix[i][j];
				for (j=k2+1; j<n; j++)
					Minor[i-1][j-1] = Matrix[i][j];	
			}
			rank = Matrix_Rank(Minor, n-1, n-1);
        	for (i=0; i<n-1; i++)
            	det*=Minor[i][i];
        	a = ((k1+k2)%2 == 0)?1:-1;
        	Adj[k2][k1] = a*det;
		}
	}

	for (int i=0; i<n-1; i++) {
		if (Minor[i]) delete[] Minor[i];
	};
	if (Minor) delete[] Minor;

	det = 1.0;
	rank = Matrix_Rank(Matrix, n, n);
    for (i=0; i<n; i++)
    	det*=Matrix[i][i];

	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			Matrix[i][j] = Adj[i][j]/det;
		}		
	}

	for (int i=0; i<n; i++) {
		if (Adj[i]) delete[] Adj[i];
	};
	if (Adj) delete[] Adj;
}

double **Multiply_Matrix(double **A, double **B, int n, int m, int k){
	double **C = new double*[n]; double temp = 0.0;
	for (int i=0; i<n; i++){
		C[i] = new double[k];
	}

	for (int i=0; i<n; i++){
		for (int j=0; j<k; j++){
			// C[i][j] = scalar production of A[i] and B[j]
			for (int t=0; t<m; t++){
				temp+=(A[i][t]*B[t][j]);
			}
			C[i][j] = temp;
			temp = 0.0;
		}
	}

	return C;
}

double **Power_Matrix(double **Matrix, int n, int p){
	double **Res = new double*[n];
	for (int i=0; i<n; i++){
		Res[i] = new double[n];
		for (int j=0; j<n; j++){
			Res[i][j] = Matrix[i][j];
		}
	}
	// positive powers >1
	if (p>1){
		for (int i=1; i<p; i++){
			Res = Multiply_Matrix(Matrix, Res, n, n, n);
		}
	}
	// negative powers, need to calculate inverse first; assuming det!=0
	if (p<0){
		Adjugate(Matrix, n);
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				Res[i][j] = Matrix[i][j];
			}
		}

		if (p<-1){
			for (int i=1; i<abs(p); i++){
				Res = Multiply_Matrix(Matrix, Res, n, n, n);
			}
		}
	}
	return Res;
}