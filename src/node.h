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
		next = 0;
	}
	Node ( T t, Node *p = 0 ) {
		value = t;
		next = p;
	}

	T get() {
		return value;
	}
	~Node() {
	}
};


#endif /* NODE_H_ */
