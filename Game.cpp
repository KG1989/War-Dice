#include "Game.hpp"

Game::Game()
{
	die1 = NULL;
	die2 = NULL;
	int rounds = 0;
}
void Game::getGameInfo()
{
	std::string input;
	int sidesP1 = 0;
	int sidesP2 = 0;
	int dieTypeP1 = 0;
	int dieTypeP2 = 0;

	cout << "Before we really begin, we need some information from everyone! " << endl;
	cout << "How many rounds would you like to play? Something reasonable, no more than 100. " << endl;
	cout << "No one wants to roll dice for that long. " << endl;
	rounds = getInt(input, 0, 100);

	cout << "Now we must enter the number of sides for each dice. " << endl;
	cout << "Also something reasonable, no more than 100, you wouldn't even be able to read that. " << endl;
	cout << "Enter P1 sides: " << endl;
	sidesP1 = getInt(input, 0, 100);
	cout << "Enter P2 sides: " << endl;
	sidesP2 = getInt(input, 0, 100);

	cout << "Now the most important question of all. Do you want a regular old lame dice, " << endl;
	cout << "Or a super awesome very special loaded die? " << endl;
	cout << "Enter 1 for regular die, 2 for loaded die. " << endl;
	cout << "Select P1 die: " << endl;
	dieTypeP1 = getInt(input, 0, 2);
	cout << "Select P2 die: " << endl;
	dieTypeP2 = getInt(input, 0, 2);

	if (dieTypeP1 == 1)
	{
		die1 = new Die(sidesP1);
		cout << "P1 has chosen regular die! " << endl;
	}
	else if (dieTypeP1 == 2)
	{
		die1 = new LoadedDie(sidesP1);
		cout << "P1 has chosen loaded die! " << endl;
	}
	else
		cout << "Something bad happened. " << endl;

	if (dieTypeP2 == 1)
	{
		die2 = new Die(sidesP2);
		cout << "P2 has chosen regular die! " << endl;
	}
	else if (dieTypeP2 == 2)
	{
		die2 = new LoadedDie(sidesP2);
		cout << "P2 has chosen loaded die! " << endl;
	}
	else
		cout << "Something bad happened. " << endl;
}

void Game::playDice()
{
	int selection = 0;
	std::vector<std::string> vec;
	int winner = 0;
	int p1Roll = 0;
	int p2Roll = 0;
	int p1Score = 0;
	int p2Score = 0;
	int totalP1 = 0;
	int totalP2 = 0;
	

	cout << "Welcome to the game of war with dice! " << endl;
	cout << "Please select 0 to view the menu, or 2 to quit right away! " << endl;
	
	//menu(selection, vec, "Press 1 to start the dice game!", "Press 2 to exit!");
	while (selection != 2)
	{
		menu(selection, vec, "Press 1 to start the dice game!", "Press 2 to exit!");
		if (selection == 1)
		{
			// call get game info function
			getGameInfo();

			for (int i = 0; i < rounds; i++)
			{
				p1Roll = die1->rollDie();
				p2Roll = die2->rollDie();

				cout << "P1 rolled a " << p1Roll << endl;
				cout << "P2 rolled a " << p2Roll << endl;


				//add 1 to score if p1 or p2 wins the individual round
				if (p1Roll > p2Roll)
				{
					winner = 1;
					p1Score++;
				}
				else if (p2Roll > p1Roll)
				{
					winner = 2;
					p2Score++;
				}
				else
					winner = 3;

				//tell you who won this round
				switch (winner)
				{
				case 1:
					cout << "Player 1 wins this round! " << endl;
						break;
				case 2:
					cout << "Player 2 wins this round! " << endl;
					break;
				case 3:
					cout << "This round was a draw! " << endl;
					break;
				default:
					cout << "Something bad happened! " << endl;
					break;
				}

				totalP1 += p1Roll;
				totalP2 += p2Roll;
				cout << "So far, the score at this very moment is: " << endl;
				cout << "P1 has: " << totalP1 << " and " << "P2 has: " << totalP2 << endl;
			}
			
			cout << "The final score for the game was: " << endl;
			cout << "P1: " << totalP1 << endl;
			cout << "P2: " << totalP2 << endl;

			//cout << "In the end, P1 won " << p1Score << " rounds, and P2 won " << p2Score << " rounds. " << endl;
			if (p1Score > p2Score)
			{
				cout << "Player 1 won the game of war! " << endl;
			}
			else if (p2Score > p1Score)
			{
				cout << "Player 2 won the game of war! " << endl;
			}
			else
			{
				cout << "There was no winner! We have a tie. " << endl;
			}
			cout << "Want more? select 0 for menu or 2 to exit. " << endl;
			menu(selection, vec, "Welcome back! Press 1 to play the game again!", "Press 2 to exit!");
		} //end selection if

	} 

}

Game::~Game()
{
	delete die1;
	delete die2;
}