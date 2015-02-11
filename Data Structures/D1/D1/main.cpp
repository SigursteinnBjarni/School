#include <iostream>

using namespace std;
int main(int argc, const char * argv[])
{
    int number;
    cin >> number;
    
    string input_string;
    
    for (int i = 0; i < number; i++)
    {
        cin >> input_string;
        // x and y cords
        int x = 0, y = 0;
        // what position we are facing
        int rotation_pos = 0;
        
        for (unsigned int j = 0; j < input_string.size(); j++)
        {
            switch (input_string[i])
            {
                case 'H':
                    // We take modulus 4 becouse we only have 4 different paths
                    rotation_pos = (rotation_pos+1) % 4;
                    break;
                case 'V':
                    rotation_pos = (rotation_pos+3) % 4;
                    break;
                case 'F':
                    // when we walk farward we move ether left, right, up or down
                    switch(rotation_pos)
                {
                    // move north / up
                    case 0:
                        y++;
                        break;
                    // move east / right
                    case 1:
                        x++;
                        break;
                    // move south / down
                    case 2:
                        y--;
                        break;
                    // move west / left
                    case 3:
                        x--;
                        break;
                }
                    break;
            }
            
        }
        
        cout << x << " " << y << endl;
    }
    
    
    return 0;
}

