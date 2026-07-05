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
    int DrawRounds;
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

stGameResults CheckWinner(enRockPaperScissors UserChoice, enRockPaperScissors CompChoice , stGameResults Result) {

    switch (UserChoice) {
    case enRockPaperScissors::Rock :
        if (CompChoice == enRockPaperScissors::Paper)
        {
            Result.CompWin = true;
            
            break;
        }
        else if (CompChoice == enRockPaperScissors::Scissors)
        {
            Result.PlayerWin = true;
            
            break;
        }
        break;

    case enRockPaperScissors::Paper :
        if (CompChoice == enRockPaperScissors::Scissors)
        {
            Result.CompWin = true;
            
            break;
        }
        else if (CompChoice == enRockPaperScissors::Rock)
        {
            Result.PlayerWin = true;
            
            break;
        }
        break;
    case enRockPaperScissors::Scissors :
        if (CompChoice == enRockPaperScissors::Rock)
        {
            Result.CompWin = true;
            
            break;
        }
        else if (CompChoice == enRockPaperScissors::Paper)
        {
            Result.PlayerWin = true;
            break;
        }
        break;

    }
    return Result;
}

void ShowFinalGameResults(stGameResults GameResults , int Rounds) {
    cout << "Game rounds " << Rounds << endl;
    cout << "Player Won Times : " << GameResults.PlayerWinRounds << endl;
    cout << "comp Won Times : " << GameResults.CompWinRounds << endl;
}

void PrintRoundResult(stGameResults& Result , enRockPaperScissors UserChoice , enRockPaperScissors CompChoice) {
    if (Result.CompWin)
    {
        Result.CompWinRounds++;
        cout << "\nPlayer choice " << UserChoice << endl;
        cout << "Comp Choice : " << CompChoice << endl;
        cout << "\n==computer win : ==" << endl;
        cout << "\ncomp score : " << Result.CompWinRounds << endl;
        cout << "\nplayer score : " << Result.PlayerWinRounds << endl;
    }
    else if (Result.PlayerWin)
    {
        Result.PlayerWinRounds++;
        cout << "\nPlayer choice " << UserChoice << endl;
        cout << "Comp Choice : " << CompChoice << endl;
        cout << "\n===Player win : ===" << endl;
        cout << "\ncomp score : " << Result.CompWinRounds << endl;
        cout << "\nplayer score : " << Result.PlayerWinRounds << endl;
    }
    else {
        Result.DrawRounds++;
        cout << "\nPlayer choice " << UserChoice << endl;
        cout << "Comp Choice : " << CompChoice << endl;
        cout << "\n===Draw===" << endl;
        cout << "\ncomp score : " << Result.CompWinRounds << endl;
        cout << "\nplayer score : " << Result.PlayerWinRounds << endl;
    }
}

void StartRound(int Rounds , stGameResults& Result) {
    enRockPaperScissors UserChoice, CompChoice;
    for (int i = 1; i <= Rounds; i++)
    {
        cout << "\n\nRound " << i << " Begins : " << endl;
        UserChoice = ReadUserChoice("Your choice : [1] : Rock, [2] : Paper, [3] : Scissors ? ");
        CompChoice = RandomChoice();
        Result = CheckWinner(UserChoice, CompChoice , Result);
        PrintRoundResult(Result , UserChoice , CompChoice);
    }
}

bool TryAgain() {
    bool TryAgain;
    cout << "\nTry Again ? " << endl;
    cin >> TryAgain;
    return TryAgain;
}

void StartGame() {
    int Rounds;
    bool PlayAgain;
    do
    {
        Rounds = ReadRounds("How Many Rounds ? From 1 to 10  ? \n");
        stGameResults GameResult;
        GameResult.CompWinRounds = 0;
        GameResult.PlayerWinRounds = 0;
        GameResult.DrawRounds = 0;

        StartRound(Rounds, GameResult);
        ShowFinalGameResults(GameResult , Rounds);
        PlayAgain = TryAgain();
    } while (PlayAgain);
}

int main()
{
    srand((unsigned)time(NULL));

    StartGame();
    
    
    return 0;
}
