#include <iostream>
#include <cassert>
#include <stdexcept>
#include <string>

class Student {
  public:
    // Constructor
    Student(std::string name, int grade, double gpa)
      : name_(name), grade_(grade), gpa_(gpa)
    {
      ValidateGrade();
      ValidateGpa();
    }
    
    // getters/accessors
    std::string Name()
    {
      return name_;
    }
    int Grade()
    {
      return grade_;
    }
    double Gpa()
    {
      return gpa_;
    }

    // setters/mutators
    void Name(std::string name)
    {
      name_ = name;
    }
    void Grade(int grade)
    {
      grade_ = grade;
      ValidateGrade();
    }
    void Gpa(double gpa)
    {
      gpa_ = gpa;
      ValidateGpa();
    }

  private:
    std::string name_;
    int grade_;
    double gpa_;
    void ValidateGrade()
    {
      if ( grade_ < 0 || grade_ > 12 )
      {
        throw std::invalid_argument("invalid grade");
      }
    }
    void ValidateGpa()
    {
      if ( gpa_ < 0 || gpa_ > 4.0 )
      {
        throw std::invalid_argument("invalid gpa");
      }
    }
};

int main()
{
  // Valid Data Test
  Student student("John Doe", 4, 3.9);
  assert(student.Name() == "John Doe");
  assert(student.Grade() == 4);
  assert(student.Gpa() == 3.9);

  // Validation Checks - Grade
  bool myException{false};
  try {
    student.Grade(-100);
  }
  catch (...)
  {
    myException = true;
  }
  assert(myException);

  bool myException1{false};
  try {
    student.Grade(13);
  }
  catch (...)
  {
    myException1 = true;
  }
  assert(myException1);

  // Validation Checks - Gpa
  bool myException2{false};
  try {
    student.Gpa(-1.1);
  }
  catch (...)
  {
    myException2 = true;
  }
  assert(myException2);
  
  bool myException3{false};
  try {
    student.Gpa(5.3);
  }
  catch (...)
  {
    myException3 = true;
  }
  assert(myException3);
}

