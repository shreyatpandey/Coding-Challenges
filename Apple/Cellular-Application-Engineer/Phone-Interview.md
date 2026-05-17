# Phone Interview - Cellular Application Engineer

## Interviewer
Steve Holten

## Date of Interview
4th May, 2026

## Process
1. Gave introduction about role
2. It is more of SW side with access to code base
3. RF - HW productization

## Questions
1. Do you have any experience in using test equipment for calibration?
2. How do you approach new technology? Specifically for 6G
3. Why Munich?
4. Why Apple?

## Recollecting Answers
1. Test automation: Running CI/CD
2. Used equipment in Cellular domain for measuring signal strength
3. Talked about Coex between Wifi and 6G
4. For learning new technology [6G - Cellular], academician + training + overiew by directors

## Interviewer
Robert Pitchford

## Date of Interview
13th May, 2026

## Questions

``` python
import csv
from io import StringIO
import re
# you may import other packages, if desired, but it may not be required

# Given a string 'word', implement a function to
# reverse the string without relying upon Python's
# built-in 'reverse' method
def reverse_string(word):
    #Your code goes here
    reverse_string = ""
    for char in word:
        reverse_string = char + reverse_string
    return revese_string
    #pass


# Given a string 'sentence', reverse all words in the
# sentence while keeping the order of the words consistent,
# use the 'reverse' method implemented above
def reverse_words_in_sentence(sentence):
    #Your code goes here
    word_list = sentence.split()
    result_string = []
    for i range (0,len(word_list)):
        reverse_word = reverse_string(word_list[i])
        result_string.append(reverse_word)
    result = " ".join(result_string)
    return result
    #pass

# Given the following data

dataFile=""""entry",2,3,6
"boots",5,1,7
"slack",1,2.6
"triffid",11,-1.5
"""
f = StringIO(datafile)
data = list(csv.reader(f, delimiter=','))

# The data needs to be sorted *numerically* in ascening order by the
# second column
# Complete the following function so that it returns a list containing
# the sorted entries

def sort_fn(unsorted_data):
    #Your code goes here
    sorted_data = sorted(unsorted_data, key=lambda row:int(row[1]))
    return sorted_data

print()
print("Q3:", sort_fn(data)== [['slack','1','2.6'], ['entry','2','3.6'],
['boots', '5', '6'], ['triffid', '11', '-1.5']])
```