//2252566
//Nguyen Quoc Huy
//Lab2HW Exercise 03
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
struct Node {
    int value;
    Node* next;
};
class Stack {
public:
    Stack() : top(NULL) {}

    void push(int value) {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = top;
        top = newNode;
    }
    int topValue() {
        if (top == NULL) {
            cout << "Error: Stack rong." << endl;
            return -1;
        }
        return top->value;
    }
 int pop() {
        if (top == NULL) {
            cout << "Error: Khong the pop tu mot stack rong." << endl;
            return -1;
        }
        int value = top->value;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }
    bool isEmpty() {
        return top == NULL;
    }


    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }
private:
    Node* top;
};
void visiblePeople(int heights[], int n) {
    int* answer = new int[n];
    for (int i = 0; i < n; i++) {
        answer[i] = 0;  
    }

    Stack stack;  

    for (int i = n - 1; i >= 0; i--) {
        int visibleCount = 0; 

        while (!stack.isEmpty() && heights[i] > stack.topValue()) {
            stack.pop(); 
            visibleCount++; 
        }
        if (!stack.isEmpty()) {
            visibleCount++; // Dem nguoi ngay tren dinh cua stack
        }
        answer[i] = visibleCount; 
        // Day chieu cao hien tai len stack
        stack.push(heights[i]);
    }
    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    delete[] answer;  
}
int main() {
    int n;
    cout << "Nhap so nguoi: ";
    cin >> n;

    int* heights = new int[n];
    cout << "Nhap chieu cao: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    visiblePeople(heights, n);

    delete[] heights; 
    return 0;
}
