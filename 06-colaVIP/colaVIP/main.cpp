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
	colaVIP(int p) : prioridades(p)
	{
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
		bool noEncontrado = true;
		int i = 0;
		while (i < colaVip.size() && noEncontrado)
		{
			if (colaVip[i].empty()) { i++; }
			else { noEncontrado = false; }
		}
		return noEncontrado;
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

	int getLength() { return colaVip.size(); }
	void queueCleaner() { colaVip.clear(); }
};

void readPropeties(int& Priorities, int& AandL, int& gauging)
{
	cin >> Priorities >> AandL >> gauging;
}

bool readInput(int& priority, int& id)
{
	char InOut;
	cin >> InOut;

	if (InOut == '+'){
		cin >> priority >> id;
		return true;
	}
	else if(InOut == '-'){ return false; }
	else { cout << "algo fue mal"; return false; }
}

void writeOutput(colaVIP<int> cola)
{
	if (cola.empty())
	{
		cout << "NADIE";
	}
	else 
	{
		while (!cola.empty())
		{
			cout << cola.front() << " ";
			cola.pop();
		}
		cout << endl;
	}
}

int main()
{
	int Test, Priorities, AandL, gauging, peopleIn = 0;
	cin >> Test;
	

	for (int i = 0; i < Test; i++)
	{
		
		readPropeties(Priorities, AandL, gauging);
		colaVIP<int> cola(Priorities);

		for (int j = 0; j < AandL; j++)
		{
			int priority, id;
			bool entrada = readInput(priority, id);
			if (entrada) 
			{
				if (peopleIn < gauging) { peopleIn++; }
				else { cola.push(priority, id); }
			}
			else
			{
				peopleIn--;
				if (!cola.empty())
				{
					cola.pop();
					peopleIn++;
				}
			}
		}
		writeOutput(cola);
		cola.queueCleaner();
	}
	

	system("pause");
	return 0;
}