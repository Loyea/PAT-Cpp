## How to run these codes in CLion?
To run single C/C++ file, you need install `C/C++ Single File Execution` plugin in CLion Preferences - Plugins.

When first time you open this project, if `cmake-build-debug` directory not exists, you may need to go to `File` menu
and click `Reload CMake Project` option to make CLion create `cmake-build-debug` directory.

Once you add a new C/C++ file, right click on the new C/C++ file editor, click the `add executable for single c/cpp file`
option, then you can run this single C/C++ file.