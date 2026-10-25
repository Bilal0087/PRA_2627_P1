#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Node{
	public:
T data;
Node<T>* next;


Node (T data){
this-> data= data;
next = nullptr;
}

Node (T data, Node<T>* next){
this-> data= data;
this->next = next;
}

friend ostream& operator<<(ostream& out, Node<T>& node){
out << node.data;
return out;
}



};




































#endif
