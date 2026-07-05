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

    if (UserChoice == CompChoice)
    {
        return Result;
    }


    switch (CompChoice) {

    case enRockPaperScissors::Paper :
        switch (UserChoice) {
        case enRockPaperScissors::Rock:
            Result.CompWin = true;
            return Result;
        case enRockPaperScissors::Scissors:
            Result.PlayerWin = true;
            return Result;
        }
        break;

    case enRockPaperScissors::Scissors : 
        switch (UserChoice) {
        case enRockPaperScissors::Paper:
            Result.CompWin = true;
            return Result;
        case enRockPaperScissors::Rock:
            Result.PlayerWin = true;
            return Result;
        }
        break;


    case enRockPaperScissors::Rock :
        switch (UserChoice) {
        case enRockPaperScissors::Scissors:
            Result.CompWin = true;
            return Result;
        case enRockPaperScissors::Paper:
            Result.PlayerWin = true;
            return Result;
        }
        break;

    }
}

void ShowFinalGameResults(stGameResults GameResults , int Rounds) {
    cout << "\n\n\t==================================\n\n";
    cout << "\t\t G A M E  O V E R \n";
    cout << "\n\n\t==================================\n\n";
    cout << "\tGame rounds " << Rounds << endl;
    cout << "\tPlayer Won Rounds : " << GameResults.PlayerWinRounds << endl;
    cout << "\tcomp Won Rounds : " << GameResults.CompWinRounds << endl;
    cout << "\tDraw Rounds: " << GameResults.DrawRounds << endl;

    if (GameResults.CompWinRounds > GameResults.PlayerWinRounds)
    {
        cout << "\n\tFinal Winner is Computer \n";
    }
    else if (GameResults.PlayerWinRounds > GameResults.CompWinRounds)
    {
        cout << "\n\tFinal Winner is Player \n";
    }
    else
    {
        cout << "\n\tFinal Winner is None \n";
    }
    
    cout << "\n\n\t==================================\n\n";
}

string ToStringResult(enRockPaperScissors Choice) {
    switch (Choice) {
    case enRockPaperScissors::Rock:
        return "Rock";
    case enRockPaperScissors::Paper:
        return "Paper";
    case enRockPaperScissors::Scissors:
        return "Scissors";
    }
}

void PrintResult(stGameResults Result, enRockPaperScissors UserChoice, enRockPaperScissors CompChoice) {
    cout << "\n-------------------------------------------";
    cout << "\nPlayer choice " << ToStringResult(UserChoice) << endl;
    cout << "Comp Choice : " << ToStringResult(CompChoice) << endl;
    if (Result.CompWin)
    {
        cout << "\a";
        cout << "\n======\n";
        cout << "The Winner is comp";
        cout << "\n======\n";
        system("COLOR 4F");

    }
    else if (Result.PlayerWin)
    {
        cout << "\n======\n";
        cout << "The Winner is player";
        cout << "\n======\n";
        system("COLOR 2F");

    }
    else
    {
        cout << "\n======\n";
        cout << "The Winner is None";
        cout << "\n======\n";
        system("COLOR 6F");

    }
    
    cout << "\ncomp score : " << Result.CompWinRounds << endl;
    cout << "\nplayer score : " << Result.PlayerWinRounds << endl;
    cout << "\n-------------------------------------------";
}

void ResetValues(stGameResults& Result) {
    Result.CompWin = false;
    Result.PlayerWin = false;
}

void PrintRoundResult(stGameResults& Result , enRockPaperScissors UserChoice , enRockPaperScissors CompChoice) {
    if (Result.CompWin)
    {
        Result.CompWinRounds++;
        PrintResult(Result,UserChoice,CompChoice);
        ResetValues(Result);
    }
    else if (Result.PlayerWin)
    {
        Result.PlayerWinRounds++;
        PrintResult(Result, UserChoice, CompChoice);
        ResetValues(Result);
    }
    else {
        Result.DrawRounds++;
        PrintResult(Result, UserChoice, CompChoice);
        ResetValues(Result);
    }
}

void StartRound(int Rounds , stGameResults& Result) {
    enRockPaperScissors UserChoice, CompChoice;
    for (int i = 1; i <= Rounds; i++)
    {
        
        cout << "\n\nRound " << i << " Begins : " << endl;
        UserChoice = ReadUserChoice("Your choice : [1] : Rock, [2] : Paper, [3] : Scissors ? ");
        CompChoice = RandomChoice();
        Result = CheckWinner(UserChoice, CompChoice, Result);
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
