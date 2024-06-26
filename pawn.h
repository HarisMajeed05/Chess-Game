//#pragma once
//#include"piece.h"
//#include<math.h>
//class queen;
//class pawn:public piece
//{
//
//private:
//	bool double_step;  
//	bool IsPromoted{ false };
//	bool hasMoved;
//public:
//	pawn(int _r, int _c,color Col, board* _b);
//	virtual void draw(int ri, int ci);
//	virtual ~pawn() {};
//	bool isLegalMove(board* b, int sr, int sc, int dr, int dc)
//	{
//		//bool isLegalMove=false;
//		if ((c == white && sr == 7) || IsPromoted == true) {
//			IsPromoted = true;
//			int r = abs(sr - dr);
//			int c = abs(sc - dc);
//			return  (isDig(sr, sc, dr, dc) && (isdiagL2RpathClear1(sr, sc, dr, dc) ||
//				isdiagR2LpathClear1(sr, sc, dr, dc))) || ((isHor(sr, sc, dr, dc) && ishoriclr(sr, sc, dr, dc)) ||
//					(isVer(sr, sc, dr, dc) && isverclr2(sr, sc, dr, dc))) || ((r == 2 && c == 1) && (sr > dr));
//		}
//		if ((c == black && sr == 0 ) || IsPromoted == true) {
//			IsPromoted = true;
//			int r = abs(sr - dr);
//			int c = abs(sc - dc);
//			return  (isDig(sr, sc, dr, dc) && (isdiagL2RpathClear1(sr, sc, dr, dc) ||
//				isdiagR2LpathClear1(sr, sc, dr, dc))) || ((isHor(sr, sc, dr, dc) && ishoriclr2(sr, sc, dr, dc)) ||
//					(isVer(sr, sc, dr, dc) && isverclr2(sr, sc, dr, dc))) || ((r == 2 && c == 1) && (sr > dr));
//			
//		}
//		//if (IsPromoted == false) {
//			//bool isLegalMove = false;
//			//int move_one_space = 1; int move_two_space = 2;  // for white pieces 
//			//if (c == black)								// for black des rows will be less than sr rows
//			//{
//			//	move_one_space = -1;
//			//	move_two_space = -2;
//			//}
//			//if (dr == sr + move_one_space && dc == sc && b->getPieceAt(dr, dc) == nullptr)
//			//{
//			//	this->double_step = false;
//			//	return !isLegalMove;
//			//}
//			//else if (double_step && dr == sr + move_two_space && dc == sc && b->getPieceAt(dr, dc) == nullptr)
//			//{
//			//	this->double_step = false;
//			//	return !isLegalMove;
//			//}
//			//else if (dr == sr + move_one_space && (dc == sc + move_one_space || dc == sc - move_one_space)
//			//	&& b->getPieceAt(dr, dc) != nullptr && b->getPieceAt(dr, dc)->getCol() != c)
//			//{
//			//	this->double_step = false;
//			//	return !isLegalMove;
//			//}
//
//			//return isLegalMove;
//
//			
//		//}
//		if (IsPromoted == false) {
//			bool isLegalMove = false;
//			int move_one_space, int move_two_space;  // for white pieces 
//			if (c == black)								// for black des rows will be less than sr rows
//			{
//				move_one_space = -1;
//				move_two_space = -2;
//			}
//			else if (c == white)
//			{
//				move_one_space = 1;
//				move_two_space = 2;
//			}
//			if (dr == sr + move_one_space && dc == sc && b->getPieceAt(dr, dc) == nullptr)
//			{
//				this->double_step = false;
//				return !isLegalMove;
//			}
//			else if (double_step && dr == sr + move_two_space && dc == sc && b->getPieceAt(dr, dc) == nullptr)
//			{
//				this->double_step = false;
//				return !isLegalMove;
//			}
//			else if (dr == sr + move_one_space && (dc == sc + move_one_space || dc == sc - move_one_space)
//				&& b->getPieceAt(dr, dc) != nullptr && b->getPieceAt(dr, dc)->getCol() != c)
//			{
//				this->double_step = false;
//				return !isLegalMove;
//			}
//
//			return isLegalMove;
//		}
//
//		//	
//		//bool hasMoved;
//	
//		//int direction = (isWhite ? -1 : 1); // assume white pawns move up, black pawns move down
//		//if (destCol == sourceCol) { // pawn is moving straight
//		//	if (destRow == sourceRow + direction) { // single step forward
//		//		if (board->getPieceAt(destRow, destCol) == nullptr) { // destination is empty
//		//			return true;
//		//		}
//		//	}
//		//	else if (destRow == sourceRow + 2 * direction) { // double step forward
//		//		if (!hasMoved && board->getPieceAt(sourceRow + direction, destCol) == nullptr && board->getPieceAt(destRow, destCol) == nullptr) { // both squares in front are empty and the pawn has not moved yet
//		//			return true;
//		//		}
//		//	}
//		//return false; // illegal move
//
//	}
//	void set_hasMoved(const bool& hasMoved_status)
//	{
//		hasMoved = hasMoved_status;
//	}
//	bool get_hasMoved() const
//	{
//		return hasMoved;
//	}
//	
//	
//	virtual char IAm()const override
//	{
//		return (c == white) ? 'P' : 'p';
//	}
//	bool isKing() {
//		return false;
//	}
//};
// 

#pragma once
#include "piece.h"

class pawn :public piece
{
protected:
	bool double_step;
	bool promotion = false;
	bool stop1 = false;
	bool stop2 = false;

