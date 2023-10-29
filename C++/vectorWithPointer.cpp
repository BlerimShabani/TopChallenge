#include <algorithm>
#include <iostream>
#include <vector>

class Student {
public:
  Student(const std::string& name, int grade) : name(name), grade(grade) {}

  int getGrade() const { return grade; }

  void display() const {
    std::cout << "Student: " << name << ", Grade: " << grade << std::endl;
  }

private:
  std::string name;
  int grade;
};

int main() {
  // List of students stored as pointers
  std::vector<Student*> students;
  students.push_back(new Student("Alice", 85));
  students.push_back(new Student("Bob", 90));
  students.push_back(new Student("Charlie", 78));
  students.push_back(new Student("David", 92));

  // Sort students based on grades in descending order
  std::sort(students.begin(), students.end(),
            [](const Student* a, const Student* b) {
              return a->getGrade() > b->getGrade();
            });

  std::cout << "Students sorted by grades:" << std::endl;

  // Display the sorted students
  for (const Student* student : students) {
    student->display();
  }

  // Clean up dynamically allocated memory
  for (Student* student : students) {
    delete student;
  }

  return 0;
}
