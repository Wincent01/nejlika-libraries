#pragma once

#include <filesystem>

namespace std {
    struct hash2
    {
        std::size_t operator()(const std::filesystem::path& path) const
        {
            return std::hash<std::string>{}(path.string());
        }
    };
}

namespace nejlika
{
    using filepath_hash = std::hash2;
}
