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

struct stGameResults
{
    bool PlayerWin = false;
    bool CompWin = false;
    
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

stGameResults CheckWinner(enRockPaperScissors UserChoice, enRockPaperScissors CompChoice) {
    stGameResults Result;
    Result.CompWinRounds = 0;
    Result.PlayerWinRounds = 0;
    switch (UserChoice) {
    case enRockPaperScissors::Rock :
        if (CompChoice == enRockPaperScissors::Paper)
        {
            Result.CompWin = true;
            Result.CompWinRounds++;
            break;
        }
        else if (CompChoice == enRockPaperScissors::Scissors)
        {
            Result.PlayerWin = true;
            Result.PlayerWinRounds++;
            break;
        }
        break;

    case enRockPaperScissors::Paper :
        if (CompChoice == enRockPaperScissors::Scissors)
        {
            Result.CompWin = true;
            Result.CompWinRounds++;
            break;
        }
        else if (CompChoice == enRockPaperScissors::Rock)
        {
            Result.PlayerWin = true;
            Result.PlayerWinRounds++;
            break;
        }
        break;
    case enRockPaperScissors::Scissors :
        if (CompChoice == enRockPaperScissors::Rock)
        {
            Result.CompWin = true;
            Result.CompWinRounds++;
            break;
        }
        else if (CompChoice == enRockPaperScissors::Paper)
        {
            Result.PlayerWin = true;
            Result.PlayerWinRounds++;
            break;
        }
        break;

    }
    return Result;
}

void ShowFinalGameResults(stGameResults GameResults) {
    cout << "Player Won Times : " << GameResults.PlayerWinRounds << endl;
    cout << "comp Won Times : " << GameResults.CompWinRounds << endl;
}

void PrintRoundResult(stGameResults Result) {
    if (Result.CompWin)
    {
        cout << "computer win : " << endl;
    }
    else if (Result.PlayerWin)
    {
        cout << "Player win : " << endl;
    }
    else {
        cout << "Draw" << endl;
    }
}

void StartRound(int Rounds , stGameResults Result) {
    
    enRockPaperScissors UserChoice, CompChoice;
    for (int i = 0; i < Rounds; i++)
    {
        cout << "Round " << i << " Begins : " << endl;
        UserChoice = ReadUserChoice("Your choice : [1] : Rock, [2] : Paper, [3] : Scissors ? ");
        CompChoice = RandomChoice();
        PrintRoundResult(CheckWinner(UserChoice, CompChoice));
    }


}

bool TryAgain() {
    bool TryAgain;
    cout << "Try Again ? " << endl;
    cin >> TryAgain;
    return TryAgain;
}

void StartGame() {
    int Rounds;
    bool PlayAgain;
    do
    {
        Rounds = ReadRounds("How Many Rounds ? From 1 to 10  ? ");
        stGameResults GameResult;
        StartRound(Rounds, GameResult);
        ShowFinalGameResults(GameResult);
        PlayAgain = TryAgain();
    } while (PlayAgain);
}

int main()
{
    srand((unsigned)time(NULL));

    StartGame();
    
    
    return 0;
}
