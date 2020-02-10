//Word Jumble
// The classic word jumble game where the player can ask for hints

#include <iostream> //input output
#include <string> // allows string varibles 
#include <cstdlib> // all standard librarys 
#include <ctime> // to convert time value to a string, honestly not needed???? 

using namespace std; // allows shortcut on cout's and cin's

int main() // Main varible 
{
	system("color 0A"); // adds color to text 
	bool replay = true; // so user can have the choice to play again
	int humanAnswer = 0;  // for yes or no at the end
	enum fields { WORD, HINT, NUM_FIELDS }; // to define the data types within the enum field 
	const int NUM_WORDS = 10; // amount possible words
	while (replay == true) // to re run or naw depending on user 
	{
		const string WORDS[NUM_WORDS][NUM_FIELDS] = // string integers which are the words and the hints 
		{
			{"wall", "Do you feel you're banging your head against something?"},
			{"glasses", "These might help you see the answers."},
			{"labored", "Going slowly, is it?"},
			{"persistent", "Keep at it"},
			{"jumble", "It's what the game is all about"},
			{"perception", "How deeply can you see?"},
			{"interrogation", "First you must answer my question"},
			{"darknet", "Onions"},
			{"secret", "Tell me something"},
			{"hacker", "sorry this information is encrypted. =("},
		};

		srand(static_cast<unsigned int>(time(0))); // picks word
		int choice = (rand() % NUM_WORDS);  // ^^
		string theWord = WORDS[choice][WORD];  //word to guess
		string theHint = WORDS[choice][HINT]; //hint for word
		string jumble = theWord; //jumbled version of word
		int length = jumble.size(); //determines word size of jumble word
		for (int i = 0; i < length; ++i) // integer i starts at 0 and counts entire word until it = length     
		{
			int index1 = (rand() % length); //integer to randomize the length for index 1
			int index2 = (rand() % length); //interger to randomize the length for index 2
			char temp = jumble[index1]; // contains the jumble for index 1
			jumble[index1] = jumble[index2]; // jumbles first half of word then second half of word and squishes it togther 
			jumble[index2] = temp; // a varible that contains our jumble word. 
		}
		// displays text that welcomes and instructs user
		cout << "\t\t\tWelcome to Keywords";
		cout << "\nUnscramble the letters to make a word. This is a top secret program created by the CIA for the CIA eyes only\n";
		cout << "Enter 'hint' for a hint.\n";
		cout << "Enter 'quit' to quit the game.\n\n";
		cout << "the jumble is: " << jumble << endl; //tells user this is the jumbled version of the word
		
		string guess; // user guess
		cout << "\n\nYour guess: "; // text to request answer
		cin >> guess; // human guess

		while ((guess != theWord) && (guess != "quit")) // while loop for hint.
		{
			if (guess == "hint") // if user types hint then it does the following 
			{
				cout << theHint; //displays hint 
			}
			else // for wrong answers
			{
				cout << "Sorry, that's not it."; //displays wrong answer text
			}
			cout << "\n\nyour guess: "; // re asks for guess
			cin >> guess; //human guess 
		}

		if (guess == theWord) // if the user gets it right "if" loop. 
		{
			cout << "\nGood work you guessed correct..."; // congratz for winner
		}
		cout << "\nThanks for playing, expect us\n" << endl; // random cringy CIA stuff
		cout << "\nWould you like to play again?" << endl; // asks if the user would like to play again
		cout << "\nPress '1' for Yes & '2' for No." << endl; // instucts user on how to play again or quit
		cin >> humanAnswer; //collects user input on whether they want to play or not

		if (humanAnswer == 1) // 1 to play
		{
			replay = true; // to start the game over
		}
		else if (humanAnswer == 2) // to quit
		{
			replay = false; // stops loop
		}
		else // for less expected answers
		{
			replay = false; // stops loop
		}
		
	}
	system("pause"); //pauses
	return 0; // returns the integer value of 0 and verifys execution 
}
	
