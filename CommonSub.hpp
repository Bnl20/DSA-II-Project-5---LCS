/*********************************************************************************
  Student Name: Bradley Love
  File Name: CommonSub.hpp
  Assignment number 5
  Desc: Responsible for declaring methods used to generate the LCS of two strings
**********************************************************************************/
#ifndef COMMONSUB_H
#define COMMONSUB_H
#include<string>
using namespace std;

class CommonSub{
    private:
     

        /*
        * "c" 2d array to store the length of the LCS
        */
       int cArray[1000][1000];

    public:
    

       /*
       *reads input file
       */
        void ReadInfile(string fileName);

        /*
        *finds the LCS of two strings
        */
        string FindLCS(string &firstString, string &secondString);

        /*
        *print the lcs
        */
        void PrintLCS(string firstString, string secondString);
};
#endif