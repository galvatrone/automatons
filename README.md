# Automatons

Small C++ programs for a formal languages and automata course. Each automaton lives in its own folder and is a single self-contained source file.

| Folder | Automaton | Alphabet | What it does |
|--------|-----------|----------|--------------|
| `dfa/`  | Deterministic finite automaton (DFA) | `{0, 1}` | Enumerates binary words and prints those accepted by a 4-state DFA |
| `nfa/`  | Nondeterministic finite automaton (NFA) | `{0, 1}` | Explores every path of a 9-state NFA for a given word |
| `enfa/` | NFA with epsilon transitions (e-NFA) | `{0, 1}` | Explores every path, including epsilon moves, for several test words |
| `rls/`  | DFA state equivalence (table filling) | `{0, 1}` | Builds the distinguishability table for an 8-state DFA, used for minimization |

## Build and run

Requires any C++17 compiler (g++ or clang++).

```sh
g++ -std=c++17 -O2 -o dfa/dfa dfa/dfa.cpp && ./dfa/dfa
g++ -std=c++17 -O2 -o nfa/nfa nfa/nfa.cpp && ./nfa/nfa
g++ -std=c++17 -O2 -o enfa/enfa enfa/enfa.cpp && ./enfa/enfa
g++ -std=c++17 -O2 -o rls/rls rls/rls.cpp && ./rls/rls
```

## dfa

Start and accepting state: `A`. The automaton accepts words with an even number of `0`s and an even number of `1`s.

```
+------+-----+-----+
|      |  0  |  1  |
+------+-----+-----+
| ->*A |  B  |  C  |
|    B |  A  |  D  |
|    C |  D  |  A  |
|    D |  C  |  B  |
+------+-----+-----+
```

The program walks through the first 500 binary words and prints the path of every accepted one:

```
->C->A  (Accepted)[11]
->C->D->C->A  (Accepted)[1001]
->C->D->B->A  (Accepted)[1010]
->C->A->B->A  (Accepted)[1100]
```

## nfa

Start state `1`, accepting state `9`. The input word is set in `main` (`0010011` by default). Every path is printed, and the word is accepted if at least one path ends in `9`.

```
+------+-------+-------+
|      |  0=R  |  1=B  |
+------+-------+-------+
| -> 1 |  2,4  |  5    |
|    2 |  4,6  | 1,5,3 |
|    3 |  2,6  |  5    |
|    4 |  2,8  | 1,5,7 |
|    5 |2,4,6,8|1,3,7,9|
|    6 |  2,8  | 3,5,9 |
|    7 |  4,8  |  5    |
|    8 |  4,6  | 7,5,9 |
|   *9 |  8,6  |  5    |
+------+-------+-------+
```

Example output fragment:

```
0010011
->1->2->4->1->2->4->1->5 (Rejected)
->1->2->4->1->2->4->5->9 (Accepted)
...
(Accepted)
```

## enfa

Start state `A`, accepting state `D`. Column `E` lists epsilon transitions. The program checks the words `111`, `11`, `011`, `000`, `0`, `01`, `1`, `010`.

```
+------+-------+-------+----+
|      |  0=R  |  1=B  |  E |
+------+-------+-------+----+
| -> A |   E   |   B   |    |
|    B |       |   C   |  D |
|    C |       |   D   |    |
|   *D |       |       |  D |
|    E |   F   |       | B,C|
|    F |   D   |       |    |
+------+-------+-------+----+
```

Example output:

```
111
->A->B->C->D (Accepted)
->A->B->D (Rejected)
(Accepted)
11
->A->B->C (Rejected)
->A->B->D (Rejected)
 (Rejected)
```

## rls

Table-filling algorithm for an 8-state DFA (states `A`-`H`, accepting state `C`). For every pair of states the program tests binary words and marks the pair `x` if some word is accepted from one state and rejected from the other, and `o` if no such word was found (the states are equivalent and can be merged).

```
+------+-----+-----+
|      |  0  |  1  |
+------+-----+-----+
|    A |  B  |  F  |
|    B |  G  |  C  |
|   *C |  A  |  C  |
|    D |  C  |  G  |
|    E |  H  |  F  |
|    F |  C  |  G  |
|    G |  G  |  E  |
|    H |  G  |  C  |
+------+-----+-----+
```

Resulting table (lower triangle):

```
A
B x
C x  x
D x  x  x
E o  x  x  x
F x  x  x  o  x
G x  x  x  x  x  x
H x  o  x  x  x  x  x
  A  B  C  D  E  F  G  H
```

Equivalent pairs: `A = E`, `B = H`, `D = F`, so the minimal DFA has 5 states.
