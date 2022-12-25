#pragma once

class Resource {
private:
    int size;

public:
    Resource(int _size = 0) : size(_size) {}

    int getSize() const { return size; }
};

int some_free(const Resource& obj, int x);

