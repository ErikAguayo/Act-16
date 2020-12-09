#ifndef LISTA_DOBLE_LIGADA_H
#define LISTA_DOBLE_LIGADA_H
#include <iostream>
using namespace std;

template <class T>
class ListaDobleLigada
{
	public:
		ListaDobleLigada();
		~ListaDobleLigada();
	
		bool empty();
		
		void push_front(const T &dato);
		void push_back(const T &dato);
		T* buscar(const T &dato);	
		void print();
		void print_reverse();
		T* front();
		T* back();
		
		void pop_front();
		void pop_back();
		void erase(size_t p);
		
		void insert(const T &dato, size_t p);
		
		size_t size();
		
		ListaDobleLigada &operator<<(const T &dato){
			
			push_back(dato);
			
			return *this;
		}
		
		T* operator[](size_t p)
		{
			size_t pos=0;
			Nodo *temp =head;
			
			while(temp != NULL)
			{
				if(p==pos)
				{
					return &temp->dato;
				}
				temp= temp->sig;
				pos++;
			}
			return NULL;
		}
		
	private:
		struct Nodo{
			T dato;
			Nodo *sig;
			Nodo *ant;
			
			Nodo(const T &dato, Nodo *sig=NULL, Nodo *ant=NULL)
			:dato(dato), sig(sig), ant(ant){}
		};
		
		Nodo *head;
		Nodo *tail;
		size_t cont;	
		
		
};

	template <class T>
	ListaDobleLigada<T>::ListaDobleLigada()
	{
		head=NULL;
		tail=NULL;
		cont=0;
		
	}
	
	template <class T>
	ListaDobleLigada<T>::~ListaDobleLigada()
	{
		while(!empty())
		{
			pop_front();
		}
	}
	
	template <class T>
	bool ListaDobleLigada<T>::empty()
	{
		return cont == 0;
	}
	
	template <class T>
	void ListaDobleLigada<T>::push_front(const T &dato)
	{
		Nodo *nodo = new Nodo(dato, head);
		if(cont == 0)
		{
			head = nodo;
			tail = nodo;
		}
		else{
			head->ant = nodo;
			head=nodo;
		}
		cont++;
	}
	
	template <class T>
	void ListaDobleLigada<T>::push_back(const T &dato)
	{
		Nodo *nodo = new Nodo(dato, NULL, tail);
		if(cont == 0)
		{
			head = nodo;
			tail = nodo;
		}
		else{
			tail->ant = nodo;
			tail=nodo;
		}
		cont++;
	}
	
	template <class T>
	size_t ListaDobleLigada<T>::size()
	{
		return cont;
	}
	
	template <class T>
	void ListaDobleLigada<T>::print()
	{
		Nodo *temp = head;
		
		while(temp != NULL)
		{
			cout << temp->dato << endl;
			temp = temp->sig;
			
		}
	}
	
	template <class T>
	void ListaDobleLigada<T>::print_reverse()
	{
		Nodo *temp=tail;
		
		while(temp!=NULL)
		{
			cout<<temp->dato<<endl;
			temp=temp->ant;
		}
	}
		template <class T>
	T* ListaDobleLigada<T>::front()
	{
	    if (empty()) {
	        return NULL;
	    } else {
	        return &head->dato;
	    }
	}
		
		
	
	template <class T>
	T* ListaDobleLigada<T>::back()
	{
		if(empty())	
		{
			return NULL;
			}
		else{
			return &tail->dato;
		}	
	}
	
	template <class T>
	void ListaDobleLigada<T>::pop_front()
	{
		if(empty())
		{
			cout<< " Lista vacia " << endl;
		}
		else if(cont == 1)
		{
			delete head;
			head=NULL;
			tail=NULL;
			cont--;
		}
		else{
			Nodo *temp = head->sig;
			
			head->sig->ant=NULL;
			delete head;
			head = temp;
			cont--;
		}
	}

	template <class T>
	void ListaDobleLigada<T>::pop_back()
	{
		if(empty())
		{
			cout<< " Lista vacia " << endl;
		}
		else if(cont == 1)
		{
			delete tail;
			head=NULL;
			tail=NULL;
			cont--;
		}
		else{
			Nodo *temp = tail->ant;
			
			temp->sig=NULL;
			delete tail;
			tail = temp;
			cont--;
		}
	}	
	
	template <class T>
	void ListaDobleLigada<T>::insert(const T &dato, size_t p)
	{
		if(p>=cont)
		{
			cout<< " Posicion no valida " << endl;
		}
		else if(p == 0)
		{
		 	push_front(dato);
		}
		else{
			Nodo *temp = head->sig;
			
		size_t pos=1;
		
		while(temp!=NULL)
		{
			if(p==pos)
			{
				Nodo *nodo= new Nodo(dato);
				nodo->sig =temp;
				nodo->ant =temp->ant;
				
				temp->ant->sig=nodo;
				nodo->sig->ant=nodo;
				
				cont++;
				break;
				
			}
			temp= temp->sig;
			pos++;
			}
		}
	}	
	
	template <class T>
	void ListaDobleLigada<T>::erase(size_t p)
	{
		if(p>=cont)
		{
			cout<< " Posicion no valida " << endl;
		}
		else if(p == 0)
		{
		 	pop_front();
		}
		else if(p == cont-1){
			
			pop_back();
	    }
	    else{
	    	Nodo *temp = head->sig;
	    	size_t pos=1;
		
		while(temp!=NULL)
		{
			if(p==pos)
			{
				
				temp->ant->sig=temp->sig;
				temp->sig->ant=temp->ant;
				
				delete temp;
				
				cont++;
				break;
				
			}
			temp= temp->sig;
			pos++;
			}
		}
	}	
	
	template <class T>
	T* ListaDobleLigada<T>::buscar(const T &dato)
    {    
    
	Nodo *temp = head;
	
	while(temp!=NULL){
	
	if(dato == temp->dato)
	{
		cout<< &temp->dato;
		temp=temp->sig;
	}
	else
	{
		return NULL;
	}
		
	}
}




#endif
