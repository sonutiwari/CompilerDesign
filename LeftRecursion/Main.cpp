#include <iostream>
#include "readGrammer.h"
#include "LRPurge.h"

using namespace std;

int main(int ac, char *av[])
{

    string outputFile ("grammar.txt");
    string inputFile ("");

    if (ac < 2 || ac > 3)
    {
        std::cout << "Input Parameters: <input file> [output file] = '" + outputFile + "'" << std::endl;
        return false;
    }

    inputFile = av[1];
    if (ac == 3)
        outputFile = av[2];

    GrammarRule* s = readgrammar(av[1]);
    if (!s)
    {
        std::cout << "Problems reading grammar. Check the input format!" << std::endl;
        return false;
    }

    if (!lrecursionpurge(s, outputFile))
    {
        std::cout << "Error trying to remove recursion from the left of the presented grammar!" << std::endl;
        return false;
    }

    std::cout << "Output is in the file:" + outputFile << std::endl;

    return true;
}
