// CoursworkOne.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>  // Header that defines the standard input/output stream objects
using namespace std;



class Node           // calss  Node Declaration
{
public:
	                 // constructor  is a special public  member function that is automatically called when
	                 //  a class object is created;
	Node(int value, Node* nextptr = NULL, Node* prevptr = NULL, int currentpriority = 0)
	{
	   this-> value = value;
		next = nextptr;
		prev = prevptr;
	   priority = currentpriority;
	}

	int getVal(void)
	{	
	  return value;                    // this function returns the value in member variable value
	}

	Node* getNext(void)
	{
		return next;                   // this function returns the value in member variable next
	}

	Node* getPrev(void)
	{
		return prev;                  // this function returns the value in member variable previous
	}

	void setVal(int value)
	{
		value = value;                // this function copies the argumnet passed into the parameter to
		                              // the private memeber variable value;
	}

	void setPrev(Node* prevptr)
	{
		prev = prevptr;               // this function copies the argumnet passed into the parameter to
		                              // the private memeber variable prev;
	}  

	void setNext(Node* nextptr)
	{
		next = nextptr;               // this function copies the argumnet passed into the parameter to
		                              // the private memeber variable next;
	}

	int getPriority(void)
	{
		return priority;              // this function returns the value in member variable priority
	}

	void setPriority(int priority)
	{
		priority = priority;           // this function copies the argumnet passed into the parameter to
		                              // the private memeber variable priority;
	}

private:
	Node* next;                       //this is member variable next
	Node* prev;                       //this is member variable previous
    int priority;                    //this is member variable priority
	int value;                      //this is member variable value
};
// end of class Node 


class Stack                              // Stack calss  Declaration
{
public:
	Stack()                            // constructor  is a special public  member function that is automatically
							           //called when a class object is created;
	{  
		top = nullptr;                // top of the stack initialised to null  poniter 
	}

	~Stack()                           // a  destructor is a member function that is automatically
									  //called when a object is destroyed;
	{
		while (top != nullptr)     
			pop();                     // to Cleare the memeory after deleting the stack 
	}
	void push(int value)
	{
		Node* tmp = new Node(value, top);    // puting items into the Stack by creating new node;
		top = tmp;                           // to reassign the top of stack to a new created node in the stack
	}
	Node* NodePop(void)
	{

	}

	int pop()                               // function to remove items from stack strating from top 
	{
		int NewValue = 0;                         // variable to hold a value 
		if (top != nullptr)                  //checking that the top value is not null
		{
			cout << "popping this value " << endl;
			NewValue = top->getVal();            // geting the top vaule of the stack items
			Node* tmp = top;                // here is the top of stack assgining to tmp;
			top = top->getNext();           // reassign the top to the previous item in the stack
			delete tmp;                     // deleting the tmp (the top value )

		}
		else

		throw "underFlow exception occured";  // a program throws an exception when a problem shows up.this is done 
		                                       // using a throw keyword. 
		return NewValue;                            // to return the value
	}
private:

	Node* top;                                  //this is member variable top
};// end of Stack Class 

//========================================================================================================================

class Queue                                  ///Queue calss  Declaration
{
public:
	Queue(void)                               // Constructor explained above
	{
		front = back = nullptr;               // initialising  the fornt and the back of queue when first created . right now my 
	}                                          // my queue is empty so front and back equal to null.
	~Queue(void)                              // destructor explined above 
	{
		while (front != nullptr)
		{
			delete NodeDequeue();
		}
	}
	                                             // a queue may be implemented as a link list and expand or shrink with
	void Enqueue(int i, int priority = 0)        //each enqueue or dequeue operation.
	{                                            // Enqueue adds items to the queue.addition of an item to the queue is always
												 // done at the rear of the queue.
		Node* tmp = new Node(i, back);           // creating a new node (dinamically allocated node) to but items in the queue accept  
		                                        //a value. And Back to point to the back of the queue as well as to update the back of the queue when adding new items.
		back = tmp;                             //here is the back of the queue assign to the new created node .
		                                    
		if (front == nullptr) front = back; // checking if the front of the queue is null than assigning the front and the back
		else                                // of the queue to the same created node.
		{
			tmp = back->getNext();    // here is the front of the queue is not null so allowing me to get the front of the node.
			tmp->setPrev(back);        //  now updating the back of the node by setiing tha back of the queue to the new created node.
		}		                                           
	}

	int Dequeue(void)                            //Dequeue Rrmoves items from the queue.an item is removed or dequeued always
	{                                            // from the front of the queue.(first in , first out)
		Node* tmp = NodeDequeue();                // returning the node that is going to be removed(dequeue).In other word, Identifying the item to be deleted.
		int returnvalue = 0;
		if (tmp != nullptr)                        
		{
			cout << "now is Dequeuing thia value " << endl;
			returnvalue = tmp->getVal();
		}
		else
		{
			throw "the queue is Empty " ;    // print a message if the user tried to dequqe items more than the items in the queue.
		}
		if (front == nullptr)back = front;          // if the front of the queue is null that mean the front and the back assgning to the same value.
		delete tmp;                                //  actual deleting an item from the queue
		return returnvalue;                        // return the value is doing to be removed.
	}
protected:
	Node* back;
	Node* front;
private:
	virtual Node* NodeDequeue(void)                  //Virtual function a member function which is declared within a base
	{                                                //class and is redefined(Overriden)by a derived class. When you refer
		cout << "this is a base class " << endl;     //to a derived class object using a pointer to the base class,you can
		return 0;										//call a virtual function for that object and execute the derived class's
	}                                               //version of the function.
};                                                  


                                       // Scheduler class decelaration
class Scheduler :  public Queue       // Inheritance(is the process of creating new classes,called derived classes,	                                	                                       
{                                     //from exsiting or base classes.The derived class inherits all the capability of the base class but
	                                 //can add its own features.And the base class is unchanged by this process.
private:
	                                
	Node* NodeDequeue(void)           
	{                                     // method overriding (run time polymorphism)
		Node* tmp = front;               // to get the first value in the queue to remove it.                   
		if (front != nullptr)            // checking whether the front of the queue is null or not .
		{
			front = front->getPrev();    // after deleting the first item this code is to update the front of the queue by pointing the previous node to the fornt.
			if (front != nullptr) front->setNext(nullptr); // if the front of the queue is not null updating the next node .
		}
		//return tmp;                    // returing the item that is going to removed from the queue.
		//============
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
	
};




int main()
{
	  //Stack s;                          
	  //s.push(5);              
	  //s.push(10);
	  //s.push(15);
	  //try                            // a try block identifies a block of code for which particular exception will
		 //                                // be activated. it is followwd by one or more catch blocks
	  //{ 
		 // cout << s.pop() << endl;        
		 // cout << s.pop() << endl;         // removing items form stack by calling pop function 
		 // cout << s.pop() << endl;
		 // cout << s.pop() << endl;
	  //}
	  //catch (const char* msg)            // A program catches an exception with an exception handler at the place 
		 //                                // in a program where you want to hadel the problem
	  //{                                  // to handel erreors that occured at running time ( excusion time errors) 
		 // cout << msg << endl;
	  //}

	Scheduler  number;
		 
		number.Enqueue(20);
		number.Enqueue(30);
		number.Enqueue(40);
		cout << number.Dequeue() << " " << endl;
		cout << number.Dequeue() << " " << endl;
		cout << number.Dequeue() << " " << endl;
		cout << number.Dequeue() << " " << endl;
		//cout << number.Dequeue() << " " << endl;
	  system("pause");
	  return 0;
}

