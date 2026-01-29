//
// Created by deadly on 29.01.2026.
//

#pragma once
#ifndef ECHOENGINE_RULEENGINE_H
#define ECHOENGINE_RULEENGINE_H
#include "../../model/Snapshot.h"
#include <iostream>

template<typename Predicate>
void apply_rule(const Snapshot& snap, Predicate rule) {
    for (const auto& f : snap.files)
        if (rule(f))
            std::cout << "[RULE HIT] " << f.path << "\n";
}

#endif