/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
var reverseString = function(s) {
    var stringLength = s.length 

    for ( let i = 0;i<stringLength/2;i++)
    {
        [s[i],s[stringLength-i-1]] = [s[stringLength-i-1],s[i]]        
    }
};
