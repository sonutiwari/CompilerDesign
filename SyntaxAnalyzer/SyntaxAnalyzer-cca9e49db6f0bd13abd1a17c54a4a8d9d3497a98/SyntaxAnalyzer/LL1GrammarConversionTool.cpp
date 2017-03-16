#include "stdafx.h"
#include "LL1GrammarConversionTool.h"


LL1GrammarConversionTool::LL1GrammarConversionTool(void)
{
}


LL1GrammarConversionTool::~LL1GrammarConversionTool(void)
{
}


void LL1GrammarConversionTool::init(map<Symbol,list<list<Symbol>>>* CFG)
{
	removeLeftRecursion(CFG);
	LeftFactoring(CFG);

}

void LL1GrammarConversionTool::removeLeftRecursion(map<Symbol,list<list<Symbol>>>* CFG){
}

void LL1GrammarConversionTool::LeftFactoring(map<Symbol,list<list<Symbol>>>* CFG)
{
}