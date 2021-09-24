# Disable Fast Travel for VR

Disable fast travel in the map menu and fix UI bugs that prevent placing custom markers.

This is a VR example using [vr_address_tools](https://github.com/alandtse/vr_address_tools) and a modified [commonlibvr](https://github.com/alandtse/CommonLibVR/tree/vr). However, please note the offset is not correct at [FastTravelmanager.cpp:14](https://github.com/alandtse/Disable-Fast-Travel/blob/main/src/FastTravelManager.cpp#L14).

## Requirements
* [CMake](https://cmake.org/)
	* Add this to your `PATH`
* [PowerShell](https://github.com/PowerShell/PowerShell/releases/latest)
* [Vcpkg](https://github.com/microsoft/vcpkg)
	* Add the environment variable `VCPKG_ROOT` with the value as the path to the folder containing vcpkg
* [Visual Studio Community 2019](https://visualstudio.microsoft.com/)
	* C++ Clang tools for Windows
	* Desktop development with C++

## Register Visual Studio as a Generator
* Open `x64 Native Tools Command Prompt`
* Run `cmake`
* Close the cmd window

## Building
```
git clone https://github.com/alandtse/Disable-Fast-Travel
cd Disable-Fast-Travel
```

### SSE
```
git submodule update --init --recursive
cmake -B build -S .
```

### VR
Set environment variable `CommonLibVRPath` to CommonLibVR location.
```
cmake -B build -S . DBUILD_SKYRIMVR=ON
```
