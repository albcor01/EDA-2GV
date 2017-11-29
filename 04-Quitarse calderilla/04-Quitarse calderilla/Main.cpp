#include <iostream>
#include <vector>
using namespace std;


struct par { int valor = 0; int cantidad = 0; };

void rellenaMon(vector<par>& mon, vector<par>& monAux, vector<par>& sol_mejor)
{
	mon[0].valor = monAux[0].valor = sol_mejor[0].valor = 1;
	mon[1].valor = monAux[1].valor = sol_mejor[1].valor = 2;
	mon[2].valor = monAux[2].valor = sol_mejor[2].valor = 5;
	mon[3].valor = monAux[3].valor = sol_mejor[3].valor = 10;
	mon[4].valor = monAux[4].valor = sol_mejor[4].valor = 20;
	mon[5].valor = monAux[5].valor = sol_mejor[5].valor = 50;
	mon[6].valor = monAux[6].valor = sol_mejor[6].valor = 100;
	mon[7].valor = monAux[7].valor = sol_mejor[7].valor = 200;

	for (int i = 0; i < 8; i++)
	{
		cin >> mon[i].cantidad;
		monAux[i].cantidad = 0;
		sol_mejor[i].cantidad = 0;
	}
}

int actualiza(int cantidad, const vector<par>& sol, int k)
{
	if (sol[k].cantidad > 0)
		cantidad++;
	return cantidad;
}

bool es_solucion(int valor_total, const vector<par> sol, int k)
{
	int valorActual = 0;
	bool valorIdeal = false;
	int i = 0;
	while (i <= k && !valorIdeal) {
		valorActual += sol[i].cantidad * sol[i].valor;
		if (valorActual == valor_total) 
			valorIdeal = true;
		i++;
	}
	return valorIdeal;
}

bool mejor(int nuevo_valor, int valor_mejor)
{
	if (nuevo_valor > valor_mejor)
		return true;
	else
		return false;
}

bool es_completable(int valor_total, const vector<par> sol, int k)
{
	int valorActual = 0;

	for (int i = 0; i <= k; i++) {
		valorActual += sol[i].cantidad * sol[i].valor;
	}
	if (k < sol.size() - 1 && valorActual < valor_total)
		return true;
	else
		return false;
}

bool es_prometedora(vector<par>& sol, int k, int nueva_cantidad, int cantidad_mejor)
{
	return true;
}

void vuelta_atras_opt(vector<par>& sol, int k, int& num_Mon, vector<par>& sol_mejor, int& cantidad_mejor, int totalPagar, const vector<par> monedero)
{
	for (int c = 0; c <= monedero[k].cantidad; c++)
	{
		sol[k].cantidad = c;
		int nueva_cantidad = actualiza(num_Mon, sol, k);
		if (es_solucion(totalPagar, sol, k))
		{
			if (mejor(nueva_cantidad, cantidad_mejor))
			{
				sol_mejor = sol;
				cantidad_mejor = nueva_cantidad;
			}
		}
		else if (es_completable(totalPagar, sol, k) && es_prometedora(sol, k, nueva_cantidad, cantidad_mejor))
		{
			vuelta_atras_opt(sol, k + 1, nueva_cantidad, sol_mejor, cantidad_mejor, totalPagar, monedero);
		}
	}
}

int main()
{
	vector<par> mon(8);
	vector<par> monAux(8);
	vector<par> sol_mejor(8);
	int n, dinero, cantidad = 0, num_Mon = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> dinero;
		rellenaMon(mon, monAux, sol_mejor);
		vuelta_atras_opt(monAux, 0, num_Mon, sol_mejor, cantidad, dinero, mon);
		for (int i = 0; i < sol_mejor.size(); i++)
			cout << sol_mejor[i].cantidad << " ";
		cout << endl << cantidad << endl;
	}

	system("pause");
	return 0;
}