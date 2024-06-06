#include "player.h"
#include<string>
using namespace std;
player::player(string n, color _c)
{
	this->name = n;
	this->c = _c;
}
string player::getName()
{
	return name;
}
color player::getCol()
{
	return c;
}