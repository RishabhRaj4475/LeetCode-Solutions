class Solution
{
    public:
        string countOfAtoms(string formula)
        {
            int n = formula.length();

            stack<unordered_map<string, int>> st;
            st.push(unordered_map<string, int> ());

            for (int i = 0; i < n;)
            {
                if (formula[i] == '(')
                {
                    unordered_map<string, int> mp;
                    string currFormula = "";
                    string count = "";

                    int index = i + 1;

                    while (index < n and(isalpha(formula[index]) or isdigit(formula[index])))
                    {
                        if (isdigit(formula[index]))
                        {
                            count += formula[index];
                        }
                        if (islower(formula[index]))
                        {
                            currFormula += formula[index];
                        }
                        if (isupper(formula[index]))
                        {
                            if (currFormula != "")
                            {
                                mp[currFormula] += (count == "") ? 1 : stoi(count);
                                currFormula = "";
                                count = "";
                            }
                            currFormula += formula[index];
                        }
                        index++;
                    }

                    if (currFormula != "")
                    {
                        mp[currFormula] += (count == "") ? 1 : stoi(count);
                        currFormula = "";
                        count = "";
                    }
                    i = index;
                    st.push(mp);
                }
                else if (formula[i] == ')')
                {
                    unordered_map<string, int> topMap = st.top();
                    st.pop();

                    string count = "";
                    int index = 1 + i;

                    while (index < n and isdigit(formula[index]))
                    {
                        count += formula[index++];
                    }

                    int countInt = count == "" ? 1 : stoi(count);

                    for (auto &x: topMap)
                    {
                        x.second *= countInt;
                    }

                    unordered_map<string, int> topMap2 = st.top();
                    st.pop();

                    for (auto &x: topMap)
                    {
                        string s = x.first;
                        int cnt = x.second;
                        if (topMap2[s] > 0) topMap2[s] += cnt;
                        else topMap2[s] = cnt;
                    }

                    st.push(topMap2);
                    i = index;
                }
                else
                {
                    unordered_map<string, int> mp = st.top();
                    st.pop();
                    string currFormula = "", count = "";

                    int index = i;

                    while (index < n and(isalpha(formula[index]) or isdigit(formula[index])))
                    {
                        if (isdigit(formula[index]))
                        {
                            count += formula[index];
                        }
                        if (islower(formula[index]))
                        {
                            currFormula += formula[index];
                        }
                        if (isupper(formula[index]))
                        {
                            if (currFormula != "")
                            {
                                mp[currFormula] += (count == "") ? 1 : stoi(count);
                                currFormula = "";
                                count ="";
                            }
                            currFormula += formula[index];
                        }
                        index++;
                    }

                    if (currFormula != "")
                    {
                        mp[currFormula] += (count == "") ? 1 : stoi(count);
                        currFormula = "";
                        count = "";
                    }

                    st.push(mp);
                    i = index;
                }
            }

            map<string, int> finalCount;
            for (auto &kv: st.top())
            {
                finalCount[kv.first] += kv.second;
            }

            string result;
            for (auto &kv: finalCount)
            {
                result += kv.first;
                if (kv.second > 1)
                {
                    result += to_string(kv.second);
                }
            }

            return result;
        }
};