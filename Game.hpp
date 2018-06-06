#ifndef GAME_HPP
#define GAME_HPP

#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Util.hpp"


class Game
{
	/*
	Die *p1, *p2;			//this is what I origally had, realized it wasnt
	LoadedDie *p1, *p2		//working then switched to virtual. Not enough time
	*/						//to figure it out.
private:
	Die *die1;
	Die *die2;
	//int p1Score;
	//int p2Score;
	//int totalP1;
	//int totalP2;
	int rounds;
public:
	Game();
	void getGameInfo();
	void playDice();
	 ~Game();
};

#endif
