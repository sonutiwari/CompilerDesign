#include<bits/stdc++.h>
#include "readGrammer.h"

GrammarRule* readgrammar(char *filename)
{
    FILE *arquivoDeEntrada = fopen(filename, "rt");

    if (arquivoDeEntrada == NULL)
    {
        std::cout << "Problems opening the file" << std::endl;
        return nullptr;
    }

    GrammarRule *s = (GrammarRule*) malloc(sizeof(GrammarRule));
    s->next = NULL;
    if (!readRule(arquivoDeEntrada, s))
        return nullptr;

    GrammarRule *currentgrammarrule = s;
    GrammarRule *nextgrammarrule;
    while (!feof(arquivoDeEntrada))
    {
        nextgrammarrule = (GrammarRule*) malloc(sizeof(GrammarRule));
        nextgrammarrule->next = nullptr;

        if (!readRule(arquivoDeEntrada, nextgrammarrule))
            break;

        while (currentgrammarrule->next != nullptr)
            currentgrammarrule = currentgrammarrule->next;

        currentgrammarrule->next = nextgrammarrule;
        currentgrammarrule = nextgrammarrule;
    }

    fclose(arquivoDeEntrada);
    return s;
}

bool readRule(FILE *arquivoDeEntrada, GrammarRule  *gramarrule)
{


    char currentchar;
    char key = (char) fgetc(arquivoDeEntrada);

    if (!isupper(key))
        return false;

    gramarrule->key = new std::string ("");
    *gramarrule->key += key;
    gramarrule->rule = new std::string ("");

    int separator = fgetc(arquivoDeEntrada);
    if (separator != '-')
        return false;

    while (true)
    {

        while (!feof(arquivoDeEntrada) && (currentchar = (char) fgetc(arquivoDeEntrada)) != '|' && currentchar != '\n' && currentchar != EOF)
        {
            if (currentchar != ' ')
            {
                *gramarrule->rule += currentchar;

            }
        };

        if (currentchar == '|')
        {
            GrammarRule *nextgrammarrule = (GrammarRule*) malloc(sizeof(GrammarRule));
            nextgrammarrule->key = new std::string ("");
            *nextgrammarrule->key += *gramarrule->key;
            nextgrammarrule->rule = new std::string ("");
            nextgrammarrule->next = nullptr;
            gramarrule->next = nextgrammarrule;
            gramarrule = nextgrammarrule;
            continue;
        }

        break;
    };

    return true;
}

