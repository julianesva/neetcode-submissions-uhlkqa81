class Solution {
public:
    bool isPalindrome(string s) {
        std::string filtered;
        for (char c : s) {
            if (std::isalnum(c)) { 
                filtered += std::tolower(c); 
            }
        }

        cout<<"String: "<<filtered<< endl;
        int right = filtered.size()-1;
        int left = 0;

        while(left < right){
            cout<<"left: "<<left<<" right: "<<right<<endl;
            if(filtered[left] != filtered[right]){
                return false;
            }
            right--;
            left++;
        }

        return true;
    }
};
