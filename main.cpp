#include <iostream>
using namespace std;

int main()
{
    string p1, p2;
    int p1score = 0;
    int p2score = 0;

    // printf("Basic Prisoner's Dilemma");
    cout << "Basic Prisoner's Dilemma" << endl;

    cout << "Choices are : cooperate OR defect" << endl;

    cout << "Enter what p1 wants to do" << endl;
    cin >> p1;

    cout << "Enter what p2 wants to do" << endl;
    cin >> p2;

    if (p1 == "cooperate" && p2 == "cooperate")
    {
        p1score += 3;
        p2score += 3;
    }
    else if (p1 == "cooperate" && p2 == "defect")
    {
        p2score += 5;
    }
    else if (p1 == "defect" && p2 == "cooperate")
    {
        p1score += 5;
    }
    else
    {
        p1score += 1;
        p2score += 1;
    }

    cout << "Score card:\n"
         << "P1: " << p1score << "\n"
         << "P2: " << p2score << endl;

    return 0;
}