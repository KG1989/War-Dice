#include "Die.hpp"
#include "LoadedDie.hpp"


LoadedDie::LoadedDie(int m_sides) : Die(m_sides)
{
	this->m_sides = m_sides;
}
int LoadedDie::rollDie()
{
	// rand % m_sides returns any number from 0 to m_sides, add one and we got 1 to 6!
	int dieValue = rand() % m_sides + 1;

	//if die gets an even value
	if (dieValue % 2 == 0)
	{
		//if the die value is less than half of the sides
		if (dieValue < m_sides / 2)
		{
			//set the die value to the number of sides
			//so if die value is 10, and we roll a 4,
			//then now the value is 10.
			//yes this means our values cant be even values
			//less than half of the sides, so i'll keep thinking
			//of a better way.
			dieValue = m_sides;
			return dieValue;
		}
		else
			return dieValue;
	}
	else
		return dieValue;
}
