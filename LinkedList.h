#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <stdexcept>

template <typename T>
struct Node
{
    T data;
    Node<T>* next;
};

template <class T>
class LinkedList
{
private:
    Node<T>* head;
    int count;
public:
    LinkedList()
    {
        head = NULL;
        count = 0;
    }

    ~LinkedList()
    {
        while (count > 0)
            removeAt(0);
    }

    void insertFront(const T data)
    {
        Node<T>* newNode = new Node<T>{ data, head };
        head = newNode;
        count++;
    }

    void insertAt(int index, const T data)
    {
        if (index < 0 || index > count)
            throw std::out_of_range("index out of range");
        if (index == 0)
        {
            insertFront(data);
            return;
        }
        Node<T>* temp = head;
        for (int i = 1; i < index; i++)
            temp = temp->next;
        Node<T>* newNode = new Node<T>{ data, temp->next };
        temp->next = newNode;
        count++;
    }

    T get(int index) {
        if (index < 0 || index >= count)
            throw std::out_of_range("index out of range");
        Node<T>* temp = head;
        for (int i = 1; i <= index; i++)
            temp = temp->next;
        return temp->data;
    }

    void removeAt(int index)
    {
        if (index < 0 || index >= count)
            throw std::out_of_range("index out of range");
        Node<T>* curr = head;
        if (index == 0)
        {
            head = curr->next;
            delete(curr);
        }
        else
        {
            for (int i = 1; i < index; i++)
                curr = curr->next;
            Node<T>* temp = curr->next->next;
            delete(curr->next);
            curr->next = temp;
        }
        count--;
    }

    int getCount() const
    {
        return count;
    }

    bool operator==(const LinkedList<T> &other) const
    {
        if (this == &other)
            return true;
        if (this->count != other.count)
            return false;
        Node<T>* temp1 = this->head;
        Node<T>* temp2 = other.head;
        for (int i = 0; i < count; i++)
        {
            if (temp1->data != temp2->data)
                return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
};

#endif