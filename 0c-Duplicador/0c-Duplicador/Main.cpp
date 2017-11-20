#include <iostream>

using namespace std;


int resolver(unsigned int n)
{
	return n * 2;
}

bool resuelveCaso()
{
	int n;
	cin >> n;
	if (!cin) return false;
	n = resolver(n);
	cout << n << endl;
	return true;
}

int main()
{
	while (resuelveCaso());
	
	return 0;
}