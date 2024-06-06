#pragma once
#include<string>
class board;
class piece;
class player;
class validity;
struct position
{
	int ri, ci;
};
class chess
{
	int sr, sc, dr, dc;
	int turn;
	player* Ps[2];
	board* b;
	//board* b2;
	//color col;
	
public:
	chess();
	void play();
	void turnMsg(player* P);
	void slcPos();
	void slcDs();
	bool IsValidSc(player* p, int r, int c);
	bool IsValidDs(player *p,int r,int c);
	//bool IsValidSc2(player* p, int r, int c);
	//bool IsValidDs2(player* p, int r, int c);
	//bool isLegal(player* p, int r, int c);
	void DisBor(int dim, int row, int col);
	void box(int sr, int sc, int ri, int ci, char sym, int col);
	//bool checkmate();
	bool** comp_high(player* ap, int sr, int sc, int dim);

	void highlight(player* ap, bool**& map, int dim, int brow, int bcol);
	void unhighlight(player* ap, bool**& map, int dim, int brow, int bcol);
	
	position findKing(player* ap);
	//position findKing2(player* ap);
	bool check(player *ap);
	//bool check2(player* ap);
	bool selfcheck(player **ap);
	bool checkmate(player* p);
	//bool selfcheck2(player* p);
	void undo(piece *p);
	void redo(piece* p);
	void save();
	void load( );
	void turnChn();
};

