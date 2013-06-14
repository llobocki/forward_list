/*
 * list.h
 *
 *  Created on: 13-06-2013
 *      Author: lukasz
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include "node.h"

template <class T> class List {
private:
	int size;
	Node<T> *root;
public:
	List();
	List ( T t );
	~List();

	void add_head ( T t );
	void remove_head();

	void remove ( T t );

	void print();

	bool is_empty();

};

template <class T> List<T>::List()
{
	size = 0;
	root = nullptr;
}

template <class T> List<T>::List ( T t )
{
	if ( size == 0 ) {
		root = new Node<T> ( t, root );
		size++;
	} else {
		root = new Node<T> ( t );
		size = 1;
	}
}

template <class T> void List<T>::add_head ( T t )
{
	root = new Node<T> ( t, root );
	size++;
}

template <class T> void List<T>::remove_head ()
{
	Node<T> *tmp = root;
	root = root->next;
	delete tmp;
	tmp = nullptr;
	size--;
};

template <class T> void List<T>::print()
{
	int i = size;
	Node<T> *n = root;
	while ( i > 0 ) {
		std::cout << n->value << '\n';
		n = n->next;
		i--;
	}
};

template <class T> void List<T>::remove ( T t )
{
	if ( size > 0 ) {
		if ( size ==1 && t == root->value ) {
			delete root;
			root = nullptr;
		}
		else if(t == root->value){
			Node<T> *tmp = root;
			root = root->next;
			delete tmp;
			tmp = nullptr;
			size--;
		}
		else {
			Node<T> *prev;
			Node<T> *tmp;
			for ( prev = root, tmp = root->next; tmp != 0 && ! ( tmp->value ==t ); prev = prev->next, tmp = tmp ->next );
			if ( tmp != 0 ) {
				prev->next = tmp-> next;
				delete tmp;
				tmp = nullptr;
				size--;
			}
		}
	}
}

template<class T> List<T>::~List() {
	Node<T> *tmp;
	int i = size;
	while((i--) > 0){
		tmp = root->next;
		delete root;
		root = tmp;
	}
}

template<class T> bool List<T>::is_empty() {
	return size == 0;
}


#endif /* LIST_H_ */
