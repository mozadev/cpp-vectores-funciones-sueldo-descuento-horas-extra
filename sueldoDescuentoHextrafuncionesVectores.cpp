// ConsoleApplication20.cpp : main project file.

#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>

using namespace std;
using namespace System;

int ingresan()
{
	int n;
	cout << "ingresa numero de traba"; cin >> n;
	while (n <= 0 || n > 40)
	{
		cout << "ingresa numero de traba"; cin >> n;

	}
	return n;
}


void sueldobruto(int*n, float*sueldob)
{

	for (int i = 0; i < *n; i++)
	{
		cout << "ingresa sueldo" << i + 1 << ": ";
		cin >> sueldob[i];
	}


}


void descuento(int*n, float*descxperso)
{

	for (int i = 0; i < *n; i++)
	{
		cout << "ingresa descuento" << i + 1 << ": ";
		cin >> descxperso[i];
	}


}




void horasextra(int*n, float*horasex)
{

	for (int i = 0; i < *n; i++)
	{
		cout << "ingresa pagox horas" << i + 1 << ": ";
		cin >> horasex[i];
	}

}

void efectivo(int*n, float*horasex, float*descxperso, float*sueldob, int*codigo, float *efectivo)
{

	for (int i = 0; i < *n; i++)

		efectivo[i] = sueldob[i] + horasex[i] - descxperso[i];

}



void salidadatos(int*n, float*horasex, float*descxperso, float*sueldob, int*codigo, float*efectivo)
{
	cout << "cod" << "\t" << "sbrut" << "\t" << "pag" << "\t" << "desc" << "\t" << "efect" << "\t";
	for (int i = 0; i < *n; i++)
		cout << codigo[i] << "\t" << sueldob[i] << "\t" << horasex[i] << "\t" << descxperso[i] << "\t" << efectivo[i] << "\t";


}






void generacodigo(int *n, int *codigo)
{
	srand(time(NULL));
	for (int i = 0; i < *n; i++)
		codigo[i] = 201 +  rand()% 999 - 201 + 1;
}

int main()
{

	int n = ingresan();
	int*codigo = new int[n];
	float *sueldob = new float[n];
	float *horasex = new float[n];
	float *descxperso = new float[n];
	float*efectivo = new float[n];
	sueldobruto(&n, sueldob);
	descuento(&n, descxperso);
	horasextra(&n, horasex);
	salidadatos(&n, horasex, descxperso, sueldob, codigo,efectivo);

	delete[]sueldob;
	delete[]horasex;
	delete[]descxperso;
	_getch();
}



