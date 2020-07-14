//most code from cpplusplus.com
// mutex example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex

std::mutex mtx;           // mutex for critical section

void print_block (int n, char c) {
  // critical section (exclusive access to std::cout signaled by locking mtx):
  mtx.lock();
  for (int i=0; i<n; ++i) { std::cout << c; }
  std::cout << '\n';
  mtx.unlock();
}

int main ()
{
  std::thread th1 (print_block,50,'a');
  std::thread th2 (print_block,50,'b');
  std::thread th3 (print_block,50,'c');

  th1.join();
  th2.join();
  th3.join();

  return 0;
}
