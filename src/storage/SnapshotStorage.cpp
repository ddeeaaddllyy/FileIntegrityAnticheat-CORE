#include "../model/Snapshot.h"
#include <fstream>

void save_snapshot(const Snapshot& snapshot, const std::string& file) {
    std::ofstream out(file, std::ios::binary);
    size_t count = snapshot.files.size();
    out.write((char*)&count, sizeof(count));

    for (const auto& record_file : snapshot.files) {
        auto path = record_file.path.string();
        size_t length = path.size();

        out.write((char*)&length, sizeof(length));
        out.write(path.data(), length);
        out.write((char*)&record_file.size, sizeof(record_file.size));
        out.write((char*)record_file.hash.data(), 32);
    }

    out.close();
}

Snapshot load_snapshot(const std::string& file) {
    Snapshot snapshot;
    std::ifstream in(file, std::ios::binary);

    size_t count;
    in.read((char*)&count, sizeof(count));

    if (count == 0 || count > 1'000'000) {
        throw std::runtime_error("Baseline corrupted (invalid file count)");
    }

    for (size_t i = 0; i < count; ++i) {
        FileRecord record;
        size_t length;
        in.read((char*)& length, sizeof(length));

        std::string path(length, '\0');
        in.read(path.data(), length);
        record.path = path;

        in.read((char*)&record.size, sizeof(record.size));
        in.read((char*)record.hash.data(), 32);

        snapshot.files.push_back(record);
    }

    in.close();

    return snapshot;
}
