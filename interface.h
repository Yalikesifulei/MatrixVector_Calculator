#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include"toolset.h"

#define CYAN_BG 48
#define YELLOW_BG 224
#define WHITE 15
#define YELLOW 14

#define ESC 27
#define ENTER 13
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define UP 72
#define ZERO_KEY 48

void DrawHorizontalMenu(HANDLE h, int select);
void HorizontalMenu(HANDLE h);

void VectorMenu(HANDLE h);
void Vector_Submenu(HANDLE h);
void ScalarProduct_Menu(HANDLE h);			//1
void VectorProduct_Menu(HANDLE h);			//2
void ScalarTripleProduct_Menu(HANDLE h);	//3
void VectorTripleProduct_Menu(HANDLE h);	//4
void VectorLength_Menu(HANDLE h);			//5
void VectorAngle_Menu(HANDLE h);			//6
void VectorCalculator_Menu(HANDLE h);		//7

void MatrixMenu(HANDLE h);
void Matrix_Submenu(HANDLE h);
void Determinant_Menu(HANDLE h);			//1
void Transpose_Menu(HANDLE h);				//2
void Rank_Menu(HANDLE h);					//3
void Inverse_Menu(HANDLE h);				//4
void MatrixProduct_Menu(HANDLE h);			//5
void MatrixCalculator_Menu(HANDLE h);		//6
void MatrixPower_Menu(HANDLE h);			//7
void MatrixUPT_Menu(HANDLE h);				//8
void MatrixTrace_Menu(HANDLE h);			//9

void AboutMenu(HANDLE h);
void AboutText(HANDLE h);


void DrawHorizontalMenu(HANDLE h, int select){
	CONSOLE_SCREEN_BUFFER_INFO Info;
	GetConsoleScreenBufferInfo(h, &Info);

	COORD left;
	left.X = (Info.dwSize.X - 34)/2;
	left.Y = 0;
	COORD start; start.X = 0; start.Y = 0;
	SetConsoleTextAttribute(h, CYAN_BG+WHITE);
	SetConsoleCursorPosition(h, start); 
	for (int i=0; i<Info.dwSize.X; i++) {
		printf(" ");
	}
	SetConsoleCursorPosition(h, left);

	switch (select){
		case 0:{
			SetConsoleTextAttribute(h, CYAN_BG+WHITE);
			printf("[");
			SetConsoleTextAttribute(h, YELLOW_BG);
			printf(" Vectors ");
			SetConsoleTextAttribute(h, CYAN_BG+WHITE);
			printf("] [ Matrices ] [ About ]\n");
			break;
		}
		case 1:{
			SetConsoleTextAttribute(h, CYAN_BG+WHITE);
			printf("[ Vectors ] [");
			SetConsoleTextAttribute(h, YELLOW_BG);
			printf(" Matrices ");
			SetConsoleTextAttribute(h, CYAN_BG+WHITE);
			printf("] [ About ]\n");
			break;
		}
		case 2:{
			SetConsoleTextAttribute(h, CYAN_BG+WHITE);
			printf("[ Vectors ] [ Matrices ] [");
			SetConsoleTextAttribute(h, YELLOW_BG);
			printf(" About ");
			SetConsoleTextAttribute(h, CYAN_BG+WHITE);
			printf("]\n");
			break;
		}

	}
	//printf("[ Vectors ] [ Matrices ] [ About ]\n");
}

void VectorMenu(HANDLE h){
	system("cls");
	DrawHorizontalMenu(h, 0);
	printf("\n 1. Scalar product          (x,y)\n"
			 " 2. Vector product          [x,y]\n" 
			 " 3. Scalar triple product   (x,[y,z])\n"
			 " 4. Vector triple product   [a,[b,c]]\n"
			 " 5. Vector length           ||x||\n"
			 " 6. Angle between vectors \n"
			 " 7. Simple calculations (addition, substraction)\n");

	int ch, fl = 1, select = 0, max = 2;
	while(fl){
		if(_kbhit()){
			ch = _getch();
			switch(ch){
				case ZERO_KEY+1: {
					ScalarProduct_Menu(h);
					break;
				}
				case ZERO_KEY+2: {
					VectorProduct_Menu(h);
					break;
				}
				case ZERO_KEY+3: {
					ScalarTripleProduct_Menu(h);
					break;
				}
				case ZERO_KEY+4: {
					VectorTripleProduct_Menu(h);
					break;
				}
				case ZERO_KEY+5: {
					VectorLength_Menu(h);
					break;
				}
				case ZERO_KEY+6: {
					VectorAngle_Menu(h);
					break;
				}
				case ZERO_KEY+7: {
					VectorCalculator_Menu(h);
					break;
				}

				case ESC: {fl = 0; exit(0);}
				case ENTER:{
					switch(select){
						case 0: {
							VectorMenu(h);
							break;
						}
						case 1: {
							MatrixMenu(h);
							break;
						}
						case 2: {
							AboutMenu(h); 
							break;
						}
					} break;
				}
				case LEFT:{
					if (select==0) select=max; else select--;
					DrawHorizontalMenu(h, select); break;
				}
				case RIGHT:{
					if (select==max) select=0; else select++;
					DrawHorizontalMenu(h, select); break;
				}
			}
		}
	}
}

