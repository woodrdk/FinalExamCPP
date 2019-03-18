

// Robert M Wood Jr.
// 3/15/2019
// CPW 218 Winter
// 2019 Final Exam


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

// Main function that calls the actions of the program
int main() {

	array<const string *, DECK_SIZE> deck;
	initializeDeck(&deck);
	// variable for user choice of what to do
	int userChoice = -1;
	// as long as the user doesnt choose 0 do the following
	while (userChoice != 0) {
		// prints out the options for the user to choose from
		printMenu();
		// Allows user to put their choice in for what they want to do
		cin >> userChoice;
		// Added this line to make program more visually readable to me when running 
		cout << endl; 
		// if user chooses 1 then shuffle the deck
		if (userChoice == 1) {
			shuffleDeck(&deck);
		}
		// if user picks 2 then display the deck
		else if (userChoice == 2) {
			displayDeck(deck);
		}
	}
	// pauses the program till key is pressed
	system("pause");
	return 0;
}

// This method builds the initial deck of cards before displayed or shuffled
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
	for (size_t i = 0; i < DECK_SIZE; ++i)
	{
		// prints out the card in order
		cout << *deck[i] << " ";
		// checks what card it is and if its the 13th, 16th or 39th it inserts an endline
		if (i == 12 || i == 25 || i == 38) {
			cout << endl;
		}
	}
	// prints two blank lines for spacing to make it look better visually
	cout << endl << endl;
}

// This method will shuffle the deck of cards
void shuffleDeck(array<const string *, DECK_SIZE> * deck) {
	// using the default random number generator will produce random  0 - 51
	static default_random_engine engine(static_cast<unsigned int>(time(0)));
	static uniform_int_distribution<unsigned int> randomInt(0, 51);   // needs to be in the loop
	int whichCard = randomInt(engine);

	for (size_t i = 0; i < DECK_SIZE; ++i)
	{	// check if the card has already been assigned
		
		for (int w = 0; w < i; ++w)
		{
			// sets up what number to swap with 
			int j = i + (rand() % (52 - i));
			// swaps card with randomly chosen card
			swap((*deck)[i], (*deck)[j]);
		}
	}
	// Tells the user the deck is shuffled
	cout << "Shuffled the deck!" << endl << endl;
}