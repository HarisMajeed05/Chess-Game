#include "chess.h";
#include"player.h";
#include"board.h";
#include"piece.h";
#include"Header.h";
#include<time.h>
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<windows.h>
#include<string>
#include<fstream>
#include"pawn.h";
#include"king.h";
#include"bishop.h";
#include"queen.h";
#include"rook.h";
#include"knight.h";
using namespace std;
class piece;
void getRCbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}
void gotoRC(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void SC(int clr)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}
chess::chess()
{
	string s;
	cout << "Enter first name(black pieces): ";
	cin >> s;
	string p;
	cout << "Enter second name(white pieces): ";
	cin >> p;
	Ps[0] = new player(s,black);
	Ps[1] = new player(p, white);
	b = new board();
	//b2 = new board();
	srand(time(0));
	turn = rand() % 2;
}
void chess::turnMsg(player* p)
{
	//gotoRC(10, 90);
	cout <<endl<< p->getName() << " 's turn\n";
}
void chess::slcPos()
{
	//cin >> sr >> sc;
	int x, y;
	getRCbyLeftClick(x, y);
	sr = x/8 ;
	sc = y/8 ;
}
void chess::slcDs()
{
	//cin >> dr >> dc;
	int x, y;
	getRCbyLeftClick(x, y);
	dr = x/8 ;
	dc = y/8 ;
}
bool chess::IsValidSc(player* Ap, int r, int c)
{
	if (r < 0 || r>7 || c < 0 || c>7)
		return false;
	piece* p = b->getPieceAt(r, c);
	return p != nullptr && p->getCol() == Ap->getCol();
}
bool chess::IsValidDs(player* Ap, int r, int c)
{
	if (r < 0 || r>7 || c < 0 || c>7)
		return false;
	
	piece* p = b->getPieceAt(r, c);
	return p == nullptr || p->getCol() != Ap->getCol();
}
//
//bool chess::IsValidSc2(player* Ap, int r, int c)
//{
//	if (r < 0 || r>7 || c < 0 || c>7)
//		return false;
//	piece* p = b2->getPieceAt(r, c);
//	return p != nullptr && p->getCol() == Ap->getCol();
//}
//bool chess::IsValidDs2(player* Ap, int r, int c)
//{
//	if (r < 0 || r>7 || c < 0 || c>7)
//		return false;
//
//	piece* p = b2->getPieceAt(r, c);
//	return p == nullptr || p->getCol() != Ap->getCol();
//}
void chess::turnChn()
{
	turn = (turn + 1) % 2;
}
void chess::DisBor(int dim, int row, int col)
{
	char sym = -37;
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if ((i + j) % 2 == 0) {
				box(i * row, j * col, row, col, sym, 15);
				gotoRC((i * row) + (row / 2), (j * col) + (row / 2));
				if (b->getPieceAt(i, j) != nullptr)
					b->getPieceAt(i, j)->draw((i * row) + (row / 2), (j * col) + (row / 2));
				else
					cout << "";
			}
			else
			{
				box(i * row, j * col, row, col, sym, 12);
				gotoRC((i * row) + (row / 2), (j * col) + (row / 2));
				if (b->getPieceAt(i, j) != nullptr)
					b->getPieceAt(i, j)->draw((i * row) + (row / 2), (j * col) + (row / 2));
				else
					cout << "";
			}
		}
	}
}
void chess::box(int sr, int sc, int ri, int ci, char sym, int color)
{
	for (int r = 0; r < ri; r++)
	{
		for (int c = 0; c < ci; c++)
		{
			gotoRC(sr + r, sc + c);
			SC(color);
			cout << sym;
		}
	}
}
bool** chess::comp_high(player* ap, int sr, int sc, int dim)
{
	bool **bmap = new bool* [dim];
	for (int r = 0; r < dim; r++)
	{
		bmap[r] = new bool[dim] {};
	}
	//position ds;
	int dri, dci;
	for (int r = 0; r < dim; r++)
	{
		for (int c = 0; c < dim; c++)
		{
			dri = r;
			dci = c;
			if ((IsValidDs(ap, dri, dci)) && b->getPieceAt(sr, sc)->isLegalMove(b, sr, sc, dri, dci))
			{
				bmap[r][c] = true;
			}
		}
	}
	return bmap;
}
void chess::highlight(player* ap, bool**& map, int dim, int brow, int bcol)
{
	char sym = -37;
	for (int r = 0; r < dim; r++)
	{
		for (int c = 0; c < dim; c++)
		{
			if (map[r][c] == true)
			{
				box( r * brow, c * bcol,brow,bcol, sym, 10);
			}
		}
	}
}
void chess::unhighlight(player* ap, bool**& map, int dim, int brow, int bcol)
{
	char sym = -37;
	for (int r = 0; r < dim; r++)
	{
		for (int c = 0; c < dim; c++)
		{
			if (map[r][c] == true)
			{
				if ((r + c) % 2 == 0)
				{
					box(r * brow, c * bcol, brow, bcol, sym, 15);
				}
				else
				{
					box(r * brow, c * bcol, brow, bcol, sym, 12);
				}
			}
		}
	}
}


