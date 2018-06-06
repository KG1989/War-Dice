#include "Die.hpp"

//starting to adopt m_ syntax thanks to learncpp.com
//I think it helps knowing what is and isn't a member variable.
Die::Die(int m_sides)
{
	this->m_sides = m_sides;
}
int Die::getDieSides()
{
	return m_sides;
}
int Die::rollDie()
{
	// rand % m_sides returns any number from 0 to m_sides, add one and we got 1 to 6!
	int dieValue = rand() % m_sides + 1;
	return dieValue;
}
Die::~Die()
{

}