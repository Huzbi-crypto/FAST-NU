# Typing Game

## Overview

This is a typing game written in Assembly language using the Irvine32 library. The game presents the user with a series of strings that fall from the top of the screen. The user must type these strings before they hit the bottom of the screen. The game has multiple levels, each of which is faster than the last. The number of strings and their size can be adjusted before the start of the program. The game also keeps track of the user's accuracy and mistakes after each level.

## Motivation

This project came from our idea of first making a text editor. However, we decided to make a typing game instead. We wanted to make a game that was fun and challenging, but also educational. We also wanted to make a game that was easy to play and understand, but also had a lot of depth. Our hope is that this game will help people improve their typing skills while also having fun.

## Features

- Adjustable number of strings and string size before the start of the program.
- Multiple levels with increasing speed.
- The ability to start typing from any string at any position.
- The game will move to the string that is about to reach the end if two strings start with the same characters.
- If a typo is made, the incorrect character will be highlighted in red.
- After completing a level, the game displays the number of mistakes and the user's accuracy.

## Usage

To play the game, you need to adjust the number of strings, string size, and speed before starting the program. As the game progresses, the speed increases. The game starts with a block at the bottom of the screen. The user must type the strings as they fall from the top of the screen. If a string is correctly typed, it will disappear. If a string is not correctly typed, it will turn red and the user will be restricted from typing the next character until the incorrect string is typed correctly.

## Code Examples

Here are some key parts of the code:

- `BetterRandomRange PROC l: SDWORD, h: SDWORD`: This procedure generates a random number between `l` and `h`.
- `RandomString PROC uses esi ecx n: DWORD`: This procedure generates a random string of length `n`.
- `set_speed PROC`: This procedure sets the speed of the game according to the level.
- `init_string PROC`: This procedure initializes all the strings with random strings.
- `user_input PROC`: This procedure handles the user's input and updates the game state accordingly.

## Conclusion

This typing game is a fun and challenging way to improve your typing skills. It is a great tool for both beginners and experienced typists.

## Contributing

Contributions are welcome. Please feel free to submit a pull request or open an issue.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.

## Acknowledgments

This project was inspired by the need for a fun and engaging way to improve typing skills.
