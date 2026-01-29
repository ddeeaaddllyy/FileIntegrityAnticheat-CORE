#include "../model/Snapshot.h"
#include <fstream>

void save_snapshot(const Snapshot& s, const std::string& file) {
    std::ofstream out(file, std::ios::binary);
    size_t count = s.files.size();
    out.write((char*)&count, sizeof(count));

    for (auto& f : s.files) {
        auto path = f.path.string();
        size_t len = path.size();

        out.write((char*)&len, sizeof(len));
        out.write(path.data(), len);
        out.write((char*)&f.size, sizeof(f.size));
        out.write((char*)f.hash.data(), 32);
    }
}

Snapshot load_snapshot(const std::string& file) {
    Snapshot s;
    std::ifstream in(file, std::ios::binary);

    size_t count;
    in.read((char*)&count, sizeof(count));

    if (count == 0 || count > 1'000'000) {
        throw std::runtime_error("Baseline corrupted (invalid file count)");
    }

    for (size_t i = 0; i < count; ++i) {
        FileRecord r;
        size_t len;
        in.read((char*)& len, sizeof(len));

        std::string path(len, '\0');
        in.read(path.data(), len);
        r.path = path;

        in.read((char*)&r.size, sizeof(r.size));
        in.read((char*)r.hash.data(), 32);

        s.files.push_back(r);
    }

    return s;
}