bool ismypiece(piece* sym, int turn) {
	if (turn == white && isupper(sym->IAm())) {
		return true;
	}
	else if (turn == black && islower(sym->IAm())) {
		return true;
	}
	return false;
}

position chess::findKing(player* ap)
{
	position kingLoc;
	kingLoc.ri = 0, kingLoc.ci = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (b->getPieceAt(i, j) != nullptr && b->getPieceAt(i, j)->isKing() == true && b->getPieceAt(i, j)->getCol() != ap->getCol())
			{
				kingLoc.ri = i, kingLoc.ci = j;
				return kingLoc;
			}
		}
	}
}
//
//position chess::findKing2(player* ap)
//{
//	position kingLoc;
//	kingLoc.ri = 0, kingLoc.ci = 0;
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			if (b2->getPieceAt(i, j) != nullptr && b2->getPieceAt(i, j)->isKing() == true && b2->getPieceAt(i, j)->getCol() != ap->getCol())
//			{
//				kingLoc.ri = i, kingLoc.ci = j;
//				return kingLoc;
//			}
//		}
//	}
//}
void chess::save()
{
	ofstream wrt("save.txt");
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (b->getPieceAt(r, c) == nullptr)
			{
				wrt << '-';
				continue;
			}
			else if (b->getPieceAt(r, c)->IAm() == 'P')
				wrt << 'P';
			else if (b->getPieceAt(r, c)->IAm() == 'p')
				wrt << 'p';
			else if (b->getPieceAt(r, c)->IAm() == 'K')
				wrt << 'K';
			else if (b->getPieceAt(r, c)->IAm() == 'k')
				wrt << 'k';
			else if (b->getPieceAt(r, c)->IAm() == 'Q')
				wrt << 'Q';
			else if (b->getPieceAt(r, c)->IAm() == 'q')
				wrt << 'q';
			else if (b->getPieceAt(r, c)->IAm() == 'R')
				wrt << 'R';
			else if (b->getPieceAt(r, c)->IAm() == 'r')
				wrt << 'r';
			else if (b->getPieceAt(r, c)->IAm() == 'N')
				wrt << 'N';
			else if (b->getPieceAt(r, c)->IAm() == 'n')
				wrt << 'n';
			else if (b->getPieceAt(r, c)->IAm() == 'B')
				wrt << 'B';
			else if (b->getPieceAt(r, c)->IAm() == 'b')
				wrt << 'b';
		}
		wrt << endl;
	}
}
//
//bool chess::checkmate()
//{
//	if (check(Ps[turn]))
//	{
//		//find opponent king
//		position p = findKing(Ps[turn]);
//		//turn change
//		turnChn();
//		for (int r = 0; r < 8; r++)
//		{
//			for (int c = 0; c < 8; c++)
//			{
//				//check if legal my piece move on fakeboard
//				if(b->getPieceAt(r,c)->isLegalMove())
//				selfcheck()
//				//if not in self check return false;
//
//			}
//		}
//		return true;
//	}
//}

