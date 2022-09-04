///My second project using c++: Number Guessing Game!
///Using pure c++!

///including important libraries
#include <iostream>
#include <string>
#include <random>

using namespace std;

/// Defining game functions
void Game();
void displayGuess(string);
static void GuessWithHint(string);
static void GuessWithoutHint(string);
void UpdateDisplay();
void Win(string);
void GameOver(string);


///Main function
int main(){
    char chr;
    cout<<"Welcome to my number guessing project!\nPress any key to start:"<<endl;
    chr = _getwch();
    if (chr=='q') return 0;
    else{
        Game();
        return 0;
    }
}

/// @brief 
void Game(){
    system("cls");
    int offset, max;
    cout<<"Choose a number range!"<<endl;
    cout<<"From: ";
    cin>>offset;
    cout<<"By: ";
    cin>>max;
    int num = offset+(rand()%max);
    string rdNum = to_string(num);
    displayGuess(rdNum);
}

/// @brief 
/// @param rdNum
///Displaying the number to guess via question marks in a nice and simple way! then moving into the guessing mode
///There are 2 guessing modes: ["with hint", "without hint"] if the number has 2 digits or more you can use some hint to unlock a new digit
///If the number has only 1 digit, there is no need for a hint:(
void displayGuess(string rdNum){
    system("cls");
    string QMK;
    for(int i = 0; i<rdNum.length(); i++){
        QMK.push_back('?');
    }
    cout<<"I'm "<<QMK.length()<<" Digits Long!"<<endl;
    cout<<QMK<<endl;
    switch(rdNum.length()){
        case 1:
        GuessWithoutHint(rdNum);
        break;
        default:
        GuessWithHint(rdNum);
    }
}

/// @brief 
/// @param rdNum 
static void GuessWithHint(string rdNum){
    cout<<"Guess With Hint!"<<endl;
}

/// @brief 
/// @param rdNum 
static void GuessWithoutHint(string rdNum){
    cout<<"Guess me!"<<endl;
    string guess;
    int falseGuess = 3;
    cin>>guess;
    if(falseGuess<=0){
        GameOver(rdNum);
    }
    else{
        if(guess==rdNum) {
            UpdateDisplay();
            Win(guess);
        }
        else {
            UpdateDisplay();
            falseGuess -= 1;
            GuessWithoutHint(rdNum);
        }
    }
}


void UpdateDisplay(){
    system("cls");
}

void GameOver(string rdNum){
    cout<<"You Lost! The number is: "<<rdNum<<endl;
}

void Win(string guess){
    cout<<"You Won! The number is: "<<guess<<endl;
}