# RunTimeFramework

A lightweight C-based web framework for building simple HTTP servers. This project provides a basic structure for handling routes, controllers, and commands, inspired by modern web frameworks but implemented in C for performance and low-level control.

## Table of Contents
- [Features](#features)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Commands](#commands)
- [Contributing](#contributing)
- [License](#license)

## Features
- Simple routing system for HTTP GET requests.
- Modular controller-based architecture.
- Command-line interface for building, serving, and watching the project.
- Lightweight and minimal dependencies.
- Extensible for custom routes and commands.

## Project Structure
```
RunTimeFramework/
├── app/
│   ├── Controllers/
│   │   ├── HomeController.c
│   │   └── AboutController.c
│   └── Routes/
│       └── web.c
├── src/
│   ├── Commands/
│   │   ├── build_command.c
│   │   ├── serve_command.c
│   │   └── watch_command.c
│   ├── commandLoad.c
│   ├── app.c
│   └── app.h
├── main.c
├── Makefile
└── README.md
```

- **app/Controllers/**: Contains logic for handling HTTP requests (e.g., home, about pages).
- **app/Routes/**: Defines the web routes for the application.
- **src/Commands/**: Includes CLI commands like build, serve, and watch.
- **src/**: Core framework logic, including the HTTP server and command loader.
- **main.c**: Entry point of the application.
- **Makefile**: Build script for compiling the project.

## Installation
1. **Clone the repository**:
   ```bash
   git clone https://github.com/your-repo/RunTimeFramework.git
   cd RunTimeFramework
   ```

2. **Install dependencies**:
   - Ensure you have `gcc` installed on your system.
   - For the `watch` command, install `entr` (optional):
     ```bash
     sudo apt-get install entr  # On Ubuntu/Debian
     ```

3. **Build the project**:
   ```bash
   make
   ```
   This will compile the project and generate an executable named `server`.

## Usage
1. **Run the server**:
   ```bash
   ./server
   ```
   The server will start on `http://localhost:8080`. Available routes:
   - `/`: Home page
   - `/about`: About page
   - `/me`: Personal page

2. **Run with commands**:
   Use the command-line interface to manage the project:
   ```bash
   ./server <command>
   ```
   See [Commands](#commands) for details.

## Commands
- **build**: Compiles the project into an executable.
  ```bash
  ./server build
  ```
- **serve**: Runs the compiled server.
  ```bash
  ./server serve
  ```
- **watch**: Watches for file changes and rebuilds/runs the server automatically (requires `entr`).
  ```bash
  ./server watch
  ```

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make your changes and commit (`git commit -m "Add feature"`).
4. Push to your branch (`git push origin feature-branch`).
5. Open a pull request.

Please ensure your code follows the existing style and includes appropriate tests.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.