#ifndef FILELIST_H
#define FILELIST_H

#include "struct.h"

// Implementing linked list to store a list of files.

file_node* insert_file(
        directory *parent_directory, 
        file* file_to_insert)
        {

        if(parent_directory == NULL){
                return NULL;
        }

        file_node* new_file = (file_node*)calloc(1, sizeof(file_node));

        if(parent_directory->file_list == NULL){
                parent_directory->file_list = new_file;
                new_file->file_ptr->parent = parent_directory;
                new_file->file_ptr = file_to_insert;
                new_file->next_file = NULL;
                new_file->prev_file = NULL;
                return new_file;
        }

        for(
        file_node *file_itr = parent_directory->file_list; 
        file_itr->next_file != NULL; 
        file_itr = file_itr->next_file)
        {

                file_itr->next_file = new_file;
                new_file->prev_file = file_itr;
                new_file->next_file = NULL;
                return new_file;
        }
        
}

file_node* delete_file(
        directory *parent_directory,
        file* file_to_delete)
        {

        if(parent_directory == NULL){
                return NULL;
        }

        if(file_to_delete == NULL){
                return NULL;
        }

        for(
        file_node* file_itr = parent_directory->file_list;
        file_itr->next_file != NULL; 
        file_itr = file_itr->next_file)
        {
                if(file_itr->file_ptr == file_to_delete){
                        if(file_itr->next_file){
                                file_node* temp_prev = file_itr->prev_file;
                                temp_prev->next_file = file_itr->next_file; 
                                file_itr->next_file->prev_file = temp_prev;
                                file_itr->next_file = NULL;
                                file_itr->prev_file = NULL;
                                file_itr = NULL;
                                free(file_itr);
                                file_itr = NULL;
                        }
                        else if(file_itr->prev_file && !file_itr->next_file){
                                file_node* temp_prev = file_itr->prev_file;
                                temp_prev->next_file = NULL; 
                                free(file_itr);
                                file_itr = NULL;
                        }
                        else if(!file_itr->next_file && !file_itr->prev_file){
                                free(file_itr);
                                file_itr = NULL;
                        }
                }
        }      
}


#endif