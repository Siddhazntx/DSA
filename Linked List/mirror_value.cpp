#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

class List {
private:
    Node* reverseList(Node* head) {
        if(head == NULL) return NULL;
        Node* prev = NULL;
        Node* curr = head;

        while(curr != NULL) {
            Node* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    } 

public: 
    Node* mirrorvalue(Node* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL){
            head->val += head->val;
            return head; 
        }
        
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;

        while(fast != NULL && fast->next != NULL){
            prev = slow; 
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* first = head;
        prev->next = NULL; 
        
        Node* second = reverseList(slow);
        
        
        Node* secondHeadForRestore = second; 

        Node* p1 = first;
        Node* p2 = second;

        while(p1 != NULL && p2 != NULL){ 
            int mirrorval = p1->val + p2->val;
            p1->val = mirrorval;
            p2->val = mirrorval;

            p1 = p1->next;
            p2 = p2->next;
        }

        if(p2 != NULL){ 
            p2->val += p2->val;
        }
        
        
        second = reverseList(secondHeadForRestore); 
        prev->next = second; 
        
        return head;
    }
}; 


Node* createList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

void freeList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Test Case 1: Even length list
    vector<int> input1 = {1, 2, 3, 4};
    Node* head1 = createList(input1);
    
    cout << "Original List (Even): ";
    printList(head1);
    
    List sol;
    head1 = sol.mirrorvalue(head1);
    
    cout << "Mirrored List (Even): ";
    printList(head1);
    freeList(head1);
    
    cout << "---------------------\n";
    
    // Test Case 2: Odd length list
    vector<int> input2 = {1, 2, 3, 4, 5};
    Node* head2 = createList(input2);
    
    cout << "Original List (Odd):  ";
    printList(head2);
    
    head2 = sol.mirrorvalue(head2);
    
    cout << "Mirrored List (Odd):  ";
    printList(head2);
    freeList(head2);
    
    return 0;
}