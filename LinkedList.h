// Assignment #1
// Name: Derek Janzen
// ASU Email Address: djanzen@asu.edu
// Description: Create linked list of courses with the ability to add, remove, and display the nodes.

#include <iostream> //to use cout
#include <iomanip> //to format output
#include <string> //to use strings

using namespace std;

//struct Course represents some course information
struct Course
{
	string number;
	string title;
	struct Course * next;
};

//class LinkedList will contains a linked list of courses
class LinkedList
{
private:
	struct Course * head;
	int size = 0;

public:
	LinkedList();
	~LinkedList();
	bool addElement(string number, string title, int index);
	bool removeElement(string number, string title);
	void printList();
};

//Constructor to initialize the linked list
LinkedList::LinkedList()
{
	head = NULL;

}

//Destructor
//Description: ...... to be completed
LinkedList::~LinkedList()
{
	Course *curr, *temp;
	curr = head;
	temp = head;
	int count=0;
	while (curr != NULL)
	{
		curr = curr->next;
		delete temp;
		temp = curr;
		count++;
	}
	cout << "The number of deleted courses is: " << count << "\n";
}

//Description: Adds a node to the linked list.
bool LinkedList::addElement(string newNumber, string newTitle, int index)
{

	Course *temp = new Course;
	struct Course *temp2;
	temp->number = newNumber;
	temp->title = newTitle;
	temp->next = NULL;
	if (index >= (size + 1) || index < 0)
	{
		return false;
	}
	if (head == NULL)
	{
		head = temp;
		
	}
	else
	{
		temp2 = head;
		if (index == 0)
		{
			temp->next = head;
			head = temp;
			
		}
		else
		{
			for (int i = 1; i < index; i++)
			{
				temp2 = temp2->next;

			}
			temp->next = temp2->next;
			temp2->next = temp;
			
		}
	}
	size++;
	return true;
}

//Description: Removes node from the linked list.
bool LinkedList::removeElement(string someNumber, string someTitle)
{
	struct Course *temp, *temp2;
	temp = head;
	if (head == NULL)
	{
		return false;
	}
	if (head->number.compare(someNumber) == 0 && head->title.compare(someTitle) == 0)
	{
		head = head->next;
		delete temp;
		size--;
		return true;
	}
	else if (head->next == NULL)
	{
		return false;
	}
	temp = head->next;
	temp2 = head;
	while (temp->next != NULL)
	{
		if (temp->number.compare(someNumber) == 0 && temp->title.compare(someTitle) == 0)
		{
			temp2->next = temp->next;
			delete temp;
			size--;
			return true;
		}
		else
		{
			temp2 = temp2->next;
			temp = temp->next;
		}
	}
	if (temp->number.compare(someNumber) == 0 && temp->title.compare(someTitle) == 0)
	{
		temp2->next = NULL;
		delete temp;
		size--;
		return true;
	}
	else
		return false;
	cout << "Whoops";
}

//Description: Prints the linked list for the user to see.
void LinkedList::printList()
{
	struct Course *temp;
	temp = head;
	while (temp != NULL)
	{
		cout << "Course Number: " << temp->number << ", Course Title: " << temp->title << "\n";
		temp = temp->next;
	}

}