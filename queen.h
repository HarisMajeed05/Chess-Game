#pragma once

#include"piece.h"

class queen :public piece
{
public:
	queen(int _r, int _c, color Col, board* _b);
	virtual void draw(int ri, int ci);
	bool isLegalMove(board* b, int sr, int sc, int dr, int dc) {

        if (b->getPieceAt(dr, dc) != nullptr && b->getPieceAt(dr, dc)->getCol() == b->getPieceAt(sr, sc)->getCol())
            return false;
        if (!isHor(sr, sc, dr, dc) && !isVer(sr, sc, dr, dc) && !isDig(sr, sc, dr, dc))
            return false;
        if (isHor(sr, sc, dr, dc))
            return (ishoriclr(sr, sc, dr, dc) || ishoriclr2(sr, sc, dr, dc));
        if (isVer(sr, sc, dr, dc))
            return (isverclr(sr, sc, dr, dc) || isverclr2(sr, sc, dr, dc));
        if (isDig(sr, sc, dr, dc))
            return (isdiagL2RpathClear1(sr, sc, dr, dc) || isdiagL2RpathClear2(sr, sc, dr, dc)
                || isdiagR2LpathClear1(sr, sc, dr, dc) || isdiagR2LpathClear2(sr, sc, dr, dc));
        return true;
	}
    virtual char IAm()const override
    {
        return (c == white) ? 'Q' : 'q';
    }
    bool isKing() {
        return false;
    }
};

