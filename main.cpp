#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

   //initialize deck
   vector<int> deck = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8,
                  8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13};

   //declare here to avoid looping declarations
   bool lastGuess = 1;
   bool cardDeleted = 0;
   
   string input;
   
   int card = 0, lastCard = 0;
   int higher = 0, lower = 0;
   
   //start loop here
 while (true) {
	 
   lastCard = card;
   
   //get starting card
   cout << "Card: "; 
   cin >> input;
   
   
   if (input.length() == 1) {
	  
	  card = (static_cast<int>(input[0]) - '0');
   }
   else {
	  
	  card = stoi(input);
   }
   
   //account for K, j, etc.
		
	if (card >= 1 && card <= 13) {
	}
		
	else if (card == 17 || card == 49) {
		
	  card = 1;
	}

	else if (card == 120 || card == 88 || card == 0) {

	  card = 10;
	}
		  
	else if (card == 26 || card == 58) {
		
	  card = 11;
	}
		  
	else if (card == 33 || card == 65) {
		
	  card = 12;
	}
		  
	else if (card == 27 || card == 59) {
		  
	  card = 13;
	}
		  
	else {
		
	  cout << "Invalid";
	  return 0;
	  }
	
   
   //check whether the previous guess was correct. Terminate program if not
	if (card > lastCard && lastGuess == 0) {
		
	  return 0;
	}
	else if (card < lastCard && lastGuess == 1) {
		
	  return 0;
	}
	
  //iterate through deck, tally higher/lower cards, & delete pulled card
  //this way the deck need only be read once 
  //+ reset variables
   higher = 0;
   lower = 0;
   cardDeleted = 0;
   
   for (int i = 0; i < deck.size(); i++) {
	   
	   if (deck[i] > card) {
		   
		   higher++;
	   }
	   else if (deck[i] < card) {
		   
		   lower++;
	   }
	   else if (deck[i] == card && cardDeleted == 0) {
		   //delete card
		   deck.erase(deck.begin() + i);
		   cardDeleted = 1;
	   }
   }
   
   //find optimal guess & take it  
   if (higher > lower) {
	     
	 cout << "\nHigher \n";
	 lastGuess = 1;
   }
		 
   else if (lower > higher) {
	   
	 cout << "\nLower \n";
	 lastGuess = 0;	
   }
	   
   else if (lower == higher) {
	   
	 srand(time(NULL));
	 cout << "\nEqual odds\n";
		
	   if (rand() % 2 == 0) {
			
		  cout << "\nLower \n";
		  lastGuess = 0;
		}
		else {
			
		  cout << "\nHigher \n";
		  lastGuess = 1;
		}
   
  
  }
  
 }
 
 return 0;
}
