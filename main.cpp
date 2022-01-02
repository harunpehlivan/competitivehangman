#include <iostream>
#include <string>
#include <vector>
using namespace std;
string word, oword, inc, inc2;
string hanged = "___\n| O\n|/|\\\n| |\n|/ \\";
string current = "";
int j=0;
string calc(string g){
  string output, now;
  size_t finding = word.find(g);
  if (finding != string::npos) {
    word = word.erase(finding, 1);
    now = oword + g;
    oword = now;
    output = "Correctly guessed: " + oword;
  } else {
    inc2 = inc+g;
    inc = inc2;
    output = "Not in the word.";
  }
  current = current + hanged[j] + hanged[j+1];
  j+=2;
  return output +"\n"+ current +"\n";
}
int main() {
  int won = 0;
  inc = "";
  cout << "Welcome to competitive hangman!\nHow to play: There are three players. One decides a word, the other two are trying to guess it.\nPlease note: If a letter is repeated multiple times in the word, you must guess multiple times to get them all.\nGood luck!\n";
  cout << "What is the word you want them to guess?\nPlease do it in lowercase characters.\n";
  string guess2 ,guess, M, a;
  getline(cin, word);
  oword = "";
  a = word;
  system("clear");
  cout << "Length:\n" << word.length() <<"\nPress ENTER to start.";
  cin.ignore();
  while(true){
    cout << "Player 1's turn! Place your guess:\n";
    getline(cin,guess);
    system("clear");
    M = calc(guess);
    cout << M << "\n" << "Incorrect: " << inc << "\n";
    if((word=="")||(current.find(hanged)!=string::npos)){
      if (!(current.find(hanged)!=string::npos)){
        won = 1;
      }
      break;
    }
    cout << "Player 2's turn! Place your guess:\n";
    getline(cin,guess2);
    system("clear");
    M = calc(guess2);
    cout << M << "\n" << "Incorrect: " << inc << "\n";
    if((word=="")||(current.find(hanged)!=string::npos)){
      if (!(current.find(hanged)!=string::npos)){
        won = 2;
      }
      break;
    }
  }
  cout << "The word: " << a << "\n" << "Player " << won << " won\n";
  return 0;
}