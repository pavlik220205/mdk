// mdk.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;
int main()
{
		srand(time(NULL));

		int N = 0;
		int K = 0;
		do
		{
			cout << "Enter number (1-999) : "; cin >> N;

		} while (N < 0 && N > 1000);
		cout << "Enter K : "; cin >> K;
		//const int NN = N;
		//int array[NN] = {};
		
		int *array = new int[N];

		for (int i = 0; i < N; i++)
		{
			array[i] = rand() / 101;
		}
	
		for (int i = 0; i < N-1; i++)
		{
			for (int b = 0; b < N-1-i; b++)
			{
				if (array[b] > array[b+1]) {
				int temp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = temp;
				}	
			}
		}

		for (int i = 0; i < N; i++)
		{
			if (i != 0 && i % 10 == 0) cout << endl;
			cout << setw(5) << array[i];
		}
		int L = 0; int R = N - 1; int fpos = -1;
		
		while (R - L >= 0)
		{
			int vid = (L + R) / 2;

			if (array[vid] == K)
			{
				fpos = vid;
				break;
			}
			if (K > array[vid]) {
				L = vid + 1;
				continue;
			}
			R = vid - 1;
		}

		if (fpos != -1)
			cout << endl << "K position = " << fpos << endl;
		else
			cout << endl << "K position not found" << endl;
		system("pause");

}