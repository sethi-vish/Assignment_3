#include<iostream>
using namespace std;
#define MAXLEN 100

typedef struct {
    int element[MAXLEN];
    int top;
} mystack;

mystack init() { mystack S; S.top = -1; return S; }
int isEmpty(mystack S) { return (S.top == -1); }
int isFull(mystack S) { return (S.top == MAXLEN-1); }

int peek(mystack S) {
    if (isEmpty(S)) {
        cout << "Stack is empty" << endl;
        return -1;
    } else {
        return S.element[S.top];
    }
}

mystack push(mystack S, int x) {
    if (isFull(S)) cout << "Stack overflow!" << endl;
    else S.element[++S.top] = x;
    return S;
}

mystack pop(mystack S) {
    if (isEmpty(S)) cout << "Stack underflow!" << endl;
    else S.top--;
    return S;
}

void display(mystack S) {
    if (isEmpty(S)) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack elements (top to bottom): ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.element[i] << " ";
    }
    cout << endl;
}

int main() {
    mystack S = init();
    int choice, value;

    while (true) {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. isEmpty\n";
        cout << "6. isFull\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                S = push(S, value);
                break;

            case 2:
                S = pop(S);
                break;

            case 3: {
                int topElement = peek(S);
                if (topElement != -1)
                    cout << "Top element: " << topElement << endl;
                break;
            }

            case 4:
                display(S);
                break;

            case 5:
                if (isEmpty(S))
                    cout << "Stack is empty" << endl;
                else
                    cout << "Stack is NOT empty" << endl;
                break;

            case 6:
                if (isFull(S))
                    cout << "Stack is full" << endl;
                else
                    cout << "Stack is NOT full" << endl;
                break;

            case 7:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
} 
