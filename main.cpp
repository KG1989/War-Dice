#include "Die.hpp"
#include "Game.hpp"
#include "LoadedDie.hpp"
#include "Util.hpp"


int main()
{
	unsigned seed = time(0);
	srand(seed);

	Game dice;

	dice.playDice();

	return 0;
}