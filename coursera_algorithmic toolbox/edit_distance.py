# Uses python3
# Computes the edit distance between two strings
# Algorithmic toolbox, Week 4.3

def edit_distance(s, t):
    dist = []
    for i in range(len(s)+1):
        dist.append([0 for j in range(len(t)+1)])
    for j in range(1,len(t)+1):
        for i in range(1,len(s)+1):
            insertion = dist[i][j-1]+1
            deletion = dist[i-1][j]+1
            match = dist[i-1][j-1]
            mismatch = dist[i-1][j-1]+1
            #print (insertion, deletion, match, mismatch)
            if s[i-1] == t[j-1]:
                if match > 0:
                    print ("match!")
                val = match
                dist[i][j] = int(val)
            else:
                val = int(min(min(insertion,deletion),mismatch))
                if val > 0:
                    print ("mismatch!")
                dist[i][j] = val
    return dist[i][j]+1

if __name__ == "__main__":
    print (edit_distance("short", "ports"))
    #print(edit_distance(input(), input()))
