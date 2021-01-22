#include <iostream>
#include <ctime>

void PrintIntroduction (int Difficulty)
{
    std::cout << "You are a warlock trying to breaking into a terminal to get acces to the room level " << Difficulty << " of a fortress\n\n";
    std::cout << "The rooms here create an idea that you are in a maze.";
}
//A function with the expressions for the game
bool PlayGame (int Difficulty)
{
    PrintIntroduction(Difficulty);

    //Print the first messages to the terminal   
    std::cout << "Inside the room you see a computer with a message, and a terminal to enter a code\n";
    std::cout << "\"So this is should be the terminal we were looking, I just need to figure out the code to continue...\"\n";

    //Stores the variables for the numbers we need
    const int CodeA = rand() %Difficulty + Difficulty;
    const int CodeB = rand() %Difficulty + Difficulty;
    const int CodeC = rand() %Difficulty + Difficulty;

    int CodeSum = CodeA + CodeB + CodeC; 
    int CodeProduct = CodeA * CodeB * CodeC;
    //print a ProducSum based on the variables
    std::cout << std::endl;
    std::cout << "The computer initiate with only the numbers on the screen:";
    std::cout << "There are 3 numbers in the code and they add up to " << CodeSum << std::endl;
    std::cout << "The code multiply to give "<<  CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;

    //Store the player Guess 
    std::cout << "\"A panel with numbers lights up, looks like I need to input a sequence of numbers:\"\n";       
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "\nYou entered: " << GuessA << GuessB << GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if the player guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nLooks like the sequence is right, the terminal starts to respond, you have to keep going\n\n";
        return true;
    }
    else
    {
        std::cout<< "\nThe warlock is poisoned by a mechanism activated by the terminal, is not letal but he probably dont have many more chances...\n\n";
        return false;
    }
}

int main ()
{

    srand(time(NULL));//Creates a new random sequence based on the time of day
    int LevelDifficulty = 1;
    const int MaxLevel = 5;
    
    while (LevelDifficulty <= MaxLevel)// Loop the game until all levels are completed.
    {
    bool bLevelComplete = PlayGame(LevelDifficulty);
    std::cin.clear();//Clears any errors
    std::cin.ignore();//Discards the buffer

    if (bLevelComplete)
    {
        ++LevelDifficulty;
    }

    }
    
    std::cout << "It worked ! The terminal activates a door behind the warlock...";
    return 0;
}