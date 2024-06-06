#include "bishop.h"
#include"header.h";
#include<iostream>
using namespace std;
bishop::bishop(int _r, int _c, color _C, board* _b)
	:piece(_r, _c, _C, _b)
{

}
void bishop::draw(int ri, int ci)
{
	//cout << ((c == white) ? "B" : "b");
	if (c == white) {
		SetClr(6);
		gotoRowCol(ri - 2, ci);
		cout << char(-37);
		gotoRowCol(ri - 1, ci - 1);
		cout << char(-37) << char(-37) << char(-37);
		gotoRowCol(ri, ci);
		cout << char(-37);
		gotoRowCol(ri + 1, ci - 1);
		cout << char(-37) << char(-37) << char(-37);
		gotoRowCol(ri + 2, ci - 1);
		cout << char(-37) << char(-37) << char(-37);
		gotoRowCol(ri + 3, ci - 3);
		cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
	}
	else {
		SetClr(9);
		gotoRowCol(ri - 2, ci);
		cout << char(-37);
		gotoRowCol(ri - 1, ci - 1);
		cout << char(-37) << char(-37) << char(-37);
		gotoRowCol(ri, ci);
		cout << char(-37);
		gotoRowCol(ri + 1, ci - 1);
		cout << char(-37) << char(-37) << char(-37);
		gotoRowCol(ri + 2, ci - 1);
		cout << char(-37) << char(-37) << char(-37);
		gotoRowCol(ri + 3, ci - 3);
		cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
	}
}