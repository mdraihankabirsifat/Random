# LeetCode Solution Organization Guide

This directory stores solved LeetCode problems grouped by their primary
algorithm or technique. Future Codex runs should read this file first and
follow the workflow below without requiring the full instructions again.

## Work completed so far

The initial organization pass processed all 31 C++ solutions that were in
`Prev/`:

- Identified the exact LeetCode problem represented by every file.
- Added a short revision comment at the very top of every solution.
- Chose one primary topic based on the technique used in that solution.
- Moved each solution into a consistent topic folder.
- Renumbered files independently inside each topic folder, starting at `1`.
- Preserved every solution body and verified the before/after file count.
- Left `Prev/` with no C++ solution files.
- Later scanned all 33 C++ files under `Leetcode/` for unused macros, removed
  332 unused definitions, retained 60 required definitions, and verified every
  file with `g++ -std=c++17 -fsyntax-only`.

Historical counts immediately after that pass:

| Topic | Files |
| --- | ---: |
| Array | 4 |
| Bit_Manipulation | 2 |
| Dynamic_Programming | 4 |
| Graph | 6 |
| Greedy | 2 |
| Hashing | 1 |
| Math | 2 |
| Prefix_Sum | 1 |
| Segment_Tree | 1 |
| Simulation | 1 |
| Sliding_Window | 3 |
| Sorting | 2 |
| String | 2 |
| **Total** | **31** |

These counts are a historical record, not a permanent expectation. Always
rescan the filesystem because new solutions may have been added afterward.

## Incoming solutions

`A_curr/` is the active area for new or not-yet-organized solutions. When asked to organize
new work, scan both directories as well as the existing topic folders for
unprocessed, duplicated, or incorrectly numbered C++ files.

If a problem cannot be confidently identified, leave it in its incoming
directory and report it. Never invent a title or description.

## Required problem header

Every organized `.cpp` solution must begin with this style of comment:

```cpp
/*
Problem: Course Schedule

Given the number of courses and prerequisite pairs, determine whether
all courses can be completed without encountering a dependency cycle.
*/
```

Header rules:

- Use the exact, clean LeetCode title.
- Write a concise two- or three-line paraphrase for revision.
- Do not copy the full problem statement.
- Put the comment at the absolute top of the file.
- Do not add a second header if a valid one already exists.

## Topic classification

Assign each solution to exactly one primary-topic folder. Choose the topic
that best represents the technique actually used in the file, even when the
LeetCode problem has several tags.

Current established folder names are:

```text
Array/
Bit_Manipulation/
Dynamic_Programming/
Graph/
Greedy/
Hashing/
Math/
Prefix_Sum/
Segment_Tree/
Simulation/
Sliding_Window/
Sorting/
String/
```

Reuse these exact names. Do not create variants such as `DP/`,
`DynamicProgramming/`, or `Bit_manipulation/`. Create a new category only
when an actual solution clearly needs a primary technique not represented by
the existing folders.

## Filename convention

Each topic folder has its own independent, contiguous sequence:

```text
Bit_Manipulation/
├── 1_Gray_Code.cpp
└── 2_longest_subsequence_XOR.cpp
```

Use this format:

```text
<serial>_<existing-descriptive-name>.cpp
```

Filename rules:

- Restart numbering from `1` in every topic folder.
- Keep numbering contiguous with no gaps or duplicate serials.
- Keep the existing descriptive part, capitalization, and spelling unless
  there is a strong reason to correct it.
- Keep the `.cpp` extension.
- During a bulk migration, preserve the old numeric order when assigning the
  new per-folder sequence.
- For a newly added solution, append it after the existing normalized
  sequence in its selected topic folder.

## Workflow for future Codex runs

1. Read this README and any applicable repository instructions.
2. Inventory every incoming `.cpp` file before changing anything.
3. Also inspect existing topic folders for numbering conflicts or misplaced
   new files.
4. Record the starting solution count and, when practical, content hashes.
5. Identify each problem from its filename, class/function signature, and
   implementation. Use LeetCode or web search when the name is ambiguous or
   the problem is newly released.
6. Make a complete classification plan before creating folders or moving
   files.
7. Add only the required top comment. Do not alter the solution body.
8. Move each confidently identified solution into one primary-topic folder.
9. Normalize filenames so every affected topic folder is numbered from `1`
   without gaps.
10. Verify all checks listed below and provide a concise final summary.

## Non-negotiable safety rules

- Never modify, optimize, repair, or rewrite solution logic.
- Do not rename variables, used macros, functions, or classes.
- Remove unused macros only when explicitly requested. Treat a macro as used
  when solution code references it directly or another retained macro depends
  on it; comments and string literals do not count as usage.
- Do not reformat solution code unnecessarily.
- Never delete a solution.
- Do not silently overwrite a destination file.
- Do not merge two files merely because they solve the same problem; they may
  contain different approaches.
- Preserve unrelated files and user changes.
- If identification is uncertain, leave the file where it is and report why.

## Final verification checklist

Before reporting completion, confirm all of the following:

- The number of `.cpp` solutions after processing equals the number before.
- Every expected source file exists at exactly one destination.
- No destination collision or accidental overwrite occurred.
- Every organized solution starts with a valid problem header.
- Every header description is two or three concise lines.
- Solution logic and all non-requested code match their pre-edit contents.
- If macro cleanup was requested, no retained macro is left undefined and no
  unused macro remains.
- Each solution is in one primary-topic folder.
- Each affected folder is numbered consecutively from `1`.
- Incoming folders contain only unresolved or intentionally pending files.

Use a final report in this general form:

```text
Processed: N files

Graph: X
Dynamic_Programming: Y
Array: Z
...

Uncertain classifications:
- filename.cpp -> reason
```

If there are no uncertain files, state that explicitly.
