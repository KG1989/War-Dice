#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include "Die.hpp"

class LoadedDie : public Die
{
public:
	LoadedDie(int);
	int rollDie();
};

#endif
