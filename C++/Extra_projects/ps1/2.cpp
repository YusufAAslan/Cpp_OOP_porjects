#include <iostream>
#include <cstdlib>
using namespace std;

const int SCORE_LIMIT = 100; // Define the goal score to achive
int diceRoll();
int humanTurn(int humanTotalScore);
int computerTurn(int computerTotalScore);

int main()
{


    bool win = 1;
    int humanTotalScore = 0, computerTotalScore = 0;

    cout << "It is your turn. Press r to roll.\n";

    do
    {
        cout << "Computers Score: " << computerTotalScore << endl;
       
        humanTotalScore= humanTurn(humanTotalScore);


        computerTotalScore =  computerTurn(computerTotalScore);
        if ((humanTotalScore <= SCORE_LIMIT) && (computerTotalScore <= SCORE_LIMIT))
        {
            win = 1;
        }
        else
        {
            win = 0;
        }

    }
    while(win == 1);

    if ((win == 0) && (humanTotalScore > computerTotalScore))
    {
        cout << "You win!";
    }
    else
    {
        cout << "You lost!!!!!";
    }
   

    return 0;
 }
 


 int diceRoll()  // to generate random numbers 
{
    int roll;

    roll = (int)(rand()%6)+1;
   
    return roll;
}  


int humanTurn(int humanTotalScore) // to manage human turn 
{
    int currentScore = 0;
    int lastRoll=0;
    char hold;

    cout << "Your total score is: " << humanTotalScore << "." << endl;
    cout << "Press r to roll again, or h to hold." << endl;
    cin >> hold;

    while (hold == 'r' && humanTotalScore <SCORE_LIMIT)
    {
        srand (time(NULL));
        lastRoll = diceRoll();
        if (lastRoll == 1)
        {
            cout << "You rolled a 1, ending your turn." << endl;
            break;
        }
        else
        {
            currentScore += lastRoll;
            humanTotalScore = currentScore ;
            cout << "You roll a " << lastRoll << ". Your score this turn is: " << currentScore << endl;
            cout << "Press r to roll again, or h to hold." << endl;
            cin >> hold;
        }
    }
    while (hold == 'h')
    {
        humanTotalScore += currentScore;
        break;
    }
   
    return humanTotalScore;
} 


int computerTurn(int computerTotalScore) // to manage computer urn 
{
    int currentScore = 0;
    int lastRoll=0;

    cout << "Computer's total score is: " << computerTotalScore << "." << endl;
    while ((currentScore < 20) && (currentScore != 1))
    {
        lastRoll = diceRoll();
        if (lastRoll == 1)
        {
            cout << "The computer rolled a 1, ending their turn." << endl;
            break;
        }
        else
        {
            currentScore += lastRoll;
            computerTotalScore = currentScore;
            cout << "The computer rolls a " << lastRoll << ". Computer's score this turn is: " << currentScore << endl;
        }
    }
    if(currentScore >= 20)
    {
        computerTotalScore += currentScore;
        cout << "Computer has more than 20 points so it won! "<< endl;
    }
   
    return computerTotalScore;
}