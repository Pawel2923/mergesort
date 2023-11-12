#include <iostream>
#include "list.h";

using namespace std;

List::~List() {
    while (first) {
        listElement* element = first->next;
        delete first;
        first = element;
    }
    last = nullptr;
    counter = 0;
}

unsigned List::unshift(int newKey) {
    listElement* element = new listElement;
    element->key = newKey;

    element->next = first;
    element->prev = nullptr;

    if (first) {
        first->prev = element;
    }
    first = element;
    if (!last) {
        last = first;
    }
    return ++counter;
}

unsigned List::push(int newKey) {
    listElement* element = new listElement;
    element->key = newKey;

    element->next = nullptr;
    element->prev = last;

    if (last) {
        last->next = element;
    }
    last = element;
    if (!first) {
        first = last;
    }
    return ++counter;
}

unsigned List::insert(int newKey, unsigned position) {
    if (position == 0) {
        return unshift(newKey);
    }
    if (position >= counter) {
        return push(newKey);
    }

    listElement* element = new listElement;
    element->key = newKey;

    listElement* current = first;
    for (size_t i = 0; i < position - 1; i++)
    {
        current = current->next;
    }

    element->next = current->next;
    element->prev = current;

    current->next->prev = element;
    current->next = element;

    return ++counter;
}

int List::shift() {
    if (!first) {
        cout << "\nLista jest pusta\n";
        return 0;
    }

    listElement* element = first;
    int key = element->key;

    first = first->next;
    if (first) {
        first->prev = nullptr;
    }
    else {
        last = nullptr;
    }

    delete element;
    counter--;
    return key;
}

int List::pop() {
    if (!last) {
        cout << "\nLista jest pusta\n";
        return 0;
    }

    listElement* element = last;
    int key = element->key;

    last = last->prev;
    if (last) {
        last->next = nullptr;
    }
    else {
        last = nullptr;
    }

    delete element;
    counter--;
    return key;
}

int List::remove(unsigned position) {
    if (position == 0) {
        return shift();
    }

    if (position >= counter - 1) {
        return pop();
    }

    listElement* current = first;
    for (size_t i = 0; i < position; i++)
    {
        current = current->next;
    }
    int key = current->key;

    current->prev->next = current->next;
    current->next->prev = current->prev;

    delete current;
    counter--;
    return key;
}

void List::print() {
    if (!first) {
        cout << "\nLista jest pusta\n";
        return;
    }

    listElement* element = first;

    cout << "-------Wszystkie elementy listy-------\n";
    while (element)
    {
        cout << element->key << " ";
        element = element->next;
    }
    cout << "\n--------------------------------------\n";
}

void List::printReverse() {
    if (!last) {
        cout << "\nLista jest pusta\n";
        return;
    }

    listElement* element = last;

    cout << "-----Wszystkie elementy od konca------\n";
    while (element)
    {
        cout << element->key << " ";
        element = element->prev;
    }
    cout << "\n--------------------------------------\n";
}

void List::nextElement(unsigned position) {
    if (position >= counter) {
        cout << "\nNie ma takiego elementu\n";
        return;
    }

    listElement* current = first;
    for (size_t i = 0; i < position; i++)
    {
        current = current->next;
    }

    cout << "\nNastepny element po " << current->key << " : " << current->next->key << "\n";
}

void List::prevElement(unsigned position) {
    if (position >= counter) {
        cout << "\nNie ma takiego elementu\n";
        return;
    }

    listElement* current = first;
    for (size_t i = 0; i < position; i++)
    {
        current = current->next;
    }

    cout << "\Poprzedni element przed " << current->key << " : " << current->prev->key << "\n";
}

void List::clear() {
    while (first) {
        listElement* element = first->next;
        delete first;
        first = element;
    }
    last = nullptr;
    counter = 0;
}