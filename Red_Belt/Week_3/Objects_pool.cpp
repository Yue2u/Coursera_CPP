#include test_runner.h

#include algorithm
#include string
#include queue
#include stdexcept
#include set
using namespace std;

template class T
class ObjectPool {
public
  T Allocate();
  T TryAllocate();

  void Deallocate(T object);

  ~ObjectPool();

private
  queueT free;
  setT allocated;
};

template typename T
T ObjectPoolTAllocate() {
  if (free.empty()) {
    free.push(new T);
  }
  auto ret = free.front();
  free.pop();
  allocated.insert(ret);
  return ret;
}

template typename T
T ObjectPoolTTryAllocate() {
  if (free.empty()) {
    return nullptr;
  }
  return Allocate();
}

template typename T
void ObjectPoolTDeallocate(T object) {
  if (allocated.find(object) == allocated.end()) {
    throw invalid_argument();
  }
  allocated.erase(object);
  free.push(object);
}

template typename T
ObjectPoolT~ObjectPool() {
  for (auto x  allocated) {
    delete x;
  }
  while (!free.empty()) {
    auto x = free.front();
    free.pop();
    delete x;
  }
}
