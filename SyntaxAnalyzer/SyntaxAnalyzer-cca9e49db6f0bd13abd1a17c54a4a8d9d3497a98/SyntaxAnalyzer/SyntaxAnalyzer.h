#pragma once
#include <map>
#include <string.h>
#include <list>
#include <vector>
#include <string>
#include <iostream>
#include "Symbol.h"
#include "LL1GrammarConversionTool.h"

using namespace std;

//non_terminal,first,follow,map,table,CFG

class SyntaxAnalyzer
{
public:
	SyntaxAnalyzer(void);
	SyntaxAnalyzer(string);
	~SyntaxAnalyzer(void);
	map<string,vector<string>> first; // clear enough
	map<string,vector<string>> follow; // clear enough
	vector<string> nonTerminal;// while constructing the CFG map from the Grammar file, this is a simple list that gets filled with strings of the non Terminal symbols, to later iterate on them while computing first and follow
	vector<string> Terminal;// while constructing the CFG map from the Grammar file, this is a simple list that gets filled with strings of the Terminal symbols, to later iterate on them while computing first and follow
	LL1GrammarConversionTool convTool; // object used to send the CFG map to and return a new map, that is left recursion and left factoring free.
	///////////////////////////////////////////////////////////////////
	vector<string> split(const string& s, char c);
	string spaceRemove(string symbol);
	vector<Symbol> splitSymbol(const string& s, char c);
	void addTerminal(string);
	vector<string> computeFirst(Symbol symbol);
	//////////////////////////////////////

	map<string,vector<vector<Symbol>>> CFG; // the constructor reads the file, then constructs this map in the following format
	// for example AA ::= BB | CC DD | EE FF GG
	// this is equal to one map element which in which the key is a symbol of value ("AA",false), and it has a list of three element
	// the first element is a list containing only one element BB
	// the second element is a list containing two elements, CC & DD
	// the third element is a list containing three elements, EE, FF & DD

	void parseLine(string);//takes a grammar line from the file, and then parse it and puts it into the CFG map
	// it was said that a single grammar line could expand over several lines, but this method takes a whole grammar line
	//and it's the job of the calling method to handle this

	void computeFirst();// this method is called after the CFG map is built, it then computes the first map, called in constructor

	void computeFollow();// this method is called after the first map is built, it then computes the follow map, called in constructor

	void computeParsingTable();// this method is called after the follow map is built, it then computes the parsing Table, called in constructor

	void simulate(); // ??
	// we still need to modify the simulation of the previous part, so that it can support getNextToken() for the simulation of this part;
	};