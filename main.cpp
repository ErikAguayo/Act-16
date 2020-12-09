#include <iostream>
#include "listadobleligada.h"
using namespace std;

int main() {
	
ListaDobleLigada<int> enteros;

enteros.push_front(1);
enteros.push_front(2);
enteros.push_front(3);

enteros<<4<<5<<6;

cout<< "Cantidad:"<< enteros.size()<<endl;

enteros.buscar(3);


//enteros.print();





return 0;


	
}
