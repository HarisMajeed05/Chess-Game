#include "piece.h";
#include<math.h>
#include<iostream>
using namespace std;
piece::piece(int r, int c, color col,board *_b)
{
	this->ri = r;
	this->ci = c;
	this->c = col;
	this->B = _b;
}
void piece::move(int _r, int _c)
{
	this->ri = _r;
	this->ci = _c;
}
color piece::getCol()
{
	return c;
}/*
bool piece::isVerPthClr(board *B,int sr, int sc, int dr, int dc)
{
	int a = max(sr, dc);
	int b = min(sc, dc);
	for (int i = b + 1; i < a; i++)
	{
		if (B->getPieceAt(sc, i) != nullptr)
			return true;
	}
	return false;

}*/