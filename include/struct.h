#ifndef STRUCT_H
#define STRUCT_H

#include<stdlib.h>
#include<time.h>

enum file_permission {
    READ,
    WRITE,
    READ_WRITE,
};


typedef struct{
    char* name;
    char* type;
    char* owner;
    enum file_permission permission;
    time_t time_created;
    time_t time_modified;
    directory *parent;
} file;


typedef struct{
    char* name;
    directory *parent_directory;
    directory *sub_directory;
    file_node* file_list;
} directory;


typedef struct{
    file* file_ptr;
    file_node* prev_file;
    file_node* next_file;
} file_node;

typedef struct{
    directory* dir_list;
    sub_dir_node* prev_dir;
    sub_dir_node* next_dir;
} sub_dir_node;


#endif