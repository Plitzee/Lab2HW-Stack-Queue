//2252566
//Nguyen Quoc Huy
//Lab2HW Exercise 02

#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Node {
public:	
    string url;
    Node* prev;
    Node* next;

    Node(string url) : url(url), prev(NULL), next(NULL) {}
};

class BrowserHistory {
public:
    Node* current;
    Node* head;    
    BrowserHistory() {
        head = NULL;
        current = NULL;
    }
    void visit(string url) {
        Node* newNode = new Node(url);
        if (current) {
            current->next = newNode; 
            newNode->prev = current;  
        } else {
            head = newNode; 
        }
        current = newNode; 
    }

    string back() {
        if (current && current->prev) {
            current = current->prev; 
        }
        return current ? current->url : "No previous url"; 
    }
    string forward() {
        if (current && current->next) {
            current = current->next; 
        }
        return current ? current->url : "No forward url"; 
    }

    ~BrowserHistory() {
        Node* temp;
        while (head) { 
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};


void processBrowserHistory() {
    cout<<"please type the command"<<endl;
    BrowserHistory* browserHistory = new BrowserHistory(); 

    string command;
    while (getline(cin, command)) { 
        if (command.substr(0, 5) == "visit") {
            string urls = command.substr(6); 
            stringstream ss(urls);
            string url;
            cout<<"please type the command"<<endl;
            while (getline(ss, url, ',')) { 
                browserHistory->visit(url);
            }
            cout << "Visit: " << urls << endl;
        } else if (command == "back") {
            cout << "Current url: " << browserHistory->back() << endl; 
            cout<<"please type the command"<<endl;
        } else if (command == "forward") {
            cout << "Current url: " << browserHistory->forward() << endl;
            cout<<"please type the command"<<endl;
        }else if(command =="exit"){
        	break;
		}
		 else {
            cout << "Unknown command." << endl;
            cout<<"please type the command"<<endl;
        }
    }

    delete browserHistory; 
}

int main() {
    processBrowserHistory();  
    return 0;
}

