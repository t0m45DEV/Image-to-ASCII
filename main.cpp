#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main(int argc, char* argv[]) {

    String greyScale = " .:-=+*%#@"; // Black to white

    String imgPath = argv[1];
    Image img;

    if (!img.loadFromFile(imgPath)) {
        cout << "ERROR: Could't load image" << endl;
        return 0;
    }

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
