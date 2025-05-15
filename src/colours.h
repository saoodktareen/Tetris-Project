#pragma once
#include <raylib.h>
#include <vector>
using namespace std;

 // extern allows to use declared variable of one class in another
extern const Color darkGrey; // Custom Dark Grey Colour
extern const Color Green; // Custom Green Colour
extern const Color Red; // Custom Red Colour
extern const Color Orange; // Custom Orange Colour
extern const Color Yellow; // Custom Yellow Colour
extern const Color Purple; // Custom Purple Colour
extern const Color Cyan; // Custom Cyan Colour
extern const Color Blue; // Custom Blue Colour
extern const Color lightBlue; // Custom Light Blue Colour
extern const Color darkBlue; // Custom Dark Blue Colour

vector<Color> getCellColours();