Extensibility:
- add more states: I don't think this is useful, as I don't see what play states we would want to add to the current list of Stopped, Paused, Playing

If I were to make PlayState more extensible, I would create an interface PlayState with a virtual function for each button, and implement this interface in each playstate. Then call the playstate's implementations of the button's function when the button is pressed.

- add more buttons: This would simply require the class to be derived into a new media player class, that could have a button to for example: skip 5 seconds forward. I don't see what I could change to make this easier.