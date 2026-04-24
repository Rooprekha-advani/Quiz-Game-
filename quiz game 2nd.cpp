#include <iostream>
#include <string>
#include<windows.h>
#include <conio.h>  // For _getch() function




using namespace std;


int score = 0;  // Global variable to store the user's score
int totalQuestions = 0;  // Global variable to store the total number of questions

// Function to clear the console screen
void clearScreen() {

    system("cls");

}
// Function to display a question and get user input
bool askQuestion(string question, string options[], int correctOption) {
    totalQuestions++;  // Increment the total number of questions

    cout << question << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << options[i] << endl;
    }

    int userAnswer;
    cout << "Enter your choice (1-3): ";
    cin >> userAnswer;

    bool isCorrect = (userAnswer == correctOption);

    if (isCorrect) {
        score++;  // Increment the score for correct answers
    }

    return isCorrect;
}

// Function to play the warm-up round
bool warmUpRound() {
    clearScreen();  // Clear the screen before starting the warm-up round
   

    cout << "\n                                      Welcome to the Warm-up Round!" << endl;

    string gkQuestion = "What is the capital of France?";
    string gkOptions[] = {"Paris", "Berlin", "London"};
    int gkCorrectOption = 1;

    string scienceQuestion = "What is the chemical symbol for gold?";
    string scienceOptions[] = {"Au", "Ag", "Hg"};
    int scienceCorrectOption = 1;

    string sportsQuestion = "Which sport uses a shuttlecock?";
    string sportsOptions[] = {"Tennis", "Badminton", "Table Tennis"};
    int sportsCorrectOption = 2;

    int correctAnswers = 0;

    if (askQuestion(gkQuestion, gkOptions, gkCorrectOption)) {
   
        cout << "                                  Correct answer! "<<endl;
    
        correctAnswers++;
    } else {
     
        cout << "                                   Incorrect answer. "<<endl;
     
    }

    if (askQuestion(scienceQuestion, scienceOptions, scienceCorrectOption)) {
      
        cout << "                                     Correct answer! "<<endl;
  
        correctAnswers++;
    } else {
    
        cout << "                                     Incorrect answer. "<<endl;
      
    }

    if (askQuestion(sportsQuestion, sportsOptions, sportsCorrectOption)) {
    
        cout << "                                     Correct answer! "<<endl;
 
        correctAnswers++;
    } else {
      
        cout << "                                     Incorrect answer. "<<endl;
     
    }

    cout << "\n                                 **********You got " << correctAnswers << " out of " << totalQuestions << " questions correct in the Warm-up Round.**********" << endl;

    // Reset the global score and total questions for the challenge round
    score = 0;
    totalQuestions = 0;



    return correctAnswers >= 2;
}

// Function to play the challenge round
void challengeRound() {
    clearScreen();  // Clear the screen before starting the challenge round
 

    cout << "\n                            Congratulations! You have entered the Challenge Round!" << endl;

    // Challenge Round Question
    string challengeQuestion = "Which planet is known as the Red Planet?";
    string challengeOptions[] = {"Venus", "Mars", "Jupiter"};
    int challengeCorrectOption = 2;

    if (askQuestion(challengeQuestion, challengeOptions, challengeCorrectOption)) {
    
        cout << "                       Correct answer! You earned 5 points.     **HURRAY!**";
       
        cout << endl;
        score += 5; // Add 5 points to the score
    } else {
    
        cout << "                        Incorrect answer. Your answer is wrong.";
   
        cout << endl;
    }

    cout << "\nChallenge Round completed! Thanks for playing." << endl;
    cout << "                           Your final score is: " << score << " points out of " << totalQuestions << " questions." << endl;

    // Display correct answers and congratulations
   /* cout << "\nCorrect Answers:\n";
    cout << "1. Paris\n2. Au\n3. Badminton\n";*/
    cout << "\n                         *****Congratulations! " << score << " points is a great achievement!*****\n"<<endl;

    // Ask if the user wants to play with 'y' or 'n'
    char playChoice;
    cout << "\nDo you want to play again? (y/n): ";
    cin >> playChoice;

    if (playChoice == 'y' || playChoice == 'Y') {
        // Play again
        clearScreen();  // Clear the screen before starting the next round
       
        cout << "\nWelcome to the Second Round!" << endl;
   

        // Add questions for the second round
        // ...

        // Call the function for the second round
        // ...
    } else {
       
      cout << "\n                                    v^v^v^v^v^Thanks for playingv^v^v^v^v^" << endl;
    
    }
}

// Function to show scores
void showScores() {
   

    cout << "\n                                      ===== High Scores =====" << endl<<endl;
    cout << "Player: " << score << " points out of " << totalQuestions << " questions" << endl;

   
}

// Function to reset the score
void resetScore() {
    score = 0;
    totalQuestions = 0;
    cout << "\nScore has been reset to 0." << endl;
}

int main() {
	 system("color 3f");

    string playerName;
    cout << "\n                    ******************** Welcome to the Quiz Game ********************\n"<<endl;
    cout<<"                                                     *********          "<<endl;
    cout <<"                                                       Rules"<<endl; 
    cout<<"                                                     *********          "<<endl;
	cout<<"1.You must complete the Warm-up Round to move to the Challenge Round.\n";
    cout << "2.Each question in the Warm-up Round has three options. Answer at least two correctly to proceed.\n"<<endl;
   
    cout <<"Enter your name: "<<endl;
    
    getline(cin, playerName);

    int choice;
    do {
        clearScreen();  // Clear the screen // setColor(15);   // White color
        cout << "                                          Welcome, " << playerName << "!\n";
       
        cout << "\n1. Play Quiz\n2. Press 's' to Show Scores\n3. Reset Score\n4. Quit\nEnter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (warmUpRound()) {
                    challengeRound();
                } else {

                    cout << "\n                          Sorry, you did not qualify for the Challenge Round. Better luck next time!" << endl;

                }
                break;
            case 2:
                // Check if the user pressed 's' to show scores
                char key;
                cout << "\nPress 's' to show scores: ";
                cin >> key;
                if (key == 's' || key == 'S') {
                    showScores();
                    cout << "\nPress any key to continue...";
                    _getch();  // Wait for a key press before continuing
                }
                break;
            case 3:
                resetScore();
                break;
            case 4:
               
                cout << "\n                    v^v^v^v^v^Thanks for playingv^v^v^v^v^" << endl;
               
                break;
            default:
             
                cout << "\n                    Invalid choice. Please enter a valid option." << endl;
            
        }

    } while (choice != 4);

    return 0;
}

