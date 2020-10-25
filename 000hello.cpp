#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int videoStitching(vector<vector<int>>& clips, int T) {
    vector<int> starts, ends;
    int minStart = 999;
    int cnt = 0;
    while (1){
    int flag = 0;
        for (auto it = clips.begin(); it < clips.end(); it++){
            if ((*it)[1] >= T){
                flag = 1;
                if ((*it)[0] < minStart){
                    minStart = (*it)[0];
                }
                clips.erase(it);
            }
        }
        if (flag == 0)
            return -1;
        cnt++;
        if (minStart == 0)
            break;
        T = minStart;
    }
    return cnt;
}

int main(){  
    string S = "abbbbbac";
    vector<vector<int>> clips;
    vector<int> v;
    cout << "nothing";

    

    return 0;   
}
   