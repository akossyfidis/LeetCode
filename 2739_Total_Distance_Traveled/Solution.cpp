#include "Solution.hpp" // header in local directory

using namespace leetcode;
using namespace std;

int Solution::distanceTraveled(int mainTank, int additionalTank) {
    int km = 0;
    while(mainTank >= 5)
    {   
        mainTank -= 5;
        km += 50;
        if(additionalTank > 0){
            mainTank++;
            additionalTank--;
        }
    }
    return (km += mainTank*10);
}