/*
 * node.h
 *
 *  Created on: 13-06-2013
 *      Author: lukasz
 */

#ifndef NODE_H_
#define NODE_H_

template <class T> struct Node {
	T value;
	class Node<T> *next;
	Node() {
		next = nullptr;
	}
	Node ( T t, Node *p = nullptr ) {
		value = t;
		next = p;
	}

	Node (const Node<T> *n){
		value = n->value;
		next = n->next;
	}

	~Node() {
	}

};


#endif /* NODE_H_ */
