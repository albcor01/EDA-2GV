#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;


template<typename T>
class colaVIP
{
private:
	vector<queue<T>> colaVip;
	int prioridades;

public:
	colaVIP(int p)
	{
		prioridades = p;
		for (int i = 0; i < prioridades; i++)
		{
			colaVIP.push_back(queue<T>());
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
			if (colaVip[i].empty()){ i++; }
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



int main()
{
	int Test, Priorities, AandL, gauging;
	cin >> Test;
	
	for (int i = 0; i < Test; i++)
	{
		cin >> Priorities >> AandL >> gauging;
		colaVIP cola = new colaVIP(Priorities);
	}

	system("pause");
	return 0;
}