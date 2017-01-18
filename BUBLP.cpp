#include <iostream>
#include <cmath>
#include "antoine.h"
using namespace std;

void BUBLP(){
	cout<<"BUBLP is designed to calculate y_i, P, given x_i, T\n";
	cout<<"It's based on Raoult's Law\n";
	int n;
	cout<<"Enter number of compounds\n"; cin>>n;
	
	//given parameter
	double* X; X = new double[n];
	double T;
	
	//variables to calculate
	double* Y; Y = new double[n];
	double P;
	
	double* A; A = new double[n];
	double* B; B = new double[n];
	double* C; C = new double[n];
	
	cout<<"Enter the temperature[Celsius]\n"; cin>>T;
	for(int i=0; i<n; i++){
		cout<<"Enter the molar fraction of compound "<<(i+1)<<endl;
		cin>>X[i];
	}
	cout<<"Antoine Equation is given below\n";
	cout<<"log10(Psat)=A-B/(T+C)\n";
	for(int i=0; i<n; i++){
		cout<<"Enter the Antoine coefficients(A,B,C) of compount "<<(i+1)<<endl;
		cin>>A[i]>>B[i]>>C[i];
	}
	
	double sum = 0;
	for(int i=0; i<n; i++){
		sum += X[i]*Psat(T,A[i],B[i],C[i]);
	}
	P = sum;
	for(int i=0; i<n; i++){
		Y[i] = X[i]*Psat(T,A[i],B[i],C[i])/P;
	}
	cout<<"P[mmHg]"<<P<<endl;
	for(int i=0; i<n; i++){
		cout<<"Y["<<(i+1)<<"]="<<Y[i]<<endl;
	}
}
