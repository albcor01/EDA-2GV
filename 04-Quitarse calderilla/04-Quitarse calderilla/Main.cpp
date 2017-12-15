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
		if (mon[i].cantidad > 100) mon[i].cantidad = 100;
		monAux[i].cantidad = 0;
		sol_mejor[i].cantidad = 0;
	}
}

int actualiza(int numMon, int c)
{
	return numMon + c;
}

bool es_solucion(int valor_total, int sumanueva)
{
	return valor_total == sumanueva;
}

bool mejor(int nuevo_valor, int valor_mejor)
{
	if (nuevo_valor > valor_mejor)
		return true;
	else
		return false;
}

bool es_completable(int valor_total, int sumanueva)
{
	return sumanueva < valor_total;
}

bool es_prometedora(const vector<par>& sol, int k, int totalPagar, int sumaNueva)
{
	if (k + 1 < sol.size())
	{
		return totalPagar >= (sumaNueva + sol[k + 1].valor);
	}
	return false;
}

void vuelta_atras_opt(vector<par>& sol, int k, int num_Mon, int& cantidad_mejor, int totalPagar, const vector<par>& monedero, bool& posible, int sumaTotal)
{
	unsigned int c = 0;
	bool stop = false;
	while (k < sol.size() && c <= monedero[k].cantidad)
	{
		sol[k].cantidad = c;

		int sumaNueva = sumaTotal + (sol[k].valor * c);
		int nueva_cantidad = actualiza(num_Mon, c);
		if (es_solucion(totalPagar, sumaNueva))
		{
			posible = true;
			if (mejor(nueva_cantidad, cantidad_mejor))
			{
				cantidad_mejor = nueva_cantidad;
			}
		}
		else if (es_completable(totalPagar, sumaNueva) && es_prometedora(sol, k, totalPagar, sumaNueva))
		{
			vuelta_atras_opt(sol, k + 1, nueva_cantidad, cantidad_mejor, totalPagar, monedero, posible, sumaNueva);
			if (k == 0) 
				cout << "k = 0" << endl;
		}
		c++;
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
		bool posible = false;
		cin >> dinero;

		rellenaMon(mon, monAux, sol_mejor);
		vuelta_atras_opt(monAux, 0, num_Mon, cantidad, dinero, mon, posible, 0);

		if (posible)
		{
			cout << cantidad << endl;
		}
		else
		{
			cout << "IMPOSIBLE" << endl;
		}

	}
	system("pause");

	return 0;
}