void MatrixMenu(HANDLE h){
	system("cls");
	DrawHorizontalMenu(h, 1);
	printf("\n 1. Determinant\n"
			 " 2. Transpose\n"
			 " 3. Rank\n"
			 " 4. Inverse matrix\n"
			 " 5. Matrix product\n"
			 " 6. Simple calculations (addition, substraction)\n"
			 " 7. Matrix power\n"
			 " 8. Upper triangular form\n"
			 " 9. Matrix trace\n");

	int ch, fl = 1, select = 1, max = 2;
	while(fl){
		if(_kbhit()){
			ch = _getch();
			switch(ch){
				case ZERO_KEY+1: {
					Determinant_Menu(h);
					break;
				}
				case ZERO_KEY+2: {
					Transpose_Menu(h);
					break;
				}
				case ZERO_KEY+3: {
					Rank_Menu(h);
					break;
				}
				case ZERO_KEY+4: {
					Inverse_Menu(h);
					break;
				}
				case ZERO_KEY+5: {
					MatrixProduct_Menu(h);
					break;
				}
				case ZERO_KEY+6: {
					MatrixCalculator_Menu(h);
					break;
				}
				case ZERO_KEY+7: {
					MatrixPower_Menu(h);
					break;
				}
				case ZERO_KEY+8: {
					MatrixUPT_Menu(h);
					break;
				}
				case ZERO_KEY+9: {
					MatrixTrace_Menu(h);
					break;
				}

				case ESC: {fl = 0; exit(0);}
				case ENTER:{
					switch(select){
						case 0: {
							VectorMenu(h);
							break;
						}
						case 1: {
							MatrixMenu(h);
							break;
						}
						case 2: {
							AboutMenu(h);
							break;
						}
					} break;
				}
				case LEFT:{
					if (select==0) select=max; else select--;
					DrawHorizontalMenu(h, select); break;
				}
				case RIGHT:{
					if (select==max) select=0; else select++;
					DrawHorizontalMenu(h, select); break;
				}
			}
		}
	}
}

void EasterEgg();
// -----  ABOUT MENU -----

void AboutMenu(HANDLE h){
	system("cls");
	DrawHorizontalMenu(h, 2);
	AboutText(h);

	int ch, fl = 1, select = 2, max = 2, e1 = 0, e2 = 0, e3 = 0;
	while(fl){
		if(_kbhit()){
			ch = _getch();
			switch(ch){
				case ESC: {fl = 0; exit(0);}
				case ENTER: {
					switch(select){
						case 0: {
							VectorMenu(h);
							break;
						}
						case 1: {
							MatrixMenu(h);
							break;
						}
						case 2: {
							AboutMenu(h); 
							break;
						}
					} break;
				}
				case LEFT: {
					if (select==0) select=max; else select--;
					DrawHorizontalMenu(h, select); break;
				}
				case RIGHT: {
					if (select==max) select=0; else select++;
					DrawHorizontalMenu(h, select); break;
				}
				case 81: {
					if (!e1) EasterEgg(); e1++; 
					break;
				}
				case 72: {
					if (!e2) printf("\n Thanks to Dasha Falileeva for testing and inspiration!\n"); e2++;
					break;
				}
				case 100: {
					if (!e3) printf("\n Thanks to Nadia Miller for support!\n"); e3++;
					break;
				}
			}
		}
	}
}

void HorizontalMenu(HANDLE h){
	int select = 0, max = 2;
	int ch, fl = 1;
	DrawHorizontalMenu(h, select);
	printf("\n Welcome to vector and matrix calculator!\n\n");
	printf(" Use LEFT and RIGHT keys to navigate the horizontal menu, ENTER key to select menu item.\n"
		   " While in \"Vectors\" or \"Matrices\", select menu items using Num keys.\n"
	   	   " Use ESC key to return to main menu from operation menu and to exit program while in main menu.\n"
		   " Vectors should be entered in one line, coordinates separated by space.\n\n"
		   " Matrices are entered in the same way: line by line, numbers separated by space.\n"
		   " Real numbers with fractional part are enterted with dot: 3.14, but not 3,14.\n"
		   " Default Windows clipboard works in console.\n"
		   " You can select result vector or matrix, copy and paste it with right mouse click (on Windows 10).\n"
		   " Copy-paste should work on earlier Windows versions with Shift-Ctrl-C and Shift-Ctrl-V combinations.\n");
	while(fl){
		if(_kbhit()){
			ch = _getch();
			switch(ch){
				case ESC: {fl = 0; exit(0);}
				case ENTER:{
					switch(select){
						case 0: {
							VectorMenu(h);
							break;
						}
						case 1: {
							MatrixMenu(h);
							break;
						}
						case 2: {
							AboutMenu(h);
							break;
						}
					} break;
				}
				case LEFT:{
					if (select==0) select=max; else select--;
					DrawHorizontalMenu(h, select); break;
				}
				case RIGHT:{
					if (select==max) select=0; else select++;
					DrawHorizontalMenu(h, select); break;
				}
			}
		}
	}
}

