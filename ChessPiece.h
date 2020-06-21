#pragma once

class ChessPiece {

protected:
	bool m_moved = false;
	bool isBlack;
public:

	ChessPiece(bool black = false) : isBlack(black) {};
	virtual bool move(int orow, int ocol, int nrow, int ncol);
	virtual char getName();
	virtual bool getColor();

};


class Knight : public ChessPiece {


public:
	Knight(bool black = false) : ChessPiece(black) {};
  // using ChessPiece::ChessPiece;
	char getName();
	bool move(int orow, int ocol, int nrow, int ncol);

};


class Bishop : public ChessPiece {

public:
	Bishop(bool black = false) : ChessPiece(black) {};
  // using ChessPiece::ChessPiece;
	char getName();
	bool move(int orow, int ocol, int nrow, int ncol);

};

class King : public ChessPiece {

public:
	King(bool black = false) : ChessPiece(black) {};
  // using ChessPiece::ChessPiece;
	char getName();
	bool move(int orow, int ocol, int nrow, int ncol);

};

class Queen : public ChessPiece {

public:
	// Queen(bool black = false) : ChessPiece(black) {};
  using ChessPiece::ChessPiece;
	char getName();
	bool move(int orow, int ocol, int nrow, int ncol);

};

class Pawn : public ChessPiece {

public:
	Pawn(bool black = false) : ChessPiece(black) {};
  // using ChessPiece::ChessPiece;
	char getName();
	bool attack(int orow, int ocol, int nrow, int ncol);
	bool move(int orow, int ocol, int nrow, int ncol);

};


class Rook : public ChessPiece {

public:
	Rook(bool black = false) : ChessPiece(black) {};
  // using ChessPiece::ChessPiece;
	char getName();
	bool move(int orow, int ocol, int nrow, int ncol);
};

