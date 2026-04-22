class Solution {
public:
    bool checkAlphaNumeric(char ch){
        if((ch>='0'&&ch<='9') || (ch>='a'&& ch<='z')|| (ch>='A'&&ch<='Z')){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int len=s.length();

        int i=0;
        int j=len-1;

        while(j>i){
            if(checkAlphaNumeric(s[i]) && checkAlphaNumeric(s[j])){
                if(tolower(s[i])==tolower(s[j])){
                    i++;
                    j--;
                }
                else{
                    return false;
                }
            }

            while(!checkAlphaNumeric(s[i])){
                i++;
            }
            while(!checkAlphaNumeric(s[j])){
                j--;
            }
        }

        return true;
    }
};
