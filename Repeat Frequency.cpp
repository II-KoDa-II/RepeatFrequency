/***********************
*                      *
*  Кофф Даниил ПИ-221  *
*  Вариант 12          *
*  Частота повторений  *
*                      *
***********************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  ifstream file;
  string lineBuffer;
  char letterBuffer;
  struct letterCount {
    char letter;
    int repeats = 0;
  };
  letterCount letter[1000];
  struct doubleLetterCount {
    char letter1;
    char letter2;
    int repeats = 0;
  };
  doubleLetterCount doubleLetter[1000];
  int index1;
  int index2;
  int index3;
  int maxIndex1 = 0;
  int maxIndex2 = 0;
  int buffer1 = 0;
  int buffer2 = 0;
  int doubleFrequency = 0;
  
  file.open("Greek Alphabet");
  
  if (!file.is_open()) {
    cout << "File missing";
    
    return 1;
  }
  
  while (getline(file, lineBuffer)) { 
    for (index1 = 0; index1 < lineBuffer.length(); ++index1) {
      lineBuffer[index1] = toupper(lineBuffer[index1]);
      
      if (isalpha(lineBuffer[index1])) {
        for (index2 = 0; index2 < maxIndex1; ++index2) {
          if (lineBuffer[index1] == letter[index2].letter) {
            ++buffer1;
            ++letter[index2].repeats;
            
            break;
          }
        }
        
        for (index3 = 0; index3 < maxIndex2; ++index3) {
          if (lineBuffer[index1] == doubleLetter[index3].letter2 && letterBuffer == doubleLetter[index3].letter1 && isalpha(letterBuffer)) {
            ++buffer2;
            ++doubleLetter[index3].repeats;
            
            break;
          }
        }
        
        if (buffer1 == 0) {
          letter[index2].letter = lineBuffer[index1];
          ++maxIndex1;
        }
        else {
          --buffer1;
        }
        
        if (buffer2 == 0) {
          doubleLetter[index3].letter2 = lineBuffer[index1];
          doubleLetter[index3].letter1 = letterBuffer;
          ++maxIndex2;
        }
        else {
          --buffer2;
        }
      }
      letterBuffer = lineBuffer[index1];
    }
  }
  
  file.close();
  
  for (index1 = 0; index1 < maxIndex1; ++index1) {
    if (letter[index1].repeats > 0) {
      cout << "Frequency of letter " << letter[index1].letter << " repeats: " << letter[index1].repeats << "\n";
    }
  }
  
  cout << "\n";
  
  for (index1 = 0; index1 < maxIndex2; ++index1) {
    if (doubleLetter[index1].repeats > 0) {
      cout << "Frequency of combination " << doubleLetter[index1].letter1 << doubleLetter[index1].letter2 << " repeats: " << doubleLetter[index1].repeats << "\n";
    }
  }
  
  return 1;
}
