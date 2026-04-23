#include "../include/activity_parser.h"

std::string ActivityParser::formatOutput(const std::string &json_data) {

  try {
    data = json::parse(json_data);
  } catch (json::parse_error &e) {
    return "error parsing JSON data: " + std::string(e.what());
  }
  if (data.empty() || !data.is_array()) {
    return "no recent was activity found for this user.";
  }
  std::string output; // this will hold the formatted output string, declaring
                      // it here so if theirs is a fail in parsing we can return
                      // an error message instead of an empty string
  for (const auto &event : data) {

    // using .value() allows to give ("Unknown") if the key doesn't exist,
    // instead of throwing an exception (core dump)

    std::string type = event.value("type", "Unknown Event");

    std::string repo_name = "Unknown Repo";
    if (event.contains("repo") && event["repo"].contains("name")) {
      repo_name = event["repo"]["name"].get<std::string>();
    }

    std::string created_at = event.value("created_at", "Unknown Date");

    output += "Event Type: " + type + "\n";
    output += "Repository: " + repo_name + "\n";
    output += "Created At: " + created_at + "\n\n";
    if (type == "PushEvent") {
      // very specific for push event, we want to know how many commits were
      // pushed, so we check if the payload and commits keys exist and if
      // commits is an array, then we get the size of the commits array to know
      // how many commits were pushed
      int commits_count = 0;
      if (event.contains("payload") && event["payload"].contains("commits") &&
          event["payload"]["commits"].is_array()) {
        commits_count = event["payload"]["commits"].size();
      }
      output += "- Pushed " + std::to_string(commits_count) + " commits to " +
                repo_name + "\n";
    } else if (type == "WatchEvent") {
      output += "- Starred " + repo_name + "\n";
    } else if (type == "IssuesEvent") {
      output += "- Opened a new issue in " + repo_name + "\n";
    } else {
      output += "- " + type + " in " + repo_name + "\n";
    }
  }

  return output;
}