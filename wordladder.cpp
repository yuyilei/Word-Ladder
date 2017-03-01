#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;


int main() {

    string dic ; 
    string w1 ;
    string w2 ;
    int len1 ; 
    int len2 ; 
    ifstream infile ;
    ofstream outfile ;

    cout<<"Welcome to CS 106B Word Ladder."<<endl ; 
    cout<<"Please give me two English words, and I will change the " <<endl ; 
    cout<<"first into the second by changing one letter at a time."<<endl ; 
    cout<<"Dictionary file name?"<<endl ;
    
    infile.open(dic.c_str()) ; 

    if (infile.fail() ) {
        Error("Could not open the file!! ") ;
        infile.fail() ;
        }

    cin>>dic ;
    
    cout<<"Word #1 (or Enter to quit): "<<endl ; 
    cin>>w1 ;
    cout<<"Word #2 (or Enter to quit): "<<endl ; 
    cin>>w2 ;

    len1 = strlen(w1) ;
    len2 = strlen(w2) ;

    if (len1 != len2 )
        cout<<"The two words must be the same length."<<endl; 

    return 0 ; 
}
