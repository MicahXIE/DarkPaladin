/*
Sample Input 0

6 4
give me one grand today night
give one grand today
Sample Output 0

Yes
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the checkMagazine function below.
void checkMagazine(vector<string> magazine, vector<string> note) {
    
    map<string, int> mgz_mp;
    map<string, int> note_mp;
    map<string, int>::iterator mgz_iter;
    map<string, int>::iterator note_iter;
    
    for(int i=0; i<magazine.size(); i++){
        mgz_iter = mgz_mp.find(magazine[i]);
        if(mgz_mp.empty() || mgz_iter == mgz_mp.end()){
            mgz_mp[magazine[i]] = 1;
        } else {
            mgz_mp[magazine[i]] += 1;
        }        
    }

    for(int j=0; j<note.size(); j++){
        note_iter = note_mp.find(note[j]);
        if(note_mp.empty() || note_iter == note_mp.end()){
            note_mp[note[j]] = 1;
        } else {
            note_mp[note[j]] += 1;
        }        
    }
    
    for(auto item_iter = note_mp.begin(); item_iter != note_mp.end(); item_iter++){
        if(mgz_mp.count(item_iter->first) == 0 || item_iter->second > mgz_mp[item_iter->first]){
            cout << "No" << endl;
            return;
        }
    }
    
    cout << "Yes" << endl;
    
    return;
    
}

int main()
{
    string mn_temp;
    getline(cin, mn_temp);

    vector<string> mn = split_string(mn_temp);

    int m = stoi(mn[0]);

    int n = stoi(mn[1]);

    string magazine_temp_temp;
    getline(cin, magazine_temp_temp);

    vector<string> magazine_temp = split_string(magazine_temp_temp);

    vector<string> magazine(m);

    for (int i = 0; i < m; i++) {
        string magazine_item = magazine_temp[i];

        magazine[i] = magazine_item;
    }

    string note_temp_temp;
    getline(cin, note_temp_temp);

    vector<string> note_temp = split_string(note_temp_temp);

    vector<string> note(n);

    for (int i = 0; i < n; i++) {
        string note_item = note_temp[i];

        note[i] = note_item;
    }

    checkMagazine(magazine, note);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
