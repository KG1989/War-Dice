#ifndef DIE_HPP
#define DIE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

/*Layout for the Die class. I used program 13-14 from the 8th edition of 
  the text to help with the syntax of calling the srand function and 
  also setting up the basic information of the dice */
class Die
{
protected:
	int m_sides;
public:
	Die(int);
	int getDieSides();
	//after not getting this assignment to work, I added this to be virtual.
	//so far it made it easier because I dont need 4 objects. I receieved word
	//about this from slack and also looking at the character-wizard example
	//in the modules.
	virtual int rollDie();
	virtual ~Die();
};


#endif
