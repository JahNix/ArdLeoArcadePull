Okay, First like to say I know that this has been done before by many others. But not by me...

Best way for me to learn is to pick it apart and rebuild it.
I like to think of Look, Cover, Write, Check...

My personal button layout for 10 buttons I came up with years ago.
It gives me all I need for fighting games and regular games.

A simple arduino Leo keyboard sequence to use with MAME.
It uses my Keyboard preference but you could always change and make your own.



Coin In
Start
Select
P1_UP
P1_DOWN
P1_LEFT
P1_RIGHT
P1_B1
P1_B2
P1_B3
P1_B4
P1_B5
P1_B6
P1_B7
P1_B8

working on adding buttons 9 & 10.

BUGS
- Well, it sort of works and doesn't.
Some buttons work (say pins 5-11 and A0) but not all.
Back off the amount of ACTIVE pins and it does what it is supposed to do.
Pretty sure its got to do with timing...delay() and millis()

- Validate I have the correct decimal value for the keypresses.