#include <iostream>
#include <string>

using namespace std;

string decrypt( const string& word ) 
{
  int currentPos;
  char prev;
  char currentChar;
  int wordSize = word.size();
  // your code goes here
  string decrypted;
  if(wordSize == 0)
    return decrypted;
  
  currentChar = word[0] - 1;
  prev        = word[0]; 
  decrypted   = decrypted + currentChar;
  //cout<<decrypted<<endl;
  currentPos = 1;
  while(currentPos < wordSize)
  {
     int value = (26 - (prev % 26)) + (int)word[currentPos]; 
     if(value > (int)'z')
       value = value - 26;
     currentChar = (char)value;
     //cout<<"prev"<<prev<<endl;
     if(currentChar - 'a' > 25)
     {
       cout<<"greater"<<currentChar<<endl;
       currentChar = currentChar - 26;
     }
     decrypted   = decrypted + currentChar;
     prev = word[currentPos];
     currentPos++;
    
    //cout<<(int)currentChar<<endl;
     
  }
  return decrypted;
}

int main() {
  cout<<decrypt("dnotq")<<endl;
  return 0;
}

