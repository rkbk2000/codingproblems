// Suppose we have a class:

// public class Foo {
//   public void first() { print("first"); }
//   public void second() { print("second"); }
//   public void third() { print("third"); }
// }
// The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().

// Note:

// We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seem to imply the ordering. The input format you see is mainly to ensure our tests' comprehensiveness.

// Example 1:

// Input: nums = [1,2,3]
// Output: "firstsecondthird"
// Explanation: There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(), thread B calls second(), and thread C calls third(). "firstsecondthird" is the correct output.
// Example 2:

// Input: nums = [1,3,2]
// Output: "firstsecondthird"
// Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(), and thread C calls second(). "firstsecondthird" is the correct output.

// Testcase:
// [1,2,3]
// [1,3,2]

// Output:
// "firstsecondthird"
// "firstsecondthird"

// Runtime: 144 ms, faster than 57.82% of C++ online submissions for Print in Order.
// Memory Usage: 7 MB, less than 88.10% of C++ online submissions for Print in Order.

// https: //leetcode.com/problems/print-in-order/

class Foo
{
  std::mutex mx;
  std::condition_variable cv;
  atomic_int val{1};

public:
  Foo()
  {
  }

  void first(function<void()> printFirst)
  {
    std::unique_lock<std::mutex> lck(mx);
    while (val != 1)
      cv.wait(lck);

    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    val++;
    cv.notify_all();
  }

  void second(function<void()> printSecond)
  {

    std::unique_lock<std::mutex> lck(mx);
    while (val != 2)
      cv.wait(lck);

    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    val++;
    cv.notify_all();
  }

  void third(function<void()> printThird)
  {
    std::unique_lock<std::mutex> lck(mx);
    while (val != 3)
      cv.wait(lck);

    // printThird() outputs "third". Do not change or remove this line.
    printThird();
    val++;
    cv.notify_all();
  }
};

// Another solution with atomic and sleep
// Runtime: 128 ms, faster than 71.32% of C++ online submissions for Print in Order.
// Memory Usage: 7.2 MB, less than 59.49% of C++ online submissions for Print in Order.
class FooAtomicSleep
{
  atomic_int val{1};

public:
  Foo()
  {
  }

  void first(function<void()> printFirst)
  {
    while (val != 1)
    {
      std::this_thread::sleep_for(std::chrono::nanoseconds(100));
    }

    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    val++;
  }

  void second(function<void()> printSecond)
  {

    while (val != 2)
      std::this_thread::sleep_for(std::chrono::nanoseconds(100));

    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    val++;
  }

  void third(function<void()> printThird)
  {
    while (val != 3)
      std::this_thread::sleep_for(std::chrono::nanoseconds(100));

    // printThird() outputs "third". Do not change or remove this line.
    printThird();
    val++;
  }
};

// Without sleep
// Runtime: 1512 ms, faster than 8.76% of C++ online submissions for Print in Order.
// Memory Usage: 7.1 MB, less than 88.10% of C++ online submissions for Print in Order.
class FooAtomic
{
  atomic_int val{1};

public:
  Foo()
  {
  }

  void first(function<void()> printFirst)
  {
    while (val != 1)
      ;

    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    val++;
  }

  void second(function<void()> printSecond)
  {

    while (val != 2)
      ;

    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    val++;
  }

  void third(function<void()> printThird)
  {
    while (val != 3)
      ;

    // printThird() outputs "third". Do not change or remove this line.
    printThird();
    val++;
  }
};

// Using promise
// Runtime: 140 ms, faster than 62.03% of C++ online submissions for Print in Order.
// Memory Usage: 7.4 MB, less than 15.44% of C++ online submissions for Print in Order.
class Foo
{
  promise<void> ps, pt;

public:
  Foo()
  {
  }

  void first(function<void()> printFirst)
  {

    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    ps.set_value();
  }

  void second(function<void()> printSecond)
  {

    ps.get_future().get();

    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    pt.set_value();
  }

  void third(function<void()> printThird)
  {
    pt.get_future().get();

    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
};