#include <iostream>
#include <thread>
#include <mutex>

class Parent {
 public:
  Parent() {}

  virtual void setValue(int value) {
    // std::lock_guard<std::mutex> lock(m_mutex);
    doSetValue(value);
  }

  virtual int getValue() {
    // std::lock_guard<std::mutex> lock(m_mutex);
    return doGetValue();
  }

   virtual void doSomething(int n) {
        std::lock_guard<std::mutex> lock(m_mutex);
        l_doSomething(n);
    }

 protected:
  virtual void doSetValue(int value) = 0;
  virtual int doGetValue() = 0;
  virtual void l_doSomething(int n) = 0;

 private:
  std::mutex m_mutex;
};

class Child : public Parent {
public:
  Child() {}
  void doSetValue(int value) override{
    m_value = value;
  }

  int doGetValue() override {
    return m_value;
  }

  void l_doSomething(int n) override {
    setValue(n);
    std::cout << "Child: value = " << getValue()<< std::endl;
  }

 private:
  int m_value = 0;
};

int main() {
  Child child;
  std::thread t1([&](){ child.doSomething(1); });
  std::thread t2([&](){ child.doSomething(5); });
  std::thread t3([&](){ child.doSomething(58); });

        t1.join();
        t2.join();
        t3.join();
    

  return 0;
}