void Vector_Submenu(HANDLE h){
	int select = 0, max = 2;
	int ch, fl = 1;
	while(fl){
		if(_kbhit()){
			ch = _getch();
			switch(ch){
				case ESC: {fl = 0; system("cls"); VectorMenu(h); break;}
				case ENTER:{
					switch(select){
						case 0: {
							VectorMenu(h);
							break;
						}
						case 1: {
							MatrixMenu(h);
							break;
						}
						case 2: {
							AboutMenu(h); 
							break;
						}
					} break;
				}
				case LEFT:{
					if (select==0) select=max; else select--;
					DrawHorizontalMenu(h, select); break;
				}
				case RIGHT:{
					if (select==max) select=0; else select++;
					DrawHorizontalMenu(h, select); break;
				}
			}
		}
	}
}

void Matrix_Submenu(HANDLE h){
	int select = 1, max = 2;
	int ch, fl = 1;
	while(fl){
		if(_kbhit()){
			ch = _getch();
			switch(ch){
				case ESC: {fl = 0; system("cls"); MatrixMenu(h); break;}
				case ENTER:{
					switch(select){
						case 0: {
							VectorMenu(h);
							break;
						}
						case 1: {
							MatrixMenu(h);
							break;
						}
						case 2: {
							AboutMenu(h);
							break;
						}
					} break;
				}
				case LEFT:{
					if (select==0) select=max; else select--;
					DrawHorizontalMenu(h, select); break;
				}
				case RIGHT:{
					if (select==max) select=0; else select++;
					DrawHorizontalMenu(h, select); break;
				}
			}
		}
	}
}


// ----- VECTOR OPERATIONS MENUS -----

void ScalarProduct_Menu(HANDLE h){
// TECHINCAL PART
	system("cls");
	DrawHorizontalMenu(h, 0);
	printf("\n SCALAR PRODUCT CALCULATOR\n\n");
	int i = 0, n = 0;
	double *x = NULL;
	double *y = NULL;
	char temp[512];
	printf("Enter dimension: ");
	fflush(stdin);
    scanf("%i", &n);
    if (n>0){
    	x = new double[n];
    	y = new double[n];
    	fflush(stdin);
    	printf("Enter x vector:\n");
    	gets(temp);
    	StringToArray(temp, x, n);
    	printf("Enter y vector:\n");
    	gets(temp);
    	StringToArray(temp, y, n);
        printf("\n(x, y) = %g\n", Vector_ScalarProduct(x, y, n));
    	if (x) delete[] x; if (y) delete[] y;
    }
    else printf("\nERROR: zero or negative dimension.");
    
// INTERFACE PART
	Vector_Submenu(h);
}

void VectorProduct_Menu(HANDLE h){
// TECHINCAL PART
	system("cls");
	DrawHorizontalMenu(h, 0);
	printf("\n VECTOR PRODUCT CALCULATOR\n\n");
	int i = 0;
	double x[3], y[3], z[3];
	char temp[512];
	printf("Only for R3 vectors!\n");
    fflush(stdin);
    printf("Enter x vector:\n");
    gets(temp);
    StringToArray(temp, x, 3);
    printf("Enter y vector:\n");
    gets(temp);
    StringToArray(temp, y, 3);
    z[0] = x[1]*y[2] - x[2]*y[1];
    z[1] = x[2]*y[0] - x[0]*y[2];
    z[2] = x[0]*y[1] - x[1]*y[0];
    printf("\n[x, y] = (%g, %g, %g)\n", z[0], z[1], z[2]);
// INTERFACE PART
	Vector_Submenu(h);
}

