/*********************************************************************************
  Student Name: Bradley Love
  File Name: CommonSub.hpp
  Assignment number 5
  Desc: Responsible for defining methods used to generate the LCS of two strings
**********************************************************************************/
#include<iostream>
#include<fstream>
#include<cstring>
#include "CommonSub.hpp"
using namespace std;



/*
*reads input file
*/
void CommonSub::ReadInfile(string fileName){
    ifstream inFile;
    string inputString1;
    string inputString2;


    if(fileName == "twoStrings.txt"){
        inFile.open(fileName);
        
        if(inFile.is_open()){
            inFile >> inputString1;

            inFile >> inputString2;

             PrintLCS(inputString1, inputString2);
        }

    }
        else{
            cout << "file not found" << endl;
        }
    inFile.close();
}

/*
*calculates the LCS
*/
string CommonSub::FindLCS(string &firstString, string &secondString){
    int rowIndex = firstString.length();
    int colIndex = secondString.length();
    int lcsIndex;


    for (int i=0; i <= rowIndex; i++){
        for (int j=0; j <= colIndex; j++){
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

    lcsIndex = cArray[rowIndex][colIndex];

    char commSubsequence[lcsIndex + 1];
    commSubsequence[lcsIndex] = '\0';

    int i = rowIndex;
    int j = colIndex;

    while((i > 0) && (j > 0)){
        if(firstString[i - 1] == secondString[j - 1]){
            commSubsequence[lcsIndex - 1] = firstString[i - 1];
            i -= 1;
            j -= 1;
            lcsIndex -= 1;

        }
        else if(cArray[i - 1][j] > cArray[i][j-1]){
            i -= 1;
        }
        else{
            j-= 1;
        }
        
    }
    return commSubsequence;
}

void CommonSub::PrintLCS(string firstString, string secondString){

    cout << "String 1: " << firstString << endl;
    cout << "String 2: " << secondString << endl;
    cout << "LCS of both strings: " << FindLCS(firstString, secondString) << endl;
}