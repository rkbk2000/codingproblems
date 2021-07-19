// You have the four functions:

// printFizz that prints the word "Fizz" to the console,
// printBuzz that prints the word "Buzz" to the console,
// printFizzBuzz that prints the word "FizzBuzz" to the console, and
// printNumber that prints a given integer to the console.
// You are given an instance of the class FizzBuzz that has four functions: fizz, buzz, fizzbuzz and number. The same instance of FizzBuzz will be passed to four different threads:

// Thread A: calls fizz() that should output the word "Fizz".
// Thread B: calls buzz() that should output the word "Buzz".
// Thread C: calls fizzbuzz() that should output the word "FizzBuzz".
// Thread D: calls number() that should only output the integers.
// Modify the given class to output the series [1, 2, "Fizz", 4, "Buzz", ...] where the ith token (1-indexed) of the series is:

// "FizzBuzz" if i is divisible by 3 and 5,
// "Fizz" if i is divisible by 3 and not 5,
// "Buzz" if i is divisible by 5 and not 3, or
// i if i is not divisible by 3 or 5.
// Implement the FizzBuzz class:

// FizzBuzz(int n) Initializes the object with the number n that represents the length of the sequence that should be printed.
// void fizz(printFizz) Calls printFizz to output "Fizz".
// void buzz(printBuzz) Calls printBuzz to output "Buzz".
// void fizzbuzz(printFizzBuzz) Calls printFizzBuzz to output "FizzBuzz".
// void number(printNumber) Calls printnumber to output the numbers.

// Example 1:

// Input: n = 15
// Output: [1,2,"fizz",4,"buzz","fizz",7,8,"fizz","buzz",11,"fizz",13,14,"fizzbuzz"]
// Example 2:

// Input: n = 5
// Output: [1,2,"fizz",4,"buzz"]

// Constraints:

// 1 <= n <= 50

// https://leetcode.com/problems/fizz-buzz-multithreaded/

// Runtime: 1788 ms, faster than 5.01% of C++ online submissions for Fizz Buzz Multithreaded.
// Memory Usage: 6.6 MB, less than 85.77% of C++ online submissions for Fizz Buzz Multithreaded.

class FizzBuzz
{
private:
    int n;
    int pc{1};
    std::mutex pmutex;

public:
    FizzBuzz(int n)
    {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz)
    {
        while (true)
        {
            pmutex.lock();
            if (pc > n)
                break;
            // Divide by 3 and  not 5
            if ((pc % 5) && (pc % 3 == 0))
            {
                printFizz();
                pc++;
            }
            pmutex.unlock();
        }
        pmutex.unlock();
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz)
    {
        while (true)
        {
            pmutex.lock();
            if (pc > n)
                break;
            // Divide by 5 not 3
            if ((pc % 5 == 0) && (pc % 3))
            {
                printBuzz();
                pc++;
            }
            pmutex.unlock();
        }
        pmutex.unlock();
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz)
    {
        while (true)
        {
            pmutex.lock();
            if (pc > n)
                break;
            // Divide by 3 and 5
            if (pc % 15 == 0)
            {
                printFizzBuzz();
                pc++;
            }
            pmutex.unlock();
        }
        pmutex.unlock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber)
    {
        while (true)
        {
            pmutex.lock();
            if (pc > n)
                break;
            // Not divisible by 3 and 5
            if ((pc % 5) && (pc % 3))
            {
                printNumber(pc);
                pc++;
            }
            pmutex.unlock();
        }
        pmutex.unlock();
    }
};

// Using a condition variable - CV - Ideally best solution
// Runtime: 64 ms, faster than 18.24% of C++ online submissions for Fizz Buzz Multithreaded.
// Memory Usage: 6.7 MB, less than 51.90% of C++ online submissions for Fizz Buzz Multithreaded.
class FizzBuzz
{
private:
    int n;
    int pc{1};
    std::mutex pmutex;
    std::condition_variable pcond;

public:
    FizzBuzz(int n)
    {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz)
    {
        while (true)
        {
            unique_lock<std::mutex> lock(pmutex);
            pcond.wait(lock, [this]()
                       { return pc > n || ((pc % 5) && (pc % 3 == 0)); });
            if (pc > n)
                break;
            printFizz();
            pc++;
            pcond.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz)
    {
        while (true)
        {
            unique_lock<std::mutex> lock(pmutex);
            pcond.wait(lock, [this]()
                       { return pc > n || ((pc % 5 == 0) && (pc % 3)); });
            if (pc > n)
                break;
            printBuzz();
            pc++;
            pcond.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz)
    {
        while (true)
        {
            unique_lock<std::mutex> lock(pmutex);
            pcond.wait(lock, [this]()
                       { return pc > n || (pc % 15 == 0); });
            if (pc > n)
                break;
            printFizzBuzz();
            pc++;
            pcond.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber)
    {
        while (true)
        {
            unique_lock<std::mutex> lock(pmutex);
            pcond.wait(lock, [this]()
                       { return pc > n || ((pc % 5) && (pc % 3)); });
            if (pc > n)
                break;
            printNumber(pc);
            pc++;
            pcond.notify_all();
        }
    }
};

// Using automic variable
// Runtime: 52 ms, faster than 32.67% of C++ online submissions for Fizz Buzz Multithreaded.
// Memory Usage: 6.8 MB, less than 13.43% of C++ online submissions for Fizz Buzz Multithreaded.
class FizzBuzzAt
{
private:
    int n;
    atomic_int pc{1};

public:
    FizzBuzz(int n)
    {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz)
    {
        while (true)
        {
            if (pc > n)
                break;
            if ((pc % 5) && (pc % 3 == 0))
            {
                printFizz();
                pc++;
            }
            std::this_thread::sleep_for(std::chrono::nanoseconds(1));
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz)
    {
        while (true)
        {
            if (pc > n)
                break;
            if ((pc % 5 == 0) && (pc % 3))
            {
                printBuzz();
                pc++;
            }
            std::this_thread::sleep_for(std::chrono::nanoseconds(1));
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz)
    {
        while (true)
        {
            if (pc > n)
                break;
            if (pc % 15 == 0)
            {
                printFizzBuzz();
                pc++;
            }
            std::this_thread::sleep_for(std::chrono::nanoseconds(1));
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber)
    {
        while (true)
        {
            if (pc > n)
                break;
            if ((pc % 5) && (pc % 3))
            {
                printNumber(pc);
                pc++;
            }
            std::this_thread::sleep_for(std::chrono::nanoseconds(1));
        }
    }
};