#include <locale>
#include <iostream>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
int n=8,variant=26;

void GMetInFile()
{
	ofstream fout("gauss.txt", ios_base::out | ios_base::trunc);
	fout.precision(5);
	fout<<fixed;
	int i, j, m, k;	double a[n][n+1], b[n][n+1],tmp,sum = 0;
	double *x = new double[n+1]; double *norma = new double[n];
	int znak=1;
	
	fout<<"Double\tN = "<<n<<"\tVariant:  "<<variant<<endl<<"\n";
	for(i=0; i<n;++i)
	  for (j=0;j<n;++j){
	   a[i][j] = (double)variant/10.0 + 1.1*( (double)(j+1)-(double)(i+1) )-cos( (double)(i+1)-(double)(j+1) );
	   b[i][j] = a[i][j];
	  }	  
	for(i = 0; i < n; ++i){
		a[i][i] += 1;	
		b[i][i] += 1;	
	}	
	for(i = 0; i < n; ++i){
		a[i][n] = (1/(double)variant) - sin( (double)(i+1)*(double)variant );
		b[i][n] = a[i][n];
	}	
	for(i = 0; i < n; ++i){
	  for (j = 0;j < n+1; ++j){
	    fout<<setw(11)<<fixed<<a[i][j]<<"\t";
	  }
	  fout<<endl;
	 }	 
    for (k = 0; k<n-1; k++)  {		
        tmp = abs((a[k][k]));
        i = k;
        for(m = k+1; m<n; m++)
            if(abs(double(a[m][k]))>tmp){
                i = m;
                tmp = abs(a[m][k]);
            } 
            if (tmp == 0){
                fout<<"Система не имеет решений"<<endl;
            }
 
            if (i != k) {
                for (j = k; j < n+1; j++)
                {                    
					swap( a[k][j], a[i][j] );
                }
				znak=-znak;
            }            
           
				for(i = k+1;i < n; ++i)
				for (j = k+1; j < n+1; j++)	{
					a[i][j] = a[i][j] - a[i][k] * a[k][j] / a[k][k];
				}	
    }	
	for(i = 0; i < n; ++i) {
	  for (j = 0;j < n+1; ++j) {
	    if (i > j) 
			a[i][j] = 0;
	  }	  
	 }	
	for(i = n-1;i > -1; --i){		
		sum = 0;
		for(j = i+1;j < n; ++j)			
			sum += a[i][j] * x[j];
		x[i] = (a[i][n] - sum) / a[i][i];
	}	
    fout<<endl;
	
	for (j = 0;j < n; ++j){
		sum = 0;
		for(i = 0; i < n; ++i)
		sum +=b[j][i]*x[i];
		norma[j]=sum-b[j][n];
	}
	sum=0;
	for (i=1;i<n;++i){
		sum +=( norma[i]*norma[i]);
	}
	double fas=sqrt(sum);

	sum = 1;
	for(i = 0; i < n; ++i){
	sum *=a[i][i];
		  for (j = 0; j < n+1; ++j){
		    if (i>j){ fout <<fixed<<setw(11)<<"\t";
		      continue;}
			fout<<fixed<<setw(11)<<a[i][j]<<"\t";		
		  }
		  fout<<endl;	 
	  }
	  sum=sum*znak;		 
	 fout<<scientific<<"Норма: "<<fas<<"\tОпределитель = "<<sum<<"\tРешение системы:"<<endl; 
	 int cx = 0;
	 fout.precision(16);
    for (i = 0; i < n; i++){		
		fout<<scientific<<x[i]<<"\n";
    }	
	fout.close();	  	
}

