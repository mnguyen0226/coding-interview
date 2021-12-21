// string_count.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Challenge: Write a function that count number of word, vowel, and consonant in a sentence

#include <iostream>
#include <string>

using namespace std;

void counter(string s) {
    int num_word = 0;
    int num_vowel = 0;
    int num_cons = 0;

    // lowercase the string first
    string::iterator it;
    string new_s;
    for (it = s.begin(); it != s.end(); it++) {
        new_s.push_back(tolower(*it));
    }

    // For word, use tokenizer
    // For vowel, consonant, we will use iterator 
    for (int i = 0; new_s[i] != '\0'; i++) {
        if (new_s[i] == 'a' || new_s[i] == 'o' || new_s[i] == 'u' || new_s[i] == 'e' || new_s[i] == 'i') {
            num_vowel++;
        }
        else if (new_s[i] == ' ') {
            num_word++;
        }
        else {
            num_cons++;
        }
    }

    cout << num_vowel << endl;
    cout << num_word << endl;
    cout << num_cons << endl;

}

int main()
{
    std::cout << "Count word, consonant, vowel\n";
    string s = "Hello, my name is Minh";

    counter(s);

    return 0;
}
