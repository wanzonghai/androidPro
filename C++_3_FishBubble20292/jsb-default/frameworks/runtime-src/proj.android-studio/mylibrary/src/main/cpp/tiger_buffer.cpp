//
// Created by ybpcn on 2023/10/8.
//
#include <cstdio>
#include <cstring>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <cerrno>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include <cstdlib>
#include <dirent.h>
#include <sys/mman.h>
#include <libgen.h>

#include <fcntl.h>
#include <zconf.h>
#include <malloc.h>
#include <sys/types.h>
#include <stdio.h>

#include "tiger_JNIUtils.h"
#include "tiger_buffer.h"






Buffer::Buffer(int fd, size_t size) {
    uint8_t *addr;
    if ((addr = (uint8_t *) mmap(nullptr, size, PROT_READ, MAP_SHARED, fd, 0)) != MAP_FAILED) {
        bytes_ = addr;
        size_ = size;
        is_mmap_ = true;
    } else {
        LOGE("mmap");
    }
}

Buffer::Buffer(const char *path) {
    if (!path) return;

    LOGD("Attempt to read %s", path);

    bytes_ = nullptr;
    size_ = 0;

    auto fd = open(path, O_RDONLY);
    if (fd == -1) {
        LOGE("open %s", path);
        close(fd);
        return;
    }
    size_ = lseek(fd, 0, SEEK_END);
    if (size_ == -1) {
        LOGE("lseek %s", path);
        close(fd);
        return;
    }
    lseek(fd, 0, SEEK_SET);

    bytes_ = static_cast<uint8_t *>(malloc(size_));
    if (read_full(fd, bytes_, size_) == -1) {
        size_ = 0;
        free(bytes_);
        bytes_ = nullptr;
    }
    close(fd);
}

Buffer::~Buffer() {
    LOGD("~Buffer %p", bytes_);
    if (!bytes_) return;
    if (is_mmap_)
        munmap(bytes_, size_);
    else
        free(bytes_);
}

uint8_t *Buffer::data() const {
    return bytes_;
}

size_t Buffer::size() const {
    return size_;
}

int Buffer::writeToFile(const char *path, mode_t mode) {
    if (!bytes_) return -1;

    auto dir = dirname(path);
    mkdirs(dir, mode);

    int fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, mode);
    if (fd == -1) {
        LOGE("open %s", path);
        return -1;
    }

    if (write_full(fd, bytes_, size_) == -1) {
        close(fd);
        LOGE("write");
        return -1;
    }
    return fd;
}
