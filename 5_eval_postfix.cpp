#include <iostream>
using namespace std;
#define MAX 100
struct Stack {
    int arr[MAX];
    int top;
};

Stack init() {
    Stack s;
    s.top = -1;
    return s;
}

int isEmpty(Stack s) {
    return (s.top == -1);
}

int isFull(Stack s) {
    return (s.top == MAX - 1);
}

void push(Stack &s, int val) {
    if (isFull(s)) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    s.arr[++s.top] = val;
}

int pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    return s.arr[s.top--];
}

int performOperation(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) {
                cout << "Division by zero error!" << endl;
                return 0;
            }
            return a / b;
        default:
            cout << "Invalid operator!" << endl;
            return 0;
    }
}

int evaluatePostfix(string exp) {
    Stack s = init();
    
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (ch >= '0' && ch <= '9') {
            push(s, ch - '0');
        } else {
            int val2 = pop(s);
            int val1 = pop(s);
            int result = performOperation(val1, val2, ch);
            push(s, result);
        }
    }

    return pop(s);
}

int main() {
    string exp;
    cout << "Enter a postfix expression (single-digit operands): ";
    cin >> exp;

    int result = evaluatePostfix(exp);
    cout << "Result = " << result << endl;

    return 0;
}