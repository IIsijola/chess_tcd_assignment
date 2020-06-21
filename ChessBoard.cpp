#include <iostream>
#include <string>
#include "ChessBoard.h"
#include "ChessBoardSquare.h"
#include "ChessPiece.h"

void ChessBoard::setUp() {

  m_list = new LinkedList();

	for (int col = 0; col < 8; col++) {
		m_board[6][col].setPiece(new Pawn());
		m_board[1][col].setPiece(new Pawn(true));
	}

	m_board[0][0].setPiece(new Rook(true));
	m_board[7][0].setPiece(new Rook());

	m_board[0][7].setPiece(new Rook(true));
	m_board[7][7].setPiece(new Rook());

	m_board[0][1].setPiece(new Knight(true));
	m_board[7][1].setPiece(new Knight());

	m_board[0][6].setPiece(new Knight(true));
	m_board[7][6].setPiece(new Knight());

	m_board[0][2].setPiece(new Bishop(true));
	m_board[7][2].setPiece(new Bishop());

	m_board[0][5].setPiece(new Bishop(true));
	m_board[7][5].setPiece(new Bishop());

	m_board[0][3].setPiece(new King(true));
	m_board[7][4].setPiece(new King());

	m_board[0][4].setPiece(new Queen(true));
	m_board[7][3].setPiece(new Queen());
}

void ChessBoard::move(int orow, int ocol, int nrow, int ncol) {

  if(orow > 7 || ocol > 7 || nrow > 7 || ncol > 7){
    throw "Cannot move outside the square";
  }
  if(orow < 0 || ocol < 0 || nrow < 0 || ncol < 0){
    throw "Cannot move outside the square";
  }

  m_board[orow][ocol].setLocation(orow, ocol);
  m_board[nrow][ncol].setLocation(nrow, ncol);

	ChessPiece* piece = m_board[orow][ocol].getPiece();

	if( piece == nullptr ){
		throw "Cannot move empty square";
	}

	if (piece->move(orow, ocol, nrow, ncol)) {
		
		ChessPiece* opiece = m_board[nrow][ncol].getPiece();

		if (opiece != nullptr) {

			if (opiece->getColor() == piece->getColor()) {
				throw "Invalid move cannot attack your own piece";
			}

			delete opiece;
		}
		m_board[nrow][ncol].setPiece(piece);
		m_board[orow][ocol].setPiece(nullptr);
	}

  m_list->append((new Move(piece,&m_board[orow][ocol],&m_board[nrow][ncol])));
}; 


void ChessBoard::printBoard() {

	for (int row = 0; row < 8; row++) {

		std::cout << row << ": " << "|";

		for (int col = 0; col < 8; col++) {
			
			if (m_board[row][col].getPiece() == nullptr) {
				std::cout << "   " << "|";
			}
			else {
				std::cout << " " << m_board[row][col].getPiece()->getName() << " |";
			}
		}
		//std::cout << std::endl << std::string(36, '-');

		std::cout << std::endl;
	}

	std::cout << std::string(36, '-') << std::endl;
	std::cout << "   ";
	for (int col = 0; col < 8; col++) {
		std::cout << "  " << col << " ";
	}

	std::cout << std::endl << std::endl; 
};


void ChessBoard::moves(){
  m_list->display();
  std::cout << std::endl;
}

