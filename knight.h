#pragma once

#include"piece.h"

class knight :public piece
{
public:
	knight(int _r, int _c, color Col, board* _b);
	virtual void draw(int ri, int ci);


	bool isLegalMove(board* b, int sr, int sc, int dr, int dc) {
		bool isLegalMove{ false };

		// check for L shaped move
		if ((((dc - sc) == 2 && (dr - sr) == 1) || ((dc - sc) == 1 && (dr - sr) == 2)
			|| ((dc - sc) == 2 && (dr - sr) == -1) || ((dc - sc) == 1 && (dr - sr) == -2)
			|| ((dc - sc) == -2 && (dr - sr) == 1) || ((dc - sc) == -1 && (dr - sr) == 2)
			|| ((dc - sc) == -2 && (dr - sr) == -1) || ((dc - sc) == -1 && (dr - sc) == -2))
			&& b->getPieceAt(dr,dc) == nullptr) {

			return !isLegalMove;
		}

		// check for a capture of opposite colour piece
		else if ((((dc - sc) == 2 && (dr -sr) == 1) || ((dc - sc) == 1 && (dr - sr) == 2)
			|| ((dc - sc) == 2 && (dr - sr) == -1) || ((dc - sc) == 1 && (dr - sr) == -2)
			|| ((dc - sc) == -2 && (dr - sr) == 1) || ((dc - sc) == -1 && (dr - sr) == 2)
			|| ((dc - sc) == -2 && (dr - sr) == -1) || ((dc - sc) == -1 && (dr - sr) == -2))
			&& b->getPieceAt(dr,dc) != nullptr && b->getPieceAt(dr,dc)->getCol() != c) {

			return !isLegalMove;
		}

		return isLegalMove;
	}
	bool isKing() {
		return false;
	}
	virtual char IAm()const override
	{
		return (c == white) ? 'N' : 'n';
	}
};



