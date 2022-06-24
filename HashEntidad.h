#pragma once
#include <string>

using namespace std;

class HashEntidad {
	int key;
	string value;

public:
	HashEntidad(int k = 0, string v = "") :key(k), value(v) {}

	int getKey() { return key; }
	string getValue() { return value; }
};