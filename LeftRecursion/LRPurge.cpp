#include<bits/stdc++.h>
#include "LRPurge.h"
#include "grammer.h"

bool lrecursionpurge(GrammarRule* s, std::string outputfilename)
{


    std::stringbuf a ("");
    std::vector<char> alfabeto = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    std::unordered_map<char, char> map;

    GrammarRule *g = s;

    while (g != NULL)
    {

        for (int i = 0; i < alfabeto.size(); ++i)
        {
            if (alfabeto[i] == g->key->at(0))
            {
                alfabeto.erase(alfabeto.begin()+i);
                break;
            }
        }
        g = g->next;
    }

    g = s;
    while (g != NULL)
    {
        map[g->key->at(0)] = alfabeto.at(0);
        alfabeto.erase(alfabeto.begin());
        g = g->next;
    }

    std::string cc ("");
    g = s;
    while (g != NULL)
    {
        if (g->key->at(0) == g->rule->at(0))
        {
            char k = g->key->at(0);
            char newk = map[g->key->at(0)];

            g->key = new std::string (""); // tem que criar um novo
            *g->key += newk;
            g->rule = new std::string (g->rule->substr(1));

            if (cc.find(k) == std::string::npos)
            {
                *g->rule += newk;

                GrammarRule *nextgrammarrule = (GrammarRule *) malloc(sizeof(GrammarRule));
                nextgrammarrule->key = new std::string("");
                *nextgrammarrule->key += *g->key;
                nextgrammarrule->rule = new std::string("");
                *nextgrammarrule->rule += CARACTER_VAZIO;
                nextgrammarrule->next = g->next;
                g->next = nextgrammarrule;
                g = nextgrammarrule;

                addNewRecursion(k, newk, s);
                cc += k;
            }
        }
        g = g->next;
    }

    std::ofstream myfile;
    myfile.open (outputfilename);
    g = s;
    while (g != NULL)
    {
        myfile << *g->key << "-" << *g->rule << std::endl;
        g = g->next;
    }
    myfile.close();

    return true;
}

void addNewRecursion(char k, char newk, GrammarRule* s)
{

    GrammarRule *g = s;
    while (g != NULL)
    {

        if (g->key->at(0) == k)
        {
            *g->rule += newk;
        }

        g = g->next;
    }


    return;
}
