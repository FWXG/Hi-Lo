#include <iostream>
#include <ctime>
#include <string>
#include <cstdint>

int gameNumber()
{
    srand(static_cast<int>(time(0)));

    int answerNumber = rand() % 100;

    return answerNumber;
}

int inputPlayer()
{
    int playerGuess;
    std::cin >> playerGuess;

    if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
    {
        std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
        std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
        std::cout << "\nIncorrect input.Plaese try again! \n";
    }
    else // если всё хорошо, то возвращаем a
        return playerGuess;
}

std::string guessing()
{
    int numberOfTries{ 1 };

    const int randGuessNumber = gameNumber();
    const int upRangeOfAttempt{ 7 };

    std::cout << randGuessNumber << std::endl;

    std::cout << "You have "<< upRangeOfAttempt <<" tries to guess what it is.\n";

    while (numberOfTries <= upRangeOfAttempt)
    {
        std::cout << "Guess #"<< numberOfTries<<"\n";


        int mainPlayerGuess = inputPlayer();

        if (mainPlayerGuess > 101)
            continue;

        if (mainPlayerGuess > randGuessNumber)
        {
            std::cout << "Your guess is too high.\n";
            ++numberOfTries;
            continue;
        }
        if (mainPlayerGuess < randGuessNumber)
        {
            std::cout << "Your guess is too low.\n";
            ++numberOfTries;
            continue;
        }
        if (mainPlayerGuess == randGuessNumber)
        {
            return "Correct! You win!";
        }
    }

    if (numberOfTries > upRangeOfAttempt)
    {
        std::cout << "Sorry, you lose. The correct number was " << randGuessNumber << std::endl;
        return "\n";
    }
    
}

bool resetGame()
{
    char exit{ 'n' };
    char resetGame{ 'y' };

    char decision;

    while (true)
    {
        std::cout << "\nSelect literal, to start game. (y/n)?\n";

        std::cin >> decision;
        std::cin.ignore(32767, '\n');

        if (decision == exit)
        {
            std::cout << "Thanks for playing \n";
            return false;
        }
        else if (decision == resetGame)
        {
            return true;
        }
        else
        {
            std::cout << "Incorrect input.Plaese try again! \n";
        }
    }
    

}

int main()
{
    

    std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.\n";


    while (resetGame())
    {
        std::cout << guessing();
    }

}

