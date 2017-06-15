# python3

class JobQueue:
    def __init__(self):
        self.size = 0
        self.worker_queue = []

    def read_data(self):
        self.num_workers, m = map(int, input().split())
        self.jobs = list(map(int, input().split()))
        assert m == len(self.jobs)

    def write_response(self):
        for i in range(len(self.jobs)):
          print(self.assigned_workers[i], self.start_times[i])

    def assign_jobs(self):
        # TODO: replace this code with a faster algorithm.
        self.assigned_workers = [None] * len(self.jobs)
        self.start_times = [None] * len(self.jobs)
        next_free_time = [0] * self.num_workers
        for i in range(len(self.jobs)):
          next_worker = 0
          for j in range(self.num_workers):
            if next_free_time[j] < next_free_time[next_worker]:
              next_worker = j
          self.assigned_workers[i] = next_worker
          self.start_times[i] = next_free_time[next_worker]
          next_free_time[next_worker] += self.jobs[i]

    def assign_jobs_better(self):
        self.assigned_workers = [None] * len(self.jobs)
        self.start_times = [None] * len(self.jobs)
        for i in range(self.num_workers):
            self.insert((i,0))
        for j in range(len(self.jobs)):
            next = self.ExtractMax()
            self.assigned_workers[j] = next[0]
            self.start_times[j] = next[1]
            self.insert((next[0], next[1]+self.jobs[j]))

    def insert(self, worker):
        self.size += 1
        self.worker_queue.append(worker)
        self.SiftUp(self.size-1)

    def SiftUp(self, i):
        while i > 0 and (self.worker_queue[i][1] == self.worker_queue[self.Parent(i)][1] \
        and self.worker_queue[i][0] < self.worker_queue[self.Parent(i)][0] \
        or self.worker_queue[i][1] < self.worker_queue[self.Parent(i)][1]):
            self.worker_queue[self.Parent(i)], self.worker_queue[i] = self.worker_queue[i], self.worker_queue[self.Parent(i)]
            i = self.Parent(i)

    def Parent(self, i):
      return (i-1)//2

    def LeftChild(self, i):
      return (2*i)+1

    def RightChild(self, i):
      return (2*i)+2

    def ExtractMax(self):
        result = self.worker_queue[0]
        self.worker_queue[0] = self.worker_queue[self.size-1]
        self.worker_queue.pop()
        self.size -= 1
        self.SiftDown(0)
        return result

    def SiftDown(self, i):
        max_index = i
        l = self.LeftChild(i)
        if l <= self.size-1 and self.worker_queue[l][1] < self.worker_queue[max_index][1]:
            max_index = l
        elif l <= self.size-1 and (self.worker_queue[l][1] == self.worker_queue[max_index][1]\
        and self.worker_queue[l][0] < self.worker_queue[max_index][0]):
            max_index = l
        r = self.RightChild(i)
        if r <= self.size-1 and self.worker_queue[r][1] < self.worker_queue[max_index][1]:
            max_index = r
        elif r <= self.size-1 and (self.worker_queue[r][1] == self.worker_queue[max_index][1]\
        and self.worker_queue[r][0] < self.worker_queue[max_index][0]):
            max_index = r
        if i != max_index:
            self.worker_queue[i], self.worker_queue[max_index] = self.worker_queue[max_index], self.worker_queue[i]
            self.SiftDown(max_index)


    def solve(self):
        self.read_data()
        self.assign_jobs_better()
        self.write_response()

    def solve_naive(self):
        #self.read_data()
        self.assign_jobs()
        self.write_response()

if __name__ == '__main__':
    job_queue = JobQueue()
    job_queue.solve()
    '''import random
    while 1:
        workers = random.randint(1,10)
        numjobs = random.randint(1,100)
        jobs = [random.randint(1,1000) for i in range(numjobs)]
        print (jobs)
        job_queue = JobQueue()
        job_queue.num_workers = workers
        job_queue.jobs = jobs
        job_queue.solve()

        job_queue_naive = JobQueue()
        job_queue_naive.num_workers = workers
        job_queue_naive.jobs = jobs
        job_queue_naive.solve_naive()

        assert(job_queue.assigned_workers == job_queue_naive.assigned_workers)
        assert(job_queue.start_times == job_queue_naive.start_times)
        print ("OK")'''
