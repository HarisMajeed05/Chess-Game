#pragma once
#include"piece.h"

class king :public piece
{
public:
	king(int _r, int _c, color Col, board* _b);
	virtual void draw(int ri, int ci);
	bool isKing() {
		return true;
	}
	bool isLegalMove(board* b, int sr, int sc, int dr, int dc)
	{
		int r = abs(sr - dr);
		int c = abs(sc - dc);
		return ((isHor(sr, sc, dr, dc) && ishoripathclr(sr, sc, dr, dc)) || (isVer(sr, sc, dr, dc) && isverpthclr2(sr, sc, dr, dc))) || (isDig(sr, sc, dr, dc) && (isDiagonalL2RPathClear1(sr, sc, dr, dc) ||
			isDiagonalR2LPathClear1(sr, sc, dr, dc)) && r <= 1 && c <= 1);
	}
	virtual char IAm()const override
	{
		return (c == white) ? 'K' : 'k';
	}
};
