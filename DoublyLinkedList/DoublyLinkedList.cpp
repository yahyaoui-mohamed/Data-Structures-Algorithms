#include<bits/stdc++.h>
using namespace std;

class Node{
     public : int value;
     Node* prev;
     Node* next;
     public : Node(int val)
     {
         this->value = val;
         this->prev  = NULL;
         this->next  = NULL;
     }
};

class DoublyLinkedList{
    Node* head = NULL;
    public : int length = 0;

    public : void insert(int val){
        Node* node = new Node(val);
        if(head == NULL){
            head = node;
        }
        else{
            Node* current = head;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = node;
            node->prev = current;
        }
        ++length;
    }

    public : void remove()
    {
        if(head == NULL){
            return;
        }
        else if(head->next == NULL){
        	head = NULL;
        	--length;
        	return;
		}
        Node* current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->prev->next = NULL;
        current = NULL;
        --length;
    }

    public : void insertAt(int index, int val){
        if(head == NULL && index > 1 || index < 1){
            return;
        }
        else if(head == NULL && index == 1){
            Node* node = new Node(val);
            head = node;
            return;
        }
        int i = 1;
        Node* current = head;
        while(current->next != NULL && i != index){
            current = current->next;
            i++;
        }
        if(current == NULL || index > i){
            return;
        }
        else{
            Node* node = new Node(val);
            if(current == head){
                node->next = current;
                current->prev = node;
                head = node;
            }
            else{
                current->prev->next = node;
                node->next = current;
                node->prev = current->prev;
                current->prev = node;
            }

        }
    }

    public : void removeAt(int index){
        Node* current = head;
        if(head == NULL){
            return;
        }
        else if(index == 1){
            if(head->next == NULL){
                head = NULL;
            }
            else{
                head = current->next;
                current = NULL;
                head->prev = NULL;
            }
            --length;
            return;
        }
        int i = 1;
        while(i != index && current != NULL){
            current = current->next;
            ++i;
        }
        if(current == NULL) return;
        else if(current->next == NULL){
            current->prev->next = NULL;
            current = NULL;
            --length;
            return;
        }
        else{
            current->prev->next = current->next;
            current->next->prev = current->prev;
            current = NULL;
        }

        --length;
    }


    public : bool empty()
    {
    	return head == NULL;
	}


	public : int indexOf(int val){
		Node* current = head;
		int i = 0;
		while(current != NULL){
			if(current->value == val)
			{
				return i;
			}
			current = current->next;
			++i;
		}
		return -1;
	}

	public : bool contains(int val){
		Node* current = head;
		while(current != NULL)
		{
			if(current->value == val){
				return true;
			}
			current = current->next;
		}
		return false;
	}

	public : void reverse()
	{
	    Node* current = head;
        if(current == NULL || current->next == NULL){
            return;
        }
        else{
            Node* prev;
            while(current != NULL){
                swap(current->prev, current->next);
                prev = current;
                current = current->prev;
            }
            head = prev;
        }
	}

	public : void print()
    {
        Node* current = head;
        cout << "NULL <-> ";
        while(current != NULL){
            cout << current->value << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

main()
{
    DoublyLinkedList dll;
    dll.insert(1);
    dll.insert(2);
    dll.insert(3);
    dll.insert(4);
    dll.print();
    dll.reverse();
    dll.print();


}
