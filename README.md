# Arduino-Workshop
A repo containing all resources needed for several Arduino workshops.

This repo will eventually contain schematics, library code, activities, and lesson plans for various Arduino workshops.

# Schematics
Schematics are pictures or diagrams showing how the Arduino hardware be set up, or how a certain piece of hardware connects to the Arduino. These can be general for the pinouts, or specific if required for the workshop. They need to be accurate, as well as highlight key areas with specific colors: RED for 5V, BLACK or BROWN for ground, and a color symbolizing data traffic (some sensors may even require several data lines).

# Library Code
Library code consists of non-ino extension code that is specifically used for utility and not full Arduino applications. As of the current version of the Arduino IDE, this code needs to be in its own folder (header and source files together), located in the `libraries` folder in the Arduino IDE directory on the computer, that way they can be easily accessible through the Arduino IDE.

Several libraries should already be included in this repo as soon as they can be. Please look over how the folder is constructed to see how they work.

I recommend that all code be under the namespace `acm`, to avoid conflicts and keep it simple.

# Activities
Activties can include a multitude of different schematics, library code, and even Arudino .ino files. These activities can be as simple as lighting up a diode, to playing a guessing game. To easily create these activities, they can contain their own schematics and library code folders, where the schematics are taken from the main pool, and the library code folder names are marked down to show what dependencies they will use. This consistency will help make activities for readable for everyone. Hopefully, examples will be put up to show how this could work.

# Lesson Plans
If needed, lesson plans can be created to hold several activities to be carried out either in one or multiple sessions. These lesson plans can be used to create interest in Arudinos, or a certain aspect of Arudinos.
