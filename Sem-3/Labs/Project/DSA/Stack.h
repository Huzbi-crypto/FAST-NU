// Stack.h
#ifndef STACK_H
#define STACK_H

#include <string>

#define SIZE 5

/**
 * @brief A template class representing a stack data structure.
 * 
 * @tparam T The type of elements stored in the stack.
 */
template <class T> class Stack {
public:
    /**
     * @brief Constructs an empty stack.
     */
    Stack();

    /**
     * @brief Pushes an element onto the top of the stack.
     * 
     * @param k The element to be pushed onto the stack.
     */
    void push(T k);

    /**
     * @brief Removes and returns the top element from the stack.
     * 
     * @return The top element of the stack.
     */
    T pop();

    /**
     * @brief Returns the top element of the stack without removing it.
     * 
     * @return The top element of the stack.
     */
    T topElement();

    /**
     * @brief Checks if the stack is full.
     * 
     * @return True if the stack is full, false otherwise.
     */
    bool isFull();

    /**
     * @brief Checks if the stack is empty.
     * 
     * @return True if the stack is empty, false otherwise.
     */
    bool isEmpty();

private:
    int top; /**< The index of the top element in the stack. */
    T st[SIZE]; /**< The array representing the stack. */
};

// Implementation of the Stack class template
template <class T> Stack<T>::Stack() { top = -1; }

/**
 * Checks if the stack is full.
 * 
 * @return true if the stack is full, false otherwise.
 */
template <class T> bool Stack<T>::isFull() {
  if (top == (SIZE - 1))
      return 1;
  else
      return 0;
}

/**
 * Checks if the stack is empty.
 * 
 * @return true if the stack is empty, false otherwise.
 */
template <class T> bool Stack<T>::isEmpty() {
  if (top == -1)
      return 1;
  else
      return 0;
}

/**
 * @brief Pushes an element onto the stack.
 * 
 * @param k The element to be pushed onto the stack.
 */
template <class T> void Stack<T>::push(T k) {
  if (isFull()) {
      std::cout << "Stack is full\n";
  }
  else {
      top = top + 1;
      st[top] = k;
  }
}

/**
 * @brief Removes and returns the top element from the stack.
 * 
 * @tparam T The type of elements stored in the stack.
 * @return T The popped element from the stack.
 */
template <class T> T Stack<T>::pop() {
  T popped_element = st[top];
  top--;
  return popped_element;
}

/**
 * Returns the top element of the stack.
 * 
 * @tparam T The type of elements in the stack.
 * @return The top element of the stack.
 */
template <class T> T Stack<T>::topElement() {
  T top_element = st[top];
  return top_element;
}

#endif // STACK_H
