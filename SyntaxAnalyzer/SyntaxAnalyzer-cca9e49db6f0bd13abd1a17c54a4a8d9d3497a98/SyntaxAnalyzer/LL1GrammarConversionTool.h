#pragma once
#include "Symbol.h"
#include <map>
#include <list>

class LL1GrammarConversionTool
{
public:
	LL1GrammarConversionTool(void);
	void init(map<Symbol,list<list<Symbol>>>* CFG); // takes the CFG
	void removeLeftRecursion(map<Symbol,list<list<Symbol>>>* CFG); // clear, it edits the map whose pointer is in the parameters
	void LeftFactoring(map<Symbol,list<list<Symbol>>>* CFG); // clear, it edits the map whose pointer is in the parameters
	~LL1GrammarConversionTool(void);
	map<Symbol,list<list<Symbol>>>* CFG;
};