void ScalarTripleProduct_Menu(HANDLE h){
// TECHINCAL PART
	system("cls");
	DrawHorizontalMenu(h, 0);
	printf("\n SCALAR TRIPLE PRODUCT CALCULATOR\n\n");
	double x[3], y[3], z[3], t[3];
	char temp[512];
	printf("Only for R3 vectors! Calculates (x,[y,z])\n");
    fflush(stdin);
    printf("Enter x vector:\n");
    gets(temp);
    StringToArray(temp, x, 3);
    printf("Enter y vector:\n");
    gets(temp);
    StringToArray(temp, y, 3);
    printf("Enter z vector:\n");
    gets(temp);
    StringToArray(temp, z, 3);
    t[0] = y[1]*z[2] - y[2]*z[1];
    t[1] = y[2]*z[0] - y[0]*z[2];
    t[2] = y[0]*z[1] - y[1]*z[0];
    printf("\n(x, [y, z]) = %g\n", Vector_ScalarProduct(x, t, 3));
// INTERFACE PART
	Vector_Submenu(h);
}
void VectorTripleProduct_Menu(HANDLE h){
// TECHINCAL PART
	system("cls");
	DrawHorizontalMenu(h, 0);
	printf("\n VECTOR TRIPLE PRODUCT CALCULATOR\n\n");
	int i = 0;
	double a[3], b[3], c[3], t[3]; double ac, ab;
	char temp[512];
	printf("Only for R3 vectors! Calculates [a,[b,c]]\n");
	fflush(stdin);
	printf("Enter a vector:\n");
    gets(temp);
    StringToArray(temp, a, 3);
    printf("Enter b vector:\n");
    gets(temp);
    StringToArray(temp, b, 3);
    printf("Enter c vector:\n");
    gets(temp);
    StringToArray(temp, c, 3);
    ac = Vector_ScalarProduct(a, c, 3);
    ab = Vector_ScalarProduct(a, b, 3);
    for (int i=0; i<3; i++){
    	t[i] = b[i]*ac - c[i]*ab;
    }
    printf("\n[a, [b, c]] = (%g, %g, %g)\n", t[0], t[1], t[2]);
// INTERFACE PART
	Vector_Submenu(h);
}

void VectorLength_Menu(HANDLE h){
// TECHINCAL PART
	system("cls");
	DrawHorizontalMenu(h, 0);
	printf("\n VECTOR LENGTH CALCULATOR\n\n");
	int i = 0, n = 0;
	double *x = NULL;
	char temp[512];
	printf("Enter dimension: ");
	fflush(stdin);
    scanf("%i", &n);
    if (n>0){
    	x = new double[n];
    	fflush(stdin);
    	printf("Enter vector:\n");
    	gets(temp);
    	StringToArray(temp, x, n);
    	printf("\n||x|| = %g\n", sqrt(Vector_ScalarProduct(x, x, n)));
    	if (x) delete[] x;
    } else printf("\nERROR: zero or negative dimension.");
    
// INTERFACE PART
	Vector_Submenu(h);
}

void VectorAngle_Menu(HANDLE h){
// TECHINCAL PART
	system("cls");
	DrawHorizontalMenu(h, 0);
	printf("\n ANGLE BETWEEN VECTORS CALCULATOR\n\n");
	int i = 0, n = 0;
	double *x = NULL;
	double *y = NULL;
	char temp[512];
	printf("Enter dimension: ");
	fflush(stdin);
    scanf("%i", &n);
    if (n>0){
    	x = new double[n];
    	y = new double[n];
    	fflush(stdin);
    	printf("Enter x vector:\n");
    	gets(temp);
    	StringToArray(temp, x, n);
    	printf("Enter y vector:\n");
    	gets(temp);
    	StringToArray(temp, y, n);
    	double norm_x = sqrt(Vector_ScalarProduct(x, x, n));
    	double norm_y = sqrt(Vector_ScalarProduct(y, y, n));
    	double cosine = Vector_ScalarProduct(x, y, n)/(norm_x*norm_y);
        printf("\ncos(x, y) = %g\n", cosine);
        printf("angle = %g rad, %g deg\n", acos(cosine), acos(cosine)*(180/M_PI));
    	if (x) delete[] x; if (y) delete[] y;
    } else printf("\nERROR: zero or negative dimension.");
    
// INTERFACE PART
	Vector_Submenu(h);
}

void VectorCalculator_Menu(HANDLE h){
	// TECHINCAL PART
	system("cls");
	DrawHorizontalMenu(h, 0);
	printf("\n SIMPLE VECTOR CALCULATIONS (addition, substraction)\n\n");
	int i = 0, n = 0;
	double A = 1.0, B = 1.0;
	double *x = NULL;
	double *y = NULL;
	char temp[512];
	printf("You can calculate A*x + B*y (x and y are vectors, A and B - real numbers)\n");
	printf("Enter dimension: ");
	fflush(stdin);
    scanf("%i", &n);
    if (n>0){
    	x = new double[n];
    	y = new double[n];
    	fflush(stdin);
    	printf("Enter x vector:\n");
    	gets(temp);
    	StringToArray(temp, x, n);
    	printf("Enter y vector:\n");
    	gets(temp);
    	StringToArray(temp, y, n);
    	printf("Enter A and B: ");
    	scanf("%lf %lf", &A, &B);
    	printf("%g*x + %g*y = (", A, B);
    	for(i=0; i<n; i++){
    		if (i!=(n-1)) printf("%g, ", A*x[i]+B*y[i]);
    		else printf("%g)", A*x[i]+B*y[i]);
    	}
    	if (x) delete[] x; if (y) delete[] y;
    } else printf("\nERROR: zero or negative dimension.");
    
// INTERFACE PART
	Vector_Submenu(h);
}