void GMetFloat()
{	
	int start_time =  clock();	

	float **a = new float*[n];
	float **b = new float*[n];	
	float *x = new float[n+1];
	float *norma = new float[n];
	int znak=1;
	int i, j, m, k;
	float tmp,sum = 0;
	cout<<"Float\tN = "<<n<<"\tВариант:  "<<variant<<endl;
	for (int i = 0; i < n; i++)
	{
		a[i] = new  float[n+1];		b[i] = new  float[n+1];
	}
	for(i=0; i<n;++i)
	  for (j=0;j<n;++j) {
	   a[i][j] = (float)variant/10.0 + 1.1*( (float)(j+1)-(float)(i+1) )-cos( (float)(i+1)-(float)(j+1) );
	   b[i][j] = a[i][j];
	  }
	for(i = 0; i < n; ++i){
		a[i][i] += 1;	
		b[i][i] += 1;	
	}	
	for(i = 0; i < n; ++i){
		a[i][n] =(1/(float)variant)- sin( (float)(i+1)*(float)variant );
		b[i][n] = a[i][n];
	}	
    for (k = 0; k<n-1; k++){		
        tmp = abs((a[k][k]));
        i = k;
        for(m = k+1; m<n; m++)
            if(abs(float(a[m][k]))>tmp) {
                i = m;
                tmp = abs(a[m][k]);
            } 
            if (tmp == 0)  {
                cout<<"Система не имеет решений"<<endl;
            }
 
            if (i != k) {
                for (j = k; j < n+1; j++){                    
					swap( a[k][j], a[i][j] );
                }
				znak=-znak;
            }  
				for(i = k+1;i < n; ++i)
				for (j = k+1; j < n+1; j++)	{
					a[i][j] = a[i][j] - a[i][k] * a[k][j] / a[k][k];
				}	
    }	
	 for(i = 0; i < n; ++i)	{
	  for (j = 0;j < n+1; ++j) {
	    if (i > j) 
			a[i][j] = 0;
	  }	  
	 }	
	for(i = n-1;i > -1; --i){		
		sum = 0;
		for(j = i+1;j < n; ++j)			
			sum += a[i][j] * x[j];
		x[i] = (a[i][n] - sum) / a[i][i];
	}		
	for (j = 0;j < n; ++j){
		sum = 0;
		for(i = 0; i < n; ++i)
		sum +=b[j][i]*x[i];
		norma[j]=sum-b[j][n];
	}
	sum=0;
	for (i=1;i<n;++i){
		sum +=( norma[i]*norma[i]);
	}
	float nrm=sqrt(sum);
	sum = 1;
	for(i = 0; i < n; ++i) {
		sum *=a[i][i];
	 }
	 sum=sum*znak;	 
	 cout<<scientific<<"Норма: "<<nrm<<"\tОпределитель: "<<sum<<endl; 
	
	int end_time = clock();	
	int search_time = end_time - start_time;
	cout<< "\nВремя работы: "<<fixed<<(search_time) / CLOCKS_PER_SEC<<endl;
	cout<<endl;	
	
   cout<<"Введите интервал знaчений(левую и правую границы)\n";
	 int aa,bb;	 
	 cout<<"Enter a: ";	 
	 cin>>aa;
	 cout<<"Enter b: ";
	 cin>>bb;
	 
    for (i = aa-1; i <bb ; i++)   {			
         cout<< i+1 << ": "<<scientific<<x[i]<<"\n";			
        	
    }	cout<<endl;		
	
	 
	
	  	
}

