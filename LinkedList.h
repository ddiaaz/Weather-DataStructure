#ifndef WEATHER_PROJECT_LINKEDLIST_H
#define WEATHER_PROJECT_LINKEDLIST_H
#include "Node.h"
#include <ostream>
#include <iostream>

template <class T>
class List
{
private:
    int count;
    Node<T> *start;
    Node<T> *end;

public:
    List();
    List(int count, Node<T> *start, Node<T> *end);
    List(List &list);

    ~List();

    Node<T> *getStart();
    Node<T> *getEnd();

    void setStart(Node<T> *node);
    void setEnd(Node<T> *node);

    void add(T data, int key);
    void deleteData(int atIndex);
    int getCount();
    void setCount(int num);
    bool isEmpty();
    void destroy();
    void print(std::ofstream& outstream);
    bool remove(int key);
};

template<typename T>
bool List<T>::remove(int key) {
    Node<T> *current = this->start;
    Node<T> *tmp2;
    for (int i = 0; i < this->count; i++)
    {
        if(current->key == key){
            if(current->next == NULL){
                current = NULL;
                return true;
            }
            //current->data = current->next->data;
            //current->key = current->next->key;
            //current->next = current->next->next;
            tmp2 = current;
            tmp2->next = current->next;
            free(current);
            setCount(-1);
            //free(current);
            std::cout<<current->key<<" has been Deleted."<<std::endl;
            return true;
        }
        current = current->next;
    }
    return false;
}



template <class T>
Node<T> *List<T>::getStart()
{
    return this->start;
}

template <class T>
Node<T> *List<T>::getEnd()
{
    return this->end;
}

template <class T>
void List<T>::setStart(Node<T> *node)
{
    this->start = node;
}

template <class T>
void List<T>::setEnd(Node<T> *node)
{
    this->end = node;
}

template <class T>
List<T>::List()
{
    this->count = 0;
    this->start = nullptr;
    this->end = nullptr;
}

template <class T>
List<T>::List(int count, Node<T> *start, Node<T> *end)
{
    this->count = count;
    this->start = start;
    this->end = end;
}

template <class T>
List<T>::List(List &list)
{
    this->count = list.count;
    this->start = list.start;
    this->end = list.end;
}

template <class T>
List<T>::~List()
{
    for (int i = 0; i < this->count; i++)
    {
        Node<T> *tmp = this->start;
        this->start = this->start->next;
        delete tmp;
    }
}

template <class T>
void List<T>::add(T data, int key)
{
    Node<T> *newNode = new Node<T>(data, 0, key);
    if (this->isEmpty())
    {
        this->start = newNode;
        this->end = newNode;
        this->count++;
    }
    else
    {
        this->end->next = newNode;
        this->end = newNode;
        this->count++;
    }
}

template <class T>
void List<T>::deleteData(int atIndex)
{
    Node<T> *prev = 0;
    Node<T> *current = this->start;

    if (atIndex > this->count)
        return;

    for (int i = 0; i < this->count; i++)
    {
        if (i == 0)
        {
            this->start = current->next;
            delete current;
            this->count = this->count - 1;
            return;
        }
        else if (i == this->count - 1)
        {
            this->end = prev;
            this->end->next = 0;
            delete current;
            this->count = this->count - 1;
            return;
        }
        else if (i == atIndex)
        {
            prev->next = current->next;
            delete current;
            this->count = this->count - 1;
            return;
        }
        prev = current;
        current = current->next;
    }
}

template <class T>
int List<T>::getCount()
{
    return this->count;
}

template <class T>
void List<T>::setCount(int num)
{
    this->count += num;
}

template <class T>
bool List<T>::isEmpty()
{
    return (this->count == 0);
}

template <class T>
void List<T>::destroy()
{
    for (int i = 0; i < this->count; i++)
    {
        Node<T> *tmp = this->start;
        this->start = this->start->next;
        delete tmp;
    }
}

template <class T>
void List<T>::print(std::ofstream& outstream)
{
    Node<T> *current = this->start;
    for (int i = 0; i < this->count; i++)
    {
        std::cout << current->data << " ";
        outstream<< current->data << " ";
        current = current->next;
    }
}
#endif //WEATHER_LINKEDLIST_H
