#ifndef ACTIVITY_PARSER_H
#define ACTIVITY_PARSER_H

#include <nlohmann/json.hpp>

using json = nlohmann::json;

// class for processing string json data and format it for output
class ActivityParser {
private:
  json data;

public:
  ActivityParser() = default;
  ~ActivityParser() = default;

  std::string formatOutput(const std::string &json_data);
};

#endif