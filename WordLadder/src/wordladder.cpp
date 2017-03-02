// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "console.h"

using namespace std;

string lower( string s ){

    for ( int i = 0 ; i < s.lenght() ; i++ ) 
        s[i] = tolower(s[i])
    return s ;
}

int main() {

    string dic ; 
    string w1 ;
    string w2 ;
    ifstream in ; 
    int flag = 0 ;
    
    cout << "Welcome to CS 106B Word Ladder." < endl ;
    cout << "Please give me two English words, and I will change the " << endl ;
    cout << "first into the second by changing one letter at a time." << endl ;

    while ( true ){   // 打开字典文件
    
        cin >> dic ;
        in.open(dic.c_str()) ;
        if ( in.fail() ) {
        
            cout << "Unable to open that file.  Try again." << endl ;
        }

        else {
        
            break ;
        }
    }


    while ( true ){
    cout << "Word #1 (or Enter to quit):" << endl ;
    cin >> w1 ;
    cout << "Word #2 (or Enter to quit):" << endl ;
    cin >> w2 ;
    cout << "Have a nice day." << endl ;
    
    if ( w1.length != w2.length ) {
    
        cout << "The two words must be the same length." << endl ;
        continue ;
    }

    else {
    
        Lexicon dict(dic) ;
        if ( !dict.containsWord(w1) || !dict.containsWord(w2) ){
            cont << "The two words must be found in the dictionary."  << endl ; 
            continue ;
            } 

        else {
        
            if ( w1 == w2 ) {
            
                cout << "The two words must be different." << endl ;
                continue ;
            }

            else {
            
                if ( w1 == 'Q' || w2 == 'Q') {
                
                    cout << "Have a nice day." << endl; 
                    break ;
                }

                else {
                
                    flag = 1 ;
                    break ;
                }
            }
        }
    }
 }  
    
    if ( flag == 1 ) { 
        w1 = lower(w1) ;
        w2 = lower(w2) ;
        cout << "A ladder from " << w2 << " back to " << w1 << ":" << endl ;
        Lexicon dict(dic) ;
        Queue<stack> queue ; 
        Stack<string> stack ;
        Stack<string> temp ;
        stack.push(w1) ;
        queue.enqueue(stack) ;
        

        while ( !queue.isEmpty() ) {
        
            temp = queue.dequeue() ;
            string str = temp.peek() ;

            int len = str.strlen() ;
            for ( i = 0 ; i < len ; i++) {
            
                char tmp = str[i] ;
                for ( char c = 'a' ; c <= 'z' ; c++) {
                
                    if ( c == tmp )
                        continue ;
                    str[i] = c ;
                    if ( !dict.containsWord(str) ) 
                        continue ;
                    else {
                    
                        if  has not already been used in a ladder before {
                        
                            if ( str == w2 ) {
                            
                                new  a stack ?
                            }

                            else {
                            
                                stack<string> rela = temp ; // copy ;
                                rela.push(str) ;
                                queue.enqueue(rela) ; 
                            }
                        } 
                    }

                }
            }

        }

  }
    long min = 10000000 ;
    stack<string> mini ;
    while ( !queue.isEmpty() ){
    
        temp = queue.dequeue() ;
        if ( temp.size() < mini ){
            min = temp.size() ;
            mini = temp ;
       }
        
    }


    return 0;

   
}
