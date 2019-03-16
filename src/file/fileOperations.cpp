//
// Created by Matt Robinson on 2019-03-16.
//

#include "fileOperations.h"

int test()
{
    return 0;
}

bool isFileOpen(std::ifstream & file)
{
    return file.is_open();
}

bool isFileOkay(std::ifstream & file)
{
    return file.good();
}