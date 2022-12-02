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

double Similarity::GetRequiredLCSLength(double percent, int shortStringLength) {
    // function that, given the short string length and the percent used to calculate similarity
    // calculates what required LCS length the program requires, see `projDesc.txt`
    // for example, when the precent is 10% for high similarity, the LCS must be >= 90% of the short
    // string length (see projDesc line 65)
    double LCSLength;
    double doubleShortLength = (double)shortStringLength;
    if (percent == 0.1) {                    // when percent = 10% [HIGH SIMILARITY]
        LCSLength = doubleShortLength * 0.9; // required LCS = 90% of short string length
    } else if (percent == 0.2) {             // when percent = 20% [MEDIUM SIMILARITY]
        LCSLength = doubleShortLength * 0.8; // required LCS = 80% of short string length
    } else if (percent == 0.4) {             // when percent = 20% [LOW SIMILARITY]
        LCSLength = doubleShortLength * 0.5; // when percent = 10%, required LCS is 90% of short string length
    }
    // @TODO: may need to add the logic for dissimilar
    return LCSLength;
}

bool Similarity::CompareLength(double percent, int longStringLength, int shortStringLength){
    // calculate above and below limits given a percent
    double requiredLCSLength = GetRequiredLCSLength(percent, shortStringLength);
    // cout << "REQUIRED LCS LENGTH " << requiredLCSLength << endl;
    double abovePercent = 1 + percent; // 1.2 OR 120%
    double belowPercent = 1 - percent; // 0.8 OR 80%
    double maxLimit = longStringLength * abovePercent;
    double minLimit = longStringLength * belowPercent;
    // cout << "SHORT STRING LENGTH MUST BE > " << minLimit << " AND < " << maxLimit << endl;
    // cout << "THE CURRENT SHORT STRING LENGTH IS " << shortStringLength << endl; 

    // return true if the short string is within the percent limits 
    if((shortStringLength > minLimit) & (shortStringLength < maxLimit)){ // for reference, &&, || always evaluates to true if first condition is true
        return true;                                               
    } else { 
        return false;
    }
}


bool Similarity::CompareSimilarity(double percent, string firstString, string secondString) {
    string longString;
    string shortString;
    bool LCSLengthSatisfied;
    bool stringLengthSatisfied;

    // check which string is longer
    if(firstString.length() > secondString.length()){
        longString = firstString;
        shortString = secondString;
    } else {
        longString = secondString;
        shortString = firstString;
    }

    // get LCS Length
    int LCSLength = CalcLCSLen(firstString, secondString);
    
    // get what LCS length must be greater than or equal to: 
    double requiredLCSLength = GetRequiredLCSLength(percent, shortString.length());

    // if the LCS length is >= required length, set a true or false value 
    if (LCSLength >= requiredLCSLength) {
        LCSLengthSatisfied = true;
    } else {
        LCSLengthSatisfied = false;
    }
    
    stringLengthSatisfied = CompareLength(percent, longString.size(), shortString.size());
    // only returns true if both conditions are true
    // cout << "DEBUG, LCS LENGTH SATISIFED:  " << LCSLengthSatisfied << endl;
    // cout << "DEBUG, String LENGTH SATISIFED:  " << stringLengthSatisfied << endl;

    return (LCSLengthSatisfied & stringLengthSatisfied);
    
} 

char Similarity::EvaluateStringSimilarity(string firstString, string secondString) {
     //cout << "\n---- CHECKING FOR HIGH SIMILARITY --- " << endl;
    bool highSimilarity = CompareSimilarity(0.1, firstString, secondString);
    //cout << "\n---- CHECKING FOR MEDIUM SIMILARITY --- " << endl;
    bool mediumSimiliarity = CompareSimilarity(0.2, firstString, secondString);
     //cout << "\n---- CHECKING FOR LOW SIMILARITY --- " << endl;
    bool lowSimilarity = CompareSimilarity(0.4, firstString, secondString);
    if(highSimilarity) {
        return 'H';
    } else if(mediumSimiliarity) {
        return 'M';
    } else if(lowSimilarity) {
        return 'L';
    } else{
        return 'D';
    }
}

