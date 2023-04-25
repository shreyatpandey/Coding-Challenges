/*
You have an initial power of power, an initial score of 0, and a bag of tokens where tokens[i] is the value of the ith token (0-indexed).

Your goal is to maximize your total score by potentially playing each token in one of two ways:

If your current power is at least tokens[i], you may play the ith token face up, losing tokens[i] power and gaining 1 score.
If your current score is at least 1, you may play the ith token face down, gaining tokens[i] power and losing 1 score.
Each token may be played at most once and in any order. You do not have to play all the tokens.

Return the largest possible score you can achieve after playing any number of tokens.

Input: tokens = [100,200], power = 150
Output: 1
Explanation: Play the 0th token (100) face up, your power becomes 50 and score becomes 1.
There is no need to play the 1st token since you cannot play it face up to add to your score.
*/
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int maxPoints = 0;
        int points = 0;
        int i = 0, j= tokens.size()-1;
        while(i<=j) // if i<j then there is test case failure
        {
            if(power >= tokens[i])
            {
                points += 1;
                power -= tokens[i++]; // why i++, dont want to resue the same value 
                maxPoints = max(maxPoints, points);
            }
            else if(points >0)
            {
                points -= 1;
                power += tokens[j--]; // why j--, don't want to reuse the same value
            }
            else
            {
                return maxPoints;
            }
        }
        return maxPoints;
        
    }
};
