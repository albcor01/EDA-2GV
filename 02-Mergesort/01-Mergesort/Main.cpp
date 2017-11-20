//Alberto Córdoba Ortiz
//Alejandro Villar Rubio
//Grupo 10

#include <vector>
#include <iostream>
using namespace std;

void creaVector(vector <int>& v)
{
	v.clear();
	int tam, num = 0;
	cin >> tam;

	for (int i = 0; i < tam; i++)
	{
		cin >> num;
		v.push_back(num);
	}
}

//Tiene coste O(n) porque tiene un bucle for con n elementos
void merge(vector <int>& v, int p, int q, int r)
{
	int i = 0, j = 0;
	int nl = q - p;
	int nr = r - q;

	vector<int>vl, vr;

	for (int i = 0; i < nl; i++){ vl.push_back(v[p + i]); }
	for (int i = 0; i < nr; i++){ vr.push_back(v[q + i]);}

	for (int k = p; k < r; k++)
	{
		if (j >= nr || (i < nl && vl[i] <= vr[j]))
		{
			v[k] = vl[i];
			i++;
		}
		else
		{
			v[k] = vr[j];
			j++;
		}
	}
}

//El coste de mergesort es O(n·log n) debido a (2·T(n/2) + n) donde n es el número de iteraciones
//2·T se debe a que se llama recursivamente dos veces y n/2 es debido a que se llama una vez
//en cada ocasion
void mergesort(vector <int>& v, int ini, int fin)
{
	if (ini < fin - 1)
	{
		int mit = (fin + ini) / 2;
		mergesort(v, ini, mit);
		mergesort(v, mit, fin);
		merge(v, ini, mit, fin);
	}
}

void escribeVector(const vector <int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " " << endl;
	}
}

int main()
{
	int numVectores;
	cin >> numVectores;
	vector <int> v;

	for (int i = 0; i < numVectores; i++)
	{
		creaVector(v);
		mergesort(v, 0, v.size());
		escribeVector(v);
	}

	system("pause");
	return 0;
}