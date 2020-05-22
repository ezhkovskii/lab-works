#include <locale>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
int n=10; //количество уравнений
float v = 26.0; //вариант

void MetodProgonkiFileFloat()
{
	ofstream fout("Resultat (float).txt", ios_base::out | ios_base::trunc);
	int i, j,  k;
	float ymmm,sum = 0,m;
	float *a = new float[n+1];
	float *asave = new float[n+1];
	float *b = new float[n+1];
	float *bsave = new float[n+1];
	float *c = new float[n+1];
	float *csave = new float[n+1];
	float *d = new float[n+1];
	float *dsave = new float[n+1];
	float *xn = new float[n+1];
	float *nr = new float[n];
cout.precision(5);
	for( i=1;i<n;++i)
	{
		a[i]=0.3*sin(i+1)/v;
		asave[i]=0.3*sin(i+1)/v;
	}
	for( i=0;i<n-1;++i)
	{
		c[i]=0.4*cos(i+1)/v;
		csave[i]=0.4*cos(i+1)/v;
	}
	for( i=0;i<n;++i)
	{
		b[i]=10*v+(i+1)/v;
		bsave[i]=10*v+(i+1)/v;
		d[i]=1.3+(i+1)/v;
		dsave[i]=1.3+(i+1)/v;
	}
		fout<<fixed<<"A: "<<setw(11)<<right;
		for( i=1;i<n;++i)
		{
		 fout<<fixed<<setw(11)<<right<<a[i]<<"\t";
		}fout<<"\nB: ";
		for( i=0;i<n;++i)
		{
		 fout<<fixed<<setw(11)<<right<<b[i]<<"\t";
		}fout<<"\nC: ";
		for( i=0;i<n-1;++i)
		{
		 fout<<fixed<<setw(11)<<right<<c[i]<<"\t";
		}fout<<"\nD: ";
		for( i=0;i<n;++i)
		{
		 fout<<fixed<<setw(11)<<right<<d[i]<<"\t";
		}
		
		fout<<endl;
		fout<<"\nAlpha: ";
		for( i=0;i<n-1;++i)
		{
		 fout<<setw(11)<<right<<fixed<<-c[i]/b[i]<<"\t";
		}
		fout<<"\nBeta:  ";
		for( i=0;i<n;++i)
		{
		 fout<<setw(11)<<right<<fixed<<d[i]/b[i]<<"\t";
		}
		fout<<endl;

	for ( i = 1; i < n; i++)
	{
		m = a[i]/b[i-1];
		
		b[i] = b[i] - m*c[i-1];
		d[i] = d[i] - m*d[i-1];
	}

	xn[n-1] = d[n-1]/b[n-1];
	

	for ( i = n - 2; i >= 0; i--)
		xn[i]=(d[i]-c[i]*xn[i+1])/b[i];
	fout<<"\nX: ";
	for( i=0;i<n;++i)
	{
	 fout<<setw(11)<<right<<xn[i]<<"\t";
	}
	
	sum=0;
	for (i=0;i<n-1;++i)
	{
		nr[i]=dsave[i]-asave[i]*xn[i-1]-bsave[i]*xn[i]-csave[i]*xn[i+1];
		sum+=nr[i]*nr[i];
	}
	fout<<"\n|Ax-B| "<<scientific<<sqrt(sum); 
	fout.close();
}	

