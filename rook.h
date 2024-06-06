#pragma once
#include"piece.h"
#include"board.h";

class rook :public piece
{

public:
	rook(int _r, int _c, color Col, board* _b);
	virtual void draw(int ri, int ci);
	bool isLegalMove(board* b, int sr, int sc, int dr, int dc) {
		return ((isHor(sr,sc, dr,dc) && ishoripathclr(sr, sc, dr,dc)) || (isVer(sr,sc,dr, dc) && isverpthclr2(sr,sc,dr, dc)));
	}
	virtual char IAm()const override
	{
		return (c == white) ? 'R' : 'r';
	}
	bool isKing() {
		return false;
	}
};


