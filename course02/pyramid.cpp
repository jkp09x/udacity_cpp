#include <iostream>
#include <cassert>

class Pyramid
{
  public:
    // Default Contructor with initializer list
    Pyramid(int length, int width, int height) 
      : length_(length), width_(width), height_(height) {
      Validate();
    }

    // Setter Functions
    void Length(int length)
    {
      length_ = length;
      Validate();
    }
    void Width(int width)
    {
      width_ = width;
      Validate();
    }
    void Height(int height)
    {
      height_ = height;
      Validate();
    }

    // Getter functions
    int Length()
    {
      return length_;
    }
    int Width()
    {
      return width_;
    }
    int Height()
    {
      return height_;
    }

    // Member Functions
    double Volume()
    {
      return (length_ * width_ * height_) / 3.0;
    }

  private:
    int length_;
    int width_;
    int height_;
    void Validate()
    {
      if (length_ <= 0 || width_ <= 0 || height_ <= 0)
      {
        throw std::invalid_argument("negative dimension");
      }
    }
};

int main()
{
  Pyramid pyramid(4, 5, 6);
  assert(pyramid.Length() == 4);
  assert(pyramid.Width() == 5);
  assert(pyramid.Height() == 6);
  assert(pyramid.Volume() == 40);

  bool caught{false};
  try {
    Pyramid invalid(-1, 2, 3);
  } catch (...) {
    caught = true;
  }
  assert(caught);
  return 0;
}
