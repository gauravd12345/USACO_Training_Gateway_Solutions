/*
ID: icystuf1
PROG: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>


using namespace std;

int checkChar(char letter){
    if(letter == 'A' || letter == 'B' || letter == 'C'){
        return 2;


    }

    else if(letter == 'D' || letter == 'E' || letter == 'F'){
        return 3;


    }

    else if(letter == 'G' || letter == 'H' || letter == 'I'){
        return 4;


    }

    else if(letter == 'J' || letter == 'K' || letter == 'L'){
        return 5;


    }

    else if(letter == 'M' || letter == 'N' || letter == 'O'){
        return 6;


    }

    else if(letter == 'P' || letter == 'R' || letter == 'S'){
        return 7;


    }

    else if(letter == 'T' || letter == 'U' || letter == 'V'){
        return 8;


    }

    else if(letter == 'W' || letter == 'X' || letter == 'Y'){
        return 9;


    }




}

int main()
{
    ifstream fin("namenum.in");
    ifstream dict("dict.txt");

    ofstream fout("namenum.out");

    double num;
    fin >> num;

    int len = 0;
    while(num > 1){
        num /= 10;
        len++;

    }

    num *= pow(10, len);

    string line;

    vector<string> found;
    if (dict.is_open())
    {

        while (getline (dict, line) )
        {
            double count = 0;

            if(line.size() == len){
                for(int x = 0; x < len; x++){

                    count += checkChar(line[x]) * pow(10, len - x - 1);
                }
                if(count == num){
                    found.push_back(line);

                }
                
            }
            

        }
        dict.close();
    }

    if(!found.empty()){
        for(string s: found){
            fout << s << endl;
        }

    }
    else{
        fout << "NONE" << endl;

    }

    
}