void chess::load()
{
	ifstream rdr("save.txt");
	
	char piece;
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			rdr >> piece;
			switch (piece)
			{
			case 'P':
				b->setPawn(r, c, white);
				break;
			case 'p':
				b->setPawn(r, c, black);
				break;
			case 'K':
				b->setKing(r, c, white);
				break;
			case 'k':
				b->setKing(r, c, black);
				break;
			case 'Q':
				b->setQueen(r, c, white);
				break;
			case 'q':
				b->setQueen(r, c, black);
				break;
			case 'R':
				b->setRook(r, c, white);
				break;
			case 'r':
				b->setRook(r, c, black);
				break;
			case 'B':
				b->setBishop(r, c, white);
				break;
			case 'b':
				b->setBishop(r, c, black);
				break;
			case 'N':
				b->setKnight(r, c, white);
				break;
			case 'n':
				b->setKnight(r, c, black);
				break;
			case'-':
				b->setPieceAt(r, c, nullptr);
				break;
			}

		}
		
	}
}
bool chess::check(player *ap) {
	turnChn();
	position FindKing = findKing(ap);
	turnChn();
	int sri = 0, sci = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			sri = i, sci = j;
			if (IsValidSc(Ps[turn], sri, sci) && b->getPieceAt(sri, sci)->isLegalMove(b, sri, sci, FindKing.ri, FindKing.ci))
			{
				return true;
			}
		}
	}
	return false;
}
bool chess::selfcheck(player **ap)
{
	////turnChn();
	//position dc = findKing(ap); // find the king of the current player
	////turnChn();
	//int sc = 0;
	//int sr = 0;
	//for (int ri = 0; ri < 8; ri++) {
	//	for (int ci = 0; ci < 8; ci++) {
	//		sc = ci;
	//		sr = ri;
	//		// check if the current player's piece at (sr, sc) can legally move to (dc.row, dc.col)
	//		if (IsValidSc(ap, sr, sc) && b->getPieceAt(sr, sc)->isLegalMove(b, sr, sc, dc.ri, dc.ci)) {
	//			return true;
	//		}
	//	}
	//}
	//return false;
	bool che = false;
	turnChn();
	che = check(ap[turn]);
	if (che == true)
	{
		turnChn();

		gotoRC(4, 150);
		cout << "It's a self check!  ";
		return true;
	}
	else
	{
		turnChn();

		return false;
	}

}
/*
bool chess::check2(player* Ap)
{
	turnChn();
	position king = findKing2(Ap);
	turnChn();
	int sri = 0;
	int sci = 0;
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			sri = r;
			sci = c;
			if (IsValidSc2(Ps[turn], sri, sci) && b2->getPieceAt(sri, sci)->isLegalMove(b2, sri, sci, king.ri, king.ci))
			{
				return true;
			}
		}
	}
	return false;
}
bool chess::selfcheck2(player* p)
{
	turnChn();
	bool self = 0;
	self = check2(p);
	turnChn();
	return self;

}*/
bool chess::checkmate(player* ap)
{
	/*turnChn();
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (IsValidSc(p, r, c))
			{
				piece* P = b->getPieceAt(r, c);
				for (int ri = 0; ri < 8; ri++)
				{
					for (int ci = 0; ci < 8; ci++)
					{
						if (IsValidDs(p, ri, ci) && P->isLegalMove(b, r, c, ri, ci))
						{
							b2->deep(*b);
							b2->move(r, c, ri, ci);
							if (!selfcheck2(p))
							{
								turnChn();
								return false;
							}
						}
					}
				}
			}
		}
	}
	turnChn();*/
	if (!check(ap))
	{
		return false;
	}
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (IsValidSc(ap, r, c))
			{
				piece* p = b->getPieceAt(r, c);
				for (int tr = 0; tr < 8; tr++)
				{
					for (int tc = 0; tc < 8; tc++)
					{
						if (IsValidDs(ap, tr, tc) && p->isLegalMove(b, r, c, tr, tc))
						{
							board* tempB = new board();
							tempB->deep(*b);
							tempB->move(r, c, tr, tc);
							if (!check(ap))
								return false;
						}
					}
				}
			}
		}
	}
	return true;
}
	/*for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (IsValidSc(p, r, c))
			{
				piece* pp = b->getPieceAt(r, c);
				for (int tr = 0; tr < 8; tr++)
				{
					for (int tc = 0; tc < 8; tc++)
					{
						if (IsValidDs(p, tr, tc) && pp->isLegalMove(b, r, c, tr, tc))
						{
							board tempB = *b;
							tempB.move(r, c, tr, tc);
							if (!check(p))
							{
								return false;
							}
						}
					}
				}
			}
		}
	}*/
	//turnChn();
	//return true;


void chess::undo(piece *p)
{
	piece* q = b->getPieceAt(dr, dc);
	b->setPieceAt(sr, sc, q);
	b->setPieceAt(dr, dc, p);
}

void chess::redo(piece* p)
{
	piece* q = b->getPieceAt(sr, sc);
	b->setPieceAt(dr, dc, q);
	b->setPieceAt(sr, sc, p);
}

