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

Compiling the GUI version on Linux goes like this (currently working on Ubuntu 24.04):

```
sudo apt-get install build-essential cmake libboost-all-dev qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools libbz2-dev liblzma-dev libzstd-dev

git clone https://github.com/jandress/shelf.git

cd ~/shelf

mkdir build

cd build/

cmake -Dqt=ON ..

make
```
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