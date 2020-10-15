#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){  

    string a = "abc";
    for (int i = 0; i < a.length(); i++){
        cout << a[i] << '\t';
        cout << a[i] - 'a' << '\t';
        cout << char('a' + i) << '\n';
        
    }
    // vector<int> minFreq(26, 0), curFreq(26,1);
    // vector<int> a = max(minFreq, curFreq);
    // for (int i = 0; i < a.size(); i++){
    //     cout << a[i];
    // }
    

    return 0;
        
}
   