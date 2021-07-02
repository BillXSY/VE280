#include <iostream>
#include <cstdlib>

using namespace std;

// Classes for exception types. They are just dummy types for you to use when
// handling expections.
// TODO: Define needed classes for exception.


// EFFECTS: Check whether there are enough costumes in Omori's Costume Store. If not, throw
//          a exception.
void buy_costumes(int num_scenes, int costume_remain) {
    // TODO:
    int n;
    if (costume_remain < num_scenes) {
        n = num_scenes - costume_remain;
        throw n;
    }

}

// EFFECTS: Check whether there are enough guns in Yamazaki's Model Shop. If not, throw
//          a exception
void buy_guns(int num_scenes, int guns_remain) {
    // TODO:
    int n;
    if (guns_remain < 2 * num_scenes) {
        n = 2 * num_scenes - guns_remain;
        throw n;
    }
}

// EFFECTS: Check whether there are enough bullets in Yamazaki's Model Shop. If not, throw
//          a exception.
void buy_bullets(int num_scenes, int bullets_remain) {
    // TODO:
    float f;
    if (bullets_remain < 100 * num_scenes) {
        f = 100 * num_scenes - bullets_remain;
        throw f;
    }
}

// EFFECTS: Check if Omori's Costume Store is open. If it is open, then go on to buy flour 
//          and eggs. If it is closed, throw a exception.
void visit_Omori(bool Omori_status, int num_scenes, int costume_remain) {
    // TODO:
    char c = '8';
    if (!Omori_status) throw c;
    buy_costumes(num_scenes, costume_remain);
}

// EFFECTS: Check if Yamazaki's Model Shop is open. If it is open, then go on to buy guns.
//          If it is closed, throw a exception.
void visit_Yamazaki(bool Yamazaki_status, int num_scenes, int guns_remain, int bullets_remain) {
    // TODO:
    char c = '8';
    if (!Yamazaki_status) throw c;
    buy_guns(num_scenes, guns_remain);
    buy_bullets(num_scenes, bullets_remain);
}


int main(int argc, char *argv[]) {
    int num_scenes = atoi(argv[1]);           // number of scenes Haruhi wants to make.
    bool Omori_status = atoi(argv[2]);    // whether Omori is open or closed. 1 for open and 0 for closed.
    bool Yamazaki_status = atoi(argv[3]);    // whether Yamazaki is open or closed. 1 for open and 0 for closed.
    int costume_remain = atoi(argv[4]);        // number of costumes remaining in Omori's Costume Store.
    int guns_remain = atoi(argv[5]);      // number of guns remaining in Yamazaki's Model Shop.
    int bullets_remain = atoi(argv[6]);     // number of bullets remaining in Yamazaki's Model Shop.

    //TODO: 
    // Read all the above parameters from the program arguments


    // If any expception happens, flag will be changed to 0.
    bool flag = 1;

    // They will first visit Omori and then visit Yamazaki. If any exception happens, 
    // their buying process will end.
    cout << "We visit Omori's Costume Store first..." << endl;
    try // visit Omori's Costume Store
    {
        // TODO: 
        visit_Omori(Omori_status, num_scenes, costume_remain);
        cout
                << "We've bought enough costumes! I can't wait before Miss Asahina wears them! Then we visit Yamazaki's Model Shop..."
                << endl;
        try {
            // TODO: 
            visit_Yamazaki(Yamazaki_status, num_scenes, guns_remain, bullets_remain);
            cout
                    << "We've also bought enough guns and bullets! We can start the movies now! But Miss Asahina's nightmare is coming."
                    << endl;
        } // visit Yamazaki's Model Shop
        catch (char c) // Yamazaki's Model Shop is closed!
        {
            cout << "Yamazaki's Model Shop is closed!" << endl;
            flag = 0;
        }
        catch (int n) // Guns in Yamazaki's Model Shop are not enough
        {
            cout << "Guns in Yamazaki's Model Shop are not enough. We still need " << n << " more." << endl;
            flag = 0;
        }
        catch (float f) // Bullets in Yamazaki's Model Shop are not enough
        {
            cout << "Bullets in Yamazaki's Model Shop are not enough. We still need " << int(f) << " more." << endl;
            flag = 0;
        }
    }
    catch (char c) //Omori's Costume Store is closed
    {
        cout << "Omori's Costume Store is closed!" << endl;
        flag = 0;
    }
    catch (int n) //Costumes in Omori's Costume Store are not enough
    {
        cout << "Costumes in Omori's Costume Store are not enough. We still need " << n << " more." << endl;
        flag = 0;
    }

    if (!flag)
        cout << "We have to wait longer before we get started. Fortunately, Miss Asahina can have more peaceful days."
             << endl;

    return 0;
}
