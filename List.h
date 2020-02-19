//
// Created by lurk1 on 19.02.2020.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H


#include <iostream>

using namespace std;

template <class T>
class List
{
private:
    struct List_s
    {
        List_s *next;
        T element;
    };
    void d(List_s *l);
public:
    int size;
    List_s *l;
    List();
    ~List();
    bool isEmpty();
    void Add(T element);
    void AddAt(int pos, T element);
    void Delete(T element);
    void newList();
    void Print();
    T operator[](int pos);
};

template <class T>
List<T>::List()
{
    this->size = 0;

    this->l = new List_s;

    this->l->next = NULL;
}

template <class T>
void List<T>::d(List_s *l)
{
    if (l->next != NULL)
    {
        d(l->next);
    }
    free(l);
}

template <class T>
List<T>::~List()
{
    d(l);
    l = NULL;
    this->size = 0;
}

template <class T>
bool List<T>::isEmpty()
{
    return(this->size == 0);
}


template <class T>
void List<T>::Add(T element)
{
    List_s *next =this->l;
    while (next->next != NULL)
    {
        next = next->next;
    }
    next->next= new List_s;
    next->next->element = element;
    next->next->next = NULL;
    this->size++;
}

template <class T>
void List<T>::AddAt(int pos, T element)
{
    List_s *next = this->l;
    for (int i = 0; next->next != NULL && i < pos; i++, next = next->next);
    if (next->next == NULL)
    {
        return;
    }
    List_s *tmp = next->next;
    next->next = new List_s;
    next->next->element = element;
    next->next->next = tmp;
    this->size++;
}

template <class T>
void List<T>::Delete(T element)
{
    List_s *next = this->l;
    while (next->next != NULL && next->next->element != element )
    {
        next = next->next;
    }
    if (next->next == NULL)
    {
        return;
    }
    List_s *d = next->next;
    next->next = next->next->next;
    delete d;
    this->size--;
}

template <class T>
void List<T>::newList()
{
    this->l = new List_s;

    this->l->next = NULL;
}

template <class T>
void List<T>::Print()
{
    List_s *cur = this->l->next;
    while(cur != NULL)
    {
        cout << cur->element << (cur->next!=NULL ? " -> ":"");
        cur = cur->next;
    }
    cout << "\n";
}

template <class T>
T List<T>::operator[](int pos)
{
    List_s *cur = this->l->next;
    if (cur == NULL)
    {
        return NULL;
    }
    for (int i = 0; cur != NULL && i != pos; i++, cur = cur->next);
    if (cur == NULL)
    {
        return NULL;
    }
    return cur->element;
}




#endif //LIST_LIST_H
