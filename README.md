# ♻️ Push Swap

**Push Swap** is a sorting algorithm challenge from the 42 curriculum.  
The goal: sort a stack of integers using only **a limited set of operations** — as few as possible.  

It’s not just about sorting numbers — it’s about **building efficient algorithms**, mastering **data structures**, and optimizing **logic under constraints**.

---

## 🧠 Project Overview

You start with two stacks:
- **Stack A** — contains all the integers (unsorted)
- **Stack B** — empty at the start

Your mission:  
Use a predefined list of stack operations to **sort Stack A in ascending order**, using **Stack B as temporary storage**.

---

## ⚙️ Allowed Operations

| Command | Description |
|----------|-------------|
| `sa` | Swap the first 2 elements of stack A |
| `sb` | Swap the first 2 elements of stack B |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the top of B onto A |
| `pb` | Push the top of A onto B |
| `ra` | Rotate A upward (first becomes last) |
| `rb` | Rotate B upward |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate A (last becomes first) |
| `rrb` | Reverse rotate B |
| `rrr` | `rra` and `rrb` at the same time |

Your program must output a list of these instructions that sorts the numbers perfectly.

---

## 🧩 Example

```bash
$ ./push_swap 2 1 3 6 5 8
sa
ra
pb
pb
sa
ra
pa
pa
```
- The output above is one possible valid sequence of operations that sorts the input.

---

## 🧱 Building the Project

Compile everything using the included Makefile:
- make


This creates the executable:

- push_swap


Other useful commands:

- make clean     # Remove object files
- make fclean    # Remove all generated files
- make re        # Rebuild everything

---

## 🖋️ Author

Balica Virgil Eduard | Intra: bavirgil
42 Student | Algorithmic masochist in training

“Sorting numbers with pain and precision — one push at a time.” ♻️
