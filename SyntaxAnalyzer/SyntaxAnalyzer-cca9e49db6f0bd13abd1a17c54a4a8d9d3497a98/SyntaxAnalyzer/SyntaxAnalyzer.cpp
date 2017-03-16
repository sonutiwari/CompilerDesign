#include "stdafx.h"
#include "SyntaxAnalyzer.h"


SyntaxAnalyzer::SyntaxAnalyzer(void)
	{
	}


SyntaxAnalyzer::~SyntaxAnalyzer(void)
	{
	}

SyntaxAnalyzer::SyntaxAnalyzer(string CFGfilePath)
	{

	FILE* GrammerFile = fopen(CFGfilePath.c_str(),"r");
	if (GrammerFile==NULL)
		{
		cout << "Can't open file" << endl;
		}


	//read the file line by line and sent this line to parse line method

	vector<string> grammerLines;
	string lineStr;
	char line[1000];
	while( fgets(line,1000,GrammerFile) != NULL ){
		line[1000];
		string lineStr(line);
		unsigned  pos = lineStr.find("\n");
		lineStr = lineStr.substr (0,pos);
		grammerLines.push_back(lineStr);
		//cout<< lineStr;
		}

	/*
	grammerLines.push_back("# IF = ‘if’ ‘(‘ EXPRESSION ‘)’ ‘{‘ STATEMENT ’}’ ‘else’ ‘{’ STATEMENT ‘}’");
	grammerLines.push_back("# STATEMENT = DECLARATION");
	grammerLines.push_back("| IF");
	grammerLines.push_back("| WHILE");
	grammerLines.push_back("| ASSIGNMENT");
	*/
	for (int i =0 ; i < grammerLines.size(); i++){
		string lineExact;
		if( !grammerLines.at(i).empty() && grammerLines.at(i).at(0) == '#' ){
			lineExact = grammerLines.at(i).substr(1,grammerLines.at(i).size());
			for( int k = i+1 ; k < grammerLines.size() ; k++){
				if( !grammerLines.at(k).empty() && grammerLines.at(k).at(0) != '#' ){
					lineExact += grammerLines.at(k);
					}else{
						break;
					}
				}
			parseLine(lineExact);
			}
		}

	//@ this point the CFG map and the nonTerminal list are built

	//the bonus part gets called here, using the convTools object
	//convTool.init(&CFG);

	// call computeFirst(), then call computeFollow(), then call computeParsingTable()
	computeFirst();
	computeFollow();
	computeParsingTable();

	// now we can call the simulation part
	simulate();// i haven't thought about the design of the simulation part, or where to put it

	}

void SyntaxAnalyzer::parseLine(string line)
	{
	int equalIndex = line.find('=');
	string nonTerminalString = spaceRemove(line.substr(0,equalIndex));
	nonTerminal.push_back(nonTerminalString);
	vector<string> OrSplit = split(line.substr(equalIndex+1,line.size()),'|');
	vector<vector<Symbol>> CFGRow;

	for ( int i = 0 ; i <  OrSplit.size(); i++){
		vector<Symbol> andSplit = splitSymbol(OrSplit.at(i),' ');
		CFGRow.push_back(andSplit);
		}

	if( OrSplit.empty() ){
		vector<Symbol> andSplit = splitSymbol(line.substr(equalIndex+1,line.size()),' ');
		CFGRow.push_back(andSplit);
		}

	CFG[nonTerminalString] = CFGRow;
	}


void SyntaxAnalyzer::computeFirst()
	{

	//for (std::map<string,vector<vector<Symbol>>>::iterator it=CFG.begin(); it!=CFG.end(); ++it){
	for( int index = 0 ; index < nonTerminal.size() ; index++){
		string nonTerminalName = nonTerminal.at(index);
		vector<vector<Symbol>> CFGRow = CFG[nonTerminalName];
		vector<string> firstForRow;
		vector<string> pindVector;
		for(int i = 0 ; i < CFGRow.size() ; i++ ){

			if( CFGRow.at(i).at(0).isTerminal ){
				firstForRow.push_back(CFGRow.at(i).at(0).sym);
				//first[nonTerminalName]=firstForRow;
				}else{
					///pindVector = computeFirst(CFGRow.at(i).at(0));



					map<string,vector<string>>::iterator it2 = first.find(CFGRow.at(i).at(0).sym);
					vector<string> symbolFirst;
					if(it2 != first.end())
						{
						// Found in First map
						symbolFirst = it2->second;
						for(int i = 0; i < symbolFirst.size() ; i++){
							for( int k = 0 ; k < firstForRow.size() ; k++){
								if( firstForRow.at(k).compare(symbolFirst.at(i)) == 0 ){
									continue;
									}
								firstForRow.push_back(symbolFirst.at(i));
								}
						}

						//first[nonTerminalName]=firstForRow;

						}else{
							pindVector = computeFirst(CFGRow.at(i).at(0));

							for(int i = 0 ; i < pindVector.size() ; i++){
								bool add = true;
								for(int k = 0 ; k < firstForRow.size() ; k++){
									if( firstForRow.at(k).compare(pindVector.at(i)) == 0 ){
										add = false;
										break;
										}
									}
								if( add ){
									firstForRow.push_back(pindVector.at(i));
									}
								}
							//first[nonTerminalName]=firstForRow;
						}



				}
			first[nonTerminalName]=firstForRow;
			}
		}
	}