void GMetDouble()
{	
	int start_time = clock();	
	
	double **a = new double*[n];
	double **b = new double*[n];	
	double *x = new double[n+1];
	double *norma = new double[n];
	int znak=1;
	int i, j, m, k;
	double tmp,sum = 0;
	cout<<"Double\tN = "<<n<<"\tVariant:  "<<variant<<endl;
	for (int i = 0; i < n; i++)
	{
		a[i] = new  double[n+1];		b[i] = new  double[n+1];
	}
	for(i=0; i<n;++i)
	  for (j=0;j<n;++j) {
	   a[i][j] = (double)variant/10.0 + 1.1*( (double)(j+1)-(double)(i+1) )-cos( (double)(i+1)-(double)(j+1) );
	   b[i][j] = a[i][j];
	  }
	for(i = 0; i < n; ++i){
		a[i][i] += 1;	
		b[i][i] += 1;	
	}	
	for(i = 0; i < n; ++i){
		a[i][n] =(1/(double)variant)- sin( (double)(i+1)*(double)variant );
		b[i][n] = a[i][n];
	}	
    for (k = 0; k<n-1; k++){		
        tmp = abs((a[k][k]));
        i = k;
        for(m = k+1; m<n; m++)
            if(abs(double(a[m][k]))>tmp) {
                i = m;
                tmp = abs(a[m][k]);
            } 
            if (tmp == 0)  {
                cout<<"Система не имеет решений"<<endl;
            }
 
            if (i != k) {
                for (j = k; j < n+1; j++){                    
					swap( a[k][j], a[i][j] );
                }
				znak=-znak;
            }  
				for(i = k+1;i < n; ++i)
				for (j = k+1; j < n+1; j++)	{
					a[i][j] = a[i][j] - a[i][k] * a[k][j] / a[k][k];
				}	
    }	
	 for(i = 0; i < n; ++i)	{
	  for (j = 0;j < n+1; ++j) {
	    if (i > j) 
			a[i][j] = 0;
	  }	  
	 }	
	for(i = n-1;i > -1; --i){		
		sum = 0;
		for(j = i+1;j < n; ++j)			
			sum += a[i][j] * x[j];
		x[i] = (a[i][n] - sum) / a[i][i];
	}		
	for (j = 0;j < n; ++j){
		sum = 0;
		for(i = 0; i < n; ++i)
		sum +=b[j][i]*x[i];
		norma[j]=sum-b[j][n];
	}
	sum=0;
	for (i=1;i<n;++i){
		sum +=( norma[i]*norma[i]);
	}
	double nrm=sqrt(sum);
	sum = 1;
	for(i = 0; i < n; ++i) {
		sum *=a[i][i];
	 }
	 sum=sum*znak;	 
	 cout<<scientific<<"Норма: "<<nrm<<"\tОпределитель: "<<sum<<endl; 
	 
	int end_time = clock();	
	int search_time = end_time - start_time;
	cout<< "\nВремя работы: "<<fixed<<(search_time) / CLOCKS_PER_SEC<<endl;
	cout<<endl;
	 
   cout<<"Введите интервал знaчений(левую и правую границы)\n";
	 int aa,bb;	 
	 cout<<"Enter a: ";	 
	 cin>>aa;
	 cout<<"Enter b: ";
	 cin>>bb;
	 
    for (i = aa-1; i <bb ; i++)   {			
         cout<< i+1 << ": "<<scientific<<x[i]<<"\n";			
        	
    }	cout<<endl;		
	
	
	  	
}
void GMetLdouble()
{
	int start_time = clock();	
	
	int i, j, m, k;
	long double **a = new long double*[n];
	long double **b = new long double*[n];
	long double tmp,sum = 0;
	long double *x = new long double[n+1];
	long double *norma = new long double[n];
	int znak=1;
	cout<<"Long double\tN = "<<n<<"\tVariant:  "<<variant<<endl;
	for (int i = 0; i < n; i++)
	{
		a[i] = new long double[n+1];		b[i] = new long double[n+1];
	}
	for(i=0; i<n;++i)
	  for (j=0;j<n;++j)
	  {
	   a[i][j] = (long double)variant/10.0 + 1.1*( (long double)(j+1)-(long double)(i+1) )-cos( (long double)(i+1)-(long double)(j+1) );
	   b[i][j] = a[i][j];
	  }
	  
	for(i = 0; i < n; ++i)
	{
		a[i][i] += 1;	
		b[i][i] += 1;	
	}
	
	for(i = 0; i < n; ++i){
		a[i][n] =(1/(long double)variant)- sin( (long double)(i+1)*(long double)variant );
		b[i][n] = a[i][n];
	}		
    for (k = 0; k<n-1; k++)  {		
        tmp = abs((a[k][k]));
        i = k;
        for(m = k+1; m<n; m++)
            if(abs(a[m][k])>tmp) {
                i = m;
                tmp = abs(a[m][k]);
            } 
            if (tmp == 0)  {
                cout<<"Система не имеет решения"<<endl;
            } 
            if (i != k){
                for (j = k; j < n+1; j++){                    
					swap( a[k][j], a[i][j] );
                }
				znak=-znak;
            }                       
				for(i = k+1;i < n; ++i)
				for (j = k+1; j < n+1; j++){
					a[i][j] = a[i][j] - a[i][k] * a[k][j] / a[k][k];
				}	
    }
	 for(i = 0; i < n; ++i)	{
	  for (j = 0;j < n+1; ++j) {
	    if (i > j) 
			a[i][j] = 0;
	  }	  
	 }
	
	for(i = n-1;i > -1; --i){		
		sum = 0;
		for(j = i+1;j < n; ++j)			
			sum += a[i][j] * x[j];
		x[i] = (a[i][n] - sum) / a[i][i];
	}		
	for (j = 0;j < n; ++j)	{
		sum = 0;
		for(i = 0; i < n; ++i)
		sum +=b[j][i]*x[i];
		norma[j]=sum-b[j][n];
	}
	sum=0;
	for (i=1;i<n;++i){
		sum +=( norma[i]*norma[i]);
	}
	double fas=sqrt(sum);

	sum = 1;
	for(i = 0; i < n; ++i) {
	sum *=a[i][i];
	}	 
	 sum=sum*znak;
	 cout<<scientific<<"Норма: "<<fas<<"\tОпределитель: "<<sum<<endl; 
	 
	 int end_time = clock();	
	int search_time = end_time - start_time;
	cout<< "\nВремя работы: "<<fixed<<(search_time) / CLOCKS_PER_SEC<<endl;
	cout<<endl;
	 
	 cout<<"Введите  интервал знaчений(левую и правую границы)\n";
	 int aa,bb;
	 cout<<"Enter a: ";	 
	 cin>>aa;
	 cout<<"Enter b: ";
	 cin>>bb;
    for (i = aa-1; i <bb ; i++)
    {			
        cout<< i+1 << ": "<<scientific<<x[i]<<"\n";		
        	
    }	cout<<endl;	 	
	
}

 
int main()
{   
	system("color F0");
	setlocale(LC_ALL, "Russian");
	GMetInFile();
	n=1000;
	for (int i=1;i<3;++i)
	{
	GMetFloat();
	cout<<endl; 
	cout<<endl;
	
	GMetDouble();
	cout<<endl; 
	cout<<endl; 
		
	GMetLdouble();
	
	cout<<endl; 
	cout<<endl; 
	n=2000;
	}
	
	return 0;
}
