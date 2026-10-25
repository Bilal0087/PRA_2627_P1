#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <iostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

using namespace std;

template <typename T>
class ListLinked : public List<T> {

    private:
 
       Node<T>* first;
       int n;

    public:

 ListLinked(){
	first=nullptr;
	n=0;
	}

	~ListLinked() override{
		Node<T>* aux = first;
		Node<T>* siguiente = nullptr;

	while(aux != nullptr){
		siguiente = aux->next;
	delete aux;
	aux = siguiente;	
		}
	}

T operator[](int pos) {
    if (pos < 0 || pos >= n)
        throw out_of_range("fuera del rango");

    Node<T>* aux = first;

    for (int i = 0; i < pos; i++)
        aux = aux->next;

    return aux->data;
}

friend ostream& operator<<(ostream& out, ListLinked<T>& list) {
    Node<T>* aux = list.first;

    while (aux != nullptr) {
        out << " " << aux->data;
        aux = aux->next;
    }

    return out;
}

void append(T e) override {
    Node<T>* nuevo = new Node<T>(e, nullptr);

    if (first == nullptr) {
        first = nuevo;
    } else {
        Node<T>* aux = first;

        while (aux->next != nullptr)
            aux = aux->next;

        aux->next = nuevo;
    }

    n++;
}

void prepend(T e) override {
    Node<T>* nuevo = new Node<T>(e, first);
    first = nuevo;
    n++;
}

T remove(int pos) override {
    if (pos < 0 || pos >= n)
        throw out_of_range("fuera del rango");

    Node<T>* aux = first;

    if (pos == 0) {
        first = first->next;
    } else {
        Node<T>* anterior = nullptr;

        for (int i = 0; i < pos; i++) {
            anterior = aux;
            aux = aux->next;
        }

        anterior->next = aux->next;
    }

    T valor = aux->data;
    delete aux;
    n--;

    return valor;
}

T get(int pos) override {
    if (pos < 0 || pos > n)
        throw out_of_range("fuera del rango");

    Node<T>* aux = first;

    for (int i = 0; i < pos; i++)
        aux = aux->next;

    return aux->data;
}

bool empty() override {
    return n == 0;
}

int size() override {
    return n;
}

void insert(int pos,T e) override{
if(pos < 0 || pos > n)
	throw out_of_range("fuera del rango");

if(pos == 0)
first=new Node <T>(e,first);
else{

Node<T>* aux = first;
Node<T>* anterior=nullptr;

for(int i=0; i<pos; i++){
	anterior=aux;
	aux=aux->next;
}
anterior->next = new Node<T>(e,aux); 

}

n++;
}

int search (T e) override{
	if(first == nullptr)
		return -1;
int i=0;
Node<T>* aux = first;
while(aux != nullptr){
	
if(aux->data == e)
	return i;
aux =aux -> next;
i++;
}

return -1;
}









};

#endif LIST_LINKED_H
