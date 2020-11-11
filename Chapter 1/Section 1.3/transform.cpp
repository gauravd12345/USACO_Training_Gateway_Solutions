/*
ID: icystuf1
PROG: transform
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>


using namespace std;


vector<vector<char>> rotate90(vector<vector<char>> array){
    vector<vector<char>> new_col;
    for (int i = 0; i < array.size(); i++) {
        vector<char> new_row;
        long index = array.size() - 1;
        for (int j = 0; j < array[i].size(); j++) {
            new_row.push_back(array[index][i]);
            index--;
            
        }
        new_col.push_back(new_row);
        
    }
    
    return new_col;
    
    
}


vector<vector<char>> rotate180(vector<vector<char>> array){
    vector<vector<char>> new_col;
    for (long i = array.size() - 1; i >= 0; i--) {
        vector<char> new_row;

        for (long j = array[i].size() - 1; j >= 0; j--) {
            new_row.push_back(array[i][j]);
            
            
        }
        new_col.push_back(new_row);
        
    }
    
    return new_col;
    
    
}



vector<vector<char>> rotate270(vector<vector<char>> array){
    vector<vector<char>> new_col;
    for (int i = 0; i < array.size(); i++) {
        vector<char> new_row;
        long index = 0;
        for (int j = 0; j < array[i].size(); j++) {
            new_row.push_back(array[index][array[i].size() - i - 1]);
            index++;
            
        }
        new_col.push_back(new_row);
        
    }
    
    return new_col;
    
    
}



vector<vector<char>> reflect(vector<vector<char>> array){
    vector<vector<char>> new_col;
    for (long i = 0; i < array.size(); i++) {
        vector<char> new_row;

        for (long j = array[i].size() - 1; j >= 0; j--) {
            new_row.push_back(array[i][j]);
            
            
        }
        new_col.push_back(new_row);
        
    }
    
    return new_col;
    
    
}

bool isEqual(vector<vector<char>> old_arr, vector<vector<char>> new_arr, int size){
    for (int i = 0; i < size; i++) {


        for (int j = 0; j < size; j++) {
            if(old_arr[i][j] != new_arr[i][j]){
                return false;
            }
            
            
        }

        
    }
    
    return true;
    
    
}



int main()
{
    ifstream fin("transform.in");
    ofstream fout("transform.out");

    int n;
    fin >> n;
    
    char a;
    
    vector<vector<char>> init_col;
    for (int i = 0; i < n; i++) {
        vector<char> init_row;
        for (int j = 0; j < n; j++) {
            fin >> a;
            init_row.push_back(a);
            
        }
        init_col.push_back(init_row);
    }
    
    
    char b;

    
    vector<vector<char>> fin_col;
    for (int i = 0; i < n; i++) {
        vector<char> fin_row;
        for (int j = 0; j < n; j++) {
            fin >> b;
            fin_row.push_back(b);
            
        }
        fin_col.push_back(fin_row);
    }
    
    
    vector<vector<char>> r = reflect(init_col);
    if(isEqual(fin_col, rotate90(init_col), n)){
        fout << 1 << endl;
        
    }
    else if(isEqual(fin_col, rotate180(init_col), n)){
        fout << 2 << endl;
        
    }
    else if(isEqual(fin_col, rotate270(init_col), n)){
        fout << 3 << endl;
        
    }
    
    else if(isEqual(fin_col, r, n)){
        fout << 4 << endl;
        
    }
    
    else if(isEqual(fin_col, rotate90(r), n) || isEqual(fin_col, rotate180(r), n) || isEqual(fin_col, rotate270(r), n)){
        fout << 5 << endl;
        
    }
    
    else if(isEqual(fin_col, init_col, n)){
        fout << 6 << endl;
        
    }
    
    else{
        fout << 7 << endl;
        
    }
    
    
}