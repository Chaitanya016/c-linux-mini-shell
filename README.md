# 🐚 C Linux Mini Shell

A minimal Unix-like shell implemented from scratch in C to understand Linux process creation and execution.

---

## 🚀 Features

- Built-in commands:
  - `cd`
  - `pwd`
  - `echo`
  - `exit`
- External command execution using:
  - `fork()`
  - `execvp()`
  - `waitpid()`
- Safe input handling using `fgets()`
- Modular project structure
- Strict compilation flags (`-Wall -Wextra -Werror`)

---

## 🧠 Concepts Demonstrated

This project demonstrates understanding of:

- Process creation (`fork`)
- Program replacement (`execvp`)
- Parent-child synchronization (`waitpid`)
- Working directory management (`chdir`, `getcwd`)
- Environment handling (`getenv`)
- Argument parsing using `strtok`
- Makefile-based build system

---

## 📂 Project Structure
```
c-linux-mini-shell/
├── src/
│   ├── main.c
│   └── shell.c
├── include/
│   └── shell.h
├── Makefile
└── README.md
```