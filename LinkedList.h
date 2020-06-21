#pragma once
#include "Move.h"

class LinkedList{


  private:
    Move * m_head = nullptr;
    Move * m_last = nullptr;


  public:
    ~LinkedList();

    void append(Move * move);
    void display();

};