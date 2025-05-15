#include "colours.h"
using namespace std;

const Color darkGrey = {26, 31, 40, 255}; // Custom Dark Grey Colour
const Color Green = {47, 230, 23, 255}; // Custom Green Colour
const Color Red = {232, 18, 18, 255}; // Custom Red Colour
const Color Orange = {226, 116, 17, 255}; // Custom Orange Colour
const Color Yellow = {237, 234, 4, 255}; // Custom Yellow Colour
const Color Purple = {166, 0, 247, 255}; // Custom Purple Colour
const Color Cyan = {21, 204, 209, 255}; // Custom Cyan Colour
const Color Blue = {13, 64, 216, 255}; // Custom Blue Colour
const Color lightBlue = {59, 85, 162, 255}; // Custom Light Blue Colour
const Color darkBlue = {44, 44, 127, 255}; // Custom Dark Blue Colour

vector<Color> getCellColours(){ // Get Colour according to Index
    return {darkGrey, Green, Red, Orange, Yellow, Purple, Cyan, Blue};
}