REM find the working directory
cd %~dp0
mkdir target
cd target

REM create the runner
"C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/bin/amd64/cl" ^
    -I"C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/include" ^
    -I"C:/Program Files/Microsoft SDKs/Windows/v7.1/Include" ^
    -I"../../../../../../" ^
    "../../../../../../cutest-1.5/CuTest.c" ^
    "../../Contact.cpp" ^
    "../ContactTest.cpp" ^
    "../../Option.cpp" ^
    "../OptionTest.cpp" ^
    "../AllTests.c" ^
    /TP /O1 /EHsc /MT /link -subsystem:console ^
    "C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/lib/amd64/comsupp.lib" ^
    "C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/lib/amd64/comsuppd.lib" ^
    "C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/lib/amd64/comsuppw.lib" ^
    "C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/lib/amd64/comsuppwd.lib" ^
    "C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/lib/amd64/delayimp.lib" ^
    "C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/lib/amd64/libcmt.lib" ^
    "C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/lib/amd64/libcmtd.lib" ^
    "C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/lib/amd64/libcpmt.lib" ^
    "C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/lib/amd64/libcpmt1.lib" ^
    "C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/lib/amd64/libcpmtd.lib" ^
    "C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/lib/amd64/libcpmtd0.lib" ^
    "C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/lib/amd64/libcpmtd1.lib" ^
    "C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/lib/amd64/oldnames.lib" ^
    "C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/lib/amd64/ptrustm.lib" ^
    "C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/lib/amd64/ptrustmd.lib" ^
    "C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/lib/amd64/ptrustu.lib" ^
    "C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/lib/amd64/ptrustud.lib" ^
    "C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/lib/amd64/runtmchk.lib" ^
    "C:/Program Files/Microsoft SDKs/Windows/v7.1/lib/x64/*.lib" /out:AllTests.exe

REM run the runner
AllTests.exe
pause
