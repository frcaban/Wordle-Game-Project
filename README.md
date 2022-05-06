# Wordle-Game-Project
A C++ program for the wordle game 

This C++ program simulates the wordle game from the NY Times in which the user has 6 attempts
to guess a 5 letter word each day.
The user is asked to enter a 5 letter word. For this program it is not required for the word 
entered to be a real word, however the word to match is a real word.The word can also consist
of lower case or upper case letters or a mixture of both.
The user word will then be compared to the word of the day which will be chosen at random from
a file called Wordle_Dictionary.txt which stores a library of 5 letter words. 
The user word is first checked if it is valid using a function called check_user_word which is a 
boolean function that takes in a string (which in this case would be the user word) and returns 
true if the word is invalid or false if the word is valid based on several checks of the input.
A function called color_Array then takes in 2 strings which would be the user word & random
word and compares the letters in each word and assigns a color to the user word. It does this by
returing a vector of strings which contain the words "green", "yellow" and "grey" in order to 
track the similarities & differences in the positions of the letters of both words. If the words 
are exactly the same then the user guessed the correct answer and a message is displayed and
the game is finished. If a letter in the user word is in the random word & in the same position
then the color_Array vector will assign "green" for the index position, and if a letter in the
user word is in the random word but not in the same position then color_Array will be assigned
"yellow" for this index position and if the letter is not in the random word in any position then 
the color_Array will be assigned "grey" for this index position. 
A function called color_assign takes in the string vector returned from the color_Array function   
along with a string and assigns the correct color to the letter and prints it to the screen.
A function called user_feedback then takes in string vector and a string which will be the
vector returned from the color_Array function & the user word and provides the user with feedback 
informing them which letters are in the random word and in the same position, which letters are
in the random word but not in the same position & which words are not in the random word in any
position. 
The user will have 6 attempts after which the program will end.

The test program is called Wordle_Game_Project_Test.cpp and it has 3 tests using assert statements.
The first test checks that the random word selected by the get_random_word function contains 5 
elements. The second test checks that user_word also contains 5 elements as well as the last
test which checks that letter_color_Array contains 5 elements. To use it you can just type
'make Wordle_Game_Project_Test' then type ./Wordle_Game_Project_Test. It will ask you to enter
a word. Once you enter a word it will then conduct these tests and will ouput "All tests passed."
if no problems were encountered. To play the game you can type make Wordle_Game_Project then
type ./Wordle_Game_Project and enter a word. 
