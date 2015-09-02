REM find the working directory
cd %~dp0
cd ..\..\
mkdir target\tests\
cd target\tests

REM create the runner
mkdir objects
cd objects
"C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/bin/amd64/cl" -I"C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/include" -I"C:/Program Files/Microsoft SDKs/Windows/v7.1/Include" "../../../lib/cutest-1.5/CuTest.c" -Tc"../../../libraries/networking/esp8266/contactInfo.cpp" "../../../src/test/c/esp_contactInfo.c" "../../../src/test/c/AllTests.c" /O1 /EHsc /link -subsystem:console "C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/lib/amd64/*.lib" "C:/Program Files/Microsoft SDKs/Windows/v7.1/lib/x64/*.lib" /out:../AllTests.exe
cd ..

REM run the runner
AllTests.exe
pause
