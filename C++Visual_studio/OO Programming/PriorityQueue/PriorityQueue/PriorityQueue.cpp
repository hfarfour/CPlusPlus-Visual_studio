// PriorityQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//  main.cpp
//  PriorityQueue
//
//  Created by hossam on 11/12/2020.
#include <iostream>
using namespace std;

class Node
{
private:
    int val;
    Node* next;
    Node* prev;
    int priority;

public:
    Node(int value, Node* nextptr = nullptr, Node* prevptr = nullptr, int currentpriority = 0)
    {
        val = value;
        next = nextptr;
        prev = prevptr;
        priority = currentpriority;
    }
    int getVal()
    {
        return val;
    }

    void setVal()
    { }

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

    int getPriority()
    {
        return priority;
    }
    void setPriority(int priority)
    {
        //priority=currentpriority;
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
    void Enqueue(int i, int priority = 0)
    {
        Node* tmp = new Node(i, back, nullptr, priority);
        back = tmp;
        if (front == nullptr) front = back;
        else
        {
            tmp = back->getNext();
            tmp->setPrev(back);
        }
    }
        //Node *NodeDequeue() // =====need adjuestment to use priority
        //{
        //    Node *tmp=front;
        //    if(front != nullptr)
        //    {
        //        front = front -> getPrev();
        //        if(front != nullptr) front ->setNext(nullptr);
        //    }
        //    return tmp;
        //}
        //                  //=====================================================
    Node* NodeDequeue() // =====need adjuestment to use priority
    {
        Node* max = front;   //max priority
        int mp = 0;          //maximum priority
        int cp = 0;          // current priority
        Node* temp = front;
        while (temp != nullptr)
        {
            cp = temp->getPriority();
            if (cp > mp)
            {
                mp = cp;
                max = temp;
            }
            temp = temp->getPrev();
        }
        Node* pmax = back;   // previous max
        Node* nmax = front;  // next max
        pmax = max->getPrev();
        nmax = max->getNext();
        pmax->setNext(nmax);
        nmax->setPrev(pmax);
        back = max->getNext();   //uopdate the back
        front = max->getPrev();  //update the front

        return max;

    }
    //==================================================
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
            cout << " the Queue is Empty" << endl;
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
                cout << temp->getPriority() << endl;
                temp = temp->getPrev();
            }
        }
        else
        {
            temp = back;
            while (temp != nullptr)
            {
                cout << temp->getVal() << ", ";
                cout << temp->getPriority() << endl;
                temp = temp->getNext();
            }
        }
        cout << endl << endl;
    }
};

int main()
{
    Queue numbers;

    numbers.Enqueue(10, 1);
    numbers.Enqueue(20, 3);
    numbers.Enqueue(50, 2);
    numbers.Enqueue(80, 2);
    numbers.print("forward");
    numbers.print("backward");
        cout<<numbers.Dequeue()<<" "<<endl;
        numbers.print("forward");
        cout<<numbers.Dequeue()<<" "<<endl;
        numbers.print("forward");
        cout<<numbers.Dequeue()<<" "<<endl;
        cout<<numbers.Dequeue()<<" "<<endl;
  
}