vector<string> SyntaxAnalyzer::computeFirst(Symbol symbol){

	vector<string> symbolFirst;
	vector<string> firstForRow;

	vector<vector<Symbol>> row = CFG[symbol.sym];
	vector<vector<string>> rowFirst;
	for ( int i = 0 ; i < row.size(); i++){
		if( row.at(i).at(0).isTerminal){
			vector<string> temp;
			temp.push_back(row.at(i).at(0).sym);
			rowFirst.push_back(temp);
			}else{
				map<string,vector<string>>::iterator it = first.find(row.at(i).at(0).sym);
				if(it != first.end()){
					rowFirst.push_back(first[row.at(i).at(0).sym]);
					}else{

						rowFirst.push_back(computeFirst(row.at(i).at(0)));
					}
			}
		}
	for( int i = 0 ; i< rowFirst.size(); i ++){
		for ( int k = 0 ; k < rowFirst.at(i).size() ; k++){
			firstForRow.push_back(rowFirst.at(i).at(k));
			}
		}
	first[symbol.sym]=firstForRow;

	return firstForRow;
	}

void SyntaxAnalyzer::computeFollow()
	{
	}

void SyntaxAnalyzer::computeParsingTable()
	{
	}

void SyntaxAnalyzer::simulate()
	{
	}

vector<string> SyntaxAnalyzer::split(const string& s, char c) {
	vector<string> v;
	string::size_type i = 0;
	string::size_type j = s.find(c);

	while (j != string::npos) {
		if (!(s.substr(i, j-i).empty())){
			v.push_back(s.substr(i, j-i));
			}
		i = ++j;
		j = s.find(c, j);

		if (j == string::npos  && !(s.substr(i, s.length()).empty()) )
			v.push_back(s.substr(i, s.length()));
		}
	return v;
	}

vector<Symbol> SyntaxAnalyzer::splitSymbol(const string& s, char c) {
	vector<Symbol> v;
	string::size_type i = 0;
	string::size_type j = s.find(c);
	Symbol sym;
	while (j != string::npos) {
		if (!(s.substr(i, j-i).empty())){
			string tempString = ((s.substr(i, j-i).at(0) =='\'') && (s.substr(i, j-i).at(s.substr(i, j-i).size()-1) =='\'' ) ) ? s.substr(i+1, (j-i)-2):s.substr(i, j-i);
			if(tempString.at(tempString.size()-1) == '\'' ){
				tempString = tempString.substr(0,tempString.size()-1);
				}
			bool tempBool = ( (s.substr(i, j-i).at(0) =='\'') && (s.substr(i, j-i).at(s.substr(i, j-i).size()-1) =='\'' ) ) ? true:false;
			Symbol temp( tempString, tempBool);
			// v.push_back( Symbol( ((s.substr(i, j-i).at(0) =='\'') && (s.substr(i, j-i).at(s.substr(i, j-i).size()-1) =='\'' ) ) ? s.substr(i+1, (j-i)-2):s.substr(i, j-i),
			// ( (s.substr(i, j-i).at(0) =='\'') && (s.substr(i, j-i).at(s.substr(i, j-i).size()-1) =='\'' ) ) ? true:false) );
			v.push_back(temp);
			if(temp.isTerminal){
				if(temp.sym.at(0)!='\\')
					addTerminal(temp.sym);
				}
			}
		i = ++j;
		j = s.find(c, j);

		if (j == string::npos  && !(s.substr(i, s.length()).empty()) ){
			string temp2String = ((s.substr(i, s.length()).at(0) =='\'') && (s.substr(i, s.length()).at(s.substr(i, s.length()).size()-1) =='\'')) ?  s.substr(i+1, s.length()-2) :s.substr(i, s.length());
			if(temp2String.at(temp2String.size()-1) == '\'' ){
				temp2String = temp2String.substr(0,temp2String.size()-1);
				}
			Symbol temp2(  temp2String,
				((s.substr(i, s.length()).at(0) =='\'') && (s.substr(i, s.length()).at(s.substr(i, s.length()).size()-1) =='\'')) ? true:false);
			v.push_back(temp2);
			if(temp2.isTerminal){
				addTerminal(temp2.sym);
				}
			//v.push_back( Symbol(  ((s.substr(i, s.length()).at(0) =='\'') && (s.substr(i, s.length()).at(s.substr(i, s.length()).size()-1) =='\'')) ?  s.substr(i+1, s.length()-2) :s.substr(i, s.length()),
			//((s.substr(i, s.length()).at(0) =='\'') && (s.substr(i, s.length()).at(s.substr(i, s.length()).size()-1) =='\'')) ? true:false) );
			}
		}
	return v;
	}

string SyntaxAnalyzer::spaceRemove(string symbol){
	string temp = "";
	for ( int i = 0 ; i < symbol.size() ; i++){
		if( symbol.at(i) != ' '){
			temp += symbol.at(i);
			}
		}
	return temp;
	}

void SyntaxAnalyzer::addTerminal(string sym){
	for ( int i = 0 ; i < Terminal.size() ; i++){
		if(Terminal.at(i).compare(sym)==0){
			return;
			}
	}
	Terminal.push_back(sym);
	}

int main (int arg,char** args){
	cout << "Working Main" << endl;
	SyntaxAnalyzer f("input4.txt");
	//string test = "IF = 'if' '(' EXPRESSION ')' '{' STATEMENT '}' 'else' '{' STATEMENT '}'";
	//f.parseLine(test);
	//system("pause");
	}
