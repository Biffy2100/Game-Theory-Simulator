#include "Strategy.h"
#include <random>
using namespace std;

static random_device rd;
static mt19937 gen(rd());
static uniform_int_distribution<int> dist(1, 2);

string computerMove(const int choice, int roundNum, const string &move, strategyMemory &memory)
{
    // strategy selector
    switch (choice)
    {
    case 1://always cooperate
        return "cooperate";
    case 2://always defect
        return "defect";
    case 3://random
    {
        int randomNum = dist(gen);
        return (randomNum == 1) ? "cooperate" : "defect";
    }
    case 4://tit for tat 
    {
        if (roundNum == 1)
        {
            memory.previousMove = move;
            return "cooperate";
        }
        else
        {
            string temp = memory.previousMove;
            memory.previousMove = move;
            return temp;
        }
    }
    case 5:{ //Grudger
        if(move == "defect"){
            memory.hasDefected = true;
        }

        if(memory.hasDefected){
            return "defect";
        }else{
            return "cooperate";
        }
    }
    default:
        return "NULL";
    }
}