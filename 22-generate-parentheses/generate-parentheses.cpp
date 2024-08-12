class Solution {
public:

    void generate(vector<string> & res , int n , string current , int openingBracket , int closingBracket) {
        cout<<"new string : "<<current<<endl;
        if(current.length() == n * 2 && openingBracket + closingBracket == 2*n) {
            res.push_back(current);
            return;
        }

        if(openingBracket < n) generate(res, n , current + '(' , openingBracket +1 , closingBracket);

        if(closingBracket < n and closingBracket < openingBracket) generate(res,n,current+')',openingBracket ,closingBracket+1);

        cout<<"backtrack string : "<<current<<endl;

    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> res ;
        generate(res , n ,"", 0 , 0);
        return res; 
    }
};