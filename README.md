# ELF Parser
This is a fork of the original ELF Parser by Jacob Baines. The current focus is to get it building properly on all of its targets, get the various libraries up to date, and perform miscelaneous housekeeping. 

## Compile Targets
ELF Parser has a number of compilation targets that can be configured by CMakeLists.txt. The targets are:
* Unit tests
* CLI build
* GUI build
* Windows build

## How do I compile it?
ELF Parser can be compiled on Windows, OS X, or Linux (demangling and unit tests don't work on Windows). Windows uses the VS 2010 project in the base directory for compilation whereas Linux/OS X uses CMake.

### Linux
Compiling the GUI version on Linux goes like this (currently working on Ubuntu 24.04):

#### Install all the needed developmnent packages
```
sudo apt-get install build-essential cmake qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools libbz2-dev liblzma-dev libzstd-dev
```

#### Download shelf and make a build directory
```
git clone https://github.com/jandress/shelf.git
cd ~/shelf
```

#### Build the project (GUI)
```
mkdir build
cd build
cmake -Dqt=ON ..
make
```

#### Build the project (CLI)
```
mkdir build
cd build
cmake -Dcli=ON ..
make
```

### Windows
NOTE: boost is no longer required to build shelf. Updated instructions for Windows will be along shortly.

Compiling the GUI version on Windows goes like this (work in progress on Windows 10):

Get a coffee and a snack, take a deep breath, and buckle in.

#### Install Chocolatey
```
@powershell -NoProfile -ExecutionPolicy Bypass -Command "iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))" && SET PATH=%PATH%;%ALLUSERSPROFILE%\chocolatey\bin
```
#### Install the required development packages
```
choco install visualstudio2022community --package-parameters "--add Microsoft.VisualStudio.Workload.NativeDesktop --add Microsoft.VisualStudio.Workload.NativeCrossPlat --includeRecommended --includeOptional" -y
```
You will probably need to reboot here

#### Install vcpkg
```
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
.\vcpkg integrate install
```

Yes, there is an option to install vcpkg in the Visual Studio installer now, ymmv.

#### Configure vcpkg
```
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
.\vcpkg integrate install
```

Watch for this in the output:

CMake projects should use: "-DCMAKE_TOOLCHAIN_FILE=C:/Users/admin/Downloads/vcpkg/scripts/buildsystems/vcpkg.cmake"

Save the portion of the line in quotes as it will be needed later

#### Install required libraries with vcpkg

```
.\vcpkg install boost sqlite3 bzip2 liblzma zstd qt5-base
```

These will take a looooooong time to install, maybe take up a new hobby or learn a language

If you have trouble getting boost to install (you will), it may be your Visual Studio environment. You can download pkg-mgr (https://github.com/mingw-io/pkg-mgr/releases) and run 'pkg-mgr.exe --info' to see what potential issues may be present. If you have more than one Visual Studio environment installed, this will likely not work. If you have an older verison than current (2022 as of now) installed, this will likely not work.

#### Download shelf and make a build directory

```
git clone https://github.com/jandress/shelf.git
cd shelf
mkdir build
cd build
```

#### Build the project
```
cmake .. -G "Visual Studio 17 2022" <DCMAKE_TOOLCHAIN_FILE string from earlier goes here>  -Dqt=ON
cmake --build . --config Release
```

### macOS
Work in progress

## CLI Usage
The user can pass in a single file (-f) or a directory (-d) of files:
```
./elfparser-cli --help
options:
  --help                 A list of command line options
  --version              Display version information
  -f [ --file ] arg      The ELF file to examine
  -d [ --directory ] arg The directory to look through.
  -r [ --reasons ]       Print the scoring reasons
  -c [ --capabilities ]  Print the files observed capabilities
  -p [ --print ]         Print the ELF files various parsed structures.
```
## Example Output
```
/elfparser-cli -f /bin/ls -c -r
/bin/ls - Score: 6
---- Scoring Reasons ----
4 -> Process manipulation functions
2 -> Environment variable manipulation
---- Detected Capabilities ----
    File Functions
        fclose() found
    Process Manipulation
        raise() found
    Environment Variables
        getenv() found

```
```
./elfparser-cli -f ~/Desktop/malwr.BillGates -r -c
/home/charlie/Desktop/malwr.BillGates - Score: 241
---- Scoring Reasons ----
8 -> Network functions
24 -> Process manipulation functions
8 -> Information gathering
8 -> Environment variable manipulation
3 -> Syslog manipulation functions
20 -> Shell commands
50 -> Packed
60 -> Hard coded IPv4 addresses
10 -> Anti debug techniques
50 -> Dropper functionaltiy
---- Detected Capabilities ----
    File Functions
        fclose() found
        feof() found
        fopen() found
        funlockfile() found
        unlink() found
    Network Functions
        accept() found
        bind() found
        connect() found
        inet_addr() found
        listen() found
        recv() found
        sendto() found
        socket() found
    Process Manipulation
        clone() found
        daemon() found
        execve() found
        fork() found
        kill() found
        raise() found
    Random Functions
        rand() found
        random_r() found
        srand() found
        srandom_r() found
    Information Gathering
        Examines /proc/cpuinfo
        Examines /proc/meminfo
        Examines /proc/stat
        access() found
        fstat() found
        getpagesize() found
        phys_pages_info() found
        uname() found
    Environment Variables
        clearenv() found
        getenv() found
        setenv() found
        unsetenv() found
    System Log
        closelog() found
        openlog() found
        vsyslog() found
    Shell
        chmod 0755 %s
        system() found
    Packed
        UPX copyright string found
        UPX signature found
    IP Addresses
        1.0.0.0
        1.0.0.1
        10.0.0.0
        10.255.255.255
        127.0.0.0
        127.0.0.1
        127.255.255.255
        172.16.0.0
        172.31.255.255
        192.168.0.0
        192.168.255.255
        254.255.255.254
        255.0.0.0
        8.8.4.4
        8.8.8.8
    Anti-Debug
        Fake dynamic symbol table in sections
    Dropper
        Embedded ELF binary found at file offset 0xb7730 (751408)
```
## Source License
GPLv3. See the LICENSE file.