void chess::play()
{
	bool** bmap = new bool* [8];
	for (int r = 0; r < 8; r++)
	{
		bmap[r] = new bool[8] {};
	}
	//DisBor(8, 8, 8);
	piece* p;
	//piece** q = new piece* {};
	int i = 0;
	char a;
	cout << "do you want to load from the previous  file ?(y/n)" << endl;
	cin >> a;
	if (a == 'y')
	{
		load();

		turnChn();
	}
	piece* q;
	bool gameOver = false;
	while (gameOver==false)
	{
		//system("cls");
		DisBor(8, 8, 8);

		//turn = white;
		cout << endl << endl << endl << endl << endl << endl << endl << endl;

		turnMsg(Ps[turn]);
		//do {
			do {
				do {
					do {
						cout << "select piece(ri,ci)" << endl;
						slcPos();
						//cout << b->getPieceAt(sr, sc);
					} while (!IsValidSc(Ps[turn], sr, sc));
					//q = b->getPieceAt(sr, sc);
					//b2->setPieceAt(sr, sc,q);
					cout << "select destination(ri,ci)" << endl;
					bmap=comp_high(Ps[turn], sr, sc, 8);
					highlight(Ps[turn], bmap, 8, 8, 8);
					slcDs();
					unhighlight(Ps[turn], bmap, 8, 8, 8);
					//bmap = nullptr;
					p = b->getPieceAt(dr, dc);
					//b2->setPieceAt(dr, dc, p);
				} while (!IsValidDs(Ps[turn], dr, dc));
			} while (!(b->getPieceAt(sr, sc)->isLegalMove(b, sr, sc, dr, dc)));
		//} while (selfcheck(Ps));

		b->move(sr, sc, dr, dc);
		//b2->move(sr, sc, dr, dc);
		//b2->deep(*b);
		//system("cls");////////////
		////piece* a = b->getPieceAt(dr, dc);
		/*if (check(Ps[turn]))
		{
			gotoRC(4, 150);
			cout << "\n\n\ncheck hai " << endl;
			Sleep(1000);
			system("cls");
			DisBor(8, 8, 8);
			if (checkmate(Ps[turn]))
			{
				gotoRC(10, 80);
				cout << "it's check mate";
				Sleep(1000000);
				cout << Ps[turn]->getName()<<" has won the game" << endl;
				gameOver = true;
			}
		}*/
		/*if (check(Ps[turn]))
		{
			gotoRC(4, 150);
			cout << "\n\n\ncheck hai " << endl;
			Sleep(1000);
			system("cls");
			DisBor(8,8,8);
			if (checkmate(Ps[turn],b2))
			{
				gotoRC(10, 80);
				cout << "it's check mate";
			}
		}
		*/
		//DisBor(8, 8, 8);
		//gotoRC(10, 80);
		//cout << "do you want to undo(y/n)?";
		//char c;
		//cin >> c;
		//if (c == 'y')
		//{
		//	undo(p);
		//	//system("cls");//////////////
		//	DisBor(8, 8, 8);
		//	turnChn();
		//	gotoRC(10, 80);
		//	cout << "do you want to redo(y/n)?";
		//	char r;
		//	cin >> r;
		//	if (r == 'y') {
		//		//		//redo(p);
		//		//		//system("cls");//////////////
		//		//		//DisBor(8, 8, 8);
		//		//		////turnChn();
		//		//		//gotoRC(10, 80);
		//		//		//cout << "							";
		//		b->move(sr, sc, dr, dc);
		//		turnChn();
		//	}
		//	//	else if (r == 'n')
		//	//	{
		//	//		/*gotoRC(10, 80);
		//	//		cout << "							";*/
		//	//		//system("cls");
		//	//	}
		//	//}
		//	//else if (c == 'n')
		//	//{
		//		//turnChn();
		//		//	system("cls");
		//		//	gotoRC(10, 80);
		//		//	cout << "							";
		//		//	//system("cls");
		//	//}
		//	//
		//}
		////DisBor(8, 8, 8);
		////b->displayBoard();
		DisBor(8, 8, 8);
		gotoRC(10, 80);
		cout << "do you want to undo(y/n)?";
		char c;
		cin >> c;
		if (c == 'y')
		{
			undo(p);
			//system("cls");//////////////
			DisBor(8, 8, 8);
			turnChn();
			gotoRC(10, 80);
			cout << "do you want to redo(y/n)?";
			char r;
			cin >> r;
			if (r == 'y') {
				//		//redo(p);
				//		//system("cls");//////////////
				//		//DisBor(8, 8, 8);
				//		////turnChn();
				//		//gotoRC(10, 80);
				//		//cout << "							";
				b->move(sr, sc, dr, dc);
				turnChn();
			}
		}
		turnChn();
		save();
	}
}