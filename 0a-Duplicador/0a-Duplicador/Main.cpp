#include <iostream>
#include <vector>

using namespace std;

int resolver(unsigned int n)
{
	return 2 * n;
}

void leeNumeros()
{
	unsigned int n;
	cin >> n;
	n = resolver(n);
	cout << n << endl;
}


int main()
{
	int numLineas;
	cin >> numLineas;
	for (int i = 0; i < numLineas; i++)
	{
		leeNumeros();
	}
	return 0;
}