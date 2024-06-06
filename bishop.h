#pragma once
#include"piece.h"

class bishop :public piece
{
public:
	bishop(int _r, int _c, color Col, board* _b);
	virtual void draw(int ri, int ci);
	bool isLegalMove(board* b, int sr, int sc, int dr, int dc)
	{
		return (isDig(sr,sc,dr,dc) && (isDiagonalL2RPathClear1(sr,sc,dr,dc) ||
			isDiagonalR2LPathClear1(sr, sc, dr,dc)));
	}
	virtual char IAm()const override
	{
		return (c == white) ? 'B' : 'b';
	}
	bool isKing() {
		return false;
	}

};


