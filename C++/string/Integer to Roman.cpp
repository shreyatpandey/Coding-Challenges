lass Solution {
public:
    string intToRoman(int num) {
        vector<string>Symbol = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int>Numbers = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string Result = "";
        for(int i=0;i<Symbol.size() && num>0;i++)
        {
            while(Numbers[i]<=num)
            {
                num -= Numbers[i];
                Result += Symbol[i];
            }
        }
        
        return Result;
    }
};
