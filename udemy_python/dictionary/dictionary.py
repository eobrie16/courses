import time
import json
from difflib import SequenceMatcher, get_close_matches
data = json.load(open('data.json'))

def get_similar(word):
    # this is slow
    for key in data.keys():
        if SequenceMatcher(None, word, key).ratio() > 0.8:
            res = input("Did you mean <%s>? (Y/N)" % key)
            if res.lower()[0] == 'y':
                return data[key]
    return "Word not found!"
    
def get_close(word):
    matches = get_close_matches(word, data.keys(), 5, 0.8)
    for match in matches:
        res = input("Did you mean <%s>? (Y/N)" % match)
        if res.lower()[0] == 'y':
            return data[match]
    return "Word not found!"

def get_definition(word):
    w = word.lower()
    if w in data:
        return data[w]
    else:
        return get_close(word)
        #return get_similar(word)


word = str(input("Enter word: ").strip())
#start = time.time()
output = get_definition(word)
if isinstance(output, list):
    print ('\n'.join(output))
else:
    print (output)
#print (time.time()-start)

