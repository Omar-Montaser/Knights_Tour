# ♞ Knights_Tour

A C++ program that attempts to solve the **Closed Knight's Tour Problem** on an `N x N` chessboard using **Warnsdorff's heuristic**.

---

## What is a Closed Knight's Tour?

A closed tour means the knight:

- Visits **every square exactly once**
- Ends up **one knight's move away** from the starting square

---

## How It Works

- Uses **Warnsdorff’s heuristic** to always move to the square with the fewest onward moves.
- Tries to find a valid tour starting from **every square** on the board.
- Prints the tour if found, as a grid of move numbers.

---

## Future Work

- A **Graphical User Interface (GUI)** to visualize the knight's tour interactively.
- Additional knight's tour solving approaches:
  - **Backtracking**
  - **Hybrid algorithms** (e.g., combining heuristics and recursion)

