# Setting up for MacOS
Notes and updates on the build steps based on the links provided in the course
as well as modifications needed in order to build locally on MacOS Monterey.

## Steps
1. Clone CppND-Route-Planning-Project to desired location
```
git clone git@github.com:udacity/CppND-Route-Planning-Project.git --recurse-submodules
```
2. Clone third-party repos in <>/CppND-Route-Planning-Project/thirdparty/
```
git clone git@github.com:cpp-io2d/P0267_RefImpl.git --recurse-submodules
```
3. Download and untar the the latest version of the clang+llvm tools in the same third-party directory
[CLANG+LLVM-14.0.6 as of
08/06/2022](https://github.com/llvm/llvm-project/releases/download/llvmorg-14.0.6/clang+llvm-14.0.6-x86_64-apple-darwin.tar.xz)
```
tar -xvzf clang+llvm-14.0.6-x86_64-apple-darwin.tar.xz
```
4. Set environment variables
> **Warning**
> Change <project path> to the absolute path of your project directory
```
export CXXFLAGS="-nostdinc++ -isystem<project path>/CppND-Route-Planning-Project/thirdparty/CppND-Route-Planning-Project/thirdparty/clang/include/c++/v1"

export LDFLAGS="$LDFLAGS -L/opt/X11/lib -L/opt/local/lib -L/usr/local/lib"

export LDFLAGS="-L<project path>/CppND-Route-Planning-Project/thirdparty/CppND-Route-Planning-Project/thirdparty/clang/lib -Wl,-rpath,<project path>/CppND-Route-Planning-Project/thirdparty/CppND-Route-Planning-Project/thirdparty/clang/lib"
```
5. Install brew
6. Install libpng
```
brew install libpng
```
7. Install cmake
```
brew install cmake
```
8. Generate io2d XcodeProject by first navigating to the P0267_RefImpl folder
```
mkdir Debug && cd Debug
cmake -G "Xcode" -DIO2D_DEFAULT=COREGRAPHICS_MAC ../.
```
9. Open & Run io2d project by clicking COMMAND+B in Xcode
```
open io2d.xcodeproj
run project
```


## Reference
- https://github.com/cpp-io2d/P0267_RefImpl
- https://github.com/udacity/CppND-Route-Planning-Project/blob/master/README.md
- https://github.com/cpp-io2d/P0267_RefImpl/blob/master/BUILDING.md
- https://ssvaddiparthy.medium.com/setting-up-the-cppnd-route-planning-project-on-mac-751a6122fb78

