#include "Node.h"


Node::Node(int k) {
    key = k;
    next = nullptr;
}


Node::Node(): Node(0){}


int Node::getKey(){
    return key;
}

void Node::setKey(int k){
    key = k;
}

Node* Node::getNext(){
    return next;
}

void Node::setNext(Node* n){
    next = n;
}


Node::~Node(){
    // Nothing to deallocate
}