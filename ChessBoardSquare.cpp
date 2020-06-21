#include <iostream>
#include "ChessBoardSquare.h"

void ChessBoardSquare::setPiece(ChessPiece* piece) {
	m_piece = piece;
};

void ChessBoardSquare::setLocation(int row, int col){
  m_row = row;
  m_col = col;
}

ChessPiece* ChessBoardSquare::getPiece() {
	return m_piece;
}

void ChessBoardSquare::print(){
  std::cout << "row " << m_row << " col " << m_col;
}