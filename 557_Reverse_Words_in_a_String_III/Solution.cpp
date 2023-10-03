#include "Solution.hpp" // header in local directory

using namespace leetcode;
using namespace std;


string Solution::reverseWords(string s) {
    string r;
    if (!s.empty()) {
        int start = 0;
        do {
            
            int idx = s.find(" ", start);
            if (idx == string::npos) {
                break;
            }

            int length = idx - start;
            string sub = s.substr(start, length);
            reverse(sub.begin(), sub.end());
            r.append(sub);
            r.append(" ");
            start += (length + sizeof(char));
        } while (true);
        string sub = s.substr(start);
        reverse(sub.begin(), sub.end());
        r.append(sub);
    }
    return r;
}

//other approach
/*string Solution::reverseWords(string& s) {
    auto n = s.size();
    auto l = s.begin();

    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') {
            auto r = s.begin() + i;
            reverse(l, r);
            l = r + 1;
        }
    }
    reverse(l, s.end());

    return move(s);
}
*/