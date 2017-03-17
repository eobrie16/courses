# Uses python3
# Given a set of points on a line, and a set of segments on a line
# For each point, compute the number of segments that contains the point
# Algorithmic toolbox, Week 3.5

import sys
import random
import time

def value(seg, key):
    if seg['value'] < key['value']:
        return -1
    elif seg['value'] > key['value']:
        return 1
    else:
        if seg['point_type'] < key['point_type']:
            return -1
        elif seg['point_type'] == key['point_type']:
            return 0
        else:
            return 1

def partition(segments,l,r):
    x = segments[l]
    j = l
    for i in range(l+1, r+1):
        if value(segments[i], x) <= 0:
            j += 1
            segments[j], segments[i] = segments[i], segments[j]
    segments[j], segments[l] = segments[l], segments[j]
    return j

def quick_sort(segments,l,r):
    if l >= r:
        return
    k = random.randint(l,r)
    segments[l], segments[k] = segments[k], segments[l]
    m = partition(segments,l,r)
    quick_sort(segments,l,m-1)
    quick_sort(segments,m+1,r)

#def faster_count_segments(starts, ends, points):
def faster_count_segments(segList, numPts):
    quick_sort(segList,0,len(segList)-1)
    cnt = [0] * numPts
    segs = 0
    count = 0
    for curSeg in segList:
        if curSeg['point_type'] == 0:
            segs += 1
        elif curSeg['point_type'] == 2:
            segs -= 1
        else:
            index = curSeg['index']
            cnt[index] = segs
            count += 1
        if count == numPts:
            break
    return cnt

def naive_count_segments(starts, ends, points):
    cnt = [0] * len(points)
    for i in range(len(points)):
        for j in range(len(starts)):
            if starts[j] <= points[i] <= ends[j]:
                cnt[i] += 1
    return cnt

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    segList = []
    n = data[0]
    m = data[1]
    starts = data[2:2 * n + 2:2]
    ends   = data[3:2 * n + 2:2]
    points = data[2 * n + 2:]

    segList.extend([{'point_type': 0, 'value': int(x)} for x in starts])
    segList.extend([{'point_type': 1, 'value': int(x), 'index': i} for i, x in enumerate(points)])
    segList.extend([{'point_type': 2, 'value': int(x)} for x in ends])

    cnt = faster_count_segments(segList, m)
    for x in cnt:
        print(x, end=' ')
    print()

    while 0:
        n = 50000
        maxval = 10e8
        input = '%s %s\n' % (n,n)
        for i in range(n):
            a = random.randint(-maxval, maxval-2)
            b = random.randint(a, maxval)
            input += '%s %s\n' % (a, b)
        for j in range(n):
            input += '%s ' % random.randint(-maxval, maxval)
        input += '\n'

        #input = sys.stdin.read()
        s = time.clock()
        data = list(map(int, input.split()))
        segList = []
        n = data[0]
        m = data[1]
        starts = data[2:2 * n + 2:2]
        ends   = data[3:2 * n + 2:2]
        points = data[2 * n + 2:]

        segList.extend([{'point_type': 0, 'value': int(x)} for x in starts])
        segList.extend([{'point_type': 1, 'value': int(x), 'index': i} for i, x in enumerate(points)])
        segList.extend([{'point_type': 2, 'value': int(x)} for x in ends])

        #use fast_count_segments
        cnt2 = faster_count_segments(segList, m)
        total = time.clock() - s
        #cnt1 = naive_count_segments(starts, ends, points)
        #if cnt1 != cnt2:
        #    print ('error!')
        #    print (starts, ends, points)
        #    print (cnt1, cnt2)
        #    break
        if total > 20.0:
            print ("took too long ", total)
            break
        else:
            print ("OK", total)
        #for x in cnt:
        #    print(x, end=' ')
        #print()
