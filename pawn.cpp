#include "pawn.h"
#include<iostream>
using namespace std;
pawn::pawn(int _r, int _c, color _C, board* _b)
	:piece(_r,_c,_C,_b)
{
	this->double_step = true;
}
void pawn::draw(int ri, int ci)
{
	//cout << ((c == white) ? "P" : "p");
	if (promotion == false) {
		if (c == white)
		{
			SetClr(6);
			gotoRowCol(ri - 2, ci);
			cout << char(-37);
			gotoRowCol(ri - 1, ci - 2);
			cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
			gotoRowCol(ri, ci - 1);
			cout << char(-37) << char(-37) << char(-37);
			gotoRowCol(ri + 1, ci - 3);
			cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
		}
		else
		{
			SetClr(9);
			gotoRowCol(ri - 2, ci);
			cout << char(-37);
			gotoRowCol(ri - 1, ci - 2);
			cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
			gotoRowCol(ri, ci - 1);
			cout << char(-37) << char(-37) << char(-37);
			gotoRowCol(ri + 1, ci - 3);
			cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
		}
	}
	else if (promotion == true)
	{
		if (c == white) {
			SetClr(6);
			gotoRowCol(ri - 2, ci - 3);
			cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
			gotoRowCol(ri - 1, ci - 2);
			cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
			gotoRowCol(ri, ci - 1);
			cout << char(-37) << char(-37) << char(-37);
			gotoRowCol(ri + 1, ci - 1);
			cout << char(-37) << char(-37) << char(-37);
			gotoRowCol(ri + 2, ci - 2);
			cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
			gotoRowCol(ri + 3, ci - 3);
			cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
		}
		else
		{
			SetClr(9);
			gotoRowCol(ri - 2, ci - 3);
			cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
			gotoRowCol(ri - 1, ci - 2);
			cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
			gotoRowCol(ri, ci - 1);
			cout << char(-37) << char(-37) << char(-37);
			gotoRowCol(ri + 1, ci - 1);
			cout << char(-37) << char(-37) << char(-37);
			gotoRowCol(ri + 2, ci - 2);
			cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
			gotoRowCol(ri + 3, ci - 3);
			cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
		}
	}
}
