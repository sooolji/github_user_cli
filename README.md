# GitHub User Activity CLI

A simple command-line interface tool written in C++ to fetch and display a GitHub user's recent public activity.

## App Flow

![App Flow diagram](flow.png)

## Usage

```bash
./github-activity <username>
```

## Tools Used

1. **libcurl**: A free, highly portable, thread-safe, and feature-rich client-side URL transfer library supporting numerous protocols including HTTP, HTTPS, FTP, and SMTP.
2. **nlohmann/json**: Often referred to as "JSON for Modern C++," it's a popular open-source, header-only library that simplifies working with JSON data in C++. It provides an intuitive syntax and integrates seamlessly with C++'s Standard Template Library (STL).

## Building

To build the project, you need `cmake` and `make` installed on your system.

```bash
mkdir build
cd build
cmake ..
make
```

## Let's Work Together

This project is open-source and I would love your help to make it even better! Whether you are a beginner looking for your first open-source contribution or an advanced C++ developer, all kinds of contributions are welcome:

- **Found a bug?** Open an issue with a description and steps to reproduce.
- **Have a feature idea?** Open an issue to discuss it, or directly submit a Pull Request!
- **Documentation:** Help me improve this README or the inner code comments.

### Quick Start for Contributors

1. Fork the repository.
2. Clone your fork: `git clone https://github.com/yourusername/github_user_cli.git`
3. Create a new branch: `git checkout -b feature/my-cool-feature`
4. Make your changes and commit: `git commit -m "Add some cool feature"`
5. Push to your branch and open a Pull Request!

## Some Cool Stuff (Future Features)

Want to help out? Here are some awesome features we can add next:

- **Terminal Colors & Styling:** Add ANSI color codes or use a nice library like `fmt` to color-code different GitHub events (e.g., green for `PushEvent`, yellow for `StarEvent`).
- **Filtering System:** Add flags to filter activity. For example: `github-activity username --type IssuesEvent` or `--limit 5`.
- **Export Features:** Add an option to export a user's recent activity to a Markdown or CSV file for report generation.
