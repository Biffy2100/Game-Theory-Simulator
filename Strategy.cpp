#include "Strategy.h"
#include<random>
using namespace std;


string computerMove(const int x)
{
    // strategy selector using x
    if (x == 1)
        return "cooperate";
    else if (x == 2)
        return "defect";
    else if (x == 3)
    {
        random_device rd;
        mt19937 mt(rd());
        uniform_int_distribution<int> dist(1, 2);
        int randomNum = dist(mt);
        return (randomNum == 1) ? "cooperate" : "defect";
    }
    return "NULL";
}