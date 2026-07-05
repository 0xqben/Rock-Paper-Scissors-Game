// Rock-Paper-Scissors Game.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <cstdlib>

using namespace std;

enum enRockPaperScissors
{
    Rock=1,
    Paper=2,
    Scissors=3,
};

struct stResults
{
    int PlayerWinRounds;
    int CompWinRounds;
};

int RandomNumber(int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

enRockPaperScissors RandomChoice() {
    int RandomChoice = RandomNumber(1, 3);
    switch (RandomChoice) {
    case 1 : 
        return enRockPaperScissors::Rock;
    case 2 : 
        return enRockPaperScissors::Paper;
    case 3 : 
        return enRockPaperScissors::Scissors;
    }
}

void TestRandomChoice() {
    for (int i = 0; i <= 20; i++)
    {
        switch (RandomChoice()) {
        case enRockPaperScissors::Rock :
            cout << "Random choice " << i << " is rock " << endl;
            break;
        case enRockPaperScissors::Paper :
            cout << "Random choice " << i << " is paper " << endl;
            break;
        case enRockPaperScissors::Scissors :
            cout << "Random choice " << i << " is scissors " << endl;
            break;
        }
    }
}

int ReadRounds(string Message) {
    int Rounds;
    do
    {
        cout << Message << endl;
        cin >> Rounds;
    } while (Rounds < 0 && Rounds > 10);
    return Rounds;
}

enRockPaperScissors ReadUserChoice(string Message) {
    int Input = 0;
    do
    {
        cout << Message << endl;
        cin >> Input;
    } while (Input > 3 || Input < 1);

    switch (Input) {
    case 1 : 
        return enRockPaperScissors::Rock;
    case 2 : 
        return enRockPaperScissors::Paper;
    case 3 : 
        return enRockPaperScissors::Scissors;
    }

}

int main()
{
    srand((unsigned)time(NULL));

    
    
    return 0;
}
