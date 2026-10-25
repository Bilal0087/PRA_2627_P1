#include <iostream>
#include <stdexcept>
#include "List.h"

using namespace std;
template <typename T>
class ListArray : public List<T>{
	private :
T* arr;   				// Puntero al inicio del array
int max; 		 		// Tamaño actual del array 
int n;	  				// Número de elementos que contiene la lista
static const int MINSIZE=2;		 //Tamaño mínimo del array. Deberá inicializarse a 2.	

void resize(int new_size){
T* arrnuevo= new T[new_size];

for(int i=0; i < n; i++)
arrnuevo[i] = arr[i];

delete[] arr;
arr=arrnuevo;
max = new_size;

}

	public:
ListArray(){
arr = new T[MINSIZE];
max = MINSIZE;
n = 0;					 //todavía no hemos insertado ningún elemento 

}

T operator[](int pos){
if(pos > n-1 || pos < 0)
throw out_of_range("estás fuera del rango");

return arr[pos];

}

friend ostream& operator<< (ostream& out, ListArray<T>& list ){
for (int i=0; i <list.n; i++){
out <<" "<<list.arr[i];
}

return out;
}

void insert(int pos, T e) override{
	if(pos < 0 || pos > n )
		throw out_of_range("fuera del rango");
if(n == max)
resize (max + 1);

for (int i=n-1; i >= pos;i--)
arr[i+1]=arr[i];

arr[pos]= e;
n++;}

void append (T e) override{

if(n == max)
resize (max+1);
	
arr[n] = e;

n++;
}

void prepend(T e) override{
if (n == max)
	resize(max+1);

for(int i=n-1; i >= 0; i--)
arr[i+1]=arr[i];

arr[0]=e;
n++;

}

T remove (int pos) override {
T valor;

if (pos > n-1 || pos < 0)
	throw out_of_range("fuera del rango");

valor = arr[pos];

for (int i=pos; i < n-1; i++)
arr[i]=arr[i+1];

n--;
return valor;
}

T get(int pos) override{
if (pos > n-1 || pos < 0)
	throw out_of_range("fuera del rango");

return arr[pos];

}

int search(T e) override{

for (int i=0; i < n; i++){
if(arr[i] == e)
return i;
}

return -1;
}

bool empty() override {
if(n == 0)
	return true;
else
	return false;
}

int size() override{
return n;

}

~ ListArray() override{
delete[] arr;
}



};





