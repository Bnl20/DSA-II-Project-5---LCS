#ifndef COMMONSUB_H
#define COMMONSUB_H
#include<string>
using namespace std;

class CommonSub{
    private:
        string stringToCheck;

        int row;

        int col;

        /*
        * "c" 2d array to store the length of the LCS
        */
       int cArray[1000][1000];

    public:
        /*
        *default constructor
        */
        CommonSub();

       /*
       *overloaded constructor
       */
        CommonSub(string stringToCheck);

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