//boost free
#ifndef MAPPEDFILE_HPP
#define MAPPEDFILE_HPP

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <cerrno>
#include <cstring>
#include <stdexcept>

class MappedFile {
public:
    MappedFile() : data_(nullptr), length_(0) {}

    void open(const std::string &filepath, size_t &length) {
        int fd = ::open(filepath.c_str(), O_RDONLY);
        if (fd == -1) {
            throw std::runtime_error("Failed to open file: " + std::string(strerror(errno)));
        }

        struct stat fileInfo;
        if (fstat(fd, &fileInfo) == -1) {
            ::close(fd);
            throw std::runtime_error("Failed to get file info: " + std::string(strerror(errno)));
        }

        length = fileInfo.st_size;
        data_ = static_cast<char*>(mmap(nullptr, length, PROT_READ, MAP_PRIVATE, fd, 0));
        ::close(fd);

        if (data_ == MAP_FAILED) {
            data_ = nullptr;
            throw std::runtime_error("Failed to map file: " + std::string(strerror(errno)));
        }
        length_ = length;
    }

    void close() {
        if (data_ && data_ != MAP_FAILED) {
            munmap(data_, length_);
            data_ = nullptr;
            length_ = 0;
        }
    }

    bool is_open() const {
        return data_ != nullptr;
    }

    const char* data() const { return data_; }
    size_t size() const { return length_; }

private:
    char* data_;
    size_t length_;
};

#endif // MAPPEDFILE_HPP
