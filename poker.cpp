#include <iostream>
using namespace std;

int main() {
    int y = 0;

    std::cout << "THE SUPER CONVENIENT POKER MACHINE by only Max Sorrell on his own\n";
    std::cout << "(Madison didn't help at all)\n\n";

    string cards[52] = { "AS","2S","3S","4S","5S","6S","7S","8S","9S","TS","JS","QS","KS","AC","2C","3C","4C","5C","6C","7C","8C","9C","TC","JC","QC","KC","AH","2H","3H","4H","5H","6H","7H","8H","9H","TH","JH","QH","KH","AD","2D","3D","4D","5D","6D","7D","8D","9D","TD","JD","QD","KD" };

    string players_hand[2];

    srand(time(NULL)); //set random seed

    //Assigns two random cards to the players hand
    for (int i = 0; i < 2; i++) {
        y = rand() % 52 + 1; //get random number between 1 and 52
        //cout << "\nRandom: " << y << "\n";

        while (cards[y] == "NULL") {
            y = rand() % 52 + 1; //get random number between 1 and 52
        }
        //cout << cards[y] << "\n";
        players_hand[i] = cards[y];

        cout << "cards in hand: " << players_hand[i] << endl;
        cards[y] = "NULL";

        y = 0;
    }

    string deck[5];

    //Assigns 3 random cards to the deck - this can be adapted 
    for (int i = 0; i < 3; i++) {
        y = rand() % 52 + 1; //get random number between 1 and 52
        //cout << "\nRandom: " << y << "\n";

        while (cards[y] == "NULL") {
            y = rand() % 52 + 1; //get random number between 1 and 52
        }
        //cout << cards[y] << "\n";
        deck[i] = cards[y];

        //cout << players_hand[i];
        cout << "cards in deck: " << deck[i] << endl;
        cards[y] = "NULL";

        y = 0;
    }

    cout << endl << "hand 1: " << players_hand[0] << endl;
    cout << players_hand[1] << endl << endl;
    cout << "deck 1: " << deck[0] << endl;
    cout << deck[1] << endl;
    cout << deck[2] << endl;



    int finalValue[5];
    char finalSuit[5]; //initialising the arrays up here so i can add to them below


    int phtsvalue;
    char phtssuit;
    for (int p = 0; p < 2; p++) {//initial loop is for the hand. next loop will be for deck but will do basically the same thing
        string players_hand_to_string = players_hand[p];
        phtsvalue = (int)players_hand_to_string[0];
        if (phtsvalue < 58) {
            phtsvalue = phtsvalue - 48;
        }
        else if (phtsvalue == 65) { //ace
            phtsvalue = 14;
        }
        else if (phtsvalue == 75) { // king
            phtsvalue = 13;
        }
        else if (phtsvalue == 81) { // queen
            phtsvalue = 12;
        }
        else if (phtsvalue == 74) { // jack
            phtsvalue = 11;
        }
        else if (phtsvalue == 84) { // ten
            phtsvalue = 10;
        }
        else {
            cout << "mistake made";
        }
        phtssuit = players_hand_to_string[1];


        // cout << "Test: " << phtsvalue << endl;
        finalValue[p] = phtsvalue;
        //cout << "Test: " << phtssuit << endl;
        finalSuit[p] = phtssuit;

    }


    int dtsvalue;
    char dtssuit;
    for (int p = 0; p < 3; p++) {//loop for deck
        string deck_to_string = deck[p];
        dtsvalue = (int)deck_to_string[0];
        if (dtsvalue < 58) {
            dtsvalue = dtsvalue - 48;
        }
        else if (dtsvalue == 65) { //ace
            dtsvalue = 14;
        }
        else if (dtsvalue == 75) { // king
            dtsvalue = 13;
        }
        else if (dtsvalue == 81) { // queen
            dtsvalue = 12;
        }
        else if (dtsvalue == 74) { // jack
            dtsvalue = 11;
        }
        else if (dtsvalue == 84) { // ten
            dtsvalue = 10;
        }
        else {
            cout << "mistake made";
        }
        dtssuit = deck_to_string[1];



        //cout << "Test: " << dtsvalue << endl;
        finalValue[p + 2] = dtsvalue; // have to use +2 because the hand cards have already been added and there were 2 of them
        //cout << "Test: " << dtssuit << endl;
        finalSuit[p + 2] = dtssuit;
    }


    //the cards are now in their respective arrays, finalValues, and finalSuits. you can see them using this loop but it isnt needed
    /*
    for (int p = 0; p < 5; p++) {
        cout << (int) finalValues[p] << endl;
        cout << (char) finalSuits[p] << endl;
    }
    */

    //char finalSuit[5] = {'D', 'D', 'D', 'D', 'S'};



    char temp;
    bool royalFlush = false;
    //bool straightFlush = false;
    string handResult = " ";
    bool flush = false;
    bool straight = true;

    // int finalValue[5] = { 9, 11, 7, 8, 5 };

    //Bubble sort to organise finalValue in decending order
    //in order to get the final suit to "move" with the final value, we need to move it using this bubble sort.

    char tempChar;


    for (int i = 0; i < 5; i++) {
        for (int n = 0; n < 5; n++) {
            if (finalValue[n] < finalValue[n + 1]) {
                temp = finalValue[n + 1];
                finalValue[n + 1] = finalValue[n];
                finalValue[n] = temp;

                tempChar = finalSuit[n + 1];
                finalSuit[n + 1] = finalSuit[n];
                finalSuit[n] = tempChar;
            }
        }
    } // organises array so cards are in descending order


    //first we check for a flush, this is the only thing we need to use finalSuits for
    if ((finalSuit[0] == finalSuit[1]) && (finalSuit[1] == finalSuit[2]) && (finalSuit[2] == finalSuit[3]) && (finalSuit[3] == finalSuit[4])) {
        flush = true;
    }

    //straight check - not working
    for (int p = 0; p < 4; p++) {
        int value1 = 0;
        int value2 = 0;
        value1 = finalValue[p];

        value2 = finalValue[p + 1];

        if (value1 - value2 != 1) {
            straight = false;
        }
    }

    std::cout << "\nStraight: " << straight;

    //Checks what type of flush flush
    if (flush == true) {
        if (finalValue[0] == 14 && straight == true) {
            royalFlush = true;
            handResult = "Royal Flush";
        }
        else if (straight == true) {
            handResult = "Straight Flush";
        }
        else {
            handResult = "Flush";
        }
    }


    int similarCards = 0;
    int tempCard;

    for (int i = 0; i < 5; i++) {
        tempCard = finalValue[i];
        if (tempCard == finalValue[i + 1]) {
            similarCards += 1;
        }
    }

    std::cout << "\n" << similarCards;

    if (similarCards == 3) {
        if (finalValue[1] != finalValue[3]) {
            handResult = "Full House";
        }
        else {
            handResult = "Four of a Kind";
        }
    }
    else if (similarCards == 2) {
        if (finalValue[1] != finalValue[3]) {
            handResult = "Two pair";
        }
        else {
            handResult = "Three of a Kind";
        }
    }
    else if (similarCards == 1) {
        handResult = "Pair";
    }
    //Two pairs. You goddamn pedantic prick


    std::cout << "\n" << handResult << "\n";
    char convertedFinalSuit;
    if (handResult == " ") {
        if (finalValue[0] == 14) {
            convertedFinalSuit = 'A';
            std::cout << "HIGH CARD: " << convertedFinalSuit << finalSuit[0] << "\n";
        }
        else if (finalValue[0] == 13) {
            convertedFinalSuit = 'K';
            std::cout << "HIGH CARD: " << convertedFinalSuit << finalSuit[0] << "\n";
        }
        else if (finalValue[0] == 12) {
            convertedFinalSuit = 'Q';
            std::cout << "HIGH CARD: " << convertedFinalSuit << finalSuit[0] << "\n";
        }
        else if (finalValue[0] == 11) {
            convertedFinalSuit = 'J';
            std::cout << "HIGH CARD: " << convertedFinalSuit << finalSuit[0] << "\n";
        }
        else if (finalValue[0] == 10) {
            convertedFinalSuit = 'T';
            std::cout << "HIGH CARD: " << convertedFinalSuit << finalSuit[0] << "\n";
        }
        else
            std::cout << "HIGH CARD: " << finalValue[0] << finalSuit[0] << "\n";
    }

    for (int p = 0; p < 5; p++) {
        cout << finalValue[p] << endl;

    }

    // std::cout << flush;



     /*
     we now have each card which the player has been dealt as an int and a char.
     we now need to work out the win conditions
     the win conditions are:

     pair
     three of a kind
     four of a kind
     flush
     these can all be done by comparing the chars and seeing if all 5 are the same. can be done in same if else block because only one is applicable.

     two pairs

     boolean pair being false would mean we dont have to check for
     {
     straight - if the difference between the largest and smallest integer is 4 and there are no pairs then its a straight
     straight flush - same as above but all the suits are also the same.
     royal flush - add up all of the integers and if they total 60 and all of the suits are the same then its a royal flush!
     }

     full house - a pair and a three of a kind. tricky


     */
}