# Philosophers

<p align='center'>
  <img src='./static/1.png'/>
</p>

The Dining Philosophers Problem is an illustrative example of a common computing problem in `concurrency`.
The dining philosophers problem describes a group of philosophers sitting at a table doing one of three things
**eating**, **thinking** or **sleeping**. While eating, they are not thinking, and while thinking, they are not eating. The philosophers sit at a circular table each with a bowl of spaghetti. A chopstick is placed in between each
philosopher, thus each philosopher has one chopstick to his or her left and one chopstick to his or her right.
As spaghetti is difficult to serve and eat with a single chopstick, it is assumed that a philosopher must eat
with two chopsticks. The philosopher can only use the chopstick on his or her immediate left or right.

**The philosophers never speak to each other**, which creates a dangerous possibility of deadlock. `Deadlock`
could occur if every philosopher holds a left chopstick and waits perpetually for a right chopstick (or vice
versa). Originally used as a means of illustrating the problem of deadlock, this system reaches deadlock
when there is a ’cycle of unwarranted requests’.
The lack of available chopsticks is an analogy to the locking of `shared resources` in real computer programming.
Locking a resource is a common technique to ensure the resource is accessed by only one program or chunk of
code at a time. The challenge occurs when there are multiple resources which must be acquired individually.
When several programs are involved in locking multiple resources, deadlock can occur. For example, one
program needs two files to process. When two such programs lock one file each, both programs wait for the
other one to unlock the other file, which will never happen.

## Key Concepts

- Concurrency
- Multithreading
- Multiprocessing
- Atomic operations
- Interleavings
- Semaphores
- Mutexes
- Race conditions
- Data races
- Critical sections
- Dead lock
- Starvation
- Lock-order-inversion


## Terminology

- **Concurrency** : Concurrency refers to the ability of a system to handle multiple tasks or processes simultaneously.
- **Multithreading** : Multithreading is a programming technique where multiple threads are spawned by a process to execute tasks concurrently.
- **Multiprocessing** : Multiprocessing is the utilization of two or more central processing units (CPUs) in a single computer system. It refers to a system's ability to support multiple CPUs and its capacity to distribute work among them.
- **Atomic operations** : Atomic operations are operations that are performed completely independently of any other operations **and cannot be interrupted**.
- **Interleavings** : Interleavings refer to the various possible sequences in which the instructions of multiple threads or processes may be executed when they run concurrently. 
- **Race conditions** : A race condition occurs when two or more threads or processes access shared data concurrently
- **Data races** : A data race is a specific type of race condition that occurs when two or more threads access the same memory location concurrently, and **at least one of the accesses is a write operation**.
- **Critical sections** : A critical section is a part of the code that accesses shared resources and must not be executed by more than one thread or process at a time to prevent race conditions.
- **Dead lock** : Deadlock is a situation in concurrent programming where two or more threads or processes are **unable to proceed because each is waiting for the other** to release a resource. This creates a cycle of dependencies that causes the threads to be stuck **indefinitely**.
- **lock-order-inversion** : Lock-order inversion is a situation where two or more threads acquire locks in different orders, which can lead to deadlocks. For example, if Thread 1 locks Resource A and then Resource B, while Thread 2 locks Resource B and then Resource A, they could end up waiting indefinitely for each other to release the locks, resulting in a deadlock.
- **Starvation** : Starvation in concurrent programming occurs when a thread or process is unable to make progress because it is continuously denied access to the resources it needs. This happens when other threads or processes continually monopolize the resources, leaving the affected thread or process waiting indefinitely.

## Used Functions

- sem_wait
- sem_post
- sem_init
- sem_open
- pthread_mutex_lock
- pthread_mutex_unlock
- pthread_create
- pthread_mutex_init

## Usage

```
cd philo && make && ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```
**Bonus**
```
cd philo_bonus && make && ./philo_bonus <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

## Resources

- [Subject](./static/Philosophers.pdf)
- [Extreme C (book)](https://www.dropbox.com/scl/fi/jspczpgumsd2ct7sluvox/Extreme_C_Taking_You_To_The_Limit_In_Concurrency_OOP_And_The_Most_Advanced_Capabilities_Of_C_Kamran_Amini_z-lib.org.pdf?rlkey=ffpu0qmift02gzo79vx36xe8j&e=1&dl=0)
- [Unix threads in C](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
- [Multithreading tutorial](https://randu.org/tutorials/threads/)
- [Lecture note](https://lass.cs.umass.edu/~shenoy/courses/fall13/lectures/Lec10_notes.pdf)