// ----- MATRIX OPERATIONS MENUS -----

void Determinant_Menu(HANDLE h){
	system("cls");
	DrawHorizontalMenu(h, 1);
// TECHNICAL PART
	printf("\n MATRIX DETERMINANT CALCULATOR\n\n");
	int i = 0, j = 0, n = 0;
	double det = 1.0;
	double **Matrix = NULL;
	char temp[512];
	printf("Enter dimension: ");
	fflush(stdin);
    scanf("%i", &n);
    if (n>0) {
    	Matrix = new double*[n];
    	for (i=0; i<n; i++) {
        	Matrix[i] = new double[n];
    	}

    	fflush(stdin);
    
    	printf("Enter matrix:\n");
        for (i=0; i<n; i++){
    		gets(temp);
            StringToArray(temp, Matrix[i], n);
    	}
    
        int rank = Matrix_Rank(Matrix, n, n);
        for (i = 0; i < n; ++i) {
            det*=Matrix[i][i];
        }
    	if (fabs(det)>=0.000001)
       		printf("\nDet = %g", det);
       	else printf("\nDet = 0\n");

        for (i=0; i<n; i++) {
        	if (Matrix[i]) delete[] Matrix[i];
    	}
    	if (Matrix) delete[] Matrix;
    } else printf("\nERROR: zero or negative dimension.");

// INTERFACE PART
	Matrix_Submenu(h);
}

void Transpose_Menu(HANDLE h){
	system("cls");
	DrawHorizontalMenu(h, 1);
// TECHNICAL PART
	printf("\n MATRIX TRANSPOSE\n\n");
	int i = 0, j = 0, n = 0, m = 0;
	double **Matrix = NULL, **Matrix_T = NULL;
	char temp[512];
	printf("Enter dimension NxM: ");
	fflush(stdin);
    scanf("%i %i", &n, &m);
    if (n>0 && m>0) {
    	Matrix = new double*[n];
        Matrix_T = new double*[m];
        for (i=0; i<n; i++) {
            Matrix[i] = new double[m];
        }
        for (i=0; i<m; i++) {
        	Matrix_T[i] = new double[n];
        }
    
        fflush(stdin);
        printf("Enter matrix:\n");
        for (i=0; i<n; i++){
    		gets(temp);
            StringToArray(temp, Matrix[i], m);
    	}
    
    	for (i=0; i<n; i++){
    		for (j=0; j<m; j++){
    			Matrix_T[j][i] = Matrix[i][j];
    		}
    	}
    
    	printf("\nTransposed matrix:\n");
    	for(i=0; i<m; i++){
    		for (j=0; j<n; j++){
    			printf("%g ", Matrix_T[i][j]);
    		}
    		printf("\n");
    	}

    	for (i=0; i<n; i++) {
            if (Matrix[i]) delete[] Matrix[i];
        }
        for (i=0; i<m; i++) {
        	if (Matrix_T[i]) delete[] Matrix_T[i];
        }
        if (Matrix) delete[] Matrix; if (Matrix_T) delete[] Matrix_T;
    } else printf("\nERROR: zero or negative dimension.");

// INTERFACE PART
	Matrix_Submenu(h);
}

void Rank_Menu(HANDLE h){
	system("cls");
	DrawHorizontalMenu(h, 1);
// TECHNICAL PART
	printf("\n MATRIX RANK CALCULATOR\n\n");
	int i = 0, j = 0, n = 0, m = 0;
	double **Matrix = NULL;
	char temp[512];
	printf("Enter dimension NxM: ");
	fflush(stdin);
    scanf("%i %i", &n, &m);
    if (n>0 && m>0) {
    	Matrix = new double*[n];
    
        for (i=0; i<n; i++) {
            Matrix[i] = new double[m];
        }
    
        fflush(stdin);
        printf("Enter matrix:\n");
        for (i=0; i<n; i++){
    		gets(temp);
            StringToArray(temp, Matrix[i], m);
    	}
    
    	int rank = Matrix_Rank(Matrix, n, m);
    
    	printf("\nRank = %i\n", rank);

    	for (i=0; i<n; i++) {
            if (Matrix[i]) delete[] Matrix[i];
        }
        if (Matrix) delete[] Matrix;
    } else printf("\nERROR: zero or negative dimension.");

// INTERFACE PART
	Matrix_Submenu(h);
}

