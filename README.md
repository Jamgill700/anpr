You'll need the following packages installed vis powershell (may take some time)
vcpkg (https://github.com/Microsoft/vcpkg)
cppresksdk (https://github.com/Microsoft/cpprestsdk)

You'll also need to set the properties of the alpr.cpp file so that it can avoid problems with running a mutex inside a CLR app. To do this, you need to right-click in VS2017 --> properties --> C/C++ --> General --> Common Language Runtime... and set it to NO Common Language Runtime Support.

