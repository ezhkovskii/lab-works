#include <iostream>
#include<iomanip>
#include <ctime>

using namespace std;

/*
Процедура заполняет матрицы А и В размерностью N,
Умножает матрицы А и В,
Считает сумму  элементов матрицы C и время работы программы. 
*/
void FloatMatrix(int N){
	
	unsigned int start_time =  clock();
    float V = 26.0; //Вариант
	float S = 0.0; 
    float **A = new float*[N];
    for(int i = 0; i < N; i++) A[i] = new float[N];
  	float **B = new float*[N];
  	for(int i = 0; i < N; i++) B[i] = new float[N];
  	float **C = new float*[N];
  	for(int i = 0; i < N; i++) C[i] = new float[N];
  	float **BT = new float*[N];
  	for(int i = 0; i < N; i++) BT[i] = new float[N];
  	 	  	
  	for(int i = 0; i < N; i++){
  		for(int j = 0; j < N; j++){
  			A[i][j] = (0.2*(i+1) - 0.3*(j+1))/V;
			B[i][j] = (0.7*(j+1) - 0.4*(i+1))/V;	
  		}
  	}
  	
  	for(int i = 0; i < N; i++){
  		for(int j = 0; j < N; j++){
			BT[j][i] = B[i][j];	
  		}
  	}
  	
  	for(int i = 0; i < N; i++)
	  	for(int j = 0; j < N; j++){
			C[i][j] = 0.0;
			for(int k = 0; k < N; k++)
				C[i][j] += (A[i][k] * BT[j][k]);
		}
    
    for(int i = 0; i < N; i++){
  		for(int j = 0; j < N; j++){
  			S = S + C[i][j];	
  		}
  	}
  	  	
  	cout << endl << fixed << "Сумма элементов матрицы C (float): " << S << endl;
  	
  	unsigned int end_time = clock();
    unsigned int search_time = (end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Время работы float: " << search_time << " с. " << endl << endl;
  	
  	for(int i = 0; i < N; i++)
        delete [] A[i];
    delete [] A;
    
    for(int i = 0; i < N; i++)
        delete [] B[i];
    delete [] B;
    
    for(int i = 0; i < N; i++)
        delete [] C[i];
    delete [] C;
	
	for(int i = 0; i < N; i++)
	        delete [] BT[i];
	    delete [] BT;	
}

void DoubleMatrix(int N){
	
	unsigned int start_time =  clock();
    double V = 26.0; //Вариант
	double S = 0.0; 
    double **A = new double*[N];
    for(int i = 0; i < N; i++) A[i] = new double[N];
  	double **B = new double*[N];
  	for(int i = 0; i < N; i++) B[i] = new double[N];
  	double **C = new double*[N];
  	for(int i = 0; i < N; i++) C[i] = new double[N];
  	float **BT = new float*[N];
  	for(int i = 0; i < N; i++) BT[i] = new float[N];
  	 	  	
  	for(int i = 0; i < N; i++){
  		for(int j = 0; j < N; j++){
  			A[i][j] = (0.2*(i+1) - 0.3*(j+1))/V;
			B[i][j] = (0.7*(j+1) - 0.4*(i+1))/V;	
  		}
  	}
  	
  	for(int i = 0; i < N; i++){
  		for(int j = 0; j < N; j++){
			BT[j][i] = B[i][j];	
  		}
  	}
  	
  	for(int i = 0; i < N; i++)
	  	for(int j = 0; j < N; j++){
			C[i][j] = 0.0;
			for(int k = 0; k < N; k++)
				C[i][j] += (A[i][k] * BT[j][k]);
		}
    
    for(int i = 0; i < N; i++){
  		for(int j = 0; j < N; j++){
  			S = S + C[i][j];	
  		}
  	}
  	  	
  	cout << endl << fixed << "Сумма элементов матрицы C (double): " << S << endl;
  	
  	unsigned int end_time = clock();
    unsigned int search_time = (end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Время работы double: " << search_time << " с. " << endl << endl;
  	
  	for(int i = 0; i < N; i++)
        delete [] A[i];
    delete [] A;
    
    for(int i = 0; i < N; i++)
        delete [] B[i];
    delete [] B;
    
    for(int i = 0; i < N; i++)
        delete [] C[i];
    delete [] C;
	
	for(int i = 0; i < N; i++)
	        delete [] BT[i];
	    delete [] BT;	
}

void LongDoubleMatrix(int N){
	
	unsigned int start_time =  clock();
    long double V = 26.0; //Вариант
	long double S = 0.0; 
    long double **A = new long double*[N];
    for(int i = 0; i < N; i++) A[i] = new long double[N];
  	long double **B = new long double*[N];
  	for(int i = 0; i < N; i++) B[i] = new long double[N];
  	long double **C = new long double*[N];
  	for(int i = 0; i < N; i++) C[i] = new long double[N];
  	float **BT = new float*[N];
  	for(int i = 0; i < N; i++) BT[i] = new float[N];
  	 	  	
  	for(int i = 0; i < N; i++){
  		for(int j = 0; j < N; j++){
  			A[i][j] = (0.2*(i+1) - 0.3*(j+1))/V;
			B[i][j] = (0.7*(j+1) - 0.4*(i+1))/V;	
  		}
  	}
  	
  	for(int i = 0; i < N; i++){
  		for(int j = 0; j < N; j++){
			BT[j][i] = B[i][j];	
  		}
  	}
  	
  	for(int i = 0; i < N; i++)
	  	for(int j = 0; j < N; j++){
			C[i][j] = 0.0;
			for(int k = 0; k < N; k++)
				C[i][j] += (A[i][k] * BT[j][k]);
		}
    
    for(int i = 0; i < N; i++){
  		for(int j = 0; j < N; j++){
  			S = S + C[i][j];	
  		}
  	}
  	  	
  	cout << endl << fixed << "Сумма элементов матрицы C (long double): " << S << endl;
  	
  	unsigned int end_time = clock();
    unsigned int search_time = (end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Время работы long double: " << search_time << " с. " << endl << endl;
  	
  	for(int i = 0; i < N; i++)
        delete [] A[i];
    delete [] A;
    
    for(int i = 0; i < N; i++)
        delete [] B[i];
    delete [] B;
    
    for(int i = 0; i < N; i++)
        delete [] C[i];
    delete [] C;
	
	for(int i = 0; i < N; i++)
	        delete [] BT[i];
	    delete [] BT;	
}

VyvodMatrix(float **A, int N){
	  	for(int i = 0; i < N; i++){
	  		for(int j = 0; j < N; j++){
	  			cout << fixed << A[i][j] << setw(3) << "\t";	
	  		}
	  		cout << endl;
	  	}
	cout << endl;		
}

int main()
{
	system("color F0");
	setlocale(LC_ALL, "Russian");
    int N;
    cout<<"Задание №4" << endl;
    cout<<"Введите размерность матриц: ";
    cin >> N;
    
    //При N = 4 выводит матрицы А, В и С
    if (N == 4){  
		float V = 26.0; //Вариант
	    float **A = new float*[N];
	    for(int i = 0; i < N; i++) A[i] = new float[N];
	  	float **B = new float*[N];
	  	for(int i = 0; i < N; i++) B[i] = new float[N];
	  	float **C = new float*[N];
	  	for(int i = 0; i < N; i++) C[i] = new float[N];
	  	float **BT = new float*[N];
  		for(int i = 0; i < N; i++) BT[i] = new float[N];
	  	 	  	
	  	for(int i = 0; i < N; i++){
	  		for(int j = 0; j < N; j++){
	  			A[i][j] = (0.2*(i+1) - 0.3*(j+1))/V;
				B[i][j] = (0.7*(j+1) - 0.4*(i+1))/V;	
	  		}
	  	}
	  	
	  	for(int i = 0; i < N; i++){
  			for(int j = 0; j < N; j++){
			BT[j][i] = B[i][j];	
  			}
  		}
	  	
	  	for(int i = 0; i < N; i++)
		  	for(int j = 0; j < N; j++){
				C[i][j] = 0.0;
				for(int k = 0; k < N; k++)
					C[i][j] += (A[i][k] * BT[j][k]);
			}
	    	  	
	  	cout << "Матрица A: " << endl;
	  	VyvodMatrix(A, N);
	  	
	  	cout << "Матрица В траспонированная: " << endl;
	  	VyvodMatrix(BT, N);
	  	
	  	cout << "Матрица C: " << endl;
	  	VyvodMatrix(C, N);
	  	
	  	for(int i = 0; i < N; i++)
	        delete [] A[i];
	    delete [] A;
	    
	    for(int i = 0; i < N; i++)
	        delete [] B[i];
	    delete [] B;
	    
	    for(int i = 0; i < N; i++)
	        delete [] C[i];
	    delete [] C;
	    
	    for(int i = 0; i < N; i++)
	        delete [] BT[i];
	    delete [] BT;
	  	
	  	return 0;
	}
    
	FloatMatrix(N);
	DoubleMatrix(N);
	LongDoubleMatrix(N);
	
    return 0;
}
