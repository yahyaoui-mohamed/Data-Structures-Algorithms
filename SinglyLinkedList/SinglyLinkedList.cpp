#include<bits/stdc++.h>
using namespace std;

class Node{
    public : int value;
    Node* next;
    public : Node(int val){
        this->value = val;
        this->next = NULL;
    }
};

class LinkedList{
    Node* head = NULL;
    public : int size = 0;
    public : void insert(int val){
        Node* node = new Node(val);
        if(head == NULL){
            head = node;
            ++size;
            return;
        }

        else{
            Node* current = head;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = node;
            ++size;
        }
    }

    public : void remove(){
        if(head == NULL){
            return;
        }
        else if(head->next == NULL){
            head = NULL;
            --size;
            return;
        }
        else{
            Node* current = head->next;
            Node* prev = head;
            while(current->next != NULL){
                prev = current;
                current = current->next;
            }
            prev->next = NULL;
            current = NULL;
            --size;
        }
    }

    public : void insertAt(int pos, int val){
        int i = 1;
        Node* node = new Node(val);
        if(pos < 1){
            return;
        }
        else if(pos == 1){
            node->next = head;
            head = node;
        }
        else{
            Node* current = head;
            Node* prev;
            while(i != pos && current != NULL){
                prev = current;
                current = current->next;
                ++i;
            }
            if(current == NULL && i != pos){
                return;
            }
            else{
                prev->next = node;
                node->next = current;
            }
        }
    }

    public : void removeAt(int pos){
        int i = 1;
        if(pos < 1){
            return;
        }
        else if(pos == 1){
            Node* current = head;
            head = head->next;
            current = NULL;
        }
        else{
            Node* current = head;
            Node* prev;
            while(i != pos && current != NULL){
                prev = current;
                current = current->next;
                ++i;
            }
            if(current == NULL){
                return;
            }
            else{
                prev->next = current->next;
                current = NULL;
            }
        }
    }

    public : int indexOf(int val){
        int i = 0;
        Node* current = head;
        while(current != NULL){
            if(current->value == val){
                return i;
            }
            current = current->next;
            ++i;
        }
        return -1;
    }

    public : bool contains(int val){
        Node* current = head;
        while(current != NULL){
            if(current->value == val){
                return true;
            }
            current = current->next;
        }
        return false;
    }

    public : bool empty(){
        return head == NULL;
    }

    public : void reverse(){
        if(head == NULL){
            return;
        }
        Node* current = head->next;
        Node* prev = head;
        while(current != NULL){
            Node* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head->next = NULL;
        head = prev;
    }

    public : void print()
    {
        Node* current = head;
        while(current != NULL){
            cout << current->value << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;;
    }
};


main()
{
    LinkedList ls;
    ls.insert(1);
    ls.insert(2);
    ls.insert(3);
    ls.insert(4);
    ls.print();
}
