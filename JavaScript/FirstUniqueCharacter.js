var firstUniqueCharacter = function(s) {
    let hashMap = new Array(26).fill(0);
    let stringLength = s.length;
    for(let i=0;i<stringLength;i++)
    {
       hashMap[s.charCodeAt(i)-"a".charCodeAt(0)]++;
    }
    console.log(hashMap);
    for(let i=0;i<stringLength;i++)
    {
        if(hashMap[s.charCodeAt(i)-"a".charCodeAt(0)] == 1)
        {
            return i;
        }
    }
    return -1;
};
let stringInput = 'aabccd';
var result = firstUniqueCharacter.call(this,stringInput);
console.log(result);
