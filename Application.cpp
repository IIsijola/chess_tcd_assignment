#include <iostream>
#include "Application.h"
#include "ChessBoard.h"


void Application::run() {

	char input = 'n';

	int orow, ocol, nrow, ncol, player_counter;
	ChessBoard* myboard = new ChessBoard();
	myboard->setUp();
	player_counter = 1;

	while (input != 'q' && input != 'Q') {

    if(input == 'P' || input == 'p'){
      myboard->moves();
    }

		myboard->printBoard();

		std::cout << "Enter the row and column of the piece you want to move: ";
		std::cin >> orow >> ocol;
		std::cout << "Enter the new row and the new column: ";
		std::cin >> nrow >> ncol;

		try {
			myboard->move(orow, ocol, nrow, ncol);
		}
		catch (const char* error_msg) {
			std::cout << error_msg << std::endl;
		}

		std::cout << "Do you want to quit (q/Q) or p to print all moves up to now: ";
		std::cin >> input;

	}
};

void Application::test() {
	ChessBoard* myboard = new ChessBoard();
	myboard->setUp();

  // illegal moves
	try {
		myboard->move(6, 0, 6, 1);
		std::cout << "Test Failed" << std::endl;
	}
	catch (...) {
		std::cout << "Test Passed" << std::endl;
	}

	try {
		myboard->move(7, 3, 6, 3);
		std::cout << "Test Failed" << std::endl;
	}
	catch (...) {
		std::cout << "Test Passed" << std::endl;
	}

	try{
		myboard->move(7, 3, 0, 0);
		std::cout << "Test Failed" << std::endl;
	}catch(...){
		std::cout << "Test Passed" << std::endl;
	}
};