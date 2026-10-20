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
int main()
{
    string expression = "26+9*6+";
    Stack<int> S(expression.length());

    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            S.push(expression[i] - '0');
        }
        else
        {
            int rightOperand, leftOperand;
            int result = 0;

            S.pop(rightOperand); // Second oper
            S.pop(leftOperand);  // First opr

            if (expression[i] == '+')
                result = leftOperand + rightOperand;
            else if (expression[i] == '-')
                result = leftOperand - rightOperand;
            else if (expression[i] == '*')
                result = leftOperand * rightOperand;
            else if (expression[i] == '/')
                result = leftOperand / rightOperand;

            S.push(result);
        }
    }

    cout << "Result = " << S.peek() << endl;

    return 0;
}
