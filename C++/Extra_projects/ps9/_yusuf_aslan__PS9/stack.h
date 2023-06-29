#ifndef STACK_H
#define STACK_H

class PopEmptyStackException
{
public:
    const char* what() const
    {
        return "Pop from empty stack";
    }
};

template <class T>
class Node
{
public:
    Node(T theData, Node<T>* theLink) : data(theData), link(theLink) {}

    Node<T>* getLink() const
    {
        return link;
    }

    const T& getData() const
    {
        return data;
    }

    void setLink(Node<T>* pointer)
    {
        link = pointer;
    }

private:
    T data;
    Node<T>* link;
};

template <class T>
class Stack
{
public:
    Stack() : top(nullptr) {}
    Stack(const Stack<T>& aStack);
    Stack<T>& operator=(const Stack<T>& rightSide);
    ~Stack();

    void push(T stackFrame);
    T pop();

    bool isEmpty() const;

private:
    Node<T>* top;
};

template <class T>
Stack<T>::Stack(const Stack<T>& aStack)
{
    if (aStack.top == nullptr)
    {
        top = nullptr;
    }
    else
    {
        top = new Node<T>(aStack.top->getData(), nullptr);
        Node<T>* temp = top;
        Node<T>* iter = aStack.top->getLink();

        while (iter != nullptr)
        {
            temp->setLink(new Node<T>(iter->getData(), nullptr));
            temp = temp->getLink();
            iter = iter->getLink();
        }
    }
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& rightSide)
{
    if (this != &rightSide)
    {
        Node<T>* temp = top;

        while (temp != nullptr)
        {
            Node<T>* next = temp->getLink();
            delete temp;
            temp = next;
        }

        if (rightSide.top == nullptr)
        {
            top = nullptr;
        }
        else
        {
            top = new Node<T>(rightSide.top->getData(), nullptr);
            temp = top;
            Node<T>* iter = rightSide.top->getLink();

            while (iter != nullptr)
            {
                temp->setLink(new Node<T>(iter->getData(), nullptr));
                temp = temp->getLink();
                iter = iter->getLink();
            }
        }
    }

    return *this;
}

template <class T>
Stack<T>::~Stack()
{
    Node<T>* temp = top;

    while (temp != nullptr)
    {
        Node<T>* next = temp->getLink();
        delete temp;
        temp = next;
    }
}

template <class T>
void Stack<T>::push(T stackFrame)
{
    top = new Node<T>(stackFrame, top);
}

template <class T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        throw PopEmptyStackException();
    }

    T result = top->getData();
    Node<T>* discard = top;
    top = top->getLink();
    delete discard;

    return result;
}

template <class T>
bool Stack<T>::isEmpty() const
{
    return (top == nullptr);
}

#endif

