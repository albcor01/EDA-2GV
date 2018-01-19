//Alberto Córdoba Ortiz
//Alejandro Villar Rubio
//Grupo 10

#include <vector>
#include <iostream>

//EL COSTE DE TODOS LOS MÉTODOS SON 0(1) MENOS EL MÉTODO N_Reinas que es 0(!n) CON N SIENDO
//EL NUMERO DE REINAS (EN EL MÉTODO ESTÁ DETALLADO EL PORQUÉ)

using namespace std;
/*//El metodo diag_desc tiene coste constante 0(1)
int diag_desc(int x, int y, int numReinas)
{
	return (x - y + (numReinas - 1));
}
//El metodo diag_asc tiene coste constante 0(1)
int diag_asc(int x, int y)
{
	return (x + y);
}
//no_ataca_m tiene un coste constante 0(1)
bool no_ataca_m(vector <int>& sol, int k, vector <bool>& filas, vector <bool>& d_asc, vector <bool>& d_desc)
{
	return !filas[sol[k]] && !d_asc[diag_asc(k, sol[k])] && !d_desc[diag_desc(k, sol[k], sol.size())];
}
//es_solucion tiene coste constante 0(1)
bool es_solucion(int numReinas, vector <int>& sol, int k, vector <bool>& filas, vector <bool>& d_asc, vector <bool>& d_desc)
{
	return (k == (numReinas - 1)) && (no_ataca_m(sol, k, filas, d_asc, d_desc));
}
//es_completable tiene conste constante 0(1)
bool es_completable(int numReinas, vector <int>& sol, int k, vector <bool>& filas, vector <bool>& d_asc, vector <bool>& d_desc)
{
	return (k < (numReinas - 1)) && (no_ataca_m(sol, k, filas, d_asc, d_desc));
}
//procesar_solucion tiene coste constante 0(1)
void procesar_solucion(int& numSol)
{
	numSol++;
}

//EL NÚMERO DE RAMAS ES N^N PERO COMO AL PONER UNA REINA DESCARTAMOS SU FILA SU COSTE SE REDUCE A N! YA QUE
//POR CADA REINA COLOCADA LA COMPROBACIÓN SE REDUCE A N - (REINAS YA COLOCADAS) 
//EN EL PEOR DE LOS CASOS HAY N! POSIBLES SOLUCIONES
//EL COSTE DE N_Reinas es 0(n!)
void N_Reinas(int& numSol, int numReinas, vector <int>& sol, int k, vector <bool>& filas, vector <bool>& d_asc, vector <bool>& d_desc)
{
	for (int c = 0; c < numReinas; c++)
	{
		sol[k] = c;
		if (es_solucion(numReinas, sol, k, filas, d_asc, d_desc))
			procesar_solucion(numSol);
		else if (es_completable(numReinas, sol, k, filas, d_asc, d_desc))
		{
			filas[c] = true;
			d_asc[diag_asc(k, c)] = true;
			d_desc[diag_desc(k, c, numReinas)] = true;

			N_Reinas(numSol, numReinas, sol, k + 1, filas, d_asc, d_desc);

			filas[c] = false;
			d_asc[diag_asc(k, c)] = false;
			d_desc[diag_desc(k, c, numReinas)] = false;
		}
	}
}*/

int diag_asc(int x, int y)
{
	return x + y;
}

int diag_desc(int x, int y, int numReinas)
{
	return (x - y + (numReinas - 1));
}

bool no_ataca_m(vector <int>& sol, int k, vector <bool>& filas, vector <bool>& d_asc, vector <bool>& d_desc)
{
	return !filas[sol[k]] && !d_asc[diag_asc(k, sol[k])] && !d_desc[diag_desc(k, sol[k], sol.size())];
}

bool es_solucion(int numReinas, vector<int>& sol, int k, vector<bool> filas, vector<bool> d_asc, vector<bool> d_desc)
{

}

bool es_completable(int numReinas, vector<int>& sol, int k, vector<bool> filas, vector<bool> d_asc, vector<bool> d_desc)
{

}

void procesa_solucion(int& numSol)
{
	numSol++;
}

void N_Reinas(int& numSol, int numReinas, vector <int>& sol, int k, vector <bool>& filas, vector <bool>& d_asc, vector <bool>& d_desc)
{
	for (int c = 0; c < numReinas; c++)
	{
		sol[k] = c;
		if (es_solucion(numReinas, sol, k, filas, d_asc, d_desc))
			procesa_solucion(numSol);
		else if (es_completable(numReinas, sol, k, filas, d_asc, d_desc))
		{

		}
	}
}

int main()
{
	int m, n, numSol;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		numSol = 0;
		cin >> n;
		vector <int> sol(n);
		vector <bool> filas(n);
		vector <bool> d_asc(2 * n - 1);
		vector <bool> d_desc(2 * n - 1);
		N_Reinas(numSol, n, sol, 0, filas, d_asc, d_desc);
		cout << numSol << endl;
	}

	system("pause");
	return 0;
}
