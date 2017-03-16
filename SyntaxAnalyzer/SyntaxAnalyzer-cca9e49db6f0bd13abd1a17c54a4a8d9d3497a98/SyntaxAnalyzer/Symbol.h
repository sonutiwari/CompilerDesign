#pragma once
#include <string.h>
#include<string>
using namespace std;

class Symbol
{
public:
	Symbol(void);
	~Symbol(void);
	Symbol(string,bool);
	string sym;
	bool isTerminal;
};

