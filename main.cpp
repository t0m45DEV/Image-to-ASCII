#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main(int argc, char* argv[]) {

    /*
        Here we define our grey scale
        If we want to have more detail in the
        ASCII image, we can add more characters,
        in order of "brightness"
        
        Also if you change the number of
        characters, you'll need to modify
        the definition of pixelMapper using:
            pixelMapper = (ammoutOfASCIIChars / 255)
    */

    String greyScale = " .:-=+*%#@"; // Black to white

    /*
        Here we check if the image exist
        If this is not the case, we just
        end the program
    */

    String imgPath = argv[1];
    Image img;

    if (!img.loadFromFile(imgPath)) {
        cout << "ERROR: Could't load image" << endl;
        return 0;
    }

    /*
        The code is pretty straight forward: I
        check every pixel brightness based in
        the average color of that pixel (yes,
        I could do a formula more advance, if
        we want more detail, but this is the
        lazy option, and I like the result), and
        then map that brightness to an index of
        our range of ASCII chars
        Then we print out that char, and move
        on to the next pixel
    */

    Vector2u imgSize = img.getSize();
    int xSize = imgSize.x;
    int ySize = imgSize.y;

    Color actualPixel;
    double pixelMapper = (10 / (double)255);
    double pixelAverage;
    int pixelInASCII;

    for (int i = 0; i < ySize; i++) {
        for (int j = 0; j < xSize; j++) {

            actualPixel = img.getPixel(j, i);
            pixelAverage = (actualPixel.r + actualPixel.g + actualPixel.b) / (double)3;
            pixelInASCII = pixelAverage * pixelMapper;

            cout << char(greyScale[pixelInASCII]);
        }
        cout << endl;
    }
    return 0;
}
