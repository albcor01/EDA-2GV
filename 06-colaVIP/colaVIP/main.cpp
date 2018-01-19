//Alberto Córdoba Ortiz
//Alejandro Villar Rubio

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

//LA CLASE COLAVIP ES UNA COLA DONDE DONDE HAY QUE TENER EN CUENTA LAS PRIORIDADES
//Y PARA ELLO HEMOS USADO UN VECTOR DE COLAS PARA IMPLEMENTARLO DE FORMA EFICIENTE
template<typename T>
class colaVIP
{
private:
	vector<queue<T>> colaVip;
	int prioridades;

public:
	//LA CONSTRUCTORA ES LINEAL 0(p) DONDE 'p' ES EL NÚMERO DE PRIORIDADES
	colaVIP(int p) : prioridades(p)
	{
		for (int i = 0; i < prioridades; i++)
		{
			colaVip.push_back(queue<T>());
		}
	}
	//PUSH ES UN MÉTODO CONSTANTE 0(1), ESTO SE DEBE A QUE COMO ESTAMOS
	//USANDO UN VECTOR PODEMOS ACCEDER DIRÉCTAMENTE A LA PRIORIDAD QUE 
	//NOS INTERESA
	void push(int p, const T& elem)
	{
		if(p < prioridades)
			colaVip[p].push(elem);
		else cout << "has introducido un valor de prioridad no valido, vuelve a intentarlo";
	}
	//EL MÉTODO FRONT TIENE UN COSTE LINEAL 0(p) CON 'p' COMO NÚMERO DE PRIORIDADES
	//LOS ACCESOS A UNA POSICION CONCRETA ES CONSTANTE PERO COMO AQUÍ TENEMOS QUE 
	//COMPROBAR LAS PRIORIDADES PARA ENCONTRAR UNA QUE NO ESTÉ VACÍA EN EL PEOR DE LOS
	//CASOS TENEMOS UN BUCLE QUE HARÁ 'p' ITERACIONES
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
	//EL COSTE DE POP ES LINEAL 0(p) CON 'p' COMO PRIORIDADES, LA RAZÓN ES LA 
	//MISMA QUE EN EL MÉTODO FRONT SOLO QUE AQUÍ SE SACA DE LA COLA EL PRIMER ELEMENTO
	//DE LA PRIORIDAD 'i'
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
	//COSTE LINEAL 0(p) CON 'p' PRIORIDAD, PARA SABER SI LA COLA ES VACÍA
	//HAY QUE ITERAR PARA ENCONTRAR UNA COLA NO VACÍA. COMO MUCHO REALIZAREMOS
	//P INERACIONES
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
	//EL MÉTODO SIZE ES LINEAL 0(P), EN ESTE MÉTODO HAY QUE ITERAR 'p' VECES
	//PARA PODER SUMAR LOS ELEMENTOS DE CADA COLA DE PRIORIDADES
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
	//0(1)
	int getLength() { return colaVip.size(); }
	//0(1)
	void queueCleaner() { colaVip.clear(); }
};
//0(1)
void readPropeties(int& Priorities, int& AandL, int& gauging)
{
	cin >> Priorities >> AandL >> gauging;
}
//0(1)
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
//COSTE CUADRÁTICO 0(N^2) YA QUE TENEMOS UN BUCLE CON UN MÉTODO ANIDADO QUE ES 0(p)
void writeOutput(colaVIP<int> cola)
{
	if (cola.empty())
	{
		cout << "NADIE" << endl;
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
//RESUELVE CASO TIENE COSTE CUADRÁTICO 0(N^2) DEBIDO A QUE TENEMOS BUCLES ANIDADOS.
//EL PRIMERO ES EN NÚMERO DE ENTRADAS Y SALIDAS 0(AandL) Y LUEGO DENTRO TENEMOS 
//OTROS BUCLES EN FUNCIÓN DEL MÉTODO DE LA CLASE COLAVIP, HABITUALMENTE 0(p) POR LO TANTO 
//TENEMOS LLEGADAS Y SALIDAS * PRIORIDADES QUE ES CUADRÁTICO.
void resuelveCaso(int Test, int Priorities, int AandL, int gauging) 
{
	int peopleIn = 0;
	
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
			if (peopleIn > 0) { peopleIn -= 1; }

			if (!cola.empty())
			{
				cola.pop();
				peopleIn += 1;
			}
		}
	}
	writeOutput(cola);
	cola.queueCleaner();
}

int main()
{
	
	int Test, Priorities, AandL, gauging;
	cin >> Test;
	

	for (int i = 0; i < Test; i++)
	{
		readPropeties(Priorities, AandL, gauging);
		resuelveCaso(Test, Priorities, AandL, gauging);
	}
	
	
	system("pause");
	return 0;
}