void Inverse_Menu(HANDLE h){
	system("cls");
	DrawHorizontalMenu(h, 1);
// TECHNICAL PART
	printf("\n INVERSE MATRIX CALCULATOR\n\n");
	int i = 0, j = 0, n = 0;
	double det = 1.0;
	double **Matrix = NULL;
	double **Temp = NULL;
	char temp[512];
	printf("Enter dimension: ");
	fflush(stdin);
    scanf("%i", &n);
    if (n>0) {
    	Matrix = new double*[n];
    	Temp = new double*[n];
    	for (i=0; i<n; i++){
    		Matrix[i] = new double[n];
    		Temp[i] = new double[n];
    	}    
        fflush(stdin);
        printf("Enter matrix:\n");
        for (i=0; i<n; i++){
    		gets(temp);
            StringToArray(temp, Matrix[i], n);
            for (j=0; j<n; j++)
            	Temp[i][j] = Matrix[i][j];
    	}
    
        int rank = Matrix_Rank(Temp, n, n);
        for (i=0; i<n; i++) {
            det*=Temp[i][i];
        }
    
        if (fabs(det)<=0.000001) printf("\nDegenerate matrix!\n");
        else {
            Adjugate(Matrix, n);
            printf("\nInverse matrix:\n");
            for(i=0; i<n; i++) {
                for(j=0; j<n; j++){
                	if (fabs(Matrix[i][j])<=0.000001) 
                    	Matrix[i][j] = 0.0;
                    printf("%lf ", Matrix[i][j]);
                }
                printf("\n");
            }
            printf("\nAlternative (1/det * Adjugate matrix): \n");
            printf("1/det = 1/%g\n", det);
            printf("Adj matrix: \n");
            for(i=0; i<n; ++i) {
                for(j=0; j<n; j++){
                    Matrix[i][j]*=det;
                    if (fabs(Matrix[i][j])<=0.000001) 
                    	Matrix[i][j] = 0.0;
                    printf("%g ", Matrix[i][j]);
                }
                printf("\n");
            }
        }

        for (i=0; i<n; i++){
            if (Matrix[i]) delete[] Matrix[i];
            if (Temp[i]) delete[] Temp[i];
        }
		if (Matrix) delete[] Matrix;
		if (Temp) delete[] Temp;
    } else printf("\nERROR: zero or negative dimension.");

// INTERFACE PART
	Matrix_Submenu(h);
}

void MatrixProduct_Menu(HANDLE h){
	system("cls");
	DrawHorizontalMenu(h, 1);
// TECHNICAL PART
	printf("\n MATRIX MULTIPLICATION\n\n");
	int i = 0, j = 0;
	char temp[512];
	double **A, **B; int n = 0, m = 0, k = 0;
	printf("Enter A[NxM] size: ");
	fflush(stdin);
	scanf("%i %i", &n, &m);
	if (n>0 && m>0){
		printf("Enter K dimension for B[MxK] (enter 1 to multiply by vector): ");
		scanf("%i", &k);
		if (k>0){
			A = new double*[n]; B = new double*[m];
			for (i=0; i<n; i++){
				A[i] = new double[m];
			}
			for (i=0; i<m; i++){
				B[i] = new double[k];
			}
	
			fflush(stdin);
			printf("Enter matrix A[%ix%i]:\n", n, m);
			for (i=0; i<n; i++){
				gets(temp);
				StringToArray(temp, A[i], m);
			}
			printf("\nEnter matrix B[%ix%i]:\n", m, k);
			for (i=0; i<m; i++){
				gets(temp);
				StringToArray(temp, B[i], k);
			}
	
			double **C = Multiply_Matrix(A, B, n, m, k);
	
			printf("\nA*B =\n");
			for (i=0; i<n; i++) {
	        	for (int j=0; j<k; j++) {
	        		if (fabs(C[i][j])<=0.0000001) C[i][j]=0.0;
	            	printf("%g ", C[i][j]);
	        	}
	        	printf("\n");
	    	}

	    	for (i=0; i<n; i++){
				if (A[i]) delete[] A[i];
				if (C[i]) delete[] C[i];
			}
			for (i=0; i<m; i++){
				if (B[i]) delete[] B[i];
			}
			if (A) delete[] A; if (B) delete[] B; if (C) delete[] C;
		} else printf("\nERROR: zero or negative dimension.");
	} else printf("\nERROR: zero or negative dimension.");
// INTERFACE PART
	Matrix_Submenu(h);
}

