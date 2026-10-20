#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack
{
private:
    int Tos;
    int MaxSize;
    T *arr;

public:
    Stack(int size)
    {
        MaxSize = size;
        arr = new T[size];
        Tos = -1;
    }
    ~Stack()
    {
        delete[] arr;
    }
    bool isFull() const
    {
        return (Tos == MaxSize - 1);
    }
    bool isEmpty() const
    {
        return (Tos == -1);
    }
    void push(T x)
    {
        if (isFull())
        {
            cout << "Stack is full !" << endl;
            return;
        }
        Tos++;
        arr[Tos] = x;
    }
    void pop(T &x)
    {
        if (isEmpty())
        {
            cout << "Stack is empty !" << endl;
            return;
        }
        x = arr[Tos];
        Tos--;
    }
    T peek() const
    {
        return arr[Tos];
    }
};

int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

int main()
{
    string expression = "9+(3*4-8)/(2+2)^2*5-6";
    string postFixExpr = "";
    Stack<int> S(100);

    for (int i = 0; i < expression.length(); i++)
    {
        char currentElement = expression[i];
        // if its an operand
        if (currentElement >= '0' && currentElement <= '9')
        {
            postFixExpr += currentElement;
        }
        // if its an opening bracket
        else if (currentElement == '(')
        {
            S.push(currentElement);
        }
        // if its a closing bracket
        else if (currentElement == ')')
        {
            int Tos;
            // pop untill opening bracket is encountered
            while (!S.isEmpty())
            {

                S.pop(Tos);
                if (Tos == '(')
                {
                    break;
                }

                postFixExpr = postFixExpr + (char)Tos;
            }
        }
        // if its an operator
        else if (currentElement == '+' || currentElement == '-' || currentElement == '*' || currentElement == '/' || currentElement == '^')
        {
            int Tos;

            while (!S.isEmpty())
            {
                S.pop(Tos);
                if (precedence(char(Tos)) >= precedence(currentElement))
                {
                    postFixExpr += (char)Tos;
                }
                else
                {
                    S.push(Tos);
                    break;
                }
            }

            S.push(currentElement);
        }
    }

    int Tos;

    while (!S.isEmpty())
    {
        S.pop(Tos);
        postFixExpr = postFixExpr + (char)Tos;
    }

    cout << "Postfix Expression: " << postFixExpr << endl;

    return 0;
}
