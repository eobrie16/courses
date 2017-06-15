# python3
import random

_big_prime = 1000000007

def read_input():
    return (input().rstrip(), input().rstrip())

def print_occurrences(output):
    print(' '.join(map(str, output)))

def get_occurrences(pattern, text):
    return [
        i
        for i in range(len(text) - len(pattern) + 1)
        if text[i:i + len(pattern)] == pattern
    ]

def PolyHash(S, p, x):
    h = 0
    for i in range(len(S)-1, -1, -1):
        h = (h*x + ord(S[i])) % p
    return h

def precompute_hashes(text, pattern, p, x):
    H = [None for i in range(len(text)-len(pattern)+1)]
    S = text[len(text)-len(pattern):len(text)]
    H[len(text)-len(pattern)] = PolyHash(S, p, x)
    y=1
    for i in range(1,len(pattern)+1):
        y=(y*x) % p
    for i in range(len(text)-len(pattern)-1, -1, -1):
        H[i] = (x*H[i+1]+ord(text[i])-y*ord(text[i+len(pattern)])) % p
    return H

def rabin_karp(pattern, text):
    p = _big_prime
    x = random.randint(1, p-1)
    result = []
    pHash = PolyHash(pattern, p, x)
    for i in range(len(text)-len(pattern)+1):
        tHash = PolyHash(text[i:i+len(pattern)],p,x)
        if pHash != tHash:
            continue
        if text[i:i+len(pattern)]==pattern:
            result.append(i)
    return result

def rabin_karp_modified(pattern, text):
    p = _big_prime
    x = random.randint(1, p-1)
    result = []
    pHash = PolyHash(pattern, p, x)
    H = precompute_hashes(text, pattern, p, x)
    for i in range(len(text)-len(pattern)+1):
        if pHash != H[i]:
            continue
        if text[i:i+len(pattern)]==pattern:
            result.append(i)
    return result

if __name__ == '__main__':
    print_occurrences(rabin_karp_modified(*read_input()))
    '''text = 'baaaaaaa'
    pattern = 'aaaaa'
    print_occurrences(get_occurrences(pattern, text))
    print_occurrences(rabin_karp_modified(pattern, text))'''
