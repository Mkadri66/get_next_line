# get\_next\_line

> 42 project: Reading a line from a file descriptor, one line at a time.

---

## 🧠 Purpose

The goal of this project is to implement the `get_next_line` function, which reads a **file line by line** without knowing the length of the line in advance.

The function must work with **file descriptors** (e.g., returned by `open`).

---

## ⚙️ Allowed Functions

* `read`
* `malloc`
* `free`

---

## 📄 Required Function

```c
char *get_next_line(int fd);
```

* `fd`: file descriptor (e.g., from `open`)
* Returns the next line from the file (including the `\n` if present)
* Returns `NULL` on end of file or error

---

## 📁 Project Files

* `get_next_line.c`: main logic
* `get_next_line_utils.c`: helper functions (e.g., `ft_strlen`, `ft_strchr`, etc.)
* `get_next_line.h`: prototypes and includes
* `main.c`: (optional) test file
* `Makefile`

---

## 🧪 Example Usage

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("my_file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

---

## ⚠️ Important Notes

* Correctly handle lines that do **not end with `\n`**
* Avoid **memory leaks** by freeing all allocated memory
* Handle **multiple file descriptors** simultaneously (bonus)

---

## ⭐ Bonus (If Applicable)

* Multiple file descriptor support
* Optimized memory usage
* Compatibility with very large or slow input (e.g., pipes)


---

## 🛠️ Compilation

```bash
make
```

> `BUFFER_SIZE` must be defined at compile time.

---

## 🧼 Cleaning Up

```bash
make clean     # Removes object files
make fclean    # Removes object files and executable
make re        # Clean and recompile
```

---

## 👤 Author

* [Mkadri66](https://github.com/Mkadri66)

---

## 📚 Useful Resources

* `man read`
* `man open`
* `man malloc`
* [https://en.cppreference.com/w/c/io](https://en.cppreference.com/w/c/io)
