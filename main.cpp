/***************************************************************
  Student Name: Bradley Love
  File Name: main.cpp
  Assignment number 5
  Desc: Responsible for calling methods to run the program
*********************************************************************/
#include "CommonSub.hpp"
#include "Similarity.hpp"
#include<iostream> //  expected nested-name-specifier before ‘namsepsace’
using namespace std;


int main(){
    CommonSub c1;
    Similarity s1;
    cout << "---------Checking the LCS of two strings-----------------------------------------------" << endl;
    c1.ReadInfile("twoStrings.txt");
    cout << "---------------------------------------------------------------------------------------" << endl;
    
    //cout << "------------Calculating the degree of similaritiy among strings---------" << endl;
    s1.ReadInfile("multiStrings.txt");
    //cout << "---------------------------------------------------------------------------" << endl;
  
  

    
  return 0;
}
