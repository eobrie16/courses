# python3
# In this problem you will implement a program
#  to simulate the processing of network packets.
# Data Structures 1.3

from collections import deque

class Request:
    """
    Stores arrival time and processing time for each packet
    """
    def __init__(self, arrival_time, process_time):
        self.arrival_time = arrival_time
        self.process_time = process_time

class Response:
    """
    Stores status for the current packet
    """
    def __init__(self, dropped, start_time):
        self.dropped = dropped
        self.start_time = start_time

class Buffer:
    """
    Stores buffer size and finish time for each packet
    """
    def __init__(self, size):
        self.size = size
        self.finish_time_ = deque()

    def Process(self, request):
        while len(self.finish_time_) and self.finish_time_[0] <= request.arrival_time:
            self.finish_time_.popleft()
        if len(self.finish_time_) == size:
            return Response(True, request.arrival_time)
        else:
            if len(self.finish_time_):
                start = self.finish_time_[-1]
            else:
                start = request.arrival_time
            self.finish_time_.append(start+request.process_time)
        return Response(False, start)

def ReadRequests(count):
    """Reads requests from stdin
    The first line of the input contains the size 𝑆 of the buffer
    and the number 𝑛 of incoming network packets. Each of the next n lines
    contains two numbers. 𝑖-th line contains the time of arrival 𝐴𝑖 and the
    processing time 𝑃𝑖 (both in milliseconds) of the 𝑖-th packet.
    """
    requests = []
    for i in range(count):
        arrival_time, process_time = map(int, input().strip().split())
        requests.append(Request(arrival_time, process_time))
    return requests

def ProcessRequests(requests, buffer):
    """
    Processes the given responses, given the specifed buffer
    """
    responses = []
    for request in requests:
        responses.append(buffer.Process(request))
    return responses

def PrintResponses(responses):
    for response in responses:
        print(response.start_time if not response.dropped else -1)

if __name__ == "__main__":
    size, count = map(int, input().strip().split())
    requests = ReadRequests(count)
    buffer = Buffer(size)
    responses = ProcessRequests(requests, buffer)
    PrintResponses(responses)
