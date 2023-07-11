/*
Program Name: lab11.cpp or PPM_Lab.cpp
Student name: Isaac Abella
Net ID: iabella
Student ID: 000641840
Program Description - Manipulate a PPM file with invert, flip x, and flip y function
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct pixels
{
    // Create colors
    int r, g, b;
};

class Picture
{
public:
    // all of these are private
    vector<pixels> Pixels;
    Picture() = default;
    Picture(int width, int height, int intensity)
    {
        p_width = width;
        p_height = height;
        p_intensity = intensity;
        Pixels.resize(width * height);
    };

    // public functions that I need
    int p_width, p_height, p_intensity;
    const pixels &get_pixel(int row, int col) const
    {
      // Edit here after first submission: changed to unsigned
        unsigned int index = (row * p_width) + col;
        if (index < 0 || index >= Pixels.size())
        {
  throw out_of_range("These pixels are not in bound");
        }
        return Pixels[index];
    }

    pixels &get_pixel(int row, int col)
    {
        if (row < 0 || row >= p_height || col < 0 || col >= p_width)
        {
            throw out_of_range("These pixels are not in bound");
        }
        int index = row * p_width + col;
        return Pixels[index];
    }
    void set_pixel(int row, int col, const pixels &p)
    {
        if (row < 0 || row >= p_height || col < 0 || col >= p_width)
        {
             throw out_of_range("These pixels are not in bound");
        }
        get_pixel(row, col) = p;
    }

    void invert()
    {
        // Takes the Maximum intensity and the get/set pixel methods.
        for (pixels &p : Pixels)
        {
            p.r = p_intensity - p.r;
            p.g = p_intensity - p.g;
            p.b = p_intensity - p.b;
        }
    };
    void flip_x()
    {
        for (int row = 0; row < p_height / 2; row++)
        {
            for (int col = 0; col < p_width; col++)
            {
                pixels burner = get_pixel(row, col);
                set_pixel(row, col, get_pixel(p_height - row - 1, col));
                set_pixel(p_height - row - 1, col, burner);
            }
        }
    };
    void flip_y()
    {
        for (int row = 0; row < p_height; row++)
        {
            for (int col = 0; col < p_width / 2; col++)
            {
                pixels burner = get_pixel(row, col);
                set_pixel(row, col, get_pixel(row, p_width - col - 1));
                set_pixel(row, p_width - col - 1, burner);
            }
        }
    };
    bool read_input(const string &filename)
    {
        // Open the input file
        ifstream infile(filename);
        if (!infile)
        {
            cerr << "Error: Failed to open input file " << filename << '\n';
            return false;
        }

        // Read the image header
        string keyword;
        infile >> keyword;
        if (keyword != "P3")
        {
            cerr << "Error: Unsupported file format " << keyword << '\n';
            return false;
        }
        infile >> p_width >> p_height >> p_intensity;

        if (!infile)
        {
            cerr << "Error: Invalid image dimenstions\n";
            return false;
        }

        // Read the pixel data
        Pixels.resize(p_width * p_height);
        for (pixels &pixel : Pixels)
            if (!(infile >> pixel.r >> pixel.g >> pixel.b))
            {
                cerr << "Error: Invalid pixel data\n";
                return false;
            }

        // Close the input file (unnecessary so commented out)
        // infile.close();
        return true;
    }

    bool write_output(const string &filename) const
    {
        // Open the output file
        ofstream outfile(filename);
        if (!outfile)
        {
            cerr << "Error: Failed to open output file " << filename << '\n';
            return false;
        }

        // Write the image header
        outfile << "P3" << '\n';
        outfile << p_width << " " << p_height << '\n';
        outfile << p_intensity << '\n';

        // Write the pixel data

        for (const auto &pixel : Pixels)
        {
            outfile << pixel.r << " " << pixel.g << " " << pixel.b << " ";
        }
        outfile << '\n';

        // Close the output file
        outfile.close();
        return true;
    }
};

int main(int argc, char **argv)
{
    if (argc < 3 || argc > 4)
    {
        cerr << "Usage: " << argv[0] << " input_file, output_file, and function" << '\n';
        return 1;
    }

    // Create an instance of Picture class
    Picture p;

    string burner;
    char command;

    string input = argv[1];
    string output = argv[2];

    if (argc > 3)
    {
        command = argv[3][0];
    }
    else
    {
        cout << "Usage: ./lab11 bee.ppm output.ppm command";
        return 1;
    }

    if (input == "-")
    {
        cout << "Input a PPM File: \n";
        getline(cin, input);
    }
    if (output == "-")
    {
        cout << "Input an output file: \n";
        getline(cin, output);
    }

    command = tolower(command);
    if (!p.read_input(input))
    {
        cerr << "Error: Failed to read input file " << input << '\n';
        return 1;
    }
    if (command == 'i')
    {
        p.invert();
    }
    else if (command == 'x')
    {
        p.flip_x();
    }
    else if (command == 'y')
    {
        p.flip_y();
    }
    else if (argc == 3)
    {
        cerr << "Invalid function call.\n";
        return 1;
    }

    if (!p.write_output(output))
    {
        cerr << "Error: Failed to write output file " << output << '\n';
        return 1;
    }

    cout << "Image Processing Complete.\n";

    return 0;
}
// :3
