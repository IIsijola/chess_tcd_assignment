// ChessGame_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Application.h"

int main()
{
	Application* myapp = new Application();
	myapp->test();
	myapp->run();

	delete myapp;
}

