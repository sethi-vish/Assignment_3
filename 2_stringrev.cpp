#include <iostream>
#include <string>
using namespace std;

#define MAXLEN 100

typedef struct {
    char element[MAXLEN];
    int top;
} mystack;

mystack init() {
    mystack S;
    S.top = -1;
    return S;
}

int isEmpty(mystack S) {
    return (S.top == -1);
}

int isFull(mystack S) {
    return (S.top == MAXLEN - 1);
}

mystack push(mystack S, char x) {
    if (isFull(S)) cout << "Stack overflow!" << endl;
    else {
        ++S.top;
        S.element[S.top] = x;
    }
    return S;
}

mystack pop(mystack &S) {
    if (isEmpty(S)) cout << "Stack underflow!" << endl;
    else S.top--;
    return S;
}

char top(mystack S) {
    if (isEmpty(S)) return '\0';
    else return S.element[S.top];
}

int main() {
    mystack S = init();
    string str, rev = "";

    cout << "Enter a string: ";
    getline(cin, str);

    for (char ch : str) {
        S = push(S, ch);
    }

    while (!isEmpty(S)) {
        rev += top(S);
        pop(S);
    }

    cout << "Reversed string: " << rev << endl;

    return 0;
}