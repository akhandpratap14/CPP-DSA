#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node (int data1, Node* next1, Node* back1){
        this->data = data1;
        this->next = next1;
        this->back = back1;
    }

    public:
    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->back = nullptr;
    }
};

Node* array2DoublyLinkedList(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void printLL(Node* head){
    Node* temp = head;
    while (temp){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

// Delete Head 
Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}
Node* deleteTailNode(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

Node* deleteKthNode(Node* head, int x){
    if(head == NULL){
        return NULL;
    }
    Node* KNode = head;
    int c = 0;
    while(KNode != NULL){
        c++;
        if(c == x) break;
        KNode = KNode->next;
    }
    Node* prev = KNode->back;
    Node* front = KNode->next;
    if(prev == NULL && front == NULL){
        delete head;
        return NULL;
    } else if(prev == NULL){
        return deleteHead(KNode);
    } else if(front == NULL){
        return deleteTailNode(KNode);
    }
    prev->next = front;
    front->back = prev;
    KNode->next = nullptr;
    KNode->back = nullptr;

    delete KNode;

    return head;
}

void deleteGivenNode(Node* node){
    Node* prev = node->back;
    Node* front = node->next;
    prev->next = front;
    front->back = prev;
    delete node;
}

// Insert at Head 
Node* insertAtHead(Node* head, int x){
    Node* node = new Node(x, head, nullptr);
    head->back = node;

    return node;
}

// Insert at tail
Node* insertAtTail(Node* head, int x){
    if(head == NULL){
        return insertAtHead(head, x);
    }
    Node* mover = head;
    while(mover->next != NULL){
        mover = mover->next;
    }
    Node* prev = mover->back;
    Node* newTail = new Node(x, mover, prev);
    prev->next = newTail;
    mover->back = newTail;

    return head;
}

// Insert at KNode
Node* insertAtKNode(Node* head, int x, int num){
    if(x == 1){
        return insertAtHead(head, num);
    }
    Node* KNode = head;
    int c = 0;
    while(KNode != NULL){
        c++;
        if(c == x) break;
        KNode = KNode->next;
    }
    Node* prev = KNode->back;

    Node* newNode = new Node(num, KNode, prev);
    prev->next = newNode;
    KNode->back = newNode;

    return head;
}

void insertBeforeNode(Node* node, int val){
    Node* prev = node->back;
    Node* newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
}

// 1 -> 2 -> 3 -> 4
// 2 <-> 1
Node* reverseDLinkedList(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* mover = head;

    stack<int> st;

    while(mover != NULL){
        st.push(mover->data);
        mover = mover->next;
    }

    mover = head;

    while(mover != NULL){
        mover->data = st.top();
        st.pop();
        mover = mover->next;
    }
    
    return head;
}

Node* reverseDllOptimal(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* last = NULL;
    Node* mover = head;
    while(mover != NULL){
        last = mover->back;
        mover->back = mover->next;
        mover->next = last;
        mover = mover->back;
    }
    return last->back;
}

Node* middleNode(Node* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* mover = head;
    int count = 0;
    while(mover != NULL){
        count++;
        mover = mover->next;
    }
    mover = head;
    int middle = count/2 +1;
    while(mover != NULL){
        middle = middle - 1; 
        if(middle == 0) break;
        mover = mover->next;
    }
    return mover;
}

void middleNodeWithTortoise(Node* head){
    if (head == NULL || head->next == NULL) {
        return;
    }
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    cout << slow->data << endl;
}

int detectCycle(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL){
        slow = fast->next;
        fast = fast->next->next;
        if(fast == slow) return true;
    }
    return false;
}
bool isPalindromeBrute(Node* head){
    Node* mover = head;
    stack<int> st;
    while (mover != NULL ){
        st.push(mover->data);
        mover = mover->next;
    }
    mover = head;
    while(mover != NULL && mover->next != NULL){
        if (mover->data != st.top()){
            cout << "not palindrome" << endl;
            return false;
        } 
        st.pop();
        mover = mover->next;
    }
    return true;
}

bool isPalindromeOptimal(Node* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* slow = head;
    Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* newHead = reverseDllOptimal(slow->next);

    Node* first = head;
    Node* second = newHead;

    int count = 0;

    while(second != NULL){
        if(first->data != second->data){
            reverseDllOptimal(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseDllOptimal(newHead);
    return true;
}

// rev = 1 -> 2
// fast = 1 -> 2 -> 3
// 1== 1
// 2==1


int main() {

    vector<int> arr;

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);

    // arr.push_back(23);
    // arr.push_back(12);
    // arr.push_back(45);
    // arr.push_back(34);
    // arr.push_back(89);
    // arr.push_back(32);
    // arr.push_back(76);
    // arr.push_back(21);

    Node* head = array2DoublyLinkedList(arr);

    Node* temp = head;

    cout << "Doubly Linked List: ", printLL(temp);

    cout << endl;

    // temp = deleteHead(temp);

    // cout << "Removed Head: ", printLL(temp);

    // temp = reverseDllOptimal(temp);
    // cout << "Kth Node: ", printLL(temp);

    // cout << "Middle Node: ", middleNode(temp);
    // middleNodeWithTortoise(temp);

    // cout << isPalindromeBrute(head);

    cout << isPalindromeOptimal(head);

    return 0;
}