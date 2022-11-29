#include <iostream>
#include <fstream>
using namespace std;

double cArray[1000][1000];
double CalcLCSLen(string &firstString, string &secondString){
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
    return cArray[rowIndex][colIndex];
}

double GetRequiredLCSLength(double percent, int shortStringLength) {
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
// TODO:change this to bool soon
bool CompareLength(double percent, int longStringLength, int shortStringLength){
    // calculate above and below limits given a percent
    double requiredLCSLength = GetRequiredLCSLength(percent, shortStringLength);
    cout << "REQUIRED LCS LENGTH " << requiredLCSLength << endl;
    double abovePercent = 1 + percent; // 1.2 OR 120%
    double belowPercent = 1 - percent; // 0.8 OR 80%
    double maxLimit = longStringLength * abovePercent;
    double minLimit = longStringLength * belowPercent;
    cout << "SHORT STRING LENGTH MUST BE > " << minLimit << " AND < " << maxLimit << endl;
    cout << "THE CURRENT SHORT STRING LENGTH IS " << shortStringLength << endl; 

    // return true if the short string is within the percent limits 
    if((shortStringLength > minLimit) & (shortStringLength < maxLimit)){ // for reference, &&, || always evaluates to true if first condition is true
        return true;                                               
    } else { 
        return false;
    }
}

bool CompareSimilarity(double percent, string firstString, string secondString) {
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
    // get what LCS length must be greater than or equal to
    double requiredLCSLength = GetRequiredLCSLength(percent, shortString.length());

    // if the LCS length is >= required length, set a true or false value 
    if (LCSLength >= requiredLCSLength) {
        LCSLengthSatisfied = true;
    } else {
        LCSLengthSatisfied = false;
    }

    stringLengthSatisfied = CompareLength(percent, longString.size(), shortString.size());
    // only returns true if both conditions are true
    cout << "DEBUG, LCS LENGTH SATISIFED:  " << LCSLengthSatisfied << endl;
    cout << "DEBUG, String LENGTH SATISIFED:  " << stringLengthSatisfied << endl;

    return (LCSLengthSatisfied & stringLengthSatisfied);
    // if() // High similarity
    // else if () // Medium similarity
    // else if () // Low similarity
    // else () // Dissimilar
} 
       
void ReadInfile(string fileName) {
    ifstream inFile;
    int numStrings;
    string inputString;
    
    if(fileName == "multiStrings.txt"){
        inFile.open(fileName);
        if(inFile.is_open()){
            inFile >> numStrings;
            
            string stringArr[numStrings][numStrings];

            //Reads the file
            for(int i = 0; i < numStrings; i++){ // for every string in the file
                
                for(int j = 0; j < numStrings; j++){ // compare that string to every other string
                inFile >> inputString;
                stringArr[i][j] = inputString;
                
                }
            }
            //prints the array
            for(int i = 0; i < numStrings; i++){
                for (int j = 0; j < numStrings; j++){
                    cout << stringArr[i][j] << " | ";
                }
            }
        }
        
    }    
}

// from what I understand, the second dimension is just the similarity between that string and the other strings
// so we need to implement the similarity function
// we can loop through every string in the file, and say "for every string in the file, iterate through the other strings
// and calculate the similarity"


// your first concern was how are we going to check similarities for every string other than itself, right?
// walk me through what the loops between 29 and 33 do

int main(){
    string a = "tgab";
    string b = "tab";
    bool c = CompareSimilarity(0.1, a, b);
    cout << c << endl;
    cout << " LCS LEN: " << CalcLCSLen(a , b) << endl;
    return 0;


    // ReadInfile("multiStrings.txt")
}
// g++ -o similarity similarity.cpp && ./similarity