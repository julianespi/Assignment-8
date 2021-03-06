#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <queue>
#include <random>
#include <Windows.h>
#include<ctime>
#include "input.h"
using namespace std;

class checkoutQueue
{
private:
	queue<int> customers;
	int size;
public:
	
	checkoutQueue();
	void addCustomer();
	void removeCustomer();
	bool empty() const;
	
	bool operator <(const checkoutQueue& RHS);
	friend ostream& operator <<(ostream& outs, const checkoutQueue& obj);
	int getSize() const;

};
checkoutQueue::checkoutQueue() : size(0) {}
//precondition: none
//postcondition: return true if vector is empty
bool checkoutQueue::empty() const
{
	return (size == 0);
}

//precondition: none
//postcondition: adds a new customer to the register
void checkoutQueue::addCustomer()
{
	int customer = rand() % 100 + 1;
	customers.push(customer);
	size++;
}

//precondition: none
//postcondition: removes a customer finished at the register
void checkoutQueue::removeCustomer()
{

	customers.pop();
	size--;
}

//precondition: none
//postcondition: returns true if vector size is smaller than right hand size
bool checkoutQueue::operator <(const checkoutQueue& RHS)
{
	return(this->size < RHS.size);
}

ostream& operator <<(ostream& outs, const checkoutQueue& obj)
{
	if (obj.empty())
	{
		outs << " " << '\n';
		return outs;
	}
	else if (obj.size == 1)
	{
		outs << "|" << obj.customers.front() << "|\n";
		return outs;
	}
	else
	{
		outs << "|" << obj.customers.front() << "|\t\t";
		for (int i = 1; i < obj.size; i++)
		{
			outs << string(3, 254) << "\t"; 
		}
		outs << '\n';
		return outs;
	}
}

//precondition: none
//postcondition: returns size of vector
int checkoutQueue::getSize() const
{
	return size;
}





bool timer(int endTime);
int newCustomer();

void displayLine(vector<checkoutQueue>& vec, int helped, int endTime);
int returnShortest(vector<checkoutQueue>& vec);

//precondition: none
//postcondition: runs a simulation of Costco checkout based on user parameters
void SimOfCheckout()
{
	vector<checkoutQueue> cq;
	int helped = 0;
	int OpTime = inputInteger("\n\tEnter the time (0..37800 in seconds) of the store will be operated: ", 0, 37800);
	int curtime = time(0);
	int endTime = curtime + OpTime;
	int numberOfCheckstands = inputInteger("\n\tEnter the number of cash registers (1..10): ", 1, 10);

	for (int i = 1; i <= numberOfCheckstands; i++)
	{
		checkoutQueue queue;
		cq.push_back(queue);
	}
	do
	{
		Sleep(100);
		int customersPerLoop = newCustomer();
		for (int i = 1; i < customersPerLoop; i++)
		{
			if (numberOfCheckstands > 1)
			{
				cq[returnShortest(cq)].addCustomer();
				system("cls");
				displayLine(cq, helped, endTime);
				if (!timer(endTime))
					break;

			}
			else
			{
				cq[0].addCustomer();
				system("cls");
				displayLine(cq, helped, endTime);
			}

		}
		for (int i = 0; i < cq.size(); i++)
			if (!cq[i].empty() && (timer(endTime)))
			{
				cq[i].removeCustomer();
				helped++;
				system("cls");
				displayLine(cq, helped, endTime);
			}
	} while (timer(endTime));
}

//precondition: none
//postcondition: displays costco queue and service time
void displayLine(vector<checkoutQueue>& vec, int helped, int endTime)
{
	int currentTime = endTime - time(0);
	if (currentTime < 0)
		currentTime = 0;
	cout << "Costco Warehouse store open for " << currentTime << " \tNumber of customers served: " << helped << '\n';
	for (int i = 0; i < vec.size(); i++)
	{
		cout << '\n' << "Cash register #" << i + 1 << '\n';
		cout << vec[i] << '\n';
	}
}

//precondition: none
//postcondition: adds new customers that are at Costco checkout
int newCustomer()
{
	int amountOfCustomers = 5;
	int percentChance = 50;
	int random = 0;

	amountOfCustomers += (rand() % 2 + 1);
	return amountOfCustomers;
}

//precondition: none
//postcondition: returns false while integer is above int holder
bool timer(int endTime)
{
	int holder;
	holder = time(0);
	return(holder < endTime);
}

//precondition: none
//postcondition: places customer at register with an empty or currently shortest queue
int returnShortest(vector<checkoutQueue>& vec)
{
	int shortest = 0;
	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i] < vec[shortest])
			shortest = i;
	}
	return shortest;
}
