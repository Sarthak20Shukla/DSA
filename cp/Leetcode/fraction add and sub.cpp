class Solution {
public:
    string fractionAddition(string expression) {
        int nume=0;
        int deno=1;
        int n=expression.length();
        int i=0;
        while(i<n){
            int currnume=0;
            int currdeno=0;
            bool isNeg=(expression[i]=='-');
            if(expression[i]=='-' || expression[i]=='+') i++;

            while(i<n && isdigit(expression[i])){
                int val=expression[i]-'0';
                currnume=val+10*currnume;
                i++;
            }
            i++;
            if(isNeg==true){
                currnume*=-1;
            }
             while(i<n && isdigit(expression[i])){
                int val=expression[i]-'0';
                currdeno=val+10*currdeno;
                i++;
            }

            nume=deno*currnume+nume*currdeno;
            deno=deno*currdeno;

        }
        int GCD= __gcd(abs(nume),deno);
         nume=nume/GCD;
         deno=deno/GCD;
        return to_string(nume)+"/"+to_string(deno);


        
    }
};