void MetodProgonkiFloat()
{	

	register int i, j,  k;
	float ymmm,sum = 0,m;
	float *a = new float[n+1];
	float *asave = new float[n+1];
	float *b = new float[n+1];
	float *bsave = new float[n+1];
	float *c = new float[n+1];
	float *csave = new float[n+1];
	float *d = new float[n+1];
	float *dsave = new float[n+1];
	float *xn = new float[n+1];
	float *nr = new float[n];
	for( i=1;i<n;++i)
	{
		a[i]=0.3*sin(i+1)/v;
		asave[i]=0.3*sin(i+1)/v;
	}
	for( i=0;i<n-1;++i)
	{
		c[i]=0.4*cos(i+1)/v;
		csave[i]=0.4*cos(i+1)/v;
	}
	for( i=0;i<n;++i)
	{
		b[i]=10*v+(i+1)/v;
		bsave[i]=10*v+(i+1)/v;
		d[i]=1.3+(i+1)/v;
		dsave[i]=1.3+(i+1)/v;
	}
	
	for ( i = 1; i < n; i++)
	{
		m = a[i]/b[i-1];
		
		b[i] = b[i] - m*c[i-1];
		d[i] = d[i] - m*d[i-1];
	}

	xn[n-1] = d[n-1]/b[n-1];
	

	for ( i = n - 2; i >= 0; i--)
		xn[i]=(d[i]-c[i]*xn[i+1])/b[i];
	

	sum=0.0;
	for (i=0;i<n-1;++i)
	{
		nr[i]=dsave[i]-asave[i]*xn[i-1]-bsave[i]*xn[i]-csave[i]*xn[i+1];
		sum+=nr[i]*nr[i];
	}
	cout<<"\n" << "Float: "<< endl;
	cout<<"\n" << "N = "<<n<<endl;
	cout<<"Невязка |Ax-B|: "<<scientific<<sqrt(sum)<<endl; 
	int aa,bb;
	cout<<"Введите диапазон x[a,b]: ";
	cout<<"\nEnter a: ";
	cin>>aa;
	cout<<"Enter b: ";
	cin>>bb;
	for(int i=aa-1;i<bb;++i) 
	{
	 cout<<setw(11)<<right<<fixed<< i+1 << ": " <<xn[i]<<"\n";
	 
	}
	
}

 
void MetodProgonkiFileDouble()
{
	ofstream fout("Resultat (double).txt", ios_base::out | ios_base::trunc);
	int i, j,  k;
	double ymmm,sum = 0,m;
	double *a = new double[n+1];
	double *asave = new double[n+1];
	double *b = new double[n+1];
	double *bsave = new double[n+1];
	double *c = new double[n+1];
	double *csave = new double[n+1];
	double *d = new double[n+1];
	double *dsave = new double[n+1];
	double *xn = new double[n+1];
	double *nr = new double[n+1];
cout.precision(5);
	for( i=1;i<n;++i)
	{
		a[i]=0.3*sin(i+1)/v;
		asave[i]=0.3*sin(i+1)/v;
	}
	for( i=0;i<n-1;++i)
	{
		c[i]=0.4*cos(i+1)/v;
		csave[i]=0.4*cos(i+1)/v;
	}
	for( i=0;i<n;++i)
	{
		b[i]=10*v+(i+1)/v;
		bsave[i]=10*v+(i+1)/v;
		d[i]=1.3+(i+1)/v;
		dsave[i]=1.3+(i+1)/v;
	}
		fout<<fixed<<"A: "<<setw(11)<<right;
		for( i=1;i<n;++i)
		{
		 fout<<fixed<<setw(11)<<right<<a[i]<<"\t";
		}fout<<"\nB: ";
		for( i=0;i<n;++i)
		{
		 fout<<fixed<<setw(11)<<right<<b[i]<<"\t";
		}fout<<"\nC: ";
		for( i=0;i<n-1;++i)
		{
		 fout<<fixed<<setw(11)<<right<<c[i]<<"\t";
		}fout<<"\nD: ";
		for( i=0;i<n;++i)
		{
		 fout<<fixed<<setw(11)<<right<<d[i]<<"\t";
		}
		
		fout<<endl;
		fout<<"\nAlpha: ";
		for( i=0;i<n-1;++i)
		{
		 fout<<setw(11)<<right<<fixed<<-c[i]/b[i]<<"\t";
		}
		fout<<"\nBeta:  ";
		for( i=0;i<n;++i)
		{
		 fout<<setw(11)<<right<<fixed<<d[i]/b[i]<<"\t";
		}
		fout<<endl;

	for ( i = 1; i < n; i++)
	{
		m = a[i]/b[i-1];
		
		b[i] = b[i] - m*c[i-1];
		d[i] = d[i] - m*d[i-1];
	}

	xn[n-1] = d[n-1]/b[n-1];
	

	for ( i = n - 2; i >= 0; i--)
		xn[i]=(d[i]-c[i]*xn[i+1])/b[i];
	fout<<"\nX: ";
	for( i=0;i<n;++i)
	{
	 fout<<setw(11)<<right<<xn[i]<<"\t";
	}
	
	sum=0;
	for (i=0;i<n-1;++i)
	{
		nr[i]=dsave[i]-asave[i]*xn[i-1]-bsave[i]*xn[i]-csave[i]*xn[i+1];
		sum+=nr[i]*nr[i];
	}
	fout<<"\n|Ax-B| "<<scientific<<sqrt(sum); 
	fout.close();
}	

