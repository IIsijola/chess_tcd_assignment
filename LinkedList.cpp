#include <iostream>

#include "LinkedList.h"


void LinkedList::append(Move *move){
  
  if(m_last != nullptr){

    m_last->setNext(move);
    m_last = move;

  }else{
    m_head = move;
    m_last = move;
  }

}


void LinkedList::display(){
    
  Move * current = m_head;

  while(current != nullptr){
    
    current->print();
    current = current->getNext();
  }
}

LinkedList::~LinkedList(){

  if(m_last == nullptr){
    delete m_head;
    return;
  }

  Move * current = m_head;
  Move * next = nullptr;

  while(current != nullptr){
  
    next = current->getNext();
  
    delete current;
    current = next;
  }

}