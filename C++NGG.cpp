#include <iostream>
#include <ctime> // used for random number generation

int difficultySel(int &difficulty);
void guessGame(int &player, int &attempts, int &randomNum, int &difficulty);


int main(){

    srand(time(0));

    int randomNum = (rand() % 50) + 1; 
    int attempts = 0; // tracking attempts
    int player; // current guessing number
    int difficulty = 0; // difficulty of gamme

    //std::cout << "number: " << randomNum << "\n"; //print random number (for testing)

    difficultySel(difficulty); // ask the user to select difficulty

    //std::cout << "difficulty set to " << difficulty << "\n"; //check if difficulty changed (for testing)

    guessGame(player, attempts, randomNum, difficulty); // starts the game
    
    

    return 0;
}


void guessGame(int &player, int &attempts, int &randomNum, int &difficulty){

    std::cout << "*******************************************************\n";
    std::cout << "                   Guess the Number\n";
    std::cout << "*******************************************************\n";

        do{
            std::cout << "Enter number to try and guess (1-50) \n";
            std::cout << "*******************************************************\n";
            std::cin >> player; // player is asked to guess 
                if(player < randomNum){
                    std::cout << "*******************************************************\n";
                    std::cout << "go higher!\n";
                    attempts++; // attempt gets added
                    std::cout << "Attempts so far: " << attempts << "\n"; // the number of attempts is printed for the player to see
                    std::cout << "*******************************************************\n";
                }
                else if(player > randomNum){
                    std::cout << "*******************************************************\n";
                    std::cout << "go lower!\n";
                    attempts++;
                    std::cout << "Attempts so far: " << attempts << "\n";
                    std::cout << "*******************************************************\n";
                }
        }while(player != randomNum && attempts < difficulty); // while number hasnt been guessed and attempts are less than the difficulty this block of code keeps looping 

        if (attempts >= difficulty){
            std::cout << "*******************************************************\n";
            std::cout << "You lost. Attempts: " << attempts << "\n";
            std::cout << "Better luck next time!\n";
            std::cout << "*******************************************************\n";
            }
        if (player == randomNum){
            std::cout << "*******************************************************\n";
            attempts++;
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts\n";
            std::cout << "*******************************************************\n";
            }
}

int difficultySel(int &difficulty){
        std::cout << "*******************************************************\n";
        std::cout << "                      Welcome!\n";
        std::cout << "*******************************************************\n";
    do{
        std::cout << "Please select the difficulty level:\n";
        std::cout << "1. Easy (10 chances)\n";
        std::cout << "2. Medium (5 chances)\n";
        std::cout << "3. Hard (3 chances)\n";
        std::cout << "Enter your choice: ";
        std::cin >> difficulty; // difficulty is taken
        if (difficulty == 1){ // if difficulty is 1 the code below is executed
            std::cout << "*******************************************************\n";
            std::cout << "Great! You have selected the Easy difficulty level.\n";
            return difficulty = 10; // difficulty returned as maximum number of questions
        }
        else if (difficulty == 2){
            std::cout << "*******************************************************\n";
            std::cout << "Great! You have selected the Medium difficulty level.\n";
            return difficulty = 5; 
        }
        else if (difficulty == 3){
            std::cout << "*******************************************************\n";
            std::cout << "Great! You have selected the Hard difficulty level.\n";
            return difficulty = 3;
        }
        else{
            std::cout << "*******************************************************\n";
            std::cout << "The number you entered was invalid.\n";
        }
    }while(difficulty < 1 || difficulty > 3); // while the difficulty is less than 1 or more than 3 this block of code keeps looping 

    return difficulty; // avoid getting a warning since function doesn't return anything, this would be fine if the function's code was in main()
}