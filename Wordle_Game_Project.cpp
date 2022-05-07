#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>





//************PROGRAM FUNCTIONS************//


//This function gets a random word from Wordle_Dictionary.txt which contains a library of 5 letter words
std::string get_random_word();
std::string get_random_word()

{
std::ifstream word_file;

std::string words;

std::vector<std::string> line; //This will store the words from the txt file that will then be used to choose a random word

word_file.open("Wordle_Dictionary.txt"); //This opens the name of the txt file containing all of the words for the game

if(word_file.is_open())
{
    while (std::getline(word_file, words))
    {
      line.push_back(words); //This adds each word in the txt file to the vector line
    }
    word_file.close();
}
srand(time(0));
return line[rand()%line.size()];
}



//This function is used to check that the characters in the string are all letters
bool letter_check(std::string const &str);
bool letter_check(std::string const &str) 
{
	return str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos;
}


//This function checks if the user input is valid
bool check_user_word(std:: string const &user_word);
bool check_user_word(std:: string const &user_word)
{
    
    if ((user_word.size() != 5) && (!letter_check(user_word)))
    { 
            std::cout<<"\n";
            std::cout<<"5 letters are required."<<std::endl;
            std::cout<<"No numbers or special characters are allowed."<<std::endl;
            std::cout<< "Please try again."<<std::endl; 
            return true;
    }

    else if (!letter_check(user_word))
    {
        std::cout<<"\n";
        std::cout<<"No numbers or special characters are allowed."<<std::endl;
        std::cout<<"Please try again."<<std::endl;
        return true;
     
    }
    else if(user_word.size() != 5)
    {
        std::cout<<"\n";
        std::cout<<"5 letters are required."<<std::endl;
        std::cout<< "Please try again."<<std::endl;
        return true;
    }
    else
    {
        return false;
    }
    
}


//This function is used to convert any lower case letters to upper case 
//then compares the user word to the random word
void upper_case(std::string const &user_word, std::string const &random_word);
void upper_case(std::string const &user_word, std::string const &random_word)
{
    std::string user_word_caps;

    for(int i = 0; i<5; i++)
    {
    user_word_caps[i] = (char) toupper(user_word[i]);
    }

    if(user_word_caps[0] == random_word[0] && user_word_caps[1] == random_word[1] && user_word_caps[2] == random_word[2] 
    && user_word_caps[3] == random_word[3] && user_word_caps[4] == random_word[4])
    {   
        std::cout<<"\x1b[32m"<<user_word_caps[0]<<user_word_caps[1]<<user_word_caps[2]<<user_word_caps[3]
        <<user_word_caps[4]<<"\x1b[37m"<<std::endl;
        std::cout<<"\n";
        std::cout<<"Congratulations! You guessed the word of the day!"<<std::endl;
        std::cout<<"\n";
        exit(EXIT_SUCCESS);
    }

    
}

//This function creates a vector of strings which contains the name of the color
//assigned to each index for letters which are in the word & in the right postion
//in the word but not in the right position & not in the word in any position
std::vector<std::string> color_Array(std::string const &user_word, std::string const &random_word);
std::vector<std::string> color_Array(std::string const &user_word, std::string const &random_word)
{
std::vector<std::string> color_arr; 
std::string user_word_caps;

for(int i=0;i<5; i++)
        {  
            user_word_caps[i] = (char) toupper(user_word[i]); //This will accept lower case letters and capitalize them

            if(user_word_caps[i] == random_word[i])
            {
                color_arr.push_back("green");
            }
            else if(random_word.find(user_word_caps[i]) != std::string::npos)
            {
                color_arr.push_back("yellow");
            }
            else 
            {
                color_arr.push_back("grey");
            }
        }
            return color_arr;
}


//This function assigns the color to each letter in the user word
void color_assign(std::vector<std::string> const &letter_color_Array, std::string const &user_word);
void color_assign(std::vector<std::string> const &letter_color_Array, std::string const &user_word)

{
for(int i=0; i<5; i++) //This for-loop now uses the color array to determine which color to assign to each letter
                {
                    if(letter_color_Array[i] == "green")
                    {
                        std::cout<<"\x1b[32m"<< (char) toupper(user_word[i]);
                    }

                    else if(letter_color_Array[i] == "yellow")
                    {
                        std::cout<<"\x1b[33m"<< (char) toupper(user_word[i]);
                    }

                    else //The only case left which assigns the color grey to each letter that is not in the word
                    {
                        std::cout<<"\x1b[30m"<< (char) toupper(user_word[i]);
                    }
                }
        std::cout<<"\x1b[37m"<<std::endl;
}


//This function gives the appropriate feedback based on the user word
void user_feedback(std::vector<std::string> const &letter_color_Array, std::string const &user_word);
void user_feedback(std::vector<std::string> const &letter_color_Array, std::string const &user_word)
{

    std::cout<<"\n";

for(int i=0; i<5; i++)
                {   
                    
                    if(letter_color_Array[i]=="green")
                    {
                        std::cout<<"The letter "<<(char) toupper(user_word[i])<<" is in the word and in the correct position."<<std::endl;
                    }
                    else if(letter_color_Array[i]=="yellow")
                    {
                        std::cout<<"The letter "<<(char) toupper(user_word[i])<<" is in the word but not in the right position."<<std::endl;
                    }
                    else
                    {
                        std::cout<<"The letter "<<(char) toupper(user_word[i])<<" is not in the word in any position."<<std::endl;
                    }
                }

    std::cout<<"\x1b[37m";
}






//Main program
int main()

{

std::string user_word, user_word_caps;
bool invalid_word;
std::string random_word = get_random_word();

std::cout<<"\n";
std::cout<<"Welcome to my Wordle Game!!"<<std::endl;
std::cout<<"The objective of the game is to guess the word of the day."<<std::endl;
std::cout<<"You will have 6 tries to guess the word which contains 5 letters."<<std::endl;
std::cout<<"A correct letter in the right position will be colored green."<<std::endl;
std::cout<<"A letter that is in the word but not in the correct position will be colored yellow."<<std::endl;
std::cout<<"A letter that is not in the word at all will be colored grey."<<std::endl; 

std::cout<<"\n";

std::cout<<"So lets begin!"<<std::endl;

std::cout<<"\n";

std::cout <<"Enter a 5 letter word:"<<std::endl;

for(int i = 0; i<6; i++) //This is the main for-loop for the 6 user attempts at guessing the correct word
{

std::vector<std::string> letter_color_Array; //This will assign the color to the index of each letter to the word entered by the user

do  //This do-while loops is performed until the user enters a 5 letter word
{
std::cin>>user_word;

invalid_word = check_user_word(user_word); //This function checks that the user input is valid

} 
while(invalid_word == true);

upper_case(user_word,random_word); //Converts lower case letters to upper case and compares them to the user word

letter_color_Array = color_Array(user_word,random_word); //letter_color_Array stores a vector of strings which correspond to color assigned to user_word letter

color_assign(letter_color_Array,user_word); //This assigns the correct color for each letter of the user word

user_feedback(letter_color_Array,user_word); //This assigns the correct feedback based on the user word

if (i==5) //If we've reached this point then the user has run out of attemps 
{
    std::cout<<"\n";
    std::cout<<"Sorry, you are out of tries. You can try again tomorrow. Hope you had fun!"<<std::endl;
    std::cout<<"\n";
        
    exit(EXIT_SUCCESS);
} 
    std::cout<<"\n";
}
    return 0;
}
