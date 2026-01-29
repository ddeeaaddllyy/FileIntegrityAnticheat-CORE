//
// Created by deadly on 27.01.2026.
//

#pragma once
#ifndef ECHOENGINE_FILEENTRY_H
#define ECHOENGINE_FILEENTRY_H
#include <array>
#include <filesystem>

struct FileRecord {
    std::filesystem::path   path;
    uintmax_t               size{};
    std::array<uint8_t, 32> hash;
};

#endif