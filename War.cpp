//precondition: cardUser is set
//postcondition: sets up player decks
void Deck(int& cardUser)
{
	int i = 0;
	int playerSelection = 1;
	int cardDealt;
	int setDeck = cardUser;
	bool cardGiven = false;
	bool dealt = false;
	bool empty = false;
	bool gameComplete = false;
	bool playerOneWin = false;
	bool playerTwoWin = false;
	int cardSelection;
	int cardTotal;
	vector <int> cardCount;
	deque <int> playDeque;
	deque <int> deckOne;
	deque <int> deckTwo;

	srand(time(0));

	cardTotal = 4 * setDeck;

	while (i < setDeck)
	{
		cardCount.push_back(4);
		i++;
	}

	cout << "Deck is being created..." << endl << endl;
	Sleep(1000);
	system("CLS");
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
				cardGiven = true;
				playerSelection = 2;
			}
			if (playerSelection == 2 && cardGiven == false)
			{
				cardSelection = cardSelection++;
				deckTwo.push_front(cardSelection);
				cardGiven = true;
				playerSelection = 1;
			}
		}
		int x = 0;
		int empCheck = 0;
		while (x < setDeck)
		{
			if (cardCount[x] == 0)
			{
				empCheck += 1;
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
			cout << "Cards have been dealt to both players." << endl;
			cout << "The game will now begin." << endl << endl;
		}
	}

	while (gameComplete == false)
	{
		int inPlay = 1;
		int countPS = 0;
		int countPSTotal = 0;
		int coinFlip = 0;
		int shuffle = 0;
		bool takenTwo = false;
		bool takenOne = false;
		while (inPlay != 0 && gameComplete == false)
		{
			cin.ignore();
			if (deckOne.empty() == true && deckTwo.empty() == false && playerOneWin == false)
			{
				cout << "Player 1 has run out of cards! Player 2 wins with " << cardTotal << " in their deck!" << endl;
				gameComplete = true;
				break;
			}
			if (deckTwo.empty() == true && deckOne.empty() == false && playerTwoWin == false)
			{
				cout << "Player 2 has run out of cards! Player 1 wins with " <<  cardTotal << " in their deck!" << endl;
				gameComplete = true;
				break;
			}
			cout << "Player 1 plays: " << setw(3);
			cout << deckOne.front();
			cout << " || " << "Players 2 plays: " << setw(3);
			cout << deckTwo.front() << " -> ";
			if (deckOne.front() > deckTwo.front() && inPlay != 0 && gameComplete == false)
			{
				cout << "Player 1 wins the pot." << endl << endl;
				takenOne = false;
				takenTwo = false;
				while (takenOne == false && takenTwo == false)
				{
					shuffle = rand() % 2 + 1;
					if (shuffle == 1 && deckOne.empty() == false && takenOne == false)
					{
						deckOne.push_back(deckOne.front());
						deckOne.pop_front();
						takenOne = true;
					}
					if (shuffle == 2 && deckTwo.empty() == false && takenTwo == false)
					{
						deckOne.push_back(deckTwo.front());
						deckTwo.pop_front();
						takenTwo = true;
					}
				}
				inPlay--;
				if (deckTwo.empty() == true && deckOne.empty() == false && playerTwoWin == false)
				{
					cout << "Player 2 has run out of cards! Player 1 wins with " << cardTotal << " in their deck!"  << endl;
					gameComplete = true;
					break;
				}
				if (countPSTotal != 0)
				{
					countPS = 0;
					while (countPSTotal != 0)
					{
						countPSTotal--;
						deckOne.push_back(playDeque.front());
						playDeque.pop_front();
					}
				}
			}
			if (gameComplete == true)
			{
				break;
			}
			if (deckTwo.front() > deckOne.front() && inPlay != 0 && gameComplete == false)
			{
				cout << "Player 2 wins the pot." << endl << endl;
				takenOne = false;
				takenTwo = false;
				while (takenOne == false && takenTwo == false)
				{
					shuffle = rand() % 2 + 1;
					if (shuffle == 1 && deckOne.empty() == false && takenOne == false)
					{
						deckTwo.push_back(deckOne.front());
						deckOne.pop_front();
						takenOne = true;
					}
					if (shuffle == 2 && deckTwo.empty() == false && takenTwo == false)
					{
						deckTwo.push_back(deckTwo.front());
						deckTwo.pop_front();
						takenTwo = true;
					}
				}
				inPlay--;
				if (deckOne.empty() == true && deckTwo.empty() == false && playerOneWin == false)
				{
					cout << "Player 1 has run out of cards! Player 2 wins with " << cardTotal << " in their deck!"  << endl;
					gameComplete = true;
					break;
				}
				if (countPSTotal != 0)
				{
					countPS = 0;
					while (countPSTotal != 0)
					{
						countPSTotal--;
						deckOne.push_back(playDeque.front());
						playDeque.pop_front();
					}
				}
			}
			if (gameComplete == true)
			{
				break;
			}
			if (deckOne.front() == deckTwo.front() && inPlay != 0 && gameComplete == false)
			{
				cout << "Player 1 and 2 tie." << endl << endl;
				takenOne = false;
				takenTwo = false;
				countPSTotal += 2;
				while (countPS != countPSTotal)
				{
					shuffle = rand() % 2 + 1;
					if (shuffle == 1 && deckOne.empty() == false && takenOne == false)
					{
						playDeque.push_back(deckOne.front());
						deckOne.pop_front();
						takenOne = true;
						countPS++;
					}
					if (shuffle == 2 && deckTwo.empty() == false && takenTwo == false)
					{
						playDeque.push_back(deckTwo.front());
						deckTwo.pop_front();
						takenTwo = true;
						countPS++;
					}
				}
				if (countPSTotal == cardTotal)
				{
					cout << "There are no more cards in either player's deck." << endl << "Determining who earns the pot through a coin flip." << endl;
					inPlay = 0;
					coinFlip = rand() % 2 + 1;
					if (coinFlip == 1)
					{
						cout << "Player 1 wins the coin flip!" << endl;
						cout << "Player 1 wins with " << cardTotal << " cards!" << endl;
						gameComplete = true;
						playerOneWin = true;
					}
					if (coinFlip == 2)
					{
						cout << "Player 2 wins the coin flip!" << endl;
						cout << "Player 2 wins with " << cardTotal << " cards!" << endl;
						gameComplete = true;
						playerTwoWin = true;
					}
				}
			}
		}
	}
}

//precondition: none
//postcondition: plays a game of war
void Game()
{
	int cardUser = 0;

	cout << "Simulation of War (Card Game) using deque STL" << endl;
	cout << "In this game a standard deck of up to 52 cards (no jokers) will be used." << endl << endl;
	cardUser = inputInteger("Enter a number of cards per suit: ", 1, 13);
	Deck(cardUser);
}

