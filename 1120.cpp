#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <cstring>
#include <sstream>
#include <stdlib.h>


using namespace std;
using std::string;
using std::stringstream;


int main ()
{
	string d, n, array;
	long long numero;

	do
	{
		numero = 0;
		array = "";
		cin >> d >> n;

		if (d[0] != '0' && n[0] != '0')
		{
			for (int i = 0; i < n.length(); i++)
			{
				if (n[i] != d[0])
				{
					array += n[i];
				}
			}

			numero = atof(array.c_str());


			if (numero > 2147483647 || numero < -2147483647)
			{
				cout << array << endl;
			}
			else
			{
				cout << numero << endl;
			}
		}


	}
	while (d[0] != '0' && n[0] != '0');


	return 0;
}
