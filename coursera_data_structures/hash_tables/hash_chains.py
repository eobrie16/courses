# python3

'''import sys

class Logger:
    def __init__(self):
        self.output = None

    def write(self, text):
        self.output = text

    def flush(self):
        self.output = None
        sys.__stdout__.flush()

oldstdout = sys.stdout
sys.stdout = Logger()'''

class Query:

    def __init__(self, query):
        self.type = query[0]
        if self.type == 'check':
            self.ind = int(query[1])
        else:
            self.s = query[1]

class QueryProcessor:
    _multiplier = 263
    _prime = 1000000007

    def __init__(self, bucket_count):
        self.bucket_count = bucket_count
        # store all strings in one list
        self.elems = []
        self.map = HashMap(bucket_count)

    def _hash_func(self, s):
        ans = 0
        for c in reversed(s):
            ans = (ans * self._multiplier + ord(c)) % self._prime
        return ans % self.bucket_count

    def write_search_result(self, was_found):
        print('yes' if was_found else 'no')

    def write_chain(self, chain):
        print(' '.join(chain))

    def read_query(self):
        return Query(input().split())

    def process_query_old(self, query):
        if query.type == "check":
            # use reverse order, because we append strings to the end
            self.write_chain(cur for cur in reversed(self.elems)
                        if self._hash_func(cur) == query.ind)
        else:
            try:
                ind = self.elems.index(query.s)
            except ValueError:
                ind = -1
            if query.type == 'find':
                self.write_search_result(ind != -1)
            elif query.type == 'add':
                if ind == -1:
                    self.elems.append(query.s)
            else:
                if ind != -1:
                    self.elems.pop(ind)

    def process_queries(self, input_string=None):
        if input_string is None:
            n = int(input())
            for i in range(n):
                self.process_query(self.read_query())
        else:
            lines = input_string.splitlines()[1:]
            for line in lines:
                #print (line)
                self.process_query(Query(line.split()))
                '''text1 = sys.stdout.output
                self.process_query_old(Query(line.split()))
                if sys.stdout.output != text1:
                    sys.__stdout__.write("ERROR! ", text1, sys.stdout.output, "\n")
                    break
                else:
                    sys.__stdout__.write(text1)'''

    def process_query(self, query):
        if query.type == "check":
            print(self.map.check(query.ind))
        elif query.type == 'find':
            print(self.map.find(query.s))
        elif query.type == 'add':
            self.map.add(query.s)
        elif query.type == 'del':
            self.map.delete(query.s)
        else:
            pass

class HashMap:
    _multiplier = 263
    _prime = 1000000007

    def __init__(self, size=1):
        self.size = size
        self.map = [None for i in range(size)]

    def _hash_func(self, s):
        ans = 0
        for c in reversed(s):
            ans = (ans * self._multiplier + ord(c)) % self._prime
        return ans % self.size

    def add(self, value):
        hashval = self._hash_func(value)
        if self.map[hashval] is None:
            self.map[hashval] = [value]
        else:
            for entry in self.map[hashval]:
                if entry == value:
                    return
            self.map[hashval].insert(0, value)

    def check(self, index):
        if self.map[index] is None:
            return ''
        else:
            return ' '.join(self.map[index])

    def find(self, value):
        hashval = self._hash_func(value)
        if self.map[hashval] is None:
            return 'no'
        else:
            for entry in self.map[hashval]:
                if entry == value:
                    return 'yes'
            return 'no'

    def delete(self, value):
        index = self._hash_func(value)
        if self.map[index] is None:
            return
        else:
            for entry in self.map[index]:
                if entry == value:
                    self.map[index].remove(value)
                    return



if __name__ == '__main__':
    bucket_count = int(input())
    proc = QueryProcessor(bucket_count)
    proc.process_queries()
