class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(
            std::remove_if(s.begin(), s.end(),
                [](unsigned char c) {

                    return !std::isalnum(c);
                }),
            s.end()
        );

        for (char& c : s) {
            c = std::tolower(static_cast<unsigned char>(c));
        }

        cout<<"String: "<<s<< endl;
        int right = s.size()-1;
        int left = 0;

        while(left < right){
            cout<<"left: "<<left<<" right: "<<right<<endl;
            if(s[left] != s[right]){
                return false;
            }
            right--;
            left++;
        }

        return true;
    }
};
