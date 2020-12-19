// Lab_06_2.cpp
// < Кузів Назар >
// Лабораторна робота № 6.2-2
// Опрацювання одновимірних масивів рекурсивним  способoм
// Варіант 6

#include <iostream>
#include <cmath>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const  int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);

}

void Cout(int* a, const int size, int i)
{
	
		cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
		if (i < size - 1)
			Cout(a, size, i + 1);
		else
			cout << endl;

}
void Cout2(int* a, const int size, int min, int i)
{
	if (a[i] == min && i < size)

		cout << "Min a[" << i << "]=" << a[i] << endl;
	else
		Cout2(a, size, min, i+1);
	
}

int Search(int* a, const int size, int min, int i)
{
	if (a[i] < min && a[i] % 2 == 0)
		min = a[i];

	if (i < size - 1)
		 Search(a, size, min, i + 1);
	else
		return min;

}

int First(int* a, const int size, int min, int i)
{
	if (a[i] % 2 == 0)
	{
		min = a[i]; 
		
		return min;
	} 
	if (i < size - 1)
		return First(a, size, min, i + 1);
	else
		return -1;
}

int Castling(int* a, const int size, int min, const int first, const int xmin, int i)
{
	if (a[i] == min) 
	{
		a[i] = first;
		a[0] = xmin;
	}

	if( i < size -1)
		return Castling(a, size, min, first, xmin, i+1);
	else
		return 0;
}


int main()
{
	srand((unsigned)time(NULL));

	int Low, High, Min{};
	const int n = 6;
	int a[n];

	cout << "Low ="; cin >> Low;
	cout << "High ="; cin >> High;
	cout << endl;

	Create(a, n, Low, High,0);
	Cout(a, n, 0);
	
	int X = First(a, n, Min, 0);

	if(X == -1)
		cerr << "Error" << endl;
	else
	{
		Min = Search(a, n, X, 0);

		cout << endl;
		Cout2(a, n, Min, 0);
		cout << endl;

		const int first = a[0];
		const int xmin = Min;

		Castling(a, n, Min, first, xmin, 0);
		Cout(a, n, 0);
	}

	return 0;
}
