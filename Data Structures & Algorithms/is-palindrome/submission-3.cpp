class Solution {
public:
    bool isPalindrome(std::string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            // Skip non-alphanumeric (left)
            while (left < right && 
                   !std::isalnum(static_cast<unsigned char>(s[left])))
                left++;

            // Skip non-alphanumeric (right)
            while (left < right && 
                   !std::isalnum(static_cast<unsigned char>(s[right])))
                right--;

            if (left < right) {
                if (std::tolower(static_cast<unsigned char>(s[left])) !=
                    std::tolower(static_cast<unsigned char>(s[right])))
                    return false;

                left++;
                right--;
            }
        }
        return true;
    }
};