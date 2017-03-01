#include<cstring>
#include<iostream>
using namespace std;


int main() {

    char dic[30] ; 
    char w1[20] ;
    char w2[20] ;
    int len1 ; 
    int len2 ; 

    cout<<"Welcome to CS 106B Word Ladder."<<endl ; 
    cout<<"Please give me two English words, and I will change the " <<endl ; 
    cout<<"first into the second by changing one letter at a time."<<endl ; 
    cout<<"Dictionary file name?"<<endl ;
    
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
