#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;

    public:
    Node (int data1, Node* next1){
        this->data = data1;
        this->next = next1;
    }

    public:
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

Node* convertArray2ll(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i =1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// 1. go at end by travesal 
// 2. make new node 
// 3. point the prev node next to this node 
Node* insertAtEnd(Node* head, int x){
    Node* lastNode = new Node(x);
    if (lastNode == NULL){
        return lastNode;
    }
    Node* mover = head;
    while(mover->next != NULL){
        mover = mover->next;
    }
    mover->next = lastNode;
    return head;
}

int lengthOfLL(Node* head){
    int count = 0;
    Node* node = head;
    while(node){
        count++;
        node = node->next;
    }
    return count;
}


// 1. Travesal through node 
// 2. check if present till end 
// 3. return true if present else false
bool findValueLL(Node* head, int x){
    Node* mover = head;
    while(mover){
        if(mover->data == x){
            return true;
        }
        mover = mover->next;
    }
    return false;
}

// 1. store in temp;
// 2. move head to next 
Node* removeHead(Node* head){
    if(head == NULL){
        return head;
    }
    Node* temp = head;
    temp = temp->next;
    delete head;
    return temp;
}



Node* removeTailNode(Node* head){
    Node* mover = head;
    if (head == NULL || head->next == NULL){
        return head;
    }
    while(mover->next->next != NULL){
        mover = mover->next;
    }
    delete mover->next;
    mover->next = NULL;
    return head;
}

void printLL(Node* head){
    Node* temp = head;
    while (temp){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

bool detectLoopinLL(Node* head){
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow){
            return true;
        }
    }
    return false;
}



int main() {

    vector<int> arr;

    arr.push_back(23);
    arr.push_back(12);
    arr.push_back(45);
    arr.push_back(34);
    arr.push_back(89);
    arr.push_back(32);
    arr.push_back(76);
    arr.push_back(21);

    Node* head = convertArray2ll(arr); 
    Node* newLL = insertAtEnd(head, 19);
    Node* temp = newLL;

    cout << "Linked List: ", printLL(temp);

    cout << endl << "Count: " << lengthOfLL(head);
    cout << endl << "The Value is presnet or or not: " << findValueLL(head, 76) << endl;

    // Node* removedHeadLL = removeHead(temp);

    // cout << "Remove Head of Linked List: ", printLL(removedHeadLL);

    cout << endl;

    Node* removeTail = removeTailNode(temp);

    // removeTailNode(temp);

    cout << "Remove tail of Linked List: ", printLL(removeTail);

    return 0;
}