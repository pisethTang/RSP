#include <iostream>

struct Node{
    int data;
    Node* next;

    // Constructors to initialize data and set next to nullptr
    Node(int x): data(x), next(nullptr){}
    Node(): Node(0) {}
};

class LinkedList{ // Singly Linked List
    private:
        Node* head; //pointer to the first node in the list
        int length;
    public:
        LinkedList(): head(nullptr), length(0){ }
        
        // Count nodes
        int get_length() const {return length;}

        // Sort lists in ascending or descending order
        // <in progress>

        // Concatenate lists
        // <in progress>

        // Inserts node at the end of the list
        void insertEnd(int value){
            Node* newNode = new Node(value);
            if(head == nullptr) head = newNode; // 
            else{ // List is not empty, 
            //traverse till the end of list (until current = nullptr),
            // then let that current node (currently pointing to nullptr) point to that newly created node, newNode.
                Node* current = head;
                while(current -> next != nullptr) current = current -> next;
                current -> next =  newNode;
            }
            length++;
        }

        // Insert node at the beginning of the list
        void insertBegin(int value){
            Node* newNode = new Node(value);
            // if the head is a nullptr (an empty list), just let the head point to the new node (same as above)
            if(head != nullptr) 
                {
                    // head = newNode; 
                    newNode -> next = head;
                }
                head = newNode;
                length++;

        }



        // Insert at before or after specific position
        void insertBefore(int targetValue, int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            // If the list is empty, just add the new node
            head = newNode;
        } else if (head->data == targetValue) {
            // If the target is the head, insert before the head
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr && current->next->data != targetValue) {
                current = current->next;
            }
            if (current->next != nullptr) {
                newNode->next = current->next;
                current->next = newNode;
            }
        }
        length++;
    }


    void insertAfter(int targetValue, int value) {
        Node* newNode = new Node(value);
        Node* current = head;

        while (current != nullptr && current->data != targetValue) {
            current = current->next;
        }

        if (current != nullptr) {
            newNode->next = current->next;
            current->next = newNode;
        }
        length++;
    }

        // The reason why we implement insertion at the beginning and at the end of list separate from the insert at a specified position procedure is due to the fact that 
        // Insertion at the beginning and the end require less elementary operations but 

        void insertGeneralized(){
            // <optional_in progress>
            // Just implement an insert menu where user can insert at beginning, ending and specific and increase length by 1
        }    	

        // Search : by value or position
        // <in progress>


        // Prints all elements in the singly linked list
        void displayList(){
            Node* current = head;
            if (current == nullptr) std::cout << "<Empty>";
            while(current != nullptr){
                std::cout << current -> data << " ";
                current  = current -> next;
            }
            std::cout << std::endl;
        }

        // delete a specific value
        // <in progress>

        // The destructor is called to delete every single element in the linked list
        ~LinkedList(){
            Node* current = head;
            Node* next;
            while(current != nullptr){
                next = current -> next;
                delete current;
                current = next;

            }
        }
    
};




int main(){
    // Crate a linked list and perform operations
    LinkedList myList;

    // insert at the end
    myList.insertEnd(1);
    myList.insertEnd(22);
    myList.insertEnd(31);
    myList.insertEnd(54);

    std::cout << "Linked List: ";
    myList.displayList();    // 10 21 34 54
    std::cout << "Length: " << myList.get_length() << std::endl;

    myList.insertBegin(3);
    myList.insertBegin(2);
    myList.insertBegin(18);

    std::cout << "Linked List: ";
    myList.displayList(); // 18 2 3 10 21 34 54

    std::cout << "Length: " << myList.get_length() << std::endl;

    myList.insertBefore(3, 100);
    myList.displayList(); // 18 2 3 10 21 34 54

    std::cout << "Length: " << myList.get_length() << std::endl;

    myList.insertAfter(22, 200);
    myList.displayList(); // 18 2 3 10 21 34 54

    std::cout << "Length: " << myList.get_length() << std::endl;

    return 0;
}