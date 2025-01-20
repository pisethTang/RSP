#ifndef NODE_H
#define NODE_H

class Node{
    private:
        int key;
        Node* next;
    public:
        Node();
        Node(int k);

        // getters and setters 
        int getKey();
        void setKey(int k);

        Node* getNext();
        void setNext(Node* n);

        
        // Best practice to have this here.
        ~Node();
};




#endif 