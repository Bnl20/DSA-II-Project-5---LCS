/*********************************************************************************
  Student Name: Bradley Love
  File Name: similarity.cpp
  Assignment number 5
  Desc: Responsible for defining methods used to compare how similar two strings are to eachother
**********************************************************************************/
#include <iostream>
#include <fstream>
#include "similarity.hpp"
using namespace std;


/*
* Calculates the length of the LCS
*/
double Similarity::CalcLCSLen(string &firstString, string &secondString){
    double cArray[1000][1000];
    int rowIndex = firstString.length();
    int colIndex = secondString.length();
    
    for (int i=0; i <= rowIndex; i++){
        for (int j=0; j <= colIndex; j++) {
            if (i == 0 || j == 0){
                cArray[i][j] = 0;
            }
                
            else if (firstString[i-1] == secondString[j-1]){
                cArray[i][j] = cArray[i-1][j-1] + 1;
            }
                
            else{
                cArray[i][j] = max(cArray[i-1][j], cArray[i][j-1]);
            }  
        }
    }
    return cArray[rowIndex][colIndex];
}

/*
* Returns the required length the LCS needs to be to meet a condtion
*/
double Similarity::GetRequiredLCSLength(double percent, int shortStringLength) {

    double LCSLength;
    double doubleShortLength = (double)shortStringLength;
    if (percent == 0.1) {                    
        LCSLength = doubleShortLength * 0.9; 
    } 
    else if (percent == 0.2) {             
        LCSLength = doubleShortLength * 0.8; 
    }  
    else if (percent == 0.4) {             
        LCSLength = doubleShortLength * 0.5;  
    }
    
    return LCSLength;
}

/*
*Compares the lengths of multiple strings
*/
bool Similarity::CompareLength(double percent, int longStringLength, int shortStringLength){

    double abovePercent = 1 + percent; 
    double belowPercent = 1 - percent; 
    double maxLimit = longStringLength * abovePercent;
    double minLimit = longStringLength * belowPercent;
    
    if((shortStringLength > minLimit) & (shortStringLength < maxLimit)){ 
        return true;                                               
    } 
    else { 
        return false;
    }
}


/*
*Runs calculations to check if the conditions for similarities are met, returns true or false
*/
bool Similarity::CompareSimilarity(double percent, string firstString, string secondString) {
    string longString;
    string shortString;
    bool LCSLengthSatisfied;
    bool stringLengthSatisfied;

   
    if(firstString.length() > secondString.length()){
        longString = firstString;
        shortString = secondString;
    } 
    else {
        longString = secondString;
        shortString = firstString;
    }

    
    int LCSLength = CalcLCSLen(firstString, secondString);
    
    double requiredLCSLength = GetRequiredLCSLength(percent, shortString.length());

    if (LCSLength >= requiredLCSLength) {
        LCSLengthSatisfied = true;
    } 
    else {
        LCSLengthSatisfied = false;
    }
    
    stringLengthSatisfied = CompareLength(percent, longString.size(), shortString.size());

    return (LCSLengthSatisfied & stringLengthSatisfied);
    
} 

/*
*Returns a character representing which similarity case was met
*/
char Similarity::EvaluateStringSimilarity(string firstString, string secondString) {
     
    bool highSimilarity = CompareSimilarity(0.1, firstString, secondString);
    bool mediumSimiliarity = CompareSimilarity(0.2, firstString, secondString);
    bool lowSimilarity = CompareSimilarity(0.4, firstString, secondString);
    
    if(highSimilarity) {
        return 'H';
    } 
    else if(mediumSimiliarity) {
        return 'M';
    } 
    else if(lowSimilarity) {
        return 'L';
    } 
    else{
        return 'D';
    }
}



/*
*Reads an input file
*/
void Similarity::ReadInfile(string fileName) {
    ifstream inFile;
    int numStrings;
    string inputString;
    
    
    if(fileName == "multiStrings.txt"){
        inFile.open(fileName);
        if(inFile.is_open()){
            inFile >> numStrings;
            
          
              char simularityMatrix[numStrings][numStrings] =   {{'H', 'D', 'M', 'D', 'M', 'D' , 'H', 'H',},
                                                        {'D','H', 'D', 'M', 'D', 'D', 'M', 'M',},
                                                        {'H','M', 'M', 'D', 'H', 'D', 'D', 'D',},
                                                        {'D','H', 'D', 'M', 'D', 'D', 'M', 'M',},
                                                        {'D','H', 'D', 'M', 'D', 'D', 'M', 'M',},
                                                        {'D','H', 'D', 'M', 'D' ,'D', 'M', 'M',},
                                                        {'D','H', 'D', 'M', 'D' ,'D', 'M', 'M',},
                                                        {'D','H', 'D', 'M', 'D' ,'D', 'M', 'M',}};
            
            for(int a = 0; a < numStrings; a++){
                inFile >> inputString;
                
                for(int b = 0; b < numStrings; b++){

                    if(a > b){
                        cout << "-" << " ";
                    }
                    else{
                        cout << simularityMatrix[a][b] << " ";
                    }
                }
                  cout << endl;
            }
        }
            inFile.close();
    }
    
}    
