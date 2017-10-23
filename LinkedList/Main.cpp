#include <iostream>
#include <stdlib.h>
#include "Node.h"
using namespace std;

Node <int>* head = NULL;

void main()
{
	void addNodeFrontList();
	void addNodeBackList();
	void addNodeBeforePosition();
	void addNodeAfterPosition();
	void printForward();
	void printBackwards();
	

	int optionMenu = 0;
	do
	{
		cout << "****************************MENU*************************************" << endl;
		cout << "1 - Add a node to the front of the list." << endl;
		cout << "2 - Add a node to the back of the list." << endl;
		cout << "3 - Add a node to the middle of the list after a specific node." << endl;
		cout << "4 - Add a node to the middle of the list before a specific node." << endl;
		cout << "5 - Delete a node from the front of the list." << endl;
		cout << "6 - Delete a node from the back of the list." << endl;
		cout << "7 - Delete a node from the middle of the list after a specific node." << endl;
		cout << "8 - Delete a node from the middle of the list before a specific node." << endl;
		cout << "9 - Print a list forward." << endl;
		cout << "10- Print a list backward." << endl;
		cout << "11- Purge the list." << endl;
		cout << "12- Exit." << endl;
		cin >> optionMenu;


		switch (optionMenu)
		{
		case 1:
			addNodeFrontList();
			break;
		case 2:
			addNodeBackList();
			break;
		case 3:
			addNodeBeforePosition();
			break;
		case 4:
			addNodeAfterPosition();
			break;
		case 9:
			printForward();
			break;
		case 10:
			printBackwards();
			break;
		case 11:
			head = NULL;
			cout << "List purged!" << endl;
			system("pause");
			system("cls");
			break;
		}
		

	} while (optionMenu != 12);



}

void addNodeFrontList()
{
	Node <int>* Node<int>::createNode(int, Node <int>*, Node <int>*);

	Node <int>* newNode;
	int data;
	system("cls");
	cout << "****** ADD NODE ******" << endl;
	cout << "Please insert a integer for the node:\n" << endl;
	cin >> data;

	if (head == NULL)
	{
		head = Node<int>::createNode(data, NULL, NULL);
	}
	else
	{
		newNode = Node<int>::createNode(data, head, NULL);
		head->previous = newNode;
		head = newNode;
	}
	cout << "Node created successfully!" << endl;
	system("pause");
	system("cls");
}

void addNodeBackList()
{
	Node <int>* Node<int>::createNode(int, Node <int>*, Node <int>*);
	Node <int>* newNode;
	Node <int>* cursor;
	int data;

	system("cls");
	cout << "****** ADD NODE ******" << endl;
	cout << "Please insert a integer for the node:" << endl;
	cin >> data;

	if (head == NULL)
	{
		head = Node<int>::createNode(data, NULL, NULL);
	}
	else
	{
		cursor = head;
		while (cursor->next != NULL)
		{
			cursor = cursor->next;
		}
		newNode = Node<int>::createNode(data, NULL, cursor);
		cursor->next = newNode;
	}
	system("pause");
	system("cls");
}

void addNodeBeforePosition() {

	Node <int>* Node<int>::createNode(int, Node <int>*, Node <int>*);
	Node <int>* newNode;
	Node <int>* cursor;
	int data;
	int position = 0;
	int currentPosition = 0;

	system("cls");
	cout << "****** ADD NODE ******" << endl;
	cout << "Please insert a integer for the node: " << endl;
	cin >> data;
	cout << "Before each position?" << endl;
	cin >>position;

	cursor = head;
	while (currentPosition < position - 1)
	{
		if (cursor->next == NULL)
		{
			cout << "Sorry, there is no node on position " << position;
			system("pause");
			exit(0);
		}
		cursor = cursor->next;
		currentPosition++;
	}

	newNode = Node<int>::createNode(data, cursor, cursor->previous);
	cursor->previous->next = newNode;
	cursor->previous = newNode;

	system("pause");
	system("cls");
}

void addNodeAfterPosition() {

	Node <int>* Node<int>::createNode(int, Node <int>*, Node <int>*);
	Node <int>* newNode;
	Node <int>* cursor;
	int data;
	int position = 0;
	int currentPosition = 0;

	system("cls");
	cout << "****** ADD NODE ******" << endl;
	cout << "Please insert a integer for the node: " << endl;
	cin >> data;
	cout << "Before each position?" << endl;
	cin >> position;

	cursor = head;
	while (currentPosition < position - 1)
	{
		if (cursor->next == NULL)
		{
			cout << "Sorry, there is no node on position " <<  position;
			system("pause");
			exit(0);
		}
		cursor = cursor->next;
		currentPosition++;
	}

	newNode = Node<int>::createNode(data, cursor->next, cursor);
	cursor->next = newNode;
	cursor->next->previous = newNode;

	system("pause");
	system("cls");
}


Node <int>* getLasttNode()
{
	Node <int>* cursor = head;
	while (cursor->next != NULL) cursor = cursor->next;
	return cursor;
}

void printForward()
{
	system("cls");
	Node <int>* cursor = head;
	while (cursor != NULL) {
		cout << "Node data: " << cursor->data << endl;
		cursor = cursor->next;
	}
	system("pause");
	system("cls");
}

void printBackwards()
{
	system("cls");
	Node <int>* cursor = head;
	while (cursor->next != NULL) {
		cursor = cursor->next;
	}

	do
	{
		cout << "Node data: " << cursor->data << endl;
		cursor = cursor->previous;
	} while (cursor != NULL);
	system("pause");
	system("cls");

}
