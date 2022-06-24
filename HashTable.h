#pragma once
#include "HashEntidad.h"
#include "Lista.hpp"

class Hashtable {
private:
	HashEntidad** tabla;
	Lista<HashEntidad*> lista;
	int numElementos;
	int Table_Size;

public:
	Hashtable(int table_size) {
		this->Table_Size = table_size;
		tabla = new HashEntidad * [table_size];

		for (int i = 0; i < table_size; i++)
			tabla[i] = nullptr;

		numElementos = 0;
	}

	~Hashtable() {
		for (int i = 0; i < Table_Size; i++) {
			if (tabla[i] != nullptr)
				delete tabla[i];
		}
		delete[] tabla;
	}

	void insertar(int key, string value) {
		int base, hash, step;

		if (numElementos == Table_Size) return;

		base = key % Table_Size;
		hash = base;
		step = 0;

		while (tabla[hash] != nullptr) {
			hash = (base + step) % Table_Size;
			step++;
		}

		tabla[hash] = new HashEntidad(key, value);
		numElementos++;
	}

	int size() { return Table_Size; }

	int sizeActual() { return numElementos; }

	int buscar(int key) {
		int step = 0;
		int i, base;
		i = base = key % Table_Size;

		while (true) {
			if (tabla[i] == nullptr) return -1;

			else if (tabla[i]->getKey() == key) return i;

			else step++;

			i = (base + step) % Table_Size;

		}
	}

};