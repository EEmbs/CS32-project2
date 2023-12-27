 //
//  main.cpp
//  project2
//
//  Created by Eileen on 2023/10/13.
//

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

//  returns the remainder of two positive integers, m and n
//  m might be 0, n won't
int modulo( unsigned int m, unsigned int n ){
    if (m < n) {
        return m;
    }else{
        return modulo(m-n, n);
    }
}

/*
int modulo( unsigned int m, unsigned int n ){
    int result = 1;
    if (m < n) {
        result = m
    }else{
        result = modulo(m-n, n);
 
    return result;
 */

// returns the number of occurrences of d in number
// d and number may be 0
int occurrences( int number, int d ){
    if (number == 0){
        return 0;
    }else{
        int lastd = number % 10;
        if (lastd == d) {
            return 1 + occurrences(number / 10, d);
        }else{
            return 0 + occurrences(number / 10, d);
        }
    }
}

/*
int occurrences( int number, int d ){
 int result = 1
    if (number == 0){
        result = 0;
    }else{
        int lastd = number % 10;
        if (lastd == d) {
            result = 1 + occurrences(number / 10, d);
        }else{
            result = 0 + occurrences(number / 10, d);
        }
    }
 return result;
}
 */


// Returns a string where repeated matching characters in the value s get separated by the string "77"
string lucky7s( string s ){
    if (s.length() <= 1) {
        return s;
    }else{
        if (s[0] == s[1]) {
            return s.substr(0,1) + "77" + lucky7s(s.substr(1));
        }else{
            return s.substr(0,1) + lucky7s(s.substr(1));
        }
    }
    return "1";
}

// Returns true if the total of any combination of elements in the array parameter equals the target value
bool combinations( int array[ ], int size, int target ){
    if (target == 0) return true;
    if (size == 0 || target < 0) return false;
    
    int include = combinations(array, size - 1, target - array[size - 1]);
    int exclude = combinations(array, size - 1, target);
        
    return (include||exclude);
} // BigO, O(2^n)


int main() {
    // insert code here...
    assert( modulo( 100, 10 ) == 0 );
    assert( modulo( 1, 13 ) == 1 );
    assert( modulo( 12, 5 ) == 2 );
    assert( modulo( 33, 6 ) == 3 );

    assert( occurrences( 567, 2 ) ==  0 );
    assert( occurrences( 128874, 2 ) == 1 );
    assert( occurrences( 212121, 2 ) == 3 );
    assert( lucky7s( "cs32" ) == "cs32" );
    assert( lucky7s( "Apple Baseball" ) == "Ap77ple Basebal77l" );
    assert( lucky7s( "abbba" ) == "ab77b77ba" );
    
    int array[ 5 ] = { 2, 4, 6, 8, 10 };
    assert( combinations( array, 5, 10 ) == true );
    assert( combinations( array, 5, 18 ) == true );
    assert( combinations( array, 5, 15 ) == false );

    /*
    // test code
    // remaider = 0 or otherwise, dividends = 0.
    assert(modulo(70, 7) == 0);
    assert(modulo(9, 9) == 0);
    assert(modulo(0, 11) == 0);
    assert(modulo(15, 4) == 3);
    assert(modulo(13, 2) == 1);
    
    // test when d and numbers are both or either zero
    // test normal occurences count
    assert(occurrences(0, 0) == 0);
    assert(occurrences(0, 13) == 0);
    assert(occurrences(1001, 0) == 2);
    assert(occurrences(120, 0) == 1);
    assert(occurrences(333333, 5) == 0);
    assert(occurrences(333333, 3) == 6);
    
    // test when no repetition or multiple repetitions
    assert(lucky7s("abc") == "abc");
    assert(lucky7s("Llo") == "Llo");
    assert(lucky7s("cctv") == "c77ctv");
    assert(lucky7s("lolll") == "lol77l77l");
    assert(lucky7s("bbbb") == "b77b77b77b");
    
    // test the adds-up will use once and case when they are partially or all needed
    int a[5] = {1,2,3,11,13};
    assert(combinations(a, 5, 7) == false);
    assert(combinations(a, 5, 20) == false);
    assert(combinations(a, 5, 50) == false);
    assert(combinations(a, 5, 3) == true);
    assert(combinations(a, 5, 17) == true);
    assert(combinations(a, 5, 30) == true);
    */
    
    cout << "all tests passed!" << endl;
    return 0;
}
