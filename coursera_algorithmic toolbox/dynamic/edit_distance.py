# Uses python3
# Computes the edit distance between two strings
# Algorithmic toolbox, week4.3
def edit_distance(s, t):
    dist = []
    for i in range(len(s)+1):
        dist.append([])
        for j in range(len(t)+1):
            if i==0:
                dist[i].append(j)
            elif j==0:
                dist[i].append(i)
            else:
                dist[i].append(0)
    for j in range(1,len(t)+1):
        for i in range(1,len(s)+1):
            insertion = dist[i][j-1]+1
            deletion = dist[i-1][j]+1
            match = dist[i-1][j-1]
            mismatch = dist[i-1][j-1]+1
            if s[i-1] == t[j-1]:
                dist[i][j] = min(insertion,deletion,match)
            else:
                dist[i][j] = min(insertion,deletion,mismatch)
    return dist[i][j]

if __name__ == "__main__":
    #print (edit_distance("editing", "distance"))
    print(edit_distance(input(), input()))
