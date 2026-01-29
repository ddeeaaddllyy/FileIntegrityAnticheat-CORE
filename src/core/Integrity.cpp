#include "../model/Snapshot.h"
#include <unordered_map>
#include <iostream>

bool compare(const Snapshot& trusted, const Snapshot& current) {
    std::unordered_map<std::string, FileRecord> base;

    for (auto& f : trusted.files)
        base[f.path.string()] = f;

    bool ok = true;

    for (auto& f : current.files) {
        auto it = base.find(f.path.string());

        if (it == base.end()) {
            std::cout << "[ADDED] " << f.path << "\n";
            ok = false;
        } else if (it->second.hash != f.hash) {
            std::cout << "[MODIFIED] " << f.path << "\n";
            ok = false;
        }
    }

    return ok;
}
