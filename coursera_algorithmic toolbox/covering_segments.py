# Uses python3
# Given a set of 𝑛 segments {[𝑎0,𝑏0],[𝑎1,𝑏1],...,[𝑎𝑛−1,𝑏𝑛−1]}
#  with integer coordinates on a line,
#  nd the minimum number 𝑚 of points
#  such that each segment contains at least one point.
# Output the minimum number 𝑚 of points on the  rst line and
#  the integer coordinates of 𝑚 points (separated by spaces) on the second line.
# Algorithmic toolbox, Week 3.4

import sys
import random
from collections import namedtuple

Segment = namedtuple('Segment', 'start end')

def sortSegment(seg):
    return seg.end

def optimal_points(segments):
    points = []
    segments.sort(key=sortSegment)
    mergedSegments = [segments[0]]
    points.append(segments[0].end)
    for segment in segments:
        found = 0
        for point in points:
            if point >= segment.start and point <= segment.end:
                found = 1
                break
        if not found:
            points.append(segment.end)
    return points

if __name__ == '__main__':
    # input from stdin
    n = int(sys.stdin.readline())
    segments = []
    for i in range(n):
        x = sys.stdin.readline().split()
        segments.append(Segment(int(x[0]), int(x[1])))
    # for testing
    '''stop = 0
    while (not stop):
        stop = 1
        segments = []
        n = random.randint(1,100)
        for i in range(n):
            a = random.randint(0,1e6-1)
            b = random.randint(a, 1e6)
            segments.append(Segment(a, b))
        points = optimal_points(segments)
        for segment in segments:
            for p in points:
                if p >= segment.start and p <= segment.end:
                    stop = 0
                    break
            if stop:
                print ("Error! No points found in segment %s, %s" % (segment.start, segment.end))
                break'''
    points = optimal_points(segments)
    print(len(points))
    for p in points:
        print(p, end=' ')
    print ()
