//
//  main.cpp
//  InqueueAndDequeue
//
//  Created by hossam on 30/11/2020.
//
#include <stdlib.h>
#include <iostream>
using namespace std;

class Queue
{
private:
    int front;
    int back;
    int values[5];
public:
    Queue()
    {
        front = -1;
        back = -1;
        for (int i = 0; i < 5; i++)
        {
            values[i] = 0;
        }
    }
    bool IsEmpty()
    {
        if (front == -1 && back == -1)

            return true;

        else
            return false;

    }
    bool IsFull()
    {
        if (back == 4)
            return true;
        else
            return false;
    }

    void Enqueue(int val)
    {
        if (IsFull())
        {
            cout << " the queue is full right now so dequeue an item to do so  " << endl;
            return;
        }
        else if (IsEmpty())
        {
            front = 0;
            back = 0;
            values[back] = val;
        }
        else
        {
            back++;
            values[back] = val;
        }
    }
    int Dequeue()
    {
        int x;
        if (IsEmpty())
        {
            cout << " the queue is empty " << endl;
            return 0;
        }
        // if the queue has only one item
        else if (front == back)
        {
            x = values[front];
            values[front] = 0;
            front = -1;
            back = -1;
            return x;
        }
        else // if the queue has omore one item
        {
            x = values[front];
            values[front] = 0;
            front++;
            return x;
        }
    }
    int Count()
    {
        return(back - front + 1);

    }
    void display()
    {
        cout << " all the values in the Queue are : " << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << values[i] << "   ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q1;
    int option;
    int value;

    do
    {
        cout << "\n what operation do you want to perform ?  choose from the list .Enter 0 to exit " << endl;
        cout << "  press 1 to Enqueue ()  " << endl;
        cout << "  press 2 to Dequeue ()  " << endl;
        cout << "  press 3 to check whether the queue is empty or not ()  " << endl;
        cout << "  press 4 to check whether the queue is full or not () " << endl;
        cout << "  press 5 to count the element in the queue ()   : " << endl;
        cout << "  press 6 to display the content of the queue ()  " << endl;
        cout << "  press 7 to Clear the screen()  " << endl;

        cin >> option;

        switch (option)
        {
        case 0:
            cout << " thank you " << endl;
            break;

        case 1:
            cout << " Enqueue operation \n enter an item to enqueue  " << endl;
            cin >> value;
            q1.Enqueue(value);
            break;

        case 2:
            cout << " Dequeue operation /n " << q1.Dequeue() << endl;
            break;

        case 3:
            if (q1.IsEmpty())
            {
                cout << " queue is empty " << endl;
            }
            else
            {
                cout << " queue is Not empty " << endl;
            }
            break;

        case 4:
            if (q1.IsFull())
            {
                cout << " queue is full " << endl;
            }
            else
            {
                cout << " queue is Not full " << endl;
            }            break;

        case 5:
            cout << " count operation /n count of elements in the queue : " << q1.Count() << endl;
            break;

        case 6:
            cout << "display cunction is called " << endl;
            q1.display();
            break;

        case 7:
            system("cls");
            break;


        default:
            cout << " enter proper option number please " << endl;
            break;
        }
    } while (option != 0);
    {
        return 0;
    }
    return 0;
}
