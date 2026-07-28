# Algorithm and Data Structures

The idea of this repository is to implement in C++ some of the most important algorithms and data structures in order for beginners to have a reference while studying them.

__Every algorithm in this repository is a direct implementation of the one showed in `Introduction to Algorithms` by Cormen, Leiserson, Rivest and Stein.__

Refer to the book [here](https://dl.ebooksworld.ir/books/Introduction.to.Algorithms.4th.Leiserson.Stein.Rivest.Cormen.MIT.Press.9780262046305.EBooksWorld.ir.pdf).

## Contents

| Folder | Description |
| --- | --- |
| [LinkedList](LinkedList) | Doubly linked list template (`insertAtHead`, `insertAtEnd`, `insertAtIndex`, `find`, `remove`, `show`). |
| [Disjoint_Set](Disjoint_Set) | Disjoint-set (union-find) with union by rank and path compression (`makeSet`, `findSet`, `unionSet`). |
| [LinkedListHashTable](LinkedListHashTable) | Hash table with chaining, using separate `LinkedList` buckets and the multiplication method. |
| [OpenAddressingHashTable](OpenAddressingHashTable) | Hash table with open addressing, using double hashing for probing. |
| [RedBlackTree](RedBlackTree) | Self-balancing binary search tree with `insert`, `remove`, rotations and color fix-up. |
| [Graph](Graph) | Directed weighted graph loaded from a text file, with DFS, BFS, topological sort, Bellman-Ford, Dijkstra, strongly connected components, and MST via Kruskal and Prim (built on top of `Disjoint_Set`). |
| [HuffmanEncoding](HuffmanEncoding) | Huffman tree built from character frequencies in a text file, with encoding/decoding of the input. |

## Structure

Each folder is a self-contained example: a data structure (as a header/implementation pair, e.g. `X.h`/`X.cpp`) plus a `main.cpp` that exercises it. Templated structures declare their methods in `X.h`, which in turn includes `X.cpp` for the implementation, so only the header needs to be included from `main.cpp`.

## Requirements

- A C++17-capable compiler (`g++` or `clang++`); no other tools or external libraries are needed.
- Only the standard library is used, so the examples build the same way on Linux, macOS, and Windows (via MinGW or WSL).

## Building and running an example

There is no shared build system — each folder is compiled independently. For example, to build and run the `LinkedList` example:

```bash
cd LinkedList
g++ -std=c++17 *.cpp -o main
./main
```

The same pattern (`cd <folder> && g++ -std=c++17 *.cpp -o main && ./main`) applies to every folder. Some examples (`Graph`, `HuffmanEncoding`) read an input file from their own directory (`GRP.txt`, `Lorem.txt`), so run the resulting binary from inside that folder.

## Examples

What each bundled `main.cpp` prints when run. Where the bundled example doesn't print anything on its own, a minimal snippet is given instead.

### LinkedList

Builds a list from `{"foo", "bar"}`, prints it, removes `"foo"`, and prints it again:

```
foo -> bar ->
bar ->
```

### Disjoint_Set

The bundled `main.cpp` only calls `makeSet`/`unionSet` and prints nothing by itself. Adding one lookup after the unions:

```cpp
set.unionSet(1, 2);
set.unionSet(2, 2);
set.unionSet(3, 3);
cout << set.findSet(1)->getValue() << endl;
```

shows that `1` was merged into `2`'s set:

```
2
```

### LinkedListHashTable

Inserts `{"ciccio", "cane", "pippo"}` into a 10-bucket table (bucket = string length hashed with the multiplication method) and dumps every bucket:

```
0: pippo ->
1:
2:
3:
4: cane ->
5:
6:
7: ciccio ->
8:
9:
```

### OpenAddressingHashTable

Inserts `{"foo", "bar"}` into a 30-slot table (both hash to the same key, `3`, since the key is the string length, so `"bar"` probes to slot `7` via double hashing), dumps the table, then looks up `"foo"`:

```
0:
1:
2:
3: foo
4:
5:
6:
7: bar
8:
...            (9-29 are empty)
Element found at index: 3
```

### RedBlackTree

The bundled `main.cpp` seeds the tree with unseeded `rand()`, so its printed values differ on every run/platform. Using fixed values instead:

```cpp
RedBlackTree<int> tree;
tree.insert(10);
tree.insert(20);
tree.insert(30);
tree.show();
```

triggers the classic left-rotation case and prints:

```
L----20(b)
|  L----10(r)
|  R----30(r)
```

### Graph

Loading `GRP.txt` (15 vertices, 20 edges) prints progress from the file-parsing constructor itself:

```
Vertecis: 15
Edges: 20
Loading completed successfully.
Loaded Vertices: 15
Loaded Edges: 20
```

### HuffmanEncoding

`encode()` writes the encoded bits to `encoded_<file>` rather than stdout, and the tree built from `Lorem.txt` has too many nodes to list here. `preorderTraversal()` prints one `{characters, frequency}` line per node (root first); building the tree from the short input `"aaab"` instead:

```
{ba, 4}
{b, 1}
{a, 3}
```