void MatrixCalculator_Menu(HANDLE h){
	system("cls");
	DrawHorizontalMenu(h, 1);
// TECHNICAL PART
	printf("\n SIMPLE MATRIX CALCULATIONS (addition, substraction)\n\n");
	printf("You can calculate a*X + b*Y (X and Y are matrices, a and b - real numbers)\n");
	int i = 0, j=0;
	char temp[512];
	double a = 1.0, b = 1.0;
	double **X, **Y; int n = 0, m = 0;
	printf("Enter X[NxM] and Y[NxM] size: ");
	fflush(stdin);
	scanf("%i %i", &n, &m);
	if (n>0 && m>0){
		X = new double*[n]; Y = new double*[n];
	
		for (i=0; i<n; i++){
			X[i] = new double[m];
		}
		for (i=0; i<n; i++){
			Y[i] = new double[m];
		}
	
		fflush(stdin);
		printf("Enter matrix X[%ix%i]:\n", n, m);
		for (i=0; i<n; i++){
			gets(temp);
			StringToArray(temp, X[i], m);
		}
		printf("\nEnter matrix Y[%ix%i]:\n", n, m);
		for (i=0; i<n; i++){
			gets(temp);
			StringToArray(temp, Y[i], m);
		}
		printf("\nEnter a and b: ");
		scanf("%lf %lf", &a, &b);

		printf("\n%g*X + %g*Y =\n", a, b);
		for (i=0; i<n; i++) {
	        for (int j=0; j<m; j++) {
	            printf("%g ", a*X[i][j]+b*Y[i][j]);
	        }
	        printf("\n");
	    }

	    for (i=0; i<n; i++){
			if (X[i]) delete[] X[i];
			if (Y[i]) delete[] Y[i];
		}
		if (X) delete[] X; if (Y) delete[] Y;
	} else printf("\nERROR: zero or negative dimension.");

// INTERFACE PART
	Matrix_Submenu(h);
}

void MatrixPower_Menu(HANDLE h){
	system("cls");
	DrawHorizontalMenu(h, 1);
// TECHNICAL PART
	printf("\n MATRIX POWER CALCULATOR\n\n");
	int i = 0, j = 0, n = 0, p = 1;
	double det = 1.0;
	double **Matrix = NULL;
	char temp[512];
	printf("Enter dimension: ");
	fflush(stdin);
    scanf("%i", &n);
    if (n>0) {
    	Matrix = new double*[n];
    	for (i=0; i<n; i++) {
        	Matrix[i] = new double[n];
    	}

    	fflush(stdin);
    
    	printf("Enter matrix:\n");
        for (i=0; i<n; i++){
    		gets(temp);
            StringToArray(temp, Matrix[i], n);
    	}
    	printf("\nEnter power: ");
    	scanf("%i", &p);
    	if (p==0){
    		printf("\nA^0 =\n");
    		for (i=0; i<n; i++){
    			for (j=0; j<n; j++){
    				if (i==j) printf("1 ");
    				else printf("0 ");
    			}
    			printf("\n");
    		}	
    	}
    	else {
    		double **Temp_Matrix = new double*[n];
    		for (i=0; i<n; i++){
    			Temp_Matrix[i] = new double[n];
    			for (j=0; j<n; j++){
    				Temp_Matrix[i][j] = Matrix[i][j];
    			}
    		}
    		int rank = Matrix_Rank(Temp_Matrix, n, n);
    		for (i=0; i<n; i++) {
        		det*=Temp_Matrix[i][i];
    		}
    		if (fabs(det)<=0.000001 && p<0) printf("\nDegenerate matrix!\n");
    		else {
        		double **Res = Power_Matrix(Matrix, n, p);

        		printf("\nA^%i =\n", p);
        		for (i=0; i<n; i++){
        			for (j=0; j<n; j++){
        				printf("%g ", Res[i][j]);
        			}
        			printf("\n");
        		}
        	}
    	}

        for (i=0; i<n; i++) {
        	if (Matrix[i]) delete[] Matrix[i];
    	}
    	if (Matrix) delete[] Matrix;
    } else printf("\nERROR: zero or negative dimension.");

// INTERFACE PART
	Matrix_Submenu(h);
}

void MatrixUPT_Menu(HANDLE h){
	system("cls");
	DrawHorizontalMenu(h, 1);
// TECHNICAL PART
	printf("\n UPPER TRIANGULAR FORM CALCULATOR\n\n");
	int i = 0, j = 0, n = 0, m = 0;
	double **Matrix = NULL;
	double d;
	char temp[512];
	printf("Enter dimension NxM: ");
	fflush(stdin);
    scanf("%i %i", &n, &m);
    if (n>0 && m>0) {
    	Matrix = new double*[n];
    
        for (i=0; i<n; i++) {
            Matrix[i] = new double[m];
        }
    
        fflush(stdin);
        printf("Enter matrix:\n");
        for (i=0; i<n; i++){
    		gets(temp);
            StringToArray(temp, Matrix[i], m);
    	}
    
    	int rank = Matrix_Rank(Matrix, n, m);
    
    	printf("\nUpper triangular form:\n");
    	for (i=0; i<n; i++){
    		d = Matrix[i][i];
    		if (fabs(d)<=0.000001){
    			for (j=0; j<n; j++){
    				printf("%g ", Matrix[i][j]);
    			}
    		}
    		else {
    			for (j=0; j<n; j++){
    				Matrix[i][j]=Matrix[i][j]/d;
    				if (fabs(Matrix[i][j])<=0.000001) Matrix[i][j]=0.0;
    				printf("%g ", Matrix[i][j]);
    			}
    		}
    		printf("\n");
    	}

    	for (i=0; i<n; i++) {
            if (Matrix[i]) delete[] Matrix[i];
        }
        if (Matrix) delete[] Matrix;
    } else printf("\nERROR: zero or negative dimension.");

// INTERFACE PART
	Matrix_Submenu(h);
}

