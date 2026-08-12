// hello welcome to our CARD class!!!
#include <iostream>
#include <string>

class Card {
    // members 
    public:
        std::string question;
        std:: string answer;
        int interval; 
        int nextReviewDay;

    // methods
    public: 
        // constructor
        Card( std::string q, std::string a) : question(q), answer(a) {}

        // setters

        // getters
        
        // display
        /*
        void display() {
            std::string enter; 
            std::cout << question << std::endl;
            getline(std::cin, enter);

            if (enter == ""){
                std::cout << answer << std:: endl;
            }
            
            
            std::cout << std::endl; 
        */
        };
