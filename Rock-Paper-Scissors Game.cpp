// Rock-Paper-Scissors Game.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <cstdlib>

using namespace std;

enum enGameChoice
{
    Rock=1,
    Paper=2,
    Scissors=3,
};
// Hasn't Changed
enum enWinner
{
    Player = 1 , Computer = 2, Draw = 3
};
// New
struct stGameResults
{
    int GameRounds = 0;
    int PlayerWinRounds = 0;
    int CompWinRounds = 0;
    int DrawRounds =0;

    bool CompWin = false;
    bool PlayerWin = false;

    enWinner GameWinner;
    string WinnerName = "";
    
};
// To Be Changed
struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice PlayerChoice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
    
};
// New
int RandomNumber(int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
// Hasn't Changed
enGameChoice GetComputerChoice() {
    return (enGameChoice)RandomNumber(1, 3);
    
}
// Refactored
void TestRandomChoice() {
    for (int i = 0; i <= 20; i++)
    {
        switch (GetComputerChoice()) {
        case enGameChoice::Rock :
            cout << "Random choice " << i << " is rock " << endl;
            break;
        case enGameChoice::Paper :
            cout << "Random choice " << i << " is paper " << endl;
            break;
        case enGameChoice::Scissors :
            cout << "Random choice " << i << " is scissors " << endl;
            break;
        }
    }
}
// To Be Removed
int ReadRounds(string Message) {
    int Rounds;
    do
    {
        cout << Message << endl;
        cin >> Rounds;
    } while (Rounds < 0 && Rounds > 10);
    return Rounds;
}
// Hasn't Changed
enGameChoice ReadUserChoice(string Message) {
    int Input = 0;
    do
    {
        cout << Message << endl;
        cin >> Input;
    } while (Input > 3 || Input < 1);

    return (enGameChoice)Input;
    
}
// Refactored
string Tabs(short NumberOfTabs) {
    string t = "";
    for (int i = 1; i < NumberOfTabs; i++)
    {
        t += "\t";
        cout << t;
    }
    return t;
}
// New
void SetWinnerScreenColor(enWinner Winner) {
    if (Winner == enWinner::Computer)
    {
        system("COLOR 4F");
        cout << "\a";
    }
    else if (Winner == enWinner::Player)
    {
        system("COLOR 2F");
    }
    else
    {
        system("COLOR 6F");
    }
}
// New
stGameResults CheckWinner(enGameChoice UserChoice, enGameChoice CompChoice , stGameResults Result) {

    if (UserChoice == CompChoice)
    {
        return Result;
    }


    switch (CompChoice) {

    case enGameChoice::Paper :
        switch (UserChoice) {
        case enGameChoice::Rock:
            Result.CompWin = true;
            return Result;
        case enGameChoice::Scissors:
            Result.PlayerWin = true;
            return Result;
        }
        break;

    case enGameChoice::Scissors : 
        switch (UserChoice) {
        case enGameChoice::Paper:
            Result.CompWin = true;
            return Result;
        case enGameChoice::Rock:
            Result.PlayerWin = true;
            return Result;
        }
        break;


    case enGameChoice::Rock :
        switch (UserChoice) {
        case enGameChoice::Scissors:
            Result.CompWin = true;
            return Result;
        case enGameChoice::Paper:
            Result.PlayerWin = true;
            return Result;
        }
        break;

    }
}
// To Be Removed
void ShowFinalGameResults(stGameResults GameResults) {
    cout<< Tabs(2) << "__________________[Game Results]_______________\n\n";
    cout<< Tabs(2) << "\tGame rounds " << GameResults.GameRounds << endl;
    cout<< Tabs(2) << "\tPlayer Won Rounds : " << GameResults.PlayerWinRounds << endl;
    cout<< Tabs(2) << "\tcomp Won Rounds : " << GameResults.CompWinRounds << endl;
    cout<< Tabs(2) << "\tDraw Rounds: " << GameResults.DrawRounds << endl;
    cout << Tabs(2) << "Final Winner : " << GameResults.WinnerName << endl;
    cout<< Tabs(2) << "\n\n\t==================================\n\n";

    SetWinnerScreenColor(GameResults.GameWinner);
}
// Refactored
string ChoiceName(enGameChoice Choice) {
    string arrGameChoice[3] = { "Rock","Paper","Scissors" };
    return arrGameChoice[Choice - 1];
}
// Refactored
void PrintResult(stGameResults Result, enGameChoice UserChoice, enGameChoice CompChoice) {
    cout << "\n-------------------------------------------";
    cout << "\nPlayer choice " << ChoiceName(UserChoice) << endl;
    cout << "Comp Choice : " << ChoiceName(CompChoice) << endl;
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
// To Be Removed
string WinnerName(enWinner Winner) {
    string arrWinnerName[3] = { "Player","Computer","No Winner" };
    return arrWinnerName[Winner - 1];
}
// New
void ResetValues(stGameResults& Result) {
    Result.CompWin = false;
    Result.PlayerWin = false;
}
// To Be Removed
enWinner WhoWonTheGame(int PlayerWinTimes, int ComputerWinTimes) {
    if (PlayerWinTimes > ComputerWinTimes)
    {
        return enWinner::Player;
    }
    else if (ComputerWinTimes > PlayerWinTimes)
    {
        return enWinner::Computer;
    }
    else
    {
        return enWinner::Draw;
    }
}
// New
stGameResults FillGameResults(int GameRounds, int PlayerWinTimes, int ComputerWinTimes, int DrawTimes) {
    stGameResults GameResults;

    GameResults.GameRounds = GameRounds;
    GameResults.PlayerWinRounds = PlayerWinTimes;
    GameResults.CompWinRounds = ComputerWinTimes;
    GameResults.DrawRounds = DrawTimes;

    GameResults.GameWinner = WhoWonTheGame(PlayerWinTimes, ComputerWinTimes);
    GameResults.WinnerName = WinnerName(GameResults.GameWinner);


    return GameResults;
}
// New
enWinner WhoWonTheRound(stRoundInfo RoundInfo) {
    if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
    {
        return enWinner::Draw;
    }

    switch (RoundInfo.PlayerChoice) {
    case enGameChoice::Rock :
        if (RoundInfo.ComputerChoice == enGameChoice::Paper)
        {
            return enWinner::Computer;
        }
        break;
    case enGameChoice::Paper :
        if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
        {
            return enWinner::Computer;
        }
        break;
    case enGameChoice::Scissors :
        if (RoundInfo.ComputerChoice == enGameChoice::Rock)
        {
            return enWinner::Computer;
        }
        break;
    }
    // if you reach here then player is the winner
    return enWinner::Player;
}
// New
void PrintRoundResult(stRoundInfo RoundInfo) {
    cout << "\n________Round [" << RoundInfo.RoundNumber << "] _________\n\n";
    cout << "Player choice : " << ChoiceName(RoundInfo.PlayerChoice) << endl;
    cout << "Computer choice : " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner : " << RoundInfo.WinnerName << endl;
    cout << "_______________\n " << endl;

    SetWinnerScreenColor(RoundInfo.Winner);
}
// Refactored
stGameResults PlayGame(int Rounds) {
    stRoundInfo RoundInfo;
    short PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    enGameChoice UserChoice, CompChoice;
    for (int GameRound = 1; GameRound <= Rounds; GameRound++)
    {

        cout << "\n\nRound " << GameRound << " Begins : " << endl;
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.PlayerChoice = ReadUserChoice("Your choice : [1] : Rock, [2] : Paper, [3] : Scissors ? ");
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::Player)
        {
            PlayerWinTimes++;
        }
        else if (RoundInfo.Winner == enWinner::Computer)
        {
            ComputerWinTimes++;
        }
        else
        {
            DrawTimes++;
        }

        PrintRoundResult(RoundInfo); 
    }

    return FillGameResults(Rounds, PlayerWinTimes, ComputerWinTimes, DrawTimes);
}
// Refactored
bool TryAgain() {
    char TryAgain;
    cout << "\nTry Again ? Y/N" << endl;
    cin >> TryAgain;

    if (TryAgain == 'y' || TryAgain == 'Y')
    {
        system("cls");
        system("COLOR 07");
        return true;
    }
    else
    {
        system("COLOR 07");
        system("cls");
        

        return false;
    }
}
// To Be Removed
void ResestScreen() {
     system("cls");
     system("COLOR 0F");
}
// New 
void ShowGameOverScreen() {
    cout << Tabs(2) << "___________________________________________\n\n";
    cout << Tabs(2) << "          +++ G a m e  O v e r +++\n";
    cout << Tabs(2) << "___________________________________________\n\n";
}
// New
void StartGame() {
    int HowManyRounds;
    char PlayAgain = 'y';
    do
    {
        ResestScreen();
        HowManyRounds = ReadRounds("How Many Rounds ? From 1 to 10  ? \n");
        stGameResults GameResult = PlayGame(HowManyRounds);
        ShowGameOverScreen();
        ShowFinalGameResults(GameResult);
        
        cout << endl << Tabs(3) << "Do You want to play again ? Y/N ?" << endl;
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');

}
// Refactored
int main()
{
    srand((unsigned)time(NULL));

    StartGame();
    
    
    return 0;
}
