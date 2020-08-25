lass Solution(object):
    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        list_morse_code = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        english_alphabet = "abcdefghijklmnopqrstuvwxyz"
        list_result = []
        for i in range(0,len(words)):
            list_words = list(words[i])
            string_morse = ""
            for j in range(len(list_words)):
                index_hold = english_alphabet.find(list_words[j])
                string_morse += str(list_morse_code[index_hold])
            
            if string_morse not in list_result:
                list_result.append(string_morse)
        
        return len(list_result)
                
