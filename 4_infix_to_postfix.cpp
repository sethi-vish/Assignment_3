#include <iostream>
#include <string>
using namespace std;

#define MAXLEN 100

typedef struct {
    char element[MAXLEN];
    int top;
} mystack;

mystack init() { mystack S; S.top = -1; return S; }
int isEmpty(mystack S) { return S.top == -1; }
int isFull(mystack S) { return S.top == MAXLEN-1; }
mystack push(mystack S, char x) { if (!isFull(S)) S.element[++S.top] = x; else cout << "Overflow!\n"; return S; }
mystack pop(mystack &S) { if (!isEmpty(S)) S.top--; else cout << "Underflow!\n"; return S; }
char top(mystack S) { if (!isEmpty(S)) return S.element[S.top]; return '\0'; }

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

string infixToPostfix(string infix) {
    mystack S = init();
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            S = push(S, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(S) && top(S) != '(') {
                postfix += top(S);
                pop(S);
            }
            if (!isEmpty(S)) pop(S);
        }
        else if (isOperator(ch)) {
            while (!isEmpty(S) && precedence(top(S)) >= precedence(ch)) {
                postfix += top(S);
                pop(S);
            }
            S = push(S, ch);
        }
    }

    while (!isEmpty(S)) {
        postfix += top(S);
        pop(S);
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}