// Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//  week 8 Queue

//  Created by hossam on 29/11/2020.
#include <iostream>
using namespace std;

class Node
{
private:
    int val;
    Node* next;
    Node* prev;

public:
    Node(int value, Node* nextptr, Node* prevptr = nullptr)
    {
        this->val = value;
        next = nextptr;
        prev = prevptr;
    }
    int getVal()
    {
        return val;
    }

    void setNext(Node* nextptr)
    {
        next = nextptr;
    }

    Node* getNext()
    {
        return next;
    }

    void setPrev(Node* prevptr)
    {
        prev = prevptr;
    }

    Node* getPrev()
    {
        return prev;
    }

};
class Queue
{
protected:
    Node* back;
    Node* front;
public:
    Queue()
    {
        front = back = nullptr;
    }
    ~Queue()
    {
        while (front != nullptr)
        {
            delete NodeDequeue();
        }
    }
    void Enqueue(int i)
    {
        Node* tmp = new Node(i, back);
        back = tmp;
        if (front == nullptr) front = back;
        else
        {
            tmp = back->getNext();
            tmp->setPrev(back);
        }
    }
    Node* NodeDequeue()
    {
        Node* tmp = front;
        if (front != nullptr)
        {
            front = front->getPrev();
            if (front != nullptr) front->setNext(nullptr);
        }
        return tmp;
    }
    int Dequeue()
    {
        Node* tmp = NodeDequeue();
        int  ret = 0;
        if (tmp != nullptr)
        {
            ret = tmp->getVal();
        }
        else
        {
            cout << "Queue Empty" << endl;
        }
        if (front == nullptr) back = front;

        delete tmp;
        return ret;
    }
    void print(string order)
    {
        cout << " printing queue [" << order << "]" << endl;
        Node* temp = nullptr;
        if (order == "forward")
        {
            temp = front;
            while (temp != nullptr)
            {
                cout << temp->getVal() << ", ";
                temp = temp->getPrev();
            }
        }
        else
        {
            temp = back;
            while (temp != nullptr)
            {
                cout << temp->getVal() << ", ";
                temp = temp->getNext();
            }
        }
        cout << endl << endl;
    }
};

int main()
{
    Queue numbers;

    numbers.Enqueue(10);
    numbers.Enqueue(20);
    numbers.Enqueue(30);
    numbers.print("forward");
    cout << numbers.Dequeue() << " " << endl;
    //cout<<numbers.Dequeue()<<" "<<endl;
    numbers.print("forward");
    cout << numbers.Dequeue() << " " << endl;
    cout << numbers.Dequeue() << " " << endl;
    return 0;
}
