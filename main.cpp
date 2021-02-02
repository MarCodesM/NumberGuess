#include <iostream>
#include <cstdlib>
#include <ctime>

//Fuction takes max number and outputs randon number between 0 and max number
int createRandomNumber(int maxNum)
{
  int randNum;

  std::srand((int)time(0));
  randNum = (rand() % maxNum) + 1;
  return randNum;
}

//game logic checks if guess is correct, too high, or too low 
bool gameLogic(int randNum, int userGuess, int numTries)
{
  bool checker;

  if(userGuess < randNum)
  {
    std::cout << "Too Low!!" << std::endl;
  }
  else if(userGuess > randNum)
  {
    std::cout << "Too High!!" << std::endl;
  }
  else
  {
    std::cout << "\nYou're Right! It took you " << numTries << " guesses!!" << std::endl;
    return true;
  }

  return false;
}

int main() 
{
  bool gameEnds;
  int maxNum = 10;
  int numTries = 0;
  int userGuess;
  int randNum = createRandomNumber(maxNum);

  std::cout << "Hello, guess my number between 0 and " << maxNum << std::endl;

  do
  {
    std::cout << "Enter guess " << numTries + 1 << ": ";
    std::cin >> userGuess;
    numTries++;
    
    gameEnds = gameLogic(randNum, userGuess, numTries);


  }while(gameEnds != true);
  
}


