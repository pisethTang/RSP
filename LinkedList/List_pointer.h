#ifndef LIST_POINTER_H
#define LIST_POINTER_H

#include "Node.h"

class ListPointer{
    private:
        Node* head;
    public:
        ListPointer();
        ListPointer(int A[], int n); // pass in an array of integers 
        
        void add(int key);
        void remove(int key);
        bool search(int key);
        void print();
        ~ListPointer();
};



#endif 