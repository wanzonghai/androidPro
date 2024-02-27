//
// Created by ybpcn on 2023/10/8.
//

#ifndef HEADER_BUFFER_H
#define HEADER_BUFFER_H

#include <stdint.h>

class Buffer {

protected:
    uint8_t *bytes_ = nullptr;
    size_t size_ = 0;
private:
    bool is_mmap_ = 0;

public:
    Buffer() = default;

    Buffer(const char *path);

    Buffer(int fd, size_t size);

    ~Buffer();

    uint8_t *data() const;

    size_t size() const;

    int writeToFile(const char *path, mode_t mode);
};

#endif //HEADER_BUFFER_H
