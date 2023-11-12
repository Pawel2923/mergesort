#pragma once
#ifndef LISTA_H
#define LISTA_H

struct listElement
{
    listElement* prev;
    listElement* next;
    int key;
};

class List
{
private:
    listElement* first, * last;
    unsigned counter;

public:
    List() : first(nullptr), last(nullptr), counter(0) {}
    ~List();
    unsigned unshift(int newKey);
    unsigned push(int newKey);
    unsigned insert(int newKey, unsigned position);
    int shift();
    int pop();
    int remove(unsigned position);
    void print();
    void printReverse();
    void nextElement(unsigned position);
    void prevElement(unsigned position);
    void clear();
};

#endif // !LISTA_H