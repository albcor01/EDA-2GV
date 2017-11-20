#include <iostream>

using namespace std;

int resuelve(unsigned int n)
{
	return 2 * n;
}

int num(unsigned int n)
{
	cin >> n;
	return n;
}

int main()
{
	int n = 0;
	bool esCero = false;
	while (!esCero)
	{
		n = num(n);
		if (n != 0)
		{
			n = resuelve(n);
			cout << n << endl;
		}
		else esCero = true;
	}
	return 0;
}