# Chess

A two player chess game for the Windows console, written in C++.

## Features

- Every piece has its own class: pawn, rook, knight, bishop, queen and king
- Move validation
- Highlighted legal moves for the selected piece
- Check and checkmate detection
- Undo
- Save to `save.txt`

## Requirements

Windows, because the game uses `windows.h` and `conio.h`.

## Build

1. Open `bscs22017-chess.sln` in Visual Studio.
2. Build and run.

## Code layout

| File | Purpose |
|---|---|
| `bscs22017-chess.cpp` | Entry point |
| `chess.cpp` / `chess.h` | Game flow, check, checkmate, save and undo |
| `board`, `player`, `piece` | Board, players and the base piece class |
| `pawn`, `rook`, `knight`, `bishop`, `queen`, `king` | Piece rules |
| `validity.cpp` | Move validation |
