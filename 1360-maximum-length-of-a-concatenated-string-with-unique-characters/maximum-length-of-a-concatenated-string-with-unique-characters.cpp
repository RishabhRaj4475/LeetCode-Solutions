class Solution {
public:

    bool hasDuplicates(string &str1 , string &str2){
        vector<int> freq(26 , 0);

        for(auto ch : str1){
            if(freq[ch - 'a'] > 0) return true;

            freq[ch - 'a']++;
        }

        for( auto ch : str2){
            if(freq[ch - 'a'] > 0) return true;
        }

        return false;
    }

    int solve(vector<string> &arr , int size , int index , string &temp){
        if(index >= size) return temp.length();

        int include = 0 , exclude = 0 ;

        if(hasDuplicates(arr[index] , temp) == true){
            exclude = solve( arr , size , index + 1 , temp);
        } else {
            string s = temp + arr[index];
            include = solve(arr , size , index + 1 , s);
            exclude = solve(arr , size , index + 1 , temp);
        }

        return max(include , exclude);

    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string temp = "";
        int ans = solve( arr , n , 0 , temp);
        cout << temp<<endl;
        return ans;
    }
};