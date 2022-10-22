#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

template <typename T>
Stack<T>::Stack(): vector<T>(){}

template <typename T>
Stack<T>::~Stack(){}

template <typename T>
void Stack<T>::pop()
{
    if(Stack<T>::empty()){
        throw out_of_range("Empty stack!");
    }
    vector<T>::pop_back();
}

template <typename T>
T const & Stack<T>::top() const
{
    if(Stack<T>::empty()){
      throw out_of_range("Empty stack!");
    }
    std::vector<T>::pop_back();
    return vector<T>::front();
}

template <typename T>
bool Stack<T>::empty() const
{
    return vector<T>::empty();
}

template <typename T>
size_t Stack<T>::size() const
{
    return vector<T>::size();
}

template <typename T>
void Stack<T>::push(const T& item)
{
    vector<T>::push_back(item);
}


#endif