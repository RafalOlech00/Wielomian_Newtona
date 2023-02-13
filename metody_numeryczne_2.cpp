#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;


int main()
{
	// odczytanie z pliku tekstowego danych 
	fstream read;
	int size = 0;
	read.open("plik_tekstowy_21.txt"); // otwarcie pliku tekstowego
	read >> size;
	

	// tablice przechowywujące węzły i ich wartości
	float* TabNode = new float[size];
	double* TabValue = new double[size];

	// tablice przechowywujące wyniki
	double* TabP = new double[size];
	double* TabB = new double[size];


	// wpisanie wezlow i wartosci do tablic
	for (int i = 0; i < size; ++i)
	{
		read >> TabNode[i];
		read >> TabValue[i];
	}
	read.close(); // zamknięcie pliku tekstowego

	// wartości początkowe p0 i b0
	TabP[0] = 1;
	TabB[0] = TabValue[0];


	double x, result = (TabP[0] * TabB[0]);

	cout << "Podaj punkt: ";
	cin >> x;


	


	for (int i = 1; i < size; ++i) // w tej pętli wyliczane są wartości P
	{
		TabP[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			TabP[i] *= (x - TabNode[j]);
		}


		TabB[i] = 0;
		for (int j = 0; j <= i; ++j)
		{
			double il = 1;
			for (int k = 0; k <= i; ++k)
			{
				if (j == k) continue;
				il *= (TabNode[j] - TabNode[k]);
			}

			TabB[i] += (TabValue[j] / il);
		}
	}

	for (int i = 1; i < size; ++i)
	{
		result += (TabP[i] * TabB[i]);
	}

	cout << endl << "WYNIKI" << endl;
	cout << endl << "Liczba wezlow: " << size << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << "Wezel i wartosc: " << TabNode[i] << ", " << TabValue[i] << endl;
	}

	cout << endl << "Przybliżone wspolczynniki wielomianu Newtona:" << endl;
	for (int i = 0; i < size; ++i)
	{
		cout <<int(TabB[i])<< endl;
	}
	cout << endl << "Wartosc wielomianu Newtona w punkcie " <<x<<" wynosi: " << result << endl;

	delete[] TabNode;
	delete[] TabValue;
	delete[] TabP;
	delete[] TabB;

}

