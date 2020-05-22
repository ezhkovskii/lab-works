#include <iostream>
#include <cmath>
#include<iomanip>
#include <ctime>

using namespace std;

/*Параметры: Массив, Размер массива. Возвращает заполненный массив*/
void zapolnenie_massiva(double *A, int N){
	double V = 26.0; //Вариант
    for (int i = 0; i < N; i++){
       if ((i+1)%2==0){
       		A[i] = (1/(i+1)) * sin(V + (i+1));
       } else {
           A[i] = ((i+1) + 1) * cos(V + (i+1));
       }
    }
}

/*Параметры: Массив, Размер массива. Вывод массива на экран*/
void vyvod_massiva(double *A, int N){
    for (int i = 0; i < N; i++){
        cout << fixed << A[i] << setw(4) << " ";
    }
    cout << endl;
}

/*Параметры: Массив, Размер массива, Флаг Обратный порядок.
Считает сумму элементов массива нормальном и обратном порядке и возвращает эту сумму*/
double summa(double *A, int N, bool obratno){
    double summa = 0;
    if (obratno != true){
        for (int i = 0; i < N; i++){
            summa = summa + A[i]; 
        }
    }else{
       for (int i = N-1; i >= 0; i--){
            summa = summa + A[i]; 
        } 
    }
    return summa;
}

/*Параметры: Массив, Размер массива. Сортировка массива методом пузырька по возрастанию модулей*/
void sort(double *A, int size){
    // Для всех элементов
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = (size - 1); j > i; j--) 
    {
      if (abs(A[j - 1]) > abs(A[j]))
      {
        double temp = A[j - 1]; 
        A[j - 1] = A[j];
        A[j] = temp;
      }
    }
  }
}

