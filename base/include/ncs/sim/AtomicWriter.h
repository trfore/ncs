#pragma once
#include <functional>
#include <vector>

namespace ncs {

namespace sim {

template<typename T>
class AtomicWriter {
public:
  AtomicWriter();
  void write(T* location, const T& value);
  void commit(std::function<void(T*, const T&)> op);
  static void Add(T* location, const T& value);
  static void Or(T* location, const T& value);
  static void Set(T* location, const T& value);
private:
  std::vector<T*> locations_;
  std::vector<T> values_;
};

} // namespace sim

} // namespace ncs

#include <ncs/sim/AtomicWriter.hpp>