void MatrixTrace_Menu(HANDLE h){
	system("cls");
	DrawHorizontalMenu(h, 1);
// TECHNICAL PART
	printf("\n MATRIX TRACE CALCULATOR\n\n");
	int i = 0, j = 0, n = 0, m = 0, min = 0;
	double **Matrix = NULL;
	double trace=0.0;
	char temp[512];
	printf("Enter dimension NxM: ");
	fflush(stdin);
    scanf("%i %i", &n, &m);
    if (n>0 && m>0) {
    	Matrix = new double*[n];
    
        for (i=0; i<n; i++) {
            Matrix[i] = new double[m];
        }
    
        fflush(stdin);
        printf("Enter matrix:\n");
        for (i=0; i<n; i++){
    		gets(temp);
            StringToArray(temp, Matrix[i], m);
    	}
    	
    	if (n<m) min=n; else min=m;
    	for (i=0; i<min; i++){
    		trace+=Matrix[i][i];
    	}

    	printf("\nTrace = %g\n", trace);

    	for (i=0; i<n; i++) {
            if (Matrix[i]) delete[] Matrix[i];
        }
        if (Matrix) delete[] Matrix;
    } else printf("\nERROR: zero or negative dimension.");

// INTERFACE PART
	Matrix_Submenu(h);
}

void AboutText(HANDLE h){
	printf("\n Welcome to vector and matrix calculator!\n");

	SetConsoleTextAttribute(h, CYAN_BG+YELLOW);
	printf("\n HELP:\n");
	SetConsoleTextAttribute(h, CYAN_BG+WHITE);
	printf(" Use LEFT and RIGHT keys to navigate the horizontal menu, ENTER key to select menu item.\n"
		   " While in \"Vectors\" or \"Matrices\", select menu items using Num keys.\n"
	   	   " Use ESC key to return to main menu from operation menu and to exit program while in main menu.\n"
		   " Vectors should be entered in one line, coordinates separated by space.\n\n"
		   " Matrices are entered in the same way: line by line, numbers separated by space.\n"
		   " Real numbers with fractional part are enterted with dot: 3.14, but not 3,14.\n"
		   " Default Windows clipboard works in console.\n"
		   " You can select result vector or matrix, copy and paste it with right mouse click (on Windows 10).\n"
		   " Copy-paste should work on earlier Windows versions with Shift-Ctrl-C and Shift-Ctrl-V combinations.\n");

	SetConsoleTextAttribute(h, CYAN_BG+YELLOW);
	printf("\n\n SOME INFO ABOUT ALGORITHMS USED IN MATRICES PART:\n");
	SetConsoleTextAttribute(h, CYAN_BG+WHITE);
	printf(" Matrix rank is calculated by transforming matrix to an upper triangular one.\n"
		   " After transformation, number of zero rows is counted and substracted from number of all rows.\n"
		   " Determinant calculator uses the same algorithm.\n"
		   " Determinant of a triangular matrix equals the product of the diagonal entries.\n"
		   " Inverse matrix and negative integer powers of matrices are calculated using Adjugate-matrix algorithm.");

	printf("\n\n\n This program was made by Oleksii Galganov as a Programming and Algorithmic Languages course project.\n");
	printf(" Igor Sikorsky Kyiv Polytechnic Institute (KPI), Institute for Applied System Analysis (IASA), group KA-81, 2019.\n\n");
	printf(" Contacts: telegram @Yalikesifulei, email alex.galganov@gmail.com\n");
}

void EasterEgg(){
	printf("\n  ________        __          \n |__    __|      /  \\        \n    |  |        / /\\ \\");
	printf("\n    |  |       / /__\\ \\     \n  __|  |__    / ______ \\     \n |________|  /_/      \\_\\");
	printf("\n     ______  __        __         \n    /   __/  \\ \\______/ /              \n    \\  \\      \\  ____  /");
	printf("\n     \\  \\      \\ \\  / /           \n   ___\\  \\      \\ \\/ /             \n  /______/       \\__/\n");
}