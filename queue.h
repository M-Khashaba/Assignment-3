#include <iostream>
using namespace std;

template <class T>
class Queue
{
private:
    struct Node
    {
        T data;
        Node* next;
    };
    Node* front;
    Node* rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    void push(T x)
    {
        Node* temp = new Node;
        temp->data = x;
        temp->next = NULL;
        if (front == NULL)
        {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void pop() {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete(temp);
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }
        Node* temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
