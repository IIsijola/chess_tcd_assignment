#include <iostream>
#include "Move.h"

Move::Move(ChessPiece *piece, ChessBoardSquare *start, ChessBoardSquare *end){

  if(m_piece != nullptr){
    throw "Move Exception cannot reset a move";
  }

  m_piece = piece;
  m_start = start;
  m_end = end;

}

void Move::setNext(Move *next){
  if(next == nullptr){
    throw "Cannot set next move to a nullptr";
  }

  m_next = next;
}

Move * Move::getNext(){
  return m_next;
}

void Move::print(){
  std::cout << "Piece '" << m_piece->getName() << "' moved from ";
  m_start->print(); 
  std::cout << " to ";
  m_end->print();
  std::cout << std::endl; 
}