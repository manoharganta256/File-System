
#ifndef BLOCK_FILE_SYSTEM_STRUCTURES_H
#define BLOCK_FILE_SYSTEM_STRUCTURES_H

#define BLOCKSIZE (8*1024)
#define METADATASIZE 1
#define FILESIZE 20
#define BLOCKS 32
#define MAGICNUMBER 0x444e524d

struct command {
    int type;
    char *file_name;
    char *file_name2;
};

struct file {
    char name[FILESIZE];
    unsigned number_of_blocks;
    int block_number;
    unsigned file_length;
};

struct metadata {
    int magic_number;
    int valid_files;
    char occupied[BLOCKS];
    struct file table[BLOCKS];
};

typedef struct command Command;
typedef struct file File;
typedef struct metadata Metadata;

#endif //BLOCK_FILE_SYSTEM_STRUCTURES_H
