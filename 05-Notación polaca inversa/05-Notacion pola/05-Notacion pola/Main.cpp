#include <iostream>
#include <stack>
#include <string>

using namespace std;

//El coste es O(n) siendo n el numero de caracteres que tiene la operacion, por ejemplo 23- n = 3
void notacion_polaca(stack<int>& numeros, string palabra)
{
	int num1, num2, resultado;
	for (int i = 0; i < palabra.size(); i++)
	{
		if (palabra[i] != '+' && palabra[i] != '-')
		{
			numeros.push(palabra[i] - '0');
		}
		else
		{
			num2 = numeros.top();
			numeros.pop();
			num1 = numeros.top();
			numeros.pop();
			if (palabra[i] == '+')
				resultado = num1 + num2;
			else
				resultado = num1 - num2;

			numeros.push(resultado);
		}
	}
}

void operacion(stack<int>& numeros)
{
	int tamOp;
	string palabra;
	cin >> tamOp;
	getchar();
	getline(cin, palabra);
	notacion_polaca(numeros, palabra);
}

int main()
{
	int numCasos;
	cin >> numCasos;

	stack<int> numeros;

	for (int i = 0; i < numCasos; i++)
	{
		operacion(numeros);
		cout << numeros.top() << endl;
	}

	return 0;
}