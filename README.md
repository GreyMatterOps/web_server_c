# C HTTP Server (From Scratch) 🚧

A simple HTTP server written in C using POSIX sockets.
Built to understand how web servers work at a low level.

---

## Status

Work in progress.

---

## Features

* Creates and binds a socket
* Listens for connections
* Accepts client requests
* Reads HTTP request data
* Sends a basic "Hello, World!" response

---

## Requirements

* GCC
* Linux / macOS / WSL

---

## Build & Run

```bash
gcc test.c Server.c -o server
./server
```

---

## Usage

Open in browser:
http://localhost:8081

---

## Notes

* Same response is returned for all requests
* Browser may send multiple requests (e.g., `/favicon.ico`)
* This is a learning project, not production-ready
