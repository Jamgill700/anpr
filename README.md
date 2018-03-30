# Overview
##Prerequisites:
- Windows 10, 8.1, or 7
- Visual Studio 2017 or Visual Studio 2015 Update 3
- Git

You'll need the following packages installed vis powershell (may take some time)
- [vcpkg](https://github.com/Microsoft/vcpkg)
- [cppresksdk](https://github.com/Microsoft/cpprestsdk)

## Note
When you try to include the c++ standard <mutex> header file in a C++/CLI file you will get an error similar to:
```
error C1189: #error :  <mutex> is not supported when compiling with /clr or /clr:pure.
```
To avoid this, you need to set the properties of the alpr.cpp file and change the 'Common Language RunTime Support' to No Common Language RunTime Support (See image below for example)

![alt text](https://github.com/pjvance/OpenAlpr_Forms_Demo/blob/master/alpr_cpp_properties.png)

## Example
The following image is an example use of the demo
![alt text](https://github.com/pjvance/OpenAlpr_Forms_Demo/blob/master/2018-03-30.png)
