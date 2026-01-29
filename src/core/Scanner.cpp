#include "../model/Snapshot.h"
#include <filesystem>

std::array<uint8_t, 32> hash_file(const std::filesystem::path&);

Snapshot scan_directory(const std::filesystem::path& root) {
    Snapshot snap;

    for (const auto& e : std::filesystem::recursive_directory_iterator(root)) {
        if (!e.is_regular_file())
            continue;

        FileRecord r;
        r.path = e.path();
        r.size = e.file_size();
        r.hash = hash_file(r.path);

        snap.files.push_back(r);
    }

    return snap;
}
