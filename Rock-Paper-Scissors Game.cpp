// Rock-Paper-Scissors Game.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <cstdlib>

enum enRockPaperScissors
{
    Rock=1,
    Paper=2,
    Scissors=3,
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

int main()
{
    srand((unsigned)time(NULL));


}
