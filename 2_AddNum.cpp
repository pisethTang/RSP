#include <bits/stdc++.h>

using namespace std;
  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* headList = new ListNode();
        ListNode* currList = headList;
        ListNode* currNode1;
        ListNode* currNode2;
        currNode1 = l1; // head node of l1 
        currNode2 = l2; // head node of l2 
        int sum = 0;
        while (currNode1 && currNode2){ // when this is fault, we've reached the end of either l1 or l2
            sum = currNode1 -> val + currNode2 -> val + carry;      
            if (sum >= 10){
                carry = 1;
                sum -= 10;
            }
            currList -> val = sum;
            currList -> next = new ListNode(sum);
            currList = currList -> next;
            currNode1 = currNode1 -> next;
            currNode2 = currNode2 -> next;
        }

        if (!currNode1 && currNode2){
            
        }
        else if (!currNode2 && currNode1){

        }
        else{ // both lists are empty
            if (carry == 1) currList -> next = new ListNode(1);
        }

        return headList;
    }
};



int main(){


    return 0;
}