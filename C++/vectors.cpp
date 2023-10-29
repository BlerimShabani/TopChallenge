#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

void removeDuplicate(std::vector<int>& vec) {
  std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}

int main() {
  std::vector<int> numbers = {5, 8, 9, 6, 5};
  for (auto& num : numbers) {
    std::cout << num << " ";
  }
  std::cout << "\nInsertion at a Specific Position" << std::endl;
  numbers.insert(numbers.begin() + 2, 100);
  for (auto& num : numbers) {
    std::cout << num << " ";
  }
  std::cout << "\nFinding and Removing:" << std::endl;

  auto it = std::find(numbers.begin(), numbers.end(), 5);
  std::cout << *it << std::endl;
  if (it != numbers.end()) {
    numbers.erase(it);
  }

  for (auto& num : numbers) {
    std::cout << num << " ";
  }
  /*Reverse vector*/

  std::vector<int> vec = {3, 4, 5, 6, 9, 6};
  std::cout << "\nOriginal vector:";
  for (auto& v : vec) {
    std::cout << v << " ";
  }

  std::reverse(vec.begin(), vec.end());
  std::cout << "\nReverse vector: ";
  for (auto& v : vec) {
    std::cout << v << " ";
  }

  /*
   * Maximum value of vector
   */

  auto maxValue = *std::max_element(numbers.begin(), numbers.end());
  auto minValue = *std::min_element(numbers.begin(), numbers.end());
  std::cout << "\nMax value:" << maxValue << std::endl;
  std::cout << "\nMin value:" << minValue << std::endl;

  int maxValues = vec[0];
  for (auto& v : vec) {
    if (v > maxValues) {
      maxValues = v;
    }
  }
  std::cout << "Max:" << maxValues << std::endl;

  for (size_t i = 0; i < vec.size(); i++) {
    if (vec[i] > maxValues) {
      maxValues = vec[i];
    }
  }
  std::cout << "Maximum:" << maxValues << std::endl;

  /*Find the Average of Vector Elements:*/
  std::vector<int> averageNum{5, 9, 8, 7, 6, 5, 6, 9};
  double sum = std::accumulate(averageNum.begin(), averageNum.end(), 0);
  double average = sum / averageNum.size();
  std::cout << "\nAverage:" << average << std::endl;

  // or another way manual
  std::vector<int> numberss{6, 9, 8, 7, 8, 5, 4};
  double sumNum = 0;
  for (size_t i = 0; i < numberss.size(); i++) {
    sumNum += numberss[i];
  }
  double averageNumbers = sumNum / numberss.size();
  std::cout << "Average classic way: " << averageNumbers;
  std::cout << "\n";

  // Remove element
  std::vector<int> numberDelete{5, 8, 9, 7, 6, 8, 9, 7, 9};

  auto iter = std::remove(numberDelete.begin(), numberDelete.end(), 9);

  for (auto& num : numberDelete) {
    std::cout << num << " ";
  }
  std::cout << "\n";

  numberDelete.erase(iter, numberDelete.end());

  for (auto& n : numberDelete) {
    std::cout << n << " ";
  }
  std::cout << "\n";
  // Append on vector to another vecto
  std::vector<int> vec1{1, 2, 3};
  std::vector<int> vec2{2, 5, 6};
  vec1.insert(vec1.end(), vec2.begin(), vec2.end());
  for (auto& v : vec1) {
    std::cout << v << " ";
  }

  /*
   Count Occurrences of a Specific Value:
   */
  std::cout << "\n";
  std::vector<int> occurencies{2, 7, 8, 5, 6, 6, 9};
  int valueCount = 6;
  int count = std::count(occurencies.begin(), occurencies.end(), valueCount);
  std::cout << valueCount << " appear" << count << " times" << std::endl;

  /*
  Check if Vector is Sorted:
  */
  std::vector<int> vecSorted{1, 7, 8, 5, 6};
  bool isSorted = std::is_sorted(vecSorted.begin(), vecSorted.end());
  std::cout << "Vector is   " << (isSorted ? "sorted" : "unsorted")
            << std::endl;

  /*
   *Exercise: Merge and Remove Duplicates
   */
  std::vector<int> num1{1, 6, 7, 8, 9};
  std::vector<int> num2{1, 6, 7, 4, 5, 3};

  num1.insert(num1.end(), num2.begin(), num2.end());

  std::sort(num1.begin(), num1.end());

  // removing duplicate values
  auto its = std::unique(num1.begin(), num1.end());
  num1.resize(std::distance(num1.begin(), its));

  std::cout << "\nMerged , sorted, and without duplicated:";
  for (auto& vec : num1) {
    std::cout << vec << " ";
  }
  std::cout << "\n";

  // Another way remove dupmicate
  std::vector<int> vectorRemoveDuplicate{3, 6, 7, 8, 9, 6, 7, 8, 5, 9};

  std::set<int> s{vectorRemoveDuplicate.begin(), vectorRemoveDuplicate.end()};
  vectorRemoveDuplicate.assign(s.begin(), s.end());
  std::cout << "Remove duplicate:";
  for (auto& rd : vectorRemoveDuplicate) {
    std::cout << rd << " ";
  }
  std::cout << "\n";
  removeDuplicate(occurencies);
  for (auto& v : occurencies) {
    std::cout << v << " ";
  }
  /*
  * Exercise: Vector Intersection
Objective: Write a C++ program that takes two vectors, finds their intersection
(common elements), and then displays the resultant vector sorted in ascending
order.
  */
  std::vector<int> vecNum1{1, 5, 7, 8, 5, 4, 5, 9, 9};
  std::vector<int> vecNum2{2, 1, 5, 6, 7, 8, 9, 9};

  // set
  std::set<int> set1(vecNum1.begin(), vecNum1.end());

  std::vector<int> intersection;

  for (auto& v : vecNum2) {
    if (set1.find(v) != set1.end()) {
      intersection.push_back(v);
      set1.erase(v);
    }
  }

  std::sort(intersection.begin(), intersection.end());

  std::cout << "\nIntersection of vector 1 and vec2 :   ";
  for (auto& inter : intersection) {
    std::cout << inter << " ";
  }
  std::cout << "\n" << std::endl;

  /*
   *Pointer in vector
   */
  int a = {1};
  int b{2};
  int c{3};

  std::vector<int*> vecPtr;

  vecPtr.push_back(&a);
  vecPtr.push_back(&b);
  vecPtr.push_back(&c);

  std::cout << "\nOriginal values :";
  for (int* ptr : vecPtr) {
    std::cout << *ptr << " ";
  }

  for (auto& ptr : vecPtr) {
    *ptr = *ptr * 2;
  }

  std::cout << "\nModified values:";
  for (int* ptr : vecPtr) {
    std::cout << *ptr << " ";
  }
  std::cout << std::endl;

  return 0;
}