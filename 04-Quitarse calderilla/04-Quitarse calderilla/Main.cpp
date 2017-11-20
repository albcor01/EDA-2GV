#include <iostream>
#include <vector>
using namespace std;

struct Monedas
{
	int cent1 = 0;
	int cent2 = 0;
	int cent5 = 0;
	int cent10 = 0;
	int cent20 = 0;
	int cent50 = 0;
	int euro1 = 0;
	int euro2 = 0;
};

Monedas rellenaMon()
{
	Monedas mon;
	cin >> mon.cent1;
	cin >> mon.cent2;
	cin >> mon.cent5;
	cin >> mon.cent10;
	cin >> mon.cent20;
	cin >> mon.cent50;
	cin >> mon.euro1;
	cin >> mon.euro2;
	return mon;
}

int actualiza(int valor, vector<int> sol, int k)
{

}

bool es_solucion(vector<int> sol, int k)
{

}

bool mejor(int nuevo_valor, int valor_mejor)
{
	if (nuevo_valor > valor_mejor)
		return true;
	else
		return false;
}

bool es_completable(vector<int> sol, int k)
{

}

void vuelta_atras_opt(vector<int> sol, int k, int valor, vector<int> sol_mejor, int valor_mejor)
{

}

int main()
{
	Monedas mon;
	int n, dinero;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> dinero;
		mon = rellenaMon();
	}

	return 0;
}