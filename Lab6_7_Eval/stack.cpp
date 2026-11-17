
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <stdexcept>
using namespace std;

// ==========================================
// 1. TEMPLATE-BASED STACK ADT USING AN ARRAY
// ==========================================

template <class T>
class Stack
{
private:
    int top;
    int maxSize;
    T *arr;

public:
    // Parameterized constructor
    Stack(int size)
    {
        if (size <= 0)
            throw invalid_argument("Stack size must be positive");

        maxSize = size;
        top = -1;
        arr = new T[maxSize];
    }

    // Destructor
    ~Stack()
    {
        delete[] arr;
    }

    // Check whether stack is empty
    bool isEmpty() const
    {
        return top == -1;
    }

    // Check whether stack is full
    bool isFull() const
    {
        return top == maxSize - 1;
    }

    // Push an element
    bool push(const T &x)
    {
        if (isFull())
            return false;

        arr[++top] = x;
        return true;
    }

    // Pop an element using reference
    bool pop(T &x)
    {
        if (isEmpty())
            return false;

        x = arr[top--];
        return true;
    }

    // Return the top element without removing it
    T peek() const
    {
        if (isEmpty())
            throw underflow_error("Stack is empty");

        return arr[top];
    }

    // Return the number of elements
    int size() const
    {
        return top + 1;
    }
};

// ==========================================
// 2. BALANCED PARENTHESES
// ==========================================

bool isMatching(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(const string &expression)
{
    Stack<char> s(max(1, (int)expression.length()));

    for (int i = 0; i < (int)expression.length(); i++)
    {
        char ch = expression[i];

        // Opening brackets
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }

        // Closing brackets
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.isEmpty())
                return false;

            char open;
            s.pop(open);

            if (!isMatching(open, ch))
                return false;
        }
    }

    // All opening brackets must have been matched
    return s.isEmpty();
}

// ==========================================
// 3. REMOVE ALL OCCURRENCES OF AN ELEMENT
// ==========================================

template <class T>
void removeElement(Stack<T> &mainStack, const T &x)
{
    Stack<T> temp(mainStack.size());

    T element;

    // Transfer elements, excluding x
    while (!mainStack.isEmpty())
    {
        mainStack.pop(element);

        if (!(element == x))
        {
            temp.push(element);
        }
    }

    // Restore the original order
    while (!temp.isEmpty())
    {
        temp.pop(element);
        mainStack.push(element);
    }
}

// Display stack from top to bottom
template <class T>
void displayStack(Stack<T> &s)
{
    Stack<T> temp(s.size());
    T element;

    cout << "Top -> ";

    while (!s.isEmpty())
    {
        s.pop(element);
        cout << element << " ";
        temp.push(element);
    }

    // Restore the original stack
    while (!temp.isEmpty())
    {
        temp.pop(element);
        s.push(element);
    }

    cout << "<- Bottom" << endl;
}

// ==========================================
// 4. POSTFIX EXPRESSION EVALUATION
// Supports single-digit, non-negative operands
// ==========================================

bool evaluatePostfix(const string &expression, int &result)
{
    Stack<int> s(max(1, (int)expression.length()));

    for (int i = 0; i < (int)expression.length(); i++)
    {
        char ch = expression[i];

        // Ignore spaces
        if (isspace(static_cast<unsigned char>(ch)))
            continue;

        // Operand: push its numeric value
        if (isdigit(static_cast<unsigned char>(ch)))
        {
            s.push(ch - '0');
        }

        // Operator
        else if (ch == '+' || ch == '-' ||
                 ch == '*' || ch == '/' || ch == '^')
        {

            int a, b;

            // Two operands are required
            if (!s.pop(b) || !s.pop(a))
                return false;

            int value;

            switch (ch)
            {
            case '+':
                value = a + b;
                break;

            case '-':
                value = a - b;
                break;

            case '*':
                value = a * b;
                break;

            case '/':
                if (b == 0)
                    return false;

                value = a / b;
                break;

            case '^':
                value = static_cast<int>(pow(a, b));
                break;

            default:
                return false;
            }

            s.push(value);
        }

        else
        {
            return false;
        }
    }

    // A valid expression must leave exactly one result
    if (s.size() != 1)
        return false;

    s.pop(result);
    return true;
}

// ==========================================
// MAIN FUNCTION
// ==========================================

int main()
{
    // 1. Balanced parentheses
    cout << "=== BALANCED PARENTHESES ===\n";

    string expression = "{[a+(b*c)]}";

    if (isBalanced(expression))
        cout << expression << " is balanced.\n";
    else
        cout << expression << " is not balanced.\n";

    // 2. Remove a specific element
    cout << "\n=== REMOVE ELEMENT ===\n";

    Stack<int> s(10);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(20);
    s.push(40);

    cout << "Original stack:\n";
    displayStack(s);

    int x = 20;
    removeElement(s, x);

    cout << "After removing " << x << ":\n";
    displayStack(s);

    // 3. Postfix expression evaluation
    cout << "\n=== POSTFIX EVALUATION ===\n";

    string postfix = "82/3+";


    
    int result;

    cout << "Postfix expression: " << postfix << endl;

    if (evaluatePostfix(postfix, result))
        cout << "Result: " << result << endl;
    else
        cout << "Invalid postfix expression.\n";

    return 0;
}
