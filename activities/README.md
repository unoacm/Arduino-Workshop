# Making an Activity
Activities are generally exercises focused on one topic, such as lighting up a diode. However, it can be as complex as making a light-up guessing game. As long as it can fit into one cohesive .ino file, it is an activity.

The reason for one .ino file is the limitation of the Arduino IDE only accepting one .ino file to run. There is also some boilerplate code that every .ino file must have.

The recommended way to create an activity is to have a folder for that activity with a README.md explaining the activity. This folder can contain an .ino file for the completed activity, as well as any useful schematics taken from the schematics pool, or can be created for just that activity.

## Arudino .ino Boilerplate
```cpp
void setup() {
	// This method is called once before loop()
}

void loop() {
	// This method is called continously
}
```