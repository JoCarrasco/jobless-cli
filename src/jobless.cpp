#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>

int handle_command(const std::vector<std::string> &args);
int add(const std::vector<std::string> &args);
std::vector<std::string>
get_remaining_args(const int taken_index, const std::vector<std::string> &args);

int main(int argc, char *argv[]) {
  std::vector<std::string> args;
  for (int i = 1; i < argc; ++i) {
    args.push_back(argv[i]);
  }

  int status = handle_command(args);
  return status;
}

int handle_command(const std::vector<std::string> &args) {
  if (args.size() < 2) {
    std::cerr << "Error: Not enough arguments provided." << std::endl;
    return 1;
  }

  const std::string &main_command = args[0];
  const std::string &subcommand = args[1];
  if (main_command == "add") {
    std::vector<std::string> remaining_args = get_remaining_args(0, args);
    add(remaining_args);
  }
  return 0;
}

std::vector<std::string>
get_remaining_args(const int taken_index,
                   const std::vector<std::string> &args) {
  if (taken_index < 0 || taken_index >= args.size()) {
    // If the index is out of bounds, return an empty vector
    return {};
  }

  // Correctly constructs a new vector from the iterator range [start_iterator,
  // end_iterator)
  return {args.begin() + taken_index, args.end()};
}

// NOTE(unused): When stable, integrate with other changes.
int add(const std::vector<std::string> &args) {
  // Here we have only several options to add.
  // Interactive and Single Line
  sqlite3 *DB;
  int exit = 0;
  exit = sqlite3_open("example.db", &DB);

  if (exit) {
    std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
    return (-1);
  } else {
    std::cout << "Opened Database Successfully!" << std::endl;
    sqlite3_close(DB);
    return (0);
  }

  const std::string &companyName = args[0];
  const std::string &jobTitle = args[1];
  const std::string &jobDescription = args[2];
  const std::string &jobType = args[3];
  const std::string &jobUrl = args[4];
}
