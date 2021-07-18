// Suppose you are given the following code:

// class FooBar {
//   public void foo() {
//     for (int i = 0; i < n; i++) {
//       print("foo");
//     }
//   }

//   public void bar() {
//     for (int i = 0; i < n; i++) {
//       print("bar");
//     }
//   }
// }
// The same instance of FooBar will be passed to two different threads. Thread A will call foo() while thread B will call bar(). Modify the given program to output "foobar" n times.

// Example 1:

// Input: n = 1
// Output: "foobar"
// Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar(). "foobar" is being output 1 time.
// Example 2:

// Input: n = 2
// Output: "foobarfoobar"
// Explanation: "foobar" is being output 2 times.

// Testcase:
// 1
// 2
// 10

// Output:
// "foobar"
// "foobarfoobar"
// "foobarfoobarfoobarfoobarfoobarfoobarfoobarfoobarfoobarfoobar"

// https://leetcode.com/problems/print-foobar-alternately/

// Runtime: 208 ms, faster than 78.35% of C++ online submissions for Print FooBar Alternately.
// Memory Usage: 8 MB, less than 99.58% of C++ online submissions for Print FooBar Alternately.

class FooBar
{
private:
  int n;
  atomic_int counter{0};

public:
  FooBar(int n)
  {
    this->n = n;
  }

  void foo(function<void()> printFoo)
  {
    for (int i = 0; i < n; i++)
    {
      while (counter % 2)
        std::this_thread::sleep_for(std::chrono::nanoseconds(1));
      // printFoo() outputs "foo". Do not change or remove this line.
      printFoo();
      counter++;
    }
  }

  void bar(function<void()> printBar)
  {
    for (int i = 0; i < n; i++)
    {
      while (counter % 2 == 0)
        std::this_thread::sleep_for(std::chrono::nanoseconds(1));
      // printBar() outputs "bar". Do not change or remove this line.
      printBar();
      counter++;
    }
  }
};

// Runtime: 256 ms, faster than 75.98% of C++ online submissions for Print FooBar Alternately.
// Memory Usage: 8.4 MB, less than 28.07% of C++ online submissions for Print FooBar Alternately.
class FooBarATF
{
private:
  int n;
  std::atomic_flag lockFoo = ATOMIC_FLAG_INIT;
  std::atomic_flag lockBar = ATOMIC_FLAG_INIT;

public:
  FooBar(int n)
  {
    this->n = n;
  }

  void foo(function<void()> printFoo)
  {

    for (int i = 0; i < n; i++)
    {
      while (lockFoo.test_and_set(std::memory_order_acq_rel))
      {
        std::this_thread::yield();
      }
      // printFoo() outputs "foo". Do not change or remove this line.
      printFoo();
      lockBar.clear(std::memory_order_release);
    }
  }

  void bar(function<void()> printBar)
  {
    for (int i = 0; i < n; i++)
    {
      while (lockBar.test_and_set(std::memory_order_acq_rel))
      {
        std::this_thread::yield();
      }
      // printBar() outputs "bar". Do not change or remove this line.
      printBar();
      lockFoo.clear(std::memory_order_release);
    }
  }
};