#include <cstring>
  
class IntArray {
  int *array;
  std::size_t nElems;
public:
  // ...
 
  ~IntArray() {
    delete[] array;
  }
 
  
  IntArray(const IntArray& that); // nontrivial copy constructor
  IntArray& operator=(const IntArray &rhs) {
    if (this != &rhs) {
      delete[] array;
      array = nullptr;
      nElems = rhs.nElems;
      if (nElems) {
        array = new int[nElems];
        std::memcpy(array, rhs.array, nElems * sizeof(*array));
      }
    }
    return *this;
  }
 
  // ...
};

int main() {
  IntArray i1 = new IntArray();
  int temp_array[5] = {1,2,3,4,5};
  i1.array = temp_array;
  i1.nElems = sizeof(temp_array) / sizeof(int);
  IntArray i2 = i1;
  return 0;
}