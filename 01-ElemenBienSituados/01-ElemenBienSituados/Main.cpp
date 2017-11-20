//Alberto Córdoba Ortiz
//Alejandro Villar Rubio
//Grupo 10

#include <vector>
#include <iostream>

using namespace std;

//Tiene coste O(log n) debido a T(n/2) porque siendo n el numero de posiciones
//que tiene que recorrer para poder encontrar el numero bien situado, este se divide
//a la mitad dependiendo de la condicion de que v[mit] sea mayor o menor que mit.
bool elemento_situado(const vector <int>& v, int ini, int fin)
{
	const int n = fin - ini;

	if (n < 1) return false;
	
	else
	{
		if (n == 1)
		{
			if (v[ini] == ini) return true;
			else return false;
		}
		else
		{
			const int mit = (ini + fin) / 2;
			if (v[mit] == mit) return true;
			else if (v[mit] > mit) 
				return elemento_situado(v, ini, mit);
			else 
				return elemento_situado(v, mit, fin);
		}
	}
}

void creaVector(vector <int>& v)
{
	v.clear();
	int tamVector, num;
	cin >> tamVector;

	for (int i = 0; i < tamVector; i++)
	{
		cin >> num;
		v.push_back(num);
	}

}

int main()
{
	unsigned int numVectores;
	cin >> numVectores;

	vector <int> v;
	
	for (int i = 0; i < numVectores; i++)
	{
		creaVector(v);
		if (elemento_situado(v, 0, v.size())) cout << "SI" << endl;
		else cout << "NO" << endl;
	}

	system("pause");
	return 0;
}