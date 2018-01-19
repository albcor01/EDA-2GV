#pragma once
#include <stdexcept> // domain_error
#include <algorithm> // max
#include <memory>    // shared_ptr, make_shared
#include <iomanip>   // setw

#include <vector>
#include <queue>
#include <iostream>
using namespace std;


template <typename T>

class bintree {
private:
	const int TREE_INDENTATION = 4;

	/*
	Nodo que almacena internamente el elemento (de tipo T)
	y dos 'punteros compartidos', uno al hijo izquierdo y al hijo derecho.
	*/
	class Nodo; // Declaración adelantada para poder definir Link
	using Link = shared_ptr<Nodo>; // Alias de tipo

	class Nodo {
	public:
		Link izq;
		T elem;
		Link der;

		Nodo(const T& elem) : izq(nullptr), elem(elem), der(nullptr) {}
		Nodo(Link izq, const T& elem, Link der) : izq(izq), elem(elem), der(der) {}
	};

	// puntero a la raíz
	Link raiz;

	// constructora privada a partir de un puntero a Nodo
	// Para construir los árboles generados por left() y right()
	bintree(Link r) : raiz(r) {} // O(1)

								 // Muestra por 'out' una representación del árbol
								 // Adaptado de "ADTs, DataStructures, and Problem Solving with C++", Larry Nyhoff, Person, 2015
	void graph_rec(ostream & out, int indent, Link raiz) const { // O(n), donde 'n' es el número de nodos alcanzables desde 'raiz'
		if (raiz != nullptr) {
			graph_rec(out, indent + TREE_INDENTATION, raiz->der);
			out << setw(indent) << " " << raiz->elem << endl;
			graph_rec(out, indent + TREE_INDENTATION, raiz->izq);
		}
	}

	//Coste O(n), donde n es el numero de elementos del arbol porque se recorren recursivamente todos los elementos del arbol
	void preorder_rec(vector<T>& orden) const
	{
		if (!empty())	
		{
			orden.push_back(root());	
			left().preorder_rec(orden);	
			right().preorder_rec(orden);	
		}
	}

	//Coste O(n), donde n es el numero de elementos del arbol porque se recorren recursivamente todos los elementos del arbol
	void inorder_rec(vector<T>& orden) const
	{
		if (!empty())
		{
			left().inorder_rec(orden);	
			orden.push_back(root());	
			right().inorder_rec(orden);
		}
	}

	//Coste O(n), donde n es el numero de elementos del arbol porque se recorren recursivamente todos los elementos del arbol
	void postorder_rec(vector<T>& orden) const
	{
		if (!empty())
		{
			left().postorder_rec(orden);	
			right().postorder_rec(orden);	
			orden.push_back(root());
		}
	}

	//Coste O(n), donde n es el numero de elementos del arbol porque se recorren recursivamente todos los elementos del arbol
	void levels_rec(vector<T>& orden, queue<bintree<T>>& treeQueue)const
	{
		if (!treeQueue.empty()) 
		{
			if (!treeQueue.front().empty())	
			{
				orden.push_back(treeQueue.front().root());	
				treeQueue.push(treeQueue.front().left());	
				treeQueue.push(treeQueue.front().right());	
			}
			treeQueue.pop(); 
			levels_rec(orden, treeQueue); 
		}
	}

public:
	// constructor de árbol vacío
	bintree() : raiz(nullptr) {} // O(1)

								 // constructor de árbol hoja
	bintree(const T& elem) : raiz(make_shared<Nodo>(elem)) {} // O(1)

															  // constructor de árbol con 2 hijos
	bintree(const bintree<T>& izq, const T& elem, const bintree<T>& der) : // O(1)
		raiz(make_shared<Nodo>(izq.raiz, elem, der.raiz)) {}

	// valor en la raíz (si existe)
	const T& root() const { // O(1)
		if (empty()) {
			throw std::domain_error("No hay raiz en arbol vacio");
		}
		else {
			return raiz->elem;
		}
	}

	// hijo izquierdo (si existe)
	bintree<T> left() const { // O(1)
		return bintree(raiz->izq);
	}

	// hijo derecho (si existe)
	bintree<T> right() const { // O(1)
		return bintree(raiz->der);
	}

	// saber si el árbol es vacío 
	bool empty() const { // O(1)
		return (raiz == nullptr);
	}

	// altura del árbol
	size_t height() const { // O(n), donde 'n' es el número de nodos en el árbol
		if (empty()) {
			return 0;
		}
		else {
			size_t hl = left().height();
			size_t hr = right().height();
			return max<size_t>(hl, hr) + 1;
		}
	}

	// Muestra por 'out' una representación del árbol
	// Adaptado de "ADTs, DataStructures, and Problem Solving with C++", Larry Nyhoff, Person, 2015
	void graph(ostream & out) const { // O(n), donde 'n' es el número de nodos en el árbol
		out << "==== Tree =====" << endl;
		graph_rec(out, 0, raiz);
		out << "===============" << endl;
	}

	//O(n) debido a la llamada al metodo recursivo 
	vector<T> preorder() const
	{
		vector<T> orden;	
		preorder_rec(orden);	
		return orden;	
	}

	//O(n) debido a la llamada al metodo recursivo 
	vector<T> inorder() const
	{
		vector<T> orden;	
		inorder_rec(orden);	
		return orden;	
	}

	//O(n) debido a la llamada al metodo recursivo 
	vector<T> postorder() const
	{
		vector<T> orden;	
		postorder_rec(orden);	
		return orden;	
	}

	//O(n) debido a la llamada al metodo recursivo 
	vector<T> levels() const
	{
		queue<bintree<T>> treeQueue;
		vector<T> orden;
		if (!empty())	
		{
			treeQueue.push(*this);	
			levels_rec(orden, treeQueue);	
		}
		return orden;
	}

	void writeVector(vector<T> v) const
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;
	}
}; 

bintree<int> createTree()
{
	int num;
	cin >> num;
	if (num != 0)
	{
		bintree<int> left = createTree();
		bintree<int> right = createTree();
		bintree<int> arbol(left, num, right);
		return arbol;
	}
	else
	{
		bintree<int> arbol;
		return arbol;
	}
}

int main()
{
	int numCasos;
	vector<int> preorder;
	vector<int> inorder;
	vector<int> postorder;
	vector<int> levels;
	size_t alt;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
	{
		bintree<int> arbol = createTree();
		//arbol.graph(cout);

		preorder = arbol.preorder();
		arbol.writeVector(preorder);

		inorder = arbol.inorder();
		arbol.writeVector(inorder);

		postorder = arbol.postorder();
		arbol.writeVector(postorder);

		levels = arbol.levels();
		arbol.writeVector(levels);

		cout << "==" << endl;
	}

	system("pause");
	return 0;
}