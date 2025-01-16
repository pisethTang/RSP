#include <bits/stdc++.h>
#include <csetjmp>

using namespace std;

bool with_ds(string s){ // T(N) \in O(NlogN) where N = s.size() 
    // encode each character int0 ascii code and store in an array or vector
    int N = s.size();
    vector<int> arr;
    for (auto ch: s){
        arr.push_back((int) ch);
    }
    // then check whether the array is unique 
    // to do so (without using additional data structure such as a hash map), we need to sore the array first 
    sort(arr.begin(), arr.end());

    // then it is sufficient adjacent elements. If the array contains duplicates, they would be clustered or be adjacent to one another.
    for (int i = 0; i < N - 1; i++){
        if (arr[i] == arr[i+1]){ // found duplicate
            return false;        // string is not unique 
        }
    }

    return true;                // string is unique
}
bool with_ds_v2(string s){ // T(N) \in O(N) where N = s.size() 
    // encode each character int0 ascii code and store in an array or vector
    int N = s.size();
    unordered_map<int, int> mp;

    for (auto ch: s){
        mp[ch]++;
        if (mp[ch] > 1){ // found duplicate
            return false;        // string is not unique 
        }
    }
    return true;
}


bool without_ds(string s){ // O(N^2)
    int N = s.size();
    // 1+2+3 +... + N \in O(N^2)
    for (int i = 0; i < N; i++){ // turns N times (checks N+1 times)
        for (int j=i+1; j<N; j++){  // turns i+1 times
            if (s[i] == s[j]) return false;
        }
    }
    return true;
}




int main(){
    // 30 strings 
    vector<pair<string, int>> testMe = {
        make_pair("hello",1),
        make_pair("world", 1),
        make_pair("level", 1),
        make_pair("12321", 1),
        make_pair("abcde", 1),
        make_pair("hellohello", 1),
        make_pair("abcdefghijklmnopqrstuvwxyz", 1),
        make_pair("abcdefghijklmnopqrstuvwxyza", 1),
        make_pair("1234567890", 0),
        make_pair("0987654321", 0),
        make_pair("abca", 1),
        make_pair("aabbccdd", 1),
        make_pair("aabbccddeeffgg", 0),
        make_pair("abcdefghijklmnopqrstuvwxyzz", 0),
        make_pair("abcdefghijklmnopqrstuvwxyzzz", 1),
        make_pair("abcdefghijklmnopqrstuvwxyzabc", 1),        
    };  

    bool with = false;
    bool combine = false;
    // start testing 
    for (auto& [s, expected]: testMe){
        // cout << "String: " << s << ", Expected: " << expected << ", with_ds: " << (with_ds(s)? "true" : "false") << ", with_ds_v2: " << (with_ds_v2(s)? "true" : "false") << ", without_ds: " << (without_ds(s)? "true" : "false") << endl;
        // if (((with_ds(s) == with_ds_v2(s)) == without_ds(s)) != true) cout << "Failed: " << s << "\n";
        with = with_ds(s) == with_ds_v2(s);
        if (with == false) {
            cout << "Failed at " << s << "\n";
            break;
        }
        else{
            if (with_ds(s) != without_ds(s))  cout << "Sth wrong with the last variant at "<< s << "\n";
        }
    }


    return 0;
}