int main()
{
	system("color F0");
	setlocale(LC_ALL, "Russian");
    int N;
    cout<<"Задание №1" << endl;
    cout<<"Введите количество элементов массива: ";
    cin >> N;
    
     /*Для N = 10 вывод исходного, сортированного массива и сумм*/
    if (N == 10) {
        double S1, S2, S3;
        double *A = new double[N];

        zapolnenie_massiva(A, N);
        cout << "Вывод исходного массива: " << endl;
        vyvod_massiva(A, N);
        S1 = summa(A, N, false);
        sort(A, N);
        S2 = summa(A, N, false);
        S3 = summa(A, N, true);
        cout << "Вывод сортированного массива: " << endl;
        vyvod_massiva(A, N);
        cout << "Вывод трех сумм: " << endl;
        cout << fixed << "S1: " << S1 << endl;
        cout << fixed << "S2: " << S2 << endl;
        cout << fixed << "S3: " << S3 << endl;
        
        delete []A;
    }
    
    if (N == 100000 || N == 200000){
    	
    	/*FLOAT*/
    	unsigned int start_time =  clock();
        cout << endl << "Одинарная точность (float): " << endl;
        float S1, S2, S3 = 0.0;
        float *A = new float[N];
        float V = 26.0; //Вариант
        
        //Заполнение массива
        cout << "Заполнение... ";
        for (int i = 0; i < N; i++){
            if ((i+1)%2==0){
            	A[i] = (1/(i+1)) * sin(V + (i+1));
        } else {
                A[i] = ((i+1) + 1) * cos(V + (i+1));
            }
        }
        cout << "Готово." << endl;
        
        //Сумма S1 для float
        cout << "Сумма S1...";
        for (int i = 0; i < N; i++){
            S1 = S1 + A[i]; 
        }
        cout << "Готово." << endl;
        
        //Сортировка
        cout << "Сортировка...";
        for (int i = 0; i < N - 1; i++){
            for (int j = (N - 1); j > i; j--){ 
                if (abs(A[j - 1]) > abs(A[j])){ 
                    float temp = A[j - 1]; 
                    A[j - 1] = A[j];
                    A[j] = temp;
                }
            }
        }
        cout << "Готово." << endl;
        
        //Сумма S2 для float
        cout << "Сумма S2...";
        for (int i = 0; i < N; i++){
            S2 = S2 + A[i]; 
        }
        cout << "Готово." << endl;
        
        //Сумма S3 для float
        cout << "Сумма S3...";
        for (int i = N-1; i >= 0; i--){
            S3 = S3 + A[i]; 
        }
        cout << "Готово." << endl;
        
        cout << "Вывод сумм для float: " << endl;
        cout << fixed << "S1: " << S1 << endl;
        cout << fixed << "S2: " << S2 << endl;
        cout << fixed << "S3: " << S3 << endl;
    
        unsigned int end_time = clock();
        unsigned int search_time = (end_time - start_time) / CLOCKS_PER_SEC;
        cout << "Время работы float: " << search_time << " с. " << endl << endl;
        
        delete []A;
		/*____________________________________________________________________
		DOUBLE*/
		start_time =  clock();
        cout << "Двойная точность (double): " << endl;
        double dS1, dS2, dS3 = 0.0;
        double *dA = new double[N];
    	double dV = 26.0; //Вариант
        
        //Заполнение массива
        cout << "Заполнение... ";
        for (int i = 0; i < N; i++){
            if ((i+1)%2==0){
                dA[i] = (1/(i+1)) * sin(dV + (i+1));
        } else {
               dA[i] = ((i+1) + 1) * cos(dV + (i+1));
            }
        }
        cout << "Готово." << endl;
        
        //Сумма S1 для double
        cout << "Сумма S1...";
        for (int i = 0; i < N; i++){
            dS1 = dS1 + dA[i]; 
        }
        cout << "Готово." << endl;
        
        //Сортировка
        cout << "Сортировка...";
        for (int i = 0; i < N - 1; i++){
            for (int j = (N - 1); j > i; j--){ 
                if (abs(dA[j - 1]) > abs(dA[j])){ 
                    double dtemp = dA[j - 1]; 
                    dA[j - 1] = dA[j];
                    dA[j] = dtemp;
                }
            }
        }
        cout << "Готово." << endl;
        
        //Сумма S2 для double
        cout << "Сумма S2...";
        for (int i = 0; i < N; i++){
            dS2 = dS2 + dA[i]; 
        }
        cout << "Готово." << endl;
        
        //Сумма S3 для double
        cout << "Сумма S3...";
        for (int i = N-1; i >= 0; i--){
            dS3 = dS3 + dA[i]; 
        }
        cout << "Готово." << endl;
        
        cout << "Вывод сумм для double: " << endl;
        cout << fixed << "S1: " << S1 << endl;
        cout << fixed << "S2: " << S2 << endl;
        cout << fixed << "S3: " << S3 << endl;
    
       	end_time = clock();
        search_time = (end_time - start_time) / CLOCKS_PER_SEC;
        cout << "Время работы double: " << search_time << " с. " << endl << endl;
        
        delete []dA;
        /*____________________________________________________________________
		LONG DOUBLE*/
		start_time =  clock();
        cout << "Расширенная точность (long double): " << endl;
        long double ldS1, ldS2, ldS3 = 0.0;
        long double *ldA = new long double[N];
        long double ldV = 26.0; //Вариант
        
        //Заполнение массива
        cout << "Заполнение... ";
        for (int i = 0; i < N; i++){
            if ((i+1)%2==0){
                ldA[i] = (1/(i+1)) * sin(ldV + (i+1));
        } else {
               ldA[i] = ((i+1) + 1) * cos(ldV + (i+1));
            }
        }
        cout << "Готово." << endl;
        
        //Сумма S1 для long double
        cout << "Сумма S1...";
        for (int i = 0; i < N; i++){
            ldS1 = ldS1 + ldA[i]; 
        }
        cout << "Готово." << endl;
        
        //Сортировка
        cout << "Сортировка...";
        for (int i = 0; i < N - 1; i++){
            for (int j = (N - 1); j > i; j--){ 
                if (abs(ldA[j - 1]) > abs(ldA[j])){ 
                    long double ldtemp = ldA[j - 1]; 
                    ldA[j - 1] = ldA[j];
                    ldA[j] = ldtemp;
                }
            }
        }
        cout << "Готово." << endl;
        
        //Сумма S2 для long double
        cout << "Сумма S2...";
        for (int i = 0; i < N; i++){
            ldS2 = ldS2 + ldA[i]; 
        }
        cout << "Готово." << endl;
        
        //Сумма S3 для long double
        cout << "Сумма S3...";
        for (int i = N-1; i >= 0; i--){
            ldS3 = ldS3 + ldA[i]; 
        }
        cout << "Готово." << endl;
        
        cout << "Вывод сумм для long double: " << endl;
        cout << fixed << "S1: " << S1 << endl;
        cout << fixed << "S2: " << S2 << endl;
        cout << fixed << "S3: " << S3 << endl;
    
       	end_time = clock();
        search_time = (end_time - start_time) / CLOCKS_PER_SEC;
        cout << "Время работы long double: " << search_time << " с. " << endl;
			 
        delete []ldA;         
    }
    
    return 0;
}