void MetodProgonkiDouble()
{	

	register int i, j,  k;
	double ymmm,sum = 0,m;
	double *a = new double[n+1];
	double *asave = new double[n+1];
	double *b = new double[n+1];
	double *bsave = new double[n+1];
	double *c = new double[n+1];
	double *csave = new double[n+1];
	double *d = new double[n+1];
	double *dsave = new double[n+1];
	double *xn = new double[n+1];
	double *nr = new double[n+1];
	for( i=1;i<n;++i)
	{
		a[i]=0.3*sin(i+1)/v;
		asave[i]=0.3*sin(i+1)/v;
	}
	for( i=0;i<n-1;++i)
	{
		c[i]=0.4*cos(i+1)/v;
		csave[i]=0.4*cos(i+1)/v;
	}
	for( i=0;i<n;++i)
	{
		b[i]=10*v+(i+1)/v;
		bsave[i]=10*v+(i+1)/v;
		d[i]=1.3+(i+1)/v;
		dsave[i]=1.3+(i+1)/v;
	}
	
	for ( i = 1; i < n; i++)
	{
		m = a[i]/b[i-1];
		
		b[i] = b[i] - m*c[i-1];
		d[i] = d[i] - m*d[i-1];
	}

	xn[n-1] = d[n-1]/b[n-1];
	

	for ( i = n - 2; i >= 0; i--)
		xn[i]=(d[i]-c[i]*xn[i+1])/b[i];
		

	sum=0;
	for (i=0;i<n-1;++i)
	{
		nr[i]=dsave[i]-asave[i]*xn[i-1]-bsave[i]*xn[i]-csave[i]*xn[i+1];
		sum+=nr[i]*nr[i];
	}
	cout<<"\n" << "Double: "<< endl;
	cout<<"\n" << "N = "<<n<<endl;
	cout<<"Невязка |Ax-B|: "<<scientific<<sqrt(sum)<<endl; 
	int aa,bb;
	cout<<"Введите диапазон x[a,b]: ";
	cout<<"\nEnter a: ";
	cin>>aa;
	cout<<"Enter b: ";
	cin>>bb;
	for(int i=aa-1;i<bb;++i) 
	{
	 cout<<setw(11)<<right<<fixed<< i+1 << ": " <<xn[i]<<"\n";
	 
	}
	
}


void MetodProgonkiFileLong()
{
	ofstream fout("Resultat (long double).txt", ios_base::out | ios_base::trunc);
	int i, j,  k;
	long double ymmm,sum = 0.0,m;
	long double *a = new long double[n+1];
	long double *asave = new long double[n+1];
	long double *b = new long double[n+1];
	long double *bsave = new long double[n+1];
	long double *c = new long double[n+1];
	long double *csave = new long double[n+1];
	long double *d = new long double[n+1];
	long double *dsave = new long double[n+1];
	long double *xn = new long double[n+1];
	long double *nr = new long double[n];
cout.precision(5);
	for( i=1;i<n;++i)
	{
		a[i]=0.3*sin(i+1)/v;
		asave[i]=0.3*sin(i+1)/v;
	}
	for( i=0;i<n-1;++i)
	{
		c[i]=0.4*cos(i+1)/v;
		csave[i]=0.4*cos(i+1)/v;
	}
	for( i=0;i<n;++i)
	{
		b[i]=10*v+(i+1)/v;
		bsave[i]=10*v+(i+1)/v;
		d[i]=1.3+(i+1)/v;
		dsave[i]=1.3+(i+1)/v;
	}
		fout<<fixed<<"A: "<<setw(11)<<right;
		for( i=1;i<n;++i)
		{
		 fout<<fixed<<setw(11)<<right<<a[i]<<"\t";
		}fout<<"\nB: ";
		for( i=0;i<n;++i)
		{
		 fout<<fixed<<setw(11)<<right<<b[i]<<"\t";
		}fout<<"\nC: ";
		for( i=0;i<n-1;++i)
		{
		 fout<<fixed<<setw(11)<<right<<c[i]<<"\t";
		}fout<<"\nD: ";
		for( i=0;i<n;++i)
		{
		 fout<<fixed<<setw(11)<<right<<d[i]<<"\t";
		}
		
		fout<<endl;
		fout<<"\nAlpha: ";
		for( i=0;i<n-1;++i)
		{
		 fout<<setw(11)<<right<<fixed<<-c[i]/b[i]<<"\t";
		}
		fout<<"\nBeta:  ";
		for( i=0;i<n;++i)
		{
		 fout<<setw(11)<<right<<fixed<<d[i]/b[i]<<"\t";
		}
		fout<<endl;

	for ( i = 1; i < n; i++)
	{
		m = a[i]/b[i-1];
		
		b[i] = b[i] - m*c[i-1];
		d[i] = d[i] - m*d[i-1];
	}

	xn[n-1] = d[n-1]/b[n-1];
	

	for ( i = n - 2; i >= 0; i--)
		xn[i]=(d[i]-c[i]*xn[i+1])/b[i];
	fout<<"\nX: ";
	for( i=0;i<n;++i)
	{
	 fout<<setw(11)<<right<<xn[i]<<"\t";
	}
	
	sum=0;
	for (i=1;i<n-1;i++)
	{
		nr[i]=dsave[i]-asave[i]*xn[i-1]-bsave[i]*xn[i]-csave[i]*xn[i+1];
		sum+=nr[i]*nr[i];
	}
	fout<<"\n|Ax-B| "<<scientific<<sqrt(sum); 
	fout.close();
	
	delete []a;
	delete []asave;
	delete []b;
	delete []bsave;
	delete []d;
	delete []dsave;
	delete []c;
	delete []csave;
	delete []xn;
	delete []nr;
}	

