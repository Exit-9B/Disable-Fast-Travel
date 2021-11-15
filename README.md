# Disable Fast Travel for SSE/VR

Disable fast travel in the map menu and fix UI bugs that prevent placing custom markers.

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
git clone https://github.com/Exit-9B/Disable-Fast-Travel.git
cd Disable-Fast-Travel

```
### CommonLibSSE/CommonLibVR
```
# pull CommonLibSSE and CommonLibVR
# alternatively, override by setting environment variable `CommonLibSSEPath` or `CommonLibVRPath` if you need something different from extern

git submodule update --init --recursive

```
### SSE

```
cmake -B build -S .
```

### VR
```
cmake -B build -S . DBUILD_SKYRIMVR=ON
```
