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

    // std::cout << "loaded " << cards.size() << " cards!" << std::endl; 

    /*

    // attempt to print the first card!
    std::cout << cards[0]["question"] << std:: endl;
    std::cout << cards[0]["answer"] << std::endl;

    // loop through all the cards!
    for (int i = 0; i < cards.size(); i++){
        std::cout << cards[i]["question"] << std::endl;
        std::cout << cards[i]["answer"] << std::endl; 
    }

    */

    // ok now we are going to attempt to print a question, wait for user input, then display the answer!
    // outer loop to get through all the cards
    std::string enter;
    std::string answer;
    std::string question;
    //enter = "";

    for (int i = 0; i < cards.size(); i++){
        question = cards[i]["question"];
        std::cout << "Card " << i + 1 << "/" << cards.size() << std::endl;
        std::cout << question << std::endl;
        //std::cout << cards[i]["question"] << std::endl;
        
        answer = cards[i]["answer"];
       
        getline(std::cin, enter); 

        if (enter == ""){
            std::cout << answer << std::endl;
            //std::cout << cards[i]["answer"] << std::endl;
        }
        else if (enter == "q"){
            break;
        }
        std::cout << std::endl;
        std::cout << std::endl; 

        getline(std::cin, enter); 

        if (enter == ""){
            std::cout << std::endl;
            //std::cout << cards[i]["answer"] << std::endl;
        }
        else if (enter == "q"){
            break;
        }

    }

    std::cout << "Congratulations! You have studied all your cards!" << std::endl;
    

    //freak i don't really remember how to get input

}