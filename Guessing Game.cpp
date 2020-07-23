#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
	std::cout << "\nYou are a secret agent breaking into a "<< Difficulty;
	std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
}
bool PlayGame(int Difficulty)
{
	PrintIntroduction(Difficulty);

	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	//print CodeSum and CodeProduct
	std::cout << "There are 3 numbers in the code\n";
	std::cout << "\nThe code add-up to: " << CodeSum;
	std::cout << "\nThe code multiply to give: " << CodeProduct << "\n";

	//store player guess
	int GuessA, GuessB, GuessC;
	std::cin >> GuessA;
	std::cin >> GuessB;
	std::cin >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	//Check if the player guess is correct
	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		std::cout<< "\nGood job, now we will move to the next room! \ n";
	}
	else
	{
		std::cout << "\nYou entered the wrong code! Careful agent! Try again!\ n";
		return false;
	}
}



int main()
{
	srand(time(NULL)); //create new random sequence based on time of day

	const int MaxDifficulty=5;
	int LevelDifficulty = 1;
	while (LevelDifficulty <= MaxDifficulty)
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear();// Clear any errors
		std::cin.ignore();//Discard the buffer

		if (bLevelComplete) 
		{
			++LevelDifficulty;
		}
	}
	std::cout << "\n Great job agent! You got all the files! Now get out of there! \n";
	return 0;
}	