void MetodProgonkiLong()
{	

	register int i, j,  k;
	long double ymmm,sum = 0.0,m;
	long double *a = new long double[n+1];
	long double *asave = new long double[n+1];
	long double *b = new long double[n+1];
	long double *bsave = new long double[n+1];
	long double *c = new long double[n+1];
	long double *csave = new long double[n+1];
	long double *d = new long double[n+1];
	long double *dsave = new long double[n+1];
	long double *xn = new long double[n+1];
	long double *nr = new long double[n];
	for( i=1;i<n;++i)
	{
		a[i]=0.3*sin(i+1)/v;
		asave[i]=0.3*sin(i+1)/v;
	}
	for( i=0;i<n-1;++i)
	{
		c[i]=0.4*cos(i+1)/v;
		csave[i]=0.4*cos(i+1)/v;
	}
	for( i=0;i<n;++i)
	{
		b[i]=10*v+(i+1)/v;
		bsave[i]=10*v+(i+1)/v;
		d[i]=1.3+(i+1)/v;
		dsave[i]=1.3+(i+1)/v;
	}
	
	for ( i = 1; i < n; i++)
	{
		m = a[i]/b[i-1];
		
		b[i] = b[i] - m*c[i-1];
		d[i] = d[i] - m*d[i-1];
	}

	xn[n-1] = d[n-1]/b[n-1];
	

	for ( i = n - 2; i >= 0; i--)
		xn[i]=(d[i]-c[i]*xn[i+1])/b[i];
		

	sum=0;
	for (i=1;i<n-1;++i)
	{
		nr[i]=dsave[i]-asave[i]*xn[i-1]-bsave[i]*xn[i]-csave[i]*xn[i+1];
		sum+=nr[i]*nr[i];
	}
	cout<<"\n" << "Long Double: "<< endl;
	cout<<"\n" << "N = "<<n<<endl;
	cout<<"Невязка |Ax-B|: "<<scientific<<sqrt(sum)<<endl; 
	int aa,bb;
	cout<<"Введите диапазон x[a,b]: ";
	cout<<"\nEnter a: ";
	cin>>aa;
	cout<<"Enter b: ";
	cin>>bb;
	for(int i=aa-1;i<bb;++i) 
	{
	 cout<<setw(11)<<right<<fixed<< i+1 << ": " <<xn[i]<<"\n";
	 
	}
	
	delete []a;
	delete []asave;
	delete []b;
	delete []bsave;
	delete []d;
	delete []dsave;
	delete []c;
	delete []csave;
	delete []xn;
	delete []nr;
	
}


int main()
{   
	system("color F0");
	setlocale(LC_ALL, "Russian");
	
	n=10;
	MetodProgonkiFileFloat();
	cout << "Результат для N = 10 сохранен в файле Resultat (float).txt" << endl;
	
	MetodProgonkiFileDouble();
	cout << "Результат для N = 10 сохранен в файле Resultat (double).txt" << endl;
	
	MetodProgonkiFileLong();
	cout << "Результат для N = 10 сохранен в файле Resultat (long double).txt" << endl;
	
	
	
	n=2000000;
	MetodProgonkiFloat();
	MetodProgonkiDouble();
	MetodProgonkiLong();	
	
	return 0;
}
