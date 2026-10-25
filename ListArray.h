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


~ ListArray() override{
delete[] arr;
}

};





