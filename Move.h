#pragma once 
#include "ChessPiece.h"
#include "ChessBoardSquare.h"

class Move{
  private:
    ChessPiece * m_piece = nullptr;
    ChessBoardSquare * m_start = nullptr;
    ChessBoardSquare * m_end = nullptr;

    Move * m_next = nullptr;


  public:
    Move(ChessPiece * piece, ChessBoardSquare * start, ChessBoardSquare * end);
    void setNext(Move * next);
    void print();
    Move * getNext();

};