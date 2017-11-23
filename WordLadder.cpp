class WordInfo {
public:
    string word;
    int count;
    WordInfo( string word, int count ) {
        this->word = word;
        this->count = count;
    }
};

bool inDict( string word, unordered_map<string,int>& wordMap ) {
    if( wordMap[word] && wordMap[word] == 1 ) return true;
    return false;
}

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Storing dict in a map for O(1) lookup
        unordered_map<string,int> wordMap;
        for( int i = 0; i < wordList.size(); i++ ) {
            wordMap[wordList[i]] = 1;
        }

        // Base case
        if( !inDict( endWord, wordMap ) ) return 0;

        queue< WordInfo > q;
        q.push( WordInfo( beginWord, 1 ));
        while( !q.empty() ) {
            WordInfo top = q.front();
            q.pop();
            string word = top.word;
            int count = top.count;
            if( word.compare( endWord ) == 0 ) return count;
            for( int i = 0; i < word.length(); i++ ) {
                for( char c = 'a'; c <= 'z'; c++ ) {
                    char temp = word[i];
                    if( word[i] != c ) {
                        word[i] = c;
                        if( inDict( word, wordMap ) ) {
                            q.push( WordInfo( word, count+1 ) );
                            wordMap[word] = 0;   
                        }
                    }
                    word[i] = temp;
                }
            }
        }
        return 0;
    }
};
