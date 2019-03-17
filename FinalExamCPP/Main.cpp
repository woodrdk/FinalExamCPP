

// Robert M Wood Jr.
// 3/15/2019
// CPW 218 Winter
// 2019 Final Exam

#include <iomanip> // need?
#include <iostream>
#include <array>
#include <string>
#include <cstdlib>
#include <random>
#include <ctime>

using namespace std;

// Defined the decksize
const int DECK_SIZE = 52;

// Array of the decks cards
const array<string, DECK_SIZE> cards{
		 "AH", "AC", "AD", "AS",
		 "2H", "2C", "2D", "2S",
		 "3H", "3C", "3D", "3S",
		 "4H", "4C", "4D", "4S",
		 "5H", "5C", "5D", "5S",
		 "6H", "6C", "6D", "6S",
		 "7H", "7C", "7D", "7S",
		 "8H", "8C", "8D", "8S",
		 "9H", "9C", "9D", "9S",
		 "10H", "10C", "10D", "10S",
		 "JH", "JC", "JD", "JS",
		 "QH", "QC", "QD", "QS",
		 "KH", "KC", "KD", "KS", };

// function prototypes 
void initializeDeck(array<const string *, DECK_SIZE> * deck);
void displayDeck(array<const string *, DECK_SIZE> deck);
void shuffleDeck(array<const string *, DECK_SIZE> * deck);
void printMenu();

int main() {

	array<const string *, DECK_SIZE> deck;
	initializeDeck(&deck);

	int userChoice = -1;
	while (userChoice != 0) {
		printMenu();
		cin >> userChoice;
		cout << endl; // Added this line to make program more visually readable to me when running 
		if (userChoice == 1) {
			shuffleDeck(&deck);
		}
		else if (userChoice == 2) {
			displayDeck(deck);
		}
	}

	system("pause");
	return 0;
}

void initializeDeck(array<const string *, DECK_SIZE> * deck) {
	for (size_t i = 0; i < DECK_SIZE; ++i) {
		(*deck)[i] = &cards[i];
	}
}

// This method tells the user what to push to run the program
void printMenu() {
	cout << "0 - Quit" << endl;
	cout << "1 - Shuffle deck" << endl;
	cout << "2 - Display deck" << endl;
}

// This method will display the deck of cards
void displayDeck(array<const string *, DECK_SIZE> deck) {
	cout << "This is the deck of Cards" << endl << endl;
	// Will print out the cards
	// currently prints the address not the actual data
	for (size_t i = 0; i < DECK_SIZE; ++i)
	{
		cout << *deck[i] << " ";
		if (i == 12 || i == 25 || i == 38) {
			cout << endl;
		}
	}
	cout << endl << endl;
}

// This method will shuffle the deck of cards
void shuffleDeck(array<const string *, DECK_SIZE> * deck) {
	// using the default random number generator will produce random  0 - 51
	static default_random_engine engine(static_cast<unsigned int>(time(0)));
	static uniform_int_distribution<unsigned int> randomInt(0, 51);
	int whichCard = randomInt(engine);
	for (size_t i = 0; i < DECK_SIZE; ++i)
	{	// check if the card has already been assigned

		// reassigns the card
		(*deck)[i] = &cards[whichCard];
	}
	// Tells the user the deck is shuffled
	cout << "Shuffled the deck!" << endl << endl;
}