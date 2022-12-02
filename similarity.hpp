/*********************************************************************************
  Student Name: Bradley Love
  File Name: similarity.hpp
  Assignment number 5
  Desc: Responsible for declaring methods used to compare how similar two strings are to eachother
**********************************************************************************/
#ifndef SIMILARITY_H
#define SIMILARITY_H
#include<iostream>
using namespace std;

class Similarity {
    private:
       

    public:
       /*
       * Calculates the length of the LCS
       */
       double CalcLCSLen(string &firstString, string &secondString);

       /*
       * Returns the required length the LCS needs to be to meet a condtion
       */
       double GetRequiredLCSLength(double percent, int shortStringLength);

       /*
       *Compares the lengths of multiple strings
       */
       bool CompareLength(double percent, int longStringLength, int shortStringLength);

       /*
       *Runs calculations to check if the conditions for similarities are met, returns true or false
       */
       bool CompareSimilarity(double percent, string firstString, string secondString);

       /*
       *Returns a character representing which similarity case was met
       */
       char EvaluateStringSimilarity(string firstString, string secondString);

       /*
       *Reads an input file
       */
       void ReadInfile(string fileName);

};

#endif