#include <iostream>
#include <string>
using namespace std;

#define MAXLEN 100

typedef struct {
    char element[MAXLEN];
    int top;
} mystack;

mystack init() { mystack S; S.top = -1; return S; }
int isEmpty(mystack S) { return (S.top == -1); }
int isFull(mystack S) { return (S.top == MAXLEN - 1); }
mystack push(mystack S, char x) { if (!isFull(S)) S.element[++S.top] = x; else cout << "Overflow!\n"; return S; }
mystack pop(mystack &S) { if (!isEmpty(S)) S.top--; else cout << "Underflow!\n"; return S; }
char top(mystack S) { if (!isEmpty(S)) return S.element[S.top]; return '\0'; }

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(string expr) {
    mystack S = init();

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            S = push(S, ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(S)) return false;
            else if (!isMatching(top(S), ch)) return false;
            else pop(S);
        }
    }

    return isEmpty(S);
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);

    if (isBalanced(expr)) cout << "Parentheses are balanced." << endl;
    else cout << "Parentheses are NOT balanced." << endl;

    return 0;
}