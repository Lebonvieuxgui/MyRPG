# My RPG

This is a role-playing game developed as part of the Epitech project. The game is built in C and uses the CSFML library. All the ressources were made by hand and by buying ressources from pixel-artists.

## Project Structure

The project is structured as follows:

- `include/`: Contains header files.
- `lib/`: Contains utility functions for string manipulation and output.
- `src/`: Contains the main game logic, divided into various modules like `boss`, `check_rsrce`, `collision`, `doors`, `error_handling`, `event`, `game_asset`, `gameover`, `HUD`, `init_game`, `intro`, `main_game`, `map`, `menu`, `particles`, `pause`, `settings`, `view`.
- `main.c`: The entry point of the application.
- `Makefile`: Used to build the project.

## Building the Project

To build the project, run the following command in the terminal:

```sh
make
```

## Running the Project

After building the project, you can run it with the following command:
```sh
./my_rpg
```

## Gameplay
The goal of the game is to reclaim your gold in a mighty dungeon. But be careful, you are not alone in here...

## Controls :

- Arrow keys
- Pause: Esc
- Attack: Space
- Interact: X
- Block: C
- Dash: D

You cannot Block and Dash from the beginning so do not worry if it is not yet working ;)

 ### Contributors
- G.LEBRETON
- G.RAUX
- A.TEBINI
