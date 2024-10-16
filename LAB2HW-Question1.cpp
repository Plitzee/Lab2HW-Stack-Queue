    //2252566
    //Nguyen Quoc Huy
    //Lab2HW Exercise 01
    #include <iomanip>
    #include <iostream>
    #include <string>
    #include <sstream>

    using namespace std;

    class Node {
        public:
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
    int pop() {
        if (top == NULL) {
            cout << "Can't pop an empty stack." << endl;
            return -1;  
        }
        int value = top->value;
        Node* temp = top;    
        top = top->next;      
        delete temp;          
        return value;
    }
        int topValue() {
            if (top == NULL) {
                cout << "Stack empty." << endl;
                return -1;
            }
            return top->value;
        }
        bool isEmpty() {
            return top == NULL;
        }
    void display() {
        Node* current = top;
        cout << "stack = < ";
        while (current != NULL) {    // Traverse 
            cout << current->value << " ";
            current = current->next;
        }
        cout << ">" << endl;
    }
    public:
        Node* top;
    };
    bool isValidMove(Stack& source, Stack& destination) {
        if (source.isEmpty()) {
            cout << "Cannot move an empty source stack." << endl;
            return false;}
        if (destination.isEmpty()) {
            return true;}
        return source.topValue() < destination.topValue();
    }
    void displayTowers(Stack& towerA, Stack& towerB, Stack& towerC) {
        cout << "A Tower"<<endl;
        towerA.display();
        cout << "B Tower"<<endl;
        towerB.display();
        cout << "C Tower"<<endl;
        towerC.display();
        cout << "========"<<endl;
    }
    void moveDisk(Stack& source, Stack& destination) {
        if (isValidMove(source, destination)) {
            int disk = source.pop();
            if (disk != -1) { // Ensure the move is valid
                destination.push(disk);
            }
        } else {
            cout << "Try again." << endl;
        }
    }


    bool isGameWon(Stack& towerC, int numDisks) {
        if (towerC.isEmpty()) {
            return false;}  
        Node* current = towerC.top;
        int expectedDisk = 1; 
        while (current != NULL) {
            if (current->value != expectedDisk) {
                return false;  }
            current = current->next;
            expectedDisk++; 
        }

        return expectedDisk - 1 == numDisks;
    }
    int main() {
        const int numDisks = 3; 

        Stack towerA, towerB, towerC;

        //  Khoi tao thap A voi cac dia theo thu tu giam dan 
        for (int i = numDisks; i > 0; i--) {
            towerA.push(i);
        }
        cout << "=== Demo Stack ==="<<endl;
        cout << "0.Creating Tower."<<endl;
        cout << "1. A -> B"<<endl;
        cout << "2. B -> A"<<endl;
        cout << "3. B -> C"<<endl;
        cout << "4. C -> B"<<endl;
        cout << "5. C -> A"<<endl;
        cout << "6. A -> C"<<endl;
        cout << "===================================\n";

        displayTowers(towerA, towerB, towerC);

        int move;
        while (!isGameWon(towerC, numDisks)) {
            cout << "Please input a move (1-6): ";
            cin >> move;

            switch (move) {
                case 1:
                    moveDisk(towerA, towerB); 
                    break;
                case 2:
                    moveDisk(towerB, towerA); 
                    break;
                case 3:
                    moveDisk(towerB, towerC); 
                    break;
                case 4:
                    moveDisk(towerC, towerB); 
                    break;
                case 5:
                    moveDisk(towerC, towerA); 
                    break;
                case 6:
                    moveDisk(towerA, towerC); 
                    break;
                default:
                    cout << "Wrong typing, try again between 1-6." << endl;
                    continue;
            }
            
            displayTowers(towerA, towerB, towerC);
        }

        cout << "Congrats! You won the Tower of Hanoi." << endl;

        return 0;
    }

