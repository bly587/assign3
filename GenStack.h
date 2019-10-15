#include <iostream>

using namespace std;

template <class T>
class GenStack
{
  public:
    GenStack(); //constructor
    GenStack(int maxSize); // overload constructor
    ~GenStack(); // destructor

    void push(T elem);
    T pop();
    T peek(); // AKA top()

    bool isFull();
    bool isEmpty();

    int size;
    int top;

    T *myArray; // declare memory address for array of chars --- pointer to a char
};

// default constructor
template <class T>
GenStack<T>::GenStack()
{
  //fill values
  myArray = new T[10];
  size = 10;
  top = -1;
}

// overload constructor
template <class T>
GenStack<T>::GenStack(int maxSize)
{
  myArray = new T[maxSize]; // dynamically allocated array ----- on the heap
  size = maxSize;
  top = -1;
}

// destructor
template <class T>
GenStack<T>::~GenStack()
{
  delete []myArray;
}

template <class T>
void GenStack<T>::push(T elem)
{
  // adds more memory for stack if it full
  if(isFull() == true)
  {
    //create a new stack
    T* newStack = new T[2 * size];
    //fill new stack with old stack's value
    for (int i = 0; i < size; ++i)
    {
      newStack[i] = myArray[i];
    }
    //update size
    size *= 2;
    //delete the old stack
    delete myArray;
    //change name of new stack
    myArray = newStack;
  }
  //add the element into the stack
  myArray[++top] = elem;
}

template <class T>
T GenStack<T>::pop()
{
  //check to see if empty
  if(isEmpty() == true)
  {
    cout << "Error: Stack is empty!" << endl;
    exit(1);
  }
  else
  {
    //return top value and AFTER update the top value
    return myArray[top--];
  }
}

template <class T>
T GenStack<T>::peek()
{
  //check if empty
  if(isEmpty() == true)
  {
    cout << "Error: Stack is empty!" << endl;
    exit(1);
  }
  else
  {
    return myArray[top];
  }
}

template <class T>
bool GenStack<T>::isFull()
{
  return(top == size-1);
}

template <class T>
bool GenStack<T>::isEmpty()
{
  return (top == -1);
}
