#include <iostream>
#include <cmath>
#include "antoine.h"
using namespace std;

void DEWP(){
	cout<<"DEWP is designed to calculate x_i, P, given y_i, T\n";
	cout<<"It's based on Raoult's Law\n";
	int n;
	cout<<"Enter number of compounds\n"; cin>>n;
	
	//given parameter
	double* Y; Y = new double[n];
	double T;
	
	//variables to calculate
	double* X; X = new double[n];
	double P;
	
	double* A; A = new double[n];
	double* B; B = new double[n];
	double* C; C = new double[n];
	
	cout<<"Enter the temperature[Celsius]\n"; cin>>T;
	for(int i=0; i<n; i++){
		cout<<"Enter the molar fraction of compound "<<(i+1)<<endl;
		cin>>Y[i];
	}
	cout<<"Antoine Equation is given below\n";
	cout<<"log10(Psat)=A-B/(T+C)\n";
	for(int i=0; i<n; i++){
		cout<<"Enter the Antoine coefficients(A,B,C) of compount "<<(i+1)<<endl;
		cin>>A[i]>>B[i]>>C[i];
	}
	
	double sum = 0;
	for(int i=0; i<n; i++){
		sum += Y[i]/Psat(T,A[i],B[i],C[i]);
	}
	P = 1./sum;
	for(int i=0; i<n; i++){
		X[i] = Y[i]*P/Psat(T,A[i],B[i],C[i]);
	}
	cout<<"P[mmHg]"<<P<<endl;
	for(int i=0; i<n; i++){
		cout<<"X["<<(i+1)<<"]="<<X[i]<<endl;
	}
}
