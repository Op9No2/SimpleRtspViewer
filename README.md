# SimpleRtspViewer
This repo is simple RTSP viewer using OpenCV, and you can run this on Windows or Linux OS.

## Requirements
- OpenCV 3.0.0 or above
- CMake 2.8 or above
- Visual studio 2015 or above

## How to build
- Linux
```bash
$ git clone https://github.com/Op9No2/SimpleRtspViewer.git
$ cd SimpleRtspViewer/
$ mkdir build
$ cd build/
$ cmake -G "Unix Makefiles" .. -DCMAKE_BUILD_TYPE=RELEASE
$ make
```

- Windows
```bash
% git clone https://github.com/Op9No2/SimpleRtspViewer.git
% cd SimpleRtspViewer/
% mkdir build
% cd build/
% cmake -G"Visual Studio 15" .. -DCMAKE_BUILD_TYPE=RELEASE -DOpenCV_DIR="your opencv folder"
% open SimpleRtspViewer.sln by Visual studio
% Build -> Build Solution
```

## How to use
- Linux
```bash
$ ./SimpeRtspViewer "your RTSP link"
```

- Windows
```bash
% SimpeRtspViewer.exe "your RTSP link"
```
