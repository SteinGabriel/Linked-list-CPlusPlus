#ifndef NODE_H

#endif 

#define NODE_H

template< class T >
class Node {
public:
	Node();
	T data;                 
	Node< T > * next;
	Node< T >  * previous;
	static Node <T> * createNode(T data, Node <T>* next, Node <T>* prev);

};

template< class T >
Node< T >::Node()
{

}

template<class T>
inline Node<T>* Node<T>::createNode(T data, Node<T>* next, Node<T>* prev)
{
	Node<T>* newNode = (Node<T>*)malloc(sizeof(Node <T>));

	if (newNode == NULL)
	{
		cout << "Error creating a new node";
		exit(0);
	}

	newNode->data = data;
	newNode->next = next;
	newNode->previous = prev;
	return newNode;
}

