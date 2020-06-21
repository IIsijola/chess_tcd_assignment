#include <iostream>
#include <cmath>
#include "ChessPiece.h"

bool ChessPiece::move(int orow, int ocol, int nrow, int ncol) {

	return true;
}

bool ChessPiece::getColor() {
	return isBlack; 
}

char ChessPiece::getName() {
	return 0; 
}

char Pawn::getName() {
	return 'P';
}

bool Pawn::move(int orow, int ocol, int nrow, int ncol) {

	int delta_row = (orow - nrow);
	int delta_col = abs(ocol - ncol);

	const char* error_msg = "Invalid Pawn movement";

	if (isBlack && delta_row < 0) {
		throw error_msg;
	}

	delta_row = abs(delta_row);

	if (delta_col !=0) {
		throw error_msg;
	}
	else if (delta_row > 2) {
		throw error_msg;
	}
	else if (delta_row == 2 && m_moved) {
		throw error_msg;
	}

	m_moved = true;
	return true;
}

bool Pawn::attack(int orow, int ocol, int nrow, int ncol) {

	int delta_row = abs(orow - nrow);
	int delta_col = abs(ocol - ncol);

	if (delta_row == delta_col == 1) {
		return true;
	}

	return false;
}

char Queen::getName() {
	return 'Q';
}

bool Queen::move(int orow, int ocol, int nrow, int ncol) {
	int delta_row = abs(orow - nrow);
	int delta_col = abs(ocol - ncol);
	int sum = delta_row + delta_col;

	const char* error_msg = "Invalid Queen move";

	if (sum != delta_row && sum != delta_col && delta_row != delta_col) {
		throw error_msg;
	}
	
	return true;
}

char King::getName() {
	return 'K';
}

bool King::move(int orow, int ocol, int nrow, int ncol) {
	int delta_row = abs(orow - nrow);
	int delta_col = abs(ocol - ncol);

	int distance = pow(delta_row, 2) + pow(delta_col, 2);

	char const* error_msg = "Invalid King move";

	if (distance > 2 && distance != 1) {
		throw error_msg;
	}

	return true;
}

char Knight::getName() {
	return 'N';
}

bool Knight::move(int orow, int ocol, int nrow, int ncol) {
	int delta_row = abs(orow - nrow);
	int delta_col = abs(ocol - ncol);

	const char* error_msg = "Invalid Knight move";

	if (delta_row == 0 || delta_col == 0) {
		throw error_msg;
	}
	else if ((delta_col + delta_row) != 3) {
		throw error_msg;
	}

	return true;
}

char Bishop::getName() {
	return 'B';
}

bool Bishop::move(int orow, int ocol, int nrow, int ncol) {
	int delta_row = abs(orow - nrow);
	int delta_col = abs(ocol - ncol);

	const char* error_msg = "Invalid Bishop move";

	if (delta_col != delta_row) {
		throw error_msg;
	}

	return true;
}

char Rook::getName() {
	return 'R';
}

bool Rook::move(int orow, int ocol, int nrow, int ncol) {

	int delta_row = abs(orow - nrow);
	int delta_col = abs(ocol - ncol);

	int sum = delta_row + delta_col;

	const char* error_msg = "Invalid Rook Move";

	if (sum != delta_row && sum != delta_col) {
		throw error_msg;
	}

	return true;
}

