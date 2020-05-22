#include <iostream>
#include<iomanip>
#include <ctime>

using namespace std;

/*Параметры: размерность квадратной матрицы.
Процедура выводит суммы элементов матрицы по строкам
и считает время работы программы. Тип матрицы Float.*/
void FloatSummaElementovMatrixPoStrokam(int N){
	
	unsigned int start_time =  clock();
    
    float V = 26.0; 
    float S1 = 0.0;
    float **A = new float*[N];
    for(int i = 0; i < N; i++)
  	 	A[i] = new float[N];
  	 	  	
  	for(int i = 0; i < N; i++){
  		for(int j = 0; j < N; j++){
  			A[i][j] = (0.2*(i+1) - 0.3*(j+1))/V;	
  		}
  	}
  	 	
  	for(int i = 0; i < N; i++){
  		for(int j = 0; j < N; j++){
  			S1 = S1 + A[i][j];	
  		}
  	}
	
	cout << endl << fixed << "Сумма по строкам (float): " << S1 << endl;
	
	unsigned int end_time = clock();
    unsigned int search_time = (end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Время работы float: " << search_time << " с. " << endl << endl;
		 	
  	for(int i = 0; i < N; i++)
        delete [] A[i];
    delete [] A;	
}

/*Параметры: размерность квадратной матрицы.
Процедура выводит суммы элементов матрицы по строкам
и считает время работы программы. Тип матрицы double.*/
void DoubleSummaElementovMatrixPoStrokam(int N){
	
	unsigned int start_time =  clock();
    
    double V = 26.0; 
    double S1 = 0.0;
    double **A = new double*[N];
    for(int i = 0; i < N; i++)
  	 	A[i] = new double[N];
  	 	  	
  	for(int i = 0; i < N; i++){
  		for(int j = 0; j < N; j++){
  			A[i][j] = (0.2*(i+1) - 0.3*(j+1))/V;	
  		}
  	}
  	 	
  	for(int i = 0; i < N; i++){
  		for(int j = 0; j < N; j++){
  			S1 = S1 + A[i][j];	
  		}
  	}
  		
	cout << endl << fixed << "Сумма по строкам (double): " << S1 << endl;
	
	unsigned int end_time = clock();
    unsigned int search_time = (end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Время работы double: " << search_time << " с. " << endl << endl;
		 	
  	for(int i = 0; i < N; i++)
        delete [] A[i];
    delete [] A;	
}

/*Параметры: размерность квадратной матрицы.
Процедура выводит суммы элементов матрицы по строкам
и считает время работы программы. Тип матрицы long double.*/
void LongDoubleSummaElementovMatrixPoStrokam(int N){
	
	unsigned int start_time =  clock();
    
    long double V = 26.0; 
    long double S1 = 0.0;
    long double **A = new long double*[N];
    for(int i = 0; i < N; i++)
  	 	A[i] = new long double[N];
  	 	  	
  	for(int i = 0; i < N; i++){
  		for(int j = 0; j < N; j++){
  			A[i][j] = (0.2*(i+1) - 0.3*(j+1))/V;	
  		}
  	}
  	 	
  	for(int i = 0; i < N; i++){
  		for(int j = 0; j < N; j++){
  			S1 = S1 + A[i][j];	
  		}
  	}

	cout << endl << fixed << "Сумма по строкам (long double): " << S1 << endl;
	
	unsigned int end_time = clock();
    unsigned int search_time = (end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Время работы long double: " << search_time << " с. " << endl << endl;
		 	
  	for(int i = 0; i < N; i++)
        delete [] A[i];
    delete [] A;	
}


/*Параметры: размерность квадратной матрицы.
Процедура выводит суммы элементов матрицы по столбцам
и считает время работы программы. Тип матрицы Float.*/
void FloatSummaElementovMatrixPoStolbcam(int N){
	
	unsigned int start_time =  clock();
    
    float V = 26.0; 
    float S1 = 0.0;
    float **A = new float*[N];
    for(int i = 0; i < N; i++)
  	 	A[i] = new float[N];
  	 	  	
  	for(int i = 0; i < N; i++){
  		for(int j = 0; j < N; j++){
  			A[i][j] = (0.2*(i+1) - 0.3*(j+1))/V;	
  		}
  	}
  	 	
  	for(int i = 0; i < N; i++){
  		for(int j = 0; j < N; j++){
  			S1 = S1 + A[j][i];	
  		}
  	}
	
	cout << endl << fixed << "Сумма по столбцам (float): " << S1 << endl;
	
	unsigned int end_time = clock();
    unsigned int search_time = (end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Время работы float: " << search_time << " с. " << endl << endl;
		 	
  	for(int i = 0; i < N; i++)
        delete [] A[i];
    delete [] A;	
}

/*Параметры: размерность квадратной матрицы.
Процедура выводит суммы элементов матрицы по столбцам
и считает время работы программы. Тип матрицы double.*/
void DoubleSummaElementovMatrixPoStolbcam(int N){
	
	unsigned int start_time =  clock();
    
    double V = 26.0; 
    double S1 = 0.0;
    double **A = new double*[N];
    for(int i = 0; i < N; i++)
  	 	A[i] = new double[N];
  	 	  	
  	for(int i = 0; i < N; i++){
  		for(int j = 0; j < N; j++){
  			A[i][j] = (0.2*(i+1) - 0.3*(j+1))/V;	
  		}
  	}
  	 	
  	for(int i = 0; i < N; i++){
  		for(int j = 0; j < N; j++){
  			S1 = S1 + A[j][i];	
  		}
  	}
  		
	cout << endl << fixed << "Сумма по столбцам (double): " << S1 << endl;
	
	unsigned int end_time = clock();
    unsigned int search_time = (end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Время работы double: " << search_time << " с. " << endl << endl;
		 	
  	for(int i = 0; i < N; i++)
        delete [] A[i];
    delete [] A;	
}

/*Параметры: размерность квадратной матрицы.
Процедура выводит суммы элементов матрицы по столбцам
и считает время работы программы. Тип матрицы long double.*/
void LongDoubleSummaElementovMatrixPoStolbcam(int N){
	
	unsigned int start_time =  clock();
    
    long double V = 26.0; 
    long double S1 = 0.0;
    long double **A = new long double*[N];
    for(int i = 0; i < N; i++)
  	 	A[i] = new long double[N];
  	 	  	
  	for(int i = 0; i < N; i++){
  		for(int j = 0; j < N; j++){
  			A[i][j] = (0.2*(i+1) - 0.3*(j+1))/V;	
  		}
  	}
  	 	
  	for(int i = 0; i < N; i++){
  		for(int j = 0; j < N; j++){
  			S1 = S1 + A[j][i];	
  		}
  	}

	cout << endl << fixed << "Сумма по столбцам (long double): " << S1 << endl;
	
	unsigned int end_time = clock();
    unsigned int search_time = (end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Время работы long double: " << search_time << " с. " << endl << endl;
		 	
  	for(int i = 0; i < N; i++)
        delete [] A[i];
    delete [] A;	
}

int main()
{
	system("color F0");
	setlocale(LC_ALL, "Russian");
    int N;
    cout<<"Задание №2" << endl;
    cout<<"Введите размерность матрицы: ";
    cin >> N;
    
    FloatSummaElementovMatrixPoStrokam(N);
    DoubleSummaElementovMatrixPoStrokam(N);
    LongDoubleSummaElementovMatrixPoStrokam(N);
    
    FloatSummaElementovMatrixPoStolbcam(N);
    DoubleSummaElementovMatrixPoStolbcam(N);
    LongDoubleSummaElementovMatrixPoStolbcam(N);

    return 0;
}
