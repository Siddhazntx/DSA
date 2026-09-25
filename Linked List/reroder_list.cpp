#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node* next) : val(x), next(next) {}
};

class Reorder {
private:
    Node* reverseList(Node* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        Node* prev = nullptr;
        Node* curr = head;

        while (curr != nullptr) {
            Node* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        return prev;
    }

public:
    Node* reorder(Node* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        Node* slow = head;
        Node* fast = head->next;
        Node* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* second = slow->next;
        slow->next = nullptr;

        Node* first = head;

        second = reverseList(second);

        Node* temp1 = first;
        Node* temp2 = second;

        while (temp2 != nullptr) {
            Node* next1 = temp1->next;
            Node* next2 = temp2->next;

            temp1->next = temp2;
            temp2->next = next1;

            temp1 = next1;
            temp2 = next2;
        }

        return head;
    }
};

Node* createList(const vector<int>& arr) {
    if (arr.empty())
        return nullptr;

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
    Reorder sol;

    vector<int> input1 = {1, 2, 3, 4};

    Node* head1 = createList(input1);

    cout << "Original List (Even): ";
    printList(head1);

    head1 = sol.reorder(head1);

    cout << "Reordered List (Even): ";
    printList(head1);

    freeList(head1);

    cout << "---------------------\n";

    vector<int> input2 = {1, 2, 3, 4, 5};

    Node* head2 = createList(input2);

    cout << "Original List (Odd): ";
    printList(head2);

    head2 = sol.reorder(head2);

    cout << "Reordered List (Odd): ";
    printList(head2);

    freeList(head2);

    return 0;
}
