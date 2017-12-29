#include <string>
#include <vector>
#include <iostream>
#include <queue>


using namespace std;


template<typename T>
class ColaVIP
{
private:
	vector<queue<T>> colaVip;
	unsigned int prioridades;

public:
	ColaVIP():
		prioridades(0){}
	ColaVIP(int p)
	{
		prioridades = p;
		for (int i = 0; i < prioridades; i++)
		{
			colaVip.push_back(queue<T>());
		}
	}

	void push(int p, const T& elem)
	{
		colaVip[p].push(elem);
	}

	T const& front() const
	{
		bool encontrado = false;
		int i = 0;
		while (i < colaVip.size() && !encontrado)
		{
			if (colaVip[i].empty()) { i++; }
			else { encontrado = true; }
		}
		return colaVip[i].front();
	}

	void pop()
	{
		bool encontrado = false;
		int i = 0;
		while (i < colaVip.size() && !encontrado)
		{
			if (colaVip[i].empty()) { i++; }
			else { encontrado = true; }
		}
		colaVip[i].pop();
	}

	bool empty()
	{
		bool encontrado = false;
		int i = 0;
		while (i < colaVip.size() && !encontrado)
		{
			if (colaVip[i].empty()) { i++; }
			else { encontrado = true; }
		}
		if (encontrado)
			return true;
		else return false;
	}

	size_t size() const
	{
		int numElems = 0;
		for (int i = 0; i < colaVip.size(); i++)
		{
			if (!colaVip[i].empty())
			{
				numElems += colaVip[i].size();
			}
		}
	}
};

void entradaSalida(int& genteDisco, int aforo)
{
	char masMenos = ' ';
	cin >> masMenos;
	if (masMenos == '+')
	{
		if ()
	}
}

void genteCola()
{
	int prioridades, entSal, aforo = 0;
	int genteDisco = 0;
	writeInfo(prioridades, entSal, aforo);
	for (int i = 0; i < entSal; i++)
	{

	}
}

void writeInfo(int& prioridades, int& entSal, int& aforo)
{
	cin >> prioridades >> entSal >> aforo;
}

int main()
{
	int Test, Priorities, AandL, gauging;
	cin >> Test;

	for (int i = 0; i < Test; i++)
	{
		cin >> Priorities >> AandL >> gauging;
		ColaVIP <int> cola(Priorities);
	}

	system("pause");
	return 0;
}