class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n1 = word1.size(); 
        int n2 = word2.size(); 
        if (n2 > n1) return 0; 
        unordered_map<char, int> mppp2, mppp1; 
        for (char c : word2) { 
            mppp2[c]++; 
        } 
 
        long long uttar = 0; 
        int darkar = mppp2.size(); 
        int heijaichi = 0;
 
        int bama = 0;
 
        for (int dahana = 0; dahana < n1; ++dahana) { 
            char c = word1[dahana]; 
            mppp1[c]++; 
            if (mppp2.count(c) && mppp1[c] == mppp2[c]) { 
                heijaichi++; 
            } 
             while (heijaichi == darkar) { 
                uttar += (n1 - dahana); 
                char bamachar = word1[bama]; 
                mppp1[bamachar]--; 
                if (mppp2.count(bamachar) && mppp1[bamachar] < mppp2[bamachar]) { 
                    heijaichi--; 
                } 
                bama++; 
            } 
        } 
        return uttar; 
    }
};