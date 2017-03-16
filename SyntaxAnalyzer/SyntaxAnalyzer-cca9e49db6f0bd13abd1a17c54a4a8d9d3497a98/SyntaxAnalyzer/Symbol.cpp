#include "stdafx.h"
#include "Symbol.h"


Symbol::Symbol(void)
{
}

Symbol::Symbol(string s, bool b)
{
	sym = s;
	isTerminal = b;
}

Symbol::~Symbol(void)
{
}
