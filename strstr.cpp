//KMP

vector<int> getSuffixArray(string needle) {
	int n = needle.length();
	vector<int> suffixArray(n,0);
	int i = 1;
	int j = 0;
	while(i < n) {
		if(j == 0 && needle[i] != needle[j]) {
			suffixArray[i] = 0;
			i++;
            continue;
		}
		if(needle[i] == needle[j]) {
			suffixArray[i] = j + 1;
			i++;
			j++;
            continue;
		}
		j = suffixArray[j - 1];
	}
	return suffixArray;
}

class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> suffixArray = getSuffixArray(needle);
        int n = needle.length();
        int m = haystack.length();
        int i = 0;
        int j = 0;
        while( i < m ) {
            if(j == n) return i-n;
            if(haystack[i] == needle[j]) {
                j++;
                i++;
            }
            else {
                if(j != 0) j = suffixArray[j - 1];
                else i++;
            }
        }
        if(j == n) return m-n;
        return -1;
    }
};