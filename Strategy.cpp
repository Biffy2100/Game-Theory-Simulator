#include "Strategy.h"
#include <random>
using namespace std;

static random_device rd;
static mt19937 gen(rd());
static uniform_int_distribution<int> dist(1, 2);

string computerMove(const int choice, int roundNum, const string &move, string &prevMove)
{
    // strategy selector
    switch (choice)
    {
    case 1:
        return "cooperate";
    case 2:
        return "defect";
    case 3:
    {
        int randomNum = dist(gen);
        return (randomNum == 1) ? "cooperate" : "defect";
    }
    case 4:
    {
        string prevMove;
        if (roundNum == 1)
        {
            prevMove = move;
            return "cooperate";
        }
        else
        {
            string result = prevMove;
            prevMove = move;
            return result;
        }
    }
    default:
        return "NULL";
    }
}