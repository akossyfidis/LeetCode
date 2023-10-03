#include "Solution.hpp" // header in local directory

using namespace leetcode;
using namespace std;


/*bool Solution::winnerOfGame(string colors) {
    if(colors.size() <= 2)
        return false;
    
    if(aliceActions(colors) > bobActions(colors)) return true;
    else return false;
}

int aliceActions(string colors) {
        int actions = 0;
        for(int i = 0; i < (int)colors.length(); i++) {
            if(colors[i] == 'A') {
                int consecutive =  1;
                for (int j = i+1 ; j < (int)colors.length(); j++) {
                    if (colors[i] == colors[j]) {
                        consecutive++;
                        if( j+1 >= (int)colors.length()) {
                            cout << "A : " << consecutive << endl;
                            if (consecutive >= 3)
                                actions += (consecutive - 2);
                        }
                    }
                    else {
                        cout << "A : " << consecutive << endl;
                        if (consecutive >= 3)
                            actions += (consecutive - 2);
                        i = j;
                        break;
                    }
                }
            }
        }
        cout << "Alice : " << actions << endl;
        return actions;
    }

int bobActions(string colors) {
    int actions = 0;
    for(int i = 0; i < (int)colors.length(); i++) {
        if(colors[i] == 'B') { 
            int consecutive =  1;
            for (int j = i+1 ; j < (int)colors.length(); j++) {
                if (colors[i] == colors[j]) {
                    consecutive++; 
                    if( j+1 >= (int)colors.length()) {
                        cout << "B : " << consecutive << endl;
                        if (consecutive >= 3)
                            actions += (consecutive - 2);
                    } 
                }
                else {
                    cout << "B : " << consecutive << endl;
                    if (consecutive >= 3)
                        actions += (consecutive - 2);
                    i = j;
                    break;
                }
            }
        }
    }
    cout << "Bob : " << actions << endl;
    return actions;
}*/

bool Solution::winnerOfGame(string colors) {
        int alice = 0;
        int bob = 0;

        // iterate through every character (edges exluded)
        for (int i = 1; i < colors.size() - 1; i++) {
            // check whether we get a suite of 3 same characters
            if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1]) {
                if (colors[i] == 'A') {
                    // if the character is A add action to Alice
                    alice++;
                } else {
                    // if the character is B add action to Bob
                    bob++;
                }
            }
        }
        
        return alice - bob >= 1;
    }