#include <iostream>
#include "Strategy.h"

using namespace std;

bool calculateScore(const string &p1, const string &p2, int &p1score, int &p2score)
{

    if (p1 != "cooperate" && p1 != "defect")
    {
        cout << "Invalid input for p1" << endl;
        return false;
    }

    if (p2 != "cooperate" && p2 != "defect")
    {
        cout << "Invalide input for p2" << endl;
        return false;
    }

    if (p1 == "cooperate" && p2 == "cooperate")
    {
        p1score += 3;
        p2score += 3;
        return true;
    }
    else if (p1 == "cooperate" && p2 == "defect")
    {
        p2score += 5;
        return true;
    }
    else if (p1 == "defect" && p2 == "cooperate")
    {
        p1score += 5;
        return true;
    }
    else if (p1 == "defect" && p2 == "defect")
    {
        p1score += 1;
        p2score += 1;
        return true;
    }

    return false;
}

int main()
{

    int r = 0;

    cout << "Enter the number of rounds: ";
    cin >> r;
    cout << endl;

    if (r <= 0)
    {
        cout << "Invalid number of rounds entered";
        return 1;
    }

    int strategy;
    cout << "Computer strategies: " << endl;
    cout << "1. Always cooperate " << endl;
    cout << "2. Always defect " << endl;
    cout << "3. Random" << endl;
    cout << "4. Tit for Tat " << endl;
    cout << "5. Grudger " << endl;
    cout << "Select computer strategy: ";

    cin >> strategy;
    if (strategy < 1 || strategy > 5)
    {
        cout << "Invalid input for strategy!" << endl;
        return 1;
    }

    int p1score = 0;
    int p2score = 0;

    int rounds = 1;


    strategyMemory memory;

    while (r--)
    {
        cout << "========== Prisoner's Dilemma ==========" << endl;
        cout << "Round " << rounds << endl;
        cout << "------------------------------" << endl;
        cout << "Choose (cooperate/defect)" << endl;

        string p1, p2;

        cout << "Enter what p1 wants to do" << endl;
        cin >> p1;

        p2 = computerMove(strategy, rounds, p1, memory);

        cout << "============================" << endl;
        cout << "Computer chose to " << p2 << endl;
        cout << "============================" << endl;

        if (calculateScore(p1, p2, p1score, p2score))
        {
            cout << "Score card:\n"
                 << "P1: " << p1score << "\n"
                 << "P2: " << p2score << endl;
        }
        else
        {
            cout << "Failure during calculation" << endl;
            return 1;
        }
        rounds++;
    }

    cout << "-------------------------------------" << endl;

    if (p1score == p2score)
    {
        cout << "Draw between both players" << endl;
    }
    else
    {
        (p1score > p2score) ? cout << "Player 1 wins!" << endl : cout << "Player 2 wins!" << endl;
    }

    return 0;
}