void Similarity::ReadInfile(string fileName) {
    ifstream inFile;
    int numStrings;
    string inputString;
    string temp;
    // string stringArr[];
    
    if(fileName == "multiStrings.txt"){
        inFile.open(fileName);
        if(inFile.is_open()){
            inFile >> numStrings;
            string stringArr[numStrings];

           // for(int i = 0; i < numStrings; i++){ // for every string in the file
               // inFile >> temp; // read a line from the file
                // cout << "NEW ITERATION IN FIRST LOOP WITH STRING " << temp << endl;
                //stringArr[i] = temp;
           // }
           // for (int a = 0; a<numStrings; a++) { // for every string in the array @TODO: fix this
                //for (int b = 0; b < numStrings -1; b++){ // take that string and check similarity between others
                //char sim = EvaluateStringSimilarity(stringArr[a], stringArr[a+1]);
                //cout << "SIMILIARTY BETWEEN " << stringArr[a] << " AND " << stringArr[a+1] << ": " << sim << endl;
               // }
            //}

            //TODO: note: creating the matrix format for printing
            //TODO: DELETE ALL THE COMMENTED OUT CODE
            
              char simularityMatrix[numStrings][numStrings] =   {{'H', 'D', 'M', 'D', 'M', 'D' , 'H', 'H',},
                                                        {'D','H', 'D', 'M', 'D', 'D', 'M', 'M',},
                                                        {'H','M', 'M', 'D', 'H', 'D', 'D', 'D',},
                                                        {'D','H', 'D', 'M', 'D', 'D', 'M', 'M',},
                                                        {'D','H', 'D', 'M', 'D', 'D', 'M', 'M',},
                                                        {'D','H', 'D', 'M', 'D' ,'D', 'M', 'M',},
                                                        {'D','H', 'D', 'M', 'D' ,'D', 'M', 'M',},
                                                        {'D','H', 'D', 'M', 'D' ,'D', 'M', 'M',}};
            //string rowStrings[3];
            //string colStrings[3];
            for(int a = 0; a < numStrings; a++){
                //inFile >> temp;
                //char sim = EvaluateStringSimilarity(stringArr[a], stringArr[a+1]);
               //stringMatrix[a] = "a";
               //inFile >> inputString;
               //rowStrings[a] = inputString;
              
                for(int b = 0; b < numStrings; b++){
                     //inFile >> inputString;
                     //colStrings[b] = inputString;
                    //stringMatrix[b] = "b";
                    if(a > b){
                        cout << "-" << " ";
                    }
                    else{
                       
                        
                        //charMat[a][b] = EvaluateStringSimilarity[][]
                        cout << simularityMatrix[a][b] << " ";
                       
                    }
                    
                }
                  cout << endl;
            }
        


        //int arr[2][2] = {
    //{1,2},
    //{3,4},
    //};
   /*string arr[2][2];

    string elem;
    for (int i = 0;i < 2;i++){
        inFile >> elem;
        //arr[i] = elem;
        for(int j = 0;j < 2;j++){
            //arr[j] = elem
            //Now you're on the first element
            // I have used a size of 2, but you can use whatever size you want
           //elem = arr[i][j];
           arr[i][j] = elem;
            for (int a = 0;a < 2;a++){
                for(int b = 0;b < 2;b++){
                    if (arr[a][b] == elem) continue;
                    //Do whatever you want now;
                    std::cout << "Comparing " << elem << " with " << arr[a][b] << "\n";
                }
            }

        }
    }*/



       // for (int i = 0; i < 3; i++){
            //for (int j = 0; j < 3; j++) {
                //if (i > j) {
                //cout << "-" << " ";
           // }
            //else{
           // cout << matrix[i][j] << " ";
            //}
        //}
       // cout << endl;
   // }

            
                // for(int j = 0; j < 1; j++){ // compare that string to every other string
                //     inFile >> inputString;
                //     // cout << "COMPARING " << temp << " TO " << inputString << endl;
                //     char similarity = EvaluateStringSimilarity(temp, inputString);
                //     cout << "SIMILARITY FOR " << temp << " AND " << inputString << " IS: " << similarity << endl;
                    
                //      //stringArr[i][j] = inputString;
                
                // }
            }
            inFile.close();

        }
    
    }    


/*
START FILE
---------
1
2
3
END FILE
---------

FIRST FOR LOOP -> READS LINE BY LINE UNTIL END OF FILE (1, 2, 3) !!! ENDS ONLY WHEN SECOND FOR LOOP IS DONE !!!
GIVES ACCESS TO NUMBER THE LOOP IS ON
|    
 -----> SECOND FOR LOOP: GIVEN THAT NUMBER, LOOP THROUGH THE FILE AGAIN (1,2,3) !!! ENDS ONLY WHEN THE NUMBER IS COMPARED TO ALL !!!



EXAMPLE
---------
for (int i=0; i <= numbersInFile; i++) { // 

    for (int j=0; j <= numbersInFile; j++) // loop through all other numbers, getting the sum 
        cout << i + j << endl;
        evaluate the similarity of both strings (call them x and y for now)
        put the result of the function call into arr[i][j] and print
    }
*/
// loop through all strings in input file and get a string
// take that string and loop through all the other strings 
//Print similarity in upper-triangle matrix form

