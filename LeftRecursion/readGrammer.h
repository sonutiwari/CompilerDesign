#ifndef PREDICTIONTABLE_READGRAMAR_H
#define PREDICTIONTABLE_READGRAMAR_H

#include <stdio.h>
#include <sstream>

struct gramaticalrule
{
    struct gramaticalrule *next;
    std::string *rule;
    std::string *key;
};

typedef struct gramaticalrule GrammarRule;

GrammarRule* readgrammar(char *filename);
bool readRule(FILE *arquivoDeEntrada, GrammarRule* gramarrule);


#endif //PREDICTIONTABLE_READGRAMAR_H
