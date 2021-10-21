#include<bits/stdc++.h>
using namespace std;

class Stack{
    class Node{
        public : int value;
        Node* next;
        public : Node(int val){
            this->value = val;
            this->next = NULL;
        }
    };

    Node* head = NULL;

    public : void push(int val){
        Node* node = new Node(val);
        if(head == NULL){
            head = node;
        }
        else{
            node->next = head;
            head = node;
        }
    }

    public : void pop()
    {
        if(head == NULL){
            return;
        }
        else{
            Node* current = head;
            head = head->next;
            current = NULL;
        }
    }

    public : int top(){
        return head->value;
    }

    public : bool empty(){
        return head == NULL;
    }
};

main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}
