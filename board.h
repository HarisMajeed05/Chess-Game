#pragma once
#include<math.h>
#include"Header.h";
class piece;
class board
{
	piece*** Ps;


public:
	board();
	void displayBoard();
	piece* getPieceAt(int r, int c);
	void setPieceAt(int r, int c, piece* p)
	{
		Ps[r][c] = p;
	}
	void move(int r, int c,int  dr,int dc);
	void assign(const board& s);
	const board& operator=(const board& a);
	void deep(const board& a);
	void setPawn(int r, int c, color col);
	void setRook(int r, int c, color col);
	void setKing(int r, int c, color col);
	void setQueen(int r, int c, color col);
	void setKnight(int r, int c, color col);
	void setBishop(int r, int c, color col);
	~board();
};