	int st1 = 0;
	int st2 = 0;
public:
	pawn(int _r, int _c, color Col, board* _b);
	virtual void draw(int ri, int ci);
	bool isKing() {
		return false;
	}
	bool isLegalMove(board* b, int sr, int sc, int dr, int dc)//const position& move_to_pos);  // check move is valid for the pawn
	{
		if ((c == white && sr == 1) && stop1 == false) {
			if (st1 == 0 || st1 == 1 || st1 == 2 || st1 == 3 || st1 == 4 || st1 == 5
				|| st1 == 6 || st1 == 7 || st1 == 8 || st1 == 9 || st1 == 10 || st1 == 11 || st1 == 12 || st1 == 13 || st1 == 14
				|| st1 == 15 || st1 == 16 || st1 == 17 || st1 == 18 || st1 == 19 || st1 == 20 || st1 == 21 || st1 == 22 || st1 == 23
				|| st1 == 24 || st1 == 25 || st1 == 26 || st1 == 27 || st1 == 28 || st1 == 29 || st1 == 30 || st1 == 31 || st1 == 32
				|| st1 == 33 || st1 == 34 || st1 == 35 || st1 == 36 || st1 == 37 || st1 == 38 || st1 == 39 || st1 == 40 || st1 == 41
				|| st1 == 42 || st1 == 43 || st1 == 44 || st1 == 45 || st1 == 46 || st1 == 47 || st1 == 48) {
				st1 += 1;
				return (sc == dc && isverclr2(sr, sc, dr, dc) && abs(dr - sr) <= 2 && (sr < dr));
			}
			if (st1 == 48) {
				stop1 = true;
			}
		}
		if (c == black && sr == 6 && stop2 == false) {
			if (st2 == 0 || st2 == 1 || st2 == 2 || st2 == 3 || st2 == 4
				|| st2 == 5 || st2 == 6 || st2 == 7 || st2 == 8 || st2 == 9 || st2 == 10 || st2 == 11 || st2 == 12 || st2 == 13 || st2 == 14
				|| st2 == 15 || st2 == 16 || st2 == 17 || st2 == 18 || st2 == 19 || st2 == 20 || st2 == 21 || st2 == 22 || st2 == 23
				|| st2 == 24 || st2 == 25 || st2 == 26 || st2 == 27 || st2 == 28 || st2 == 29 || st2 == 30 || st2 == 31 || st2 == 32
				|| st2 == 33 || st2 == 34 || st2 == 35 || st2 == 36 || st2 == 37 || st2 == 38 || st2 == 39 || st2 == 40 || st2 == 41
				|| st2 == 42 || st2 == 43 || st2 == 44 || st2 == 45 || st2 == 46 || st2 == 47 || st2 == 48) {

				st2 += 1;
				return (sc == dc && isverclr2(sr, sc, dr, dc) && abs(dr - sr) <= 2 && (sr > dr));
			}
			if (st2 == 48) {
				stop2 = true;
			}
		}
		if ((c == white && (sr == 7)) || promotion == true) {
			promotion = true;
			int r = abs(sr - dr);
			int c = abs(sc - dc);

			//if (sr == 0 || sr == 1 || sr == 2) {
			return  (isDig(sr, sc, dr, dc) && (isdiagL2RpathClear1(sr, sc, dr, dc) ||
				isdiagR2LpathClear1(sr, sc, dr, dc))) || ((isHor(sr, sc, dr, dc) && ishoriclr2(sr, sc, dr, dc)) ||
					(isVer(sr, sc, dr, dc) && isverclr2(sr, sc, dr, dc))) || ((r == 2 && c == 1) && (sr > dr));

			//	}
		}
		if ((c == black && (sr == 0)) || promotion == true) {
			promotion = true;
			int r = abs(sr - dr);
			int c = abs(sc - dc);

			//if (sr == 0 || sr == 1 || sr == 2) {
			return  (isDig(sr, sc, dr, dc) && (isdiagL2RpathClear1(sr, sc, dr, dc) ||
				isdiagR2LpathClear1(sr, sc, dr, dc))) || ((isHor(sr, sc, dr, dc) && ishoriclr2(sr, sc, dr, dc)) ||
					(isVer(sr, sc, dr, dc) && isverclr2(sr, sc, dr, dc))) || ((r == 2 && c == 1) && (sr > dr));

			//}
		}
		if (promotion == false) {

			bool isLegalMove{ false };

			int move_one_space{ 1 }; int move_two_space{ 2 };  // white pieces moving up the board
			if (c == black) { move_one_space = -1; move_two_space = -2; }  // black pieces moving down the board

			// check for valid move of one space forward
			if (dr == sr + move_one_space && dc == sc && b->getPieceAt(dr, dc) == nullptr) {

				this->double_step = false;
				return !isLegalMove;
			}

			// check for double step move
			else if (double_step && dr == sr + move_two_space && dc == sc && b->getPieceAt(dr, dc) == nullptr) {

				this->double_step = false;
				return !isLegalMove;
			}

			// check for diagonal capture of opposite colour pieces 
			else if (dr == sr + move_one_space && (dc == sc + move_one_space || dc == sc - move_one_space)
				&& b->getPieceAt(dr, dc) != nullptr && b->getPieceAt(dr, dc)->getCol() != c) {

				this->double_step = false;
				return !isLegalMove;
			}

			return isLegalMove;
		}
	}

	void set_double_step(const bool& double_step_status)  // set the double advance status of the piece
	{
		double_step = double_step_status;
	}
	bool get_double_step() const  // return double step status
	{
		return double_step;
	}
	char IAm() const override {
		return ((c == white) ? 'P' : 'p');
	}
};