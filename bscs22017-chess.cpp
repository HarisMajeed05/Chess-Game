#include<iostream>
#include<conio.h>
#include<windows.h>
#include"chess.h";
#include"Header.h";
using namespace std;

//void getRowColbyLeftClick(int& rpos, int& cpos)
//{
//	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
//	DWORD Events;
//	INPUT_RECORD InputRecord;
//	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
//	do
//	{
//		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
//		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
//		{
//			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
//			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
//			break;
//		}
//	} while (true);
//}
//void gotoRowCol(int rpos, int cpos)
//{
//	COORD scrn;
//	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
//	scrn.X = cpos;
//	scrn.Y = rpos;
//	SetConsoleCursorPosition(hOuput, scrn);
//}
//void SetClr(int clr)
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
//}
//void drawBox(int sr, int sc, int rdim, int cdim, char sym = -37)
//{
//	for (int r = 0; r < rdim; r++)
//	{
//		for (int c = 0; c < cdim; c++)
//		{
//			if (r == 0 || c == 0 || r == rdim - 1 || c == cdim - 1)
//			{
//				gotoRowCol(sr+r, sc+c);
//				cout << sym;
//			}
//			else
//			{
//				gotoRowCol(sr + r, sc + c);
//				cout << " ";
//			}
//		}
//	}
//}
//
//void printbox(int r,int c, int bRows, int bCols)
//{
//	system("cls");
//	for (int ri = 0; ri < r; ri++)
//	{
//		for (int ci = 0; ci < c; ci++)
//		{
//			drawBox(ri * bRows, ci * bCols, bRows, bCols);
//		}
//	}
//}
//void drawCross(int cr, int cc,int scale, char sym = -37)
//{
//	gotoRowCol(cr, cc);
//	cout << sym;
//	gotoRowCol(cr-1, cc-1);
//	cout << sym;
//	gotoRowCol(cr-1, cc+1);
//	cout << sym;
//	gotoRowCol(cr-2, cc-2);
//	cout << sym;
//	gotoRowCol(cr-2, cc+2);
//	cout << sym;
//
//	gotoRowCol(cr+1, cc-1);
//	cout << sym;
//	gotoRowCol(cr + 1, cc + 1);
//	cout << sym;
//	gotoRowCol(cr + 2, cc -2);
//	cout << sym;
//	gotoRowCol(cr + 2, cc + 2);
//	cout << sym;
//	
//}
//void ExitCell(int rdim, int cdim)
//{
//	drawBox(0 * rdim, 10 * cdim, rdim, cdim);
//	gotoRowCol(0 * rdim + rdim / 2, 10 * cdim +1);
//	//drawCross(0 * rdim + rdim / 2, 10 * cdim + cdim / 2,3);
//	cout << "Exit";
//}


int main()
{
	chess C;
	C.play();
	//drawBox()
	//_getch();
	//int height = 70;
	//int width = 50;
	//int rdim = height / 8;
	//int cdim = width / 8;
	//
	//printbox(8, 8, rdim, cdim);
	////ExitCell(rdim, cdim);
	//while (true)
	//{

	//}
	////cout << "hello";
	return _getch();
}
/*
int main1()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}*/
//#include<string>
//#include<string.h>
//#include<iostream>
//#include<SFML/Graphics.hpp>
//using namespace std;
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//	sf::CircleShape shape(100.f);
//	shape.setFillColor(sf::Color::Green);
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//		window.clear();
//		window.draw(shape);
//		window.display();
//	}
//
//	return 0;
//}
//
//void static getRowColbyLeftClick(int& rpos, int& cpos, sf::RenderWindow& window)
//{
//	while (true)
//	{
//		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//		{
//			sf::Vector2i p = sf::Mouse::getPosition(window);
//
//			cpos = p.x;
//			rpos = p.y;
//			break;
//		}
//	}
//}
//
//
//// Function to print image on screen
//
//void print(sf::RenderWindow& window,string fileName,int r, int c)
//{
//	sf::Texture temp;
//	if (!temp.loadFromFile(fileName))  //  img ==> file name for image
//	{
//		throw("Unable to load img");
//	}
//
//	sf::Sprite s(temp);
//	s.setScale(0.1, 0.1); //  (width and heigth of image to be printed)
//
//	s.setPosition(r, c); // position of image
//	window.draw(s);	// draw() will only draw image on backend, image will not display on screen
//	window.display();  // display() will show image on screen
//}
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
//	string s = "king.png";
//	string k = "horse.png";
//	//print(window, k, 10, 100);
//	print(window,s,10,10);
//	/*sf::CircleShape shape(100.f);
//	shape.setFillColor(sf::Color::Green);
//	*/
//	
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//	
//		window.clear();
//		//window.draw(shape);
//		print(window,s,10,10);
//		//print(window, k, 10, 100);
//		window.display();
//		//window.clear();
//		//print(window, k, 10, 100);
//		//window.display();
//	}
//	
//	
//	return 0;
//}
