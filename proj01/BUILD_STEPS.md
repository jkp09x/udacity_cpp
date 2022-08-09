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

### Udacity Workspace 
#### Environment Variables
```env``` command
```
HOSTNAME=ac4836a8055b
TURTLEBOT_3D_SENSOR=asus_xtion_pro
TERM=xterm-color
TURTLEBOT_STACKS=hexagons
ROS_ROOT=/opt/ros/kinetic/share/ros
TURTLEBOT_SIMULATION=false
ROS_PACKAGE_PATH=/opt/ros/kinetic/share
ROS_MASTER_URI=http://localhost:11311
ROS_PYTHON_VERSION=2
ROS_VERSION=1
TURTLEBOT_RAPP_PACKAGE_WHITELIST=[rocon_apps, turtlebot_rapps]
LD_LIBRARY_PATH=/opt/ros/kinetic/lib:/opt/ros/kinetic/lib/x86_64-linux-gnu
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
WORKSPACEDOMAIN=udacity-student-workspaces.com
CXXFLAGS=-std=c++17
TURTLEBOT_SERIAL_PORT=/dev/kobuki
PATH=/opt/ros/kinetic/bin:/root/miniconda3/bin:/opt/pytorch/bin:/opt/utils/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/opt/VirtualGL/bin:/opt/TurboVNC/bin:/opt/swift/swift-4.0.3-RELEASE-ubuntu16.04/usr/bin
PWD=/home/workspace
TURTLEBOT_BASE=kobuki
TURTLEBOT_RAPP_PACKAGE_BLACKLIST=[]
STAR_ID=autonomouscpu-nkpvduca
NODE_ENV=development
ROSLISP_PACKAGE_DIRECTORIES=
HOST_IP=172.17.0.1
CXX=g++-7
TURTLEBOT_TYPE=turtlebot
SHLVL=3
HOME=/root
ROS_DISTRO=kinetic
LIBGL_ALWAYS_SOFTWARE=1
TURTLEBOT_BATTERY=/sys/class/power_supply/BAT0
TURTLEBOT_MAP_FILE=/opt/ros/kinetic/share/turtlebot_navigation/maps/willow-2010-02-18-0.10.yaml
PYTHONPATH=/opt/ros/kinetic/lib/python2.7/dist-packages
TURTLEBOT_INTERACTIONS_LIST=[turtlebot_bringup/admin.interactions, turtlebot_bringup/documentation.interactions, turtlebot_bringup/pairing.interactions, turtlebot_bringup/visualisation.interactions]
PKG_CONFIG_PATH=/opt/ros/kinetic/lib/pkgconfig:/opt/ros/kinetic/lib/x86_64-linux-gnu/pkgconfig
LESSOPEN=| /usr/bin/lesspipe %s
GOPATH=/opt/web-terminal/gocode
WORKSPACEID=r845225c907079xREACTaj99nmrb
CMAKE_PREFIX_PATH=/opt/ros/kinetic
DISPLAY=:1
TURTLEBOT_NAME=turtlebot
LESSCLOSE=/usr/bin/lesspipe %s %s
ROS_ETC_DIR=/opt/ros/kinetic/etc/ros
_=/usr/bin/env
```

#### io2d
PWD: /usr/local/include/io2d/
total 668
drwxr-xr-x 2 root root  4096 May 29  2020 ./
drwxrwxr-x 1 root root  4096 May 29  2020 ../
-rw-r--r-- 1 root root  1907 May 29  2020 io2d.h
-rw-r--r-- 1 root root   512 May 29  2020 io2d_cairo_xlib.h
-rw-r--r-- 1 root root 21365 May 29  2020 test_process.h
-rw-r--r-- 1 root root  5630 May 29  2020 test_renderer.h
-rw-r--r-- 1 root root  2422 May 29  2020 xbrushes.h
-rw-r--r-- 1 root root  3076 May 29  2020 xbrushes_impl.h
-rw-r--r-- 1 root root 41431 May 29  2020 xcairo.h
-rw-r--r-- 1 root root  5332 May 29  2020 xcairo_brushes_impl.h
-rw-r--r-- 1 root root 15231 May 29  2020 xcairo_helpers.h
-rw-r--r-- 1 root root 58730 May 29  2020 xcairo_paths_impl.h
-rw-r--r-- 1 root root 17270 May 29  2020 xcairo_surface_state_props_impl.h
-rw-r--r-- 1 root root 42130 May 29  2020 xcairo_surfaces_image_impl.h
-rw-r--r-- 1 root root  6223 May 29  2020 xcairo_surfaces_impl.h
-rw-r--r-- 1 root root 18607 May 29  2020 xcolor.h
-rw-r--r-- 1 root root    43 May 29  2020 xdiagnostics.h
-rw-r--r-- 1 root root 11040 May 29  2020 xgraphicsmath.h
-rw-r--r-- 1 root root 25041 May 29  2020 xgraphicsmath_impl.h
-rw-r--r-- 1 root root  9816 May 29  2020 xgraphicsmathfloat.h
-rw-r--r-- 1 root root 24666 May 29  2020 xgraphicsmathfloat_impl.h
-rw-r--r-- 1 root root   131 May 29  2020 xinput.h
-rw-r--r-- 1 root root  2208 May 29  2020 xinterchangebuffer.h
-rw-r--r-- 1 root root  4881 May 29  2020 xio2d.h
-rw-r--r-- 1 root root   110 May 29  2020 xio2d_cairo_main.h
-rw-r--r-- 1 root root   342 May 29  2020 xio2d_cairo_xlib_main.h
-rw-r--r-- 1 root root 28051 May 29  2020 xio2d_cairo_xlib_output_surfaces.h
-rw-r--r-- 1 root root  5572 May 29  2020 xio2d_cairo_xlib_surfaces.h
-rw-r--r-- 1 root root 28002 May 29  2020 xio2d_cairo_xlib_surfaces_impl.h
-rw-r--r-- 1 root root 14221 May 29  2020 xio2d_cairo_xlib_unmanaged_output_surfaces.h
-rw-r--r-- 1 root root  7875 May 29  2020 xio2d_impl.h
-rw-r--r-- 1 root root 24637 May 29  2020 xpath.h
-rw-r--r-- 1 root root 47048 May 29  2020 xpath_impl.h
-rw-r--r-- 1 root root 20396 May 29  2020 xpathbuilder_impl.h
-rw-r--r-- 1 root root 23086 May 29  2020 xsurfaces.h
-rw-r--r-- 1 root root  1607 May 29  2020 xsurfaces_enums.h
-rw-r--r-- 1 root root 38741 May 29  2020 xsurfaces_impl.h
-rw-r--r-- 1 root root 21055 May 29  2020 xsurfacesprops_impl.h
-rw-r--r-- 1 root root   593 May 29  2020 xsystemheaders.h
-rw-r--r-- 1 root root   131 May 29  2020 xtext.h


