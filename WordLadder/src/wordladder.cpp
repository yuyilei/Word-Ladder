// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "stack.h"
#include "simpio.h"
#include "queue.h"
#include "map.h"
#include "vector.h"
#include <stack>

using namespace std;

string lower( string s ){

    for ( int i = 0 ; i < s.length() ; i++ )
        s[i] = tolower(s[i]) ;
    return s ;
}

int vaild(Vector<string> & lines , string s) {


    int flag = 0 ;
    for ( int i = 0 ; i < lines.size()  ; i++){
    
        if (lines[i] == s ){
        
            flag = 1 ;
            break ; 
        }
    }
    return flag ;
}

int main() {

    string dic ; 
    string w1 ;
    string w2 ;
    ifstream in ; 
    int flag = 0 ;
    Vector<string> lines ;
    
    cout << "Welcome to CS 106B Word Ladder." << endl ;
    cout << "Please give me two English words, and I will change the " << endl ;
    cout << "first into the second by changing one letter at a time." << endl ;
    cout << "Dictionary file name?" << endl ;

    while ( true ){   // 打开字典文件
    
        cin >> dic ;
        in.open(dic.c_str()) ;
        if ( in.fail() ) {
        
            cout << "Unable to open that file.  Try again." << endl ;
            in.clear() ;
        }

        else { 
    
            while (true) {
            
                string line ;
                getLine(in,line) ;
                if (in.fail()) 
                    break ;
                else 
                    lines.add(line) ;
            }
        
            break ;
        }
    }


    while ( true ){
    cout << "Word #1 (or Enter to quit):" << endl ;
    cin >> w1 ;
    cout << "Word #2 (or Enter to quit):" << endl ;
    cin >> w2 ;
//    cout << "Have a nice day." << endl ;
    
    if ( w1.length() != w2.length() ) {
    
        cout << "The two words must be the same length." << endl ;
        continue ;
    }

    else {
    
        if ( vaild(lines,w1) == 0 || vaild(lines,w2) == 0){
            cout << "The two words must be found in the dictionary."  << endl ;
            continue ;
            } 

        else {
        
            if ( w1 == w2 ) {
            
                cout << "The two words must be different." << endl ;
                continue ;
            }

            else {
            
                if ( w1[0] == 'Q' ) {
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
        Queue<Stack<string>> queue ;
        Stack<string> stack ;
        stack.push(w1) ;
        Stack<string> res ;
        queue.enqueue(stack) ;
        Map<string,int> found ;
        int j = 1 ;
        found.put(w1,1) ;
        int flag2 = 0 ;

        while ( !queue.isEmpty() ) { 
        
            stack = queue.dequeue() ;
            string str = stack.peek() ;
            for ( int i = 0 ; i < str.length() ; i++) {
            
                string output = str ;

                for ( int c = 97 ; c <= 122 ; c++) {
                   
                      output[i] = char(c) ;

                   if ( output != str && vaild(lines,output ) == 1   ) {
                    
                            if ( output == w2 ) {
                            
                              //  found.put(output,j++) ;

                                Stack<string> res = stack ;
                               // cout << "stack " << stack.size() << endl ;
                                res.push(w2) ;
                                //cout << output << endl ;
                                flag2 = 1;
                                 while (res.size() ){

                                        string a = res.pop() ;
                                        cout << a << endl ;

                                     }
                               //cout << "1" << endl ;
                                break ;
                            }

                            else {
                            
                             //   found.put(output,j++) ;
                                Stack<string> copy ;
                                copy =  stack ;
                                copy.push(output) ;
                                queue.enqueue(copy) ; 
                               // cout << output << endl ;
                            }
                        } 
                    }

            if ( flag2 == 1) {
                break ;
             //   cout << "1" << endl ;
                }
            }

            if  (flag2 ==  1)
                break ;
       }

/*        cout << res.size() << endl ;
        while ( res.size() != 0 ) {
        
            string out = res.pop() ;
            cout << out << endl ;
        }
*/
    }
    return 0;
}
