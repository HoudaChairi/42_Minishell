# 🐚 Minishell - 42 Project

A custom shell implementation in C as part of the 42 curriculum. **Minishell** replicates the behavior of a Unix shell, handling commands, environment variables, pipes, redirections, and more. This project provides an excellent opportunity to deepen your understanding of processes, system calls, and input/output redirection.

---

## 📋 Table of Contents

- [📖 Introduction](#introduction)
- [✨ Features](#features)
- [⚙️ Installation](#installation)
- [🚀 Usage](#usage)
- [📜 Commands Supported](#commands-supported)
- [🎯 Project Goals](#project-goals)
  
---

## 📖 Introduction

**Minishell** is a simple shell program that emulates basic functionalities of Bash. The project adheres to the requirements outlined by the 42 curriculum, focusing on:

- **System programming**
- **Process control**
- **Memory management**

---

## ✨ Features

- 🔄 **Interactive Mode:** Provides a prompt for user commands.
- 🏃 **Execution of Commands:** Runs executables from the system PATH.
- 🌐 **Environment Variables:** Handles `$VARIABLE` expansion.
- 🔗 **Pipes (`|`):** Supports command chaining via pipes.
- 📤 **Redirections (`>`, `<`, `>>`):** Redirects input/output streams.
- 🔧 **Built-in Commands:**
  - `echo`
  - `cd`
  - `pwd`
  - `export`
  - `unset`
  - `env`
  - `exit`
- 🛡️ **Signal Handling:** Proper handling of `Ctrl+C`, `Ctrl+D`, and `Ctrl+\`.
- ❌ **Error Handling:** Displays descriptive error messages for invalid commands.

---

## ⚙️ Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/HoudaChairi/42_Minishell.git
   cd 42_Minishell
   make
   ```
## 🚀 Usage

### Start the shell:
```bash
./minishell
```

---

## 📜 Commands Supported

| **Command** | **Description**                           |
|-------------|-------------------------------------------|
| `echo`      | 🗣️ Print arguments to the standard output. |
| `cd`        | 📂 Change the current working directory.   |
| `pwd`       | 📍 Print the current directory.            |
| `export`    | 📤 Set environment variables.              |
| `unset`     | ❌ Unset environment variables.            |
| `env`       | 🌐 Display environment variables.          |
| `exit`      | 🚪 Exit the shell.     

---

## 🎯 Project Goals

- 🧠 **Learn system programming concepts.**

- 🛠️ **Gain a deeper understanding of:**
  - Process creation and management (`fork`, `exec`, `wait`).
  - File descriptors and redirection.
  - Unix signals.

- 💻 **Develop a robust and user-friendly application.**
