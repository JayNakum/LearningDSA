// Peterson Solution
const int i = 0, j = 1;

void process1(bool *flag, int &turn)
{
    flag[i] = true;
    turn = j;
    while(flag[j] && turn == j);
        
    // Critical Section

    flag[i] = false;
}

// test and set
bool test_and_set(bool *lock)
{
    bool tmp = *lock;
    *lock = true;
    return tmp;
}

// Mutex Locks
bool available;

void acquire()
{
    while(!available);
    available = false;
}

void release()
{
    available = true;
}

// Semaphores
void wait(int semaphore)
{
    while(semaphore <= 0);
    semaphore--;
}

void signal(int semaphore)
{
    semaphore++;
}