//
// Created by user on 27.01.2026.
//

#pragma once
#ifndef ECHOENGINE_SNAPSHOT_H
#define ECHOENGINE_SNAPSHOT_H
#include <vector>
#include "FileRecord.h"

struct Snapshot {
    std::vector<FileRecord> files;
};

#endif