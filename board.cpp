#include "board.h";
#include"piece.h";
#include"pawn.h";
#include"knight.h";
#include"bishop.h";
#include"queen.h";
#include"king.h";
#include"rook.h";
#include<iostream>
using namespace std;
board::board()
{
	Ps = new piece * *[8];
	for (int r = 0; r < 8; r++)
	{
		Ps[r] = new piece * [8];
		for (int c = 0; c < 8; c++)
		{
			if (r == 1) {
				Ps[r][c] = new pawn(r,c,white,this);
			}
			else if (r == 6)
			{
				Ps[r][c] = new pawn(r, c, black, this);
			}
			else if (r == 0 && (c == 0 || c == 7))
			{
				Ps[r][c] = new rook(r, c, white, this);
			}
			else if (r == 7 && (c == 0 || c == 7))
			{
				Ps[r][c]=new rook(r,c,black,this);
			}
			else if (r == 0 && (c == 1 || c == 6))
			{
				Ps[r][c]=new knight(r,c,white,this);
			}
			else if (r == 7 && (c == 1 || c == 6))
			{
				Ps[r][c]=new knight(r,c,black,this);
			}
			else if (r == 0 && (c == 2 || c == 5))
			{
				Ps[r][c]=new bishop(r,c,white,this);
			}
			else if (r == 7 && (c == 2 || c == 5))
			{
				Ps[r][c]=new bishop(r,c,black,this);
			}
			else if (r == 0 && c == 3)
			{
				Ps[r][c]=new queen(r,c,white,this);
			}
			else if (r == 7 && c == 3)
			{
				Ps[r][c]=new queen(r,c,black,this);
			}
			else if (r == 0 && c == 4)
			{
				Ps[r][c] = new king(r, c, white, this);
			}
			else if (r == 7 && c == 4)
			{
				Ps[r][c] = new king(r, c, black, this);
			}
			else
			{
				Ps[r][c] = nullptr;
			}
		}
	}
}
void board::assign(const board& s)
{
	this->Ps = new piece * *[8];
	for (int r = 0; r < 8; r++)
	{
		this->Ps[r] = new piece * [8];
		for (int c = 0; c < 8; c++)
		{
			this->Ps[r][c] = s.Ps[r][c];
		}
	}

}

const board & board::operator=(const board &a)
{
	
	this->Ps = new piece * *[8];
	for (int r = 0; r < 8; r++)
	{
		this->Ps[r] = new piece * [8];
		for (int c = 0; c < 8; c++)
		{
			if (a.Ps[r][c] != nullptr)
			{
				this->Ps[r][c] = a.Ps[r][c];
			}
			else
				this->Ps[r][c] = nullptr;
		}
	}
	return *this;
}
void board::deep(const board& a)
{
	this->Ps = new piece * *[8];
	for (int r = 0; r < 8; r++)
	{
		this->Ps[r] = new piece * [8];
		for (int c = 0; c < 8; c++)
		{
			if (a.Ps[r][c] != nullptr)
				this->Ps[r][c] = a.Ps[r][c];
			else
				this->Ps[r][c] = nullptr;
		}
	}
	//return *this;
}
void board::displayBoard()
{
	system("cls");
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (Ps[r][c] == nullptr)
			{
				cout << "-";
			}
			else
			{
				Ps[r][c]->draw(r,c);
			}
		}
		cout << endl;
	}
}
piece* board::getPieceAt(int r, int c)
{
	return Ps[r][c];
}
void board::move(int r, int c, int dr, int ds)
{
	Ps[dr][ds] = Ps[r][c];
	Ps[r][c] = nullptr;
}
void board::setPawn(int r, int c, color col)
{
	if (col == white)
	{
		Ps[r][c] = new pawn(r, c, white, this);
	}
	else
		Ps[r][c] = new pawn(r, c, black, this);
}
void board::setRook(int r, int c, color col)
{
	if (col == white)
	{
		Ps[r][c] = new rook(r, c, white, this);
	}
	else
		Ps[r][c] = new rook(r, c, black, this);
}
void board::setKing(int r, int c, color col)
{
	if (col == white)
	{
		Ps[r][c] = new king(r, c, white, this);
	}
	else
		Ps[r][c] = new king(r, c, black, this);
}
void board::setQueen(int r, int c, color col)
{
	if (col == white)
	{
		Ps[r][c] = new queen(r, c, white, this);
	}
	else
		Ps[r][c] = new queen(r, c, black, this);
}
void board::setKnight(int r, int c, color col)
{
	if (col == white)
	{
		Ps[r][c] = new knight(r, c, white, this);
	}
	else
		Ps[r][c] = new knight(r, c, black, this);
}
void board::setBishop(int r, int c, color col)
{
	if (col == white)
	{
		Ps[r][c] = new bishop(r, c, white, this);
	}
	else
		Ps[r][c] = new bishop(r, c, black, this);
}
board::~board()
{
	delete[]this->Ps;
}