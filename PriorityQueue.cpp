#include<iostream>
using namespace std;
class Person
{
private:
	int age;
	int items;		
public:
	Person()
	{
		age = 0;
		items = 0;
	}
	void setPerson(int age,int items)
	{
		this->age = age;
		this->items = items;
	}
	void Input()
	{
		cout << "Please enter how many items do you want to purchase =";
		cin >> items;
		cout << "Please enter your age =";
		cin >> age;
	}
	int getItems()
	{
		return this->items;
	}
	int getAge()
	{
		return this->age;
	}
	void setAge(int age)
	{
		this->age = age;
	}
	void setItems(int items)
	{
		this->items = items;
	}
	void Display()
	{
		cout << "(" << items << "," << age << ")" << endl;
	}
};
class Node
{
private:
	Person obj;
	Node* Next;
public:
	Node()
	{
		Next = NULL;
	}
	void setPerson(int age, int items)
	{
		obj.setPerson(age, items);
	}
	void SetNext(Node*Next)
	{
		this->Next = Next;
	}
	Node* getNext()
	{
		return this->Next;
	}
	int getAge()
	{
		return this->obj.getAge();
	}
	int getItems()
	{
		return this->obj.getItems();
	}
	void setAge(int age)
	{
		obj.setAge(age);
	}
	void setItems(int items)
	{
		obj.setItems(items);
	}
	void Input()
	{
		obj.Input();
	}
	void Display()
	{
		obj.Display();
	}
	~Node()
	{
		if (Next != NULL)
		{
			Next = NULL;
		}
	}
};
class Queue {
private:
	Node* Front;
	Node* Rear;
	int size;
	int QueueLength;
public:
	Queue()
	{
		Front = NULL;
		Rear = NULL;
		size = 0;
		QueueLength = 0;
	}
	void enqueue(int Age,int item)
	{
		Node* NewNode = new Node();
		NewNode->setAge(Age);
		NewNode->setItems(item);
		QueueLength = QueueLength + item;
		if (Front == NULL)
		{
			NewNode->SetNext(NULL);
			Front = NewNode;
			Rear = NewNode;
		}
		else 
		{
			if (Front->getAge() <= NewNode->getAge())
			{
				NewNode->SetNext(Front);
				Front = NewNode;
				moveRear();
			}
			else
			{
				Node* current = Front;
				while (current->getNext() != NULL && (current->getNext())->getAge() > NewNode->getAge())
				{
					current = current->getNext();
				}
				NewNode->SetNext(current->getNext());
				current->SetNext(NewNode);
				moveRear();
			}
		}
		size++;
	}
	void moveRear()
	{
		while (Rear != NULL)
		{
			Rear = Rear->getNext();
		}
	}
	Person dequeue()
	{
		if (size != 0&&Front!=Rear)
		{
			Node* temp = Front;
			int  Age = temp->getAge();
			int Item = temp->getItems();
			Person obj;
			obj.setPerson(Age, Item);
			Front = temp->getNext();
			QueueLength = QueueLength - Item;
			size--;
			delete temp;
			return obj;
		}
		else {
			int  Age = 0;
			int Item = 0;
			Person obj;
			obj.setPerson(Age, Item);
			return obj;
		}
	}
	int getsize()
	{
		return size;
	}
	int getQueueLength()
	{
		return QueueLength;
	}
	Person getFront()
	{
		int  Age = Front->getAge();
		int Item = Front->getItems();
		Person obj;
		obj.setPerson(Age, Item);
		return obj;
	}
	bool isEmpty()
	{
		if (Front==NULL)
		{
			return true;
		}
		else {
			return false;
		}
	}
	void Display()
	{
		Node* Temp = Front;
		while (Temp!=NULL)
		{
			Temp->Display();
			Temp = Temp->getNext();
		}
	}

};
int getCounter(int size1, int size2, int size3, int size4)
{
	
		int res = min(min(min(size1, size2), size3), size4);
		return res;
}
void Display(Queue counter1, Queue counter2, Queue counter3, Queue counter4)
{
	cout << "Counter#1" << endl;
	counter1.Display();
	cout <<  endl;
	cout << "Counter#2" << endl;
	counter2.Display();
	cout << endl;
	cout << "Counter#3" << endl;
	counter3.Display();
	cout << endl;
	cout << "Counter#4" << endl;
	counter4.Display();
	cout << endl;
}
void main()
{
	Queue counter1;
	Queue counter2;
	Queue counter3;
	Queue counter4;
	char choice = 0;
	while (choice != 'N' && choice != 'n')
	{
		cout << "Do you want to pay bills(Y/N):";
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			int items, age;
			cout << "Please enter how many items do you want to purchase=";
			cin >> items;
			cout << "Please enter your age=";
			cin >> age;
			int size = getCounter(counter1.getQueueLength(), counter2.getQueueLength(), counter3.getQueueLength(), counter4.getQueueLength());
			if (size == counter1.getQueueLength())
			{
				counter1.enqueue(age,items);

			}
			else if (size == counter2.getQueueLength())
			{
				counter2.enqueue(age, items);
			}
			else if (size == counter3.getQueueLength())
			{
				counter3.enqueue(age, items);
			}
			else if (size == counter4.getQueueLength())
			{
				counter4.enqueue(age, items);
			}
			
		}
	}
	cout << "Queues are Following:" << endl;
	Display(counter1, counter2, counter3, counter4);
	cout << "Press 1 to Dequeue Counter#1:" << endl;
	cout << "Press 2 to Dequeue Counter#2:" << endl;
	cout << "Press 3 to Dequeue Counter#3:" << endl;
	cout << "Press 4 to Dequeue Counter#4:" << endl;
	cout << "Enter -1 to exit from Program:" << endl;
	int choice1 = 0;
	cout << "Enter the choice:";
	cin >> choice1;

	if (choice1 == 1)
	{
		cout << "Dequeue Counter#1" << endl;
		Person Front1;
		Front1 = counter1.getFront();
		if (Front1.getAge() == 0 && Front1.getItems() == 0)
		{
			cout << "Counter#1 is Empty" << endl;
		}
		else
		{
			while (Front1.getAge() != 0 && Front1.getItems() != 0)
			{
				Front1 = counter1.dequeue();
				if (Front1.getAge() == 0 && Front1.getItems() == 0)
				{
					cout << "Counter#1 is Empty" << endl;
					break;
				}
				else {
					Front1.Display();
				}
			}
		}
	}
	if (choice1 == 2)
	{
		cout << "Dequeue Counter#2" << endl;
		Person Front2;
		Front2 = counter2.getFront();
		if (Front2.getAge() == 0 && Front2.getItems() == 0)
		{
			cout << "Counter#2 is Empty" << endl;
		}
		else
		{
			while (Front2.getAge() != 0 && Front2.getItems() != 0)
			{
				Front2 = counter2.dequeue();
				if (Front2.getAge() == 0 && Front2.getItems() == 0)
				{
					cout << "Counter#2 is Empty" << endl;
					break;
				}
				else {
					Front2.Display();
				}
			}
		}
	}
	if (choice1 == 3)
	{
		cout << "Dequeue Counter#3" << endl;
		Person Front3;
		Front3 = counter3.getFront();
		if (Front3.getAge() == 0 && Front3.getItems() == 0)
		{
			cout << "Counter#3 is Empty" << endl;
		}
		else
		{
			while (Front3.getAge() != 0 && Front3.getItems() != 0)
			{
				Front3 = counter3.dequeue();
				if (Front3.getAge() == 0 && Front3.getItems() == 0)
				{
					cout << "Counter#3 is Empty" << endl;
					break;
				}
				else {
					Front3.Display();
				}
			}
		}
	}
	if (choice1 == 4)
	{
		
		cout << "Dequeue Counter#4" << endl;
		Person Front4;
		Front4 = counter4.getFront();
		if (Front4.getAge() == 0 && Front4.getItems() == 0)
		{
			cout << "Counter#4 is Empty" << endl;
		}
		else
		{
			while (Front4.getAge() != 0 && Front4.getItems() != 0)
			{
				Front4 = counter4.dequeue();
				if (Front4.getAge() == 0 && Front4.getItems() == 0)
				{
					cout << "Counter#4 is Empty" << endl;
					break;
				}
				else {
					Front4.Display();
				}
			}
		}

	}
	 if (choice1 == -1)
	{
		exit(0);
	}
	
	
}

