#pragma once
#include "ChessBoardSquare.h"
#include "LinkedList.h"

class ChessBoard{

private:
	ChessBoardSquare m_board[8][8];
  LinkedList * m_list = nullptr;

public:

	void setUp();
	void printBoard();
	void move(int orow, int ocol, int nrow, int ncol);
  void moves();
};