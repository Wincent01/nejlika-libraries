#pragma once

#include <filesystem>
#include <ostream>
#include <boost/json.hpp>

namespace nejlika
{

void json_pretty_print(std::ostream &os, boost::json::value const &jv, std::string *indent = nullptr);

void export_json(boost::json::value const &jv, std::filesystem::path const &path);

}
