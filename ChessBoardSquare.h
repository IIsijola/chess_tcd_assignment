#pragma once
#include "ChessPiece.h"

class ChessBoardSquare {

private:
	ChessPiece * m_piece = nullptr;
  int m_row;
  int m_col;

public:

	ChessPiece* getPiece();
	void setPiece(ChessPiece * piece);
  void setLocation(int row, int col);
  void print();
};
