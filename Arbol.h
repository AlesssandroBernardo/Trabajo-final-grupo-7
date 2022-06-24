#pragma once
#include<functional>
using namespace std;
template<class T>
class Node {

public:
	T elemento;
	Node* izq;
	Node* der;
};

template <class T>

class ArbolBB {
	typedef function<int(T, T)> Comp;
	Node<T>* raiz;
	void(*procesar)(T); 
	Comp comparar;	
private:

	bool _buscar(Node<T>* node, T e) {
		if (node == nullptr) return false;
		else {
			int r = comparar(node->elemento, e);
			if (r == 0) return true;
			else if (r < 0) {
				return _buscar(node->der, e);
			}
			else{
				return _buscar(node->izq, e);
			}
		}
	}
	bool _insertar(Node<T>*&node, T e) {

		if (node == nullptr) {
			node = new Node<T>();
			node->elemento = e;
			return true;
		}
		else {
			int r = comparar(node->elemento, e);
			if (r == 0) return false;
			else if (r < 0) {
				return _insertar(node->der, e);
			}
			else {
				return _insertar(node->izq, e);
			}
		}
	}

	void _enOrden(Node<T>* Node) {
		if (Node == nullptr) return;
		_enOrden(Node->izq);
		procesar(Node->elemento);
		_enOrden(Node->der);
	}

	void _preOrden(Node<T>* Node) {
		if (Node == nullptr) return;
		procesar(Node->elemento);
		_preOrden(Node->izq);
		_preOrden(Node->der);
	}

	void _postOrden(Node<T>* Node) {

		if (Node == nullptr) return;
		_postOrden(Node->izq);
		_postOrden(Node->der);
		procesar(Node->elemento);

	}
	bool _vacio() {

		return raiz = nullptr;

	}
	int _cantidad(Node<T>* Node) {

		if (Node == nullptr) return 0;
		else{
			int ci, cd;
			ci = _cantidad(Node->izq);
			cd = _cantidad(Node->der);
			return 1 + ci + cd;
		}
	}

	int _altura(Node<T>* Node) {
		if (Node == nullptr) return 0;

		else {
			int ai, ad;
			ai = 1 + _altura(Node->izq);
			ad = 1 + _altura(Node->der);
			return ai > ad ? ai : ad;
		}
	}

	int _minimo(Node<T>* Node) {
		if (Node->izq == nullptr) return Node->elemento;
		else
			return _minimo(Node->izq);
	}

	int _maximo(Node<T>* Node) {
		if (Node->der == nullptr) return Node->elemento;
		else
			return _maximo(Node->der);
	}

	bool _eliminar(Node<T>*& Node, T e) {
		if (Node == nullptr) {
			return false;
		}
		else {
			int r = comparar(Node->elemento, e);
			if (r < 0) {
				return _eliminar(Node->der, e);
			}
			else if (r > 0) {
				return _eliminar(Node->izq, e);
			}
			else {
				if (Node->der == nullptr && Node->izq == nullptr) {
					Node = nullptr;
					delete Node;
					return true;
				}
				else if (Node->izq == nullptr) {
					Node = Node->der;
					return true;
				}
				else if (Node->der == nullptr) {
					Node = Node->izq;
					return true;
				}
				else {
					Node<T>* aux = Node->der;
					while (aux->izq != nullptr) {
						aux = aux->izq;
					}
					Node->elemento = aux->elemento;
					return _eliminar(Node->der, aux->elemento);
				}
			}
		}

	}
public:

	ArbolBB(void(*otroPunteroAFuncion)(T)) {
		this->procesar = otroPunteroAFuncion;
		this->comparar = [](T a, T b)->int {return a - b; };
		raiz = nullptr;
	}

	bool insertar(T e) {
		return _insertar(raiz, e);
	}

	void enOrden() {
		_enOrden(raiz);
	}

	void preOrden() {
		_preOrden(raiz);
	}

	void postOrden() {
		_postOrden(raiz);
	}

	int cantidad() {
		return _cantidad(raiz);
	}

	int altura() {
		return _altura(raiz);
	}

	bool Buscar(T e) {
		return _buscar(raiz, e);
	}

	int Minimo() {
		return _minimo(raiz);
	}

	bool Eliminar(T e) {
		return _eliminar(raiz, e);
	}

	int Maximo() {
		return _maximo(raiz);
	}
};
