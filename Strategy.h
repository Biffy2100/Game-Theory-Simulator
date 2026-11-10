#ifndef STRATEGY_H // If STRATEGY_H hasn't been defined...
#define STRATEGY_H // ...define it now.

#include <string>

using namespace std;

struct strategyMemory
{
    string previousMove = "cooperate";
    bool hasDefected = false;
};

string computerMove(
    const int choice,
    int roundNum,
    const string &move,
    strategyMemory &memory);

#endif // End of the include guard