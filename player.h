#pragma once
#include<string>
using namespace std;
#include"header.h";
class player
{
	string name;
	color c;
public:
	player(string n, color _c);
	string getName();
	color getCol();
};

