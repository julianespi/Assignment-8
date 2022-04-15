#include <iostream>
#include <deque>
#include <stack>
#include <vector>
#include "input.h"

using namespace std;

//precondition: cardUser is set
//postcondition: sets up player decks
void Deck(int& cardUser)
{
	int i = 0;
	int empCheck = 0;
	int playerSelection = 1;
	int cardDealt;
	int setDeck = cardUser;
	bool cardGiven = false;
	bool dealt = false;
	bool empty = false;
	int cardSelection;
	int playOne;
	int playTwo;
	vector <int> cardCount;
	deque <int> inPlay;
	stack <int> cardDeckSetup;
	deque <int> deckOne;
	deque <int> deckTwo;

	srand(time(0));

	while (i < setDeck)
	{
		cardCount.push_back(4);
		i++;
	}

	while (dealt == false)
	{
		cardSelection = rand() % setDeck;
		if (cardCount[cardSelection] != 0)
		{
			cardGiven = false;
			cardCount[cardSelection] = cardCount[cardSelection]--;
			if (playerSelection == 1 && cardGiven == false)
			{
				cardSelection = cardSelection++;
				deckOne.push_front(cardSelection);
				cout << "Deck one received: " << deckOne.front() << endl;
				cardGiven = true;
				playerSelection = 2;
			}
			if (playerSelection == 2 && cardGiven == false)
			{
				cardSelection = cardSelection++;
				deckTwo.push_front(cardSelection);
				cout << "Deck two received: " << deckTwo.front() << endl;
				cardGiven = true;
				playerSelection = 1;
			}
		}
		int x = 0;
		while (x < setDeck)
		{
			if (cardCount[x] == 0)
			{
				cout << empCheck << endl;
			}
			if (empCheck == setDeck)
			{
				empty = true;
			}
			else
			{
				empty = false;
			}
			x++;
		}
		if (empty == true)
		{
			dealt = true;
		}
	}
}

//precondition: none
//postcondition: plays a game of war
void Game()
{
	int cardUser = 0;

	cout << "Simulation of War (Card Game) using deque STL" << endl;
	cout << "In this game a standard deck of 52 (no jokers) will be used." << endl << endl;
	cardUser = inputInteger("Enter a number of cards per suit: ", 1, 13);
	Deck(cardUser);
}

