#include <iostream>
#include <cmath>
#include<iomanip>
#include <ctime>

using namespace std;

/*���������: ������, ������ �������. ���������� ����������� ������*/
void zapolnenie_massiva(double *A, int N){
	double V = 26.0; //�������
    for (int i = 0; i < N; i++){
       if ((i+1)%2==0){
       		A[i] = (1/(i+1)) * sin(V + (i+1));
       } else {
           A[i] = ((i+1) + 1) * cos(V + (i+1));
       }
    }
}

/*���������: ������, ������ �������. ����� ������� �� �����*/
void vyvod_massiva(double *A, int N){
    for (int i = 0; i < N; i++){
        cout << fixed << A[i] << setw(4) << " ";
    }
    cout << endl;
}

/*���������: ������, ������ �������, ���� �������� �������.
������� ����� ��������� ������� ���������� � �������� ������� � ���������� ��� �����*/
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

/*���������: ������, ������ �������. ���������� ������� ������� �������� �� ����������� �������*/
void sort(double *A, int size){
    // ��� ���� ���������
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
    cout<<"������� �1" << endl;
    cout<<"������� ���������� ��������� �������: ";
    cin >> N;
    
     /*��� N = 10 ����� ���������, �������������� ������� � ����*/
    if (N == 10) {
        double S1, S2, S3;
        double *A = new double[N];

        zapolnenie_massiva(A, N);
        cout << "����� ��������� �������: " << endl;
        vyvod_massiva(A, N);
        S1 = summa(A, N, false);
        sort(A, N);
        S2 = summa(A, N, false);
        S3 = summa(A, N, true);
        cout << "����� �������������� �������: " << endl;
        vyvod_massiva(A, N);
        cout << "����� ���� ����: " << endl;
        cout << fixed << "S1: " << S1 << endl;
        cout << fixed << "S2: " << S2 << endl;
        cout << fixed << "S3: " << S3 << endl;
        
        delete []A;
    }
    
    if (N == 100000 || N == 200000){
    	
    	/*FLOAT*/
    	unsigned int start_time =  clock();
        cout << endl << "��������� �������� (float): " << endl;
        float S1, S2, S3 = 0.0;
        float *A = new float[N];
        float V = 26.0; //�������
        
        //���������� �������
        cout << "����������... ";
        for (int i = 0; i < N; i++){
            if ((i+1)%2==0){
            	A[i] = (1/(i+1)) * sin(V + (i+1));
        } else {
                A[i] = ((i+1) + 1) * cos(V + (i+1));
            }
        }
        cout << "������." << endl;
        
        //����� S1 ��� float
        cout << "����� S1...";
        for (int i = 0; i < N; i++){
            S1 = S1 + A[i]; 
        }
        cout << "������." << endl;
        
        //����������
        cout << "����������...";
        for (int i = 0; i < N - 1; i++){
            for (int j = (N - 1); j > i; j--){ 
                if (abs(A[j - 1]) > abs(A[j])){ 
                    float temp = A[j - 1]; 
                    A[j - 1] = A[j];
                    A[j] = temp;
                }
            }
        }
        cout << "������." << endl;
        
        //����� S2 ��� float
        cout << "����� S2...";
        for (int i = 0; i < N; i++){
            S2 = S2 + A[i]; 
        }
        cout << "������." << endl;
        
        //����� S3 ��� float
        cout << "����� S3...";
        for (int i = N-1; i >= 0; i--){
            S3 = S3 + A[i]; 
        }
        cout << "������." << endl;
        
        cout << "����� ���� ��� float: " << endl;
        cout << fixed << "S1: " << S1 << endl;
        cout << fixed << "S2: " << S2 << endl;
        cout << fixed << "S3: " << S3 << endl;
    
        unsigned int end_time = clock();
        unsigned int search_time = (end_time - start_time) / CLOCKS_PER_SEC;
        cout << "����� ������ float: " << search_time << " �. " << endl << endl;
        
        delete []A;
		/*____________________________________________________________________
		DOUBLE*/
		start_time =  clock();
        cout << "������� �������� (double): " << endl;
        double dS1, dS2, dS3 = 0.0;
        double *dA = new double[N];
    	double dV = 26.0; //�������
        
        //���������� �������
        cout << "����������... ";
        for (int i = 0; i < N; i++){
            if ((i+1)%2==0){
                dA[i] = (1/(i+1)) * sin(dV + (i+1));
        } else {
               dA[i] = ((i+1) + 1) * cos(dV + (i+1));
            }
        }
        cout << "������." << endl;
        
        //����� S1 ��� double
        cout << "����� S1...";
        for (int i = 0; i < N; i++){
            dS1 = dS1 + dA[i]; 
        }
        cout << "������." << endl;
        
        //����������
        cout << "����������...";
        for (int i = 0; i < N - 1; i++){
            for (int j = (N - 1); j > i; j--){ 
                if (abs(dA[j - 1]) > abs(dA[j])){ 
                    double dtemp = dA[j - 1]; 
                    dA[j - 1] = dA[j];
                    dA[j] = dtemp;
                }
            }
        }
        cout << "������." << endl;
        
        //����� S2 ��� double
        cout << "����� S2...";
        for (int i = 0; i < N; i++){
            dS2 = dS2 + dA[i]; 
        }
        cout << "������." << endl;
        
        //����� S3 ��� double
        cout << "����� S3...";
        for (int i = N-1; i >= 0; i--){
            dS3 = dS3 + dA[i]; 
        }
        cout << "������." << endl;
        
        cout << "����� ���� ��� double: " << endl;
        cout << fixed << "S1: " << S1 << endl;
        cout << fixed << "S2: " << S2 << endl;
        cout << fixed << "S3: " << S3 << endl;
    
       	end_time = clock();
        search_time = (end_time - start_time) / CLOCKS_PER_SEC;
        cout << "����� ������ double: " << search_time << " �. " << endl << endl;
        
        delete []dA;
        /*____________________________________________________________________
		LONG DOUBLE*/
		start_time =  clock();
        cout << "����������� �������� (long double): " << endl;
        long double ldS1, ldS2, ldS3 = 0.0;
        long double *ldA = new long double[N];
        long double ldV = 26.0; //�������
        
        //���������� �������
        cout << "����������... ";
        for (int i = 0; i < N; i++){
            if ((i+1)%2==0){
                ldA[i] = (1/(i+1)) * sin(ldV + (i+1));
        } else {
               ldA[i] = ((i+1) + 1) * cos(ldV + (i+1));
            }
        }
        cout << "������." << endl;
        
        //����� S1 ��� long double
        cout << "����� S1...";
        for (int i = 0; i < N; i++){
            ldS1 = ldS1 + ldA[i]; 
        }
        cout << "������." << endl;
        
        //����������
        cout << "����������...";
        for (int i = 0; i < N - 1; i++){
            for (int j = (N - 1); j > i; j--){ 
                if (abs(ldA[j - 1]) > abs(ldA[j])){ 
                    long double ldtemp = ldA[j - 1]; 
                    ldA[j - 1] = ldA[j];
                    ldA[j] = ldtemp;
                }
            }
        }
        cout << "������." << endl;
        
        //����� S2 ��� long double
        cout << "����� S2...";
        for (int i = 0; i < N; i++){
            ldS2 = ldS2 + ldA[i]; 
        }
        cout << "������." << endl;
        
        //����� S3 ��� long double
        cout << "����� S3...";
        for (int i = N-1; i >= 0; i--){
            ldS3 = ldS3 + ldA[i]; 
        }
        cout << "������." << endl;
        
        cout << "����� ���� ��� long double: " << endl;
        cout << fixed << "S1: " << S1 << endl;
        cout << fixed << "S2: " << S2 << endl;
        cout << fixed << "S3: " << S3 << endl;
    
       	end_time = clock();
        search_time = (end_time - start_time) / CLOCKS_PER_SEC;
        cout << "����� ������ long double: " << search_time << " �. " << endl;
			 
        delete []ldA;         
    }
    
    return 0;
}
