// we are just going to do a minimal version for now

/*
main.cpp will:  
- open cards.json
 - create card objects
 - store them in a vector
 - shuffle vector
 - loop
*/

#include <iostream>
#include <fstream> 
#include <string>
#include <nlohmann/json.hpp> // so we can parse through json
#include <vector> 
#include <random>
#include "Card.h"
using json = nlohmann::json; // so we don't have to write the full thing out everytime


int main (){
    // display introductory messages
    std::cout << "++++++++++ STUDY ++++++++++" << std::endl;
    std::cout << "select ENTER for next!" << std::endl;
    std::cout << "(q to quit)" << std::endl;
    std::cout << std::endl;

    std::ifstream file ("data/cards.json"); // open stream to our json file
    
    /*
    // check to see if cards.json is open!
    if (file.is_open()){
        std::cout << "cards.json open successfully!" << std::endl;
    }
    else {
        std::cout << "cards.json failed!" << std::endl; 
    }
    */

    // create json object
    json cards; 
    file >> cards;
    
    std::string enter;
    std::string answer;
    std::string question;
    int num = 1; 
    
   
    // okay this is going to put the cards into a vector
    std::vector<Card> flashCards;

    // generate random stuff so we can shuffle 
    std::random_device rd; 
    std::mt19937 g(rd());

    // PUTTING OUR CARDS IN THE VECTOR!
    for (int i = 0; i < cards.size(); i++){
        //read one json object, create one card, put into our flashcards vector. 
        question = cards[i]["question"];
        answer = cards[i]["answer"];
        flashCards.push_back(Card(question, answer)); 
    } 
    // shuffle the cards in our vector 
    std::shuffle(flashCards.begin(), flashCards.end(), g);
    

    // reading our cards!!!
    for (const Card& card : flashCards){
        
        std::cout << "card " << num++ << "/" << flashCards.size() <<  std::endl;
        std::cout << card.question << std::endl; 
        getline(std::cin, enter);

        if (enter == ""){
            std::cout << card.answer << std::endl;
        }
        else if (enter == "q"){
            break;
        }

        // give opportunity to quit
        getline(std::cin, enter);

        if (enter == ""){
            std::cout << std::endl;
        }
        else if (enter == "q"){
            break;
        }
    }
   
   
}