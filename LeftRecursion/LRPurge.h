#ifndef PREDICTIONTABLE_LRECURSIONPURGE_H
#define PREDICTIONTABLE_LRECURSIONPURGE_H

#include "readGrammer.h"

bool lrecursionpurge(GrammarRule* s, std::string outputfilename);
void addNewRecursion(char k, char newk, GrammarRule* s);

#endif //PREDICTIONTABLE_LRECURSIONPURGE_H
