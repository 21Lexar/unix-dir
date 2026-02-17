#ifndef STRUCT_H
#define STRUCT_H
#include<vector>

enum file_permission {
    READ,
    WRITE,
    READ_WRITE,
};

struct file{
    char* name;
    char* type;
    directory *parent;
    char* owner;
    file_permission permission;
};

struct directory{
    char* name;
    directory *parent;
    std::vector<directory> *sub_directory;
};

#endif